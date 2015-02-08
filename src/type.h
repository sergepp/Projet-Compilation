
#define TRUE 1
#define FALSE 0 
#define ID_NAME_MAX_SIZE 50

typedef int bool;

struct __Class;
struct __Expr;

typedef struct __Var {
  char* name;
  struct __Class* class;
  struct __Expr* value;
  struct __Var* next ; 
  bool isStatic;
  int lineno;
} _Var, *Var;


typedef struct __Scope {
    Var var;
    char* name;
    struct __Scope* prev; 
    struct __Scope* next; 
} _Scope, *Scope;
    
    
typedef struct __Param {
  struct __Param* next ; 
} _Param, *Param;


typedef struct __ClassType {
  char* name; 
  struct __ClassType* extends ; 
} _ClassType, *ClassType;


typedef struct __Expr {
  struct __Class* type;
  Scope scope;
  int lineno;
  bool isEvaluated;
  struct __Expr* left;
  int op;
  union {
    char *s;                    /* valeur de la feuille si op = CONST_STR ou VAR_CALL ou SELECTION*/
    int i;                      /* valeur de la feuille si op = CONST_INT */
    struct __Class* instance;   /* Valeur de la feuille si op = INSTANCE*/
  } value; 
  struct __Expr* right; 
  struct __Expr* next ; 
} _Expr, *Expr;


typedef struct __Field {
  char* name;
  ClassType type;
  Expr value;
  struct __Field* next ; 
} _Field, *Field;


typedef struct __Instr {  
  int op;
    Scope scope;
    Expr expr;                  /* valeur de la feuille si op = EXPR */
    Expr yield;                 /* valeur de la feuille si op = PROC_BLOC  ou FN_BLOC ou INSTR_BLOC */
    Var var;                    /* valeur de la feuille si op = PROC_BLOC  ou FN_BLOC  */
    struct __Instr* listInstr;  /* valeur de la feuille si op = PROC_BLOC  ou FN_BLOC ou INSTR_BLOC */                   
    Expr leftExpr;              /* valeur de la feuille si op = ASSIGN  ou SELECTION*/
    Expr rightExpr;             /* valeur de la feuille si op = ASSIGN */    
    Expr cond;                  /* valeur de la feuille si op = IF */
    struct __Instr* thenInstr;
    struct __Instr* elseInstr; 
    
    struct __Instr* next ; 
} _Instr, *Instr;


typedef struct __Method {
  
  char* name;
  int lineno;
  bool  isOverride;
  bool  isStatic;
  Var   params;
  struct __Class* class;
  Scope scope;
  Expr  bodyExpr;
  Instr bodyInstr;
  char* returnClassName;
  
  struct __Method* next ; 
  
} _Method, *Method;
 

typedef struct __MethodCall {
  struct __Class* class;
  Expr args;
  char* methodName;
} _MethodCall, *MethodCall;



typedef struct __Class {

  char* name;
  ClassType type;
  Var fields;
  Method methods;
  Var consParams;
  Instr consBody;
  MethodCall extends;
  Expr extendsParams;
  int lineno;
  struct __Class* next ; 
} _Class, *Class;


typedef struct __Program {
  Class classDefs;
  Instr instrs;
  
  struct __Program* next ; 
} _Program, *Program;



Class Integer;

Class String;

Class Void;

Expr voidInstance;

Class AllDefinedClasses;

Scope MainScope;

Scope currentScope ;

Class CurrentClass;

Expr This ;

char* CurrentMethodName;

void PrintError(char* message,  int lineno);
 
ClassType StringType();
 
Var IntegerFields();

Var StringFields();

Method IntegerAddMethod();

/* Renvoi la liste de toutes les methodes disponibles sur l'objet Integer */
Method IntegerMethods();

/* Renvoi la liste de toutes les methodes disponibles sur l'objet String */
Method StringMethods();

Class initStringClass() ;

Class initVoidClass();

Class initIntegerClass();

void incPaddingNb();

void decPaddingNb();

void printPadding();

void ProgramPrint(Program prg);


void ProgramEval(Program program);


Program makeProgram(Class classDefs, Instr instrs);



