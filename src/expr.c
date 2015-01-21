//commence par ligne 187 de tp.y
void ExprAssertFieldAccessIsOk(Expr e1,char* name){
    printf("not implemented");
}

Expr ExprFromFieldAccess (Expr e1,char* name){
    return e1;
    printf("not implemented");
}

void ExprAssertStaticFieldAccessIsOk(char* classname, char* name){
    printf("not implemented");
}

Expr ExprFromStaticFieldAccess(char* classname, char* name){
    Expr e  = NEW(1, _Expr);
    return e;
    printf("not implemented");
}

void ExprAssertStaticMethodAccessIsOk(char* classname, char* name, Expr e5) {
    printf("not implemented");
}

Expr ExprFromStaticMethodAccess(char* classname, char* name){
    Expr e  = NEW(1, _Expr);
    return e;
    printf("not implemented");
}

Expr ExprFromMethodAccess(Expr e1,char* name, Expr e5){
    return e1;
    printf("not implemented");
}

void ExprAssertMethodAccessIsOk(Expr e1,char* name, Expr e5){
    printf("not implemented");
}


Expr ExprFromConcat(Expr e1, Expr e3){
    printf("not implemented");
    return e1;
}

Expr ExprFromReturn(Expr e){
    printf("not implemented");
    return e;
}

void ExprAssertInstanciationIsOk(ClassType cy, Expr e){
    printf("not implemented");
}

Expr ExprFromInstanciation(ClassType cy, Expr e){
    printf("not implemented");
    return e;
}

void ExprAssertInheritsType(ClassType ct, ...){
     printf("not implemented");
}
 
Expr ExprFromArithmetic(Expr e1, int op, Expr e2) {
    return e1;
}

Expr ExprFromBoolean(Expr e1, int op, Expr e3){
    printf("not implemented");
    return e1;
}

Var InstrSetNext(Var v1, Var v2) {
    printf("not implemented");
    return v1;
}

void InstrAssertVarDeclIsOk(char* name, char* classname, Expr e) {
    printf("not implemented");
}

Var InstrFromVarDecl(char* name, char* classname, Expr e) {
    Var v = NEW(1, _Var);
    printf("not implemented");
    return v;
}

void InstrAssertAbstractVarDeclIsOk(char* name, char* classname) {
    InstrAssertVarDeclIsOk(name, ct, NULL);
    printf("not implemented");
}