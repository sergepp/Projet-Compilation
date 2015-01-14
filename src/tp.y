/* les tokens ici sont ceux supposes etre renvoyes par l'analyseur lexical
 * A adapter par chacun en fonction de ce qu'il a ecrit dans tp.l
 * Bison ecrase le contenu de tp_y.h a partir de la description de la ligne
 * suivante. C'est donc cette ligne qu'il faut adapter si besoin, pas tp_y.h !
 */
%token IS CLASS EXTENDS RETURN RETURNS DEF STATIC OVERRIDE VAR YIELD CONCAT NEW IF THEN ELSE ADD SUB MUL DIV CONST_VOID
%token <S> ID CONST_STR	CLASS_TYPE  /* voir %type ci-dessous pour le sens de <S> et Cie */
%token <I> CONST_INT RELOP

/* indications de precedence d'associativite. Les operateurs sur une meme
 * ligne (separes par un espace) ont la meme priorite. Les ligns sont donnees
 * par precedence croissante d'operateurs.
 */
%nonassoc ELSE
%nonassoc THEN
%nonassoc IF
%nonassoc RETURN
%right ASSIGN
%nonassoc NEW
%left ADD SUB
%left MUL DIV
%left CONCAT
%nonassoc CONST_INT CONST_STR CONST_VOID
%left '.'
%left ID CLASS_TYPE
%left '(' ')'
%left '{' '}'


/* voir la definition de YYSTYPE dans main.h 
 * Les indications ci-dessous servent a indiquer a Bison que les "valeurs" $i
 * ou $$ associees a ces non-terminaux doivent utiliser la variante indiquee
 * de l'union YYSTYPE (par exemple la variante D ou S, etc.)
 * La "valeur" associee a un terminal utilise toujours la meme variante
 */
%type <C> REL
%type <T> expr booleanExpr arithmExpr instanciation  constant concatExpr returnExpr  selection  
%type <T> proceduralBloc functionalBloc
%type <T> L_instr instr  L_varDecl varDecl Opt_L_expr L_expr

%{
#define YYDEBUG 1
#include "tp.h"     /* les definition des types et les etiquettes des noeuds */

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
program : instructionBloc
    | L_classDef instructionBloc
; 
L_classDef : classDef
    | L_classDef classDef
;
classDef :  classDecl IS '{' '}'
    |       classDecl IS '{' L_fieldDecl  '}'
    |       classDecl IS '{' L_methodDecl '}'
    |       classDecl IS '{' L_fieldDecl L_methodDecl '}'
;


/* Declaration de l'entete d'une classe */
classDecl : CLASS CLASS_TYPE '(' Opt_L_classParamDecl ')' Opt_extendsDecl  Opt_constructorBody
;
Opt_L_classParamDecl : 
    | L_classParamDecl
;
L_classParamDecl : classParamDecl
    | L_classParamDecl ',' classParamDecl 
;
classParamDecl : ID ':' CLASS_TYPE
;

Opt_extendsDecl : 
    | extendsDecl
;
extendsDecl : EXTENDS CLASS_TYPE '(' Opt_L_expr ')'
;
Opt_constructorBody : 
    | constructorBody
;
constructorBody : instructionBloc
;


/* Declaration du corps d'une classe */

L_fieldDecl : fieldDecl 
    | L_fieldDecl fieldDecl  
;
fieldDecl :  VAR ID ':' CLASS_TYPE ASSIGN expr ';' 
    |        VAR ID ':' CLASS_TYPE ';'
    | VAR STATIC ID ':' CLASS_TYPE ASSIGN expr ';'
    | VAR STATIC ID ':' CLASS_TYPE ';'
;
L_methodDecl : methodDecl
    | L_methodDecl methodDecl  
;
methodDecl : DEF OVERRIDE STATIC ID '(' Opt_L_methodParamDecl ')' RETURNS CLASS_TYPE methodBody
        |    DEF OVERRIDE STATIC ID '(' Opt_L_methodParamDecl ')' RETURNS CLASS_TYPE ASSIGN expr  // Ici Le ';' est il obligatoire ? 
        
        |           DEF OVERRIDE ID '(' Opt_L_methodParamDecl ')' RETURNS CLASS_TYPE methodBody
        |           DEF OVERRIDE ID '(' Opt_L_methodParamDecl ')' RETURNS CLASS_TYPE ASSIGN expr 
        
        |             DEF STATIC ID '(' Opt_L_methodParamDecl ')' RETURNS CLASS_TYPE methodBody
        |             DEF STATIC ID '(' Opt_L_methodParamDecl ')' RETURNS CLASS_TYPE ASSIGN expr 
        
        |                    DEF ID '(' Opt_L_methodParamDecl ')' RETURNS CLASS_TYPE methodBody
        |                    DEF ID '(' Opt_L_methodParamDecl ')' RETURNS CLASS_TYPE ASSIGN expr 
;

Opt_L_methodParamDecl  : 
    | L_methodParamDecl 
;
L_methodParamDecl  : methodParamDecl
    | L_methodParamDecl  ',' methodParamDecl  
;
methodParamDecl :  ID ':' ID
;


methodBody :  proceduralBloc 
    | functionalBloc
;

// Declaration d'un bloc d'instruction 
instructionBloc : '{'  '}'
    | '{' L_instr '}'
;
L_instr : instr         { $$ = $1; }
    | L_instr instr     { $$ = addNext($1, $2); }
;

instr :  expr ';'                       { $$ = $1; }
    | proceduralBloc                    { $$ = $1; }
    | functionalBloc                    { $$ = $1; }
    | expr ASSIGN expr ';'              { $$ = makeTree(ASSIGN, 2, $1, $3);  }
    | IF booleanExpr THEN L_instr ELSE L_instr { $$ = makeTree(IF, 3, $2, $4, $6); }
;
Opt_L_expr :            { $$ = NULL; }
    | L_expr            { $$ = $1; }
;
L_expr : expr           { $$ = $1; }
    | L_expr ',' expr   { $$ = addNext($1, $3); }
;

expr : ID           { $$ = makeLeafStr(ID, $1); } // Delete
    | arithmExpr    { $$ = $1; }
    | instanciation { $$ = $1; }
    | constant      { $$ = $1; }
    | concatExpr    { $$ = $1; }// Concatenation des chaines de caracteres
    | returnExpr    { $$ = $1; }
    | selection     { $$ = $1; } 
;
selection :   expr '.' ID                    // Field access
    |   CLASS_TYPE '.' ID                    // Static Field access
    |   CLASS_TYPE '.' ID '(' Opt_L_expr ')' // Static Method Call
    |         expr '.' ID '(' Opt_L_expr ')' // Method Call    
; 
concatExpr : expr CONCAT expr   { $$ = makeTree(CONCAT, 2, $1, $3); }
;
returnExpr : RETURN expr        { $$ = $2; }
;
constant : CONST_STR            { $$ = makeLeafStr(CONST_STR,   $1); }
    |      CONST_INT            { $$ = makeLeafInt(CONST_INT,   $1); }
    |      CONST_VOID           { $$ = makeLeafVoid(CONST_VOID); }
;

instanciation : NEW CLASS_TYPE '(' Opt_L_expr ')'   { $$ = makeTree(NEW, 2, makeLeafStr(CLASS_TYPE,$2), $4); }
;

arithmExpr : expr ADD expr  { $$ = makeTree(ADD, 2, $1, $3); }
    | expr SUB expr         { $$ = makeTree(SUB, 2, $1, $3); }
    | expr MUL expr         { $$ = makeTree(MUL, 2, $1, $3); }
    | expr DIV expr         { $$ = makeTree(DIV, 2, $1, $3); }
;

booleanExpr : expr REL expr { $$ = makeTree($2, 2, $1, $3); }
    | '(' booleanExpr ')'   { $$ = $2; }
;
REL : RELOP                 { $$ = yylval.I; }
;

// Instructions 
proceduralBloc : '{'  '}'            { $$ = makeTree(BLOC, 3, NULL, NULL, NULL); } // Voir Fonctionnl Bloc pour comprendre le 3eme parametre c'est le meme
    |   '{' L_instr   '}'            { $$ = makeTree(BLOC, 3, NULL,   $2, NULL); }  
    |   '{' L_varDecl IS L_instr '}' { $$ = makeTree(BLOC, 3, $2,     $4, NULL); }    
;

functionalBloc : '{' YIELD expr '}'                 { $$ = makeTree(BLOC, 3, NULL, NULL, $3); }
    |    '{' L_instr YIELD expr '}'                 { $$ = makeTree(BLOC, 3, NULL,   $2, $4); }
    |    '{' L_varDecl IS L_instr YIELD expr '}'    { $$ = makeTree(BLOC, 3,   $2,   $4, $6); }
;

L_varDecl : varDecl 
    |  L_varDecl varDecl 
;
varDecl : VAR ID ':' CLASS_TYPE ASSIGN expr ';'
    |     VAR ID ':' CLASS_TYPE ';'
;

