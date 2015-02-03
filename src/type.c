 

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
    fields->value = NULL;
    fields->next  = NULL;
    return fields ;
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
    
    return String;  
}


Class initVoidClass() {
   
    Void = NEW(1, _Class);
    Void->name      = (char*) malloc(ID_NAME_MAX_SIZE * sizeof(char)); sprintf(Void->name, "Void");
     
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


Program makeProgram(Class classDefs, Instr instrs){
    Program program = NEW(1, _Program);
    program->classDefs = AllDefinedClasses;
    program->instrs = instrs;
    /*ProgramPrint(program);*/
    printf("\n");
    ScopePrint(MainScope);
    ProgramEval(program);
    return program;
}


