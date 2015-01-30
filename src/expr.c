/* commence par ligne 187 de tp.y */
void ExprAssertFieldAccessIsOk(Expr e1, char* name){
    printf("not implemented\n");
}

Expr ExprFromFieldAccess (Expr e1,char* name){
    return e1;
    printf("not implemented\n");
}

void ExprAssertStaticFieldAccessIsOk(char* classname, char* name){
    printf("not implemented\n");
}

Expr ExprFromStaticFieldAccess(char* classname, char* name){
    Expr e  = NEW(1, _Expr);
    return e;
    printf("not implemented\n");
}

void ExprAssertStaticMethodAccessIsOk(char* classname, char* name, Expr e5) {
    printf("not implemented\n");
}

Expr ExprFromStaticMethodAccess(char* classname, char* name){
    Expr e  = NEW(1, _Expr);
    return e;
    printf("not implemented\n");
}

Expr ExprFromMethodAccess(Expr e1,char* name, Expr e5){
    return e1;
    printf("not implemented\n");
}

void ExprAssertMethodAccessIsOk(Expr e1,char* name, Expr e5){
    printf("not implemented\n");
}


Expr ExprFromConcat(Expr e1, Expr e3){
    
    Expr expr = NEW(1, _Expr);
    expr->left = e1; 
    expr->op = CONCAT; 
    expr->value.s = NULL;
    expr->type = NULL; 
    expr->right = e3;
    
    return expr;
    
}

Expr ExprFromReturn(Expr e){
    printf("not implemented\n");
    return e;
}

void ExprAssertInstanciationIsOk(ClassType cy, Expr e){
    printf("not implemented\n");
}

Expr ExprFromInstanciation(ClassType cy, Expr e){
    printf("not implemented\n");
    return e;
}

void ExprAssertInheritsType(ClassType ct, ...){
     printf("not implemented\n");
}


