
Class ClassDecl(char*     className,
                Var       classParamDecl,
                ClassCall extendsCall, 
                Instr     constructorBody, 
                Var       fieldDecl, 
                Method    methodDecl) {
    
    Class class =  NEW(1, _Class);
    class->name       = className;
    class->consParams = classParamDecl;
    class->extends    = extendsCall;
    class->consBody   = constructorBody;    
    class->fields     = fieldDecl ;
    class->methods    = methodDecl;
    
    ClassRegisterInScope(class);   
    
    
    ClassAssertScopeAreCorrect(class);
    ClassDefPrint(class);
    
    return class;
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
Method StaticMethodDecl(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr){
    printf("Not implemented\n");
    return NEW(1, _Method);
}

void MethodDeclAssertIsOk(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr){
    printf("Not implemented\n");
    
} 
Method MethodDecl(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr){
    printf("Not implemented\n");
    return NEW(1, _Method);
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
    Var v = NEW(1, _Var);
    v->name = name;
    v->class = GetClassByName(className);

    
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

ClassCall ExtendsDecl(char* className, Expr expr){
    ClassCall extendsCall =  NEW(1, _ClassCall);
    extendsCall->class = GetClassByName(className);
    extendsCall->args = expr;
     
    return extendsCall;
}

void ConstructorBodyAssertIsOk(Instr consBody){
    printf("ConstructorBodyAssertIsOk Not implemented\n");
}


Class ClassDeclSetNext(Class class, Class next){
    return class;
}

void ClassDeclAssertIsOk(char* className, Var classParamDecl ,ClassCall extendsCall, Instr constructorBody, Var fieldDecl, Method methodDecl){
    char message[128];
    
    /* Toute nouvelle class créée ne doit pas deja Exister  */
    Class c = GetClassByName(className);
    if ( c != NULL ){ 
        sprintf(message, "Classe %s deja définie", className);
        PrintError(message, extendsCall->args->lineno);
        exit(1);
     }
     
    /* Une classe ne peut pas extends elle meme */
    if ( extendsCall != NULL && strcmp(className, extendsCall->class->name) == 0 ) {
        sprintf(message, "La classe %s ne peut pas s'etendre elle meme", className);
        PrintError(message, extendsCall->args->lineno);
        exit(1);
    }
    
    
}       

   





