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
#line 1 "lab6.y" /* yacc.c:339  */


/*
/_/\     /_______/\ /_______/\     /_____/\    
\:\ \    \::: _  \ \\::: _  \ \    \::::_\/_   
 \:\ \    \::(_)  \ \\::(_)  \/_    \:\/___/\  
  \:\ \____\:: __  \ \\::  _  \ \    \_::._\:\ 
   \:\/___/\\:.\ \  \ \\::(_)  \ \    /_____\/ 
    \_____\/ \__\/\__\/ \_______\/    \_____/ 

  Shaun Cooper
    January 2015

  Editted by Jason Ivey, Sep 4, 2022:
    Added mult, uminus, and fixed spelling. 
    Fixed spacing issues. 
    Added int type to main. 
    Made debugsw external. 
    Added int yylex(); to supress warnings. 

  Editted by Jason Ivey, Sep 12, 2022:
      Made debug = 0
      added () to token list

  Editted by Jason Ivey, Sep 25, 2022:
      removed old:
        symbol table
        rules
        debugsw
        base

  Editted by Jason Ivey, Sep 26, 2022:
      fixed missing:
        rules


  INPUT: LEX Description + Text
  OUTPUT: y.tab.c /h 
*/

// begin specs 
#include <stdio.h>
#include <ctype.h>
#include "ast.h"
#define DEBUG

// Added this to supress warn
extern int yylex(void);
void debug(char s[]);
extern int line_num; //counts lines (FROM LEX)

// ast global
struct ASTnodetype *PROGRAM;

// Called by yyparse on error 
void yyerror (s)  
     char *s;
{
  printf ("ERROR @ line #%i: %s\n", line_num, s);
}


#line 129 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    T_AND = 258,
    T_ASSIGN = 259,
    T_BOOLTYPE = 260,
    T_BREAK = 261,
    T_CHARCONSTANT = 262,
    T_CONTINUE = 263,
    T_DOT = 264,
    T_ELSE = 265,
    T_EQ = 266,
    T_EXTERN = 267,
    T_FALSE = 268,
    T_FOR = 269,
    T_FUNC = 270,
    T_GEQ = 271,
    T_GT = 272,
    T_LT = 273,
    T_ID = 274,
    T_IF = 275,
    T_INTCONSTANT = 276,
    T_INTTYPE = 277,
    T_LEFTSHT_IFT = 278,
    T_LEQ = 279,
    T_NEQ = 280,
    T_NULL = 281,
    T_OR = 282,
    T_PACKAGE = 283,
    T_RETURN = 284,
    T_RIGHTSHT_IFT = 285,
    T_STRINGCONSTANT = 286,
    T_STRINGTYPE = 287,
    T_TRUE = 288,
    T_VAR = 289,
    T_VOID = 290,
    T_WHILE = 291,
    T_LEFTSHIFT = 292,
    T_RIGHTSHIFT = 293
  };
#endif
/* Tokens.  */
#define T_AND 258
#define T_ASSIGN 259
#define T_BOOLTYPE 260
#define T_BREAK 261
#define T_CHARCONSTANT 262
#define T_CONTINUE 263
#define T_DOT 264
#define T_ELSE 265
#define T_EQ 266
#define T_EXTERN 267
#define T_FALSE 268
#define T_FOR 269
#define T_FUNC 270
#define T_GEQ 271
#define T_GT 272
#define T_LT 273
#define T_ID 274
#define T_IF 275
#define T_INTCONSTANT 276
#define T_INTTYPE 277
#define T_LEFTSHT_IFT 278
#define T_LEQ 279
#define T_NEQ 280
#define T_NULL 281
#define T_OR 282
#define T_PACKAGE 283
#define T_RETURN 284
#define T_RIGHTSHT_IFT 285
#define T_STRINGCONSTANT 286
#define T_STRINGTYPE 287
#define T_TRUE 288
#define T_VAR 289
#define T_VOID 290
#define T_WHILE 291
#define T_LEFTSHIFT 292
#define T_RIGHTSHIFT 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 122 "lab6.y" /* yacc.c:355  */

  int value;
  char* string;
  struct ASTnodetype *astnode; //keeps track of our nodes
  enum AST_Decaf_Types asttype;
  enum AST_Operators operator;

#line 253 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 270 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   178

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,     2,     2,    51,     2,     2,
      41,    42,    49,    47,    44,    48,     2,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   131,   131,   143,   146,   152,   161,   162,   165,   170,
     179,   180,   187,   193,   200,   210,   211,   218,   229,   230,
     236,   242,   251,   260,   261,   268,   274,   284,   285,   292,
     293,   294,   295,   296,   297,   298,   299,   302,   316,   325,
     331,   339,   343,   347,   354,   360,   371,   376,   384,   393,
     394,   396,   397,   405,   406,   415,   416,   417,   418,   419,
     420,   423,   424,   436,   437,   439,   440,   449,   450,   451,
     452,   453,   454,   455,   458,   459,   460,   461,   462,   468,
     476,   477,   479,   480,   483,   485,   487,   492,   498,   506,
     511,   516
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_AND", "T_ASSIGN", "T_BOOLTYPE",
  "T_BREAK", "T_CHARCONSTANT", "T_CONTINUE", "T_DOT", "T_ELSE", "T_EQ",
  "T_EXTERN", "T_FALSE", "T_FOR", "T_FUNC", "T_GEQ", "T_GT", "T_LT",
  "T_ID", "T_IF", "T_INTCONSTANT", "T_INTTYPE", "T_LEFTSHT_IFT", "T_LEQ",
  "T_NEQ", "T_NULL", "T_OR", "T_PACKAGE", "T_RETURN", "T_RIGHTSHT_IFT",
  "T_STRINGCONSTANT", "T_STRINGTYPE", "T_TRUE", "T_VAR", "T_VOID",
  "T_WHILE", "T_LEFTSHIFT", "T_RIGHTSHIFT", "'{'", "'}'", "'('", "')'",
  "';'", "','", "'['", "']'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'",
  "$accept", "program", "Externs", "ExternDefn", "ExternParmList",
  "FullExternParmList", "FieldDecls", "FieldDecl", "MethodDecls",
  "MethodDecl", "MethodParmList", "FullMethodParmList", "Block",
  "VarDecls", "VarDecl", "Statements", "Statement", "IfStatement",
  "BreakStatement", "WhileStatement", "ReturnStatement",
  "ContinueStatement", "Assign", "Lvalue", "MethodCall", "MethodCallList",
  "FullMethodCallList", "Expr", "Relop", "Additiveexpression", "Addop",
  "Term", "Multop", "Factor", "ExternType", "Type", "MethodType",
  "BoolConstant", "ArrayType", "Constant", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   123,
     125,    40,    41,    59,    44,    91,    93,    43,    45,    42,
      47,    37,    33
};
# endif

#define YYPACT_NINF -95

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-95)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -4,     6,    29,   -13,    -4,    19,   -95,    22,   -95,    21,
      31,    34,    26,   -95,   -95,   -95,    33,   -95,    24,   -95,
      57,    62,    26,    18,    34,     0,    59,    43,    62,   -95,
     -95,   -95,    44,   -95,    68,    15,    48,    51,   -95,   -95,
     -95,    55,   120,   -95,   -95,    75,    11,   -95,   -95,   -95,
     -95,   -95,    61,    11,    69,   -95,   -95,   -95,    78,    18,
      75,    74,   -95,    95,   -95,   121,    76,    95,     0,    96,
      99,   -14,    97,   -23,   105,   -95,   108,    76,   -95,   -95,
     -95,   -95,   -95,   104,   148,   111,   -95,   115,   116,   -95,
     -95,    38,    38,    38,    13,   -95,    38,   -95,   -95,   -95,
      38,   -95,   -95,   -95,    38,    38,    38,   -95,   -95,   118,
     -95,    82,    16,    -2,   -95,   -95,    56,    92,   122,   103,
     107,   139,   119,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,    38,    38,   -95,   -95,    38,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,    38,   -95,    74,   -95,   123,    74,
     -95,   139,    16,    -2,   -95,   152,   -95,   -95,    74,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     3,     0,     1,     0,     4,     0,
       0,     6,    10,    83,    82,    80,     0,     7,     8,    81,
       0,    15,    10,     0,     6,     0,     0,     0,    15,    11,
      84,    85,     0,     9,     0,     0,     0,     0,     2,    16,
       5,     0,     0,    12,    13,    18,     0,    87,    89,    90,
      86,    91,     0,     0,     0,    19,    88,    14,    20,     0,
       0,     0,    21,    23,    17,     0,    27,    23,     0,     0,
       0,    46,     0,     0,     0,    29,     0,    27,    32,    33,
      34,    35,    36,     0,     0,     0,    24,     0,     0,    39,
      44,    49,     0,     0,     0,    41,     0,    22,    28,    31,
       0,    30,    25,    26,     0,     0,     0,    74,    75,     0,
      50,    51,    53,    61,    65,    76,     0,     0,     0,     0,
       0,    45,     0,    79,    78,    48,    59,    58,    56,    57,
      55,    60,     0,     0,    63,    64,     0,    70,    71,    72,
      73,    67,    68,    69,     0,    47,     0,    42,     0,     0,
      77,    52,    54,    62,    66,    38,    43,    40,     0,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   163,   -95,   144,   -95,   147,   -95,   142,   -95,
     -95,   112,   -61,   106,   -95,    94,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -53,   -49,   -95,   -95,   -90,   -95,    41,
     -95,    39,   -95,   -94,   -95,   -16,   117,   -95,   109,   136
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    16,    17,    21,    22,    27,    28,
      54,    55,    75,    66,    67,    76,    77,    78,    79,    80,
      81,    82,    83,   107,   108,   109,   110,   111,   133,   112,
     136,   113,   144,   114,    18,    19,    32,    51,    36,   115
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      64,   137,   116,   117,   119,    13,   120,    31,     1,    35,
     121,   123,   124,    84,   122,     7,    13,    85,    94,    42,
      95,     5,    14,    13,    84,   138,    47,    91,    85,     6,
      56,    92,    71,    14,    48,   139,   140,    58,     9,    13,
      14,    10,   151,    31,    49,    34,    50,   141,   142,   143,
     154,    47,    87,    30,   104,   118,    14,    71,    43,    48,
      20,   105,    11,   134,   135,   106,    15,   126,    24,    49,
      12,    50,   127,   128,   129,    23,    25,    26,    37,   104,
     130,   131,    69,    38,    70,   155,   105,    40,   157,    41,
     106,    44,    45,   126,    53,    71,    72,   159,   127,   128,
     129,    46,   145,   126,    57,    73,   130,   131,   127,   128,
     129,    59,    74,    63,   126,    63,   130,   131,   126,   127,
     128,   129,    60,   127,   128,   129,   132,   130,   131,    65,
     126,   130,   131,    47,   146,   127,   128,   129,    93,    89,
      68,    48,    90,   130,   131,   148,    96,    99,    97,   149,
     126,    49,   100,    50,   101,   127,   128,   129,   102,   103,
     125,   150,   158,   130,   131,   147,   156,     8,    33,    29,
      39,    98,    62,    86,   152,   153,    61,    88,    52
};

static const yytype_uint8 yycheck[] =
{
      61,     3,    92,    93,    94,     5,    96,    23,    12,    25,
     100,   105,   106,    66,   104,    28,     5,    66,    41,     4,
      43,    15,    22,     5,    77,    27,    13,    41,    77,     0,
      46,    45,    19,    22,    21,    37,    38,    53,    19,     5,
      22,    19,   132,    59,    31,    45,    33,    49,    50,    51,
     144,    13,    68,    35,    41,    42,    22,    19,    43,    21,
      34,    48,    41,    47,    48,    52,    32,    11,    44,    31,
      39,    33,    16,    17,    18,    42,    19,    15,    19,    41,
      24,    25,     6,    40,     8,   146,    48,    43,   149,    21,
      52,    43,    41,    11,    19,    19,    20,   158,    16,    17,
      18,    46,    46,    11,    43,    29,    24,    25,    16,    17,
      18,    42,    36,    39,    11,    39,    24,    25,    11,    16,
      17,    18,    44,    16,    17,    18,    44,    24,    25,    34,
      11,    24,    25,    13,    42,    16,    17,    18,    41,    43,
      19,    21,    43,    24,    25,    42,    41,    43,    40,    42,
      11,    31,     4,    33,    43,    16,    17,    18,    43,    43,
      42,    42,    10,    24,    25,    43,    43,     4,    24,    22,
      28,    77,    60,    67,   133,   136,    59,    68,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    54,    55,    56,    15,     0,    28,    55,    19,
      19,    41,    39,     5,    22,    32,    57,    58,    87,    88,
      34,    59,    60,    42,    44,    19,    15,    61,    62,    59,
      35,    88,    89,    57,    45,    88,    91,    19,    40,    61,
      43,    21,     4,    43,    43,    41,    46,    13,    21,    31,
      33,    90,    92,    19,    63,    64,    88,    43,    88,    42,
      44,    89,    64,    39,    65,    34,    66,    67,    19,     6,
       8,    19,    20,    29,    36,    65,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    66,    88,    91,    43,
      43,    41,    45,    41,    41,    43,    41,    40,    68,    43,
       4,    43,    43,    43,    41,    48,    52,    76,    77,    78,
      79,    80,    82,    84,    86,    92,    80,    80,    42,    80,
      80,    80,    80,    86,    86,    42,    11,    16,    17,    18,
      24,    25,    44,    81,    47,    48,    83,     3,    27,    37,
      38,    49,    50,    51,    85,    46,    42,    43,    42,    42,
      42,    80,    82,    84,    86,    65,    43,    65,    10,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    57,    57,    58,    58,
      59,    59,    60,    60,    60,    61,    61,    62,    63,    63,
      64,    64,    65,    66,    66,    67,    67,    68,    68,    69,
      69,    69,    69,    69,    69,    69,    69,    70,    70,    71,
      72,    73,    73,    73,    74,    75,    76,    76,    77,    78,
      78,    79,    79,    80,    80,    81,    81,    81,    81,    81,
      81,    82,    82,    83,    83,    84,    84,    85,    85,    85,
      85,    85,    85,    85,    86,    86,    86,    86,    86,    86,
      87,    87,    88,    88,    89,    89,    90,    90,    91,    92,
      92,    92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     0,     2,     8,     0,     1,     1,     3,
       0,     2,     4,     4,     6,     0,     2,     7,     0,     1,
       2,     4,     4,     0,     2,     4,     4,     0,     2,     1,
       2,     2,     1,     1,     1,     1,     1,     7,     5,     2,
       5,     2,     4,     5,     2,     3,     1,     4,     4,     0,
       1,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       1,     1
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
#line 132 "lab6.y" /* yacc.c:1646  */
    { 
                        PROGRAM = ASTCreateNode(A_PROGRAM);
                        PROGRAM->S1 = (yyvsp[-6].astnode);
                        PROGRAM->S2 = ASTCreateNode(A_PACKAGE);
                        PROGRAM->S2->name = (yyvsp[-4].string);
                        PROGRAM->S2->S1 = (yyvsp[-2].astnode); //field $5
                        PROGRAM->S2->S2 = (yyvsp[-1].astnode); //method
                    }
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 143 "lab6.y" /* yacc.c:1646  */
    { 
                        (yyval.astnode) = NULL;
                      }
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 147 "lab6.y" /* yacc.c:1646  */
    { 
                        (yyvsp[-1].astnode)->next = (yyvsp[0].astnode);
                      }
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 153 "lab6.y" /* yacc.c:1646  */
    { 
                        (yyval.astnode) = ASTCreateNode( A_EXTERN );
                        (yyval.astnode)->name = (yyvsp[-5].string);
                        (yyval.astnode)->A_Declared_TYPE = (yyvsp[-1].asttype);
                        (yyval.astnode)->S1 = (yyvsp[-3].astnode);
                      }
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 161 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = NULL;}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 162 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 166 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_EXTERN_TYPE );
                        (yyval.astnode)->A_Declared_TYPE = (yyvsp[0].asttype);
                      }
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 171 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_EXTERN_TYPE );
                        (yyval.astnode)->A_Declared_TYPE = (yyvsp[-2].asttype);
                        (yyval.astnode)->next = (yyvsp[0].astnode);
                      }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 179 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = NULL;}
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 181 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = (yyvsp[-1].astnode);
                        (yyval.astnode)->next = (yyvsp[0].astnode);
                      }
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 188 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_VARDEC );
                        (yyval.astnode)->name = (yyvsp[-2].string);
                        (yyval.astnode)->A_Declared_TYPE = (yyvsp[-1].asttype);
                      }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 194 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_VARDEC );
                        (yyval.astnode)->name = (yyvsp[-2].string);
                        (yyval.astnode)->S1 = (yyvsp[-1].astnode);
                        (yyval.astnode)->A_Declared_TYPE = (yyvsp[-1].astnode)->A_Declared_TYPE;
                      }
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 201 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_VARDEC );
                        (yyval.astnode)->name = (yyvsp[-4].string);
                        (yyval.astnode)->A_Declared_TYPE = (yyvsp[-3].asttype);
                        (yyval.astnode)->S2 = (yyvsp[-1].astnode);
                      }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 210 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = NULL;}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 212 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = (yyvsp[-1].astnode);
                        (yyval.astnode)->next = (yyvsp[0].astnode);
                      }
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 219 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_METHODDEC );
                        (yyval.astnode)->name = (yyvsp[-5].string);
                        (yyval.astnode)->A_Declared_TYPE = (yyvsp[-1].asttype);
                        (yyval.astnode)->S1   = (yyvsp[-3].astnode);
                        (yyval.astnode)->S2   = (yyvsp[0].astnode); // $7
                      }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 229 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = NULL;}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 231 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = (yyvsp[0].astnode);
                      }
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 237 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_METHOD_ID );
                        (yyval.astnode)->name = (yyvsp[-1].string);
                        (yyval.astnode)->A_Declared_TYPE = (yyvsp[0].asttype);
                      }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 243 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_METHOD_ID );
                        (yyval.astnode)->name = (yyvsp[-3].string);
                        (yyval.astnode)->A_Declared_TYPE = (yyvsp[-2].asttype);
                        (yyval.astnode)->next = (yyvsp[0].astnode);
                      }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 252 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_BLOCK );
                        (yyval.astnode)->S1 = (yyvsp[-2].astnode);
                        (yyval.astnode)->S2 = (yyvsp[-1].astnode);
                      }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 260 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = NULL;}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 262 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = (yyvsp[-1].astnode);
                        (yyval.astnode)->next = (yyvsp[0].astnode);
                      }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 269 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_VARDEC );
                        (yyval.astnode)->name = (yyvsp[-2].string);
                        (yyval.astnode)->A_Declared_TYPE = (yyvsp[-1].asttype);
                      }
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 275 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_VARDEC );
                        (yyval.astnode)->name = (yyvsp[-2].string);
                        (yyval.astnode)->S1 = (yyvsp[-1].astnode);
                        (yyval.astnode)->A_Declared_TYPE = (yyvsp[-1].astnode)->A_Declared_TYPE;
                      }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 284 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = NULL;}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 286 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = (yyvsp[-1].astnode);
                        (yyval.astnode)->next = (yyvsp[0].astnode);
                      }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 292 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 293 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = NULL;}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 294 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = NULL;}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 295 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = NULL;}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 296 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 297 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = NULL;}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 298 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 299 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 303 "lab6.y" /* yacc.c:1646  */
    { 
                      (yyval.astnode) = ASTCreateNode( A_IFSTMT );

                      (yyval.astnode)->S1 = (yyvsp[-4].astnode);
                      debug("$$->S1 line");
                      (yyval.astnode)->S2 = ASTCreateNode( A_IF_BLOCK );
                      debug("$$->S2->S1 line");
                      (yyval.astnode)->S2->S1 = (yyvsp[-2].astnode);
                      (yyval.astnode)->S2->S2 = ASTCreateNode( A_ELSE );
                      (yyval.astnode)->S2->S2->S1 = (yyvsp[0].astnode);

                    }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 317 "lab6.y" /* yacc.c:1646  */
    { 
                      (yyval.astnode) = ASTCreateNode( A_IFSTMT );
                      (yyval.astnode)->S1 = (yyvsp[-2].astnode);
                      (yyval.astnode)->S2 = ASTCreateNode( A_IF_BLOCK );
                      (yyval.astnode)->S2->S1 = (yyvsp[0].astnode);
                    }
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 326 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_BREAK );
                      }
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 332 "lab6.y" /* yacc.c:1646  */
    { 
                        (yyval.astnode) = ASTCreateNode( A_WHILESTMT );
                        (yyval.astnode)->S1 = (yyvsp[-2].astnode);
                        (yyval.astnode)->S2 = (yyvsp[0].astnode);
                      }
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 340 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_RETURN );
                      }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 344 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_RETURN );
                      }
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 348 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_RETURN );
                        (yyval.astnode)->S1 = (yyvsp[-2].astnode);
                      }
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 355 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_CONTINUE );
                      }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 361 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_ASSIGN );
                        //#ifdef DEBUG   
                        //  printf("Assign made with S1 = %s, S2 = %s",$1,$3);
                        //#endif
                        (yyval.astnode)->S1 = (yyvsp[-2].astnode);
                        (yyval.astnode)->S2 = (yyvsp[0].astnode);
                      }
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 372 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_VAR_RVAL );
                        (yyval.astnode)->name = (yyvsp[0].string);
                      }
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 377 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_VAR_RVAL );
                        (yyval.astnode)->name = (yyvsp[-3].string);
                        (yyval.astnode)->S1   = (yyvsp[-1].astnode);
                      }
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 385 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_METHOD_CALL );
                        (yyval.astnode)->name = (yyvsp[-3].string);
                        (yyval.astnode)->S1 = (yyvsp[-1].astnode);
                      }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 393 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = NULL;}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 394 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 396 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 398 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_EXPR );
                        (yyval.astnode)->S1 = (yyvsp[-2].astnode);
                        (yyval.astnode)->S2 = (yyvsp[0].astnode);
                      }
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 405 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 407 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_EXPR );
                        (yyval.astnode)->S1 = (yyvsp[-2].astnode);
                        (yyval.astnode)->operator = (yyvsp[-1].operator);
                        (yyval.astnode)->S2 = (yyvsp[0].astnode);
                      }
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 415 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = A_LEQ;}
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 416 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = A_GT ;}
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 417 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = A_LT ;}
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 418 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = A_GEQ;}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 419 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = A_EQ ;}
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 420 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = A_NEQ;}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 423 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 425 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_EXPR );
                        //#ifdef DEBUG
                        //  printf("Making expr with S1 = %d opp = %s S2 = %d", $1, $2, $3);
                        //#endif
                        (yyval.astnode)->S1 = (yyvsp[-2].astnode);
                        (yyval.astnode)->operator = (yyvsp[-1].operator);
                        (yyval.astnode)->S2 = (yyvsp[0].astnode);
                      }
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 436 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = A_PLUS;  }
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 437 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = A_MINUS; }
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 439 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 441 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_EXPR );
                        (yyval.astnode)->S1 = (yyvsp[-2].astnode);
                        (yyval.astnode)->operator = (yyvsp[-1].operator);
                        (yyval.astnode)->S2 = (yyvsp[0].astnode);
                      }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 449 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = A_TIMES;}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 450 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = A_DIV;}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 451 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = A_MOD;}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 452 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = A_AND;}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 453 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = A_OR;}
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 454 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = A_LS;}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 455 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = A_RS;}
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 458 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 459 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 460 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 461 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[-1].astnode);}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 463 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_EXPR );
                        (yyval.astnode)->operator = A_NOT;
                        (yyval.astnode)->S1 = (yyvsp[0].astnode);
                      }
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 469 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_UMINUS );
                        (yyval.astnode)->operator = A_NOT;
                        (yyval.astnode)->S1 = (yyvsp[0].astnode);
                      }
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 476 "lab6.y" /* yacc.c:1646  */
    {(yyval.asttype) = A_Decaf_STRING;}
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 477 "lab6.y" /* yacc.c:1646  */
    {(yyval.asttype) = (yyvsp[0].asttype);}
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 479 "lab6.y" /* yacc.c:1646  */
    {(yyval.asttype) = A_Decaf_INT;}
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 480 "lab6.y" /* yacc.c:1646  */
    {(yyval.asttype) = A_Decaf_BOOL;}
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 484 "lab6.y" /* yacc.c:1646  */
    {(yyval.asttype) = A_Decaf_VOID;}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 485 "lab6.y" /* yacc.c:1646  */
    {(yyval.asttype) = (yyvsp[0].asttype);}
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 488 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_CONSTANT_BOOL );
                        (yyval.astnode)->value = 1;
                      }
#line 2136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 493 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_CONSTANT_BOOL );
                        (yyval.astnode)->value = 0;
                      }
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 499 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_ARRAY_TYPE );
                        (yyval.astnode)->value = (yyvsp[-2].value);
                        (yyval.astnode)->A_Declared_TYPE = (yyvsp[0].asttype);
                      }
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 507 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_CONSTANT_INT );
                        (yyval.astnode)->value = (yyvsp[0].value);
                      }
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 512 "lab6.y" /* yacc.c:1646  */
    {
                        (yyval.astnode) = ASTCreateNode( A_CONSTANT_STRING );
                        (yyval.astnode)->name = (yyvsp[0].string);
                      }
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 516 "lab6.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2183 "y.tab.c" /* yacc.c:1646  */
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
#line 518 "lab6.y" /* yacc.c:1906  */
  /* end of rules, start of program */

int main()
{ 
  yyparse();
  printf("Parse complete!\n");
  // We know pogram parse complete PROGRAM->AST
  ASTprint(0, PROGRAM);
}

void debug(char s[]){
  #ifdef DEBUG    
    printf("DEBUG:: %s\n",s);
  #endif
}
