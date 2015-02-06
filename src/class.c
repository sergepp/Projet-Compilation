
Class ClassDecl(char*   className, Var classParamDecl) {
    
    Class class =  NEW(1, _Class);
    class->name       = className;

    class->fields   = NewThis(class, NULL);
    class->methods  = ClassInitConstructor(class, classParamDecl, NULL);    
    return class;
}

Class ClassDeclComplete(MethodCall extendsCall, 
                Instr     constructorBody, 
                Var       fieldDecl, 
                Method    methodDecl){
       Class class = CurrentClass; 
       class->extends    = extendsCall;         
       class->fields->next = fieldDecl;   

       class->methods->bodyInstr = constructorBody; 
       class->methods->next = methodDecl;        
       
       ScopeInitForClass(class);
    
       /* On verifie que le constructeur est correcte du point de vue des assignations*/
       /* AssertInstrAssignIsOk(constructorBody);*/
       ClassRegisterInScope(class);   
        
       /* ClassAssertScopeAreCorrect(class);*/
       /* ClassUpdateRefToFieldsOf(class);  */
       ClassDefPrint(class);
        
       return class;         
}

Var NewThis(Class class, Expr e){
    Var v = VarDecl("this", class->name, e) ; 
    return v;
}

Method ClassInitConstructor(Class class, Var classParamDecl, Instr constructorBody){

    Method method = MethodDecl("constructor", classParamDecl, class->name, constructorBody, NULL);
    return method;
}

/*
void  ClassUpdateRefToFieldsOf(Class class) {

    Instr k = class->consBody; 
    if ( class->consBody != NULL && class->fields != NULL ) {
        k = class->consBody->listInstr;
        Var v, tmpVar;
        Expr e , f;
        while ( k != NULL ) {
            v = class->fields;
            while( v != NULL ) {
               switch(k->op) {
                    case EXPR   : e = k->expr;                          break;
                    case ASSIGN : e = k->leftExpr; f = k->rightExpr;    break;
                    case IF     : e = k->cond;                          break;
                    default : 
                        PrintError("Operateur de l'Instruction inconnu dans ClassUpdateRefToFieldsOf \n ", -1); 
                        exit(1);
                        break;      
               }
               if ( e != NULL && e == VAR_CALL ) {
                    tmpVar = GetFieldByName(e->value.s);
                    if ( tmpVar != NULL ) 
                        k = v;
                            
               }
               v = v->next;
        }
        k = k->next;
        
    }    
    
}
*/

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
Method OverrideMethodDecl(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr){
    printf("Not implemented\n");
    return NEW(1, _Method);
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
Method MethodDecl(char* name, Var paramDecl, char* returnClassName, Instr methodBody, Expr expr){
    Method method       = NEW(1, _Method);
    method->name        = name; 
    method->isOverride  = FALSE;
    method->isStatic    = FALSE;
    method->params      = paramDecl;
    method->returnClassName = returnClassName;
    if ( methodBody == NULL )  { method->bodyExpr = expr; }
    else { method->bodyInstr = methodBody;}
        
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
 * par defaut et y ajoute la definition de la classe passée en paraletre 
 */
Class defaultClassDefsPlus(Class classDefs) {
   
    Integer = initIntegerClass();
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

void ClassDeclAssertIsOk(Class class) {
    char message[128];
    
    /* Toute nouvelle class créée ne doit pas deja Exister  
    Class c = GetClassByName(class->name);
    if ( c != NULL ){ 
        sprintf(message, "Classe %s deja définie", class->name);
        PrintError(message, class->extends->args->lineno);
        exit(1);
     }
     
    /* Une classe ne peut pas extends elle meme 
    if ( class->extends != NULL && strcmp(class->name, class->extends->class->name) == 0 ) {
        sprintf(message, "La classe %s ne peut pas s'etendre elle meme", class->name);
        PrintError(message,  class->extends->args->lineno);
        exit(1);
    }   
    */ 
}       


void AssertClassInstanciationIsOk(char* className, Expr expr){
    char message[128];
    
    /* Toute class instanciée doit forcement exister au préalable  */
    Class c = GetClassByName(className);
    
    if ( c == NULL ){ 
        sprintf(message, "Instanciation impossible Classe %s non définie", className);
        PrintError(message, expr->lineno);
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
                sprintf(message, "Nombre d'argument incorrecte pour l'appel au constructeur");
                if ( expr == NULL )
                    PrintError(message, yylineno);
                else 
                    PrintError(message, expr->lineno);
                exit(1);
            }
            if ( ClassLeftInheritsRight(e->type, consParams->class) == FALSE ) {
                sprintf(message, "Le parametre %s est de type %s. Le type effectivement attendu est %s\n", consParams->name, e->type->name, consParams->class->name);
                PrintError(message, expr->lineno);
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
    
    if ( left->extends != NULL ) {
        return ClassLeftInheritsRight(left->extends->class, right);
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
    
    /* AssertClassInstanciationIsOk(className, args); */
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
        case CONCAT     :  
            ReplaceVarInExpr(e->left, varName, v);
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
        default : printf("Evaluation Non encore implementée \n "); break;     
    }           
                
}

void ClassTypeAndRedirect(Class class){
    char message[128];
    
    printf(" ClassTypeAndRedirect %s \n", class->name);
     /* Typer et rediriger les arguments de Extends : extends->args*/
     Expr e;
     if ( class->extends != NULL ) {
         Method method = GetMethod(class->extends->class, class->extends->methodName);
         if ( method == NULL ) {
            sprintf(message, "%s() introuvabe dans la class %s \n",class->extends->methodName, class->extends->class->name); 
            PrintError(message, class->extends->args->lineno );         
            exit(1);
         }
         Var v;
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
                sprintf(message, "Identifiant %s inconnue pour l'appel de %s() \n", e->value.s,    class->extends->class->name); 
                PrintError(message, class->extends->args->lineno );         
                exit(1);
            }
            e = e->next;
         }
         /*On verifie que l'appel a exteds est bien correcte */
         
         AssertClassInstanciationIsOk(class->extends->class->name, class->extends->args);
    }
     /*TypeArg(method, name);
     /*ScopePrint(class->extends->scope);*/
     exit(1);
     
     /*
     
typedef struct __MethodCall {
  struct __Class* class;
  Expr args;
  char* methodName;
} _MethodCall, *MethodCall;

     */
     /* Typer et rediriger le corps du constructeur */
     
     /* Typer et rediriger les champs de la classe  */
     
}

