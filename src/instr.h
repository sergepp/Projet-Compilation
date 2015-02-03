
void InstrAssertProcBlocIsOk(Var var,Instr instr);


Instr InstrFromProcBloc(Var vars,Instr listInstr);


Instr InstrFromInstrBloc(Instr listInstr);

void InstrAssertFnBlocIsOk(Var vars, Instr listInstr, Expr expr);

Instr InstrFromFnBloc(Var vars, Instr listInstr, Expr expr);


Instr InstrSetNext(Instr instr, Instr next);


Instr InstrFromExpr(Expr expr);


void InstrAssertAssignIsOk(Expr e1, Expr e2);


Instr InstrFromAssign(Expr e1,Expr e2);


void InstrAssertIfIsOk(Expr cond, Instr thenInstr, Instr elseInstr);


Instr InstrFromReturn(Expr expr);


Instr InstrFromIf(Expr cond, Instr thenInstr, Instr elseInstr);


void InstrPrint(Instr inst);

void InstrEval(Instr instrs);
