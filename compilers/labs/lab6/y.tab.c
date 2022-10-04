/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20210328

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "lab6.y"

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

/* begin specs */
#include <stdio.h>
#include <ctype.h>
#include "ast.h"

/* Added this to supress warn*/
extern int yylex(void);
extern int line_num; /*counts lines*/

/* Called by yyparse on error */
void yyerror (s)  
     char *s;
{
  printf ("ERROR @ line #%i: %s\n", line_num, s);
}

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 106 "lab6.y"
typedef union YYSTYPE
{
  int value;
  char* string;
  struct ASTnodetype *astnode; /*keeps track of our nodes*/
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 91 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define T_AND 257
#define T_ASSIGN 258
#define T_BOOLTYPE 259
#define T_BREAK 260
#define T_CHARCONSTANT 261
#define T_CONTINUE 262
#define T_DOT 263
#define T_ELSE 264
#define T_EQ 265
#define T_EXTERN 266
#define T_FALSE 267
#define T_FOR 268
#define T_FUNC 269
#define T_GEQ 270
#define T_GT 271
#define T_LT 272
#define T_ID 273
#define T_IF 274
#define T_INTCONSTANT 275
#define T_INTTYPE 276
#define T_LEFTSHT_IFT 277
#define T_LEQ 278
#define T_NEQ 279
#define T_NULL 280
#define T_OR 281
#define T_PACKAGE 282
#define T_RETURN 283
#define T_RIGHTSHT_IFT 284
#define T_STRINGCONSTANT 285
#define T_STRINGTYPE 286
#define T_TRUE 287
#define T_VAR 288
#define T_VOID 289
#define T_WHILE 290
#define T_LEFTSHIFT 291
#define T_RIGHTSHIFT 292
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    5,    5,    7,    7,    3,    3,
    9,    9,    9,    4,    4,   13,   14,   14,   16,   16,
   15,   17,   17,   19,   19,   18,   18,   20,   20,   21,
   22,   22,   20,   24,   25,   25,   26,   26,   27,   27,
   20,   20,   20,   20,   20,   20,   20,   20,   23,   23,
   29,   29,   29,   29,   29,   29,   28,   28,   31,   31,
   30,   30,   33,   33,   33,   33,   33,   33,   33,   32,
   32,   32,   32,   32,   32,    8,    8,   10,   10,    6,
    6,   34,   34,   11,   12,   12,
};
static const YYINT yylen[] = {                            2,
    7,    0,    2,    8,    0,    1,    1,    3,    0,    2,
    4,    4,    6,    0,    2,    7,    0,    1,    2,    4,
    4,    0,    2,    4,    4,    0,    2,    1,    2,    3,
    1,    4,    2,    4,    0,    1,    1,    3,    1,    1,
    7,    5,    5,    2,    4,    5,    2,    2,    1,    3,
    1,    1,    1,    1,    1,    1,    1,    3,    1,    1,
    1,    3,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    3,    2,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    4,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    3,    0,    0,    0,
    0,   79,   78,   76,    0,    6,    0,   77,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   10,   80,    0,
   81,    8,    0,    0,    0,    0,    1,   15,    4,    0,
    0,   11,   12,    0,    0,   83,   85,   82,    0,   86,
    0,    0,   18,   84,   13,    0,    0,    0,    0,   20,
    0,   16,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   28,    0,    0,    0,    0,    0,   23,    0,
    0,   47,   48,    0,    0,    0,    0,   44,    0,   21,
   27,   29,    0,   33,   24,   25,   40,    0,    0,    0,
   72,   70,    0,   71,    0,   36,    0,    0,    0,   61,
    0,    0,    0,    0,    0,    0,    0,   75,   74,   55,
   54,   52,   53,   51,   56,    0,   34,    0,   59,   60,
    0,   66,   67,   68,   69,   63,   64,   65,    0,   32,
    0,   45,    0,    0,   73,    0,   38,    0,   62,    0,
   46,   43,    0,   41,
};
static const YYINT yydgoto[] = {                          2,
    3,    4,   20,   26,   15,   30,   16,   17,   21,   18,
   35,  101,   27,   52,   73,   53,   64,   74,   65,   75,
   76,  102,  103,  104,  105,  106,  107,  108,  126,  109,
  131,  110,  139,   50,
};
static const YYINT yysindex[] = {                      -251,
 -226,    0, -212, -251, -201, -194,    0,   40,  -36, -213,
 -205,    0,    0,    0,   44,    0,   46,    0, -179, -172,
 -205, -222, -213,  -80, -171,  -24, -172,    0,    0,   48,
    0,    0, -170,  -57,   50,   72,    0,    0,    0,   20,
 -198,    0,    0, -159, -219,    0,    0,    0,   60,    0,
 -219,   80,    0,    0,    0,   78, -222, -159,    3,    0,
 -165,    0, -146,  -68, -165,  -80,   69,   70,  -27,   91,
  -14,   92,    0,    9,  -68,   74, -123,   77,    0,   79,
   81,    0,    0,  -17,   -6,   -6,  -16,    0,   -6,    0,
    0,    0,   -6,    0,    0,    0,    0,   -6,   -6,   -6,
    0,    0, -154,    0,   96,    0,   95,   39,  -28,    0,
  -90,  -40,   82,   47,   57, -154,   67,    0,    0,    0,
    0,    0,    0,    0,    0,   -6,    0,  -17,    0,    0,
   -6,    0,    0,    0,    0,    0,    0,    0,   -6,    0,
    3,    0,   83,    3,    0,   39,    0,  -28,    0, -121,
    0,    0,    3,    0,
};
static const YYINT yyrindex[] = {                      -138,
    0,    0,    0, -138,    0,    0,    0,    0,    0,  104,
 -113,    0,    0,    0,    0,    0,  105,    0,    0,   22,
 -113,    0,  104,    0,    0,    0,   22,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  107,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  108,    0,    0,    0,    0,
 -105,    0,    0,   25, -105,    0,    0,    0,  -37,    0,
    0,    0,    0,    0,   25,    0,    0,    0,    0,    0,
    0,    0,    0,  110,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   -3,    0,    0,    0,  111,   27,    7,    0,
    0,    0,    0,    0,    0,   94,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   37,    0,   17,    0,  -76,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  150,    0,  137,  132,  138,  103,    0,    0,    0,    8,
   97,  121,    0,    0,  -38,  106,  100,   98,    0,    0,
    0,  -33,    6,  -31,    0,   38,    0,   41,    0,   43,
    0,  -64,    0,    0,
};
#define YYTABLESIZE 346
static const YYINT yytable[] = {                         31,
  141,   42,  140,   31,   31,   31,   31,   31,  138,   31,
   33,    9,   84,  136,    1,  100,  100,   22,  137,   22,
   62,   31,   98,   98,  113,   87,  100,   99,   99,   31,
   77,   34,   78,   98,  118,  119,   12,   39,   99,   12,
   39,   77,    5,   78,   88,   12,   42,   57,   42,   57,
   57,   57,   54,   13,   61,   31,   13,   58,   56,   58,
   58,   58,   13,   85,   31,   57,   29,   49,   46,    6,
   49,    8,   14,   80,  149,   58,   47,   50,    9,   10,
   50,  129,   19,  130,   22,   49,   11,  143,   48,   23,
  111,  112,  114,   24,  115,   50,   25,  144,  116,   57,
   37,   36,  150,  117,   40,  152,   39,  145,   43,   58,
  120,   44,   45,   51,  154,  121,  122,  123,   55,   49,
   57,   58,   63,  124,  125,   61,   66,   82,   83,   50,
   86,   89,   92,   90,   93,   94,  127,   95,  128,   96,
  142,  151,  153,    2,    5,    7,   14,   17,   19,   26,
   35,   37,   30,    7,   22,    9,   22,   28,   38,   59,
   32,   49,   81,   60,   79,  147,  146,   22,   22,    0,
    0,    0,   91,  148,  120,    0,    0,   22,   12,  121,
  122,  123,    0,   42,   22,   42,    0,  124,  125,    0,
    0,   67,    0,   68,    0,   13,   42,   42,    0,    0,
   41,    0,    0,    0,   69,   70,   42,    0,    0,    0,
    0,    0,    0,   42,   71,    0,    0,    0,    0,   31,
   31,   72,    0,    0,  120,    0,    0,   31,  132,  121,
  122,  123,   31,   31,   31,    0,    0,  124,  125,    0,
   31,   31,    0,   31,    0,    0,    0,    0,    0,   46,
   46,    0,  133,   31,   31,   69,   69,   47,   47,    0,
   46,    0,  134,  135,    0,    0,   69,   97,   47,   48,
   48,   57,    0,    0,    0,    0,   57,   57,   57,    0,
   48,   58,    0,    0,   57,   57,   58,   58,   58,    0,
    0,   49,    0,    0,   58,   58,   49,   49,   49,    0,
    0,   50,    0,    0,   49,   49,   50,   50,   50,    0,
    0,  120,    0,    0,   50,   50,  121,  122,  123,    0,
    0,  120,    0,    0,  124,  125,  121,  122,  123,    0,
    0,  120,    0,    0,  124,  125,  121,  122,  123,    0,
    0,    0,    0,    0,  124,  125,
};
static const YYINT yycheck[] = {                         37,
   41,   59,   93,   41,   42,   43,   44,   45,   37,   47,
   91,  125,   40,   42,  266,   33,   33,  123,   47,  125,
   59,   59,   40,   40,   41,   40,   33,   45,   45,   22,
   64,   24,   64,   40,   99,  100,  259,   41,   45,  259,
   44,   75,  269,   75,   59,  259,  123,   41,  125,   43,
   44,   45,   45,  276,  123,   93,  276,   41,   51,   43,
   44,   45,  276,   91,   57,   59,  289,   41,  267,  282,
   44,  273,  286,   66,  139,   59,  275,   41,  273,   40,
   44,   43,  288,   45,   41,   59,  123,   41,  287,   44,
   85,   86,   87,  273,   89,   59,  269,   41,   93,   93,
  125,  273,  141,   98,  275,  144,   59,   41,   59,   93,
  265,   40,   93,  273,  153,  270,  271,  272,   59,   93,
   41,   44,  288,  278,  279,  123,  273,   59,   59,   93,
   40,   40,   59,  125,  258,   59,   41,   59,   44,   59,
   59,   59,  264,  282,   41,   41,  125,   41,   41,  125,
   41,   41,   59,    4,  260,  269,  262,   21,   27,   57,
   23,   41,   66,   58,   65,  128,  126,  273,  274,   -1,
   -1,   -1,   75,  131,  265,   -1,   -1,  283,  259,  270,
  271,  272,   -1,  260,  290,  262,   -1,  278,  279,   -1,
   -1,  260,   -1,  262,   -1,  276,  273,  274,   -1,   -1,
  258,   -1,   -1,   -1,  273,  274,  283,   -1,   -1,   -1,
   -1,   -1,   -1,  290,  283,   -1,   -1,   -1,   -1,  257,
  258,  290,   -1,   -1,  265,   -1,   -1,  265,  257,  270,
  271,  272,  270,  271,  272,   -1,   -1,  278,  279,   -1,
  278,  279,   -1,  281,   -1,   -1,   -1,   -1,   -1,  267,
  267,   -1,  281,  291,  292,  273,  273,  275,  275,   -1,
  267,   -1,  291,  292,   -1,   -1,  273,  285,  275,  287,
  287,  265,   -1,   -1,   -1,   -1,  270,  271,  272,   -1,
  287,  265,   -1,   -1,  278,  279,  270,  271,  272,   -1,
   -1,  265,   -1,   -1,  278,  279,  270,  271,  272,   -1,
   -1,  265,   -1,   -1,  278,  279,  270,  271,  272,   -1,
   -1,  265,   -1,   -1,  278,  279,  270,  271,  272,   -1,
   -1,  265,   -1,   -1,  278,  279,  270,  271,  272,   -1,
   -1,  265,   -1,   -1,  278,  279,  270,  271,  272,   -1,
   -1,   -1,   -1,   -1,  278,  279,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 292
#define YYUNDFTOKEN 329
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,
0,0,0,0,"';'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,
"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"T_AND","T_ASSIGN","T_BOOLTYPE","T_BREAK",
"T_CHARCONSTANT","T_CONTINUE","T_DOT","T_ELSE","T_EQ","T_EXTERN","T_FALSE",
"T_FOR","T_FUNC","T_GEQ","T_GT","T_LT","T_ID","T_IF","T_INTCONSTANT",
"T_INTTYPE","T_LEFTSHT_IFT","T_LEQ","T_NEQ","T_NULL","T_OR","T_PACKAGE",
"T_RETURN","T_RIGHTSHT_IFT","T_STRINGCONSTANT","T_STRINGTYPE","T_TRUE","T_VAR",
"T_VOID","T_WHILE","T_LEFTSHIFT","T_RIGHTSHIFT",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : Start",
"Start : Externs T_PACKAGE T_ID '{' FieldDecls MethodDecls '}'",
"Externs :",
"Externs : ExternDefn Externs",
"ExternDefn : T_EXTERN T_FUNC T_ID '(' ExternParmList ')' MethodType ';'",
"ExternParmList :",
"ExternParmList : FullExternParmList",
"FullExternParmList : ExternType",
"FullExternParmList : ExternType ',' ExternParmList",
"FieldDecls :",
"FieldDecls : FieldDecl FieldDecls",
"FieldDecl : T_VAR T_ID Type ';'",
"FieldDecl : T_VAR T_ID ArrayType ';'",
"FieldDecl : T_VAR T_ID Type T_ASSIGN Constant ';'",
"MethodDecls :",
"MethodDecls : MethodDecl MethodDecls",
"MethodDecl : T_FUNC T_ID '(' MethodParmList ')' MethodType Block",
"MethodParmList :",
"MethodParmList : FullMethodParmList",
"FullMethodParmList : T_ID Type",
"FullMethodParmList : T_ID Type ',' FullMethodParmList",
"Block : '{' VarDecls Statements '}'",
"VarDecls :",
"VarDecls : VarDecl VarDecls",
"VarDecl : T_VAR T_ID Type ';'",
"VarDecl : T_VAR T_ID ArrayType ';'",
"Statements :",
"Statements : Statement Statements",
"Statement : Block",
"Statement : Assign ';'",
"Assign : Lvalue T_ASSIGN Expr",
"Lvalue : T_ID",
"Lvalue : T_ID '[' Expr ']'",
"Statement : MethodCall ';'",
"MethodCall : T_ID '(' MethodCallList ')'",
"MethodCallList :",
"MethodCallList : FullMethodCallList",
"FullMethodCallList : MethodArg",
"FullMethodCallList : MethodArg ',' FullMethodCallList",
"MethodArg : Expr",
"MethodArg : T_STRINGCONSTANT",
"Statement : T_IF '(' Expr ')' Block T_ELSE Block",
"Statement : T_IF '(' Expr ')' Block",
"Statement : T_WHILE '(' Expr ')' Block",
"Statement : T_RETURN ';'",
"Statement : T_RETURN '(' ')' ';'",
"Statement : T_RETURN '(' Expr ')' ';'",
"Statement : T_BREAK ';'",
"Statement : T_CONTINUE ';'",
"Expr : Additiveexpression",
"Expr : Expr Relop Additiveexpression",
"Relop : T_LEQ",
"Relop : T_GT",
"Relop : T_LT",
"Relop : T_GEQ",
"Relop : T_EQ",
"Relop : T_NEQ",
"Additiveexpression : Term",
"Additiveexpression : Additiveexpression Addop Term",
"Addop : '+'",
"Addop : '-'",
"Term : Factor",
"Term : Term Multop Factor",
"Multop : '*'",
"Multop : '/'",
"Multop : '%'",
"Multop : T_AND",
"Multop : T_OR",
"Multop : T_LEFTSHIFT",
"Multop : T_RIGHTSHIFT",
"Factor : Lvalue",
"Factor : MethodCall",
"Factor : Constant",
"Factor : '(' Expr ')'",
"Factor : '!' Factor",
"Factor : '-' Factor",
"ExternType : T_STRINGTYPE",
"ExternType : Type",
"Type : T_INTTYPE",
"Type : T_BOOLTYPE",
"MethodType : T_VOID",
"MethodType : Type",
"BoolConstant : T_TRUE",
"BoolConstant : T_FALSE",
"ArrayType : '[' T_INTCONSTANT ']' Type",
"Constant : T_INTCONSTANT",
"Constant : BoolConstant",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 256 "lab6.y"
  /* end of rules, start of program */

int main()
{ 
  yyparse();
}
#line 488 "y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 2:
#line 117 "lab6.y"
	{ 
                        yyval.astnode = NULL;
                      }
break;
case 3:
#line 121 "lab6.y"
	{ 
                        yyval.astnode = NULL;
                      }
break;
case 4:
#line 127 "lab6.y"
	{ 
                        yyval.astnode = ASTCreateNode( A_EXTERN );
                      }
break;
#line 705 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
