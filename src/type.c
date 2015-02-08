 

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

/*


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
 
*/



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

Method IntegerPrintMethod(){

    Method method       = NEW(1, _Method);
    method->name        = (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(method->name, "print"); 
    method->isOverride  = FALSE;
    method->isStatic    = FALSE;
    method->params      = NULL;
    method->lineno      = -1;   
    method->returnClassName = (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(method->name, "Void");  
    return method;  
}
Method IntegerPrintlnMethod(){
    Method method       = NEW(1, _Method);
    method->name        = (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(method->name, "println"); 
    method->isOverride  = FALSE;
    method->isStatic    = FALSE;
    method->params      = NULL;
    method->lineno      = -1;   
    method->returnClassName = (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(method->name, "Void");    
    return method;
}
Method IntegerToStringMethod(){
    Method method       = NEW(1, _Method);
    method->name        = (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(method->name, "toString"); 
    method->isOverride  = FALSE;
    method->isStatic    = FALSE;
    method->params      = NULL;
    method->lineno      = -1;   
    method->returnClassName = (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(method->name, "String");   
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
    IntegerMethods->next->next->next->next  = IntegerPrintMethod();
    IntegerMethods->next->next->next->next->next  = IntegerPrintlnMethod();
    IntegerMethods->next->next->next->next->next->next  = IntegerToStringMethod();
    return IntegerMethods;
}




/* Renvoi la liste de toutes les methodes disponibles sur l'objet String */
Method StringMethods() {
    Method 
    StringMethods = NULL ;/* StringPrintMethod();/*
    StringMethods->next = StringPrintlnMethod(); */
    return StringMethods;
}


Class initStringClass() {
   
    String = NEW(1, _Class); 
    
    String->name      = (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(String->name, "String");
    String->fields    = StringFields();
    String->methods   = StringMethods();
    String->consBody  = NULL;
    String->consParams = String->fields;
    
    return String;  
}


Class initVoidClass() {
   
    Void = NEW(1, _Class); 
    Void->name      = (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(Void->name, "Void");
    voidInstance = ExprFromVoid();
    voidInstance->lineno = -1; 
    
    return Void;  
}


Class initIntegerClass() {
   
    Integer = NEW(1, _Class);
    Integer->name      = (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(Integer->name, "Integer");
    Integer->fields    = IntegerFields();
    Integer->methods   = IntegerMethods();
    Integer->consParams = Integer->fields;
    
    return Integer;  
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
    Class cl = AllDefinedClasses; 
    while ( cl != NULL ) {
        /* ClassTypeAndRedirect(cl); */       
        printf("\t%s\n", cl->name);
        cl = cl->next;
    }
    /* InstrTypeAndRedirect(program->instrs); */
}


Program makeProgram(Class classDefs, Instr instrs){
    Program program = NEW(1, _Program);
    program->classDefs = AllDefinedClasses;
    program->instrs = instrs;
    /* ProgramPrint(program); */
    printf("\n");
    /* ScopePrint(MainScope); */
    ProgramTypeAndRedirect(program);
    /* ProgramEval(program); */
    return program;
}


