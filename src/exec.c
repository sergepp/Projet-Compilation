Expr exec_instr(Instr instr, Scope scope){

    if( instr == NULL) return voidInstance;

    Expr result;
    Scope sc;
    Instr i = instr;
    while ( i != NULL ) {
        switch(i->op){
        
            case EXPR       : 
                if ( verbose == TRUE ) {
                    printPadding(); printf("Instr Expr\n"); 
                    incPaddingNb();  
                }
                result = exec_expr(i->expr, scope);       
                if ( verbose == TRUE ) {
                    decPaddingNb();
                    printPadding(); printf("Instr Expr Terminate\n\n");   
                }
                break;
            case RETURN     : 
                if ( verbose == TRUE ) {
                    printPadding(); printf("Instr Return\n"); 
                    incPaddingNb();  
                }
                
                result = exec_expr(i->expr, scope);      
                if ( verbose == TRUE ) {
                    decPaddingNb();
                    printPadding(); printf("Instr Return Terminate\n");   
                }
                break;
            case PROC_BLOC  : 
                if ( verbose == TRUE ) {
                    printPadding(); printf("Instr ProcBloc\n");
                    incPaddingNb();
                }
                 
                sc = ScopeNew("", NULL, scope, i->var);
                sc->next = scope;
                result = exec_instr(i->listInstr,sc);
                sc = NULL;
                if ( verbose == TRUE ) {
                    decPaddingNb();
                    printPadding(); printf("Instr ProcBloc Terminate\n");   
                }
                break;
            case FN_BLOC :
                if ( verbose == TRUE ) {
                    printPadding(); printf("Instr FnBloc\n"); 
                    incPaddingNb();
                }
                
                sc = ScopeNew("", NULL, scope, i->var);
                sc->next = scope;
                result = exec_instr(i->listInstr,sc);
                /* Si il  n'y a pas d'expression return  alors evaluer l'expression yield. toute facon s'il y a return 
                 ceswitch va l'attraper dans la clause case RETURN */
                if ( InstrHasReturn(i->listInstr) == FALSE ) { 
                      result = exec_expr(i->yield, sc);
                }
                sc = NULL;
                if ( verbose == TRUE ) { 
                    decPaddingNb();
                    printPadding(); printf("Instr FnBloc Terminate\n\n");
                }
                break;
            case  INSTR_BLOC : 
                if ( verbose == TRUE ) {
                    printPadding(); printf("Instr InstrBloc\n"); 
                    incPaddingNb();
                }
                result = exec_instr(i->listInstr,scope); 
                if ( verbose == TRUE ) {
                    decPaddingNb();
                    printPadding(); printf("Instr InstrBloc Terminate\n\n");
                }
                break;
            case ASSIGN  :
                if ( verbose == TRUE ) {
                    printPadding(); printf("Instr Assign\n"); 
                    incPaddingNb();
                }
                result = exec_expr(i->rightExpr, scope);              
                i->leftExpr = exec_assign_right_to_left(i->leftExpr,result);;
                
                result = voidInstance; 
                
                if ( verbose == TRUE ) {
                    decPaddingNb();
                    printPadding(); printf("Instr Assign Terminate\n\n");
                }
                break;
             case IF : 
                if ( verbose == TRUE ) {
                    printPadding(); printf("Instr If\n"); 
                    incPaddingNb();
                }       
                    
                result = exec_expr(i->cond, scope);
                
                if( result->evalResult.i != 0 ) { /* Vrai si NON NULL */
                    result = exec_instr(i->thenInstr, scope) ;  
                }
                else{
                    result = exec_instr(i->elseInstr,  scope) ;
                }
                
                if ( verbose == TRUE ) {
                    decPaddingNb();
                    printPadding(); printf("Instr If Terminate\n\n");
                }
                break;
            default:  printf("\nAtttention !! Dans la methode exec_instr, Operateur non implemente pour l'instruction : %d  \n", i->op);
                    exit(1);
                
        }       
        
        if ( i->op == RETURN ) {
            return result; 
        }
        
        i = i->next ; 
    }
    return result;  
}


Expr exec_expr(Expr e, Scope scope){

    if( e == NULL) return voidInstance;
    if ( e->isEvaluated == TRUE ) return e;
    Expr result;
    Scope sc;
    Var v;
    Method m;
    char message[128];
    if ( verbose == TRUE ) {
        printPadding(); printf("E and not evaluated is not null : %d \n", e->op);
    }
    switch(e->op){
            case CONST_INT  :  
            case CONST_STR  : 
            case CONST_VOID : 
            case INSTANCE   : 
                if ( verbose == TRUE ) {
                    printPadding(); printf("Expr Const ou Instance\n");
                    result = e;  
                }
                break;
            case VAR_CALL   : 
                if ( verbose == TRUE ) {
                    printPadding(); printf("Expr Var Call : %s\n", e->value.s); 
                }
                v = FindInstanceVarInScope(e->value.s, scope);
                result = v->value;

                if ( verbose == TRUE ) {
                    printPadding(); printf("Expr Var Call Terminate\n"); 
                }
                break;
            case  STATIC_METHOD_CALL  : 
                if ( verbose == TRUE ) {
                    printPadding();printf("Expr Static Method Call : %s() \n", e->value.m->methodName);
                    incPaddingNb();
                }
                
                m = FindStaticMethodInScope(e->value.m->methodName, e->value.m->class->scope);
                v->next = method_arg_to_var_list(m,  e->value.m->args, scope);
                sc = ScopeNew("", NULL, NULL, v);
                sc->next = scope;
                result = exec_instr(m->bodyInstr, sc);
                if ( verbose == TRUE ) {
                    decPaddingNb();
                    printPadding(); printf("Expr Static Method Call Terminate \n");
                }
                break;
            case INSTANCE_METHOD_CALL   : 
                if ( verbose == TRUE ) {
                    printPadding();printf("Expr Method Call \n");    
                    printPadding();printf("Expr Method Call : instance of %s.%s() \n", e->left->type->name, e->value.m->methodName);
                    incPaddingNb();
                    printPadding();printf("Before Evaluation \n");
                }
                result = exec_eval_method_call(e, scope); 
                
                if ( verbose == TRUE ) {
                    printPadding();printf("After Evaluation \n");
                    decPaddingNb();
                    printPadding(); printf("Expr Instance Method Call Terminate \n");
                }
                break;
            case STATIC_FIELD_ACCESS    :  
                if ( verbose == TRUE ) {
                    printPadding(); printf("Expr Static Instance field Access\n");
                }   
                v = FindStaticVarInScope(e->value.s, e->type->scope);
                exec_assign_right_to_left(e, exec_expr(v->value, scope));
                result = e ;
                if ( verbose == TRUE ) {
                    printPadding(); printf("Expr Static Instance field Access Terminate\n"); 
                }
                break; 
            case INSTANCE_FIELD_ACCESS  :  
                if ( verbose == TRUE ) {
                    printPadding(); printf("Expr Instance field access\n"); 
                }
                v = FindInstanceVarInScope(e->value.s, scope);
                exec_assign_right_to_left(e, exec_expr(v->value, scope));
                result = e ;
                if ( verbose == TRUE ) {
                    printPadding(); printf("Expr Instance field Access Terminate\n"); 
                }
                break;  
            case ADD            : 
            case SUB            :           
            case DIV            :
            case MUL            : 
                 if ( verbose == TRUE ) {
                    printPadding(); printf("Expr Arithmetique\n"); 
                 }
                 result = exec_arithm_expr(e, scope);   
                 if ( verbose == TRUE ) {
                    printPadding(); printf("Expr Arithmetique Terminate\n"); 
                 }
                 break;  
            case EQ  : 
            case NEQ : 
            case LT  : 
            case LTE : 
            case GTE : 
            case GT  : 
                
                result = exec_boolean_expr(e,scope);
                
                break ; 
                
            case CONCAT         :
                if ( verbose == TRUE ) {
                    printPadding(); printf("Expr Concatenation\n");
                } 
                result = exec_concat_expr(e, scope);
                
                if ( verbose == TRUE ) {
                    printPadding(); printf("Expr Concatenation Terminate\n"); 
                }
                break;
            default : 
                sprintf(message, "\nAtttention !! Dans la methode exec_expr, Operateur non implemente pour l'expr : %d  \n", e->op);
                PrintError(message, -1);
                exit(1);
    }
    return result ; 
}

Expr exec_eval_method_call(Expr e, Scope scope){
    if ( verbose == TRUE ) {
           printPadding(); printf("Before eval op: %d\n", e->left->op);
    }
    Scope sc = ScopeNew("", NULL, NULL, NULL);
    Expr result =  exec_expr(e->left, scope); 
    if ( verbose == TRUE ) {
        printPadding(); printf("After eval \n");
    }
    Method m;
    Var v; 
    if ( strcmp(e->value.m->methodName, "print") == 0 ) {
        
        if ( strcmp(result->type->name, "Integer") == 0 ) {
            printf("%d", result->evalResult.i);
        }
        else if ( strcmp(result->type->name, "String") == 0 ) {
           printf("%s", result->evalResult.s);
        } 
        else {
             PrintError("\nAtttention !! Dans la methode exec_eval_method_call, Operateur non implemente pour l'expr : %d  \n", e->op);
             exit(1);
        }
    } 
    else if ( strcmp(e->value.m->methodName, "println") == 0 ) {
          
        if ( strcmp(result->type->name, "Integer") == 0 ) {
            printf("%d\n", result->evalResult.i);
        }
        else if ( strcmp(result->type->name, "String") == 0 ) {
            printf("%s\n", result->evalResult.s);
        } 
        else {
             PrintError("\nAtttention !! Dans la methode exec_eval_method_call, Operateur non implemente pour l'expr : %d  \n", e->op);
             exit(1);
        }
    }
    
    else if ( strcmp(e->value.m->methodName, "toString") == 0 && strcmp(result->type->name, "Integer") == 0  ) {
          
        char* str = (char*) malloc( 50 * sizeof(char));
        sprintf(str, "\"%d\"", result->evalResult.i); 
        
        result = ExprFromString(str); /* Ceci est le resultat de l'application de la eethode toString() */
    }
    else if ( strcmp(e->value.m->methodName, "toString") == 0 && strcmp(result->type->name, "String")  == 0  ) {
         result = ExprFromString(result->evalResult.s);
    }
    else { 
        m = FindInstanceMethodInScope(e->value.m->methodName, e->left->type->scope);
        v = NewThis(e->left->type, e->left);
        v->next = method_arg_to_var_list(m,  e->value.m->args, scope);
        
        sc = ScopeNew("Arguments de la methode", NULL, NULL, v);
        
        sc->next =  e->left->type->scope;
        
        if ( m->bodyExpr != NULL ) { 
            result = exec_expr(m->bodyExpr, sc);
        }
        else {
            result = exec_instr(m->bodyInstr, sc);
        }
    }
    return result;
}


Expr exec_assign_right_to_left(Expr left, Expr right) {
 
    return right; 
    if( right->op == CONST_INT ){
        left->evalResult.i =  right->evalResult.i;
        left->op = CONST_INT; 
    }
    else if( right->op == CONST_STR){
       left->evalResult.s =  right->evalResult.s;
        left->op = CONST_STR; 
    }
    else if( right->op == CONST_VOID ){
       left->evalResult.isVoid =  TRUE;
        left->op = CONST_VOID; 
    }
    else if( right->op == INSTANCE ){
         left->op = INSTANCE;
        left->evalResult.instance =  right->evalResult.instance;
    }
    else {
        PrintError("\nAtttention !! Dans la methode  exec_assign_right_to_left( Operateur non implemente : %d  \n", right->op);
        exit(1);
    }
    return left; 
}

Var method_arg_to_var_list(Method m, Expr args, Scope scope){
    if ( m == NULL || m->params == NULL ) 
        return NULL;
        
    Var result, i, k ;
    i = m->params;
    Expr j = args;

    result = VarDecl(i->name, i->class->name, exec_expr(j, scope));
    k = result;
    while ( i->next != NULL ) {
        k->next = VarDecl( i->name, i->class->name, exec_expr(j, scope) );
        k = k->next;
        j = j->next;
        i = i->next;
    }  
    return   result;
}

Expr exec_arithm_expr(Expr expr, Scope scope) {
    Expr rightTmp, leftTmp;
    leftTmp  =  exec_expr(expr->left, scope); 
    rightTmp =  exec_expr(expr->right, scope); 
    char message[128];
    
    switch(expr->op) {
        case CONST_INT  : return expr; 
        case ADD        : expr->evalResult.i = leftTmp->evalResult.i + rightTmp->evalResult.i ;break ; 
        case SUB        : expr->evalResult.i = leftTmp->evalResult.i - rightTmp->evalResult.i ;break ;            
        case DIV        : expr->evalResult.i = leftTmp->evalResult.i / rightTmp->evalResult.i ;break ; 
        case MUL        : expr->evalResult.i = leftTmp->evalResult.i * rightTmp->evalResult.i ;break ; 
       
        default :
        sprintf(message, "Evaluation Non pris en charge par la fonction : exec_arithm_exp_ %d\n ", expr->op);
        PrintError(message, -1); break;     
    }
    expr->op = CONST_INT;
    expr->isEvaluated = TRUE ;
    
    return expr;         
}


Expr exec_boolean_expr(Expr expr, Scope scope) {
    Expr rightTmp, leftTmp;
    leftTmp  =  exec_expr(expr->left, scope); 
    rightTmp =  exec_expr(expr->right, scope); 
    expr->isEvaluated = TRUE ;
    char message[128];
     
    switch(expr->op) {
        case CONST_INT  : return expr;  
        case EQ         : 
            if ( leftTmp->evalResult.i == rightTmp->evalResult.i  ) expr->evalResult.i = 1;         
            else expr->evalResult.i = 0  ; 
            expr->isEvaluated = TRUE ;  
            break;
        case NEQ         : 
            if ( leftTmp->evalResult.i != rightTmp->evalResult.i  ) expr->evalResult.i = 1;         
            else expr->evalResult.i = 0  ; 
            expr->isEvaluated = TRUE ; 
            break;
        case LT          : 
            if ( leftTmp->evalResult.i < rightTmp->evalResult.i  ) expr->evalResult.i = 1;         
            else expr->evalResult.i = 0  ; 
            expr->isEvaluated = TRUE ; 
            break;
        case LTE        : 
            if ( leftTmp->evalResult.i <= rightTmp->evalResult.i  ) expr->evalResult.i = 1;         
            else expr->evalResult.i = 0  ; 
            expr->isEvaluated = TRUE ; 
            break;
        case GT        : 
            if ( leftTmp->evalResult.i > rightTmp->evalResult.i  ) expr->evalResult.i = 1;         
            else expr->evalResult.i = 0  ; 
            expr->isEvaluated = TRUE ; 
            break;
        case GTE         : 
            if ( leftTmp->evalResult.i >= rightTmp->evalResult.i  ) expr->evalResult.i = 1;         
            else expr->evalResult.i = 0  ; 
            expr->isEvaluated = TRUE ; 
            break;
              
        default : 
        sprintf(message, "Evaluation Non pris en charge par la fonction : exec_boolean_expr %d\n ", expr->op);
        PrintError(message, -1); break;     
    }
    expr->op = CONST_INT;
    return expr;         
}


Expr exec_concat_expr(Expr expr, Scope scope) {
    Expr rightTmp, leftTmp;
    leftTmp  =  exec_expr(expr->left, scope); 
    rightTmp =  exec_expr(expr->right, scope); 
    Expr result; 
    result->isEvaluated = TRUE ;  
    switch(expr->op) {
        case CONCAT     : 
        result = ExprFromString(strcat(leftTmp->evalResult.s,rightTmp->evalResult.s));
        break;
        default : PrintError("Erreur non concat : E\n ", expr->lineno); break;     
    }
    return result;         
}
