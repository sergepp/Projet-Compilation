char* analyseurLexical() {
  int token;
  char* result; 
  
  /* redirige l'entree standard sur le fichier... */
  close(0); dup(fi); close(fi);
  printf("Debut de l'analyse Lexical\n") ;
  while (1) {
    result = strdup(" ");
    token = yylex(); 
    switch (token) {
    case 0: return result;
    case EXTENDS    : strcat(result, "EXTENDS " );  break; 
    case CLASS      : strcat(result, "CLASS "   );  break;
    case VAR        : strcat(result, "VAR "     );  break;     
    case ASSIGN     : strcat(result, "ASSIGN "  );  break;  
    case IS         : strcat(result, "IS "      );  break;      
    case YIELD      : strcat(result, "YIELD "   );  break;          
    case CONCAT     : strcat(result, "CONCAT "  );  break;          
    case DEF        : strcat(result, "DEF "     );  break;       
    case STATIC     : strcat(result, "STATIC "  );  break;  
    case RETURNS    : strcat(result, "RETURNS " );  break;  
    case NEW        : strcat(result, "NEW  "    );  break;  
    case CONST_INT  : sprintf(result, "%sCONST_INT %d " , result, yylval.I );  break;  
    case CONST_STR  : sprintf(result, "%sCONST_STR %s " , result, yylval.S );  break;    
    case CLASS_TYPE : sprintf(result, "%sCLASS_TYPE %s ", result, yylval.S );  break;
    case ID         : sprintf(result, "%sID %s "        , result, yylval.S );  break;
    case IF         : strcat (result, "if "  );      break;
    case THEN       : strcat (result, "then ");      break;
    case ELSE       : strcat (result, "else ");      break; /*
    case '(':
    case ')':
    case ':':
    case '.':
    case ',':        
    case ';':        
    case '}':        strcat(result, "Symbol \"%s\"  ",  yytext); break; */
    case ADD:        strcat(result, "ADD "); 
    case SUB:        strcat(result, "SUB "); 
    case MUL:        strcat(result, "MUL "); 
    case DIV:        strcat(result, "DIV "); 
    case RELOP:  
	    switch(yylval.C) {
	        case EQ:  strcat(result, "EQ " );  break;
	        case NEQ: strcat(result, "NEQ ");  break;
            case LTE: strcat(result, "LTE ");  break;
            case LT:  strcat(result, "LT " );  break;
            case GTE: strcat(result, "GTE ");  break;
            case GT:  strcat(result, "GT " );  break;
	        default:  return ErrorResult;
	    }
      break;
    default:
      return ErrorResult;
    }
  }
}
