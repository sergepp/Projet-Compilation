#include <stdlib.h>

#define TRUE 1
#define FALSE 0 
typedef int bool;

/* deux macros pratiques, utilisees dans les allocations */
#define NEW(howmany, type) (type *) calloc((unsigned) howmany, sizeof(type))
#define NIL(type) (type *) 0

/* Etiquettes additionnelles pour les arbres de syntaxe abstraite.
 * Les tokens tels que ADD, SUB, etc. servent directement d'etiquette.
 * Attention donc a ne pas donner des valeurs identiques a celles des tokens
 * produits par Bison dans le fichier tp_y.h
 */  
#define STATIC_FIELD_ACCESS     1
#define INSTANCE_FIELD_ACCESS   2
#define STATIC_METHOD_CALL      3
#define INSTANCE_METHOD_CALL    4
#define SELECTION               5

#define MINUS 7
#define LIST 8
#define BLOC 9

#define LT  10
#define LTE 11
#define EQ  12
#define NEQ 13
#define GT  14
#define GTE 15

#define FN_BLOC 16
#define PROC_BLOC 17
#define EXPR 18
#define INSTR_BLOC 19
#define VAR_DECL 20
#define VAR_CALL 21
#define INSTR 22
#define INSTANCE 23 

/* Codes d'erreurs */
#define SUCCESS     0
#define ERROR      -1
#define NO_ERROR	0
#define USAGE_ERROR	1
#define LEXICAL_ERROR	2
#define SYNTAX_ERROR    3
#define CONTEXT_ERROR	4
#define EVAL_ERROR	5
#define UNEXPECTED	10


/* Type pour la valeur de retour de Flex et les actions de Bison
 * le premier champ est necessaire pour flex
 * les autres correspondent aux variantes utilisees dans les actions
 * associees aux productions de la grammaire. 
*/
typedef union
{ 
  char C;
  char *S;
  int  I; 
  Expr Expr;
  Class      Class;
  Param      Param;
  Var        Var;
  Method     Method;
  Program    Program;
  Instr      Instr;
  MethodCall MethodCall;
} YYSTYPE;

/* Variables et constantes globales */


/* Fonctions utilitaires */
int arrayContainsStr(char * strArray[], char* str);

/* int isKeyWord(char *str); */

#define YYSTYPE YYSTYPE

/* construction pour les arbres */
Program makeProgram(Class classDefs, Instr instrs);


