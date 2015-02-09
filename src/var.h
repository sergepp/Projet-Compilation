
Var GetVarByName(char* varName, Scope scope);

void StaticVarDeclAssertIsOk(char* name, char* classType, Expr expr);

Var FindVarInScope(char* name, Scope scope, bool isStatic);

Var FindInstanceVarInScope(char* name, Scope scope, bool isStatic);

Var FindStaticVarInScope(char* name, Scope scope);

void AssertVarAreNotDupliqued(Var var);


void AssertVarDeclIsOk(char* varName, char* classname, Expr e) ;


Var VarDecl(char* name, char* className, Expr e) ;


void AssertAbstractVarDeclIsOk(char* name, char* classname) ;


void VarPrint(Var var);


Var StaticVarDecl(char* name, char* classType, Expr expr);

