
extern char *strdup(const char *);
 

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

     
int analyseurLexical(char* tmpFileName) {
  int token;
  
   /* Ouvrir le fichier qui vient d'etre créée */ 
   if ((fi = open(tmpFileName, O_RDONLY)) == -1) {
        fprintf(stderr, "Erreur: fichier inaccessible %s\n", tmpFileName);
        exit(1);  
   }

   /* redirige l'entree standard sur le fichier... */
   close(0); dup(fi); close(fi); 
 
    
  /* printf("Debut de l'analyse Lexical\n") ; */
  while (1) {
    yylex(); 
    token = yylex(); 
    switch (token) {
        case 0:   return 0;
        case EXTENDS    : if ( verbose == TRUE) { printf( "EXTENDS " ); } break; 
        case CLASS      : if ( verbose == TRUE) { printf( "CLASS "   ); } break;
        case VAR        : if ( verbose == TRUE) { printf( "VAR "     ); } break;     
        case ASSIGN     : if ( verbose == TRUE) { printf( "ASSIGN "  ); } break;
        case IS         : if ( verbose == TRUE) { printf( "IS "      ); } break;      
        case DEF        : if ( verbose == TRUE) { printf( "DEF "     ); } break;       
        case STATIC     : if ( verbose == TRUE) { printf( "STATIC "  ); } break;  
        case RETURNS    : if ( verbose == TRUE) { printf( "RETURNS " ); } break;  
        case NEW        : if ( verbose == TRUE) { printf( "NEW  "    ); } break; 
        case CONST_INT  : if ( verbose == TRUE) { printf( "CONST_INT %d " , yylval.I ); } break;  
        case CONST_STR  : if ( verbose == TRUE) { printf( "CONST_STR %s " , yylval.S ); } break;    
        case CLASS_TYPE : if ( verbose == TRUE) { printf( "CLASS_TYPE %s ", yylval.S ); } break;
        case ID         : if ( verbose == TRUE) { printf( "ID %s "        , yylval.S ); } break;
        case IF         : if ( verbose == TRUE) { printf( "if "  );  }    break;/*
        case THEN       : if ( verbose == TRUE) { printf( "then ");  }    break;
        case ELSE       : if ( verbose == TRUE) { printf( "else ");  }    break;*/
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
	                      return ERR;
	        }
          break;
        case ERR:
        default:
          printf("\tToken Non Reconnu : %d \n", token); 
          return ERR;
        }
    }
}
