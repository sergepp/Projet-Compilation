
#define TRUE 1
#define FALSE 0 

typedef int bool;

struct __Class;
struct __Expr;




typedef struct __Var {
  char* name;
  struct __Class* class;
  struct __Expr* value;
  struct __Var* next ; 
} _Var, *Var;

    
typedef struct __Param {
  struct __Param* next ; 
} _Param, *Param;


typedef struct __ClassType {
  char* name; 
  struct __ClassType* extends ; 
} _ClassType, *ClassType;


typedef struct __Expr {
  ClassType type;
  struct __Expr* left;
  int op;
  union {
    char *s;      /* valeur de la feuille si op = CONST_STR */
    int i;        /* valeur de la feuille si op = CONST_INT */
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

    Expr expr;                  /* valeur de la feuille si op = EXPR */
    Expr yield;                 /* valeur de la feuille si op = FN_BLOC */
    Var var;                    /* valeur de la feuille si op = PROC_BLOC  ou FN_BLOC */                   
         
    struct __Instr* listInstr;       /* valeur de la feuille si op = PROC_BLOC  ou FN_BLOC */                   
         
    Expr leftExpr;              /* valeur de la feuille si op = ASSIGN */
    Expr rightExpr;             /* valeur de la feuille si op = ASSIGN */
    
    Expr cond;                  /* valeur de la feuille si op = IF */
    struct __Instr* thenInstr;
    struct __Instr* elseInstr; 
    
  struct __Instr* next ; 
} _Instr, *Instr;


typedef struct __Method {
  char* name;
  bool isOverride;
  bool isStatic;
  Expr params;
  Expr body;
  Expr this;
  int paramsCount;
  ClassType returnType;
  Expr returnValue;
  
  struct __Method* next ; 
} _Method, *Method;


typedef struct __ClassCall {
  struct __Class* class;
  Expr args;
} _ClassCall, *ClassCall;


typedef struct __Class {

  char* name;
  ClassType type;
  Var fields;
  Method methods;
  Var consParams;
  Instr consBody;
  ClassCall extends;
  Expr extendsParams;
 
  struct __Class* next ; 
} _Class, *Class;


typedef struct __Program {
  Class classDefs;
  Instr instrs;
  
  struct __Program* next ; 
} _Program, *Program;

