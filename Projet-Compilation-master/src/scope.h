
void ScopeInitForClass(Class class);

Method FindInstanceMethodInScope( char* methodname, Scope scope);
Method FindMethodInScope( char* methodname, Scope scope, bool isStatic);
Method FindStaticMethodInScope( char* methodname, Scope scope);


Var FindVarInScope(char* name, Scope scope, bool isStatic);

Var FindInstanceVarInScope(char* name, Scope scope);

Var FindStaticVarInScope(char* name, Scope scope);

Scope ScopeNew(char* name, Scope prev, Scope next, Var var);
 

bool IsVarInCurrentScope(char* varName, Scope scope);

void ScopePrint(Scope scope);

void RemoveNextScope();

bool IsVarInClassConsScope(char* varName, Class class);

void ClassConsBodyAssertScopeAreCorrrect(Expr expr, Class class);

void ClassAssertScopeAreCorrect(Class class);

void initializeScope();

void ClassRegisterInScope(Class cl);
   
Scope CreateNewScope(char* name);

void VarAddToScope(Scope scope, Var var);

void VarAddToCurrentScope(Var var);

void VarAddToNextScope(Var var);

void VarAddToPrevScope(Var var);

void VarSetCurrentScopeToNext();

void VarSetCurrentScopeToPrev();

void CreateNextCurrentScope(char* name);

bool IsVarInClassScope(char* varName, Class class);
