/*
 * Un petit programme de demonstration qui n'utilise que l'analyse lexicale.
 * Permet principalement de tester la correction de l'analyseur lexical et de
 * l'interface entre celui-ci et le programme qui l'appelle.
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "tp.h"
#include "tp_y.h"
extern char *strdup(const char *);

/* Couple Ident, numero de ligne de sa premiere apparition */
typedef struct {
  int line;
  char *id;
} IdentS, *IdentP;

/* Table des identificateurs avec leur numero de ligne et son compteur */
IdentP idents = NIL(IdentS);
int nbIdent = 0;


/* Fonction appelee par le programme principal pour obtenir l'unite lexicale
 * suivante. Elle est produite par Flex (fichier tp_l.c)
 */
extern int yylex (void);

/* Chaine de caractere qui est une instance du token courant : definie et
 * mise a jour dans tp_l.c
 */
extern char *yytext;

/* Le numero de ligne courant : defini et mis a jour dans tp_l.c */
extern int yylineno;

/* Variable pour interfacer flex avec le programme qui l'appelle, notamment
 * pour transmettre la "valeur", en plus du type de token reconnu.
 * Le type YYSTYPE est defini dans tp.h.
 */
YYSTYPE yylval;

bool verbose = FALSE;

void setError(int code) {
  /* presente juste pour des raisons de compatibilite */
}

/* Recherche dans la table l'entree correspondant a un identificateur */
IdentP getIdent(char * id) {
  int i;
  for (i = 0; i < nbIdent; i++) {
    if (!strcmp(id, idents[i].id)) return(&idents[i]);
  }
  return NIL(IdentS);
}

/* Cree un identificateur */
IdentP makeIdent(int line, char *id) {
  IdentP ident = getIdent(id);
  if (!ident) {
    ident = &idents[nbIdent++];
    ident->line = line;
    /* Si on a duplique la chaine dans la partie Flex, il n'y a pas de raison
     * de le faire a nouveau ici.
     * Comme ca risque de dependre de ce que les uns et les autres font dans
     * tp.l, je prefere le (re-)faire ici ourb etre sur qu'elle ne soit pas ecrasee.
     */
    ident->id = strdup(id);
  }
  return(ident);
}

/* format d'appel */
void help() {
  fprintf(stderr, "Appel: tp [-h] [-v] programme.txt\n");
}

/* Appel:
 *   tp [-option]* programme.txt
 * Les options doivent apparaitre avant le nom du fichier du programme.
 * Options: -[vV] -[hH?]
 */
 
/* Variables pour optimiser l'affichage*/
int prefixIndex = 0;
int newLine = TRUE;
void prefix() {
    int i = 0;
    if (newLine == TRUE) {
        printf("\n"); 
        for(i = 0; i < prefixIndex; i++ ){
            printf("    ");    
        }
    }
    newLine = FALSE;
} 
int main(int argc, char **argv) {
  idents = NEW(1000, IdentS); /* liste des identificateurs */
  int fi;
  int token;
  int i;

  for(i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      switch (argv[i][1]) {
      case 'v': case 'V':
	verbose = TRUE; continue;
      case '?': case 'h': case 'H':
	help();
	exit(1);
      default:
	fprintf(stderr, "Option inconnue: %c\n", argv[i][1]);
	exit(1);
      }
    } else break;
  }

  if (i == argc) {
    fprintf(stderr, "Erreur: Fichier programme manquant\n");
    help();
    exit(1);
  }

  if ((fi = open(argv[i++], O_RDONLY)) == -1) {
    fprintf(stderr, "Erreur: fichier inaccessible %s\n", argv[i-1]);
    help();
    exit(1);
  }

  /* redirige l'entree standard sur le fichier... */
  /* close(0); dup(fi); close(fi); */
  fprintf(stdin, "class");
  while (1) {
    token = yylex(); 
    switch (token) {
    case 0:
      prefix(); printf("\nFin de l'analyse lexicale\n");
      prefix(); printf("Liste des identificateurs avec leur premiere occurrence:\n");
      for (i = 0; i < nbIdent; i++) {
        prefix(); printf("ligne %d : %s\n", idents[i].line, idents[i].id);
      }
      prefix(); printf("Nombre d'identificateurs: %4d\n", nbIdent);
      return 0;
    case EXTENDS    : if (verbose) {  prefix(); printf("EXTENDS  "); break; }
    case CLASS      : if (verbose) {  prefix(); printf("CLASS  ");   break; }
    case VAR        : if (verbose) {  prefix(); printf("VAR  ");     break; }
    case ASSIGN     : if (verbose) {  prefix(); printf("ASSIGN  ");  break; }
    case IS         : if (verbose) {  prefix(); printf("IS  ");      break; }
    case DEF        : if (verbose) {  prefix(); printf("DEF  ");     break; }
    case STATIC     : if (verbose) {  prefix(); printf("STATIC  ");  break; }
    case RETURNS    : if (verbose) {  prefix(); printf("RETURNS  "); break; }
    case NEW        : if (verbose) {  prefix(); printf("NEW  ");     break; }
    case CONST_INT  : if (verbose) {  prefix(); printf("CONST_INT %d  ", yylval.I ); break;  }
    case CONST_STR  : if (verbose) {  prefix(); printf("CONST_STR %s ", yylval.S );  break; }
    case CLASS_TYPE : if (verbose) {  prefix(); printf("CLASS_TYPE \"%s\" ", yylval.S );  break; }
        
    case ID:
      if (verbose) {  prefix(); printf("ID \"%s\"  ", yylval.S);  }
      break;
    case IF:if (verbose) {  prefix(); printf("if ");  }
      break;
    case THEN:if (verbose) {  prefix(); printf("then ");  }
      break;
    case ELSE: if (verbose) {  prefix(); printf("else ");  }
      break;
    case '(':
    case ')':
    case ':':
    case '.':
    case ',': if (verbose) { prefix(); printf("Sym \"%s\"  ",  yytext); break;  }
    case ';': if (verbose) { prefix(); printf("Sym \"%s\"  ",  yytext); newLine = TRUE; } break;
    case '{': if (verbose) { prefix(); printf("Sym \"%s\"  ",  yytext); newLine = TRUE; prefixIndex++; } break;
    case '}': if (verbose) { prefixIndex--; prefix(); printf("Symbole \"%s\"  ",  yytext); newLine = TRUE; } break; 
    case ADD:   if (verbose) {  prefix(); printf("ADD\t"); break; }
    case SUB:   if (verbose) {  prefix(); printf("SUB\t"); break; }
    case MUL:   if (verbose) {  prefix(); printf("MUL\t"); break; }
    case DIV:   if (verbose) {  prefix(); printf("DIV\t"); break; }
    case RELOP: if (verbose) { 
	    switch(yylval.C) {
	        case EQ:  prefix(); printf("EQ\t");  break;
	        case NEQ: prefix(); printf("NEQ\t"); break;
            case LTE: prefix(); printf("LTE\t"); break;
            case LT:  prefix(); printf("LT\t");  break;
            case GTE: prefix(); printf("GTE\t"); break;
            case GT:  prefix(); printf("GT\t");  break;
	        default: prefix(); printf("Unexpected code: %d\n", yylval.C);
	    }
      }
      break;
    default:
      prefix(); printf("\nToken non reconnu:\t\"%d\"\n", token); return 0 ;
    }
  }
}
