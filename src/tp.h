#include <stdlib.h>

/* deux macros pratiques, utilisees dans les allocations */
#define NEW(howmany, type) (type *) calloc((unsigned) howmany, sizeof(type))
#define NIL(type) (type *) 0

#define TRUE 1
#define FALSE 0 

typedef int bool;

/* la structure d'un arbre (noeud ou feuille) */
typedef struct _Tree {
  short op;         /* etiquette de l'operateur courant */
  short nbChildren; /* nombre de sous-arbres */
  union {
    char *str;      /* valeur de la feuille si op = ID ou STR */
    int val;        /* valeur de la feuille si op = CST */
    struct _Tree **children; /* tableau des sous-arbres */
  } u;
  struct _Tree* next ; 
} Tree, *TreeP;


/* la structure ci-dessous permet de memoriser des listes variable/valeur */
typedef struct _Decl
{ char *name;
  int val;
  struct _Decl *next;
} VarDecl, *VarDeclP;


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
#define GT 14
#define GTE 15

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
  int I; 
  TreeP T;
} YYSTYPE;

/* Variables et constantes globales */


/* Fonctions utilitaires */
int arrayContainsStr(char * strArray[], char* str);

/* int isKeyWord(char *str); */

#define YYSTYPE YYSTYPE

/* construction des declarations */
VarDeclP makeVar(char *name);
VarDeclP declVar(char *name, TreeP tree, VarDeclP currentScope);

/* construction pour les arbres */
TreeP makeLeafStr(short op, char *str);
TreeP makeLeafInt(short op, int val);
TreeP makeTree(short op, int nbChildren, ...);
TreeP makeLeafVoid(short op);
TreeP makeFakeTree();

/* Ajoute l'arbre tail à l'arbre head et renvoie head, Apres cette operation
 * head a comme elements suivant les elements de tail*/
TreeP addNext(TreeP head, TreeP tail);


/* evaluateur d'expressions */
int evalMain(TreeP tree, VarDeclP lvar);
VarDeclP evalDecls (TreeP tree);

/* ecriture formatee */
void pprintVar(VarDeclP decl, TreeP tree);
void pprintValueVar(VarDeclP decl);
void pprint(TreeP tree);
void pprintMain(TreeP);
