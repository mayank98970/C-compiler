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
#line 5 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"
#include "semantic.h"
#include "codegen.h"
#include "targetgen.h"

extern int yylex();
void yyerror(const char *s) { fprintf(stderr, "Error: %s\n", s); }

ASTNode *root;

#line 87 "parser.tab.c"

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
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_NUMBER = 5,                     /* NUMBER  */
  YYSYMBOL_FLOAT_LITERAL = 6,              /* FLOAT_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 7,               /* CHAR_LITERAL  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_INT = 10,                       /* INT  */
  YYSYMBOL_VOID = 11,                      /* VOID  */
  YYSYMBOL_FLOAT = 12,                     /* FLOAT  */
  YYSYMBOL_CHAR = 13,                      /* CHAR  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_BREAK = 17,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 18,                  /* CONTINUE  */
  YYSYMBOL_SCANF = 19,                     /* SCANF  */
  YYSYMBOL_PRINTF = 20,                    /* PRINTF  */
  YYSYMBOL_EQ = 21,                        /* EQ  */
  YYSYMBOL_NEQ = 22,                       /* NEQ  */
  YYSYMBOL_GT = 23,                        /* GT  */
  YYSYMBOL_LT = 24,                        /* LT  */
  YYSYMBOL_GTE = 25,                       /* GTE  */
  YYSYMBOL_LTE = 26,                       /* LTE  */
  YYSYMBOL_27_ = 27,                       /* '+'  */
  YYSYMBOL_28_ = 28,                       /* '-'  */
  YYSYMBOL_29_ = 29,                       /* '*'  */
  YYSYMBOL_30_ = 30,                       /* '/'  */
  YYSYMBOL_31_ = 31,                       /* '='  */
  YYSYMBOL_LOWER_THAN_ELSE = 32,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_33_ = 33,                       /* '('  */
  YYSYMBOL_34_ = 34,                       /* ')'  */
  YYSYMBOL_35_ = 35,                       /* ','  */
  YYSYMBOL_36_ = 36,                       /* '{'  */
  YYSYMBOL_37_ = 37,                       /* '}'  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_program = 41,                   /* program  */
  YYSYMBOL_functions = 42,                 /* functions  */
  YYSYMBOL_function = 43,                  /* function  */
  YYSYMBOL_enter_scope_marker = 44,        /* enter_scope_marker  */
  YYSYMBOL_type = 45,                      /* type  */
  YYSYMBOL_params = 46,                    /* params  */
  YYSYMBOL_param_list = 47,                /* param_list  */
  YYSYMBOL_param = 48,                     /* param  */
  YYSYMBOL_compound_stmt = 49,             /* compound_stmt  */
  YYSYMBOL_50_1 = 50,                      /* $@1  */
  YYSYMBOL_stmts = 51,                     /* stmts  */
  YYSYMBOL_stmt = 52,                      /* stmt  */
  YYSYMBOL_decl_stmt = 53,                 /* decl_stmt  */
  YYSYMBOL_expr_stmt = 54,                 /* expr_stmt  */
  YYSYMBOL_if_stmt = 55,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 56,                /* while_stmt  */
  YYSYMBOL_for_stmt = 57,                  /* for_stmt  */
  YYSYMBOL_for_init = 58,                  /* for_init  */
  YYSYMBOL_for_cond = 59,                  /* for_cond  */
  YYSYMBOL_for_incr = 60,                  /* for_incr  */
  YYSYMBOL_return_stmt = 61,               /* return_stmt  */
  YYSYMBOL_expression = 62,                /* expression  */
  YYSYMBOL_assignment_expression = 63,     /* assignment_expression  */
  YYSYMBOL_logical_expression = 64,        /* logical_expression  */
  YYSYMBOL_args = 65,                      /* args  */
  YYSYMBOL_arg_list = 66                   /* arg_list  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYLAST   168

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
       2,     2,     2,     2,     2,     2,     2,     2,    39,     2,
      33,    34,    29,    27,    35,    28,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       2,    31,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      25,    26,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    53,    53,    57,    63,    67,    74,    78,    79,    80,
      81,    85,    86,    90,    96,   100,   109,   109,   116,   117,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   137,
     143,   151,   157,   169,   173,   176,   182,   188,   209,   210,
     214,   218,   222,   226,   230,   233,   237,   240,   243,   246,
     249,   252,   255,   258,   261,   264,   267,   272,   273,   274,
     275,   276,   277,   278,   282,   283,   287,   293
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER", "STRING",
  "NUMBER", "FLOAT_LITERAL", "CHAR_LITERAL", "IF", "ELSE", "INT", "VOID",
  "FLOAT", "CHAR", "RETURN", "WHILE", "FOR", "BREAK", "CONTINUE", "SCANF",
  "PRINTF", "EQ", "NEQ", "GT", "LT", "GTE", "LTE", "'+'", "'-'", "'*'",
  "'/'", "'='", "LOWER_THAN_ELSE", "'('", "')'", "','", "'{'", "'}'",
  "';'", "'&'", "$accept", "program", "functions", "function",
  "enter_scope_marker", "type", "params", "param_list", "param",
  "compound_stmt", "$@1", "stmts", "stmt", "decl_stmt", "expr_stmt",
  "if_stmt", "while_stmt", "for_stmt", "for_init", "for_cond", "for_incr",
  "return_stmt", "expression", "assignment_expression",
  "logical_expression", "args", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-53)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      76,   -53,   -53,   -53,   -53,     3,    76,   -53,    30,   -53,
     -53,     5,    76,    49,    23,    31,   -53,   -53,   -53,    76,
      40,   -53,   -53,   -53,     1,    -8,   -53,   -53,   -53,   -53,
      61,    68,    62,    65,    64,    67,    66,    70,    77,    97,
     103,   -53,    71,     1,   -53,   -53,   -53,   -53,   -53,   -53,
      73,   -53,   110,    68,    68,    68,    74,    68,    57,   -53,
     -53,   105,   109,    81,    96,   -53,    27,   -53,   -53,   -53,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
     -53,   -53,    93,    80,    94,   -53,    95,   -53,   -53,    68,
     118,    68,   -53,    68,   -53,   120,   120,   120,   120,   120,
     120,     6,     6,   126,   126,   -53,    68,     1,     1,   -53,
      68,    68,   121,   116,   -53,   147,   -53,   123,   -53,    21,
     122,   -53,     1,     1,   124,   -53,   -53,   -53,   -53
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     7,     8,     9,    10,     0,     2,     4,     0,     1,
       3,     0,    11,     0,     0,    12,    14,    15,     6,     0,
       0,    13,    16,     5,    18,    59,    63,    60,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    18,    20,    21,    22,    23,    24,    25,
       0,    43,    45,     0,    64,     0,     0,     0,     0,    27,
      28,     0,     0,    59,     0,    56,     0,    17,    19,    33,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,    67,     0,    65,     0,    42,     0,    38,    39,     0,
       0,    64,    57,     0,    31,    50,    51,    52,    53,    54,
      55,    46,    47,    48,    49,    58,     0,     0,     0,    40,
       0,     0,     0,     0,    66,    34,    36,     0,    41,     0,
       0,    32,     0,     0,     0,    29,    35,    37,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -53,   -53,   -53,   152,   -53,    85,   -53,   -53,   140,   141,
     -53,   125,   -30,   106,   -36,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -31,   -52,   -28,    72,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,    20,    40,    14,    15,    16,    41,
      24,    42,    43,    44,    45,    46,    47,    48,    89,   110,
     117,    49,    50,    51,    52,    82,    83
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,    80,    81,     9,    25,    26,    27,    28,    29,    30,
      64,     1,     2,     3,     4,    31,    32,    33,    34,    35,
      36,    37,    88,    53,    84,    54,    86,    70,    71,    72,
      73,    74,    75,    11,    38,    78,    79,    22,    12,    81,
      39,   113,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    17,   109,   114,   124,   106,    18,    93,    81,
      25,    26,    27,    28,    29,    94,    19,     1,     2,     3,
       4,    25,    26,    27,    28,    29,    22,   115,   116,   118,
      63,    26,    27,    28,    29,     8,     1,     2,     3,     4,
      38,     8,   126,   127,    55,    57,    39,    13,    58,    61,
      65,    38,    59,    62,    13,    60,    66,    39,    67,    90,
      38,    69,    85,    91,    54,   106,    39,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,   105,   107,   108,
      92,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,   111,   121,   120,   122,   123,    10,    21,
     125,    23,   128,   112,    87,   119,     0,     0,    68
};

static const yytype_int8 yycheck[] =
{
      31,    53,    54,     0,     3,     4,     5,     6,     7,     8,
      38,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    58,    31,    55,    33,    57,    21,    22,    23,
      24,    25,    26,     3,    33,    29,    30,    36,    33,    91,
      39,    93,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     3,    89,   106,    34,    35,    34,    31,   111,
       3,     4,     5,     6,     7,    38,    35,    10,    11,    12,
      13,     3,     4,     5,     6,     7,    36,   107,   108,   110,
       3,     4,     5,     6,     7,     0,    10,    11,    12,    13,
      33,     6,   122,   123,    33,    33,    39,    12,    33,    33,
       3,    33,    38,    33,    19,    38,     3,    39,    37,     4,
      33,    38,    38,     4,    33,    35,    39,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    34,    34,    34,
      34,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    21,    22,    23,    24,    25,    26,    21,    22,    23,
      24,    25,    26,    35,    38,    34,     9,    34,     6,    19,
      38,    20,    38,    91,    58,   111,    -1,    -1,    43
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    11,    12,    13,    41,    42,    43,    45,     0,
      43,     3,    33,    45,    46,    47,    48,     3,    34,    35,
      44,    48,    36,    49,    50,     3,     4,     5,     6,     7,
       8,    14,    15,    16,    17,    18,    19,    20,    33,    39,
      45,    49,    51,    52,    53,    54,    55,    56,    57,    61,
      62,    63,    64,    31,    33,    33,    62,    33,    33,    38,
      38,    33,    33,     3,    64,     3,     3,    37,    51,    38,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      63,    63,    65,    66,    62,    38,    62,    53,    54,    58,
       4,     4,    34,    31,    38,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    34,    35,    34,    34,    54,
      59,    35,    65,    63,    63,    52,    52,    60,    62,    66,
      34,    38,     9,    34,    34,    38,    52,    52,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    44,    45,    45,    45,
      45,    46,    46,    47,    47,    48,    50,    49,    51,    51,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    53,    53,    54,    55,    55,    56,    57,    58,    58,
      59,    60,    61,    62,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    65,    65,    66,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     7,     0,     1,     1,     1,
       1,     0,     1,     3,     1,     2,     0,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     6,
       7,     3,     5,     2,     5,     7,     5,     7,     1,     1,
       1,     1,     3,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     4,     1,
       1,     1,     1,     1,     0,     1,     3,     1
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
  case 2: /* program: functions  */
#line 53 "parser.y"
              { root = (yyvsp[0].node); }
#line 1228 "parser.tab.c"
    break;

  case 3: /* functions: functions function  */
#line 57 "parser.y"
                       {
        ASTNode *last = (yyvsp[-1].node);
        while (last->next) last = last->next;
        last->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1239 "parser.tab.c"
    break;

  case 4: /* functions: function  */
#line 63 "parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1245 "parser.tab.c"
    break;

  case 5: /* function: type IDENTIFIER '(' params ')' enter_scope_marker compound_stmt  */
#line 67 "parser.y"
                                                                    {
        (yyval.node) = make_node(NODE_FUNCTION, (yyvsp[-3].node), (yyvsp[0].node));
        (yyval.node)->name = (yyvsp[-5].str);
    }
#line 1254 "parser.tab.c"
    break;

  case 6: /* enter_scope_marker: %empty  */
#line 74 "parser.y"
                { enter_scope(); (yyval.node) = NULL; }
#line 1260 "parser.tab.c"
    break;

  case 7: /* type: INT  */
#line 78 "parser.y"
           { (yyval.node) = make_type_node(TYPE_INT); }
#line 1266 "parser.tab.c"
    break;

  case 8: /* type: VOID  */
#line 79 "parser.y"
           { (yyval.node) = make_type_node(TYPE_VOID); }
#line 1272 "parser.tab.c"
    break;

  case 9: /* type: FLOAT  */
#line 80 "parser.y"
           { (yyval.node) = make_type_node(TYPE_FLOAT); }
#line 1278 "parser.tab.c"
    break;

  case 10: /* type: CHAR  */
#line 81 "parser.y"
           { (yyval.node) = make_type_node(TYPE_CHAR); }
#line 1284 "parser.tab.c"
    break;

  case 11: /* params: %empty  */
#line 85 "parser.y"
                { (yyval.node) = NULL; }
#line 1290 "parser.tab.c"
    break;

  case 12: /* params: param_list  */
#line 86 "parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1296 "parser.tab.c"
    break;

  case 13: /* param_list: param_list ',' param  */
#line 90 "parser.y"
                         {
        ASTNode *last = (yyvsp[-2].node);
        while (last->next) last = last->next;
        last->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
    }
#line 1307 "parser.tab.c"
    break;

  case 14: /* param_list: param  */
#line 96 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1313 "parser.tab.c"
    break;

  case 15: /* param: type IDENTIFIER  */
#line 100 "parser.y"
                    {
        (yyval.node) = make_node(NODE_DECL, NULL, NULL);
        (yyval.node)->name = (yyvsp[0].str);
        (yyval.node)->data_type = (yyvsp[-1].node)->data_type;
        insert_symbol((yyvsp[0].str), SYMBOL_VARIABLE, (yyvsp[-1].node)->data_type, (yyval.node));
    }
#line 1324 "parser.tab.c"
    break;

  case 16: /* $@1: %empty  */
#line 109 "parser.y"
        { enter_scope(); }
#line 1330 "parser.tab.c"
    break;

  case 17: /* compound_stmt: '{' $@1 stmts '}'  */
#line 109 "parser.y"
                                     {
        (yyval.node) = make_block((yyvsp[-1].node));
        exit_scope();
    }
#line 1339 "parser.tab.c"
    break;

  case 18: /* stmts: %empty  */
#line 116 "parser.y"
                { (yyval.node) = NULL; }
#line 1345 "parser.tab.c"
    break;

  case 19: /* stmts: stmt stmts  */
#line 117 "parser.y"
               {
        (yyval.node) = (yyvsp[-1].node);
        ASTNode *last = (yyvsp[-1].node);
        while (last && last->next) last = last->next;
        if (last) last->next = (yyvsp[0].node);
        else (yyval.node) = (yyvsp[0].node);
    }
#line 1357 "parser.tab.c"
    break;

  case 20: /* stmt: decl_stmt  */
#line 127 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1363 "parser.tab.c"
    break;

  case 21: /* stmt: expr_stmt  */
#line 128 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1369 "parser.tab.c"
    break;

  case 22: /* stmt: if_stmt  */
#line 129 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1375 "parser.tab.c"
    break;

  case 23: /* stmt: while_stmt  */
#line 130 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1381 "parser.tab.c"
    break;

  case 24: /* stmt: for_stmt  */
#line 131 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1387 "parser.tab.c"
    break;

  case 25: /* stmt: return_stmt  */
#line 132 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1393 "parser.tab.c"
    break;

  case 26: /* stmt: compound_stmt  */
#line 133 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1399 "parser.tab.c"
    break;

  case 27: /* stmt: BREAK ';'  */
#line 134 "parser.y"
                   { (yyval.node) = make_node(NODE_BREAK, NULL, NULL); }
#line 1405 "parser.tab.c"
    break;

  case 28: /* stmt: CONTINUE ';'  */
#line 135 "parser.y"
                   { (yyval.node) = make_node(NODE_CONTINUE, NULL, NULL); }
#line 1411 "parser.tab.c"
    break;

  case 29: /* stmt: PRINTF '(' STRING args ')' ';'  */
#line 137 "parser.y"
                                   {
        ASTNode *str = make_string((yyvsp[-3].str));
        if ((yyvsp[-2].node)) str->next = (yyvsp[-2].node);
        (yyval.node) = make_call("printf", str);
    }
#line 1421 "parser.tab.c"
    break;

  case 30: /* stmt: SCANF '(' STRING ',' arg_list ')' ';'  */
#line 143 "parser.y"
                                          {
        ASTNode *str = make_string((yyvsp[-4].str));
        str->next = (yyvsp[-2].node);
        (yyval.node) = make_call("scanf", str);
    }
#line 1431 "parser.tab.c"
    break;

  case 31: /* decl_stmt: type IDENTIFIER ';'  */
#line 151 "parser.y"
                        {
        (yyval.node) = make_node(NODE_DECL, NULL, NULL);
        (yyval.node)->name = (yyvsp[-1].str);
        (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        insert_symbol((yyvsp[-1].str), SYMBOL_VARIABLE, (yyvsp[-2].node)->data_type, (yyval.node));
    }
#line 1442 "parser.tab.c"
    break;

  case 32: /* decl_stmt: type IDENTIFIER '=' assignment_expression ';'  */
#line 157 "parser.y"
                                                  {
        ASTNode *decl = make_node(NODE_DECL, NULL, NULL);
        decl->name = (yyvsp[-3].str);
        decl->data_type = (yyvsp[-4].node)->data_type;
        insert_symbol((yyvsp[-3].str), SYMBOL_VARIABLE, (yyvsp[-4].node)->data_type, decl);
        ASTNode *assign = make_assign(make_var((yyvsp[-3].str)), (yyvsp[-1].node));
        decl->next = assign;
        (yyval.node) = decl;
    }
#line 1456 "parser.tab.c"
    break;

  case 33: /* expr_stmt: expression ';'  */
#line 169 "parser.y"
                   { (yyval.node) = (yyvsp[-1].node); }
#line 1462 "parser.tab.c"
    break;

  case 34: /* if_stmt: IF '(' expression ')' stmt  */
#line 173 "parser.y"
                                                     {
        (yyval.node) = make_if((yyvsp[-2].node), (yyvsp[0].node), NULL);
    }
#line 1470 "parser.tab.c"
    break;

  case 35: /* if_stmt: IF '(' expression ')' stmt ELSE stmt  */
#line 176 "parser.y"
                                         {
        (yyval.node) = make_if((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1478 "parser.tab.c"
    break;

  case 36: /* while_stmt: WHILE '(' expression ')' stmt  */
#line 182 "parser.y"
                                  {
        (yyval.node) = make_while((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1486 "parser.tab.c"
    break;

  case 37: /* for_stmt: FOR '(' for_init for_cond for_incr ')' stmt  */
#line 188 "parser.y"
                                                {
        ASTNode *init = (yyvsp[-4].node);
        ASTNode *cond = (yyvsp[-3].node);
        ASTNode *incr = (yyvsp[-2].node);
        ASTNode *body = make_block((yyvsp[0].node));

        ASTNode *last = body->left;
        if (last) {
            while (last->next) last = last->next;
            last->next = incr;
        } else {
            body->left = incr;
        }

        ASTNode *while_node = make_while(cond, body);
        if (init) init->next = while_node;
        (yyval.node) = init ? make_block(init) : while_node;
    }
#line 1509 "parser.tab.c"
    break;

  case 38: /* for_init: decl_stmt  */
#line 209 "parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1515 "parser.tab.c"
    break;

  case 39: /* for_init: expr_stmt  */
#line 210 "parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1521 "parser.tab.c"
    break;

  case 40: /* for_cond: expr_stmt  */
#line 214 "parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1527 "parser.tab.c"
    break;

  case 41: /* for_incr: expression  */
#line 218 "parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1533 "parser.tab.c"
    break;

  case 42: /* return_stmt: RETURN expression ';'  */
#line 222 "parser.y"
                          { (yyval.node) = make_return((yyvsp[-1].node)); }
#line 1539 "parser.tab.c"
    break;

  case 43: /* expression: assignment_expression  */
#line 226 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1545 "parser.tab.c"
    break;

  case 44: /* assignment_expression: IDENTIFIER '=' assignment_expression  */
#line 230 "parser.y"
                                         {
        (yyval.node) = make_assign(make_var((yyvsp[-2].str)), (yyvsp[0].node));
    }
#line 1553 "parser.tab.c"
    break;

  case 45: /* assignment_expression: logical_expression  */
#line 233 "parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1559 "parser.tab.c"
    break;

  case 46: /* logical_expression: logical_expression '+' logical_expression  */
#line 237 "parser.y"
                                              {
        (yyval.node) = make_expr(OP_ADD, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1567 "parser.tab.c"
    break;

  case 47: /* logical_expression: logical_expression '-' logical_expression  */
#line 240 "parser.y"
                                              {
        (yyval.node) = make_expr(OP_SUB, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1575 "parser.tab.c"
    break;

  case 48: /* logical_expression: logical_expression '*' logical_expression  */
#line 243 "parser.y"
                                              {
        (yyval.node) = make_expr(OP_MUL, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1583 "parser.tab.c"
    break;

  case 49: /* logical_expression: logical_expression '/' logical_expression  */
#line 246 "parser.y"
                                              {
        (yyval.node) = make_expr(OP_DIV, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1591 "parser.tab.c"
    break;

  case 50: /* logical_expression: logical_expression EQ logical_expression  */
#line 249 "parser.y"
                                             {
        (yyval.node) = make_expr(OP_EQ, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1599 "parser.tab.c"
    break;

  case 51: /* logical_expression: logical_expression NEQ logical_expression  */
#line 252 "parser.y"
                                              {
        (yyval.node) = make_expr(OP_NEQ, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1607 "parser.tab.c"
    break;

  case 52: /* logical_expression: logical_expression GT logical_expression  */
#line 255 "parser.y"
                                             {
        (yyval.node) = make_expr(OP_GT, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1615 "parser.tab.c"
    break;

  case 53: /* logical_expression: logical_expression LT logical_expression  */
#line 258 "parser.y"
                                             {
        (yyval.node) = make_expr(OP_LT, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1623 "parser.tab.c"
    break;

  case 54: /* logical_expression: logical_expression GTE logical_expression  */
#line 261 "parser.y"
                                              {
        (yyval.node) = make_expr(OP_GTE, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1631 "parser.tab.c"
    break;

  case 55: /* logical_expression: logical_expression LTE logical_expression  */
#line 264 "parser.y"
                                              {
        (yyval.node) = make_expr(OP_LTE, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1639 "parser.tab.c"
    break;

  case 56: /* logical_expression: '&' IDENTIFIER  */
#line 267 "parser.y"
                   {
        ASTNode *var = make_var((yyvsp[0].str));
        var->is_address = 1;  // ➕ You'll need to handle this in codegen
        (yyval.node) = var;
    }
#line 1649 "parser.tab.c"
    break;

  case 57: /* logical_expression: '(' logical_expression ')'  */
#line 272 "parser.y"
                               { (yyval.node) = (yyvsp[-1].node); }
#line 1655 "parser.tab.c"
    break;

  case 58: /* logical_expression: IDENTIFIER '(' args ')'  */
#line 273 "parser.y"
                            { (yyval.node) = make_call((yyvsp[-3].str), (yyvsp[-1].node)); }
#line 1661 "parser.tab.c"
    break;

  case 59: /* logical_expression: IDENTIFIER  */
#line 274 "parser.y"
               { (yyval.node) = make_var((yyvsp[0].str)); }
#line 1667 "parser.tab.c"
    break;

  case 60: /* logical_expression: NUMBER  */
#line 275 "parser.y"
           { (yyval.node) = make_num((yyvsp[0].num)); }
#line 1673 "parser.tab.c"
    break;

  case 61: /* logical_expression: FLOAT_LITERAL  */
#line 276 "parser.y"
                  { (yyval.node) = make_float((yyvsp[0].fnum)); }
#line 1679 "parser.tab.c"
    break;

  case 62: /* logical_expression: CHAR_LITERAL  */
#line 277 "parser.y"
                 { (yyval.node) = make_char((yyvsp[0].cval)); }
#line 1685 "parser.tab.c"
    break;

  case 63: /* logical_expression: STRING  */
#line 278 "parser.y"
           { (yyval.node) = make_string((yyvsp[0].str)); }
#line 1691 "parser.tab.c"
    break;

  case 64: /* args: %empty  */
#line 282 "parser.y"
                { (yyval.node) = NULL; }
#line 1697 "parser.tab.c"
    break;

  case 65: /* args: arg_list  */
#line 283 "parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1703 "parser.tab.c"
    break;

  case 66: /* arg_list: arg_list ',' assignment_expression  */
#line 287 "parser.y"
                                       {
        ASTNode *last = (yyvsp[-2].node);
        while (last->next) last = last->next;
        last->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
    }
#line 1714 "parser.tab.c"
    break;

  case 67: /* arg_list: assignment_expression  */
#line 293 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1720 "parser.tab.c"
    break;


#line 1724 "parser.tab.c"

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

#line 296 "parser.y"

int main() {
    printf("Parsing...\n");

    if (yyparse() == 0) {
        printf("Parsing complete.\n");

        if (root) {
            print_ast(root, 0);

            perform_semantic_analysis(root);

            // Generate TAC to output.tac
            FILE *out = fopen("output.tac", "w");
            if (!out) {
                fprintf(stderr, "Could not open output.tac for writing\n");
                return 1;
            }
            generate_code(root, out);  // ✅ generate TAC
            fclose(out);

            // Generate target assembly code from TAC
            generate_target_code("output.tac", "target.asm");
        } else {
            printf("No AST generated.\n");
        }
    } else {
        fprintf(stderr, "Syntax Error in input\n");
    }

    return 0;
}
