
Scope ScopeNew(char* name, Scope prev, Scope next, Var var) {
    Scope scope = NEW(1, _Scope); 
    scope->name = name;
    scope->prev = prev;
    scope->next = next;
    scope->var = var;
    return scope;
}

void ScopeInitForClass(Class class){
    /* On initialise le scope de toutes ses methodes */
    Method m = class->methods;
   
    while ( m != NULL ) {
        
        /* Eventuelles variable declaree */
        Scope localVar = ScopeNew("", NULL, NULL, NULL);
        if (  m->bodyInstr != NULL && m->bodyInstr->var != NULL ) {
            localVar->var =  m->bodyInstr->var;
        }
        /* Parametres de methodes */                
        char paramScopeName[128];
        sprintf(paramScopeName, "%s.params", class->name);
        Scope paramScope = ScopeNew(paramScopeName, localVar, NULL, m->params);
        localVar->next = paramScope;
        
        /* Champ de la classe */
        localVar->next->next = class->scope;
         
        m->scope = localVar;
        m = m->next;        
    } 
}

void ScopeInitForMethod(Class class, Method method){


}
void ScopeInitForConstructor(Class class){


}


Method FindInstanceMethodInScope(char* methodname, Scope scope) {
    bool isStatic = FALSE;
    Method m = FindMethodInScope(methodname, scope, isStatic);
    return m ;
}

Method FindStaticMethodInScope(char* methodname, Scope scope) {
    bool isStatic = TRUE;
    Method m = FindMethodInScope(methodname, scope, isStatic);
    return m ; 
}

Method FindMethodInScope( char* methodname, Scope scope, bool isStatic) {
    if ( scope == NULL ) 
        return NULL;
        
    Method m = scope->method;
    while ( m != NULL ){ 
    
        if ( m != NULL &&  strcmp(m->name, methodname) == 0 && m->isStatic == isStatic ) {
           return m ;  
        }
        m = m->next;
    }
    m = FindMethodInScope(methodname, scope->next, isStatic);
    return m;
}


Var FindInstanceVarInScope(char* name, Scope scope){
    bool isStatic = FALSE;
    Var v = FindVarInScope  (name, scope, isStatic);
    return v ;
}

Var FindStaticVarInScope(char* name, Scope scope){
    bool isStatic = TRUE;
    Var v = FindVarInScope(name, scope, isStatic);
    return v ;
}



Var FindVarInScope(char* varname, Scope scope, bool isStatic) {

    if ( scope == NULL ) 
        return NULL;
        
    Var i = scope->var;
    while ( i != NULL ){ 
    
        if ( i != NULL &&  strcmp(i->name, varname) == 0  && i->isStatic == isStatic ) {
           return i ;  
        }
        i = i->next;
    }
    i = FindVarInScope(varname, scope->next, isStatic);
    return i ; 
}

void ScopePrint(Scope scope){
    if ( scope == NULL ) 
        return;
        
    Var i = scope->var;
    printPadding();printf("%s  VAR ->    ", scope->name);
    while ( i != NULL ){
        printf("%s:%s,  ", i->name, i->class->name);
        i = i->next;
    }
    printf("\n");
    
    Method m = scope->method;
    printPadding();printf("%s  METHODS ->    ", scope->name);
    while ( m != NULL ){
        printf("%s returns %s,  ", m->name, m->returnClassName);
        m = m->next;
    }
    printf("\n");
    incPaddingNb();
    ScopePrint(scope->next);
    decPaddingNb();
}

void RemoveNextScope() {
/*
    if ( currentScope->next != NULL ) {
       printf("Attention ! le Next du scope %s  doit exister pour pouvoir être supprimé dans cette methode RemoveNextScope\n", currentScope->name);
       return ;
    } 
    free(currentScope->next->declaredVars) ; /* Faire une bouce pour supprimer la liste chainée 
    free(currentScope->next->name) ;
    free(currentScope->next->next) ;
    free(currentScope->next);
    
    currentScope->next = NULL;*/
}


bool IsVarInClassConsScope(char* varName, Class class){
    
    if ( class != NULL ) {
        /* Premiere verification dans les parametres des constructeurs */
        Var i = class->consParams;
        while ( i != NULL ) {
            if ( strcmp(i->name, varName) == 0 )
                return TRUE;
           i = i->next;      
        }
        
        /* Dans le scope de la classe */
        i = class->fields;
        while ( i != NULL ) {
            if ( strcmp(i->name, varName) == 0 )
                return TRUE;
           i = i->next;      
        }
        
        /* Dans le scope d'une des classe heritées */
    }
       
    return FALSE;

}

void ClassConsBodyAssertScopeAreCorrrect(Expr expr, Class class){
    char message[128];

     Var v, i;
     Expr e, s; 
     Class c;
     bool declared = FALSE;
     switch(expr->op) {
        case SELECTION  : 

            s = expr;
            e = expr->left; 
            

           do { 
            
                if ( e->op == VAR_CALL && strcmp(e->value.s, "this") == 0  ){ 
                        c = class;
                }
                
                else {
                        c = e->type;
                }             
                v = ClassGetFieldByName(c, s->value.s);
                if ( v  == NULL ){
                       sprintf(message, "Le champ %s n'a pas ete declare dans la classe %s\n", s->value.s, c->name);
                       PrintError(message, e->lineno);
                       exit(1);
                }
                if ( e != NULL ) {
                    s = s->left;
                    e = e->left;
                }
            }  while ( e != NULL );
            break;
        case VAR_CALL   :
            i = class->consParams;
            while ( i != NULL ) {   
                if ( strcmp(expr->value.s, i->name) == 0 ) {
                    declared = TRUE;
                    break; 
                } 
                i = i->next;
            }
            if ( declared == FALSE ) {
                sprintf(message, "La variable  %s n'a pas ete declaree avant son utilisation\n",  expr->value.s);
                PrintError(message, expr->lineno);
                exit(1);
            }

            break;
        case CONST_STR : 
        case CONST_INT : break;
        case ADD    :
        case SUB    :          
        case DIV    :  
        case MUL    : 
        case CONCAT :
            ClassConsBodyAssertScopeAreCorrrect(expr->left, class) ;
            ClassConsBodyAssertScopeAreCorrrect(expr->right, class) ;
            break ;   
        default : PrintError("Evaluation Non pris en charge par la fonction : ExprArithmeticEval\n ", expr->lineno); break;     
    }
}


void ClassAssertScopeAreCorrect(Class class){
     char message[128];
    /* Verifie le scope des Parametres du constructeur  */ 
    Var i = class->consParams; 
    Var j; 
    while ( i != NULL ) {
        if ( i->class == NULL) {
            sprintf(message, "Le type du parametre %s n'existe pas\n", i->name);
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
    /* Verifie le scope du corps du constructeur */
    Instr k = class->consBody; 
    if ( class->consBody != NULL ) 
        k = class->consBody->listInstr;
        
    while ( k != NULL ) {
        switch(k->op) {
            case EXPR   : 
                ClassConsBodyAssertScopeAreCorrrect(k->expr, class);
                break;
            case ASSIGN : 
                ClassConsBodyAssertScopeAreCorrrect(k->leftExpr, class);
                ClassConsBodyAssertScopeAreCorrrect(k->rightExpr, class);
                break;
            case IF     : 
                ClassConsBodyAssertScopeAreCorrrect(k->cond, class);
                break;
            case RETURN :
                sprintf(message, "Le corps du constructeur de %s ne doit pas comporter d'instrcution Return \n", class->name);
                PrintError(message, k->expr->lineno );
                exit(1);
                break;
            default : 
                PrintError("Operateur de l'Instruction inconnu dans ClassAssertScopeAreCorrect \n ", -1); 
                exit(1);
                break;     
        }     
        k = k->next;
    } 
    /* VerifieExtends Scope */
    
    /* Verifie Body Scope */
}


void initializeScope(){
    MainScope = ScopeNew("Main", NULL, NULL, NULL) ;
    currentScope = MainScope;
}

void ClassRegisterInScope(Class cl){
     
    
    if (   strcmp(cl->name, "Integer") == 0
        || strcmp(cl->name, "String")  == 0
        || strcmp(cl->name, "Void")    == 0 )
            return ;
            
    Class i = AllDefinedClasses ;
    while ( i->next != NULL ) {
        i = i->next;        
    }    
    i->next = cl;
}
   

void VarAddToScope(Scope scope, Var var){
    if ( scope == NULL ) {
        printf("Attention ! le scope ne doit pas etre null dans cette methode VarAddToScope\n");
        return ;
    } 
    if ( scope->var == NULL ) {
        scope->var = var;
    }
    else {     
        Var i = scope->var;
        while ( i->next != NULL ) { 
            i = i->next;
        }
        i->next =  var;
    }
    
}

void VarAddToCurrentScope(Var var){
    VarAddToScope(currentScope, var); 
}

void VarAddToNextScope(Var var){
     if ( currentScope->next == NULL ) {
       printf("Attention ! le Next du scope %s  doit exister dans cette methode VarAddToNextScope\n", currentScope->name);
       return ;
    } 
    VarAddToScope(currentScope->next, var); 
}

void VarAddToPrevScope(Var var){
    if ( currentScope->prev == NULL ) {
       printf("Attention ! le Prev du scope %s  doit exister dans cette methode VarAddToPrevScope\n", currentScope->name);
       return ;
    } 
    VarAddToScope(currentScope->prev, var);
}

void VarSetCurrentScopeToNext(){
    if ( currentScope->next == NULL ) {
       printf("Attention ! le Next du scope %s  doit exister dans cette methode VarSetCurrentScopeToNext\n", currentScope->name);
       return ;
    } 
    currentScope = currentScope->next;
}

void VarSetCurrentScopeToPrev(){
    if ( currentScope->prev == NULL ) {
       printf("Attention ! le Prev du scope %s  doit exister dans cette methode VarSetCurrentScopeToPrev\n", currentScope->name);
       return ;
    } 
    currentScope = currentScope->prev;
}
void CreateNextCurrentScope(char* name) {
    /*
    if ( currentScope->next != NULL ) {
       printf("Attention ! le Next du scope %s ne doit etre null dans cette methode CreateNextCurrentScope\n", currentScope->name);
       return ;
    } 
    currentScope->next = CreateNewScope(name);
    */
}

bool IsVarInClassScope(char* varName, Class class){
    bool result = TRUE;
    /* On verifie si la variable est un parametre de constructeur */
    /* On verifie si la variable est un champ de la classe */
    /* On verifie si la variable a ete declare dans une instruction  */
    return result; 
}



bool IsVarInCurrentScope(char* varName, Scope currentScope){
    bool result = TRUE;
    Var c = GetVarByName(varName, currentScope);
    if ( c == NULL ) 
        result = FALSE;
  
   return result; 
}
