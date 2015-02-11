 

void PrintError(char* message, int lineno){
    printf(ANSI_COLOR_RED);
    printPadding(); printf("[ Erreur ] Ligne %d  %s \n", lineno, message );
    printf(ANSI_COLOR_RESET "\n");
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
    return fields ;
}



Method IntegerInitMethod(char* methodName, char* returnClassName, Var params) {
    
    Method method       = NEW(1, _Method);
    method->name        = methodName;
    method->isOverride  = FALSE;
    method->isStatic    = FALSE;
    method->params      = params;
    method->lineno      = -1;   
    method->returnClassName = returnClassName;
    if ( strcmp("+", methodName) == 0  ) method->bodyExpr = ExprFromArithmetic(method->this, ADD, method->params->value);
    if ( strcmp("-", methodName) == 0  ) method->bodyExpr = ExprFromArithmetic(method->this, SUB, method->params->value);
    if ( strcmp("/", methodName) == 0  ) method->bodyExpr = ExprFromArithmetic(method->this, DIV, method->params->value);
    if ( strcmp("*", methodName) == 0  ) method->bodyExpr = ExprFromArithmetic(method->this, MUL, method->params->value);
    
    return method;
}



/* Renvoi la liste de toutes les methodes disponibles sur l'objet Integer */
Method IntegerMethods() {
    Var param = VarDecl("arg0", "Integer", NULL);
    Method 
    IntegerMethods = IntegerInitMethod("+", "Integer", param); 
    IntegerMethods->next  =  IntegerInitMethod("-", "Integer", param);
    IntegerMethods->next->next  = IntegerInitMethod("/", "Integer", param);
    IntegerMethods->next->next->next  = IntegerInitMethod("*", "Integer", param);
    IntegerMethods->next->next->next->next  = printMethod();
    IntegerMethods->next->next->next->next->next  = printlnMethod();
    IntegerMethods->next->next->next->next->next->next  = toStringMethod();
    
    
    return IntegerMethods;
}



Method printMethod(){

    Method method       = NEW(1, _Method);
    method->name        = (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(method->name, "print"); 
    method->isOverride  = FALSE;
    method->isStatic    = FALSE;
    method->params      = NULL;
    method->lineno      = -1;   
    method->returnClassName = (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(method->returnClassName, "Void");  
    return method;  
}
Method printlnMethod(){
    Method method       = NEW(1, _Method);
    method->name        = (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(method->name, "println"); 
    method->isOverride  = FALSE;
    method->isStatic    = FALSE;
    method->params      = NULL;
    method->lineno      = -1;   
    method->returnClassName = (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(method->returnClassName, "Void");    
    return method;
}

Method toStringMethod(){
    Method method       = NEW(1, _Method);
    method->name        =   (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(method->name, "toString"); 
    method->isOverride  = FALSE;
    method->isStatic    = FALSE;
    method->params      = NULL;
    method->lineno      = -1;   
    method->returnClassName = (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(method->returnClassName, "String");   
    return method; 
}


/* Renvoi la liste de toutes les methodes disponibles sur l'objet String */
Method StringMethods() {
    Method 
    StringMethods = printMethod();
    StringMethods->next = printlnMethod();
    StringMethods->next->next = toStringMethod();
    return StringMethods;
}


Class initStringClass() {
   
    char* name;
    name = (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(name, "String");
    CurrentClass = ClassDecl(name, NULL);
    String = ClassDeclComplete(NULL, NULL, NULL, StringMethods());
    
    return String;   
}


Class initVoidClass() {
   
    
    char* name;
    name = (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(name, "Void");
    CurrentClass = ClassDecl(name, NULL);
    Void = ClassDeclComplete(NULL, NULL, NULL, NULL);
    
    voidInstance = ExprFromVoid();
    return Void;   
}


Class initIntegerClass() {
    char* integerName;
    integerName = (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(integerName, "Integer");
    CurrentClass = ClassDecl(integerName, NULL);
    Integer = ClassDeclComplete(NULL, NULL, NULL, IntegerMethods());
    exit ;
    return Integer;  
}
 
 

void incPaddingNb(){
    PrintPaddingNb+= 6;
}


void decPaddingNb(){
    PrintPaddingNb-= 6;
}


void printPadding() {
    int i = 0;
    for (i = 0; i < PrintPaddingNb; i++ ) 
        printf("%c",  PrintPaddingChar);
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


void ProgramEval(Program program){
    Instr instrs = program->instrs;
    while (instrs != NULL) {
        InstrEval(instrs)  ; 
        instrs = instrs->next; 
    }
}

void ProgramTypeAndRedirect(Program program){
    Class cl = program->classDefs; 
    while ( cl != NULL ) {
        ClassTypeAndRedirect(cl);
        cl = cl->next;
    }
}

void InstrTypeAndRedirect(Instr instrs, Scope sc){
    Instr i = instrs;
    while( i != NULL ) {
        ReplaceVarInInstr(i, sc);
        i = i->next;
    }
}

Program makeProgram(Class classDefs, Instr instrs){
    program = NEW(1, _Program);
    program->classDefs = AllDefinedClasses;
    program->instrs = instrs;
   
    return program;
}


