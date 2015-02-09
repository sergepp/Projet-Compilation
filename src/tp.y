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
%type <Expr>        expr booleanExpr arithmExpr  constant  Opt_L_expr L_expr instanciation  concatExpr  selection
%type <Program>     program
%type <MethodCall>   Opt_extendsDecl  extendsDecl
%type <Class>       L_classDecl classDecl 
%type <Var>         L_varDecl varDecl  L_fieldDecl fieldDecl  Opt_L_classParamDecl L_classParamDecl classParamDecl Opt_L_methodParamDecl L_methodParamDecl methodParamDecl 
%type <Method>      L_methodDecl methodDecl 
%type <Instr>       proceduralBloc functionalBloc L_instr instr instructionBloc  methodBody  Opt_constructorBody constructorBody 
%{
#define YYDEBUG 1


#include "type.h"
#include "tp.h"
#include "tp_y.h"

#include "class.h"
#include "expr.h"
#include "instr.h"
#include "scope.h"
#include "var.h"


extern Class Integer;

extern Class String;

extern Class Void;

extern Scope currentScope;

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
L_classDecl : classDecl           { $$ = $1;    CurrentClass = NULL; }
    | L_classDecl classDecl       { $$ = ClassDeclSetNext($1, $2); } 
;
classDeclHeader  : CLASS CLASS_TYPE '(' Opt_L_classParamDecl ')'  { 
    AssertVarAreNotDupliqued($4);
    AssertClassIsNotDupliqued($2);
    CurrentClass = ClassDecl($2, $4);
   
}           
;
classDecl : classDeclHeader Opt_extendsDecl Opt_constructorBody  IS '{' '}'                         { $$ = ClassDeclComplete($2, $3, NULL, NULL);   ClassDeclAssertIsOk($$);   }
    |       classDeclHeader Opt_extendsDecl Opt_constructorBody  IS '{' L_fieldDecl  '}'            { $$ = ClassDeclComplete($2, $3, $6, NULL);     ClassDeclAssertIsOk($$);   }
    |       classDeclHeader Opt_extendsDecl Opt_constructorBody  IS '{' L_methodDecl '}'            { $$ = ClassDeclComplete($2, $3, NULL, $6);     ClassDeclAssertIsOk($$);   }
    |       classDeclHeader Opt_extendsDecl Opt_constructorBody  IS '{' L_fieldDecl L_methodDecl '}'{ $$ = ClassDeclComplete($2, $3, $6, $7);       ClassDeclAssertIsOk($$);   }
;

 
Opt_L_classParamDecl :      { $$ = NULL; }
    | L_classParamDecl      { $$ = $1;   }
;
L_classParamDecl : classParamDecl           { $$ = $1;  }
    | L_classParamDecl ',' classParamDecl   { $$ = ParamDeclSetNext($1, $3);   }
;
classParamDecl : ID ':' CLASS_TYPE          {  AssertClassExists($3); $$ = ParamDecl($1, $3); }
;

Opt_extendsDecl :   { $$ = NULL; }
    | extendsDecl   { $$ = $1;   }
;
extendsDecl : EXTENDS CLASS_TYPE '(' Opt_L_expr ')' { ExtendsDeclAssertIsOk($2, $4); $$ = ExtendsDecl($2, $4, "constructor"); }
;
Opt_constructorBody : { $$ = InstrFromInstrBloc(NULL); }
    | constructorBody { $$ = $1;  }
;
constructorBody : instructionBloc { $$ = $1; }
;


/* Declaration du corps d'une classe */

L_fieldDecl : fieldDecl      { $$ = $1;  }
    | L_fieldDecl fieldDecl  { $$ = ParamDeclSetNext($1, $2); }
;
fieldDecl :  varDecl                                {  $$ = $1; }
    | VAR STATIC ID ':' CLASS_TYPE ASSIGN expr ';'  {  AssertClassExists($5); $$ = StaticVarDecl($3, $5, $7);   }
    | VAR STATIC ID ':' CLASS_TYPE ';'              {  AssertClassExists($5); $$ = StaticVarDecl($3, $5, NULL); }
;
L_methodDecl : methodDecl      { $$ = $1; }
    | L_methodDecl methodDecl  { $$ = MethodDeclSetNext($1, $2); }
;
methodDecl : DEF OVERRIDE ID '(' Opt_L_methodParamDecl ')' RETURNS CLASS_TYPE methodBody { OverrideMethodDeclAssertIsOk($3, $5, $8, $9, NULL); $$=OverrideMethodDecl($3, $5, $8, $9, NULL); }
        |    DEF OVERRIDE ID '(' Opt_L_methodParamDecl ')' RETURNS CLASS_TYPE ASSIGN expr{ OverrideMethodDeclAssertIsOk($3, $5, $8, NULL, $10);$$=OverrideMethodDecl($3, $5, $8, NULL, $10);} 
        |      DEF STATIC ID '(' Opt_L_methodParamDecl ')' RETURNS CLASS_TYPE methodBody { StaticMethodDeclAssertIsOk($3, $5, $8, $9, NULL);   $$=StaticMethodDecl($3, $5, $8, $9, NULL);}
        |      DEF STATIC ID '(' Opt_L_methodParamDecl ')' RETURNS CLASS_TYPE ASSIGN expr{ StaticMethodDeclAssertIsOk($3, $5, $8, NULL, $10);  $$=StaticMethodDecl($3, $5, $8, NULL, $10);}
        |             DEF ID '(' Opt_L_methodParamDecl ')' RETURNS CLASS_TYPE methodBody { MethodDeclAssertIsOk($2, $4, $7, $8, NULL);         $$=MethodDecl($2, $4, $7, $8, NULL);}
        |             DEF ID '(' Opt_L_methodParamDecl ')' RETURNS CLASS_TYPE ASSIGN expr{ MethodDeclAssertIsOk($2, $4, $7, NULL, $9);         $$=MethodDecl($2, $4, $7, NULL, $9);}
;

Opt_L_methodParamDecl  :                            { $$ = NULL; }
    | L_methodParamDecl                             { $$ = $1;   }
;
L_methodParamDecl  : methodParamDecl                { $$ = $1;   }
    | L_methodParamDecl  ',' methodParamDecl        { $$ = ParamDeclSetNext($1, $3); }
;
methodParamDecl :  ID ':' CLASS_TYPE                { AssertClassExists($3); $$ = ParamDecl($1, $3); }
;

methodBody :  proceduralBloc                        { $$ = $1; }
    | functionalBloc                                { $$ = $1; }        
;

// Declaration d'un bloc d'instruction
instructionBloc : '{'  '}'                          { $$ = InstrFromInstrBloc(NULL); }
    |   '{' L_instr '}'                             { $$ = InstrFromInstrBloc($2);          }
;
proceduralBloc :  '{'  '}'                          { $$ = InstrFromInstrBloc(NULL); }
    |   '{' L_instr '}'                             { $$ = InstrFromInstrBloc($2);          }
    |   '{' L_varDecl IS L_instr '}'                { $$ = InstrFromProcBloc($2, $4);       }
;    

functionalBloc : '{' YIELD expr '}'                 { InstrAssertFnBlocIsOk(NULL, NULL, $3);  $$ = InstrFromFnBloc(NULL, NULL, $3); }
    |    '{' L_instr YIELD expr '}'                 { InstrAssertFnBlocIsOk(NULL, $2,   $4);  $$ = InstrFromFnBloc(NULL, $2,   $4); }
    |    '{' L_varDecl IS L_instr YIELD expr '}'    { InstrAssertFnBlocIsOk($2,   $4,   $6);  $$ = InstrFromFnBloc($2,   $4,   $6); }
;

L_instr : instr         { $$ = $1; }
    | L_instr instr     { $$ = InstrSetNext($1, $2); }
;

instr :  expr ';'                       { $$ = InstrFromExpr($1);   }
    | RETURN expr ';'                   { $$ = InstrFromReturn($2); }
    | proceduralBloc                    { $$ = $1; }
    | functionalBloc                    { $$ = $1; }
    | expr ASSIGN expr ';'              { $$ = InstrFromAssign($1, $3); }
    | IF expr THEN L_instr ELSE L_instr { InstrAssertIfIsOk($2, $4, $6);  $$ = InstrFromIf($2, $4, $6); }
;
Opt_L_expr :            { $$ = NULL; }
    | L_expr            { $$ = $1; }
;
L_expr : expr           { $$ = $1; }
    | L_expr ',' expr   { $$ = ExprSetNext($1, $3); }
;

expr : ID           { /*ExprAssertIDIsOk($1);*/ $$ = ExprFromVar($1); } // Construit une expression à partir d'une varible ou  d'un nom de fonction
    | arithmExpr    { $$ = $1; }
    | instanciation { $$ = $1; }
    | constant      { $$ = $1; }
    | concatExpr    { $$ = $1; }    // Concatenation des chaines de caracteres
    | booleanExpr   { $$ = $1; }
    | selection     { $$ = $1; } 
    | '(' expr ')'  { $$ = $2; }      
;
selection :   expr '.' ID                    { ExprAssertFieldAccessIsOk($1,$3);            $$ = ExprFromFieldAccess($1, $3);      } 
    |   CLASS_TYPE '.' ID                    { AssertClassExists($1);  ExprAssertStaticFieldAccessIsOk($1,$3);      $$ = ExprFromStaticFieldAccess($1, $3); }
    |   CLASS_TYPE '.' ID '(' Opt_L_expr ')' { AssertClassExists($1);  ExprAssertStaticMethodAccessIsOk($1,$3, $5);  $$ = ExprFromStaticMethodAccess($1, $3, $5);}
    |         expr '.' ID '(' Opt_L_expr ')' { $$ = ExprFromMethodAccess($1, $3, $5);  }    
; 
concatExpr : expr CONCAT expr   { $$ = ExprFromConcat($1, $3); }
;
constant : CONST_STR            { $$ = ExprFromString($1);  }
    |      CONST_INT            { $$ = ExprFromInt($1);     }
    |      CONST_VOID           { $$ = ExprFromVoid();      }
;

instanciation : NEW CLASS_TYPE '(' Opt_L_expr ')'   { AssertClassExists($2);  $$ = ExprFromInstanciation($2, $4); }
;
 

arithmExpr : expr ADD expr      { $$ = ExprFromArithmetic($1, ADD, $3); }
    | expr SUB expr             { $$ = ExprFromArithmetic($1, SUB, $3); }
    | expr MUL expr             { $$ = ExprFromArithmetic($1, MUL, $3); }
    | expr DIV expr             { $$ = ExprFromArithmetic($1, DIV, $3); }
    | SUB expr %prec UNARY      { $$ = ExprFromArithmetic(ExprFromInt(0), SUB, $2); } 
    | ADD expr %prec UNARY      { $$ = $2; }   
;

booleanExpr : expr RELOP expr   { $$ = ExprFromBoolean($1, yylval.I, $3); }
;

L_varDecl : varDecl         { $$ = $1;  VarAddToCurrentScope($$); }
    |  L_varDecl varDecl    { $$ =      ParamDeclSetNext($1, $2); }
;
varDecl : VAR ID ':' CLASS_TYPE ASSIGN expr ';' { AssertClassExists($4);$$ = VarDecl($2, $4, $6);    }
    |     VAR ID ':' CLASS_TYPE ';'             { AssertClassExists($4);$$ = VarDecl($2, $4, NULL);  }
;

