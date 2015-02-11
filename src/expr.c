void ExprAssertFieldAccessIsOk(Expr e, char* name){
    char message[128];
    
    Var field;
    
    if ( e->type != NULL ) {
        field = ClassGetFieldByName(e->type, name);
        if ( field == NULL ) {
            sprintf(message, "Impossible d'acceder au champ %s  de l'instance de la classe %s", name, e->type->name);
            PrintError(message, e->lineno);
            exit(1);
        }
    }
}

Expr ExprFromStaticFieldAccess(char* classname, char* fieldName){

    Expr e  = NEW(1, _Expr);
    e->op = STATIC_FIELD_ACCESS;
    e->lineno = yylineno;
    e->isEvaluated = TRUE;
    
    e->value.s = fieldName;
    e->type = GetClassByName(classname);
    return e; 
}

Expr ExprFromFieldAccess(Expr e, char* name){  
   
    Expr expr = NEW(1, _Expr);
    expr->left = e; 
    expr->op =  INSTANCE_FIELD_ACCESS;
     
    expr->value.s = name;
    expr->isEvaluated = TRUE;
    expr->lineno = yylineno;
    return expr;
}


void AssertExprIsValid(Expr expr){
    char message[128];
    if ( expr != NULL ) {
        /* Toutes ses variables sont déclarées dnas le scope actuel*/
        switch(expr->op){
            case CONST_INT  :  
            case CONST_STR  :  
            case CONST_VOID :  break; /* Rien a faire les constantes sont forcement valide */
            case ADD        :  
            case SUB        : 
            case MUL        : 
            case DIV        :
                AssertExprIsValid(expr->left); 
                AssertExprIsValid(expr->right);
                break; 
            case VAR_CALL  :
                if ( IsVarInCurrentScope(expr->value.s, NULL) == FALSE ) {
                     sprintf(message, "Identificateur %s inconnu dans le scope actuel", expr->value.s);
                     PrintError(message, expr->lineno);
                     exit(1);
                }
                break;
            default : printf("AssertExprIsValid non encore implemente pour l'operateur de l'expression  : op %d \n ", expr->op); break;     
        }
        /* Ses types sont compatibles pour toutes les operations qu'elle contient */
    }
}

void ExprAssertStaticFieldAccessIsOk(char* classname, char* name){
    printf("ExprAssertStaticFieldAccessIsOk Not implemented\n");
}


void ExprAssertStaticMethodAccessIsOk(char* classname, char* name, Expr e5) {
    printf("ExprAssertStaticMethodAccessIsOk Not implemented\n");
}


void ExprAssertIDIsOk(char* name) {
    char message[128];
    /* le nom de d'Id doit etre declarée et visible dans le scope courrant */
    /* On suppose que c'est une variable */
    Var v = GetVarByName(name, currentScope);
    if ( v == NULL ) {
            sprintf(message, "Identificateur %s n'a pas encore ete definie ou est invisibele dans ce scope\n", name);
            PrintError(message, yylineno);
            exit(1);
    }
    /* On suppose que c'est une methode */ 
}


Expr ExprFromStaticMethodAccess(char* classname, char* name, Expr args){
    Expr e  = ExprFromMethodAccess(NULL, name, args);
    e->op = STATIC_METHOD_CALL;
    e->value.m->class = GetClassByName(classname);
    return e;
}

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

void ExprAssertMethodAccessIsOk(Expr e1,char* name, Expr e5){
    printf("ExprAssertMethodAccessIsOk Not Implemented\n");
}


Expr ExprFromConcat(Expr e1, Expr e3){
    
    Expr expr = NEW(1, _Expr);
    expr->left = e1; 
    expr->op = CONCAT; 
    expr->right = e3;
    
    expr->type = String; 
    expr->isEvaluated = FALSE;
    expr->lineno = yylineno;
    
    return expr;
}

void ExprAssertInstanciationIsOk(char* className, Expr e){
    printf("ExprAssertInstanciationIsOk Not Implemented\n");
}

Expr ExprFromInstanciation(char* className, Expr e){
    Expr expr = ClassNewInstanceOf(className, e);
    return expr;
}

void ExprAssertInheritsType(Class ct, Expr e){
    char message[128];
    
    if ( ClassLeftInheritsRight(e->type, ct) == FALSE ) {
        sprintf(message, "Types incompatibles pour cette operation");
        PrintError(message, e->lineno);
        exit(1);
    }
}

void ExprAssertAllVarsAreDeclaredInScope(Expr expr, Class class) {
     char* message[128];
      /*
     switch(expr->op) {
        case VAR_CALL   : 
        if ( IsVarInClassScope(varName, Class class) == FALSE ){
             sprintf(message, "Le nom de variable  %s a deja été utilise dans les parametres", varName);
             PrintError(message);
             exit(1);
        }
        /* 
        case SUB        : expr->value.i = leftTmp->value.i - rightTmp->value.i ;break ;            
        case DIV        : expr->value.i = leftTmp->value.i / rightTmp->value.i ;break ; 
        case MUL        : expr->value.i = leftTmp->value.i * rightTmp->value.i ;break ; 
       
        default : PrintError("Evaluation Non pris en charge par la fonction : ExprArithmeticEval\n "); break;     
    }
    
    */
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
    expr->type = Integer;  
    expr->isEvaluated = FALSE;
    expr->lineno = yylineno;
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
    expr->op = CONST_VOID;
    expr->type = Void; 
    expr->isEvaluated = TRUE;
    expr->value.isVoid = TRUE;
    expr->evalResult.isVoid = TRUE;
    expr->lineno = yylineno;
    return expr;
}

Expr ExprFromInt(int value) {
    Expr expr = NEW(1, _Expr);
    expr->op = CONST_INT; 
    expr->value.i = value;
    expr->evalResult.i = value;
    expr->type = Integer; 
    expr->isEvaluated = TRUE;
    expr->lineno = yylineno;  
    return expr;
}

Expr ExprFromString(char* string){
    
    Expr expr = NEW(1, _Expr);
    expr->left = NULL; 
    expr->op = CONST_STR; 
    expr->value.s = string;
    expr->evalResult.i = string;
    expr->type = String; 
    expr->right = NULL;
    expr->isEvaluated = TRUE;
    expr->lineno = yylineno;    
    return expr;
}
Expr ExprFromVar(char* varName){

    /*    printf("Dans la fonction ExprFromVar\n"); */
    Expr expr = NEW(1, _Expr);
    expr->op = VAR_CALL;
    expr->value.s = varName;
    expr->isEvaluated = FALSE;
    expr->lineno = yylineno;
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
    expr->type = Integer;
    expr->isEvaluated = FALSE;
    expr->right = right;
    expr->lineno = yylineno;    
    return expr;
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
            case CONST_INT  : printf("Const Integer %d  \n", expr->evalResult.i); break ; 
            case CONST_VOID : printf("void \n"); break ;             
            case CONST_STR  : printf("Const String  %s \n", expr->evalResult.s); break ; 
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
            case VAR_CALL   : printf("Variable : %s\n",expr->value.s);  break;
            case INSTANCE_METHOD_CALL :   printf("left  : \n"); ExprPrint(expr->left); 
                printPadding();printf("value.m->methodName    :  %s\n", expr->value.m->methodName);
                break;
            case INSTANCE :    printf("instance of : %s\n", expr->value.instance->name); break;
            case CONCAT   :    printf("left  : \n"); ExprPrint(expr->left); 
                printPadding();printf("op    : &\n"); 
                printPadding();printf("right : \n"); ExprPrint(expr->right);        
                break; 
            default : printf("Format d'affichage non reconnu \n "); break;     
        }
         decPaddingNb();
    } 
    decPaddingNb(); 
}


void ExprPrintResult(Expr expr) {
    printPadding();  
    switch(expr->op){
        case ADD            :
        case SUB            :
        case MUL            :
        case DIV            : break;
        case VAR_CALL       : printf("Var %s  \n", expr->value.s );
        case INSTANCE       : printf("Instance of class %s\n", expr->value.instance->name);break;
        case CONST_INT      : printf("Integer = %d\n", expr->value.i);                           break;
        case CONST_VOID     : printf("Void = void\n");                                           break;
        case CONST_STR      : printf("String = %s\n", expr->value.s);                            break;
        case CONCAT         : printf("String = %s\n", expr->value.s);                            break;
        default : printf("Affichage Non encore implementé \n ");                                 break;     
    }
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
       
        default : PrintError("Evaluation Non pris en charge par la fonction : ExprArithmeticEval\n ", expr->lineno); break;     
    }
    return expr;         
}

Expr ExprConcatEval(Expr expr) {
    Expr rightTmp, leftTmp;
    leftTmp  =  ExprEval(expr->left); 
    rightTmp =  ExprEval(expr->right); 
    switch(expr->op) {
        case CONCAT     : expr->value.s=strcat(leftTmp->value.s,rightTmp->value.s);break;
        default : PrintError("Erreur non concat : E\n ", expr->lineno); break;     
    }
    return expr;         
}


Expr ExprVarEval(Expr expr) {
    Var var;
    switch(expr->op) {
        case VAR_CALL     : 
             
            var = GetVarByName(expr->value.s, currentScope);
            return ExprEval(var->value);
        default : PrintError("Erreur non Var : E\n ", expr->lineno); break;     
    }        
}


Expr ExprEval(Expr expr) { 
    
    if ( expr->isEvaluated ) 
        return expr;
     
    Expr e ;   
    switch(expr->op) {
        case CONST_INT      :  
        case CONST_VOID     : 
        case CONST_STR      :  
        case INSTANCE       : return expr;
        case ADD            : 
        case SUB            :           
        case DIV            :
        case MUL            : 
            e = ExprArithmeticEval(expr); 
            e->isEvaluated = TRUE;
            return e ; 
        case CONCAT     : 
             e = ExprConcatEval(expr);    
             e->isEvaluated = TRUE;
             return e ;
        default : printf("Evaluation Non encore implementée \n "); break;     
    }
    return expr;     
}



