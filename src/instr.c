
void InstrAssertProcBlocIsOk(Var var,Instr instr){
	printf("InstrAssertProcBlocIsOk not implemented \n");	
	
}


Instr InstrFromProcBloc(Var vars,Instr listInstr){
	Instr instr = NEW(1, _Instr);
    instr->op           = PROC_BLOC;
    instr->var          = vars;
    instr->listInstr    = listInstr;
    return instr; 
}

Instr InstrFromInstrBloc(Instr listInstr){
	Instr instr = NEW(1, _Instr);
    instr->op           = INSTR_BLOC;
    instr->listInstr    = listInstr;
    return instr; 
}

void InstrAssertFnBlocIsOk(Var vars, Instr listInstr, Expr expr) {
	printf("InstrAssertFnBlocIsOk not implemented \n");
	

}


Instr InstrFromFnBloc(Var vars, Instr listInstr, Expr expr){
	Instr instr = NEW(1, _Instr);
    instr->op           = FN_BLOC;
    instr->yield        = expr;
    instr->var          = vars;
    instr->listInstr    = listInstr;
    return instr; 
}


Instr InstrSetNext(Instr instr, Instr next){
    Instr i = instr; 
    while ( i->next != NULL ) {    
        i = i->next;
    }
    i->next = next;
    return instr; 
}

Instr InstrFromVarDecl(char* name, char* className, Expr e)  {
    Instr instr = NEW(1, _Instr);
    Var v =  VarDecl(name,className, e);
     
    return instr;
}

Instr InstrFromExpr(Expr expr){
    Instr instr = NEW(1, _Instr);
    instr->op           = EXPR;
    instr->expr         = expr;
    return instr; 
}

void AssertInstrAssignIsOk(Instr instr) {
    if ( instr != NULL ) {

       if ( instr->op == ASSIGN ) {
            InstrAssertAssignIsOk(instr->leftExpr, instr->rightExpr);         
       }
       
       if ( instr->op == INSTR_BLOC || instr->op == PROC_BLOC || instr->op == FN_BLOC )
        AssertInstrAssignIsOk(instr->listInstr); 
       else
        AssertInstrAssignIsOk(instr->next);
    }
}
void InstrAssertAssignIsOk(Expr left, Expr right){
    char message[128];
    
    /* Si l'expression de gauche est nulle on a un probleme on peut pas modifier NULL */    
    if ( left == NULL ) {
        sprintf(message, "La partie  gauche d'une expression doit être non nulle ");
        PrintError(message, yylineno);
        exit(1);
    }
    
    /* L'affectation ne sont pas pretes a etre verifeees et la verification se 
       fera apres une fois que l'arbre aura ete decore */
 
    if ( left->type == NULL );
        return;
        
    /* Si l'expression de gauche n'est pas une variable, 
       on a un probleme on peut pas modifier une constante */    
    if ( left->op != VAR_CALL ) {
        sprintf(message, "Impossible de modifier une expression qui n'est pas une variable ou une selection.   op : %d", left->op);
        PrintError(message, left->lineno);
        exit(1);
    }

    /* Si l'expression de gauche n'est pas visible on a un probleme */
   
    
    /* Si les types ne sont pas compatibles, on a un probleme : ATTENTION 
        ICI  right et left sont inversé car si on autorise : 
        Map  = HashMap
        left = right
        
        right doit bien heriter de left et non l inverse.    */
    if ( ClassLeftInheritsRight(right->type, left->type) != FALSE ) {
        sprintf(message, "Affectation impossible, au niveau des types, l'affectation se resoud a    (%s) :=  (%s) \n", left->type->name, right->type->name);
        PrintError(message, right->lineno);
        exit(1);
    }
}

Instr InstrFromAssign(Expr e1,Expr e2){
	Instr instr = NEW(1, _Instr);
    instr->op           = ASSIGN;
    instr->leftExpr     = e1;
    instr->rightExpr    = e2;
    return instr; 
}


void InstrAssertIfIsOk(Expr expr, Instr thenInstr, Instr elseInstr){
	printf("InstrAssertIfIsOk not implemented\n");
}

Instr InstrFromReturn(Expr expr){
    Instr instr = NEW(1, _Instr);
    instr->op           = RETURN;
    instr->expr         = expr;
    return instr;
}

Instr InstrFromIf(Expr cond, Instr thenInstr, Instr elseInstr){
	Instr instr = NEW(1, _Instr);
    instr->op           = IF;
    instr->cond         = cond;
    instr->thenInstr    = thenInstr;
    instr->elseInstr    = elseInstr;
    return instr; 
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
















void InstrEval(Instr instrs) { 
    switch(instrs->op) {
        case EXPR       : ExprPrintResult(ExprEval(instrs->expr)); break;
        case ASSIGN     : break;
        case PROC_BLOC  : InstrEval(instrs->listInstr);break;
        case FN_BLOC    : break;
        case IF         : break;
        
        default : printf("Evaluation de L'instruction Non encore implementée \n "); break;     
    }  
}

