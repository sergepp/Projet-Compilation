Expr exec_instr(Instr i, Scope scope);


Var method_arg_to_var_list(Method m, Expr args);

Expr exec_eval_method_call(Expr e, Scope sc);
    
Expr exec_expr(Expr e, Scope scope);

void exec_assign_right_to_left(Expr left, Expr right);

Expr exec_arithm_expr(Expr expr, Scope scope);

Expr exec_concat_expr(Expr expr, Scope scope) ;
