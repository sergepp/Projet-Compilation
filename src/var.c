

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

void AssertVarAreNotDupliqued(Var var){ 

    if ( var == NULL || var->next == NULL ) 
        return; 
    
    if (  strcmp(var->class->name, "Integer")  == 0
        || strcmp(var->class->name, "String")   == 0
        || strcmp(var->class->name, "Void")     == 0 )  
        return ; 
        
    char message[128];
    Var i = var; 
    Var j; 
    while ( i != NULL ) {
        if ( i->class == NULL) {
            sprintf(message, "Le type du parametre       hgkhgh %s n'existe pas\n", i->name);
            PrintError(message, yylineno);
            exit(1);
        }
        j = i->next;
        while ( j != NULL ) {
            if ( strcmp(i->name, j->name) == 0 ) { 
                sprintf(message, "Le nom de variable  %s a deja été utilise dans les parametres", j->name);
                PrintError(message, j->lineno);
                exit(1);
            }
            j = j->next;
        }
        
        i = i->next;            
    }
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
}

Var VarDecl(char* name, char* className, Expr e) {

    if (strcmp(name, "this") == 0 || strcmp(name, "super") == 0  ) {
         char message[128];  
         sprintf(message, "%s est un mot reserve et ne peut etre utiliser comme nom de variable ou de parametre\n", name);
        PrintError(message, yylineno);
        exit(1);
    } 
    Var v    = NEW(1, _Var);
    v->name  = name;
    v->lineno = yylineno;
    v->class = GetClassByName(className);
    v->value = e;
    v->isStatic = FALSE;
    return v;
}

