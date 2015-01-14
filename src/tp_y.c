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
#line 41 "tp.y" /* yacc.c:339  */

#define YYDEBUG 1
#include "tp.h"     /* les definition des types et les etiquettes des noeuds */

extern int yylex();	/* fournie par Flex */
extern void yyerror();  /* definie dans tp.c */

#line 74 "tp_y.c" /* yacc.c:339  */

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
    ASSIGN = 283
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TP_Y_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 149 "tp_y.c" /* yacc.c:358  */

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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   363

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  204

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

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
      30,    31,     2,     2,    34,     2,    29,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    36,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
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
      25,    26,    27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    68,    68,    69,    71,    72,    74,    75,    76,    77,
      82,    84,    85,    87,    88,    90,    93,    94,    96,    98,
      99,   101,   107,   108,   110,   111,   112,   113,   115,   116,
     118,   119,   121,   122,   124,   125,   127,   128,   131,   132,
     134,   135,   137,   141,   142,   146,   147,   149,   150,   153,
     154,   155,   156,   157,   159,   160,   162,   163,   166,   167,
     168,   169,   170,   171,   172,   174,   175,   176,   177,   179,
     181,   183,   184,   185,   188,   191,   192,   193,   194,   197,
     198,   200,   204,   205,   206,   209,   210,   211,   214,   215,
     217,   218
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
  "CONST_STR", "CLASS_TYPE", "CONST_INT", "RELOP", "ASSIGN", "'.'", "'('",
  "')'", "'{'", "'}'", "','", "':'", "';'", "$accept", "program",
  "L_classDef", "classDef", "classDecl", "Opt_L_classParamDecl",
  "L_classParamDecl", "classParamDecl", "Opt_extendsDecl", "extendsDecl",
  "Opt_constructorBody", "constructorBody", "L_fieldDecl", "fieldDecl",
  "L_methodDecl", "methodDecl", "Opt_L_methodParamDecl",
  "L_methodParamDecl", "methodParamDecl", "methodBody", "instructionBloc",
  "L_instr", "instr", "Opt_L_expr", "L_expr", "expr", "selection",
  "concatExpr", "returnExpr", "constant", "instanciation", "arithmExpr",
  "booleanExpr", "REL", "proceduralBloc", "functionalBloc", "L_varDecl",
  "varDecl", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    46,
      40,    41,   123,   125,    44,    58,    59
};
# endif

#define YYPACT_NINF -129

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-129)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,    -2,   128,    29,     2,  -129,    32,  -129,    44,   261,
      46,   198,  -129,  -129,  -129,    67,  -129,    75,  -129,   149,
    -129,   212,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,    71,    81,   334,    80,   198,   330,    89,
      90,   100,   261,  -129,    43,    16,  -129,  -129,  -129,   261,
     261,   261,   261,   261,   261,   101,  -129,     3,    91,    94,
     103,  -129,   261,   104,  -129,   261,   184,   111,   109,   279,
     261,  -129,   184,  -129,   116,    -4,    -4,    -5,    -5,   216,
     117,    41,    50,  -129,     4,  -129,     5,  -129,   123,   144,
      81,   126,   124,   334,  -129,   334,   171,   261,   134,  -129,
     296,   106,  -129,   261,   139,    54,   135,   145,   132,  -129,
    -129,    13,  -129,  -129,  -129,   151,   137,  -129,  -129,  -129,
     261,   184,   147,    -6,  -129,   261,  -129,   152,   140,   157,
     159,   169,   165,   176,  -129,   172,  -129,  -129,  -129,   334,
     184,  -129,   261,  -129,   313,  -129,   169,   175,   169,   178,
     180,   181,  -129,   189,    11,   261,   236,  -129,   186,   169,
     187,   196,   219,   169,    57,   261,  -129,   207,  -129,   220,
     208,   235,  -129,   218,  -129,   261,  -129,   240,  -129,   221,
     237,   222,    20,   260,  -129,    63,   225,    74,   261,  -129,
    -129,  -129,  -129,   261,  -129,   108,   261,  -129,   334,   334,
     261,  -129,   334,   334
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     0,     2,     0,     0,
       0,     0,    73,    58,    71,     0,    72,     0,    45,     0,
      47,     0,    64,    62,    63,    61,    60,    59,    50,    51,
       1,     5,     3,     0,    11,    70,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,    88,    46,    48,     0,
       0,     0,     0,     0,     0,     0,    49,     0,     0,     0,
      12,    13,    54,     0,    81,     0,     0,    66,     0,     0,
       0,    83,     0,    89,    69,    75,    76,    77,    78,     0,
      65,     0,     0,     6,     0,    22,     0,    28,     0,    16,
       0,     0,    55,    56,    80,    79,     0,    54,     0,    85,
       0,     0,    52,    54,     0,     0,     0,     0,     0,     7,
      23,     0,     8,    29,    15,     0,    19,    17,    14,    74,
       0,     0,     0,     0,    86,     0,    84,     0,     0,     0,
       0,    38,     0,     0,     9,     0,    10,    20,    21,    57,
      53,    67,     0,    91,     0,    68,    38,     0,    38,     0,
       0,    39,    40,     0,     0,    54,     0,    87,     0,    38,
       0,     0,     0,     0,     0,     0,    25,     0,    90,     0,
       0,     0,    42,     0,    41,     0,    27,     0,    18,     0,
       0,     0,     0,     0,    24,     0,     0,     0,     0,    36,
      43,    44,    26,     0,    34,     0,     0,    32,    37,    35,
       0,    30,    33,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,  -129,   247,  -129,  -129,  -129,   173,  -129,  -129,
    -129,  -129,  -129,   182,   190,   -79,  -128,  -129,    99,  -115,
      -1,   -12,   -18,   -93,  -129,    -9,  -129,  -129,  -129,  -129,
    -129,  -129,   227,  -129,  -103,   -68,  -129,   223
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    59,    60,    61,   116,   117,
     136,   137,    84,    85,    86,    87,   150,   151,   152,   189,
       7,    19,    20,    91,    92,    21,    22,    23,    24,    25,
      26,    27,    39,    65,    28,    29,    45,    46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      35,    48,    38,    32,   122,    44,     1,   113,    49,    49,
     127,    81,    81,    81,    82,    82,    52,    53,   158,    72,
     160,    81,   142,     8,    55,    55,    48,    41,    38,    30,
     143,   170,   113,    69,     2,    33,    83,   109,   112,   165,
      74,    75,    76,    77,    78,    79,   134,   166,   188,     9,
     104,   105,    17,    93,    96,    70,    95,    10,    11,   107,
     101,   100,   167,   129,   106,    12,    13,    14,    15,    16,
     194,    36,   197,   108,    34,    17,    71,   130,    48,   190,
     201,     9,   190,    48,   190,   175,    41,    42,    93,    10,
      11,   193,   190,   176,    93,    17,    40,    12,    13,    14,
      15,    16,   196,    57,    58,    66,    17,    17,    43,   140,
      62,   139,     9,    67,   191,   138,   144,   191,   125,   191,
      10,    11,    48,    68,    80,    89,    88,   191,    12,    13,
      14,    15,    16,   156,     9,    94,   200,    90,    17,   126,
      17,    97,    10,    11,    98,    55,    93,   103,   114,   115,
      12,    13,    14,    15,    16,     9,   177,   119,   120,   123,
      17,    18,   128,    10,    11,   131,   183,   133,   132,     2,
     146,    12,    13,    14,    15,    16,   135,     9,   141,   198,
     147,    17,    47,   145,   199,    10,    11,   202,   121,   148,
       9,   203,   149,    12,    13,    14,    15,    16,    10,    11,
     153,   154,   155,    17,     9,   159,    12,    13,    14,    15,
      16,   162,    10,   161,   164,   163,    17,   169,   171,   172,
      12,    13,    14,    15,    16,    49,   173,   179,    37,    49,
      50,    51,    52,    53,    50,    51,    52,    53,   178,   180,
      54,    55,   181,   182,   186,    55,   185,   187,    56,    49,
     195,    31,   102,    49,    50,    51,    52,    53,    50,    51,
      52,    53,   174,   118,    63,    55,   110,     9,    73,    55,
       0,     0,   168,    49,   111,    10,   184,     0,    50,    51,
      52,    53,     0,    12,    13,    14,    15,    16,     0,    55,
       0,     0,    49,     0,     0,     0,   192,    50,    51,    52,
      53,     0,     0,     0,     0,     0,     0,     0,    55,    49,
       0,     0,    99,     0,    50,    51,    52,    53,     0,     0,
       0,     0,     0,     0,     0,    55,    49,     0,     0,   124,
       0,    50,    51,    52,    53,     0,     0,     0,     0,     0,
       0,     0,    55,    49,     0,     0,   157,    49,    50,    51,
      52,    53,    50,    51,    52,    53,     0,    64,     0,    55,
       0,     0,     0,    55
};

static const yytype_int16 yycheck[] =
{
       9,    19,    11,     4,    97,    17,     4,    86,    13,    13,
     103,     8,     8,     8,    11,    11,    20,    21,   146,     3,
     148,     8,    28,    25,    29,    29,    44,    11,    37,     0,
      36,   159,   111,    42,    32,     3,    33,    33,    33,    28,
      49,    50,    51,    52,    53,    54,    33,    36,    28,     6,
       9,    10,    32,    62,    66,    12,    65,    14,    15,     9,
      72,    70,   155,     9,    23,    22,    23,    24,    25,    26,
     185,    25,   187,    23,    30,    32,    33,    23,    96,   182,
     195,     6,   185,   101,   187,    28,    11,    12,    97,    14,
      15,    28,   195,    36,   103,    32,    29,    22,    23,    24,
      25,    26,    28,    32,    23,    16,    32,    32,    33,   121,
      30,   120,     6,    23,   182,   116,   125,   185,    12,   187,
      14,    15,   140,    23,    23,    31,    35,   195,    22,    23,
      24,    25,    26,   142,     6,    31,    28,    34,    32,    33,
      32,    30,    14,    15,    35,    29,   155,    30,    25,     5,
      22,    23,    24,    25,    26,     6,   165,    31,    34,    25,
      32,    33,    23,    14,    15,    30,   175,    35,    23,    32,
      30,    22,    23,    24,    25,    26,    25,     6,    31,   188,
      23,    32,    33,    31,   193,    14,    15,   196,    17,    30,
       6,   200,    23,    22,    23,    24,    25,    26,    14,    15,
      35,    25,    30,    32,     6,    30,    22,    23,    24,    25,
      26,    31,    14,    35,    25,    34,    32,    31,    31,    23,
      22,    23,    24,    25,    26,    13,     7,     7,    30,    13,
      18,    19,    20,    21,    18,    19,    20,    21,    31,    31,
      28,    29,     7,    25,     7,    29,    25,    25,    36,    13,
      25,     4,    36,    13,    18,    19,    20,    21,    18,    19,
      20,    21,   163,    90,    37,    29,    84,     6,    45,    29,
      -1,    -1,    36,    13,    84,    14,    36,    -1,    18,    19,
      20,    21,    -1,    22,    23,    24,    25,    26,    -1,    29,
      -1,    -1,    13,    -1,    -1,    -1,    36,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    13,
      -1,    -1,    33,    -1,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    13,    -1,    -1,    33,
      -1,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    13,    -1,    -1,    33,    13,    18,    19,
      20,    21,    18,    19,    20,    21,    -1,    27,    -1,    29,
      -1,    -1,    -1,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    32,    38,    39,    40,    41,    57,    25,     6,
      14,    15,    22,    23,    24,    25,    26,    32,    33,    58,
      59,    62,    63,    64,    65,    66,    67,    68,    71,    72,
       0,    40,    57,     3,    30,    62,    25,    30,    62,    69,
      29,    11,    12,    33,    58,    73,    74,    33,    59,    13,
      18,    19,    20,    21,    28,    29,    36,    32,    23,    42,
      43,    44,    30,    69,    27,    70,    16,    23,    23,    62,
      12,    33,     3,    74,    62,    62,    62,    62,    62,    62,
      23,     8,    11,    33,    49,    50,    51,    52,    35,    31,
      34,    60,    61,    62,    31,    62,    58,    30,    35,    33,
      62,    58,    36,    30,     9,    10,    23,     9,    23,    33,
      50,    51,    33,    52,    25,     5,    45,    46,    44,    31,
      34,    17,    60,    25,    33,    12,    33,    60,    23,     9,
      23,    30,    23,    35,    33,    25,    47,    48,    57,    62,
      58,    31,    28,    36,    62,    31,    30,    23,    30,    23,
      53,    54,    55,    35,    25,    30,    62,    33,    53,    30,
      53,    35,    31,    34,    25,    28,    36,    60,    36,    31,
      53,    31,    23,     7,    55,    28,    36,    62,    31,     7,
      31,     7,    25,    62,    36,    25,     7,    25,    28,    56,
      71,    72,    36,    28,    56,    25,    28,    56,    62,    62,
      28,    56,    62,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    40,    40,    40,    40,
      41,    42,    42,    43,    43,    44,    45,    45,    46,    47,
      47,    48,    49,    49,    50,    50,    50,    50,    51,    51,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    53,
      54,    54,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    59,    59,    59,    60,    60,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    63,    63,    63,    63,    64,
      65,    66,    66,    66,    67,    68,    68,    68,    68,    69,
      69,    70,    71,    71,    71,    72,    72,    72,    73,    73,
      74,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     4,     5,     5,     6,
       7,     0,     1,     1,     3,     3,     0,     1,     5,     0,
       1,     1,     1,     2,     7,     5,     8,     6,     1,     2,
      10,    11,     9,    10,     9,    10,     8,     9,     0,     1,
       1,     3,     3,     1,     1,     2,     3,     1,     2,     2,
       1,     1,     4,     6,     0,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     6,     6,     3,
       2,     1,     1,     1,     5,     3,     3,     3,     3,     3,
       3,     1,     2,     3,     5,     4,     5,     7,     1,     2,
       7,     5
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
        case 47:
#line 149 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1397 "tp_y.c" /* yacc.c:1646  */
    break;

  case 48:
#line 150 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = addNext((yyvsp[-1].T), (yyvsp[0].T)); }
#line 1403 "tp_y.c" /* yacc.c:1646  */
    break;

  case 49:
#line 153 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[-1].T); }
#line 1409 "tp_y.c" /* yacc.c:1646  */
    break;

  case 50:
#line 154 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1415 "tp_y.c" /* yacc.c:1646  */
    break;

  case 51:
#line 155 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1421 "tp_y.c" /* yacc.c:1646  */
    break;

  case 52:
#line 156 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(ASSIGN, 2, (yyvsp[-3].T), (yyvsp[-1].T));  }
#line 1427 "tp_y.c" /* yacc.c:1646  */
    break;

  case 53:
#line 157 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(IF, 3, (yyvsp[-4].T), (yyvsp[-2].T), (yyvsp[0].T)); }
#line 1433 "tp_y.c" /* yacc.c:1646  */
    break;

  case 54:
#line 159 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = NULL; }
#line 1439 "tp_y.c" /* yacc.c:1646  */
    break;

  case 55:
#line 160 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1445 "tp_y.c" /* yacc.c:1646  */
    break;

  case 56:
#line 162 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1451 "tp_y.c" /* yacc.c:1646  */
    break;

  case 57:
#line 163 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = addNext((yyvsp[-2].T), (yyvsp[0].T)); }
#line 1457 "tp_y.c" /* yacc.c:1646  */
    break;

  case 58:
#line 166 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = makeLeafStr(ID, (yyvsp[0].S)); }
#line 1463 "tp_y.c" /* yacc.c:1646  */
    break;

  case 59:
#line 167 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1469 "tp_y.c" /* yacc.c:1646  */
    break;

  case 60:
#line 168 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1475 "tp_y.c" /* yacc.c:1646  */
    break;

  case 61:
#line 169 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1481 "tp_y.c" /* yacc.c:1646  */
    break;

  case 62:
#line 170 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1487 "tp_y.c" /* yacc.c:1646  */
    break;

  case 63:
#line 171 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1493 "tp_y.c" /* yacc.c:1646  */
    break;

  case 64:
#line 172 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1499 "tp_y.c" /* yacc.c:1646  */
    break;

  case 69:
#line 179 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(CONCAT, 2, (yyvsp[-2].T), (yyvsp[0].T)); }
#line 1505 "tp_y.c" /* yacc.c:1646  */
    break;

  case 70:
#line 181 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1511 "tp_y.c" /* yacc.c:1646  */
    break;

  case 71:
#line 183 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = makeLeafStr(CONST_STR,   (yyvsp[0].S)); }
#line 1517 "tp_y.c" /* yacc.c:1646  */
    break;

  case 72:
#line 184 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = makeLeafInt(CONST_INT,   (yyvsp[0].I)); }
#line 1523 "tp_y.c" /* yacc.c:1646  */
    break;

  case 73:
#line 185 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = makeLeafVoid(CONST_VOID); }
#line 1529 "tp_y.c" /* yacc.c:1646  */
    break;

  case 74:
#line 188 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(NEW, 2, makeLeafStr(CLASS_TYPE,(yyvsp[-3].S)), (yyvsp[-1].T)); }
#line 1535 "tp_y.c" /* yacc.c:1646  */
    break;

  case 75:
#line 191 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(ADD, 2, (yyvsp[-2].T), (yyvsp[0].T)); }
#line 1541 "tp_y.c" /* yacc.c:1646  */
    break;

  case 76:
#line 192 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(SUB, 2, (yyvsp[-2].T), (yyvsp[0].T)); }
#line 1547 "tp_y.c" /* yacc.c:1646  */
    break;

  case 77:
#line 193 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(MUL, 2, (yyvsp[-2].T), (yyvsp[0].T)); }
#line 1553 "tp_y.c" /* yacc.c:1646  */
    break;

  case 78:
#line 194 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(DIV, 2, (yyvsp[-2].T), (yyvsp[0].T)); }
#line 1559 "tp_y.c" /* yacc.c:1646  */
    break;

  case 79:
#line 197 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree((yyvsp[-1].C), 2, (yyvsp[-2].T), (yyvsp[0].T)); }
#line 1565 "tp_y.c" /* yacc.c:1646  */
    break;

  case 80:
#line 198 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[-1].T); }
#line 1571 "tp_y.c" /* yacc.c:1646  */
    break;

  case 81:
#line 200 "tp.y" /* yacc.c:1646  */
    { (yyval.C) = yylval.I; }
#line 1577 "tp_y.c" /* yacc.c:1646  */
    break;

  case 82:
#line 204 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(BLOC, 3, NULL, NULL, NULL); }
#line 1583 "tp_y.c" /* yacc.c:1646  */
    break;

  case 83:
#line 205 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(BLOC, 3, NULL,   (yyvsp[-1].T), NULL); }
#line 1589 "tp_y.c" /* yacc.c:1646  */
    break;

  case 84:
#line 206 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(BLOC, 3, (yyvsp[-3].T),     (yyvsp[-1].T), NULL); }
#line 1595 "tp_y.c" /* yacc.c:1646  */
    break;

  case 85:
#line 209 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(BLOC, 3, NULL, NULL, (yyvsp[-1].T)); }
#line 1601 "tp_y.c" /* yacc.c:1646  */
    break;

  case 86:
#line 210 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(BLOC, 3, NULL,   (yyvsp[-3].T), (yyvsp[-1].T)); }
#line 1607 "tp_y.c" /* yacc.c:1646  */
    break;

  case 87:
#line 211 "tp.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(BLOC, 3,   (yyvsp[-5].T),   (yyvsp[-3].T), (yyvsp[-1].T)); }
#line 1613 "tp_y.c" /* yacc.c:1646  */
    break;


#line 1617 "tp_y.c" /* yacc.c:1646  */
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
