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

#line 2 "lab5.y"

/*
/_/\     /_______/\ /_______/\     /_____/\    
\:\ \    \::: _  \ \\::: _  \ \    \::::_\/_   
 \:\ \    \::(_)  \ \\::(_)  \/_    \:\/___/\  
  \:\ \____\:: __  \ \\::  _  \ \    \_::._\:\ 
   \:\/___/\\:.\ \  \ \\::(_)  \ \    /_____\/ 
    \_____\/ \__\/\__\/ \_______\/    \_____/ 
	                                    
 			
   Shaun Cooper
    January 2015

   problems  fix unary minus, fix parenthesis, add multiplication
   problems  make it so that verbose is on and off with an input argument instead of compiled in
	
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
        tokens


	INPUT: LEX Description + Text
	OUTPUT: y.tab.c /h 
*/

/* begin specs */
#include <stdio.h>
#include <ctype.h>

/* Added this to supress warn*/
extern int yylex(void);
extern int line_num; /*for line_num in yyerror*/

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
#line 69 "lab5.y"
typedef union YYSTYPE
{
	int value;
	char* string;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 94 "y.tab.c"

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
    0,    1,    1,    4,    5,    5,    7,    7,    2,    2,
    9,    9,    9,    3,    3,   13,   14,   14,   16,   16,
   15,   17,   17,   19,   19,   18,   18,   20,   20,   21,
   22,   22,   20,   24,   25,   25,   26,   26,   27,   27,
   20,   20,   20,   20,   20,   20,   20,   20,   23,   28,
   28,   30,   30,   30,   30,   30,   30,   29,   29,   32,
   32,   31,   31,   34,   34,   34,   34,   34,   34,   34,
   33,   33,   33,   33,   33,   33,   33,    8,    8,   10,
   10,    6,    6,   35,   35,   11,   12,   12,   12,
};
static const YYINT yylen[] = {                            2,
    7,    0,    2,    8,    0,    1,    1,    3,    0,    2,
    4,    4,    6,    0,    2,    7,    0,    1,    2,    4,
    4,    0,    2,    4,    4,    0,    2,    1,    2,    3,
    1,    4,    2,    4,    0,    1,    1,    3,    1,    1,
    7,    5,    5,    2,    4,    5,    2,    2,    1,    1,
    3,    1,    1,    1,    1,    1,    1,    1,    3,    1,
    1,    1,    3,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    4,    1,    3,    2,    2,    1,    1,    1,
    1,    1,    1,    1,    1,    4,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    3,    0,    0,    0,
    0,   81,   80,   78,    0,    6,    0,   79,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   10,   82,    0,
   83,    8,    0,    0,    0,    0,    1,   15,    4,    0,
    0,   11,   12,    0,    0,   85,   87,   89,   84,    0,
   88,    0,    0,   18,   86,   13,    0,    0,    0,    0,
   20,    0,   16,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   28,    0,    0,    0,    0,    0,   23,
    0,    0,   47,   48,    0,    0,    0,    0,   44,    0,
   21,   27,   29,    0,   33,   24,   25,    0,    0,    0,
    0,    0,   74,   39,   72,    0,   36,    0,    0,    0,
    0,   62,    0,    0,    0,    0,    0,   30,    0,    0,
   77,   76,   34,    0,   56,   55,   53,   54,   52,   57,
    0,   60,   61,    0,   67,   68,   69,   70,   64,   65,
   66,    0,   32,    0,   45,    0,    0,    0,   75,   38,
    0,    0,   63,    0,   46,   43,   73,    0,   41,
};
static const YYINT yydgoto[] = {                          2,
    3,   20,   26,    4,   15,   30,   16,   17,   21,   18,
   35,  103,   27,   53,   74,   54,   65,   75,   66,   76,
   77,   78,  104,  105,  106,  107,  108,  109,  110,  131,
  111,  134,  112,  142,   51,
};
static const YYINT yysindex[] = {                      -253,
 -219,    0, -228, -253, -211, -210,    0,   28,  -50, -225,
 -200,    0,    0,    0,   37,    0,   45,    0, -182, -176,
 -200, -234, -225,  -89, -179,  -28, -176,    0,    0,   40,
    0,    0, -172,  -58,   47,   56,    0,    0,    0,   14,
 -208,    0,    0, -165, -189,    0,    0,    0,    0,   50,
    0, -189,   70,    0,    0,    0,   68, -234, -165,  -10,
    0, -174,    0, -157,  -85, -174,  -89,   58,   59,  -25,
   79,  -16,   81,    0,   -3,  -85,   64, -130,   71,    0,
   72,   73,    0,    0,    8,   12,   12,   -1,    0,   12,
    0,    0,    0,   12,    0,    0,    0,  -22,    0,   12,
   12,   12,    0,    0,    0,   94,    0,   92,  -87,   38,
  -21,    0,   44,   97,   82,   99,  101,    0,   12,  102,
    0,    0,    0,    8,    0,    0,    0,    0,    0,    0,
   12,    0,    0,   12,    0,    0,    0,    0,    0,    0,
    0,   12,    0,  -10,    0,   86,  -10,   57,    0,    0,
   38,  -21,    0, -112,    0,    0,    0,  -10,    0,
};
static const YYINT yyrindex[] = {                      -129,
    0,    0,    0, -129,    0,    0,    0,    0,    0,  114,
 -122,    0,    0,    0,    0,    0,  115,    0,    0,   32,
 -122,    0,  114,    0,    0,    0,   32,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  120,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  123,    0,  120,    0,
    0, -114,    0,    0,   42, -114,    0,    0,    0,  -93,
    0,    0,    0,    0,    0,   42,    0,    0,    0,    0,
    0,    0,    0,    0,  125,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -37,  -14,    0,
    0,    0,    0,    0,    0,    0,    0,  127,    5,   51,
   31,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  125,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   61,   41,    0, -111,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  167,  152,  147,    0,  157,  124,    0,    0,    0,   13,
  119,  140,    0,  131,  -43,    0,  128,  117,    0,    0,
    0,    0,   39,  -29,   75,    0,    0,    0,   65,    0,
   63,    0,  -82,    0,    0,
};
#define YYTABLESIZE 340
static const YYINT yytable[] = {                         71,
   42,   33,    9,   71,   71,   71,   71,   71,   22,   71,
   22,   42,    1,   42,   85,  141,   63,   85,  121,  122,
  139,   71,   89,   88,   12,  140,   40,   89,   89,   40,
   89,  102,   89,   12,   31,   79,   34,   62,  100,  115,
  102,   13,   89,  101,  102,   49,   79,  100,   49,    5,
   13,  100,  101,    6,   29,   71,  101,   55,   46,  153,
   14,    8,    9,   49,   57,   86,   47,   10,  119,   12,
   31,   58,   11,   58,   58,   58,   48,   22,   49,   81,
  132,   59,  133,   59,   59,   59,   13,   19,   23,   58,
   24,   50,   25,   36,   50,   44,   37,   49,   39,   59,
  154,   51,   40,  156,   51,   43,   45,   52,   56,   50,
   58,   59,   62,   64,  159,   67,   83,   84,   87,   51,
   90,   91,   93,   58,  113,  114,  116,   94,  117,   95,
   96,   97,  118,   59,  123,  124,  143,  144,  120,  146,
  145,  147,  149,   50,  155,   22,    9,   22,   42,  157,
   42,  158,    2,   51,    5,    7,   14,  148,   22,   22,
   17,   42,   42,   19,   31,   35,   26,   37,   22,   12,
    7,   42,   28,   38,   68,   22,   69,  125,   42,   32,
   50,   60,  126,  127,  128,   82,   13,   70,   71,   61,
  129,  130,   92,   80,    0,  151,  152,   72,  150,   41,
    0,    0,    0,    0,   73,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   71,
    0,    0,    0,    0,    0,    0,    0,   71,    0,    0,
    0,    0,   71,   71,   71,  135,    0,    0,    0,    0,
   71,   71,   89,   71,    0,    0,    0,    0,    0,    0,
   89,    0,    0,   71,   71,   89,   89,   89,    0,  136,
    0,    0,    0,   89,   89,   46,   89,    0,    0,  137,
  138,   98,    0,   47,   46,    0,   89,   89,   46,    0,
   98,    0,   47,   48,   98,   49,   47,    0,    0,    0,
    0,    0,   99,    0,   49,   58,   48,    0,   49,    0,
   58,   58,   58,    0,    0,   59,    0,    0,   58,   58,
   59,   59,   59,    0,    0,   50,    0,    0,   59,   59,
   50,   50,   50,    0,    0,   51,    0,    0,   50,   50,
   51,   51,   51,    0,    0,    0,    0,    0,   51,   51,
};
static const YYINT yycheck[] = {                         37,
   59,   91,  125,   41,   42,   43,   44,   45,  123,   47,
  125,  123,  266,  125,   40,   37,   60,   40,  101,  102,
   42,   59,   37,   40,  259,   47,   41,   42,   43,   44,
   45,   33,   47,  259,   22,   65,   24,  123,   40,   41,
   33,  276,   59,   45,   33,   41,   76,   40,   44,  269,
  276,   40,   45,  282,  289,   93,   45,   45,  267,  142,
  286,  273,  273,   59,   52,   91,  275,   40,   91,  259,
   58,   41,  123,   43,   44,   45,  285,   41,  287,   67,
   43,   41,   45,   43,   44,   45,  276,  288,   44,   59,
  273,   41,  269,  273,   44,   40,  125,   93,   59,   59,
  144,   41,  275,  147,   44,   59,   93,  273,   59,   59,
   41,   44,  123,  288,  158,  273,   59,   59,   40,   59,
   40,  125,   59,   93,   86,   87,   88,  258,   90,   59,
   59,   59,   94,   93,   41,   44,   93,   41,  100,   41,
   59,   41,   41,   93,   59,  260,  269,  262,  260,   93,
  262,  264,  282,   93,   41,   41,  125,  119,  273,  274,
   41,  273,  274,   41,  258,   41,  125,   41,  283,  259,
    4,  283,   21,   27,  260,  290,  262,  265,  290,   23,
   41,   58,  270,  271,  272,   67,  276,  273,  274,   59,
  278,  279,   76,   66,   -1,  131,  134,  283,  124,  258,
   -1,   -1,   -1,   -1,  290,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  265,   -1,   -1,
   -1,   -1,  270,  271,  272,  257,   -1,   -1,   -1,   -1,
  278,  279,  257,  281,   -1,   -1,   -1,   -1,   -1,   -1,
  265,   -1,   -1,  291,  292,  270,  271,  272,   -1,  281,
   -1,   -1,   -1,  278,  279,  267,  281,   -1,   -1,  291,
  292,  273,   -1,  275,  267,   -1,  291,  292,  267,   -1,
  273,   -1,  275,  285,  273,  287,  275,   -1,   -1,   -1,
   -1,   -1,  285,   -1,  287,  265,  285,   -1,  287,   -1,
  270,  271,  272,   -1,   -1,  265,   -1,   -1,  278,  279,
  270,  271,  272,   -1,   -1,  265,   -1,   -1,  278,  279,
  270,  271,  272,   -1,   -1,  265,   -1,   -1,  278,  279,
  270,  271,  272,   -1,   -1,   -1,   -1,   -1,  278,  279,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 292
#define YYUNDFTOKEN 330
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : Program",
"Program : Externs T_PACKAGE T_ID '{' FieldDecls MethodDecls '}'",
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
"FullMethodParmList : T_ID Type ',' MethodParmList",
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
"FullMethodCallList : MethodArg ',' MethodCallList",
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
"Expr : Simpleexpression",
"Simpleexpression : Additiveexpression",
"Simpleexpression : Simpleexpression Relop Additiveexpression",
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
"Factor : T_ID",
"Factor : MethodCall",
"Factor : T_ID '[' Expr ']'",
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
"Constant : T_STRINGCONSTANT",

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
#line 251 "lab5.y"
	/* end of rules, start of program */

int main()
{ 
	yyparse();
}
#line 492 "y.tab.c"

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
