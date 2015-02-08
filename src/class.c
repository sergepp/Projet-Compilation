
Class ClassDecl(char*   className, Var classParamDecl) {
    
    Class class =  NEW(1, _Class);
    class->name       = className;
    class->fields   = NewThis(class, NULL);
    ClassRegisterInScope(class);
    class->lineno = yylineno;
    class->methods  = ClassInitConstructor(class, classParamDecl, NULL);    

       
    return class;
}

Class ClassDeclComplete(MethodCall extendsCall, 
                Instr     constructorBody, 
                Var       fieldDecl, 
                Method    methodDecl){
       Class class = CurrentClass; 
       class->extends    = extendsCall;         

       class->scope = ScopeNew(class->name, NULL, NULL,  class->fields);
       class->scope->method = methodDecl ;
             
       if ( extendsCall != NULL ) {
            class->fields->next = NewSuper(class->extends->class, NULL);
            class->fields->next->next = fieldDecl; 
            class->scope->next =   class->extends->class->scope;
       } else {
            class->fields->next = fieldDecl ; 
       }

       class->methods->bodyInstr = constructorBody;        
       class->methods->next = methodDecl;        
       ScopeInitForClass(class); 
       ClassDefPrint(class);
       return class;         
}

Var NewThis(Class class, Expr e){ 
    Var v = NEW(1, _Var);
    char* varname;
    varname = (char*) malloc(12 * sizeof(char));
    sprintf(varname, "this");
    v->name = varname;
    v->class = class;
    v->value  = e;
    v->lineno = yylineno;
    
    return v;
}

Var NewSuper(Class class, Expr e){ 
    Var v = NEW(1, _Var);
    char* varname;
    varname = (char*) malloc(12 * sizeof(char));
    sprintf(varname, "super");
    v->name = varname;
    v->class = class;
    v->value  = e;
    v->lineno = yylineno;
    
    return v;
}

Method ClassInitConstructor(Class class, Var classParamDecl, Instr constructorBody){

    Method method = MethodDecl("constructor", classParamDecl, class->name, constructorBody, NULL);
    return method;
}



void ClassPrint(Class c){
    printPadding(); printf("Class : %s\n", c->name);
    incPaddingNb();
    Var field = c->fields;
    while(field != NULL){
          printPadding(); 
          if ( field->value == NULL )  
          printf("%s : %s Op = NULL \n", field->name,  field->class->name);
          else 
          printf("%s : %s Op = %d\n", field->name,  field->class->name, field->value->value.i);
          field = field->next;
    }
    incPaddingNb();
}     

void OverrideMethodDeclAssertIsOk(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr){
    printf("Not implemented\n");
} 
Method OverrideMethodDecl(char* name, Var paramDecl, char* returnClassName, Instr methodBody, Expr expr){
    Method method       =   MethodDecl(name, paramDecl,returnClassName, methodBody, expr);    
    method->isOverride    = TRUE;  
    return method;
}

Method StaticMethodDeclAssertIsOk(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr){
    printf("Not implemented\n");
    return NEW(1, _Method);
} 
Method StaticMethodDecl(char* name, Var paramDecl, char* returnClassName, Instr methodBody, Expr expr){
    Method method       =   MethodDecl(name, paramDecl,returnClassName, methodBody, expr);    
    method->isStatic    = TRUE;        
    return method; 
}

void MethodDeclAssertIsOk(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr){
    printf("Not implemented\n");
    
} 
Method MethodDecl(char* name, Var paramDecl, char* returnClassName, Instr bodyInstr, Expr bodyExpr){
    Method method       = NEW(1, _Method);
    method->name        = name; 
    method->isOverride  = FALSE;
    method->isStatic    = FALSE;
    method->params      = paramDecl;
    method->lineno      = yylineno;
    AssertClassExists(returnClassName); 
    AssertMethodAreNotDupliqued(method);
    method->returnClassName = returnClassName;
    
    if ( bodyInstr == NULL )  {
        method->bodyExpr = bodyExpr;    
     }
    else { 
        method->bodyInstr = bodyInstr;  
    }
        
    return method; 
} 
 
Method MethodDeclParamSetNext(Method method, Method next){
    Method i = method; 
    while ( i->next != NULL ) {    
        i = i->next;
    }
    i->next = next;
    return method; 
} 


Method MethodDeclSetNext(Method method, Method next){
    Method i = method; 
    while ( i->next != NULL ) {    
        i = i->next;
    }
    i->next = next;
    return method; 
} 



void ClassDefPrint(Class cl) {
    printPadding();printf("Defined Class : %s\n", cl->name);
}



/* Cree les classes predefinies si elles ne sont pas deja définies 
 * par defaut et y ajoute la definition de la classe passée en parametre 
 */
Class defaultClassDefsPlus(Class classDefs) {
   
    printf("Begin initIntegerClass \n");
    Integer = initIntegerClass();
    printf("Ended initIntegerClass \n");
    String  = initStringClass();
    Void    = initVoidClass();
    
    Integer->next = String;
    Integer->next->next = Void;
    
    Integer->next->next->next = classDefs;
    
    AllDefinedClasses = Integer;
    return AllDefinedClasses;  
}



Var ParamDeclSetNext(Var param, Var next){
    Var i = param; 
    while ( i->next != NULL ) {    
        i = i->next;
    }
    i->next = next;
    return param; 
}

void ParamDeclAssertIsOk(char* name, char* classType){
    printf("ParamDeclAssertIsOk Not implemented\n");
}

Var ParamDecl(char* name, char* className){
    Var  v = NEW(1, _Var);
    v->name = name;
    v->class = GetClassByName(className);
    v->lineno = yylineno;
    
    return v;
}

 


Class GetClassByName(char* className){
    Class class = AllDefinedClasses; 
    while ( class != NULL  && strcmp(class->name, className) != 0 )
         class = class->next;
    return class;
}


void ExtendsDeclAssertIsOk( char* className, Expr expr){
     char message[128];
    /* Il est impossible d'etendre les 3 classes predefinies Integer String et Void  */
    if (   strcmp(className, "Integer") == 0
        || strcmp(className, "String")  == 0
        || strcmp(className, "Void")    == 0 )  {
        sprintf(message, "Impossible d'etendre la classe predefinie %s \n", className);
        PrintError(message, yylineno);
        exit(1);
    }
    /* Il est impossible d'etendre une classe qui n'existe pas  */
    Class c = GetClassByName(className);
    if ( c == NULL ){ 
        sprintf(message, "Impossible d'etendre la classe %s qui n'existe pas\n", className);
        PrintError(message, yylineno);
        exit(1);
     }
}

void AssertClassExists( char* className ) {
    char message[128];
    Class c = GetClassByName(className);
    if ( c == NULL ){ 
        sprintf(message, "Operation impossible. la classe %s  n'existe pas\n", className);
        PrintError(message, yylineno);
        exit(1);
     } 
}

MethodCall ExtendsDecl(char* className, Expr expr, char* methodName){
    MethodCall extendsCall =  NEW(1, _MethodCall);
    extendsCall->class = GetClassByName(className);
    extendsCall->args = expr;
    
    extendsCall->methodName = methodName;     
    return extendsCall;
}

void ConstructorBodyAssertIsOk(Instr consBody){
    printf("ConstructorBodyAssertIsOk Not implemented\n");
}


Class ClassDeclSetNext(Class class, Class next){
    return class;
}


void AssertMethodAreNotDupliqued(Method method){ 

    if ( method == NULL  ) 
        return; 
        
 
    char message[128];
    Var i = method->params; 
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
   
}


bool MethodHasSameSignature(Method m1, Method m2){
    
    if ( m1 == NULL || m2 == NULL )
        return FALSE;
    
    if ( strcmp(m1->name, m2->name) != 0 )
        return FALSE;
    
    Var p1 = m1->params;
    Var p2 = m2->params;
    if ( (p1 != NULL && p2 == NULL) || (p1 == NULL && p2 != NULL) ) 
        return FALSE;
        
    while ( p1 != NULL ) {
        if ( strcmp(p1->class->name, p2->class->name) != 0 ) 
            return FALSE;
            
        p1 = p1->next;
        p2 = p2->next;
        if ( (p1 != NULL && p2 == NULL) || (p1 == NULL && p2 != NULL) ) 
            return FALSE;
    }
    
    if ( strcmp(m1->returnClassName, m2->returnClassName) != 0 ) 
        return FALSE;      
    
    return TRUE;
}


bool IsMethodOverrideSomething(Method method, Class class){
    
    if  ( class == NULL || method == NULL ) 
        return FALSE;
       
    Class cl = class; 
    Method m = cl->methods->next; /* On saute le constructeur */  
      
    while ( m != NULL ) {
        if ( MethodHasSameSignature(m, method) == TRUE )
            return TRUE; 
        m = m->next;
    } 
    
    if ( cl->extends == NULL ) 
        return FALSE;

    bool result;  
    result = IsMethodOverrideSomething(method, cl->extends->class);
    return result;
}


void ClassDeclAssertIsOk(Class class) {
    char message[128];

     Method m = class->methods->next; /* On saute le constructeur */ 
     Method z;
     Class current = class;
     Class super = ( class->extends == NULL ) ? NULL : class->extends->class ;
     bool onCurrentClass = TRUE;
     while ( m != NULL ) {
        current = class ; 
        z = m->next; 
        onCurrentClass = TRUE;
        if ( m->isOverride == TRUE && IsMethodOverrideSomething(m, super) == FALSE ) {
            sprintf(message, "La methode %s ne redefinit rien du tout !", m->name);
            PrintError(message, m->lineno);
            exit(1);
        }             
        while ( z != NULL ) {    
            if ( strcmp(m->name, z->name) == 0 ) {
                            
                if ( onCurrentClass == TRUE ) {
                    sprintf(message, "La surchage ou la duplication de la methode %s n'est pas authorisée dans une classe ", m->name);
                    PrintError(message, m->lineno);
                    exit(1);
                } else {
                    /* Une methode au meme nom qu'une autre dans une classe MERE est une erreur si :
                       Elles n'ont pas les mêmes parametres et type de retour ( car il s'agit d'une surchage et elles sont interdites  */
                    if ( MethodHasSameSignature(m,z) == FALSE ) {
                        sprintf(message, "La surchage de la methode %s de la classe %s n'est pas autorisee dans la classe %s", z->name, current->name, class->name);
                        PrintError(message, m->lineno);
                        exit(1);
                    }
                    
                    /* Une methode au meme nom qu'une autre dans une classe MERE est une erreur si :
                         si elles ont la meme signature ET la premiere n'a pas de mot clé ovverride  */
                    if ( MethodHasSameSignature(m,z) == TRUE &&  m->isOverride == FALSE ) {
                        sprintf(message, "La methode %s de la classe %s doit avoir le mot cle override : Elle est deja definie dnas la classe %s", m->name,  class->name, current->name);
                        PrintError(message, m->lineno);
                        exit(1);
                    }
                 }       
            } 
            z = z->next;
            if ( z == NULL ) {
                if ( current->extends != NULL ) {
                    current = current->extends->class;
                    if ( current != NULL ) {
                        z = current->methods->next; /* On saute le constructeur */
                     }
                    onCurrentClass = FALSE ;
                }
            }
        }        
        m = m->next;
     }
}       

void AssertClassIsNotDupliqued(char*  className){
    char message[128];
    Class c = GetClassByName(className);
    if ( c != NULL ){ 
        sprintf(message, "Classe %s deja définie", className);
        PrintError(message, yylineno);
        exit(1);
     }
}

void AssertClassInstanciationIsOk(Class class , Expr expr, int lineno){
    char message[128];
    
    /* Toute class instanciée doit forcement exister au préalable  */
    Class c = (class == NULL ) ? NULL : GetClassByName(class->name);
    
    if ( c == NULL ){ 
        sprintf(message, "Instanciation impossible Classe %s non définie", class->name);
        PrintError(message, lineno);
        exit(1);
     }
     
    /* Verification du nombre et du type d'arguments */
    Expr e = expr;
    Var consParams = NULL; 
    if ( c->methods != NULL ) 
        consParams =  c->methods->params;
    bool terminate = FALSE;

    while ( terminate != TRUE ){
        if ( e == NULL && consParams == NULL  ) {
            terminate = TRUE;
        } 
        else {  
            if (  (consParams == NULL && e != NULL) || (consParams != NULL && e == NULL)  ) { 
                sprintf(message, "Nombre d'arguments incorrect pour l'appel au constructeur");
                PrintError(message, lineno);
                exit(1);
            }
            if ( ClassLeftInheritsRight(e->type, consParams->class) == FALSE ) {
                sprintf(message, "Le parametre %s est de type %s. Le type effectivement attendu est %s\n", consParams->name, e->type->name, consParams->class->name);
                PrintError(message, lineno);
                exit(1);
            }
            e = e->next; 
            consParams = consParams->next; 
        }
     }
}   

bool ClassLeftInheritsRight(Class left, Class right){
    if ( strcmp(left->name, right->name) == 0 ) 
        return TRUE;
    
    bool result; 
    if ( left->extends != NULL ) {
        result =  ClassLeftInheritsRight(left->extends->class, right);
        return result ; 
    }
            
    return FALSE;

}

Var ClassGetFieldByName(Class class, char* fieldName){
    Var field = class->fields; 
    while( field != NULL ) {
        if ( strcmp(field->name, fieldName) == 0 ) 
            break;
        field = field->next;
    }
    if ( field == NULL ) {
        if ( class->extends != NULL ) {
            return ClassGetFieldByName(class->extends->class, fieldName); 
        }
    }         
    return field;
}


Expr ClassNewInstanceOf(char* className, Expr args) {
     
    Class instance = NEW(1, _Class);
    
    Expr expr = NEW(1, _Expr);
    
    Class class =  GetClassByName(className);
    
    instance->name       = class->name;
    instance->consParams = class->consParams;
    instance->extends    = class->extends;
    instance->consBody   = class->consBody;   
    instance->methods    = class->methods;

    Var vinst = NewThis(class, expr);
    instance->fields     = vinst;
    vinst->next = instance->fields->next; /* On prend le next pour sauter la premiere varable de champ qui est "this" */
    Var vclass = class->fields;
    Expr e = args; 
    while (e != NULL ) {
        vinst = NEW(1, _Var);
        vinst->name = vclass->name;
        vinst->lineno = vclass->lineno;
        vinst->class = vclass->class;
        vinst->value = e; /*Seule valeur a supprimer quand on voudra liberer de la memoire les autres sont partagés avec vclass */
        
        e = e->next;
        vinst = vinst->next;
        vclass = vclass->next;
    } 
    
    expr->op = INSTANCE;
    expr->type = instance;
    expr->lineno = yylineno;
    expr->isEvaluated = TRUE;
    
    expr->value.instance = instance;
    return expr;
}


Method GetMethod(Class class, char* methodName) {
    Method m = class->methods;
    while( m != NULL ) {
        if ( strcmp(m->name, methodName) == 0 ) {
            return m;
        }
        m = m->next ; 
    }
    return NULL;
}

void  ReplaceVarInExpr(Expr e, char* varName, Var v){
    Var t = v;
    bool declared = FALSE; 
    char message[128];
    switch(e->op) {
        case CONST_INT      :  
        case CONST_VOID     : 
        case CONST_STR      :  
        case INSTANCE       : return ;
        case ADD            : 
        case SUB            :           
        case DIV            :
        case MUL            :
        case CONCAT         :  
            ReplaceVarInExpr(e->left,  varName, v);
            ReplaceVarInExpr(e->right, varName, v); 
            return ;
        case SELECTION      : 
            ReplaceVarInExpr(e->left, varName, v);
            ExprAssertFieldAccessIsOk(e->left, e->value.s);      
            return ;
        case VAR_CALL   :
             while ( t != NULL ) {
                 if ( strcmp(e->value.s, t->name) == 0 ) {
                    declared = TRUE ; 
                    break; 
                 }  
                 t = t->next;
             }
             if ( declared == FALSE ) {        
                sprintf(message, "Identifant %s inconnu\n", e->value.s);
                PrintError(message, e->lineno);
                exit(1);
             }
             if ( strcmp(e->value.s, varName) == 0 ) {
                e->type = v->class;
             }
             return ;
        default : printf("ReplaceVarInExpr Non encore implementée \n "); break;     
    }           
                
}

void ClassTypeAndRedirect(Class class){
    char message[128];
    
     /* Typer et rediriger les arguments de Extends : extends->args*/
     Expr e;
     Var v;
      
     if ( class->extends != NULL ) {
         Method method = GetMethod(class->extends->class, class->extends->methodName);
         if ( method == NULL ) {
            sprintf(message, "%s() introuvabe dans la class %s \n",class->extends->methodName, class->extends->class->name); 
            PrintError(message, class->extends->args->lineno );         
            exit(1);
         }
         
         e = class->extends->args;
         
         while ( e != NULL ) {
             v = class->methods->params;
             while ( v != NULL ) {
                ReplaceVarInExpr(e, v->name, class->methods->params);
                v = v->next; 
             } 
             e = e->next; 
         }
         
         /*A cette etape, tous les arguments de extends sont Types : Donc si un seul ne l'est pas à cette etape, il y a une erreur */
         e = class->extends->args;
         while ( e != NULL ) {
            if ( e->type == NULL ) {
                sprintf(message, "Identifiant %s inconnu pour l'appel de %s() \n", e->value.s,    class->extends->class->name); 
                PrintError(message, class->extends->args->lineno );         
                exit(1);
            }
            e = e->next;
         }
         /*On verifie que l'appel a exteds est bien correcte */
         AssertClassInstanciationIsOk(class->extends->class, class->extends->args, class->lineno);
    } 
   
    
     /* Typer et rediriger le corps du constructeur */
     Method method = GetMethod(class, "constructor");
     
     if ( method != NULL) {
         Scope sc = method->scope; 
         ReplaceVarInInstr(method->bodyInstr, sc);
         
     }
     
     
     /* Typer et rediriger les champs de la classe  */
     Var fields = class->fields;
     
     if ( fields != NULL ) 
        fields = fields->next; /* On saute le premier fields qui est this */
        /* printf("Dans les camps Class : %s\n\n", class->name); */
     Scope sc = ScopeNew("Class", NULL,  NULL, class->fields);
     while( fields != NULL  ) {
         e = fields->value;
         if ( e != NULL ) {     
            ReplaceExprViaScope(e, sc);
            ExprAssertInheritsType(fields->class, fields->value);
         }     
         fields = fields->next;
     } 
     
     /* Typer et rediriger le corps des methodes */
     if (  strcmp(class->name, "Integer") == 0
        || strcmp(class->name, "String")  == 0
        || strcmp(class->name, "Void")    == 0 )  {
        printf(" A ne pas oublier !!\n");
        return ;
    }
     method = class->methods->next;
     while ( method != NULL ) {
          if ( method->bodyExpr == NULL ) {
                ReplaceVarInInstr(method->bodyInstr, method->scope);
                if ( strcmp(method->returnClassName, method->bodyInstr->yield->type->name) != 0  ) {
                    sprintf(message, "Le type de retour declaree n'est pas compatible avec le bloc (%s) := (%s)", method->returnClassName, method->bodyInstr->yield->type->name);
                    PrintError(message, method->lineno);
                    exit(1);
               }
           } else {
               
               ReplaceExprViaScope(method->bodyExpr, method->scope);
                 if ( strcmp(method->returnClassName, method->bodyExpr->type->name) != 0  ) {
                    sprintf(message, "Le type de retour declaree n'est pas compatible avec le bloc (%s) := (%s)", method->returnClassName, method->bodyExpr->type->name);
                    PrintError(message, method->lineno);
                    exit(1);
               }
           }
           
           method = method->next;
     }
     
     /*
     if (  strcmp(class->name, "Integer") == 0
        || strcmp(class->name, "String")  == 0
        || strcmp(class->name, "Void")    == 0 )  {
        return ;
    }
     printf("\n\nDans la class %s\n", class->name);
     Method m = class->methods->next;
     while ( m != NULL ) {
        if ( m->bodyExpr == NULL ) {
            printf("\t%s() ", m->name); 
            printf("de type %s", m->returnClassName);
            printf("\t\t Body de type  %s\n", m->bodyInstr->yield->type->name);
       } 
       else  {
            printf("\t%s() ", m->name); 
            
            printf("de type %s", m->returnClassName);
            printf("\t\t Body de type %s\n", m->bodyExpr->type->name);
        }
        m = m->next;
    }
    */
}


void ReplaceVarInInstr(Instr instr, Scope sc){
    
    if ( instr == NULL ) 
        return ;
   
    Instr i = instr;
    Scope s;
    switch(instr->op) { 
        case RETURN     :  
        case EXPR       :          
            ReplaceExprViaScope(instr->expr, sc);
            break;
        case ASSIGN     : 
            ReplaceExprViaScope(instr->leftExpr, sc);
            ReplaceExprViaScope(instr->rightExpr, sc); 
            InstrAssertAssignIsOk(instr->leftExpr, instr->rightExpr);
            break;
        case FN_BLOC    :
        case PROC_BLOC  : 
        case INSTR_BLOC :
            if ( instr->op == FN_BLOC ) 
                ReplaceExprViaScope(instr->yield, sc);
                            
            i = instr->listInstr;
            
            if ( instr->op == INSTR_BLOC ) 
                s = sc; 
            else 
                s = ScopeNew("Scope Anonyme\0", NULL, sc, i->var);

            while ( i != NULL ) {
                ReplaceVarInInstr(i, s); 
                i = i->next ; 
            } 
            instr->yield = InstrGetReturnExpr(instr);
            
            break;
        case IF         : 
            ReplaceExprViaScope(instr->cond, sc);            
            ReplaceVarInInstr(instr->thenInstr, sc);
            ReplaceVarInInstr(instr->elseInstr, sc);
            break;
        
        default : printf("ReplaceVarInInstr Non encore implementée  instr->op : %d\n ", instr->op); break;     
    }
}  

   
void ReplaceExprViaScope(Expr expr, Scope scope){
    
    if ( expr == NULL || scope == NULL ) 
        return ;
        
    bool declared = FALSE; 
    char message[128];
    Scope sc ; 
    Var v;
    Method m;
    switch(expr->op) {
        case CONST_INT      :  
        case CONST_VOID     : 
        case CONST_STR      :  
        case INSTANCE       : return ;
        case ADD            : 
        case SUB            :           
        case DIV            :
        case MUL            :
        case CONCAT         :  
            ReplaceExprViaScope(expr->left, scope);
            ReplaceExprViaScope(expr->right, scope); 
            return ;
        case SELECTION      :
            ReplaceExprViaScope(expr->left, scope);
            ExprAssertFieldAccessIsOk(expr->left, expr->value.s);
            return ;
        case VAR_CALL   : 
             /* La variable a t elle ete declaree dans le scope ?  */
             v  = FindVarInScope(expr->value.s, scope);
             if (  v == NULL ) {        
                sprintf(message, "Identifant %s inconnu\n", expr->value.s);
                PrintError(message, expr->lineno);
                exit(1);
             }
             expr->type = v->class;
             return ;
        case INSTANCE_METHOD_CALL : 
             printf("Method %s.%s \n", expr->left->type->name, expr->value.m->methodName); 
             ReplaceExprViaScope(expr->left, scope);
             m = FindMethodInScope(expr->left->type->name,  scope);
             if ( m == NULL ) {        
                sprintf(message, "Method %s inconnue dans la classe %s\n",  expr->value.m->methodName,  expr->left->type->name);
                PrintError(message, expr->lineno);
                exit(1);
             }
             expr->value.m->class = m->class;
             expr->type = m->class;
             
            /*
                        
            Expr ExprFromMethodAccess(Expr e1, char* name, Expr args){
                Expr expr = NEW(1, _Expr);
                MethodCall methodCall = NEW(1, _MethodCall);
                methodCall->methodName = name;
                methodCall->args = args;
                expr->left = e1;
                expr->value.m = methodCall;
                expr->op =  INSTANCE_METHOD_CALL;
                expr->isEvaluated = FALSE;
                expr->lineno = yylineno;
             
                return expr;
            }
            
            */
             return;
        default : printf("ReplaceExprViaScope Non encore implementée op %d \n ", expr->op); break;     
    } 
}


