/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 50 "tp.y" /* yacc.c:339  */

#define YYDEBUG 1


#include "type.h"
#include "tp.h"
#include "tp_y.h"

#include "class.h"
#include "expr.h"
#include "instr.h"
#include "scope.h"
#include "var.h"


extern Class Integer;

extern Class String;

extern Class Void;

extern Scope currentScope;

extern Class AllDefinedClasses; 

extern int yylex();	/* fournie par Flex */

extern void yyerror();  /* definie dans tp.c */

#line 96 "tp_y.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "tp_y.h".  */
#ifndef YY_YY_TP_Y_H_INCLUDED
# define YY_YY_TP_Y_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IS = 258,
    CLASS = 259,
    EXTENDS = 260,
    RETURN = 261,
    RETURNS = 262,
    DEF = 263,
    STATIC = 264,
    OVERRIDE = 265,
    VAR = 266,
    YIELD = 267,
    CONCAT = 268,
    NEW = 269,
    IF = 270,
    THEN = 271,
    ELSE = 272,
    ADD = 273,
    SUB = 274,
    MUL = 275,
    DIV = 276,
    CONST_VOID = 277,
    ID = 278,
    CONST_STR = 279,
    CLASS_TYPE = 280,
    CONST_INT = 281,
    RELOP = 282,
    ASSIGN = 283,
    UNARY = 284
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TP_Y_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 172 "tp_y.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   494

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  197

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      31,    32,     2,     2,    35,     2,    30,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,    37,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    99,    99,   100,   102,   103,   105,   112,   113,   114,
     115,   119,   120,   122,   123,   125,   128,   129,   131,   133,
     134,   136,   142,   143,   145,   146,   147,   149,   150,   152,
     153,   154,   155,   156,   157,   160,   161,   163,   164,   166,
     169,   170,   174,   175,   177,   178,   179,   182,   183,   184,
     187,   188,   191,   192,   193,   194,   195,   196,   198,   200,
     201,   203,   204,   207,   208,   209,   210,   211,   212,   213,
     214,   216,   217,   218,   219,   221,   223,   224,   225,   228,
     232,   233,   234,   235,   236,   237,   240,   243,   244,   246,
     247
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IS", "CLASS", "EXTENDS", "RETURN",
  "RETURNS", "DEF", "STATIC", "OVERRIDE", "VAR", "YIELD", "CONCAT", "NEW",
  "IF", "THEN", "ELSE", "ADD", "SUB", "MUL", "DIV", "CONST_VOID", "ID",
  "CONST_STR", "CLASS_TYPE", "CONST_INT", "RELOP", "ASSIGN", "UNARY",
  "'.'", "'('", "')'", "'{'", "'}'", "','", "':'", "';'", "$accept",
  "program", "L_classDecl", "classDeclHeader", "classDecl",
  "Opt_L_classParamDecl", "L_classParamDecl", "classParamDecl",
  "Opt_extendsDecl", "extendsDecl", "Opt_constructorBody",
  "constructorBody", "L_fieldDecl", "fieldDecl", "L_methodDecl",
  "methodDecl", "Opt_L_methodParamDecl", "L_methodParamDecl",
  "methodParamDecl", "methodBody", "instructionBloc", "proceduralBloc",
  "functionalBloc", "L_instr", "instr", "ifThenElseInstr", "Opt_L_expr",
  "L_expr", "expr", "selection", "concatExpr", "constant", "instanciation",
  "arithmExpr", "booleanExpr", "L_varDecl", "varDecl", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      46,    40,    41,   123,   125,    44,    58,    59
};
# endif

#define YYPACT_NINF -127

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-127)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,    -5,   106,    30,     1,    47,  -127,  -127,    60,   424,
      64,    54,   424,   424,   424,  -127,  -127,  -127,    78,  -127,
     424,    13,  -127,  -127,  -127,   200,  -127,  -127,   321,  -127,
    -127,  -127,  -127,  -127,  -127,    11,  -127,  -127,  -127,  -127,
      89,    85,  -127,    99,    76,    97,   103,   438,    58,    58,
     113,   409,   424,   129,    42,  -127,  -127,   424,   424,   424,
     424,   424,   424,   424,   115,  -127,   305,  -127,   111,   221,
     142,  -127,  -127,   110,   117,   121,  -127,  -127,   125,   424,
     305,   126,  -127,   146,   424,   305,   128,    48,    48,    58,
      58,   451,   334,   130,   242,   424,  -127,   263,   135,   144,
    -127,    99,    37,   138,   136,   464,   284,   424,  -127,   373,
     179,  -127,   424,  -127,   140,  -127,     7,  -127,  -127,   424,
    -127,  -127,   424,   305,   143,  -127,   424,   145,  -127,     3,
      41,  -127,    32,  -127,    -1,  -127,  -127,   347,   464,  -127,
    -127,   391,  -127,   155,   156,   157,   163,  -127,  -127,     8,
    -127,  -127,  -127,  -127,   159,   161,   172,   160,  -127,   172,
     172,   164,   167,   173,  -127,   182,   177,   184,   186,   210,
     172,    56,   213,   214,  -127,   203,  -127,   424,  -127,   204,
     205,    44,   360,    57,    74,   424,  -127,  -127,  -127,  -127,
     424,  -127,   424,  -127,   464,   464,   464
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    16,     4,     2,     0,     0,
       0,     0,     0,     0,     0,    78,    63,    76,     0,    77,
       0,     0,    44,    54,    55,     0,    50,    57,     0,    69,
      67,    66,    65,    64,    68,     0,    87,     1,     5,     3,
       0,    19,    17,    11,     0,     0,     0,     0,    85,    84,
       0,     0,     0,     0,     0,    45,    51,     0,     0,     0,
       0,     0,     0,     0,     0,    52,     0,    88,     0,     0,
       0,    20,    21,     0,     0,    12,    13,    53,     0,    59,
       0,    72,    70,     0,     0,     0,    75,    80,    81,    82,
      83,    86,     0,    71,     0,    59,    42,     0,     0,     0,
       6,     0,     0,     0,    60,    61,     0,    59,    47,     0,
       0,    56,    59,    46,     0,    43,     0,    15,    14,     0,
      90,    79,     0,     0,     0,    48,     0,     0,    18,     0,
       0,     7,     0,    22,     0,    27,    24,     0,    62,    58,
      73,     0,    74,     0,     0,     0,     0,     8,    23,     0,
       9,    28,    89,    49,     0,     0,    35,     0,    10,    35,
      35,     0,     0,    36,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,     0,    38,     0,    26,     0,
       0,     0,     0,     0,     0,     0,    33,    40,    41,    25,
       0,    31,     0,    29,    34,    32,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,  -127,   228,  -127,  -127,   137,  -127,  -127,
    -127,  -127,  -127,   105,   109,  -126,   -49,  -127,    72,   -57,
    -127,     0,   -83,   -18,   -24,  -127,   -32,  -127,    -3,  -127,
    -127,  -127,  -127,  -127,  -127,   229,   -33
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    74,    75,    76,    41,    42,
      70,    71,   132,   133,   134,   135,   162,   163,   164,   186,
      72,    23,    24,    25,    26,    27,   103,   104,    28,    29,
      30,    31,    32,    33,    34,    35,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       7,    56,    67,    53,    39,     1,    44,   129,   151,    47,
      48,    49,   143,   144,    66,   129,   129,    51,   130,     9,
       8,    67,    10,   151,    10,    52,   145,    11,    12,    56,
      37,    13,    14,   150,     2,    15,    16,    17,    18,    19,
     129,   131,   158,   130,    20,    85,    21,    22,    94,    83,
     146,    97,    40,    10,    86,    87,    88,    89,    90,    91,
      92,    57,   106,   114,    45,   119,   147,   110,    60,    61,
      56,    57,   185,    56,   120,   124,   105,    21,    64,    46,
     127,   109,    56,   136,   177,   190,    56,    45,    64,    57,
      21,    43,   105,   178,    58,    59,    60,    61,   188,   136,
     188,   188,   192,    62,   105,   139,    64,    21,    50,   105,
     166,   167,     9,    77,    68,    56,   137,    10,    69,   138,
      11,    12,    73,   141,    13,    14,   191,   193,    15,    16,
      17,    18,    19,    78,    79,     9,    81,    20,    93,    21,
      22,    84,    95,    11,    12,    98,    99,    13,    14,   100,
     102,    15,    16,    17,    18,    19,   101,   107,    64,    57,
      20,   112,    21,    55,    58,    59,    60,    61,   116,   117,
     121,   122,   128,    62,   182,   140,    64,   142,   154,   155,
     108,   187,   194,   187,   187,     9,   157,   195,   156,   196,
     159,   126,   160,    11,    12,   161,   165,    13,    14,   169,
     168,    15,    16,    17,    18,    19,     9,   171,   170,   172,
      20,   174,    21,   113,    11,    12,   173,   175,    13,    14,
     179,   180,    15,    16,    17,    18,    19,     9,   181,   183,
     184,    20,    38,    21,    55,    11,    12,   148,   118,    13,
      14,   149,   176,    15,    16,    17,    18,    19,     9,     0,
      54,     0,    20,     0,    21,    96,    11,    12,     0,     0,
      13,    14,     0,     0,    15,    16,    17,    18,    19,     9,
       0,     0,     0,    20,     0,    21,   113,    11,    12,     0,
       0,    13,    14,     0,     0,    15,    16,    17,    18,    19,
       9,     0,     0,     0,    20,     0,    21,   115,    11,    12,
       0,   123,    13,    14,     0,     0,    15,    16,    17,    18,
      19,     9,     0,     0,     0,    20,     0,    21,     0,    11,
      12,     0,     0,    13,    14,     0,     0,    15,    16,    17,
      18,    19,     0,     0,    57,     0,    20,     0,    21,    58,
      59,    60,    61,     0,     0,     0,     0,    57,    62,    63,
       0,    64,    58,    59,    60,    61,     0,     0,    65,     0,
      57,    62,     0,     0,    64,    58,    59,    60,    61,     0,
       0,   111,     0,    57,    62,     0,     0,    64,    58,    59,
      60,    61,     0,     0,   152,     0,    57,    62,     0,     0,
      64,    58,    59,    60,    61,     0,     0,   189,     0,     0,
      62,     0,     0,    64,    57,     0,     0,   125,     0,    58,
      59,    60,    61,     0,     0,     0,     0,     0,    62,     0,
       0,    64,    57,     0,     0,   153,     0,    58,    59,    60,
      61,     0,     0,     0,     0,     0,    62,     0,    11,    64,
       0,    82,    13,    14,     0,     0,    15,    16,    17,    18,
      19,    57,     0,     0,    80,    20,    58,    59,    60,    61,
       0,     0,     0,     0,    57,    62,     0,     0,    64,    58,
      59,    60,    61,     0,     0,     0,     0,    57,    -1,     0,
       0,    64,    58,    59,    60,    61,     0,     0,     0,     0,
       0,    62,     0,     0,    64
};

static const yytype_int16 yycheck[] =
{
       0,    25,    35,    21,     4,     4,     9,     8,   134,    12,
      13,    14,     9,    10,     3,     8,     8,    20,    11,     6,
      25,    54,    11,   149,    11,    12,    23,    14,    15,    53,
       0,    18,    19,    34,    33,    22,    23,    24,    25,    26,
       8,    34,    34,    11,    31,     3,    33,    34,    66,    52,
       9,    69,     5,    11,    57,    58,    59,    60,    61,    62,
      63,    13,    80,    95,    23,    28,    34,    85,    20,    21,
      94,    13,    28,    97,    37,   107,    79,    33,    30,    25,
     112,    84,   106,   116,    28,    28,   110,    23,    30,    13,
      33,    31,    95,    37,    18,    19,    20,    21,   181,   132,
     183,   184,    28,    27,   107,   123,    30,    33,    30,   112,
     159,   160,     6,    37,    25,   139,   119,    11,    33,   122,
      14,    15,    23,   126,    18,    19,   183,   184,    22,    23,
      24,    25,    26,    36,    31,     6,    23,    31,    23,    33,
      34,    12,    31,    14,    15,     3,    36,    18,    19,    32,
      25,    22,    23,    24,    25,    26,    35,    31,    30,    13,
      31,    31,    33,    34,    18,    19,    20,    21,    33,    25,
      32,    35,    32,    27,   177,    32,    30,    32,    23,    23,
      34,   181,   185,   183,   184,     6,    23,   190,    31,   192,
      31,    12,    31,    14,    15,    23,    36,    18,    19,    32,
      36,    22,    23,    24,    25,    26,     6,    25,    35,    32,
      31,    25,    33,    34,    14,    15,    32,     7,    18,    19,
       7,     7,    22,    23,    24,    25,    26,     6,    25,    25,
      25,    31,     4,    33,    34,    14,    15,   132,   101,    18,
      19,   132,   170,    22,    23,    24,    25,    26,     6,    -1,
      21,    -1,    31,    -1,    33,    34,    14,    15,    -1,    -1,
      18,    19,    -1,    -1,    22,    23,    24,    25,    26,     6,
      -1,    -1,    -1,    31,    -1,    33,    34,    14,    15,    -1,
      -1,    18,    19,    -1,    -1,    22,    23,    24,    25,    26,
       6,    -1,    -1,    -1,    31,    -1,    33,    34,    14,    15,
      -1,    17,    18,    19,    -1,    -1,    22,    23,    24,    25,
      26,     6,    -1,    -1,    -1,    31,    -1,    33,    -1,    14,
      15,    -1,    -1,    18,    19,    -1,    -1,    22,    23,    24,
      25,    26,    -1,    -1,    13,    -1,    31,    -1,    33,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    13,    27,    28,
      -1,    30,    18,    19,    20,    21,    -1,    -1,    37,    -1,
      13,    27,    -1,    -1,    30,    18,    19,    20,    21,    -1,
      -1,    37,    -1,    13,    27,    -1,    -1,    30,    18,    19,
      20,    21,    -1,    -1,    37,    -1,    13,    27,    -1,    -1,
      30,    18,    19,    20,    21,    -1,    -1,    37,    -1,    -1,
      27,    -1,    -1,    30,    13,    -1,    -1,    34,    -1,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    30,    13,    -1,    -1,    34,    -1,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    27,    -1,    14,    30,
      -1,    32,    18,    19,    -1,    -1,    22,    23,    24,    25,
      26,    13,    -1,    -1,    16,    31,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    13,    27,    -1,    -1,    30,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    13,    27,    -1,
      -1,    30,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    33,    39,    40,    41,    42,    59,    25,     6,
      11,    14,    15,    18,    19,    22,    23,    24,    25,    26,
      31,    33,    34,    59,    60,    61,    62,    63,    66,    67,
      68,    69,    70,    71,    72,    73,    74,     0,    42,    59,
       5,    46,    47,    31,    66,    23,    25,    66,    66,    66,
      30,    66,    12,    61,    73,    34,    62,    13,    18,    19,
      20,    21,    27,    28,    30,    37,     3,    74,    25,    33,
      48,    49,    58,    23,    43,    44,    45,    37,    36,    31,
      16,    23,    32,    66,    12,     3,    66,    66,    66,    66,
      66,    66,    66,    23,    61,    31,    34,    61,     3,    36,
      32,    35,    25,    64,    65,    66,    61,    31,    34,    66,
      61,    37,    31,    34,    64,    34,    33,    25,    45,    28,
      37,    32,    35,    17,    64,    34,    12,    64,    32,     8,
      11,    34,    50,    51,    52,    53,    74,    66,    66,    61,
      32,    66,    32,     9,    10,    23,     9,    34,    51,    52,
      34,    53,    37,    34,    23,    23,    31,    23,    34,    31,
      31,    23,    54,    55,    56,    36,    54,    54,    36,    32,
      35,    25,    32,    32,    25,     7,    56,    28,    37,     7,
       7,    25,    66,    25,    25,    28,    57,    59,    60,    37,
      28,    57,    28,    57,    66,    66,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    39,    40,    40,    41,    42,    42,    42,
      42,    43,    43,    44,    44,    45,    46,    46,    47,    48,
      48,    49,    50,    50,    51,    51,    51,    52,    52,    53,
      53,    53,    53,    53,    53,    54,    54,    55,    55,    56,
      57,    57,    58,    58,    59,    59,    59,    60,    60,    60,
      61,    61,    62,    62,    62,    62,    62,    62,    63,    64,
      64,    65,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    67,    67,    67,    68,    69,    69,    69,    70,
      71,    71,    71,    71,    71,    71,    72,    73,    73,    74,
      74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     5,     6,     7,     7,
       8,     0,     1,     1,     3,     3,     0,     1,     5,     0,
       1,     1,     1,     2,     1,     8,     6,     1,     2,     9,
      10,     9,    10,     8,     9,     0,     1,     1,     3,     3,
       1,     1,     2,     3,     2,     3,     5,     4,     5,     7,
       1,     2,     2,     3,     1,     1,     4,     1,     6,     0,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     6,     6,     3,     1,     1,     1,     5,
       3,     3,     3,     3,     2,     2,     3,     1,     2,     7,
       5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 99 "tp.y" /* yacc.c:1646  */
    { (yyval.Program) = makeProgram(NULL, (yyvsp[0].Instr)); }
#line 1443 "tp_y.c" /* yacc.c:1646  */
    break;

  case 3:
#line 100 "tp.y" /* yacc.c:1646  */
    { (yyval.Program) = makeProgram((yyvsp[-1].Class), (yyvsp[0].Instr));   }
#line 1449 "tp_y.c" /* yacc.c:1646  */
    break;

  case 4:
#line 102 "tp.y" /* yacc.c:1646  */
    { (yyval.Class) = (yyvsp[0].Class);    CurrentClass = NULL; }
#line 1455 "tp_y.c" /* yacc.c:1646  */
    break;

  case 5:
#line 103 "tp.y" /* yacc.c:1646  */
    { (yyval.Class) = ClassDeclSetNext((yyvsp[-1].Class), (yyvsp[0].Class)); }
#line 1461 "tp_y.c" /* yacc.c:1646  */
    break;

  case 6:
#line 105 "tp.y" /* yacc.c:1646  */
    { 
    AssertVarAreNotDupliqued((yyvsp[-1].Var));
    AssertClassIsNotDupliqued((yyvsp[-3].S));
    CurrentClass = ClassDecl((yyvsp[-3].S), (yyvsp[-1].Var));
   
}
#line 1472 "tp_y.c" /* yacc.c:1646  */
    break;

  case 7:
#line 112 "tp.y" /* yacc.c:1646  */
    { (yyval.Class) = ClassDeclComplete((yyvsp[-4].MethodCall), (yyvsp[-3].Instr), NULL, NULL);   ClassDeclAssertIsOk((yyval.Class));   }
#line 1478 "tp_y.c" /* yacc.c:1646  */
    break;

  case 8:
#line 113 "tp.y" /* yacc.c:1646  */
    { (yyval.Class) = ClassDeclComplete((yyvsp[-5].MethodCall), (yyvsp[-4].Instr), (yyvsp[-1].Var), NULL);     ClassDeclAssertIsOk((yyval.Class));   }
#line 1484 "tp_y.c" /* yacc.c:1646  */
    break;

  case 9:
#line 114 "tp.y" /* yacc.c:1646  */
    { (yyval.Class) = ClassDeclComplete((yyvsp[-5].MethodCall), (yyvsp[-4].Instr), NULL, (yyvsp[-1].Method));     ClassDeclAssertIsOk((yyval.Class));   }
#line 1490 "tp_y.c" /* yacc.c:1646  */
    break;

  case 10:
#line 115 "tp.y" /* yacc.c:1646  */
    { (yyval.Class) = ClassDeclComplete((yyvsp[-6].MethodCall), (yyvsp[-5].Instr), (yyvsp[-2].Var), (yyvsp[-1].Method));       ClassDeclAssertIsOk((yyval.Class));   }
#line 1496 "tp_y.c" /* yacc.c:1646  */
    break;

  case 11:
#line 119 "tp.y" /* yacc.c:1646  */
    { (yyval.Var) = NULL; }
#line 1502 "tp_y.c" /* yacc.c:1646  */
    break;

  case 12:
#line 120 "tp.y" /* yacc.c:1646  */
    { (yyval.Var) = (yyvsp[0].Var);   }
#line 1508 "tp_y.c" /* yacc.c:1646  */
    break;

  case 13:
#line 122 "tp.y" /* yacc.c:1646  */
    { (yyval.Var) = (yyvsp[0].Var);  }
#line 1514 "tp_y.c" /* yacc.c:1646  */
    break;

  case 14:
#line 123 "tp.y" /* yacc.c:1646  */
    { (yyval.Var) = ParamDeclSetNext((yyvsp[-2].Var), (yyvsp[0].Var));   }
#line 1520 "tp_y.c" /* yacc.c:1646  */
    break;

  case 15:
#line 125 "tp.y" /* yacc.c:1646  */
    {  AssertClassExists((yyvsp[0].S)); (yyval.Var) = ParamDecl((yyvsp[-2].S), (yyvsp[0].S)); }
#line 1526 "tp_y.c" /* yacc.c:1646  */
    break;

  case 16:
#line 128 "tp.y" /* yacc.c:1646  */
    { (yyval.MethodCall) = NULL; }
#line 1532 "tp_y.c" /* yacc.c:1646  */
    break;

  case 17:
#line 129 "tp.y" /* yacc.c:1646  */
    { (yyval.MethodCall) = (yyvsp[0].MethodCall);   }
#line 1538 "tp_y.c" /* yacc.c:1646  */
    break;

  case 18:
#line 131 "tp.y" /* yacc.c:1646  */
    { ExtendsDeclAssertIsOk((yyvsp[-3].S), (yyvsp[-1].Expr)); (yyval.MethodCall) = ExtendsDecl((yyvsp[-3].S), (yyvsp[-1].Expr), "constructor"); }
#line 1544 "tp_y.c" /* yacc.c:1646  */
    break;

  case 19:
#line 133 "tp.y" /* yacc.c:1646  */
    { (yyval.Instr) = InstrFromInstrBloc(NULL); }
#line 1550 "tp_y.c" /* yacc.c:1646  */
    break;

  case 20:
#line 134 "tp.y" /* yacc.c:1646  */
    { (yyval.Instr) = (yyvsp[0].Instr);  }
#line 1556 "tp_y.c" /* yacc.c:1646  */
    break;

  case 21:
#line 136 "tp.y" /* yacc.c:1646  */
    { (yyval.Instr) = (yyvsp[0].Instr); }
#line 1562 "tp_y.c" /* yacc.c:1646  */
    break;

  case 22:
#line 142 "tp.y" /* yacc.c:1646  */
    { (yyval.Var) = (yyvsp[0].Var);  }
#line 1568 "tp_y.c" /* yacc.c:1646  */
    break;

  case 23:
#line 143 "tp.y" /* yacc.c:1646  */
    { (yyval.Var) = ParamDeclSetNext((yyvsp[-1].Var), (yyvsp[0].Var)); }
#line 1574 "tp_y.c" /* yacc.c:1646  */
    break;

  case 24:
#line 145 "tp.y" /* yacc.c:1646  */
    {  (yyval.Var) = (yyvsp[0].Var); }
#line 1580 "tp_y.c" /* yacc.c:1646  */
    break;

  case 25:
#line 146 "tp.y" /* yacc.c:1646  */
    {  AssertClassExists((yyvsp[-3].S)); (yyval.Var) = StaticVarDecl((yyvsp[-5].S), (yyvsp[-3].S), (yyvsp[-1].Expr));   }
#line 1586 "tp_y.c" /* yacc.c:1646  */
    break;

  case 26:
#line 147 "tp.y" /* yacc.c:1646  */
    {  AssertClassExists((yyvsp[-1].S)); (yyval.Var) = StaticVarDecl((yyvsp[-3].S), (yyvsp[-1].S), NULL); }
#line 1592 "tp_y.c" /* yacc.c:1646  */
    break;

  case 27:
#line 149 "tp.y" /* yacc.c:1646  */
    { (yyval.Method) = (yyvsp[0].Method); }
#line 1598 "tp_y.c" /* yacc.c:1646  */
    break;

  case 28:
#line 150 "tp.y" /* yacc.c:1646  */
    { (yyval.Method) = MethodDeclSetNext((yyvsp[-1].Method), (yyvsp[0].Method)); }
#line 1604 "tp_y.c" /* yacc.c:1646  */
    break;

  case 29:
#line 152 "tp.y" /* yacc.c:1646  */
    { (yyval.Method)=OverrideMethodDecl((yyvsp[-6].S), (yyvsp[-4].Var), (yyvsp[-1].S), (yyvsp[0].Instr), NULL); }
#line 1610 "tp_y.c" /* yacc.c:1646  */
    break;

  case 30:
#line 153 "tp.y" /* yacc.c:1646  */
    { (yyval.Method)=OverrideMethodDecl((yyvsp[-7].S), (yyvsp[-5].Var), (yyvsp[-2].S), NULL, (yyvsp[0].Expr));}
#line 1616 "tp_y.c" /* yacc.c:1646  */
    break;

  case 31:
#line 154 "tp.y" /* yacc.c:1646  */
    { (yyval.Method)=StaticMethodDecl((yyvsp[-6].S), (yyvsp[-4].Var), (yyvsp[-1].S), (yyvsp[0].Instr), NULL);}
#line 1622 "tp_y.c" /* yacc.c:1646  */
    break;

  case 32:
#line 155 "tp.y" /* yacc.c:1646  */
    { (yyval.Method)=StaticMethodDecl((yyvsp[-7].S), (yyvsp[-5].Var), (yyvsp[-2].S), NULL, (yyvsp[0].Expr));}
#line 1628 "tp_y.c" /* yacc.c:1646  */
    break;

  case 33:
#line 156 "tp.y" /* yacc.c:1646  */
    { (yyval.Method)=MethodDecl((yyvsp[-6].S), (yyvsp[-4].Var), (yyvsp[-1].S), (yyvsp[0].Instr), NULL);}
#line 1634 "tp_y.c" /* yacc.c:1646  */
    break;

  case 34:
#line 157 "tp.y" /* yacc.c:1646  */
    { (yyval.Method)=MethodDecl((yyvsp[-7].S), (yyvsp[-5].Var), (yyvsp[-2].S), NULL, (yyvsp[0].Expr));}
#line 1640 "tp_y.c" /* yacc.c:1646  */
    break;

  case 35:
#line 160 "tp.y" /* yacc.c:1646  */
    { (yyval.Var) = NULL; }
#line 1646 "tp_y.c" /* yacc.c:1646  */
    break;

  case 36:
#line 161 "tp.y" /* yacc.c:1646  */
    { (yyval.Var) = (yyvsp[0].Var);   }
#line 1652 "tp_y.c" /* yacc.c:1646  */
    break;

  case 37:
#line 163 "tp.y" /* yacc.c:1646  */
    { (yyval.Var) = (yyvsp[0].Var);   }
#line 1658 "tp_y.c" /* yacc.c:1646  */
    break;

  case 38:
#line 164 "tp.y" /* yacc.c:1646  */
    { (yyval.Var) = ParamDeclSetNext((yyvsp[-2].Var), (yyvsp[0].Var)); }
#line 1664 "tp_y.c" /* yacc.c:1646  */
    break;

  case 39:
#line 166 "tp.y" /* yacc.c:1646  */
    { AssertClassExists((yyvsp[0].S)); (yyval.Var) = ParamDecl((yyvsp[-2].S), (yyvsp[0].S)); }
#line 1670 "tp_y.c" /* yacc.c:1646  */
    break;

  case 40:
#line 169 "tp.y" /* yacc.c:1646  */
    { (yyval.Instr) = (yyvsp[0].Instr); }
#line 1676 "tp_y.c" /* yacc.c:1646  */
    break;

  case 41:
#line 170 "tp.y" /* yacc.c:1646  */
    { (yyval.Instr) = (yyvsp[0].Instr); }
#line 1682 "tp_y.c" /* yacc.c:1646  */
    break;

  case 42:
#line 174 "tp.y" /* yacc.c:1646  */
    { (yyval.Instr) = InstrFromInstrBloc(NULL);        }
#line 1688 "tp_y.c" /* yacc.c:1646  */
    break;

  case 43:
#line 175 "tp.y" /* yacc.c:1646  */
    { (yyval.Instr) = InstrFromInstrBloc((yyvsp[-1].Instr));          }
#line 1694 "tp_y.c" /* yacc.c:1646  */
    break;

  case 44:
#line 177 "tp.y" /* yacc.c:1646  */
    { (yyval.Instr) = InstrFromInstrBloc(NULL);        }
#line 1700 "tp_y.c" /* yacc.c:1646  */
    break;

  case 45:
#line 178 "tp.y" /* yacc.c:1646  */
    { (yyval.Instr) = InstrFromInstrBloc((yyvsp[-1].Instr));          }
#line 1706 "tp_y.c" /* yacc.c:1646  */
    break;

  case 46:
#line 179 "tp.y" /* yacc.c:1646  */
    { (yyval.Instr) = InstrFromProcBloc((yyvsp[-3].Var), (yyvsp[-1].Instr));       }
#line 1712 "tp_y.c" /* yacc.c:1646  */
    break;

  case 47:
#line 182 "tp.y" /* yacc.c:1646  */
    {  (yyval.Instr) = InstrFromFnBloc(NULL, NULL, (yyvsp[-1].Expr)); }
#line 1718 "tp_y.c" /* yacc.c:1646  */
    break;

  case 48:
#line 183 "tp.y" /* yacc.c:1646  */
    {  (yyval.Instr) = InstrFromFnBloc(NULL, (yyvsp[-3].Instr),   (yyvsp[-1].Expr)); }
#line 1724 "tp_y.c" /* yacc.c:1646  */
    break;

  case 49:
#line 184 "tp.y" /* yacc.c:1646  */
    {  (yyval.Instr) = InstrFromFnBloc((yyvsp[-5].Var),   (yyvsp[-3].Instr),   (yyvsp[-1].Expr)); }
#line 1730 "tp_y.c" /* yacc.c:1646  */
    break;

  case 50:
#line 187 "tp.y" /* yacc.c:1646  */
    { (yyval.Instr) = (yyvsp[0].Instr); }
#line 1736 "tp_y.c" /* yacc.c:1646  */
    break;

  case 51:
#line 188 "tp.y" /* yacc.c:1646  */
    { (yyval.Instr) = InstrSetNext((yyvsp[-1].Instr), (yyvsp[0].Instr)); }
#line 1742 "tp_y.c" /* yacc.c:1646  */
    break;

  case 52:
#line 191 "tp.y" /* yacc.c:1646  */
    { (yyval.Instr) = InstrFromExpr((yyvsp[-1].Expr));   }
#line 1748 "tp_y.c" /* yacc.c:1646  */
    break;

  case 53:
#line 192 "tp.y" /* yacc.c:1646  */
    { (yyval.Instr) = InstrFromReturn((yyvsp[-1].Expr)); }
#line 1754 "tp_y.c" /* yacc.c:1646  */
    break;

  case 54:
#line 193 "tp.y" /* yacc.c:1646  */
    { (yyval.Instr) = (yyvsp[0].Instr); }
#line 1760 "tp_y.c" /* yacc.c:1646  */
    break;

  case 55:
#line 194 "tp.y" /* yacc.c:1646  */
    { (yyval.Instr) = (yyvsp[0].Instr); }
#line 1766 "tp_y.c" /* yacc.c:1646  */
    break;

  case 56:
#line 195 "tp.y" /* yacc.c:1646  */
    { (yyval.Instr) = InstrFromAssign((yyvsp[-3].Expr), (yyvsp[-1].Expr)); }
#line 1772 "tp_y.c" /* yacc.c:1646  */
    break;

  case 57:
#line 196 "tp.y" /* yacc.c:1646  */
    { (yyval.Instr) = (yyvsp[0].Instr); }
#line 1778 "tp_y.c" /* yacc.c:1646  */
    break;

  case 58:
#line 198 "tp.y" /* yacc.c:1646  */
    { (yyval.Instr) = InstrFromIf((yyvsp[-4].Expr), (yyvsp[-2].Instr), (yyvsp[0].Instr)); }
#line 1784 "tp_y.c" /* yacc.c:1646  */
    break;

  case 59:
#line 200 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = NULL; }
#line 1790 "tp_y.c" /* yacc.c:1646  */
    break;

  case 60:
#line 201 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = (yyvsp[0].Expr); }
#line 1796 "tp_y.c" /* yacc.c:1646  */
    break;

  case 61:
#line 203 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = (yyvsp[0].Expr); }
#line 1802 "tp_y.c" /* yacc.c:1646  */
    break;

  case 62:
#line 204 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = ExprSetNext((yyvsp[-2].Expr), (yyvsp[0].Expr)); }
#line 1808 "tp_y.c" /* yacc.c:1646  */
    break;

  case 63:
#line 207 "tp.y" /* yacc.c:1646  */
    { /*ExprAssertIDIsOk($1);*/ (yyval.Expr) = ExprFromVar((yyvsp[0].S)); }
#line 1814 "tp_y.c" /* yacc.c:1646  */
    break;

  case 64:
#line 208 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = (yyvsp[0].Expr); }
#line 1820 "tp_y.c" /* yacc.c:1646  */
    break;

  case 65:
#line 209 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = (yyvsp[0].Expr); }
#line 1826 "tp_y.c" /* yacc.c:1646  */
    break;

  case 66:
#line 210 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = (yyvsp[0].Expr); }
#line 1832 "tp_y.c" /* yacc.c:1646  */
    break;

  case 67:
#line 211 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = (yyvsp[0].Expr); }
#line 1838 "tp_y.c" /* yacc.c:1646  */
    break;

  case 68:
#line 212 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = (yyvsp[0].Expr); }
#line 1844 "tp_y.c" /* yacc.c:1646  */
    break;

  case 69:
#line 213 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = (yyvsp[0].Expr); }
#line 1850 "tp_y.c" /* yacc.c:1646  */
    break;

  case 70:
#line 214 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = (yyvsp[-1].Expr); }
#line 1856 "tp_y.c" /* yacc.c:1646  */
    break;

  case 71:
#line 216 "tp.y" /* yacc.c:1646  */
    { ExprAssertFieldAccessIsOk((yyvsp[-2].Expr),(yyvsp[0].S));                                     (yyval.Expr) = ExprFromFieldAccess((yyvsp[-2].Expr), (yyvsp[0].S));           }
#line 1862 "tp_y.c" /* yacc.c:1646  */
    break;

  case 72:
#line 217 "tp.y" /* yacc.c:1646  */
    { AssertClassExists((yyvsp[-2].S));  ExprAssertStaticFieldAccessIsOk((yyvsp[-2].S),(yyvsp[0].S));       (yyval.Expr) = ExprFromStaticFieldAccess((yyvsp[-2].S), (yyvsp[0].S));     }
#line 1868 "tp_y.c" /* yacc.c:1646  */
    break;

  case 73:
#line 218 "tp.y" /* yacc.c:1646  */
    { AssertClassExists((yyvsp[-5].S));  ExprAssertStaticMethodAccessIsOk((yyvsp[-5].S),(yyvsp[-3].S), (yyvsp[-1].Expr));  (yyval.Expr) = ExprFromStaticMethodAccess((yyvsp[-5].S), (yyvsp[-3].S), (yyvsp[-1].Expr));}
#line 1874 "tp_y.c" /* yacc.c:1646  */
    break;

  case 74:
#line 219 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = ExprFromMethodAccess((yyvsp[-5].Expr), (yyvsp[-3].S), (yyvsp[-1].Expr));  }
#line 1880 "tp_y.c" /* yacc.c:1646  */
    break;

  case 75:
#line 221 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = ExprFromConcat((yyvsp[-2].Expr), (yyvsp[0].Expr)); }
#line 1886 "tp_y.c" /* yacc.c:1646  */
    break;

  case 76:
#line 223 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = ExprFromString((yyvsp[0].S));  }
#line 1892 "tp_y.c" /* yacc.c:1646  */
    break;

  case 77:
#line 224 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = ExprFromInt((yyvsp[0].I));     }
#line 1898 "tp_y.c" /* yacc.c:1646  */
    break;

  case 78:
#line 225 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = ExprFromVoid();      }
#line 1904 "tp_y.c" /* yacc.c:1646  */
    break;

  case 79:
#line 228 "tp.y" /* yacc.c:1646  */
    { AssertClassExists((yyvsp[-3].S));  (yyval.Expr) = ExprFromInstanciation((yyvsp[-3].S), (yyvsp[-1].Expr)); }
#line 1910 "tp_y.c" /* yacc.c:1646  */
    break;

  case 80:
#line 232 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = ExprFromArithmetic((yyvsp[-2].Expr), ADD, (yyvsp[0].Expr)); }
#line 1916 "tp_y.c" /* yacc.c:1646  */
    break;

  case 81:
#line 233 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = ExprFromArithmetic((yyvsp[-2].Expr), SUB, (yyvsp[0].Expr)); }
#line 1922 "tp_y.c" /* yacc.c:1646  */
    break;

  case 82:
#line 234 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = ExprFromArithmetic((yyvsp[-2].Expr), MUL, (yyvsp[0].Expr)); }
#line 1928 "tp_y.c" /* yacc.c:1646  */
    break;

  case 83:
#line 235 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = ExprFromArithmetic((yyvsp[-2].Expr), DIV, (yyvsp[0].Expr)); }
#line 1934 "tp_y.c" /* yacc.c:1646  */
    break;

  case 84:
#line 236 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = ExprFromArithmetic(ExprFromInt(0), SUB, (yyvsp[0].Expr)); }
#line 1940 "tp_y.c" /* yacc.c:1646  */
    break;

  case 85:
#line 237 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = (yyvsp[0].Expr); }
#line 1946 "tp_y.c" /* yacc.c:1646  */
    break;

  case 86:
#line 240 "tp.y" /* yacc.c:1646  */
    { (yyval.Expr) = ExprFromBoolean((yyvsp[-2].Expr), (yyvsp[-1].I), (yyvsp[0].Expr));  }
#line 1952 "tp_y.c" /* yacc.c:1646  */
    break;

  case 87:
#line 243 "tp.y" /* yacc.c:1646  */
    { (yyval.Var) = (yyvsp[0].Var);  VarAddToCurrentScope((yyval.Var)); }
#line 1958 "tp_y.c" /* yacc.c:1646  */
    break;

  case 88:
#line 244 "tp.y" /* yacc.c:1646  */
    { (yyval.Var) =      ParamDeclSetNext((yyvsp[-1].Var), (yyvsp[0].Var)); }
#line 1964 "tp_y.c" /* yacc.c:1646  */
    break;

  case 89:
#line 246 "tp.y" /* yacc.c:1646  */
    { AssertClassExists((yyvsp[-3].S));(yyval.Var) = VarDecl((yyvsp[-5].S), (yyvsp[-3].S), (yyvsp[-1].Expr));    }
#line 1970 "tp_y.c" /* yacc.c:1646  */
    break;

  case 90:
#line 247 "tp.y" /* yacc.c:1646  */
    { AssertClassExists((yyvsp[-1].S));(yyval.Var) = VarDecl((yyvsp[-3].S), (yyvsp[-1].S), NULL);  }
#line 1976 "tp_y.c" /* yacc.c:1646  */
    break;


#line 1980 "tp_y.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
