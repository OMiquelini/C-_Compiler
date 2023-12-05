
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 7 "parser.y"

#include "scanner.h"
#include "stdio.h"
#include "stdlib.h"

#define YYSTYPE AST_p

AST_p raiz;

int yylex();
char *str_aux;
void yyerror(const char *s);



/* Line 189 of yacc.c  */
#line 89 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMERO = 258,
     IDENTIFICADOR = 259,
     MAIS = 260,
     MAIOR = 261,
     ATRIBUICAO = 262,
     DIVISAO = 263,
     MENOS = 264,
     MULTIPLICACAO = 265,
     L_PAR = 266,
     R_PAR = 267,
     L_CHAVES = 268,
     R_CHAVES = 269,
     L_BRAC = 270,
     R_BRAC = 271,
     COMMA = 272,
     SEMICOLON = 273,
     MENOR = 274,
     MAIOR_IGUAL = 275,
     MENOR_IGUAL = 276,
     DIFERENTE = 277,
     IGUAL = 278,
     IF = 279,
     INT = 280,
     ELSE = 281,
     VOID = 282,
     WHILE = 283,
     RETURN = 284
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 160 "parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   102

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNRULES -- Number of states.  */
#define YYNSTATES  104

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    18,    25,
      27,    29,    36,    38,    40,    44,    46,    49,    54,    59,
      62,    63,    66,    67,    69,    71,    73,    75,    77,    80,
      82,    88,    96,   102,   105,   109,   113,   115,   117,   118,
     124,   128,   130,   132,   134,   136,   138,   140,   142,   146,
     148,   150,   152,   156,   158,   160,   162,   166,   168,   170,
     172,   173,   179,   181,   182,   186
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      31,     0,    -1,    32,    -1,    32,    33,    -1,    33,    -1,
      34,    -1,    36,    -1,    35,     4,    18,    -1,    35,     4,
      15,     3,    16,    18,    -1,    25,    -1,    27,    -1,    35,
       4,    11,    37,    12,    40,    -1,    38,    -1,    27,    -1,
      38,    17,    39,    -1,    39,    -1,    35,     4,    -1,    35,
       4,    15,    16,    -1,    13,    41,    42,    14,    -1,    41,
      34,    -1,    -1,    42,    43,    -1,    -1,    44,    -1,    40,
      -1,    45,    -1,    46,    -1,    47,    -1,    48,    18,    -1,
      18,    -1,    24,    11,    48,    12,    43,    -1,    24,    11,
      48,    12,    43,    26,    43,    -1,    28,    11,    48,    12,
      43,    -1,    29,    18,    -1,    29,    48,    18,    -1,    49,
       7,    48,    -1,    51,    -1,     4,    -1,    -1,     4,    50,
      15,    48,    16,    -1,    53,    52,    53,    -1,    53,    -1,
      19,    -1,     6,    -1,    21,    -1,    22,    -1,    20,    -1,
      23,    -1,    53,    54,    55,    -1,    55,    -1,     5,    -1,
       9,    -1,    55,    56,    57,    -1,    57,    -1,    10,    -1,
       8,    -1,    11,    48,    12,    -1,    49,    -1,    58,    -1,
       3,    -1,    -1,     4,    59,    11,    60,    12,    -1,    61,
      -1,    -1,    61,    17,    48,    -1,    48,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    28,    28,    34,    50,    56,    60,    66,    72,    79,
      84,    91,   102,   107,   114,   123,   129,   135,   143,   152,
     168,   173,   189,   195,   199,   203,   207,   211,   217,   221,
     227,   234,   244,   253,   257,   265,   273,   279,   284,   284,
     296,   303,   309,   314,   320,   326,   332,   338,   345,   352,
     358,   364,   371,   378,   384,   389,   396,   400,   405,   410,
     417,   417,   429,   433,   439,   448
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMERO", "IDENTIFICADOR", "MAIS",
  "MAIOR", "ATRIBUICAO", "DIVISAO", "MENOS", "MULTIPLICACAO", "L_PAR",
  "R_PAR", "L_CHAVES", "R_CHAVES", "L_BRAC", "R_BRAC", "COMMA",
  "SEMICOLON", "MENOR", "MAIOR_IGUAL", "MENOR_IGUAL", "DIFERENTE", "IGUAL",
  "IF", "INT", "ELSE", "VOID", "WHILE", "RETURN", "$accept", "programa",
  "declaracao_lista", "declaracao", "var_declaracao", "tipo_especificador",
  "fun_declaracao", "params", "param_list", "param", "composto_decl",
  "local_declaracoes", "statement_list", "statement", "expressao_decl",
  "selecao_decl", "iteracao_decl", "retorno_decl", "expressao", "var",
  "@1", "simples_expressao", "relacional", "soma_expressao", "soma",
  "termo", "mult", "fator", "ativacao", "@2", "args", "arg_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    34,    34,    35,
      35,    36,    37,    37,    38,    38,    39,    39,    40,    41,
      41,    42,    42,    43,    43,    43,    43,    43,    44,    44,
      45,    45,    46,    47,    47,    48,    48,    49,    50,    49,
      51,    51,    52,    52,    52,    52,    52,    52,    53,    53,
      54,    54,    55,    55,    56,    56,    57,    57,    57,    57,
      59,    58,    60,    60,    61,    61
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     1,     3,     1,     2,     4,     4,     2,
       0,     2,     0,     1,     1,     1,     1,     1,     2,     1,
       5,     7,     5,     2,     3,     3,     1,     1,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       0,     5,     1,     0,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,     0,     0,     0,     7,    10,     0,     0,    12,    15,
       0,    16,     0,     0,     0,     0,    20,    11,    14,     8,
      17,    22,    19,     0,     0,     0,    59,    37,     0,    18,
      29,     0,     0,     0,    24,    21,    23,    25,    26,    27,
       0,    57,    36,    41,    49,    53,    58,     0,     0,     0,
       0,     0,    33,     0,    28,     0,    50,    43,    51,    42,
      46,    44,    45,    47,     0,     0,    55,    54,     0,     0,
      63,    56,     0,     0,    34,    35,    57,    40,    48,    52,
       0,    65,     0,    62,     0,     0,    39,    61,     0,    30,
      32,    64,     0,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,    17,    18,    19,
      44,    31,    34,    45,    46,    47,    48,    49,    50,    51,
      57,    52,    74,    53,    75,    54,    78,    55,    56,    58,
      92,    93
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -86
static const yytype_int8 yypact[] =
{
      29,   -86,   -86,    37,    29,   -86,   -86,    17,   -86,   -86,
     -86,    21,    34,    31,   -86,    46,    51,    56,    53,   -86,
      55,    57,    60,    29,    58,    61,   -86,   -86,   -86,   -86,
     -86,    29,   -86,    70,     0,     1,   -86,    -9,     4,   -86,
     -86,    64,    67,    27,   -86,   -86,   -86,   -86,   -86,   -86,
      62,    72,   -86,    43,    59,   -86,   -86,    66,    71,    73,
       4,     4,   -86,    65,   -86,     4,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,   -86,     4,     4,   -86,   -86,     4,     4,
       4,   -86,    74,    75,   -86,   -86,   -86,    48,    59,   -86,
      68,   -86,    76,    77,    22,    22,   -86,   -86,     4,    63,
     -86,   -86,    22,   -86
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -86,   -86,   -86,    86,    69,   -11,   -86,   -86,   -86,    78,
      80,   -86,   -86,   -85,   -86,   -86,   -86,   -86,   -38,   -31,
     -86,   -86,   -86,    18,   -86,    16,   -86,    15,   -86,   -86,
     -86,   -86
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -61
static const yytype_int8 yytable[] =
{
      59,    16,   -60,    36,    37,    63,   -38,    36,    37,    99,
     100,    38,    16,    26,    39,    38,    13,   103,    40,    14,
      33,    11,    82,    83,    41,    36,    37,    85,    42,    43,
      36,    37,    12,    38,    20,    26,    13,     9,    38,    14,
      40,    90,    91,    86,    86,    62,    41,    86,    66,    67,
      42,    43,    68,    66,     1,    21,     2,    68,   -13,     1,
     101,    15,    69,    70,    71,    72,    73,    76,    22,    77,
      23,    24,    25,    26,    35,    60,    29,    30,    61,    65,
      64,    79,    80,    84,    96,    81,    94,    95,    97,   102,
      10,    88,    87,    89,    98,     0,     0,     0,     0,     0,
      32,    28,    27
};

static const yytype_int8 yycheck[] =
{
      38,    12,    11,     3,     4,    43,    15,     3,     4,    94,
      95,    11,    23,    13,    14,    11,    15,   102,    18,    18,
      31,     4,    60,    61,    24,     3,     4,    65,    28,    29,
       3,     4,    11,    11,     3,    13,    15,     0,    11,    18,
      18,    79,    80,    74,    75,    18,    24,    78,     5,     6,
      28,    29,     9,     5,    25,     4,    27,     9,    12,    25,
      98,    27,    19,    20,    21,    22,    23,     8,    12,    10,
      17,    16,    15,    13,     4,    11,    18,    16,    11,     7,
      18,    15,    11,    18,    16,    12,    12,    12,    12,    26,
       4,    75,    74,    78,    17,    -1,    -1,    -1,    -1,    -1,
      31,    23,    22
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    27,    31,    32,    33,    34,    35,    36,     0,
      33,     4,    11,    15,    18,    27,    35,    37,    38,    39,
       3,     4,    12,    17,    16,    15,    13,    40,    39,    18,
      16,    41,    34,    35,    42,     4,     3,     4,    11,    14,
      18,    24,    28,    29,    40,    43,    44,    45,    46,    47,
      48,    49,    51,    53,    55,    57,    58,    50,    59,    48,
      11,    11,    18,    48,    18,     7,     5,     6,     9,    19,
      20,    21,    22,    23,    52,    54,     8,    10,    56,    15,
      11,    12,    48,    48,    18,    48,    49,    53,    55,    57,
      48,    48,    60,    61,    12,    12,    16,    12,    17,    43,
      43,    48,    26,    43
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 28 "parser.y"
    {
        //printf("programa\n");
        raiz = (yyvsp[(1) - (1)]);
;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 34 "parser.y"
    {
                //printf("declaracao_lista\n");
                YYSTYPE aux = (yyvsp[(1) - (2)]);
                if(aux == NULL)
                {
                        (yyval) = (yyvsp[(2) - (2)]);
                }
                else
                {
                        while(aux->irmaos != NULL){
                        aux = aux->irmaos;
                        }
                        aux->irmaos = (yyvsp[(2) - (2)]);
                        (yyval) = (yyvsp[(1) - (2)]);
                }
        ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 50 "parser.y"
    { 
                //printf("declaracao_lista\n");
                (yyval) = (yyvsp[(1) - (1)]);
        ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 56 "parser.y"
    {
                //printf("declaracao\n");
                (yyval) = (yyvsp[(1) - (1)]);
        ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 60 "parser.y"
    {
                //printf("declaracao\n");
                (yyval) = (yyvsp[(1) - (1)]);
        ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 66 "parser.y"
    {
                //printf("var_declaracao\n");
                (yyval)=(yyvsp[(1) - (3)]);
                (yyval)->str=strdup(lex->lexema);//nok
                (yyval)->tipo_var = Var;
        ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 72 "parser.y"
    {
                //printf("var_declaracao\n");
                (yyval)=(yyvsp[(1) - (6)]);
                (yyval)->str=strdup(lex->lexema);//nok
                (yyval)->tipo_var = Array;
        ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 79 "parser.y"
    {
                //printf("tipo_especificador\n"); 
                (yyval)=cria_decl(Var);
                (yyval)->tipo_var = Int;
        ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 84 "parser.y"
    {
                //printf("tipo_especificador\n"); 
                (yyval)=cria_decl(Var);
                (yyval)->tipo_var = Void;
        ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 91 "parser.y"
    {
                //printf("fun_declaracao\n"); 
                (yyval) = (yyvsp[(1) - (6)]);
                (yyval)->tipo_decl = Func;
                (yyval)->str=strdup(lex->lexema);//nok
                (yyval)->filhos[0] = (yyvsp[(4) - (6)]);
                (yyval)->filhos[1] = (yyvsp[(6) - (6)]);
                (yyval)->n_filhos = 2;
        ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 102 "parser.y"
    {
                //printf("params\n"); 
                (yyval) = (yyvsp[(1) - (1)]);

        ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    {
                //printf("params\n");
                (yyval)=cria_decl(Param);

        ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 114 "parser.y"
    {
                //printf("param_list\n");
                YYSTYPE aux = (yyvsp[(1) - (3)]);
                while(aux->irmaos != NULL){
                aux = aux->irmaos;
                }
                aux->irmaos = (yyvsp[(2) - (3)]);
                (yyval) = (yyvsp[(1) - (3)]);
        ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    {
                //printf("param_list\n");
                (yyval) = (yyvsp[(1) - (1)]);     
        ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    {
                //printf("param\n");
                (yyval) = (yyvsp[(1) - (2)]);
                (yyval)->str=strdup(lex->lexema);

        ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    {
                //printf("param\n");
                (yyval) = (yyvsp[(1) - (4)]);
                (yyval)->tipo_decl = Param;
                (yyval)->tipo_var = Array;
                (yyval)->str=strdup(lex->lexema);//nok
        ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    {
                //printf("composto_decl\n");
                (yyval)=cria_stmt(Comp);
                (yyval)->filhos[0]=(yyvsp[(2) - (4)]);
                (yyval)->filhos[1]=(yyvsp[(3) - (4)]);
                (yyval)->n_filhos = 2;

        ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    {
                //printf("local_declaracoes\n");
                YYSTYPE aux = (yyvsp[(1) - (2)]);
                if(aux == NULL)
                {
                        (yyval) = (yyvsp[(2) - (2)]);
                }
                else
                {
                        while(aux->irmaos != NULL){
                        aux = aux->irmaos;
                        }
                        aux->irmaos = (yyvsp[(2) - (2)]);
                        (yyval) = (yyvsp[(1) - (2)]);
                }
        ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    {
                //printf("local_declaracoes\n");
                (yyval) = NULL;
        ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    {
                //printf("statement_list\n");
                YYSTYPE aux = (yyvsp[(1) - (2)]);
                if(aux == NULL)
                {
                        (yyval) = (yyvsp[(2) - (2)]);
                }
                else
                {
                        while(aux->irmaos != NULL){
                        aux = aux->irmaos;
                        }
                        aux->irmaos = (yyvsp[(2) - (2)]);
                        (yyval) = (yyvsp[(1) - (2)]);
                }
        ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    {
                //printf("statement_list\n");
                (yyval) = NULL;
        ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 195 "parser.y"
    {
                //printf("statement\n");
                (yyval) = (yyvsp[(1) - (1)]);
        ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 199 "parser.y"
    {
                //printf("statement\n");
                (yyval) = (yyvsp[(1) - (1)]);
        ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 203 "parser.y"
    {
                //printf("statement\n");
                (yyval) = (yyvsp[(1) - (1)]);
        ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 207 "parser.y"
    {
                //printf("statement\n");
                (yyval) = (yyvsp[(1) - (1)]);
        ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    {
                //printf("statement\n");
                (yyval) = (yyvsp[(1) - (1)]);
        ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 217 "parser.y"
    {
                //printf("expressao_decl\n");
                (yyval) = (yyvsp[(1) - (2)]);
        ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 221 "parser.y"
    { 
                //printf("expressao_decl\n");
                (yyval) = NULL;
        ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 227 "parser.y"
    {
                //printf("selecao_decl\n");
                (yyval)=cria_stmt(If);
                (yyval)->filhos[0] = (yyvsp[(3) - (5)]);
                (yyval)->filhos[1] = (yyvsp[(5) - (5)]);
                (yyval)->n_filhos = 2;
        ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 234 "parser.y"
    {
                //printf("selecao_decl\n");
                (yyval)=cria_stmt(If);
                (yyval)->filhos[0] = (yyvsp[(3) - (7)]);
                (yyval)->filhos[1] = (yyvsp[(5) - (7)]);
                (yyval)->filhos[2] = (yyvsp[(7) - (7)]);
                (yyval)->n_filhos = 3;
        ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 244 "parser.y"
    {
                //printf("iteracao_decl\n");
                (yyval)=cria_stmt(While);
                (yyval)->filhos[0] = (yyvsp[(3) - (5)]);
                (yyval)->filhos[1] = (yyvsp[(5) - (5)]);
                (yyval)->n_filhos = 2;
        ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 253 "parser.y"
    {
                //printf("retorno_decl\n");
                (yyval)=cria_stmt(Return);
        ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 257 "parser.y"
    {
                //printf("retorno_decl\n");
                (yyval)=cria_stmt(Return);
                (yyval)->filhos[0] = (yyvsp[(2) - (3)]);
                (yyval)->n_filhos = 1;
        ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 265 "parser.y"
    {
                //printf("expressao\n");
                (yyval)=cria_exp(Op);
                (yyval)->str=strdup(lex->lexema);//nok
                (yyval)->filhos[0]=(yyvsp[(1) - (3)]);
                (yyval)->filhos[1]=(yyvsp[(3) - (3)]);
                (yyval)->n_filhos=2;
        ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 273 "parser.y"
    {
                //printf("expressao\n");
                (yyval)=(yyvsp[(1) - (1)]);
        ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 279 "parser.y"
    {
                //printf("var\n");
                (yyval)=cria_exp(Id);
                (yyval)->str=strdup(lex->lexema);//nok
        ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 284 "parser.y"
    {
                //printf("var\n");
                (yyval)=cria_exp(array);
                (yyval)->str=strdup(lex->lexema);//nok
        ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 288 "parser.y"
    {
                //printf("var\n");
                (yyval)=(yyvsp[(2) - (5)]);
                (yyval)->filhos[0]=(yyvsp[(4) - (5)]);
                (yyval)->n_filhos = 1;
        ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 296 "parser.y"
    {
                //printf("simples_expressao\n");
                (yyval) = (yyvsp[(2) - (3)]);
                (yyval)->filhos[0] = (yyvsp[(1) - (3)]);
                (yyval)->filhos[1] = (yyvsp[(3) - (3)]);
                (yyval)->n_filhos = 2;
        ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 303 "parser.y"
    {
                //printf("simples_expressao\n");
                (yyval) = (yyvsp[(1) - (1)]);
        ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 309 "parser.y"
    {
                //printf("relacao\n");
                (yyval)=cria_exp(Op);
                (yyval)->str=strdup(lex->lexema);//ok
        ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 314 "parser.y"
    {
                //printf("relacao\n");
                (yyval)=cria_exp(Op);
                (yyval)->str=strdup(lex->lexema);//ok
        ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 320 "parser.y"
    {
                //printf("relacao\n");
                (yyval)=cria_exp(Op);
                (yyval)->str=strdup(lex->lexema);//ok
        ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 326 "parser.y"
    {
                //printf("relacao\n");
                (yyval)=cria_exp(Op);
                (yyval)->str=strdup(lex->lexema);//ok
        ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 332 "parser.y"
    {
                //printf("relacao\n");
                (yyval)=cria_exp(Op);
                (yyval)->str=strdup(lex->lexema);//ok
        ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 338 "parser.y"
    {
                //printf("relacao\n");
                (yyval)=cria_exp(Op);
                (yyval)->str=strdup(lex->lexema);//ok
        ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 345 "parser.y"
    {
                //printf("soma_expressao\n");
                (yyval) = (yyvsp[(2) - (3)]);
                (yyval)->filhos[0] = (yyvsp[(1) - (3)]);
                (yyval)->filhos[1] = (yyvsp[(3) - (3)]);
                (yyval)->n_filhos = 2;
        ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 352 "parser.y"
    {
                //printf("soma_expressao\n");
                (yyval)=(yyvsp[(1) - (1)]);
        ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 358 "parser.y"
    {
                //printf("soma\n");
                (yyval)=cria_exp(Op);
                (yyval)->str=strdup(lex->lexema);//ok
        ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 364 "parser.y"
    {
                //printf("soma\n");
                (yyval)=cria_exp(Op);
                (yyval)->str=strdup(lex->lexema);//ok
        ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 371 "parser.y"
    {
                //printf("termo\n");
                (yyval)=(yyvsp[(2) - (3)]);
                (yyval)->filhos[0]=(yyvsp[(1) - (3)]);
                (yyval)->filhos[1]=(yyvsp[(3) - (3)]);
                (yyval)->n_filhos = 2;
        ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 378 "parser.y"
    {
                //printf("termo\n");
                (yyval) = (yyvsp[(1) - (1)]);
        ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 384 "parser.y"
    {
                //printf("mult\n");
                (yyval)=cria_exp(Op);
                (yyval)->str=strdup(lex->lexema);//ok
        ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 389 "parser.y"
    {
                //printf("mult\n");
                (yyval)=cria_exp(Op);
                (yyval)->str=strdup(lex->lexema);//ok
        ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 396 "parser.y"
    {
                //printf("fator\n");
                (yyval) = (yyvsp[(2) - (3)]);
        ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 400 "parser.y"
    {
                //printf("fator\n");
                (yyval) = (yyvsp[(1) - (1)]);
        ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 405 "parser.y"
    {
                //printf("fator\n");
                (yyval) = (yyvsp[(1) - (1)]);
        ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 410 "parser.y"
    {
                //printf("fator\n");
                (yyval)=cria_exp(Const);
                (yyval)->str=strdup(lex->lexema);//ok
        ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 417 "parser.y"
    {
                //printf("ativacao\n");
                (yyval)=cria_exp(Ativ);
                (yyval)->str=strdup(lex->lexema);//nok
        ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 421 "parser.y"
    {
                //printf("ativacao\n");
                (yyval)=(yyvsp[(2) - (5)]);
                (yyval)->filhos[0]=(yyvsp[(4) - (5)]);
                (yyval)->n_filhos = 1;
        ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 429 "parser.y"
    {
                //printf("args\n");
                (yyval) = (yyvsp[(1) - (1)]);
        ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 433 "parser.y"
    {
                //printf("args\n");
                (yyval) = NULL;
        ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 439 "parser.y"
    {
                //printf("arg_list\n");
                YYSTYPE aux = (yyvsp[(1) - (3)]);
                while(aux->irmaos != NULL){
                aux = aux->irmaos;
                }
                aux->irmaos = (yyvsp[(2) - (3)]);
                (yyval) = (yyvsp[(1) - (3)]);
        ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 448 "parser.y"
    {
                //printf("arg_list\n");
                (yyval) = (yyvsp[(1) - (1)]);
        ;}
    break;



/* Line 1455 of yacc.c  */
#line 2200 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 453 "parser.y"


int yylex() {
    return (get_token());
}

void yyerror(const char *s) {
    printf("Erro de sintaxe na linha %d\n", lex->linha);
}

AST_p parse()
{
        yyparse();
        return raiz;
}

