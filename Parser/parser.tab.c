/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 12 "parser.y" /* yacc.c:339  */

     #include <stdio.h>
     #include <stdlib.h>
     #include "ast.h"
     #define YYSTYPE Node *
     Node *root = NULL; //radice dell'albero sintattico astratto
     extern Lexval lexval;
     extern char *yytext;
     extern int num_line;

#line 77 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MODULE = 258,
    ID = 259,
    TYPE = 260,
    VAR = 261,
    CONST = 262,
    START = 263,
    END = 264,
    IF = 265,
    THEN = 266,
    ELSIF = 267,
    ELSE = 268,
    WHILE = 269,
    DO = 270,
    ERROR = 271,
    PLUS = 272,
    MINUS = 273,
    MULT = 274,
    DIV = 275,
    RETURN = 276,
    READ = 277,
    WRITE = 278,
    AND = 279,
    OR = 280,
    NOT = 281,
    EQ = 282,
    NEQ = 283,
    GE = 284,
    GT = 285,
    LE = 286,
    LT = 287,
    INTCONST = 288,
    REALCONST = 289,
    CHARCONST = 290,
    STRCONST = 291,
    BOOLCONST = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 166 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   144

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

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
      38,    39,     2,     2,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    42,
       2,    43,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    47,    47,    50,    50,    50,    65,    66,    69,    70,
      73,    73,    76,    77,    80,    81,    84,    87,    87,    88,
      91,    92,    95,    96,    99,   102,   103,   106,   106,   110,
     111,   114,   115,   116,   117,   118,   119,   120,   123,   123,
     126,   131,   133,   136,   137,   140,   143,   146,   147,   150,
     153,   156,   157,   160,   161,   164,   165,   168,   169,   172,
     173,   174,   175,   176,   177,   180,   181,   184,   185,   188,
     189,   192,   193,   196,   197,   198,   199,   200,   201,   202,
     202,   205,   206,   209,   210,   211,   212,   213,   216,   216,
     219,   220,   223,   227,   228
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MODULE", "ID", "TYPE", "VAR", "CONST",
  "START", "END", "IF", "THEN", "ELSIF", "ELSE", "WHILE", "DO", "ERROR",
  "PLUS", "MINUS", "MULT", "DIV", "RETURN", "READ", "WRITE", "AND", "OR",
  "NOT", "EQ", "NEQ", "GE", "GT", "LE", "LT", "INTCONST", "REALCONST",
  "CHARCONST", "STRCONST", "BOOLCONST", "'('", "')'", "':'", "','", "';'",
  "'='", "$accept", "program", "module-decl", "@1", "@2", "opt-param-list",
  "param-list", "param-decl", "@3", "opt-var-sect", "decl-list", "decl",
  "id-list", "@4", "opt-const-sect", "const-list", "const-decl",
  "opt-module-list", "module-body", "@5", "stat-list", "stat",
  "assign-stat", "@6", "if-stat", "opt-elsif-stat-list", "opt-else-stat",
  "while-stat", "return-stat", "opt-expr", "read-stat", "write-stat",
  "expr-list", "expr", "bool-op", "bool-term", "rel-op", "rel-term",
  "low-bin-op", "low-term", "high-bin-op", "factor", "@7", "unary-op",
  "constant", "module-call", "@8", "opt-expr-list", "cond-expr",
  "opt-elsif-expr-list", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,    40,    41,
      58,    44,    59,    61
};
# endif

#define YYPACT_NINF -116

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-116)))

#define YYTABLE_NINF -89

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      12,    27,    67,  -116,  -116,  -116,     7,    54,  -116,    31,
    -116,    50,    46,    62,    54,    98,    99,  -116,  -116,  -116,
     100,   101,   103,    71,  -116,    66,    74,   101,    12,    72,
     101,   106,    76,  -116,   101,    12,   107,   101,  -116,  -116,
      -1,  -116,  -116,   112,  -116,  -116,    79,  -116,    -1,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,    -1,   -18,  -116,    45,
       1,  -116,    -1,  -116,  -116,  -116,  -116,    80,    82,     3,
      25,  -116,  -116,  -116,    -1,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,    -1,    -1,  -116,  -116,    -1,  -116,    34,
      -1,    -1,    -1,  -116,  -116,    36,     1,  -116,    79,    -1,
      -1,    -1,    83,    84,   114,    85,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,   -12,    86,    41,    -2,    81,    58,
      64,  -116,    75,   101,    -1,   122,    34,    -1,  -116,  -116,
      -1,   115,    -1,    34,    34,    90,    91,  -116,  -116,  -116,
      70,    -1,    75,   119,   123,  -116,  -116,    -1,    17,    -1,
     120,  -116,    -2,  -116,    73,    34,   125,  -116,    34,  -116,
    -116,   119,  -116
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     1,     0,     7,    10,     0,
       6,     9,     0,     0,     0,     0,     0,     8,    11,     4,
      13,     0,    21,    19,    12,     0,     0,     0,    26,     0,
      15,     0,     0,    20,    23,    26,     0,     0,    14,    16,
       0,    22,    25,     0,     5,    18,    75,    79,     0,    81,
      82,    84,    85,    83,    86,    87,     0,     0,    54,    58,
      66,    70,     0,    76,    77,    78,    27,     0,     0,     0,
       0,    55,    56,    24,     0,    67,    68,    59,    60,    64,
      63,    62,    61,     0,     0,    71,    72,     0,    73,     0,
      91,     0,     0,    74,    53,    57,    65,    69,    38,     0,
       0,    48,     0,     0,     0,     0,    31,    32,    33,    34,
      35,    36,    37,    90,    52,     0,     0,    94,     0,     0,
       0,    46,    47,     0,     0,     0,    30,     0,    89,    80,
       0,     0,     0,     0,     0,     0,     0,    28,    29,    51,
       0,     0,    39,    42,     0,    49,    50,     0,     0,     0,
      44,    45,    94,    92,     0,     0,     0,    93,     0,    43,
      40,    42,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,   135,  -116,  -116,  -116,   124,  -116,  -116,  -116,
     109,    51,   -36,  -116,  -116,   102,  -116,   105,  -116,  -116,
    -115,  -116,  -116,  -116,  -116,   -24,  -116,  -116,  -116,  -116,
    -116,  -116,   -31,   -40,  -116,    68,  -116,    60,  -116,    57,
    -116,   -57,  -116,  -116,  -116,   -87,  -116,  -116,  -116,    -8
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    35,     6,    20,     9,    10,    11,    12,    22,
      24,    25,    26,    29,    28,    33,    34,    36,    44,    89,
     104,   105,   106,   118,   107,   150,   156,   108,   109,   121,
     110,   111,   113,   114,    74,    58,    83,    59,    84,    60,
      87,    61,    68,    62,    63,    64,    67,   115,    65,   131
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,    45,   112,    46,    47,    88,    71,    72,    69,    48,
     130,   138,    71,    72,    92,     1,    70,    49,   143,   144,
      85,    86,    71,    72,    73,    50,   153,    71,    72,   127,
      97,     4,    51,    52,    53,    54,    55,    56,    98,   112,
     159,    71,    72,   161,    99,     7,   112,   112,   100,    71,
      72,   116,   117,    75,    76,   101,   102,   103,     8,   119,
     120,   122,    75,    76,    93,    71,    72,     5,   112,   133,
      13,   112,    77,    78,    79,    80,    81,    82,    32,   134,
     129,   147,    71,    72,   158,    32,    15,   135,    71,    72,
     140,    14,   142,   136,    71,    72,   139,    71,    72,    71,
      72,   148,    16,    18,    19,    23,    21,   152,    30,   154,
      27,    39,   -17,    37,    31,    43,    66,   -88,    90,    40,
      91,   123,   124,   125,   132,   128,   137,   126,   141,   145,
     146,   149,   151,   155,   160,     3,    41,   162,    17,    38,
      42,    96,    94,    95,   157
};

static const yytype_uint8 yycheck[] =
{
      40,    37,    89,     4,     5,    62,    24,    25,    48,    10,
      12,   126,    24,    25,    11,     3,    56,    18,   133,   134,
      19,    20,    24,    25,    42,    26,     9,    24,    25,    41,
      87,     4,    33,    34,    35,    36,    37,    38,     4,   126,
     155,    24,    25,   158,    10,    38,   133,   134,    14,    24,
      25,    91,    92,    17,    18,    21,    22,    23,     4,    99,
     100,   101,    17,    18,    39,    24,    25,     0,   155,    11,
      39,   158,    27,    28,    29,    30,    31,    32,    27,    15,
      39,    11,    24,    25,    11,    34,    40,   123,    24,    25,
     130,    41,   132,   124,    24,    25,   127,    24,    25,    24,
      25,   141,    40,     5,     5,     4,     6,   147,    42,   149,
       7,     5,    41,    41,    40,     8,     4,    38,    38,    43,
      38,    38,    38,     9,    43,    39,     4,    42,    13,    39,
      39,    12,     9,    13,     9,     0,    34,   161,    14,    30,
      35,    84,    74,    83,   152
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    45,    46,     4,     0,    47,    38,     4,    49,
      50,    51,    52,    39,    41,    40,    40,    50,     5,     5,
      48,     6,    53,     4,    54,    55,    56,     7,    58,    57,
      42,    40,    55,    59,    60,    46,    61,    41,    54,     5,
      43,    59,    61,     8,    62,    56,     4,     5,    10,    18,
      26,    33,    34,    35,    36,    37,    38,    77,    79,    81,
      83,    85,    87,    88,    89,    92,     4,    90,    86,    77,
      77,    24,    25,    42,    78,    17,    18,    27,    28,    29,
      30,    31,    32,    80,    82,    19,    20,    84,    85,    63,
      38,    38,    11,    39,    79,    81,    83,    85,     4,    10,
      14,    21,    22,    23,    64,    65,    66,    68,    71,    72,
      74,    75,    89,    76,    77,    91,    77,    77,    67,    77,
      77,    73,    77,    38,    38,     9,    42,    41,    39,    39,
      12,    93,    43,    11,    15,    56,    76,     4,    64,    76,
      77,    13,    77,    64,    64,    39,    39,    11,    77,    12,
      69,     9,    77,     9,    77,    13,    70,    93,    11,    64,
       9,    64,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    47,    48,    46,    49,    49,    50,    50,
      52,    51,    53,    53,    54,    54,    55,    57,    56,    56,
      58,    58,    59,    59,    60,    61,    61,    63,    62,    64,
      64,    65,    65,    65,    65,    65,    65,    65,    67,    66,
      68,    69,    69,    70,    70,    71,    72,    73,    73,    74,
      75,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    80,    80,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    85,    85,    85,    85,    85,    85,    86,
      85,    87,    87,    88,    88,    88,    88,    88,    90,    89,
      91,    91,    92,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     0,    13,     1,     0,     3,     1,
       0,     4,     2,     0,     3,     2,     3,     0,     4,     1,
       2,     0,     2,     1,     4,     2,     0,     0,     6,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       7,     5,     0,     2,     0,     5,     2,     1,     0,     4,
       4,     3,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     2,     3,     1,     1,     1,     1,     0,
       5,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       1,     0,     8,     5,     0
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
#line 47 "parser.y" /* yacc.c:1646  */
    {(yyval) = nontermnode(N_PROGRAM); (yyval)->child1 = (yyvsp[0]); root = (yyval);}
#line 1363 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 50 "parser.y" /* yacc.c:1646  */
    {(yyval) = idnode();}
#line 1369 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 50 "parser.y" /* yacc.c:1646  */
    {(yyval) = typenode();}
#line 1375 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 52 "parser.y" /* yacc.c:1646  */
    {
                              (yyval) = nontermnode(N_MODULE_DECL); 
                              (yyval)->child1 = (yyvsp[-10]); 
                              (yyvsp[-10])->brother = (yyvsp[-8]); 
                              (yyvsp[-8])->brother = (yyvsp[-4]); 
                              (yyvsp[-4])->brother = (yyvsp[-3]); 
                              (yyvsp[-3])->brother = (yyvsp[-2]); 
                              (yyvsp[-2])->brother = nontermnode(N_OPT_MODULE_LIST); 
                              (yyvsp[-2])->brother->child1 = (yyvsp[-1]); 
                              (yyvsp[-2])->brother->brother = (yyvsp[0]); 
                         }
#line 1391 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 65 "parser.y" /* yacc.c:1646  */
    {(yyval) = nontermnode(N_OPT_PARAM_LIST); (yyval)->child1 = (yyvsp[0]);}
#line 1397 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 66 "parser.y" /* yacc.c:1646  */
    {(yyval) = nontermnode(N_OPT_PARAM_LIST);}
#line 1403 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 69 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-2]); (yyvsp[-2])->brother = (yyvsp[0]);}
#line 1409 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 70 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1415 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 73 "parser.y" /* yacc.c:1646  */
    {(yyval) = idnode();}
#line 1421 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 73 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0]) = typenode(); (yyval) = nontermnode(N_PARAM_DECL); (yyval)->child1 = (yyvsp[-2]); (yyval)->child2 = (yyvsp[0]);}
#line 1427 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 76 "parser.y" /* yacc.c:1646  */
    {(yyval) = nontermnode(N_OPT_VAR_SECT); (yyval)->child1 = (yyvsp[0]);}
#line 1433 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 77 "parser.y" /* yacc.c:1646  */
    {(yyval) =nontermnode(N_OPT_VAR_SECT);}
#line 1439 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 80 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-2]); (yyvsp[-2])->brother = (yyvsp[0]);}
#line 1445 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 81 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1451 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 84 "parser.y" /* yacc.c:1646  */
    {(yyval) = nontermnode(N_DECL); (yyval)->child1 = nontermnode(N_ID_LIST); (yyvsp[0]) = typenode(); (yyval)->child1->child1 = (yyvsp[-2]); (yyval)->child2 = (yyvsp[0]);}
#line 1457 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 87 "parser.y" /* yacc.c:1646  */
    {(yyval) = idnode();}
#line 1463 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 87 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-2]); (yyvsp[-2])->brother = (yyvsp[0]);}
#line 1469 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 88 "parser.y" /* yacc.c:1646  */
    {(yyval) = idnode();}
#line 1475 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 91 "parser.y" /* yacc.c:1646  */
    {(yyval) = nontermnode(N_OPT_CONST_SECT); (yyval)->child1 = (yyvsp[0]);}
#line 1481 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 92 "parser.y" /* yacc.c:1646  */
    {(yyval) = nontermnode(N_OPT_CONST_SECT);}
#line 1487 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 95 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1])->brother->brother = (yyvsp[0]); (yyval) = (yyvsp[-1]);}
#line 1493 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 96 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1499 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 99 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-3])->brother = (yyvsp[-1]); (yyval) = (yyvsp[-3]);}
#line 1505 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 102 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]); (yyvsp[-1])->brother = (yyvsp[0]);}
#line 1511 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 103 "parser.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1517 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 106 "parser.y" /* yacc.c:1646  */
    {(yyval) = idnode();}
#line 1523 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 106 "parser.y" /* yacc.c:1646  */
    {(yyval) = nontermnode(N_MODULE_BODY); (yyvsp[0]) = idnode(); (yyvsp[-3])->brother = nontermnode(N_STAT_LIST); 
                         (yyvsp[-3])->brother->child1 = (yyvsp[-2]); (yyvsp[-3])->brother->brother = (yyvsp[0]); (yyval)->child1 = (yyvsp[-3]);}
#line 1530 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 110 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-2]); (yyvsp[-2])->brother = (yyvsp[0]);}
#line 1536 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 111 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1542 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 114 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1548 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 115 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1554 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 116 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1560 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 117 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1566 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 118 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1572 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 119 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1578 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 120 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1584 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 123 "parser.y" /* yacc.c:1646  */
    {(yyval) = idnode();}
#line 1590 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 123 "parser.y" /* yacc.c:1646  */
    {(yyval) = nontermnode(N_ASSIGN_STAT); (yyval)->child1 = (yyvsp[-2]); (yyval)->child2 = (yyvsp[0]);}
#line 1596 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 126 "parser.y" /* yacc.c:1646  */
    {(yyval) = nontermnode(N_IF_STAT); (yyval)->child1 = (yyvsp[-5]); 
                         (yyval)->child1->brother = nontermnode(N_STAT_LIST); (yyval)->child1->brother->child1 = (yyvsp[-3]); (yyval)->child2 = nontermnode(N_OPT_ELSIF_STAT_LIST); 
                              (yyval)->child2->child1 = (yyvsp[-2]); (yyval)->child2->child2 = (yyvsp[-1]);}
#line 1604 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 131 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-3]); (yyvsp[-3])->brother = nontermnode(N_STAT_LIST); (yyvsp[-3])->brother->child1 = (yyvsp[-1]); 
                         (yyvsp[-3])->brother->brother = (yyvsp[0]);}
#line 1611 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 133 "parser.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1617 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 136 "parser.y" /* yacc.c:1646  */
    {(yyval) = nontermnode(N_STAT_LIST); (yyval)->child1 = (yyvsp[0]);}
#line 1623 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 137 "parser.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1629 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 140 "parser.y" /* yacc.c:1646  */
    {(yyval) = nontermnode(N_WHILE_STAT); (yyval)->child1 = (yyvsp[-3]); (yyval)->child2 = nontermnode(N_STAT_LIST); (yyval)->child2->child1 = (yyvsp[-1]);}
#line 1635 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 143 "parser.y" /* yacc.c:1646  */
    {(yyval) = nontermnode(N_RETURN_STAT); (yyval)->child1 = (yyvsp[0]);}
#line 1641 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 146 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1647 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 147 "parser.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1653 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 150 "parser.y" /* yacc.c:1646  */
    {(yyval) = nontermnode(N_READ_STAT); (yyval)->child1 = nontermnode(N_ID_LIST); (yyval)->child1->child1 = (yyvsp[-1]);}
#line 1659 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 153 "parser.y" /* yacc.c:1646  */
    {(yyval) = nontermnode(N_WRITE_STAT); (yyval)->child1 = nontermnode(N_EXPR_LIST); (yyval)->child1->child1 = (yyvsp[-1]);}
#line 1665 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 156 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-2]); (yyvsp[-2])->brother = (yyvsp[0]);}
#line 1671 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 157 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1677 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 160 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1])->child1 = (yyvsp[-2]); (yyvsp[-1])->child2 = (yyvsp[0]); (yyval) = (yyvsp[-1]);}
#line 1683 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 161 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1689 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 164 "parser.y" /* yacc.c:1646  */
    {(yyval) = logicnode(O_AND);}
#line 1695 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 165 "parser.y" /* yacc.c:1646  */
    {(yyval) = logicnode(O_OR);}
#line 1701 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 168 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]); (yyvsp[-1])->child1 = (yyvsp[-2]); (yyvsp[-1])->child2 = (yyvsp[0]);}
#line 1707 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 169 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1713 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 172 "parser.y" /* yacc.c:1646  */
    {(yyval) = relnode(O_EQ);}
#line 1719 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 173 "parser.y" /* yacc.c:1646  */
    {(yyval) = relnode(O_NEQ);}
#line 1725 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 174 "parser.y" /* yacc.c:1646  */
    {(yyval) = relnode(O_LT);}
#line 1731 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 175 "parser.y" /* yacc.c:1646  */
    {(yyval) = relnode(O_LE);}
#line 1737 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 176 "parser.y" /* yacc.c:1646  */
    {(yyval) = relnode(O_GT);}
#line 1743 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 177 "parser.y" /* yacc.c:1646  */
    {(yyval) = relnode(O_GE);}
#line 1749 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 180 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]); (yyvsp[-1])->child1 = (yyvsp[-2]); (yyvsp[-1])->child2 = (yyvsp[0]);}
#line 1755 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 181 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1761 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 184 "parser.y" /* yacc.c:1646  */
    {(yyval) = mathnode(O_PLUS);}
#line 1767 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 185 "parser.y" /* yacc.c:1646  */
    {(yyval) = mathnode(O_MINUS);}
#line 1773 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 188 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1])->child1 = (yyvsp[-2]); (yyvsp[-1])->child2 = (yyvsp[0]); (yyval) = (yyvsp[-1]);}
#line 1779 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 189 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1785 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 192 "parser.y" /* yacc.c:1646  */
    {(yyval) = mathnode(O_MULT);}
#line 1791 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 193 "parser.y" /* yacc.c:1646  */
    {(yyval) = mathnode(O_DIV);}
#line 1797 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 196 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]); (yyvsp[-1])->child1 = (yyvsp[0]);}
#line 1803 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 197 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1809 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 198 "parser.y" /* yacc.c:1646  */
    {(yyval) = idnode();}
#line 1815 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 199 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1821 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 200 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1827 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 201 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1833 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 202 "parser.y" /* yacc.c:1646  */
    {(yyval) = castnode();}
#line 1839 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 202 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-3])->child1 = (yyvsp[-1]); (yyval) = (yyvsp[-3]);}
#line 1845 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 205 "parser.y" /* yacc.c:1646  */
    {(yyval) = negnode(O_CHANGE_SIGN);}
#line 1851 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 206 "parser.y" /* yacc.c:1646  */
    {(yyval) = negnode(O_NOT);}
#line 1857 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 209 "parser.y" /* yacc.c:1646  */
    {(yyval) = charconstnode();}
#line 1863 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 210 "parser.y" /* yacc.c:1646  */
    {(yyval) = intconstnode();}
#line 1869 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 211 "parser.y" /* yacc.c:1646  */
    {(yyval) = realconstnode();}
#line 1875 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 212 "parser.y" /* yacc.c:1646  */
    {(yyval) = strconstnode();}
#line 1881 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 213 "parser.y" /* yacc.c:1646  */
    {(yyval) = boolconstnode();}
#line 1887 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 216 "parser.y" /* yacc.c:1646  */
    {(yyval) = idnode();}
#line 1893 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 216 "parser.y" /* yacc.c:1646  */
    {(yyval) = nontermnode(N_MODULE_CALL); (yyval)->child1 = (yyvsp[-3]); (yyval)->child2 = (yyvsp[-1]);}
#line 1899 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 219 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1905 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 220 "parser.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1911 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 223 "parser.y" /* yacc.c:1646  */
    {(yyval) = nontermnode(N_COND_EXPR); (yyval)->child1 = (yyvsp[-6]); (yyvsp[-6])->brother = (yyvsp[-4]); 
                         (yyval)->child2 = nontermnode(N_OPT_ELSIF_EXPR_LIST); (yyval)->child2->child1 = (yyvsp[-3]); (yyval)->child2 ->child2 = (yyvsp[-1]);}
#line 1918 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 227 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-3]); (yyvsp[-3])->brother = (yyvsp[-1]); (yyvsp[-1])->brother = (yyvsp[0]);}
#line 1924 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 228 "parser.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1930 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1934 "parser.tab.c" /* yacc.c:1646  */
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
#line 230 "parser.y" /* yacc.c:1906  */


/**   
*    Funzioni ausiliarie  
*    
*    Ogni funzione è specializzata nella costruzione di uno specifico nodo previsto dalla sintassi 
*    del linguaggio Tela.
*
**/

void yyerror(){
     fprintf(stderr, "Linea %d: errore di sintassi sul simbolo \"%s\"\n", num_line, yytext);
     exit(-1);
}

Node *nontermnode(SymName name){
     Node *p = newnode(T_NONTERMINAL, name);
     return p;
}

Node *relnode(RelOp operation){
     Node *p = nontermnode(N_REL_EXPR);
     p->lexval.ival = operation;
     return p;
}

Node *idnode(){
     Node *p = newnode(T_TERMINAL, T_ID);
     p->lexval.sval = lexval.sval;
     return p;
}

Node *typenode(){
     Node *p = newnode(T_TERMINAL, T_TYPE);
     p->lexval.ival = lexval.ival;
     return p;
}

Node *logicnode(BoolOp operation){
     Node *p = nontermnode(N_LOGIC_EXPR);
     p->lexval.ival = operation;
     return p;
}

Node *mathnode(MathOp operation){
     Node *p = nontermnode(N_MATH_EXPR);
     p->lexval.ival = operation;
     return p;
}

Node *negnode(NegOp operation){
     Node *p = nontermnode(N_NEG_EXPR);
     p->lexval.ival = operation;
     return p;
}

Node *castnode(){
     Node *p = nontermnode(N_CAST);
     p->lexval.ival = lexval.ival;
     return p;
}

Node *intconstnode(){
     Node *p = newnode(T_TERMINAL, T_INTCONST);
     p->lexval.ival = lexval.ival;
     return p;
}

Node *charconstnode(){
     Node *p = newnode(T_TERMINAL, T_CHARCONST);
     p->lexval.cval = lexval.cval;
     return p;
}

Node *realconstnode(){
     Node *p = newnode(T_TERMINAL, T_REALCONST);
     p->lexval.rval = lexval.rval;
     return p;
}

Node *strconstnode(){
     Node *p = newnode(T_TERMINAL, T_STRCONST);
     p->lexval.sval = lexval.sval;
     return p;
}

Node *boolconstnode(){
     Node *p = newnode(T_TERMINAL, T_BOOLCONST);
     p->lexval.bval = lexval.bval;
     return p;
}

Node *newnode(SymType type, SymName name){
     Node *p = malloc(sizeof(Node));
     p->type = type;
     p->name = name;
     p->line = num_line;
     p->child1 = p->child2 = p->brother = NULL;
     return p;
}
