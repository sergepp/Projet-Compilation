/* 
 * les tokens ici sont ceux supposes etre renvoyes par l'analyseur lexical
 * A adapter par chacun en fonction de ce qu'il a ecrit dans tp.l
 * Bison ecrase le contenu de tp_y.h a partir de la description de la ligne
 * suivante. C'est donc cette ligne qu'il faut adapter si besoin, pas tp_y.h !
 *
 */
%token IS CLASS EXTENDS RETURN RETURNS DEF STATIC OVERRIDE VAR YIELD CONCAT NEW IF THEN ELSE ADD SUB MUL DIV CONST_VOID
%token <S> ID CONST_STR	CLASS_TYPE  /* voir %type ci-dessous pour le sens de <S> et Cie */
%token <I> CONST_INT RELOP

/* 
 * indications de precedence d'associativite. Les operateurs sur une meme
 * ligne (separes par un espace) ont la meme priorite. Les ligns sont donnees
 * par precedence croissante d'operateurs.
 *
 */
%nonassoc ELSE
%nonassoc THEN
%nonassoc IF
%nonassoc RETURN
%nonassoc RELOP
%right ASSIGN
%nonassoc NEW
%left ADD SUB
%left MUL DIV 
%left UNARY
%left CONCAT
%nonassoc CONST_INT CONST_STR CONST_VOID
%left '.'
%left ID CLASS_TYPE
%left '(' ')'
%left '{' '}'


/** 
 * Voir la definition de YYSTYPE dans main.h 
 * Les indications ci-dessous servent a indiquer a Bison que les "valeurs" $i
 * ou $$ associees a ces non-terminaux doivent utiliser la variante indiquee
 * de l'union YYSTYPE (par exemple la variante D ou S, etc.)
 * La "valeur" associee a un terminal utilise toujours la meme variante
 */
%type <Expr>        expr booleanExpr arithmExpr  constant  Opt_L_expr L_expr instanciation  concatExpr returnExpr  selection
%type <Program>     program
%type <ClassCall>   Opt_extendsDecl extendsDecl
%type <Class>       L_classDecl classDecl 
%type <Var>         L_varDecl varDecl L_fieldDecl fieldDecl  Opt_L_classParamDecl L_classParamDecl classParamDecl L_methodParamDecl methodParamDecl 
%type <Method>      L_methodDecl methodDecl 
%type <Instruction> proceduralBloc functionalBloc L_instr instr instructionBloc  methodBody  Opt_constructorBody constructorBody Opt_L_methodParamDecl
%{
#define YYDEBUG 1


#include "type.h"
#include "tp.h"
#include "tp_y.h"

extern Class Integer;

extern Class String;

extern Class Void;

extern Class AllDefinedClasses; 

extern int yylex();	/* fournie par Flex */
extern void yyerror();  /* definie dans tp.c */
%}

%% 
 /*
 * Attention: on est dans un analyseur ascendant donc on s'occupe des composants
 * d'une construction avant de traiter la construction elle-meme. Dans le cas
 * d'un IF on traitera donc la condition et les parties THEN et ELSE avant
 * de traiter le 'IF' lui-meme. Comme on ne doit evaluer que l'une des deux
 * branches 'then' ou 'else' selon la valeur de la condition, on ne peut pas
 * evaluer les expressions au fur et a mesure qu'on les rencontre puisqu'on ne
 * sait pas si on fait partie d'un IF ou pas. On doit attendre de connaitre
 * l'expression complete pour savoir si telle partie doit etre evaluee ou non.
 *
 * Les macros d'allocation NEW et de nullite NIL sont definies dans tp.h.
 * Leur usage n'est bien sur pas obligatoire, juste conseille !
 *
 * Les definition des types YYSTYPE, VarDecl, VarDeclP, Tree, TreeP et autres
 * sont dans tp.h
 */

/* "program" est l'axiome de la grammaire */
program : proceduralBloc         { $$ = makeProgram(NULL, $1); }
    | L_classDecl proceduralBloc { $$ = makeProgram($1, $2);   }
; 
L_classDecl : classDecl           { $$ = $1; }
    | L_classDecl classDecl       { $$ = ClassDeclSetNext($1, $2); } 
;
classDecl :  CLASS CLASS_TYPE '(' Opt_L_classParamDecl ')' Opt_extendsDecl  Opt_constructorBody  IS '{' '}'  
            { ClassDeclAssertIsOk($2, $4, $6, $7, NULL, NULL);       $$ = ClassDecl($2, $4, $6, $7, NULL, NULL);  }
            
    |       CLASS CLASS_TYPE '(' Opt_L_classParamDecl ')' Opt_extendsDecl  Opt_constructorBody  IS '{' L_fieldDecl  '}' 
            { ClassDeclAssertIsOk($2, $4, $6, $7, $10, NULL);        $$ = ClassDecl($2, $4, $6, $7, $10, NULL);    }
            
    |       CLASS CLASS_TYPE '(' Opt_L_classParamDecl ')' Opt_extendsDecl  Opt_constructorBody  IS '{' L_methodDecl '}' 
            { ClassDeclAssertIsOk($2, $4, $6, $7, NULL, $10);        $$ = ClassDecl($2, $4, $6, $7, NULL, $10);    }
            
    |       CLASS CLASS_TYPE '(' Opt_L_classParamDecl ')' Opt_extendsDecl  Opt_constructorBody  IS '{' L_fieldDecl L_methodDecl '}'   
            { ClassDeclAssertIsOk($2, $4, $6, $7, $10, $11);         $$ = ClassDecl($2, $4, $6, $7, $10, $11);      }
;

 
Opt_L_classParamDecl :      { $$ = NULL; }
    | L_classParamDecl      { $$ = $1;   }
;
L_classParamDecl : classParamDecl           { $$ = $1;   }
    | L_classParamDecl ',' classParamDecl   { $$ = ParamDeclSetNext($1, $3);   }
;
classParamDecl : ID ':' CLASS_TYPE          { ParamDeclAssertIsOk($1, $3); $$ = ParamDecl($1, $3); }
;

Opt_extendsDecl :   { $$ = NULL; }
    | extendsDecl   { $$ = $1;   }
;
extendsDecl : EXTENDS CLASS_TYPE '(' Opt_L_expr ')' { ExtendsDeclAssertIsOk($2, $4); $$ = ExtendsDecl($2, $4); }
;
Opt_constructorBody : { $$ = NULL; }
    | constructorBody { $$ = $1;  }
;
constructorBody : instructionBloc { $$ = $1; }
;


/* Declaration du corps d'une classe */

L_fieldDecl : fieldDecl 
    | L_fieldDecl fieldDecl  
;
fieldDecl :  varDecl                                {  $$ = $1; }
    | VAR STATIC ID ':' CLASS_TYPE ASSIGN expr ';'  {  StaticVarDeclAssertIsOk($3, $5, $7);   $$ = StaticVarDecl($3, $5, $7);   }
    | VAR STATIC ID ':' CLASS_TYPE ';'              {  StaticVarDeclAssertIsOk($3, $5, NULL); $$ = StaticVarDecl($3, $5, NULL); }
;
L_methodDecl : methodDecl      { $$ = $1; }
    | L_methodDecl methodDecl  { $$ = MethodDeclSetNext($1, $2); }
;
methodDecl : DEF OVERRIDE ID '(' Opt_L_methodParamDecl ')' RETURNS CLASS_TYPE methodBody  { OverrideMethodDeclAssertIsOk($3, $5, $8, $9);  $$ = OverrideMethodDecl($3, $5, $8, $9); }
        |    DEF OVERRIDE ID '(' Opt_L_methodParamDecl ')' RETURNS CLASS_TYPE ASSIGN expr { OverrideMethodDeclAssertIsOk($3, $5, $8, $10); $$ = OverrideMethodDecl($3, $5, $8, $10);} 
        |      DEF STATIC ID '(' Opt_L_methodParamDecl ')' RETURNS CLASS_TYPE methodBody  { StaticMethodDeclAssertIsOk($3, $5, $8, $9);  $$ = StaticMethodDecl($3, $5, $8, $9);     }
        |      DEF STATIC ID '(' Opt_L_methodParamDecl ')' RETURNS CLASS_TYPE ASSIGN expr { StaticMethodDeclAssertIsOk($3, $5, $8, $10); $$ = StaticMethodDecl($3, $5, $8, $10);    }
        |             DEF ID '(' Opt_L_methodParamDecl ')' RETURNS CLASS_TYPE methodBody  { MethodDeclAssertIsOk($2, $4, $7, $8);  $$ = MethodDecl($2, $4, $7, $8);                 }
        |             DEF ID '(' Opt_L_methodParamDecl ')' RETURNS CLASS_TYPE ASSIGN expr { MethodDeclAssertIsOk($2, $4, $7, $9);  $$ = MethodDecl($2, $4, $7, $9);                 }
;

Opt_L_methodParamDecl  :                            { $$ = NULL; }
    | L_methodParamDecl                             { $$ = $1;   }
;
L_methodParamDecl  : methodParamDecl                { $$ = $1;   }
    | L_methodParamDecl  ',' methodParamDecl        { $$ = MethodDeclParamSetNext($1, $3); }
;
methodParamDecl :  ID ':' CLASS_TYPE                { ParamDeclAssertIsOk($1, $3); $$ = ParamDecl($1, $3); }
;


methodBody :  proceduralBloc                        { $$ = $1; }
    | functionalBloc                                { $$ = $1; }        
;

// Declaration d'un bloc d'instruction 
instructionBloc : '{'  '}'                          { $$ = NULL; }
    | '{' L_instr '}'                               { InstrAssertProcBlocIsOk(NULL, $2);      $$ = InstrFromInstrBloc($2); }
;
proceduralBloc :  '{'  '}'                          { $$ = NULL; }
    |   '{' L_instr '}'                             { InstrAssertProcBlocIsOk(NULL, $2);      $$ = InstrFromInstrBloc($2);  }
    |   '{' L_varDecl IS L_instr '}'                { InstrAssertProcBlocIsOk($2, $4);        $$ = InstrFromProcBloc($2, $4); }
;    

functionalBloc : '{' YIELD expr '}'                 { InstrAssertFnBlocIsOk(NULL, NULL, $3);  $$ = InstrFromFnBloc(NULL, NULL, $3); }
    |    '{' L_instr YIELD expr '}'                 { InstrAssertFnBlocIsOk(NULL, $2,   $4);  $$ = InstrFromFnBloc(NULL, $2,   $4); }
    |    '{' L_varDecl IS L_instr YIELD expr '}'    { InstrAssertFnBlocIsOk($2,   $4,   $6);  $$ = InstrFromFnBloc($2,   $4,   $6); }
;

L_instr : instr         { $$ = $1; }
    | L_instr instr     { $$ = InstrSetNext($1, $2); }
;

instr :  expr ';'                       { $$ = InstrFromExpr($1); }
    | proceduralBloc                    { $$ = $1; }
    | functionalBloc                    { $$ = $1; }
    | expr ASSIGN expr ';'              { InstrAssertAssignIsOk($1, $3);  $$ = InstrFromAssign($1, $3); }
    | IF expr THEN L_instr ELSE L_instr { InstrAssertIfIsOk($2, $4, $6);  $$ = InstrFromIf($2, $4, $6); }
;
Opt_L_expr :            { $$ = NULL; }
    | L_expr            { $$ = $1; }
;
L_expr : expr           { $$ = $1; }
    | L_expr ',' expr   { $$ = ExprSetNext($1, $3); }
;

expr : ID           { ExprAssertIDIsOk($1); $$ = ExprFromVar($1); } // Construit un expression à partir d'une varible ou  d'un nom de fonction
    | arithmExpr    { $$ = $1; }
    | instanciation { $$ = $1; }
    | constant      { $$ = $1; }
    | concatExpr    { $$ = $1; }// Concatenation des chaines de caracteres
    | returnExpr    { $$ = $1; }
    | booleanExpr   { $$ = $1; }
    | selection     { $$ = $1; } 
    | '(' expr ')'  { $$ = $2; }      
;
selection :   expr '.' ID                    { ExprAssertFieldAccessIsOk($1,$3);            $$ = ExprFromFieldAccess($1, $3);       } 
    |   CLASS_TYPE '.' ID                    { ExprAssertStaticFieldAccessIsOk($1,$3);      $$ = ExprFromStaticFieldAccess($1, $3); }
    |   CLASS_TYPE '.' ID '(' Opt_L_expr ')' { ExprAssertStaticMethodAccessIsOk($1,$3, $5); $$ = ExprFromStaticMethodAccess($1, $3);}
    |         expr '.' ID '(' Opt_L_expr ')' { ExprAssertMethodAccessIsOk($1,$3, $5);       $$ = ExprFromMethodAccess($1, $3, $5);  }    
; 
concatExpr : expr CONCAT expr   { ExprAssertInheritsType(StringType(), $1,$3);  $$ = ExprFromConcat($1, $3); }
;
returnExpr : RETURN expr        { $$ = ExprFromReturn($2); }
;
constant : CONST_STR            { $$ = ExprFromString($1);  }
    |      CONST_INT            { $$ = ExprFromInt($1);     }
    |      CONST_VOID           { $$ = ExprFromVoid();      }
;

instanciation : NEW CLASS_TYPE '(' Opt_L_expr ')'   { ExprAssertInstanciationIsOk($2, $4);  $$ = ExprFromInstanciation($2, $4); }
;

arithmExpr : expr ADD expr      { ExprAssertInheritsType(Integer, $1,$3);  $$ = ExprFromArithmetic($1, ADD, $3); }
    | expr SUB expr             { ExprAssertInheritsType(Integer, $1,$3);  $$ = ExprFromArithmetic($1, SUB, $3); }
    | expr MUL expr             { ExprAssertInheritsType(Integer, $1,$3);  $$ = ExprFromArithmetic($1, MUL, $3); }
    | expr DIV expr             { ExprAssertInheritsType(Integer, $1,$3);  $$ = ExprFromArithmetic($1, DIV, $3); }
    | SUB expr %prec UNARY      { ExprAssertInheritsType(Integer, $2);     $$ = ExprFromArithmetic(ExprFromInt(0), SUB, $2); } 
    | ADD expr %prec UNARY      { ExprAssertInheritsType(Integer, $2);     $$ = $2; }   
;

booleanExpr : expr RELOP expr   { ExprAssertInheritsType(Integer, $1,$3);  $$ = ExprFromBoolean($1, yylval.I, $3); }
;

L_varDecl : varDecl         { $$ = $1; }
    |  L_varDecl varDecl    { $$ = InstrSetNext($1, $2); }
;
varDecl : VAR ID ':' CLASS_TYPE ASSIGN expr ';' { InstrAssertVarDeclIsOk($2, $4, $6);            $$ = InstrFromVarDecl($2, $4, $6);   }
    |     VAR ID ':' CLASS_TYPE ';'             { InstrAssertAbstractVarDeclIsOk($2, $4);  $$ = InstrFromVarDecl($2, $4, NULL); }
;

