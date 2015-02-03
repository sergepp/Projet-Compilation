
Var ParamDeclSetNext(Var param, Var next);
void ParamDeclAssertIsOk(char* name, char* classType);
Var ParamDecl(char* name, char* classType);


void ClassDefPrint(Class cl);

Class defaultClassDefsPlus(Class classDefs);


ClassCall ExtendsDecl(char* className, Expr expr);
 

void ExtendsDeclAssertIsOk( char* className, Expr expr);

void ConstructorBodyAssertIsOk(Instr consBody);


Class ClassDeclSetNext(Class class, Class next);
void ClassDeclAssertIsOk(char* className, Var classParamDecl ,ClassCall extendsDecl, Instr constructorBody, Var fieldDecl, Method methodDecl);       
Class ClassDecl(char*     className,
                Var       classParamDecl,
                ClassCall extendsCall, 
                Instr     constructorBody, 
                Var       fieldDecl, 
                Method    methodDecl);

void OverrideMethodDeclAssertIsOk(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr); 


Class GetClassByName(char* className);

Method MethodDeclSetNext(Method method, Method next);

Method OverrideMethodDecl(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr);

Method StaticMethodDeclAssertIsOk(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr); 
Method StaticMethodDecl(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr);

void MethodDeclAssertIsOk(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr); 
Method MethodDecl(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr);  
 
Method MethodDeclParamSetNext(Method method, Method next);  

void ParamDeclAssertIsOk(char* name, char* classType); 
Var ParamDecl(char* name, char* classType);

