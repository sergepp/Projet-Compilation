
void ExprAssertFieldAccessIsOk(Expr e1, char* name);

Expr ExprFromFieldAccess (Expr e1,char* name);

void ExprAssertStaticFieldAccessIsOk(char* classname, char* name);

Expr ExprFromStaticFieldAccess(char* classname, char* name);

void ExprAssertStaticMethodAccessIsOk(char* classname, char* name, Expr e5);

void ExprAssertIDIsOk(char* name) ;


Expr ExprFromStaticMethodAccess(char* classname, char* name);

Expr ExprFromMethodAccess(Expr e1,char* name, Expr e5);

void ExprAssertMethodAccessIsOk(Expr e1,char* name, Expr e5);


Expr ExprFromConcat(Expr e1, Expr e3);

void ExprAssertInstanciationIsOk(char* className, Expr e);


Expr ExprThis();

void AssertExprIsValid(Expr expr);


Expr ExprFromInstanciation(char* className, Expr e);
 
 void ExprAssertInheritsType(Class ct, Expr e);
 
bool IsVarInClassScope(char* varName, Class class);


void ExprAssertAllVarsAreDeclaredInScope(Expr expr, Class class);


/* Renvoi TRUE si e1 et e2 sont de la meme classe modulo heritage et FALSE sinon*/
bool ExprSameInstance(Expr e1, Expr e2) ;

/* Renvoi TRUE si e1 et e2 sont de la meme classe et FALSE sinon*/
bool ExprSameClass(Expr e1, Expr e2) ;

Expr ExprFromArithmetic(Expr left, int op, Expr right);

void ExprAssertInheritsSameClass(Expr e1, Expr e2);

void ExprAssertSameClass(Expr e1, Expr e2);

Expr ExprFromVoid();

Expr ExprFromInt(int value);

Expr ExprFromString(char* string);


Expr ExprFromVar(char* varName);

Expr ExprSetNext(Expr expr, Expr next);

Expr ExprFromBoolean(Expr left, int op, Expr right); 

void ExprPrint(Expr expr) ;

void ExprPrintResult(Expr expr) ;

Expr ExprArithmeticEval(Expr expr); 

Expr ExprEval(Expr expr);

Expr ExprConcatEval(Expr expr) ;

Expr ExprVarEval(Expr expr);


