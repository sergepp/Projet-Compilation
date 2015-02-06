

void VarPrint(Var v){
    printf("Var     name:%s  class:%s  ", v->name, v->class->name );
    
    if ( v->value == NULL ) 
        printf("expr:NULL  ");
    else 
        printf("expr:(expr)  ");
        
    if ( v->isStatic == TRUE ) 
        printf("isStatic:True  ");
    else 
        printf("isStatic:False  ");
        
    if ( v->next == NULL ) 
        printf("next:NULL  \n");
    else 
        printf("next:(Var)  \n");
}

Var GetVarByName(char* varName, Scope scope){

    if ( CurrentClass != NULL ) {
        Method m = CurrentClass->methods;
        while ( m != NULL ) {
            
            if ( strcmp(m->name, CurrentMethodName) == 0 ) {
                Var v = FindVarInScope(varName, scope);
                return v;
            }
            
            m = m->next;   
        }    
    }
    Scope cs = scope;
    if ( scope == NULL ) 
        cs = currentScope;
    while ( cs != NULL ) {
        Var i = cs->var;
        while ( i != NULL ){

            if ( strcmp(i->name, varName) == 0 )
                return i;
            i = i->next;
        }
        cs = cs->next;     
    }
    return NULL  ;  
}


void StaticVarDeclAssertIsOk(char* name, char* classType, Expr expr){
    printf("StaticVarDeclAssertIsOk Not implemented\n");
}


Var StaticVarDecl(char* name, char* classType, Expr expr){
    Var v = VarDecl(name,classType, expr);
    v->isStatic = TRUE;
    return v;
}



void AssertAbstractVarDeclIsOk(char* name, char* classname) {
    AssertVarDeclIsOk(name, classname, NULL);
    printf("AssertAbstractVarDeclIsOk not implemented");
}

void AssertVarDeclIsOk(char* varName, char* classname, Expr e) {
    char message[128];
    
    /* L'expression doit etre correcte */     
    AssertExprIsValid(e);
    
    /* Le nom de la variable ne doit pas deja avoir ete utilise dans le scope actuel */
    Var c = GetVarByName(varName, NULL);
    if ( c != NULL ){ 
        sprintf(message, "Variable %s deja definie dans le scope actuel", varName);
        PrintError(message, e->lineno);
        exit(1);
     }
    /* Le type de la classe doit etre compatible avec le type de l'expression */
    
    printf("AssertVarDeclIsOk not tottaly implemented\n");
}

Var VarDecl(char* name, char* className, Expr e) {
    Var v    = NEW(1, _Var);
    v->name  = name;
    v->lineno = yylineno;
    v->class = GetClassByName(className);
    v->value = e;
    v->isStatic = FALSE;
    return v;
}

