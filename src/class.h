
Var ParamDeclSetNext(Var param, Var next);
void ParamDeclAssertIsOk(char* name, char* classType);
Var ParamDecl(char* name, char* classType);


void ClassDefPrint(Class cl);

void ClassPrint(Class c);
Class defaultClassDefsPlus(Class classDefs);


Class ClassDecl(char*   className, Var classParamDecl);

Class ClassDeclComplete(MethodCall extendsCall, 
                        Instr      constructorBody, 
                        Var        fieldDecl, 
                        Method     methodDecl);

MethodCall ExtendsDecl(char* className, Expr expr,  char* methodName);
 
Method GetMethod(Class class, char* methodName);


void AssertClassIsNotDupliqued(char*  className);

bool IsMethodOverrideSomething(Method method, Class class); 

void AssertMethodAreNotDupliqued(Method method);

void AssertClassExists(char* className); 

void ReplaceVarInExpr(Expr e, char* varName, Var v) ; 

bool MethodHasSameSignature( Method m1, Method m2);

void ReplaceExprViaScope(Expr expr, Scope scope);

void ReplaceVarInInstr(Instr instr, Scope sc);

void ClassTypeAndRedirect(Class class);

void ExtendsDeclAssertIsOk( char* className, Expr expr);

void ConstructorBodyAssertIsOk(Instr consBody);

 Method ClassInitConstructor(Class class, Var classParamDecl, Instr constructorBody);
Class ClassDeclSetNext(Class class, Class next);
void ClassDeclAssertIsOk(Class class);
 


Class GetClassByName(char* className);

Method MethodDeclSetNext(Method method, Method next);

Method OverrideMethodDecl(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr);


Method StaticMethodDecl(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr);

 

Method MethodDecl(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr);  
 
Method MethodDeclParamSetNext(Method method, Method next);  

void ParamDeclAssertIsOk(char* name, char* classType); 

Var ParamDecl(char* name, char* classType);
   
Var NewThis(Class class, Expr e);

void AssertClassLeftInheritsRight(Class left, Class right);

void AssertClassInstanciationIsOk(Class class , Expr expr, int lineno);

Var NewSuper(Class class, Expr e);

Expr ClassNewInstanceOf(char* className, Expr expr);


void ClassUpdateRefToFieldsOf(Class class);

Var ClassGetFieldByName(Class class, char* varName);

