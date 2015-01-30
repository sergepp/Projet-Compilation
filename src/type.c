#define ID_NAME_MAX_SIZE 50

extern int yylineno;

extern char* yytext; 
 
Class Integer;

Class String;

Class Void;

Class AllDefinedClasses;





void PrintError(char* message);

void PrintError(char* message){
    printf(ANSI_COLOR_RED);
    printPadding(); printf("[ Erreur ] %s\n", message );
    printf(ANSI_COLOR_RESET "\n");
}

 


/*

Var ParamDeclSetNext(Var param, Var next);
void ParamDeclAssertIsOk(char* name, char* classType);
Var ParamDecl(char* name, char* classType);


void ExtendsDeclAssertIsOk( char* classType, Expr expr);
Instruction ExtendsDecl(char* classType, Expr expr);
void ConstructorBodyAssertIsOk(Instr consBody);


Class ClassDeclSetNext(Class class, Class next);
void ClassDeclAssertIsOk(char* className, Var classParamDecl ,Instruction extendsDecl, Instruction constructorBody, Var fieldDecl, Method methodDecl);       
Class ClassDecl(char* className, Var classParamDecl ,Instruction extendsDecl, Instruction constructorBody, Var fieldDecl, Method methodDecl);       
   

void StaticVarDeclAssertIsOk(char* name, char* classType, Expr expr);
Var StaticVarDecl(char* name, char* classType);


void OverrideMethodDeclAssertIsOk(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr); 
Method OverrideMethodDecl(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr);

Method StaticMethodDeclAssertIsOk(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr); 
Method StaticMethodDecl(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr);

void MethodDeclAssertIsOk(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr); 
Method MethodDecl(char* name, Var paramDecl, char* classType, Instr methodBody, Expr expr);  
 
Method MethodDeclParamSetNext(Method method, Method next);  

void ParamDeclAssertIsOk(char* name, char* classType); 
Var ParamDecl(char* name, char* classType);

*/ 


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

Var ParamDecl(char* name, char* classType){
    printf("Not implemented\n");
    return NEW(1, _Var);
}


Class GetClassByName(char* className){
    Class class = AllDefinedClasses; 
    while ( class != NULL  && strcmp(class->name, className) != 0 )
         class = class->next;
    return class;
}


void ExtendsDeclAssertIsOk( char* className, Expr expr){
     char* message[128];
    /* Il est impossible d'etendre les 3 classes predefinies Integer String et Void  */
    if (   strcmp(className, "Integer") == 0
        || strcmp(className, "String")  == 0
        || strcmp(className, "Void")    == 0 )  {
        sprintf(message, "Impossible d'etendre la classe predefinie %s \n", className);
        PrintError(message);
        exit(1);
    }
    
    /* Il est impossible d'etendre une classe qui n'existe pas  */
    Class c = GetClassByName(className);
    if ( c == NULL ){ 
        sprintf(message, "Impossible d'etendre la classe %s qui n'existe pas\n", className);
        PrintError(message);
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
    char* message[128];
    
    /* Toute nouvelle class créée ne doit pas deja Exister  */
    Class c = GetClassByName(className);
    if ( c != NULL ){ 
        sprintf(message, "Classe %s deja définie", className);
        PrintError(message);
        exit(1);
     }
     
    /* Une classe ne peut pas extends elle meme */
    if ( extendsCall != NULL && strcmp(className, extendsCall->class->name) == 0 ) {
        sprintf(message, "La classe %s ne peut pas s'etendre elle meme", className);
        PrintError(message);
        exit(1);
    }
    
    
}       

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
    class->next       = NULL;  
    ClassDefPrint(class);
    
    return class;
}
       
   

void StaticVarDeclAssertIsOk(char* name, char* classType, Expr expr){
    printf("Not implemented\n");
}
Var StaticVarDecl(char* name, char* classType){
    printf("Not implemented\n");
    return NEW(1, _Var);
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

void ExprAssertIDIsOk(char* name) {
    
}
















ClassType StringType() {
    ClassType StringType  = NEW(1, _ClassType);
    StringType->name  = (char*) malloc( ID_NAME_MAX_SIZE * sizeof(char) ) ;
    sprintf(StringType->name, "String");
    StringType->extends = NULL;
    return StringType;
}
 
Var IntegerFields() {
    Var IntegerFields  = NEW(1, _Var);
    IntegerFields->name  = (char*) malloc( ID_NAME_MAX_SIZE * sizeof(char) ) ;
    sprintf(IntegerFields->name, "value");
    IntegerFields->class  = Integer;
    IntegerFields->value = NULL;
    IntegerFields->next  = NULL;
    return IntegerFields;
}

Var StringFields() {
    Var fields  = NEW(1, _Var);
    fields ->name  = (char*) malloc( ID_NAME_MAX_SIZE * sizeof(char) ) ;
    sprintf(fields->name, "value");
    fields->class  = String;
    fields->value = NULL;
    fields->next  = NULL;
    return fields ;
}

/* Renvoi TRUE si e1 et e2 sont de la meme classe modulo heritage et FALSE sinon*/
bool ExprSameInstance(Expr e1, Expr e2) {
    return FALSE; /* STUB */
}

/* Renvoi TRUE si e1 et e2 sont de la meme classe et FALSE sinon*/
bool ExprSameClass(Expr e1, Expr e2) {
    return TRUE; /* STUB */
}

Expr ExprFromArithmetic(Expr left, int op, Expr right){
    
    Expr expr = NEW(1, _Expr);
    expr->left = left; 
    expr->op = op; 
    expr->right = right;
    expr->type = NULL;  

    return expr;
}

void ExprAssertInheritsSameClass(Expr e1, Expr e2){
    /*
    if ( e1 et e2 ont la meme classe modulo héritage ) {
        printf("[ Erreur ] Types incompatibles dans l'expression à ligne %d à coté de   %s\n", yylineno, yytext);
        exit(1);
    }
    */ 
}

void ExprAssertSameClass(Expr e1, Expr e2){
    /*
    if ( e1 et e2 ont la meme classe ) {
        printf("[ Erreur ] Types incompatibles dans l'expression à ligne %d à coté de   %s\n", yylineno, yytext);
        exit(1);
    }
    */ 
}

Expr ExprFromVoid(){
    Expr expr = NEW(1, _Expr);
    expr->left = NULL; 
    expr->op = CONST_VOID;
    expr->right = NULL;
    expr->type = NULL; 
    return expr;
}

Expr ExprFromInt(int value) {
    Expr expr = NEW(1, _Expr);
    expr->left = NULL; 
    expr->op = CONST_INT; 
    expr->value.i = value;
    expr->type = Integer; 
    expr->right = NULL;
    
    return expr;
}
Expr ExprFromString(char* string){
    
    Expr expr = NEW(1, _Expr);
    expr->left = NULL; 
    expr->op = CONST_STR; 
    expr->value.s = strdup(string);
    expr->type = NULL; 
    expr->right = NULL;
    
    return expr;
}
Expr ExprFromVar(){
    Expr expr = NEW(1, _Expr);
    return expr;
}
Expr ExprSetNext(Expr expr, Expr next){
    Expr i = expr; 
    while ( i->next != NULL ) {    
        i = i->next;
    }
    i->next = next;
    return expr; 
}

Expr ExprFromBoolean(Expr left, int op, Expr right){
    Expr expr = NEW(1, _Expr);
    expr->left = left; 
    expr->op = op; 
    expr->type = NULL; 
    expr->right = right;
    
    return expr;
}

Method IntegerAddMethod() {
    Method IntegerMethod = NEW(1, _Method); 
    IntegerMethod->name  = (char*) malloc( ID_NAME_MAX_SIZE * sizeof(char) ) ; 
    sprintf(IntegerMethod->name, "+");    
    IntegerMethod->isOverride = FALSE; 
    IntegerMethod->isStatic = FALSE;
    IntegerMethod->paramsCount = 1;
    IntegerMethod->params = NULL;    
    IntegerMethod->next = NULL;    
    IntegerMethod->this = NULL;
    IntegerMethod->body = ExprFromArithmetic(IntegerMethod->this, ADD, IntegerMethod->params);
    
    return IntegerMethod;
}

/* Renvoi la liste de toutes les methodes disponibles sur l'objet Integer */
Method IntegerMethods() {
    Method 
    IntegerMethods = IntegerAddMethod();    /*
    IntegerMethods->next  = IntegerSubMethod();
    IntegerMethods->next->next  = IntegerDivMethod();
    IntegerMethods->next->next->next  = IntegerModMethod();
    IntegerMethods->next->next->next->next  = IntegerModMethod(); */
    
    return IntegerMethods;
}

/* Renvoi la liste de toutes les methodes disponibles sur l'objet String */
Method StringMethods() {
    
    return NULL;
}

Class initStringClass() {
   
    String = NEW(1, _Class);
    String->name      = (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(String->name, "String");
    String->fields    = StringFields();
    String->methods   = StringMethods();
    String->consBody  = NULL;
    String->consParams = String->fields;
    String->extends   = NULL;
    String->next      = NULL;
    
    return String;  
}


Class initVoidClass() {
   
    Void = NEW(1, _Class);
    Void->name      = (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(Void->name, "Void");
    Void->fields    = NULL;
    Void->methods   = NULL;
    Void->consBody  = NULL;
    Void->consParams = NULL;
    Void->extends   = NULL;
    Void->next      = NULL;
    
    return Void;  
}


Class initIntegerClass() {
   
    Integer = NEW(1, _Class);
    Integer->name      = (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(Integer->name, "Integer");
    Integer->fields    = IntegerFields();
    Integer->methods   = IntegerMethods();
    Integer->consBody  = NULL;
    Integer->consParams = Integer->fields;
    Integer->extends   = NULL;
    Integer->next      = NULL;
    
    return Integer;  
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


void ClassRegisterInScope(Class cl){
     
    if ( AllDefinedClasses == NULL ){
        defaultClassDefsPlus(cl);
    }
    
    Class i = AllDefinedClasses ;
    while ( i->next != NULL ) {
        i = i->next;        
    }    
    i->next = cl;
}
    

void incPaddingNb(){
    PrintPaddingNb+= 4;
}
void decPaddingNb(){
    PrintPaddingNb-= 4;
}
void printPadding() {
    int i = 0;
    for (i = 0; i < PrintPaddingNb; i++ ) 
        printf("%c",  PrintPaddingChar);

}

Expr ExprArithmeticEval(Expr expr); 
Expr ExprEval(Expr expr);
Expr ExprArithmeticEval(Expr expr) {
    Expr rightTmp, leftTmp;
    leftTmp  =  ExprEval(expr->left); 
    rightTmp =  ExprEval(expr->right); 
    switch(expr->op) {
        case ADD        : expr->value.i = leftTmp->value.i + rightTmp->value.i ;break ; 
        case SUB        : expr->value.i = leftTmp->value.i - rightTmp->value.i ;break ;            
        case DIV        : expr->value.i = leftTmp->value.i / rightTmp->value.i ;break ; 
        case MUL        : expr->value.i = leftTmp->value.i * rightTmp->value.i ;break ; 
       
        default : PrintError("Evaluation Non pris en charge par la fonction : ExprArithmeticEval\n "); break;     
    }
    return expr;         
}

Expr ExprConcatEval(Expr expr) {
    Expr rightTmp, leftTmp;
    leftTmp  =  ExprEval(expr->left); 
    rightTmp =  ExprEval(expr->right); 
    switch(expr->op) {
        case CONCAT     : expr->value.s=strcat(leftTmp->value.s,rightTmp->value.s);break;
        default : PrintError("Erreur non concat : E\n "); break;     
    }
    return expr;         
}


Expr ExprEval(Expr expr) { 
  
    switch(expr->op) {
        case CONST_INT  :  
        case CONST_VOID :  
        case CONST_STR  : return expr;
        case ADD        : 
        case SUB        :           
        case DIV        :
        case MUL        : return ExprArithmeticEval(expr); 
        case CONCAT     : return ExprConcatEval(expr);         
        default : printf("Evaluation Non encore implementée \n "); break;     
    }
    return expr;     
}


void ExprPrintResult(Expr expr) {

    switch(expr->op){
        case ADD        :
        case SUB        :
        case MUL        :
        case CONST_INT  : printf("Integer = %d\n", expr->value.i);break;
        case CONST_VOID : printf("Void = void\n"); break;
        case CONST_STR  : printf("String = %s\n", expr->value.s);break;
        case CONCAT     : printf("String = %s\n", expr->value.s);break;
        default : printf("Affichage Non encore implementé \n "); break;     
    }
}

void ExprPrint(Expr expr) {
   incPaddingNb();
   printPadding();printf("Expression : \n"); 
   
   if ( expr == NULL ) {
        printPadding();printf("NULL\n");
   } 
    else {
        incPaddingNb();
        printPadding();
        switch(expr->op){
            case CONST_INT  : printf("Const Integer %d \n", expr->value.i); break ; 
            case CONST_STR  : printf("Const String  %s \n", expr->value.s); break ; 
            case ADD        : 
                               printf("left  : \n"); ExprPrint(expr->left); 
                printPadding();printf("op    : + \n"); 
                printPadding();printf("right : \n"); ExprPrint(expr->right);break ; 
            case SUB        : 
                               printf("left  : \n"); ExprPrint(expr->left); 
                printPadding();printf("op    : - \n"); 
                printPadding();printf("right : \n"); ExprPrint(expr->right);break ; 
            case MUL        : 
                               printf("left  : \n"); ExprPrint(expr->left); 
                printPadding();printf("op    : X \n"); 
                printPadding();printf("right : \n"); ExprPrint(expr->right);break ; 
            default : printf("Format d'affichage non reconnu \n "); break;     
        }
         decPaddingNb();
    } 
    decPaddingNb(); 
}

void InstrPrint(Instr inst) {
    
    Instr instrs = inst;
    incPaddingNb();
    while (instrs != NULL) {
        printPadding();
        switch(instrs->op) {
            case EXPR       : printf("Expression\n");   printPadding();   ExprPrintResult(ExprEval(instrs->expr)) ; break;
            case ASSIGN     : printf("Assign \n"); break;
            case INSTR_BLOC : printf("Bloc Instruction \n"); InstrPrint(instrs->listInstr); break;
            case PROC_BLOC  : printf("Bloc Procedural \n"); InstrPrint(instrs->listInstr); break;
            case FN_BLOC    : printf("Bloc Fonctionel\n"); InstrPrint(instrs->listInstr); break;
            case IF         : printf("If Then Else\n"); break;
            
            default : printf("Affichage de L'instruction Non encore implementée \n "); break;     
        }     
        instrs = instrs->next; 
    }    
    decPaddingNb();
}

void ClassDefPrint(Class cl) {
    printPadding();printf("Defined Class : %s\n", cl->name);
}

void ProgramPrint(Program prg) {
    printPadding();printf("Programme\n");
    
    Class classDefs = prg->classDefs;
     while (classDefs != NULL) {
        ClassDefPrint(classDefs);
        classDefs = classDefs->next; 
    }      
    
    Instr instrs = prg->instrs;
    while (instrs != NULL) {
        InstrPrint(instrs);
        instrs = instrs->next; 
    }    
}

void InstrEval(Instr instrs) { 

    switch(instrs->op) {
        case EXPR       : printf("Expr \n"); ExprPrintResult(ExprEval(instrs->expr)); break;
        case ASSIGN     : printf("Assign \n"); break;
        case PROC_BLOC  : printf("Proc Bloc \n"); break;
        case FN_BLOC    : printf("Fn Bloc \n"); break;
        case IF         : printf("If \n"); break;
        
        default : printf("Evaluation de L'instruction Non encore implementée \n "); break;     
    }  
}
void ProgramEval(Program program){
    Instr instrs = program->instrs;
    while (instrs != NULL) {
        InstrEval(instrs)  ; 
        instrs = instrs->next; 
    }
}

Program makeProgram(Class classDefs, Instr instrs){
    Program program = NEW(1, _Program);
    program->classDefs = AllDefinedClasses;
    program->instrs = instrs;
   /* ProgramPrint(program);
    ProgramEval(program); */
    return program;
}



