Digit [0-9]
Letter  [a-zA-Z_]
LD  ({Letter}|{Digit})
Star \*
NotStar [^*]
Delim [ \n\t\r]
Symbol [;,\(\)\{\}:\.]
LitteralString \"([^\"])*\"
SlashStar /\*
NotStarSlash [^*/]
StarSlash \*/
AnyThing .
InlineComment (\/\/.*\n)
BlockComment  (\/\*([^*]|[ \r\n]|(\*+([^*\/]|[ \r\n])))*\*\/+)
%{
#include "type.h"
#include "tp.h"
#include "tp_y.h"
#include <string.h>	
#include <stdio.h>
#include <ctype.h>

extern char *strdup(const char *s);
extern void setError(int code);

extern YYSTYPE yylval;
extern int errorCode;

/* Il est plus economique de ne pas creer une expression reguliere pour chaque
 * mot-clef mais plutot de les reconnaitre dans un premier temps comme des
 * identificateurs et de faire la distinction par un bout de code
 */
int keywordOrClasstypeOrId() { 

  /* Keywords */ 
  if (strcmp("is"       , yytext) == 0 )    return(IS) ;
  if (strcmp("class"    , yytext) == 0 )    return(CLASS) ;
  if (strcmp("extends"  , yytext) == 0 )    return(EXTENDS) ;
  if (strcmp("return"   , yytext) == 0 )    return(RETURN) ;
  if (strcmp("returns"  , yytext) == 0 )    return(RETURNS) ;
  if (strcmp("def"      , yytext) == 0 )    return(DEF) ;
  if (strcmp("static"   , yytext) == 0 )    return(STATIC) ;
  if (strcmp("override" , yytext) == 0 )    return(OVERRIDE) ;
  if (strcmp("var"      , yytext) == 0 )    return(VAR) ;
  if (strcmp("yield"    , yytext) == 0 )    return(YIELD) ;
  if (strcmp("new"      , yytext) == 0 )    return(NEW) ;
  if (strcmp("if"       , yytext) == 0 )    return(IF) ;
  if (strcmp("then"     , yytext) == 0 )    return(THEN) ;
  if (strcmp("else"     , yytext) == 0 )    return(ELSE) ;
  if (strcmp("void"     , yytext) == 0 )    return(CONST_VOID); 
  
  yylval.S = strdup(yytext); 
  
  /* ClassType */
  /* Si le premier caractere de l'identifiant est en majusucle, alors
   * il s'agit d'un nom de classe
   */
  if ( toupper(yylval.S[0]) == yylval.S[0] ) return(CLASS_TYPE); 
    
  /* Identificateur */
  return(ID);
}


void lexError(char c) {
  fprintf(stderr, "Error: Skipping invalid character '%c' on line %d\n",
          c, yylineno);
  setError(LEXICAL_ERROR);
}


/* les codes symboliques pour les unites lexicales (CST, IF, ADD, ...) sont
 * definis dans tp_y.h et serviront aussi d'etiquettes pour les sommets de
 * l'arbre de syntaxe abstraite qui sera construit par la suite du processus
 * de compilation.
 * 
 * Les "return" qui apparaissent dans les actions associees aux expressions
 * reguleres peuvent renvoyer:
 * - soit le code symbolique d'une U.L.
 * - soit un simple caractere
 * L'eventuelle partie "valeur" de l'U.L. doit etre stockee dans une des
 * variantes de la variable yylval (definie comme etant de type YYSTYPE)
 * afin que les outils compagnons de l'analyseur lexical puisse l'y recuperer.
 * Attention: le contenu de yylval va etre ecrase a chaque appel a l'analyseur
 * lexical et doit donc etre sauvegarde si besoin.
 */
%}

%%
{Digit}+            { yylval.I = strtol(yytext, NULL, 0);  return(CONST_INT); }
{LitteralString}    { yylval.S = strdup(yytext);           return(CONST_STR); }
{Letter}{LD}*       { return keywordOrClasstypeOrId(); }
"&"                 { return(CONCAT); }
"+"                 { return(ADD); }
"-"                 { return(SUB); }
"*"                 { return(MUL); }
"/"                 { return(DIV); }
"="                 { yylval.I = EQ;    return(RELOP); }
">="                { yylval.I = GTE;   return(RELOP); }
"<="                { yylval.I = LTE;   return(RELOP); }
"<>"                { yylval.I = NEQ;   return(RELOP); }
"<"                 { yylval.I = LT;    return(RELOP); }
">"                 { yylval.I = GT;    return(RELOP); }
":="                { return(ASSIGN); }
{Symbol}            { return(yytext[0]); }
{InlineComment}     { }
{BlockComment}      { }
{Delim}             { }
{AnyThing}          { return(ERROR); }
%%
