
void InstrAssertProcBlocIsOk(Instr ins1,Instr ins2){
	printf("non implementer \n");	
	if(ins1->expr==NULL){
		/*faire*/
	}else{
		/*faire*/
	}

}


Instr InstrFromProcBloc(Var vars,Instr listInstr){
	Instr instr = NEW(1, _Instr);
    instr->op           = PROC_BLOC;
    instr->expr         = NULL;
    instr->yield        = NULL;
    instr->var          = vars;
    instr->listInstr    = listInstr;
    instr->leftExpr     = NULL;
    instr->rightExpr    = NULL;
    instr->cond         = NULL;
    instr->thenInstr    = NULL;
    instr->elseInstr    = NULL;
    instr->next         = NULL;
    return instr; 
}

Instr InstrFromInstrBloc(Instr listInstr){
	Instr instr = NEW(1, _Instr);
    instr->op           = INSTR_BLOC;
    instr->expr         = NULL;
    instr->yield        = NULL;
    instr->var          = NULL;
    instr->listInstr    = listInstr;
    instr->leftExpr     = NULL;
    instr->rightExpr    = NULL;
    instr->cond         = NULL;
    instr->thenInstr    = NULL;
    instr->elseInstr    = NULL;
    instr->next         = NULL;
    return instr; 
}

void InstrAssertFnBlocIsOk(Instr ins1,Instr ins2,Instr ins3){
	printf("not implemented \n");
	if(ins1->expr==NULL){
		/*faire*/
	}else if(ins1->expr==NULL && ins2->expr==NULL) {
		/*faire*/
	}else if (ins1->expr!=NULL && ins2->expr!=NULL && ins3->expr!=NULL){
		/*faire*/
	}

}


Instr InstrFromFnBloc(Var vars, Instr listInstr, Expr expr){
	Instr instr = NEW(1, _Instr);
    instr->op           = FN_BLOC;
    instr->expr         = NULL;
    instr->yield        = expr;
    instr->var          = vars;
    instr->listInstr    = listInstr;
    instr->leftExpr     = NULL;
    instr->rightExpr    = NULL;
    instr->cond         = NULL;
    instr->thenInstr    = NULL;
    instr->elseInstr    = NULL;
    instr->next         = NULL;
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


Instr InstrFromExpr(Expr expr){
    Instr instr = NEW(1, _Instr);
    instr->op           = EXPR;
    instr->expr         = expr;
    instr->yield        = NULL;
    instr->var          = NULL;
    instr->listInstr    = NULL;
    instr->leftExpr     = NULL;
    instr->rightExpr    = NULL;
    instr->cond         = NULL;
    instr->thenInstr    = NULL;
    instr->elseInstr    = NULL;
    instr->next         = NULL;
    return instr; 
}

void InstrAssertAssignIsOk(Instr ins1,Instr ins2){
	printf("non implementer \n");
}

Instr InstrFromAssign(Expr e1,Expr e2){
	Instr instr = NEW(1, _Instr);
    instr->op           = ASSIGN;
    instr->expr         = NULL;
    instr->yield        = NULL;
    instr->var          = NULL;
    instr->listInstr    = NULL;
    instr->leftExpr     = e1;
    instr->rightExpr    = e2;
    instr->cond         = NULL;
    instr->thenInstr    = NULL;
    instr->elseInstr    = NULL;
    instr->next         = NULL;
    return instr; 
}

void InstrAssertIfIsOk(Instr ins1,Instr ins2,Instr ins3){
	printf("non implementer \n");
}

Instr InstrFromIf(Expr cond, Instr thenInstr, Instr elseInstr){
	Instr instr = NEW(1, _Instr);
    instr->op           = IF;
    instr->expr         = NULL;
    instr->yield        = NULL;
    instr->var          = NULL;
    instr->listInstr    = NULL;
    instr->leftExpr     = NULL;
    instr->rightExpr    = NULL;
    instr->cond         = cond;
    instr->thenInstr    = thenInstr;
    instr->elseInstr    = elseInstr;
    instr->next         = NULL;
    return instr; 
}


void InstrAssertVarDeclIsOk(char* name, char* classname, Expr e) {
    printf("not implemented");
}

Var InstrFromVarDecl(char* name, char* classname, Expr e) {
    Var v = NEW(1, _Var);
    printf("not implemented");
    return v;
}

void InstrAssertAbstractVarDeclIsOk(char* name, char* classname) {
    InstrAssertVarDeclIsOk(name, classname, NULL);
    printf("not implemented");
}



