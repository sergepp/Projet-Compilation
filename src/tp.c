#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/*
 * Toute cette premiere partie n'a (normalement) pas besoin d'etre modifiee
 */

int PrintPaddingNb =  4 ;
char PrintPaddingChar = ' ';

extern char *strdup(const char *);

#include "type.h"
#include "tp.h"
#include "tp_y.h"

#include "instr.h"
#include "scope.h"
#include "expr.h"
#include "var.h"
#include "class.h"




extern int yyparse(); 
   
extern int yylineno;

extern int yydebug;


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
                
  /* Initialisations */
  CurrentMethodName = (char*) malloc(128 * sizeof(char));
  AllDefinedClasses = Integer;
  initializeScope();
  
  printf("Avant le debut du programme\n");
  Class c = AllDefinedClasses;
  while ( c != NULL ) {
        printf("\t%s", c->name);
      c = c->next;
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


#include "var.c"
#include "type.c"
#include "expr.c"
#include "instr.c"
#include "scope.c"
#include "class.c"


