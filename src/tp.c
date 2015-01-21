#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>


/*
 * Toute cette premiere partie n'a (normalement) pas besoin d'etre modifiee
 */

int PrintPaddingNb =  4 ;
char PrintPaddingChar = ' ';

#include "type.h"
#include "tp.h"
#include "tp_y.h"
#include "type.c"

extern int yyparse(); 
   
extern int yylineno;

extern int yydebug;

int eval(TreeP tree, VarDeclP decls);
TreeP getChild(TreeP tree, int rank);

/* Niveau de 'verbosite'.
 * Par defaut, n'imprime que le resultat et les messages d'erreur
 */
bool verbose = FALSE;

/* Evaluation ou pas. Par defaut, on evalue les expressions */
bool noEval = FALSE;

/* code d'erreur a retourner */
int errorCode = NO_ERROR;

FILE *fd = NIL(FILE);

/* Appel:
 *   tp [-option]* programme.txt
 * Les options doivent apparaitre avant le nom du fichier du programme.
 * Options: -[eE] -[vV] -[hH?]
 */
int main(int argc, char **argv) {
  int fi, res; 
  
  if ((fi = open("../test/syntaxique/ex1.txt", O_RDONLY)) == -1) {
    fprintf(stderr, "Error: Cannot open %s\n", "../test/syntaxique/ex1.txt");
    exit(USAGE_ERROR);
  }                 
    
  /* redirige l'entree standard sur le fichier.   .. */
  close(0); dup(fi); close(fi);

  /* Lance l'analyse syntaxique de tout le source, en appelant yylex au fur
   * et a mesure. Execute les actions semantiques en parallele avec les
   * reductions.
   * yyparse renvoie 0 si le source est syntaxiquement correct, une valeur
   * differente de 0 en cas d'erreur syntaxique (eventuellement dues a des
   * erreurs lexicales).
   * Comme l'interpretation globale est automatiquement lancee par les actions
   * associees aux reductions, une fois que yyparse a termine il n'y
   * a plus rien a faire (sauf fermer les fichiers)
   * Si le code du programme contient une erreur, on bloque l'evaluation.
   * S'il ny a que des erreurs contextuelles on essaye de ne pas s'arreter
   * a la premiere mais de continuer l'analyse pour en trovuer d'autres, quand
   * c'est possible.
   */
  yydebug = 0;
  res = yyparse();    

  if (fd != NIL(FILE)) fclose(fd);
  if (res == 0 && errorCode == NO_ERROR) return 0;
  else {
    int res2 = res ? SYNTAX_ERROR : errorCode;
    printf("Error in file. Kind of error: %d\n", res2); 
    return res2;
  }
}


void setError(int code) {
  errorCode = code;
  if (code != NO_ERROR) { noEval = TRUE; }
}


/* yyerror:  fonction importee par Bison et a fournir explicitement. Elle
 * est appelee quand Bison detecte une erreur syntaxique.
 * Ici on se contente d'un message minimal.
 */
void yyerror(char *ignore) {
  fprintf(stderr, "Syntax error on line: %d\n", yylineno);
}


/* Tronc commun pour la construction d'arbre */
TreeP makeNode(int nbChildren, short op) {
  TreeP tree = NEW(1, Tree);
  tree->op = op;
  tree->nbChildren = nbChildren;
  tree->u.children = nbChildren > 0 ? NEW(nbChildren, TreeP) : NIL(TreeP);
  return(tree);
}


/* Construction d'un arbre a nbChildren branches, passees en parametres */
TreeP makeTree(short op, int nbChildren, ...) {
  va_list args;
  int i;
  TreeP tree = makeNode(nbChildren, op); 
  va_start(args, nbChildren);
  for (i = 0; i < nbChildren; i++) { 
    tree->u.children[i] = va_arg(args, TreeP);
  }
  va_end(args);
  return(tree);
}


/* Retourne le rankieme fils d'un arbre (de 0 a n-1) */
TreeP getChild(TreeP tree, int rank) {
  return tree->u.children[rank];
}


/* Constructeur de feuille dont la valeur est une chaine de caracteres
 * (un identificateur de variable).
 */
TreeP makeLeafStr(short op, char *str) {
  TreeP tree = makeNode(0, op);
  tree->u.str = str;
  return(tree);
}


/* Constructeur de feuille dont la valeur est un entier */
TreeP makeLeafInt(short op, int val) {
  TreeP tree = makeNode(0, op); 
  tree->u.val = val;
  return(tree);
}

/* Constructeur de feuille dont la valeur est void */
TreeP makeLeafVoid(short op) {
  /* Cette fonction se contente juste de creer une feuille de type String
   * dont l'operateur est op et la valeur est NULL */
  return makeLeafStr(op, NULL);
}

TreeP makeFakeTree() {
    return NULL;
}

/* Ajoute l'arbre tail à l'arbre head et renvoie head, Apres cette operation
 * head a comme elements suivant les elements de tail*/
TreeP addNext(TreeP head, TreeP tail) {
    head->next = tail;
    return head; 
}

/*
 * Seconde partie probablement a modifier
 */

/* Fonctions Utilitaires definie dans tp.h */

/* Renvoi TRUE si la chaine de caractere str est contenue dans le tableau 
 * strArray et FALSE sinon
 */
int arrayContainsStr(char ** strArray, char* str) {
  int len = sizeof(strArray)/sizeof(strArray[0]);
  int i;
  for(i = 0; i < len; ++i)
    if(!strcmp(strArray[i], str)) return TRUE;
    
  return FALSE;
} 

/* Retourne TRUE si le parametre str est un mot clé et FALSE sinon */
/*
int isKeyWord(char *str) {
  return arrayContainsStr(KEYWORDS_LIST, str)
} 
*/





/* Avant evaluation, verifie si tout id qui apparait dans tree a bien ete declare
 * et est donc dans lvar.
 * On impose que ca soit le cas y compris si on n'a pas besoin a l'evaluation de
 * la valeur de cet id.
 */
bool checkScope(TreeP tree, VarDeclP lvar) {
  return FALSE;
}

/* Verifie si besoin que nouv n'apparait pas deja dans list. l'ajoute en
 * tete et renvoie la nouvelle liste
 */
VarDeclP addToScope(VarDeclP list, VarDeclP nouv) {
  return NIL(VarDecl);
}


/* Construit le squelette d'un couple (variable, valeur), sans la valeur. */
VarDeclP makeVar(char *name) {
  VarDeclP res = NEW(1, VarDecl);
  res->name = name; res->next = NIL(VarDecl);
  return(res);
}


/* Associe une variable a l'expression qui definit sa valeur, et procede a 
 * l'evaluation de cette expression, sauf si on est en mode noEval
 */
VarDeclP declVar(char *name, TreeP tree, VarDeclP currentScope) {
  return NIL(VarDecl);
}


/* Evaluation d'une variable */
int evalVar(TreeP tree, VarDeclP decls) {
  return 0;
}


/* Evaluation d'un if then else. Attention a n'evaluer que la partie necessaire ! */
int evalIf(TreeP tree, VarDeclP decls) {
  return 0;
}


VarDeclP evalAff (TreeP tree, VarDeclP decls) {
  return NIL(VarDecl);
}


/* Ici decls correspond au sous-arbre qui est la partie declarative */
VarDeclP evalDecls (TreeP tree) {
  return NIL(VarDecl);
}


/* Evaluation par parcours recursif de l'arbre representant une expression. 
 * Les valeurs des identificateurs situes aux feuilles de l'arbre sont a
 * rechercher dans la liste decls
 * Attention a n'evaluer que ce qui doit l'etre et au bon moment
 * selon la semantique de l'operateur (cas du IF, etc.)
 */
int eval(TreeP tree, VarDeclP decls) {
  if (tree == NIL(Tree)) { exit(UNEXPECTED); }
       switch (tree->op) {
  case ID:
    return evalVar(tree, decls);
  case EQ:
    return (eval(getChild(tree, 0), decls) == eval(getChild(tree, 1), decls));
  case NEQ:
    return (eval(getChild(tree, 0), decls) != eval(getChild(tree, 1), decls));
  case ADD:
    return (eval(getChild(tree, 0), decls) + eval(getChild(tree, 1), decls));
  case SUB:
    return (eval(getChild(tree, 0), decls) - eval(getChild(tree, 1), decls));
  case IF:
    return evalIf(tree, decls);
  default: 
    fprintf(stderr, "Erreur! etiquette indefinie: %d\n", tree->op);
    exit(UNEXPECTED);
  }
}

int evalMain(TreeP tree, VarDeclP lvar) {
  int res;
  if (noEval) {
    fprintf(stderr, "\nSkipping evaluation step.\n");
  } else {
      res = eval(tree, lvar);
      printf("\n/*Result: %d*/\n", res);
  }
  return errorCode;
}
