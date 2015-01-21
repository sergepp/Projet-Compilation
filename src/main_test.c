/*
 * Programme qui permet d'effectuer tous es tests possibles et trouvable dans le dossier ../test
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int PrintPaddingNb =  4 ;
char PrintPaddingChar = ' ';
#include "type.h"
#include "tp.h"
#include "tp_y.h"


#include <dirent.h>
#include <stdarg.h>
#include <assert.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define TAILLE_LIGNE 1024
#define TAILLE_PRG 4096
 
extern char *strdup(const char *);
 
/* String Utilities */
char *ltrim(char *s)
{
    while(isspace(*s)) s++;
    return s;
}

char *rtrim(char *s)
{
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}

char *trim(char *s)
{
    return rtrim(ltrim(s)); 
}
 
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


/* Variables pour optimiser l'affichage*/
int prefixIndex = 0;
int verbose = FALSE  ;
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

/* Variables pour l'analyseur lexical */
char* ErrorResult = "    "; 
int fi;
int analyseurLexical() ;
int analyseurSyntaxique();
extern int yychar;

/* Fonctions auxiliaires de tests */
bool hasValidFormat(char* resultatAttendu);
bool isExpectedResult(int resultatAnalyse, char* resultatAttendu);

#define LEXICAL 0
#define SYNTAXIQUE 1

/* Effectue le type d'analyse spécifié en parametre aux fichiers du Repertoire
 * dirname lui aussi passé en paramètre.
 * Exemple d'utilisation :  makeAnalyse(SYNTAXIQUE, "../token/") 
 * Les valeurs possibles pour le premier paramètres sont : LEXICAL,SYNTAXIQUE
 */
void faireAnalyse(int typeAnalyse, const char *dirname)
{
    DIR* rep = NULL;
    rep = opendir(dirname); /* Ouverture d'un dossier */
    struct dirent* fichierLu;
    FILE* fichier = NULL;
    FILE* fichierTemp = NULL;
    char  errorMsg[60];
    char* tmpStr;
    char  currentFileName[1024], tmpFileName[1024], resultatAttendu[TAILLE_LIGNE], ligne[TAILLE_LIGNE];
    char  programme[TAILLE_LIGNE];
    int   noLigneDebutPrg, noLigneActuel, resultatAnalyse;
    if (rep == NULL) /* Si le dossier n'a pas pu être ouvert */
        exit(1);
    
    switch(typeAnalyse) {
        case LEXICAL    : printf("\nANALYSE LEXICALE"); break ; 
        case SYNTAXIQUE : printf("\nANALYSE SYNTAXIQUE"); break ; 
    }   
    while ((fichierLu = readdir(rep)) != NULL) {
        strcpy(currentFileName,dirname);
        if ( strcmp(fichierLu->d_name, ".") == 0  
        ||  strcmp(fichierLu->d_name, "..") == 0
        ||  fichierLu->d_name[strlen(fichierLu->d_name)-1] == '~'  ) continue;
        else {
            strcat(currentFileName, fichierLu->d_name);
            fichier = fopen(currentFileName, "r+");
            /* Charger tout le Programme */ 
            if (fichier != NULL)
            {
                printf("\n\tDans le fichier : '%s' \n", currentFileName);
                /* Boucle de lecture des lignes une à une */
                noLigneActuel = 0;
                
                strcpy(resultatAttendu, "# Success");
                while ( fgets(ligne, TAILLE_LIGNE, fichier) != NULL )
                {   
                    noLigneActuel++;
                    programme[0] = '\0';
                    if (verbose == TRUE) printf("\t+---------------------------------------------------------------------------------------------+\n");
                    if ( ligne[0] == '#' ) {
                        tmpStr = trim(ligne); 
                        if ( strlen(tmpStr) == 1 ) 
                            strcpy(resultatAttendu, "# Success");
                        else
                            strcpy(resultatAttendu, tmpStr );
                        
                    } else {
                        noLigneDebutPrg = noLigneActuel;
                        strcat(programme,ligne);
                        if (verbose == TRUE) printf("\t%s\n", programme);
                        while ( fgets(ligne, TAILLE_LIGNE, fichier) != NULL && ligne[0] != '#') {
                            strcat(programme,ligne);
                            noLigneActuel++;
                        } 
                         
                        /* Appeler L'analyseur Lexical si le programme fait plus d'une ligne de code*/ 
                        if ( strlen(programme) > 0 ) {
                        
                            /* Ecrire le programme dans un fichier */  
                            
                            sprintf(tmpFileName, "%s../tmp/__line_%d.txt",dirname,  noLigneDebutPrg);
                            fichierTemp = fopen(tmpFileName, "w");
                            fputs(trim(programme), fichierTemp);
                            fclose(fichierTemp);
                            switch(typeAnalyse) {
                                case LEXICAL    : resultatAnalyse = analyseurLexical(tmpFileName); break ; 
                                case SYNTAXIQUE : resultatAnalyse = analyseurSyntaxique(tmpFileName, noLigneDebutPrg, noLigneActuel ); break ; 
                            }   
                            if ( isExpectedResult(resultatAnalyse,resultatAttendu) == TRUE )  {
                                printf(ANSI_COLOR_GREEN);
                                printf("\tTest du Program commencant a la ligne %d  \t \t[ Sucessful ]", noLigneDebutPrg);
                                printf(ANSI_COLOR_RESET "\n");
                            }
                            else {
                                printf(ANSI_COLOR_RED);
                                if ( resultatAnalyse == SUCCESS ) 
                                    sprintf(errorMsg, "Le program aurait du ECHOUER"); 
                                else 
                                    sprintf(errorMsg, "Le program aurait du REUSSIR"); 
                                    
                                printf("\tTest du Program commencant a la ligne %d  \t \t[ Error ] %s", noLigneDebutPrg, errorMsg);
                                printf(ANSI_COLOR_RESET "\n");
                            }
                        }

                        tmpStr = trim(ligne);
                        if (strlen(tmpStr) > 2 ) strcpy(resultatAttendu, tmpStr);
                        else strcpy(resultatAttendu, "# Sucess");
                         
                        noLigneActuel++;
                    } 
                }
            }
            else
            {
                printf("Impossible d'ouvrir le fichier %s \n", currentFileName);
            }  
            
            fclose(fichier);
       }
    }
    if (closedir(rep) == -1) /* S'il y a eu un souci avec la fermeture */
        exit(-1);
}


int main(int argc, char **argv) {

    int d = 2;
    if ( argc > 1 ) verbose = TRUE ;
    /* Test analyseur lexical */
    faireAnalyse(LEXICAL, "../test/lexicale/"); 
     if ( argc == 3 )  return 0;
    /* Test analyseur syntaxique   */
    faireAnalyse(SYNTAXIQUE, "../test/syntaxique/"); 
    printf("\n");
    return 0;
}

#include "type.c" 


bool isExpectedResult(int resultatAnalyse, char*  resultatAttendu) {
    
    /* Le format du resultat attendu doit être valide dans cette fonction */
    if  ( verbose == TRUE) 
    printf("\tResultat attendu : %s \n",resultatAttendu);
    assert( hasValidFormat(resultatAttendu) == TRUE);
    if ( strlen(resultatAttendu) == 1  
        || (     resultatAttendu[1] == 'S' /* On suppose qu'il y a un espace entre # Success ou # Error */ 
              || resultatAttendu[2] == 'S'  
              || resultatAttendu[3] == 'S')  
    ){ /* # ou #Success */
        
        return(resultatAnalyse == SUCCESS);
    } 
    else { /* #Error */
        return(resultatAnalyse == ERROR) ;
    }
}

bool hasValidFormat(char* resultatAttendu) {
    if ( strlen(resultatAttendu) == 1  ) {  /* #Success */
        return(resultatAttendu[0] == '#');
    } 
    else  {  /* #Error */
        return( resultatAttendu[0] == '#' && (
                 (resultatAttendu[1] == 'E' || resultatAttendu[1] == 'S') /* On suppose qu'il y a un espace entre # Success ou # Error */ 
              || (resultatAttendu[2] == 'E' || resultatAttendu[2] == 'S')  
              || (resultatAttendu[3] == 'E' || resultatAttendu[3] == 'S') 
              ));
    }
}
/*
#include "analyseur_lexical.c"

*/


/* code d'erreur a retourner */
int errorCode = NO_ERROR;

/*
 * Toute cette premiere partie n'a (normalement) pas besoin d'etre modifiee
 */

extern int yyparse();
extern int yylineno;
extern FILE * yyin;
extern int yydebug;

int eval(TreeP tree, VarDeclP decls);
TreeP getChild(TreeP tree, int rank);
 

/* Evaluation ou pas. Par defaut, on evalue les expressions */
bool noEval = FALSE;


FILE *fd = NIL(FILE);

int analyseurSyntaxique(char* tmpFileName, int noLigneDebutPrg, int noLigneFinPrg ) {
   
  int res;
  /* Initialisation du curseur du début*/
  yylineno = noLigneDebutPrg;
  
  if ((fi = open(tmpFileName, O_RDONLY)) == -1) {
    fprintf(stderr, "Error: Cannot open %s\n", tmpFileName);
    exit(USAGE_ERROR);
  }

  /* redirige l'entree standard sur le fichier... */
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
  fprintf(stderr,"\t");
  if( verbose == TRUE ) {
    yydebug = 0;
  }
  res = yyparse();
  yyrestart(yyin);
  
  if (fd != NIL(FILE)) fclose(fd);
  if (res == 0 && errorCode == NO_ERROR) { 
    fprintf(stderr,"\b");
    return SUCCESS;
  } 
  return ERROR;
  
}

int analyseurLexical(char* tmpFileName) {
  int token, lineCpt = 0;
  
   /* Ouvrir le fichier qui vient d'etre créée */ 
   if ((fi = open(tmpFileName, O_RDONLY)) == -1) {
        fprintf(stderr, "Erreur: fichier inaccessible %s\n", tmpFileName);
        exit(1);  
   }
    
   /* redirige l'entree standard sur le fichier... */
   close(0); dup(fi); close(fi); 
 
    
  /* printf("Debut de l'analyse Lexical\n") ; */
  if (verbose == TRUE ) printf("\t");
  while (1) {
    
    token = yylex();
    
    if (verbose == TRUE ){ lineCpt++ ;  if ( lineCpt % 6 == 0 ) printf("\n\t"); }
    switch (token) {
        case 0:  if (verbose == TRUE ) printf("\n\n"); return 0;
        case EXTENDS    : if ( verbose == TRUE) { printf( "EXTENDS " ); } break; 
        case OVERRIDE   : if ( verbose == TRUE) { printf( "OVERRIDE " ); } break; 
        case CLASS      : if ( verbose == TRUE) { printf( "CLASS "   ); } break; 
        case VAR        : if ( verbose == TRUE) { printf( "VAR "     ); } break;     
        case ASSIGN     : if ( verbose == TRUE) { printf( "ASSIGN "  ); } break;
        case IS         : if ( verbose == TRUE) { printf( "IS "      ); } break;      
        case CONCAT     : if ( verbose == TRUE) { printf( "CONCAT "  ); } break;              
        case YIELD      : if ( verbose == TRUE) { printf( "YIELD "  ); } break;                      
        case DEF        : if ( verbose == TRUE) { printf( "DEF "     ); } break;       
        case STATIC     : if ( verbose == TRUE) { printf( "STATIC "  ); } break;  
        case RETURN     : if ( verbose == TRUE) { printf( "RETURN "  ); } break;          
        case RETURNS    : if ( verbose == TRUE) { printf( "RETURNS " ); } break;  
        case NEW        : if ( verbose == TRUE) { printf( "NEW  "    ); } break; 
        case CONST_INT  : if ( verbose == TRUE) { printf( "CONST_INT %d " , yylval.I ); } break;  
        case CONST_STR  : if ( verbose == TRUE) { printf( "CONST_STR %s " , yylval.S ); } break;    
        case CONST_VOID : if ( verbose == TRUE) { printf( "CONST_STR %s " , yylval.S ); } break;    
        case CLASS_TYPE : if ( verbose == TRUE) { printf( "CLASS_TYPE %s ", yylval.S ); } break;
        case ID         : if ( verbose == TRUE) { printf( "ID %s "        , yylval.S ); } break;
        case IF         : if ( verbose == TRUE) { printf( "IF "  );  }    break;    
        case THEN       : if ( verbose == TRUE) { printf( "THEN ");  }    break;
        case ELSE       : if ( verbose == TRUE) { printf( "ELSE ");  }    break;
        case '(':
        case '{':
        case '}':        
        case ')':
        case ':':
        case '.':
        case ',':        
        case ';':        if ( verbose == TRUE) { printf( "Symbol %s ", yytext); } break;
        case ADD:        if ( verbose == TRUE) { printf( "ADD "); } break;
        case SUB:        if ( verbose == TRUE) { printf( "SUB "); } break;
        case MUL:        if ( verbose == TRUE) { printf( "MUL "); } break;
        case DIV:        if ( verbose == TRUE) { printf( "DIV "); } break;
        case RELOP:  
	        switch(yylval.C) {
	            case EQ:  if ( verbose == TRUE) { printf( "EQ " ); } break;
	            case NEQ: if ( verbose == TRUE) { printf( "NEQ "); } break;
                case LTE: if ( verbose == TRUE) { printf( "LTE "); } break;
                case LT:  if ( verbose == TRUE) { printf( "LT " ); } break;
                case GTE: if ( verbose == TRUE) { printf( "GTE "); } break;
                case GT:  if ( verbose == TRUE) { printf( "GT " ); } break;
	            default:  printf("\tOperateur Relationnel Non Reconnu : %d\n",token);
	                      return ERROR;
	        }
          break;
        case ERROR: printf("\n\tToken Non Reconnu : %s\n", yytext);
                    return ERROR;
        default:
          printf("\n\tToken Non Reconnu : %d : %s\n", token, yytext); 
          return ERROR;
        }
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
  fprintf(stderr, "Erreur de syntaxe à la ligne : %d  au niveau de  : %s  \n", yylineno, yytext);
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

