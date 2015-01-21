
#define TRUE 1
#define FALSE 0 

typedef int bool;


typedef struct __Var {
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
  ClassType type;
  Expr expr;
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


typedef struct __Class {
  ClassType type;
  Field fields;
  Method methods; 
  struct __Class* next ; 
} _Class, *Class;


typedef struct __Program {
  Class classDefs;
  Instr instrs;
  
  struct __Program* next ; 
} _Program, *Program;

