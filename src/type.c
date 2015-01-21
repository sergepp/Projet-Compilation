#define ID_NAME_MAX_SIZE 50

extern int yylineno;

extern char* yytext; 
 




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
    printf("Not implemented\n");
    return NEW(1, _Var);
}

void ParamDeclAssertIsOk(char* name, char* classType){
    printf("Not implemented\n");
}

Var ParamDecl(char* name, char* classType){
    printf("Not implemented\n");
    return NEW(1, _Var);
}



void ExtendsDeclAssertIsOk( char* classType, Expr expr){
    printf("Not implemented\n");
}

Instr ExtendsDecl(char* classType, Expr expr){
    printf("Not implemented\n");
    return NEW(1, _Instr);
}

void ConstructorBodyAssertIsOk(Instr consBody){
    printf("Not implemented\n");
}


Class ClassDeclSetNext(Class class, Class next){
    printf("Not implemented\n");
    return NEW(1, _Class);
}
void ClassDeclAssertIsOk(char* className, Var classParamDecl ,Instr extendsDecl, Instr constructorBody, Var fieldDecl, Method methodDecl){
    printf("Not implemented\n");
}       
Class ClassDecl(char* className, Var classParamDecl ,Instr extendsDecl, Instr constructorBody, Var fieldDecl, Method methodDecl){
    printf("Not implemented\n");
    return NEW(1, _Class);
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
    printf("Not implemented\n");
    return NEW(1, _Method);
} 






















void PrintError(char* message);

void PrintError(char* message){
    printf("[ Erreur ] %s\n", message );
}

ClassType IntegerType() {
    ClassType IntegerType    = NEW(1, _ClassType);
    IntegerType->name  = (char*) malloc( ID_NAME_MAX_SIZE * sizeof(char) ) ;
    sprintf(IntegerType->name, "Integer");
    IntegerType->extends = NULL;
    return IntegerType;
}
 
Field IntegerFields() {
    Field IntegerFields  = NEW(1, _Field);
    IntegerFields->name  = (char*) malloc( ID_NAME_MAX_SIZE * sizeof(char) ) ;
    sprintf(IntegerFields->name, "value");
    IntegerFields->type  = IntegerType();
    IntegerFields->value = NULL;
    IntegerFields->next  = NULL;
    return IntegerFields;
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
    expr->type = IntegerType(); 
    expr->right = NULL;
    
    return expr;
}
Expr ExprFromString(char* string){
    
    Expr expr = NEW(1, _Expr);
    expr->left = NULL; 
    expr->op = CONST_INT; 
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
    expr->next = next;
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



Instr InstrSetNext(Instr instr, Instr next){
    instr->next = next;
    return instr; 
}


Instr InstrFromExpr(Expr expr){
    Instr instr = NEW(1, _Instr);
    instr->expr = expr;
    return instr; 
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

/* Cree les classes predefinies si elles ne sont pas deja définies 
 * par defaut et y ajoute la definition de la classe passée en paraletre 
 */
Class defaultClassDefsPlus(Class classDefs) {
    Class Integer    = NEW(1, _Class);
    Integer->type    = IntegerType();
    Integer->fields  = IntegerFields();
    Integer->methods = IntegerMethods();
    
    /* Class String     = NEW(1, _Class);
    String->type     = StringType();
    String->fields   = StringFields();
    String->methods  = StringMethods();
    
    Class Void       = NEW(1, _Class);
    String->type     = VoidType();
    String->fields   = VoidFields();
    String->methods  = VoidMethods(); */
    /*
    Integer->next = String;
    Integer->next->next = Void;
    Integer->next->next->next = classDefs; */
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


Expr ExprEval(Expr expr) { 
  
    switch(expr->op) {
        case CONST_INT  :  
        case CONST_VOID :  
        case CONST_STR  : return expr;
        case ADD        : 
        case SUB        :           
        case DIV        :
        case MUL        : return ExprArithmeticEval(expr); 
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
    incPaddingNb();
    printPadding();printf("Instruction : \n");
    ExprPrint(inst->expr);
    decPaddingNb();
}

void ClassPrint(Class cl) {
    incPaddingNb();
    printPadding();printf("Classe : \n");
    decPaddingNb();
}
void ProgramPrint(Program prg) {
    printPadding();printf("Programme\n");
    ClassPrint(prg->classDefs);
    InstrPrint(prg->instrs);
}

Program makeProgram(Class classDefs, Instr instrs){
    Program program = NEW(1, _Program);
    program->classDefs = defaultClassDefsPlus(classDefs);
    program->instrs = instrs;
    /*ProgramPrint(program); */
    ExprPrintResult(ExprEval(program->instrs->expr)); 
    return program;
}



