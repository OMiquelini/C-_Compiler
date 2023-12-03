/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include "scanner.h"
#include "stdio.h"
#include "stdlib.h"



#line 79 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMERO = 3,                     /* NUMERO  */
  YYSYMBOL_IDENTIFICADOR = 4,              /* IDENTIFICADOR  */
  YYSYMBOL_MAIS = 5,                       /* MAIS  */
  YYSYMBOL_MAIOR = 6,                      /* MAIOR  */
  YYSYMBOL_ATRIBUICAO = 7,                 /* ATRIBUICAO  */
  YYSYMBOL_DIVISAO = 8,                    /* DIVISAO  */
  YYSYMBOL_MENOS = 9,                      /* MENOS  */
  YYSYMBOL_MULTIPLICACAO = 10,             /* MULTIPLICACAO  */
  YYSYMBOL_L_PAR = 11,                     /* L_PAR  */
  YYSYMBOL_R_PAR = 12,                     /* R_PAR  */
  YYSYMBOL_L_CHAVES = 13,                  /* L_CHAVES  */
  YYSYMBOL_R_CHAVES = 14,                  /* R_CHAVES  */
  YYSYMBOL_L_BRAC = 15,                    /* L_BRAC  */
  YYSYMBOL_R_BRAC = 16,                    /* R_BRAC  */
  YYSYMBOL_COMMA = 17,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 18,                 /* SEMICOLON  */
  YYSYMBOL_MENOR = 19,                     /* MENOR  */
  YYSYMBOL_MAIOR_IGUAL = 20,               /* MAIOR_IGUAL  */
  YYSYMBOL_MENOR_IGUAL = 21,               /* MENOR_IGUAL  */
  YYSYMBOL_DIFERENTE = 22,                 /* DIFERENTE  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_INT = 24,                       /* INT  */
  YYSYMBOL_ELSE = 25,                      /* ELSE  */
  YYSYMBOL_VOID = 26,                      /* VOID  */
  YYSYMBOL_WHILE = 27,                     /* WHILE  */
  YYSYMBOL_RETURN = 28,                    /* RETURN  */
  YYSYMBOL_YYACCEPT = 29,                  /* $accept  */
  YYSYMBOL_programa = 30,                  /* programa  */
  YYSYMBOL_declaracao_lista = 31,          /* declaracao_lista  */
  YYSYMBOL_declaracao = 32,                /* declaracao  */
  YYSYMBOL_var_declaracao = 33,            /* var_declaracao  */
  YYSYMBOL_tipo_especificador = 34,        /* tipo_especificador  */
  YYSYMBOL_fun_declaracao = 35,            /* fun_declaracao  */
  YYSYMBOL_params = 36,                    /* params  */
  YYSYMBOL_param_list = 37,                /* param_list  */
  YYSYMBOL_param = 38,                     /* param  */
  YYSYMBOL_composto_decl = 39,             /* composto_decl  */
  YYSYMBOL_local_declaracoes = 40,         /* local_declaracoes  */
  YYSYMBOL_statement_list = 41,            /* statement_list  */
  YYSYMBOL_statement = 42,                 /* statement  */
  YYSYMBOL_expressao_decl = 43,            /* expressao_decl  */
  YYSYMBOL_selecao_decl = 44,              /* selecao_decl  */
  YYSYMBOL_iteracao_decl = 45,             /* iteracao_decl  */
  YYSYMBOL_retorno_decl = 46,              /* retorno_decl  */
  YYSYMBOL_expressao = 47,                 /* expressao  */
  YYSYMBOL_var = 48,                       /* var  */
  YYSYMBOL_simples_expressao = 49,         /* simples_expressao  */
  YYSYMBOL_relacional = 50,                /* relacional  */
  YYSYMBOL_soma_expressao = 51,            /* soma_expressao  */
  YYSYMBOL_soma = 52,                      /* soma  */
  YYSYMBOL_termo = 53,                     /* termo  */
  YYSYMBOL_mult = 54,                      /* mult  */
  YYSYMBOL_fator = 55,                     /* fator  */
  YYSYMBOL_ativacao = 56,                  /* ativacao  */
  YYSYMBOL_args = 57,                      /* args  */
  YYSYMBOL_arg_list = 58                   /* arg_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   99

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  102

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    25,    25,    31,    34,    38,    41,    45,    48,    52,
      55,    59,    63,    66,    70,    73,    77,    80,    84,    88,
      91,    95,    98,   102,   105,   109,   113,   117,   121,   124,
     128,   131,   135,   139,   144,   150,   155,   159,   164,   170,
     175,   179,   182,   186,   190,   194,   198,   202,   207,   211,
     215,   219,   224,   228,   231,   235,   238,   242,   246,   252,
     258,   261,   265,   270
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMERO",
  "IDENTIFICADOR", "MAIS", "MAIOR", "ATRIBUICAO", "DIVISAO", "MENOS",
  "MULTIPLICACAO", "L_PAR", "R_PAR", "L_CHAVES", "R_CHAVES", "L_BRAC",
  "R_BRAC", "COMMA", "SEMICOLON", "MENOR", "MAIOR_IGUAL", "MENOR_IGUAL",
  "DIFERENTE", "IF", "INT", "ELSE", "VOID", "WHILE", "RETURN", "$accept",
  "programa", "declaracao_lista", "declaracao", "var_declaracao",
  "tipo_especificador", "fun_declaracao", "params", "param_list", "param",
  "composto_decl", "local_declaracoes", "statement_list", "statement",
  "expressao_decl", "selecao_decl", "iteracao_decl", "retorno_decl",
  "expressao", "var", "simples_expressao", "relacional", "soma_expressao",
  "soma", "termo", "mult", "fator", "ativacao", "args", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      18,   -93,   -93,    10,    18,   -93,   -93,    13,   -93,   -93,
     -93,    19,    42,    30,   -93,    29,    46,    39,    54,   -93,
      41,    58,    43,    18,    56,    59,   -93,   -93,   -93,   -93,
     -93,    18,   -93,    72,    -2,     0,   -93,    20,     3,   -93,
     -93,    66,    67,    36,   -93,   -93,   -93,   -93,   -93,   -93,
      61,    73,   -93,    40,    62,   -93,   -93,     3,     3,    69,
       3,     3,   -93,    64,   -93,     3,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,     3,     3,   -93,   -93,     3,   -93,
      71,    68,    70,   -93,    75,    76,   -93,   -93,   -93,    60,
      62,   -93,   -93,     3,   -93,    25,    25,   -93,    65,   -93,
      25,   -93
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,     0,     0,     0,     7,    10,     0,     0,    12,    15,
       0,    16,     0,     0,     0,     0,    20,    11,    14,     8,
      17,    22,    19,     0,     0,     0,    58,    37,     0,    18,
      29,     0,     0,     0,    24,    21,    23,    25,    26,    27,
       0,    56,    36,    40,    48,    52,    57,    61,     0,     0,
       0,     0,    33,     0,    28,     0,    49,    42,    50,    46,
      41,    45,    43,    44,     0,     0,    54,    53,     0,    63,
       0,    60,     0,    55,     0,     0,    34,    35,    56,    39,
      47,    51,    59,     0,    38,     0,     0,    62,    30,    32,
       0,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -93,   -93,   -93,    80,    63,     1,   -93,   -93,   -93,    74,
      77,   -93,   -93,   -92,   -93,   -93,   -93,   -93,   -38,   -11,
     -93,   -93,    15,   -93,    16,   -93,    14,   -93,   -93,   -93
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    17,    18,    19,
      44,    31,    34,    45,    46,    47,    48,    49,    50,    51,
      52,    74,    53,    75,    54,    78,    55,    56,    80,    81
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      59,    36,    37,    98,    99,    63,    36,    37,   101,    38,
       9,    26,    39,    16,    38,    13,    40,    11,    14,    79,
      82,    41,    84,    85,    16,    42,    43,    87,    36,    37,
      12,    57,    33,    20,    13,    58,    38,    14,    26,    36,
      37,   -13,     1,    40,     2,    66,    67,    38,    41,    68,
      21,    22,    42,    43,    62,    97,    26,    24,    69,    70,
      71,    72,    73,    88,    88,    66,     1,    88,    15,    68,
      76,    23,    77,    25,    29,    30,    35,    60,    61,    64,
      65,    83,    86,    92,    10,    93,    94,    95,    96,    89,
     100,    90,    91,     0,    32,     0,     0,    28,     0,    27
};

static const yytype_int8 yycheck[] =
{
      38,     3,     4,    95,    96,    43,     3,     4,   100,    11,
       0,    13,    14,    12,    11,    15,    18,     4,    18,    57,
      58,    23,    60,    61,    23,    27,    28,    65,     3,     4,
      11,    11,    31,     3,    15,    15,    11,    18,    13,     3,
       4,    12,    24,    18,    26,     5,     6,    11,    23,     9,
       4,    12,    27,    28,    18,    93,    13,    16,    18,    19,
      20,    21,    22,    74,    75,     5,    24,    78,    26,     9,
       8,    17,    10,    15,    18,    16,     4,    11,    11,    18,
       7,    12,    18,    12,     4,    17,    16,    12,    12,    74,
      25,    75,    78,    -1,    31,    -1,    -1,    23,    -1,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    24,    26,    30,    31,    32,    33,    34,    35,     0,
      32,     4,    11,    15,    18,    26,    34,    36,    37,    38,
       3,     4,    12,    17,    16,    15,    13,    39,    38,    18,
      16,    40,    33,    34,    41,     4,     3,     4,    11,    14,
      18,    23,    27,    28,    39,    42,    43,    44,    45,    46,
      47,    48,    49,    51,    53,    55,    56,    11,    15,    47,
      11,    11,    18,    47,    18,     7,     5,     6,     9,    18,
      19,    20,    21,    22,    50,    52,     8,    10,    54,    47,
      57,    58,    47,    12,    47,    47,    18,    47,    48,    51,
      53,    55,    12,    17,    16,    12,    12,    47,    42,    42,
      25,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    29,    30,    31,    31,    32,    32,    33,    33,    34,
      34,    35,    36,    36,    37,    37,    38,    38,    39,    40,
      40,    41,    41,    42,    42,    42,    42,    42,    43,    43,
      44,    44,    45,    46,    46,    47,    47,    48,    48,    49,
      49,    50,    50,    50,    50,    50,    50,    51,    51,    52,
      52,    53,    53,    54,    54,    55,    55,    55,    55,    56,
      57,    57,    58,    58
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     1,     3,     1,     2,     4,     4,     2,
       0,     2,     0,     1,     1,     1,     1,     1,     2,     1,
       5,     7,     5,     2,     3,     3,     1,     1,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     4,
       1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* programa: declaracao_lista  */
#line 25 "parser.y"
                           {
    (yyval.node) = create_node("programa", 1, (yyvsp[0].node));
    printTree((yyval.node), 0);
    freeTree((yyval.node));
}
#line 1196 "parser.tab.c"
    break;

  case 3: /* declaracao_lista: declaracao_lista declaracao  */
#line 31 "parser.y"
                                              {
    (yyval.node) = create_node("declaracao_lista", 2, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1204 "parser.tab.c"
    break;

  case 4: /* declaracao_lista: declaracao  */
#line 34 "parser.y"
             { //arrumei aqui
    (yyval.node) = create_node("declaracao_lista", 0);
}
#line 1212 "parser.tab.c"
    break;

  case 5: /* declaracao: var_declaracao  */
#line 38 "parser.y"
                           {
    (yyval.node) = (yyvsp[0].node);
}
#line 1220 "parser.tab.c"
    break;

  case 6: /* declaracao: fun_declaracao  */
#line 41 "parser.y"
                 {
    (yyval.node) = (yyvsp[0].node);
}
#line 1228 "parser.tab.c"
    break;

  case 7: /* var_declaracao: tipo_especificador IDENTIFICADOR SEMICOLON  */
#line 45 "parser.y"
                                                           {
    (yyval.node) = create_node("var_declaracao", 2, create_node((yyvsp[-2].node), NULL, NULL), create_node((yyvsp[-1].int), NULL, NULL));
}
#line 1236 "parser.tab.c"
    break;

  case 8: /* var_declaracao: tipo_especificador IDENTIFICADOR L_BRAC NUMERO R_BRAC SEMICOLON  */
#line 48 "parser.y"
                                                                  {
    (yyval.node) = create_node("var_declaracao", 3, create_node((yyvsp[-5].node), NULL, NULL), create_node((yyvsp[-4].int), NULL, NULL), create_node((yyvsp[-2].int), NULL, NULL));
}
#line 1244 "parser.tab.c"
    break;

  case 9: /* tipo_especificador: INT  */
#line 52 "parser.y"
                        {
    (yyval.node) = create_node("tipo_especificador", 1, create_node((yyvsp[0].int), NULL, NULL));
}
#line 1252 "parser.tab.c"
    break;

  case 10: /* tipo_especificador: VOID  */
#line 55 "parser.y"
       {
    (yyval.node) = create_node("tipo_especificador", 1, create_node((yyvsp[0].int), NULL, NULL));
}
#line 1260 "parser.tab.c"
    break;

  case 11: /* fun_declaracao: tipo_especificador IDENTIFICADOR L_PAR params R_PAR composto_decl  */
#line 59 "parser.y"
                                                                                  {
    (yyval.node) = create_node("fun_declaracao", 3, create_node((yyvsp[-5].node), NULL, NULL), create_node((yyvsp[-4].int), NULL, NULL), (yyvsp[-2].node), (yyvsp[0].node));
}
#line 1268 "parser.tab.c"
    break;

  case 12: /* params: param_list  */
#line 63 "parser.y"
                   {
    (yyval.node) = create_node("params", 1, (yyvsp[0].node));
}
#line 1276 "parser.tab.c"
    break;

  case 13: /* params: VOID  */
#line 66 "parser.y"
       {
    (yyval.node) = create_node("params", 1, create_node((yyvsp[0].int), NULL, NULL));
}
#line 1284 "parser.tab.c"
    break;

  case 14: /* param_list: param_list COMMA param  */
#line 70 "parser.y"
                                   {
    (yyval.node) = create_node("param_list", 2, (yyvsp[-2].node), (yyvsp[0].node));
}
#line 1292 "parser.tab.c"
    break;

  case 15: /* param_list: param  */
#line 73 "parser.y"
        {
    (yyval.node) = create_node("param_list", 1, (yyvsp[0].node));
}
#line 1300 "parser.tab.c"
    break;

  case 16: /* param: tipo_especificador IDENTIFICADOR  */
#line 77 "parser.y"
                                         {
    (yyval.node) = create_node("param", 2, create_node((yyvsp[-1].node), NULL, NULL), create_node((yyvsp[0].int), NULL, NULL));
}
#line 1308 "parser.tab.c"
    break;

  case 17: /* param: tipo_especificador IDENTIFICADOR L_BRAC R_BRAC  */
#line 80 "parser.y"
                                                 {
    (yyval.node) = create_node("param", 3, create_node((yyvsp[-3].node), NULL, NULL), create_node((yyvsp[-2].int), NULL, NULL));
}
#line 1316 "parser.tab.c"
    break;

  case 18: /* composto_decl: L_CHAVES local_declaracoes statement_list R_CHAVES  */
#line 84 "parser.y"
                                                                  {
    (yyval.node) = create_node("composto_decl", 2, (yyvsp[-2].node), (yyvsp[-1].node));
}
#line 1324 "parser.tab.c"
    break;

  case 19: /* local_declaracoes: local_declaracoes var_declaracao  */
#line 88 "parser.y"
                                                    {
    (yyval.node) = create_node("local_declaracoes", 2, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1332 "parser.tab.c"
    break;

  case 20: /* local_declaracoes: %empty  */
#line 91 "parser.y"
              {
    (yyval.node) = create_node("local_declaracoes", 0);
}
#line 1340 "parser.tab.c"
    break;

  case 21: /* statement_list: statement_list statement  */
#line 95 "parser.y"
                                         {
    (yyval.node) = create_node("statement_list", 2, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1348 "parser.tab.c"
    break;

  case 22: /* statement_list: %empty  */
#line 98 "parser.y"
              {
    (yyval.node) = create_node("statement_list", 0);
}
#line 1356 "parser.tab.c"
    break;

  case 23: /* statement: expressao_decl  */
#line 102 "parser.y"
                          {
    (yyval.node) = (yyvsp[0].node);
}
#line 1364 "parser.tab.c"
    break;

  case 24: /* statement: composto_decl  */
#line 105 "parser.y"
                {
    (yyval.node) = (yyvsp[0].node);
}
#line 1372 "parser.tab.c"
    break;

  case 25: /* statement: selecao_decl  */
#line 109 "parser.y"
               {
    (yyval.node) = (yyvsp[0].node);
}
#line 1380 "parser.tab.c"
    break;

  case 26: /* statement: iteracao_decl  */
#line 113 "parser.y"
                {
    (yyval.node) = (yyvsp[0].node);
}
#line 1388 "parser.tab.c"
    break;

  case 27: /* statement: retorno_decl  */
#line 117 "parser.y"
               {
    (yyval.node) = (yyvsp[0].node);
}
#line 1396 "parser.tab.c"
    break;

  case 28: /* expressao_decl: expressao SEMICOLON  */
#line 121 "parser.y"
                                    {
    (yyval.node) = create_node("expressao_decl", 1, (yyvsp[-1].node));
}
#line 1404 "parser.tab.c"
    break;

  case 29: /* expressao_decl: SEMICOLON  */
#line 124 "parser.y"
            { 
    (yyval.node) = create_node("expressao_decl", 0);
}
#line 1412 "parser.tab.c"
    break;

  case 30: /* selecao_decl: IF L_PAR expressao R_PAR statement  */
#line 128 "parser.y"
                                                 {
    (yyval.node) = create_node("selecao_decl", 2, (yyvsp[-2].node), (yyvsp[0].node));
}
#line 1420 "parser.tab.c"
    break;

  case 31: /* selecao_decl: IF L_PAR expressao R_PAR statement ELSE statement  */
#line 131 "parser.y"
                                                    {
    (yyval.node) = create_node("selecao_decl", 3, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
}
#line 1428 "parser.tab.c"
    break;

  case 32: /* iteracao_decl: WHILE L_PAR expressao R_PAR statement  */
#line 135 "parser.y"
                                                     {
    (yyval.node) = create_node("iteracao_decl", 2, (yyvsp[-2].node), (yyvsp[0].node));
}
#line 1436 "parser.tab.c"
    break;

  case 33: /* retorno_decl: RETURN SEMICOLON  */
#line 139 "parser.y"
                               {
    (yyval.node) = create_node("retorno_decl", 0);
    printTree((yyval.node), 0);
    freeTree((yyval.node));
}
#line 1446 "parser.tab.c"
    break;

  case 34: /* retorno_decl: RETURN expressao SEMICOLON  */
#line 144 "parser.y"
                             {
    (yyval.node) = create_node("retorno_decl", 1, (yyvsp[-1].node));
    printTree((yyval.node), 0);
    freeTree((yyval.node));
}
#line 1456 "parser.tab.c"
    break;

  case 35: /* expressao: var ATRIBUICAO expressao  */
#line 150 "parser.y"
                                    {
    (yyval.node) = create_node("expressao", 2, (yyvsp[-2].node), (yyvsp[0].node));
    printTree((yyval.node), 0);
    freeTree((yyval.node));
}
#line 1466 "parser.tab.c"
    break;

  case 36: /* expressao: simples_expressao  */
#line 155 "parser.y"
                    {
    (yyval.node) = (yyvsp[0].node);
}
#line 1474 "parser.tab.c"
    break;

  case 37: /* var: IDENTIFICADOR  */
#line 159 "parser.y"
                   {
    (yyval.node) = create_node("var", 1, create_node((yyvsp[0].int), NULL, NULL));
    printTree((yyval.node), 0);
    freeTree((yyval.node));
}
#line 1484 "parser.tab.c"
    break;

  case 38: /* var: IDENTIFICADOR L_BRAC expressao R_BRAC  */
#line 164 "parser.y"
                                        {
    (yyval.node) = create_node("ArrayVar", 2, create_node((yyvsp[-3].int), NULL, NULL), (yyvsp[-1].node));
    printTree((yyval.node), 0);
    freeTree((yyval.node));
}
#line 1494 "parser.tab.c"
    break;

  case 39: /* simples_expressao: soma_expressao relacional soma_expressao  */
#line 170 "parser.y"
                                                            {
    (yyval.node) = create_node("simples_expressao", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    printTree((yyval.node), 0);
    freeTree((yyval.node));
}
#line 1504 "parser.tab.c"
    break;

  case 40: /* simples_expressao: soma_expressao  */
#line 175 "parser.y"
                 {
    (yyval.node) = (yyvsp[0].node);
}
#line 1512 "parser.tab.c"
    break;

  case 41: /* relacional: MENOR  */
#line 179 "parser.y"
                  {
    (yyval.node) = create_node("relacional", 1, create_node((yyvsp[0].int), NULL, NULL));
}
#line 1520 "parser.tab.c"
    break;

  case 42: /* relacional: MAIOR  */
#line 182 "parser.y"
        {
    (yyval.node) = create_node("relacional", 1, create_node((yyvsp[0].int), NULL, NULL));
}
#line 1528 "parser.tab.c"
    break;

  case 43: /* relacional: MENOR_IGUAL  */
#line 186 "parser.y"
              {
    (yyval.node) = create_node("relacional", 1, create_node((yyvsp[0].int), NULL, NULL));
}
#line 1536 "parser.tab.c"
    break;

  case 44: /* relacional: DIFERENTE  */
#line 190 "parser.y"
            {
    (yyval.node) = create_node("relacional", 1, create_node((yyvsp[0].int), NULL, NULL));
}
#line 1544 "parser.tab.c"
    break;

  case 45: /* relacional: MAIOR_IGUAL  */
#line 194 "parser.y"
              {
    (yyval.node) = create_node("relacional", 1, create_node((yyvsp[0].int), NULL, NULL));
}
#line 1552 "parser.tab.c"
    break;

  case 46: /* relacional: SEMICOLON  */
#line 198 "parser.y"
            { //fazer == aqui
    (yyval.node) = create_node("relacional", 0);
}
#line 1560 "parser.tab.c"
    break;

  case 47: /* soma_expressao: soma_expressao soma termo  */
#line 202 "parser.y"
                                          {
    (yyval.node) = create_node("soma_expressao", 2, (yyvsp[-2].node), (yyvsp[0].node));
    printTree((yyval.node), 0);
    freeTree((yyval.node));
}
#line 1570 "parser.tab.c"
    break;

  case 48: /* soma_expressao: termo  */
#line 207 "parser.y"
        {
    (yyval.node) = (yyvsp[0].node);
}
#line 1578 "parser.tab.c"
    break;

  case 49: /* soma: MAIS  */
#line 211 "parser.y"
           {
    (yyval.node) = create_node("soma", 1, create_node((yyvsp[0].int), NULL, NULL));
}
#line 1586 "parser.tab.c"
    break;

  case 50: /* soma: MENOS  */
#line 215 "parser.y"
        {
    (yyval.node) = create_node("soma", 1, create_node((yyvsp[0].int), NULL, NULL));
}
#line 1594 "parser.tab.c"
    break;

  case 51: /* termo: termo mult fator  */
#line 219 "parser.y"
                        {
    (yyval.node) = create_node("termo", 2, (yyvsp[-2].node), (yyvsp[0].node));
    printTree((yyval.node), 0);
    freeTree((yyval.node));
}
#line 1604 "parser.tab.c"
    break;

  case 52: /* termo: fator  */
#line 224 "parser.y"
        {
    (yyval.node) = (yyvsp[0].node);
}
#line 1612 "parser.tab.c"
    break;

  case 53: /* mult: MULTIPLICACAO  */
#line 228 "parser.y"
                    {
    (yyval.node) = create_node("mult", 0);
}
#line 1620 "parser.tab.c"
    break;

  case 54: /* mult: DIVISAO  */
#line 231 "parser.y"
          {
    (yyval.node) = create_node("div", 0);
}
#line 1628 "parser.tab.c"
    break;

  case 55: /* fator: L_PAR expressao R_PAR  */
#line 235 "parser.y"
                             {
    (yyval.node) = (yyvsp[-1].node);
}
#line 1636 "parser.tab.c"
    break;

  case 56: /* fator: var  */
#line 238 "parser.y"
      {
    (yyval.node) = (yyvsp[0].node);
}
#line 1644 "parser.tab.c"
    break;

  case 57: /* fator: ativacao  */
#line 242 "parser.y"
           {
    (yyval.node) = (yyvsp[0].node);
}
#line 1652 "parser.tab.c"
    break;

  case 58: /* fator: NUMERO  */
#line 246 "parser.y"
         {
    (yyval.node) = create_node("NUMERO", 1, create_node((yyvsp[0].int), NULL, NULL));
    printTree((yyval.node), 0);
    freeTree((yyval.node));
}
#line 1662 "parser.tab.c"
    break;

  case 59: /* ativacao: IDENTIFICADOR L_PAR args R_PAR  */
#line 252 "parser.y"
                                         {
    (yyval.node) = create_node("ativacao", 2, create_node((yyvsp[-3].int), NULL, NULL), (yyvsp[-1].node));
    printTree((yyval.node), 0);
    freeTree((yyval.node));
}
#line 1672 "parser.tab.c"
    break;

  case 60: /* args: arg_list  */
#line 258 "parser.y"
               {
    (yyval.node) = create_node("args", 1, (yyvsp[0].node));
}
#line 1680 "parser.tab.c"
    break;

  case 61: /* args: %empty  */
#line 261 "parser.y"
              {
    (yyval.node) = create_node("args", 0);
}
#line 1688 "parser.tab.c"
    break;

  case 62: /* arg_list: arg_list COMMA expressao  */
#line 265 "parser.y"
                                   {
    (yyval.node) = create_node("arg_list", 2, (yyvsp[-2].node), (yyvsp[0].node));
    printTree((yyval.node), 0);
    freeTree((yyval.node));
}
#line 1698 "parser.tab.c"
    break;

  case 63: /* arg_list: expressao  */
#line 270 "parser.y"
            {
    (yyval.node) = create_node("arg_list", 1, (yyvsp[0].node));
    printTree((yyval.node), 0);
    freeTree((yyval.node));
}
#line 1708 "parser.tab.c"
    break;


#line 1712 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 276 "parser.y"


int main() {
    yyparse();
    return 0;
}

void yylex() {
    yylval.token_info = get_token();
}

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
}
