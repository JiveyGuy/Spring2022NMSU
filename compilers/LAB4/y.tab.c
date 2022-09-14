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

#line 2 "lab4.y"

/*
	██╗      █████╗ ██████╗     ██╗  ██╗
	██║     ██╔══██╗██╔══██╗    ██║  ██║
	██║     ███████║██████╔╝    ███████║
	██║     ██╔══██║██╔══██╗    ╚════██║
	███████╗██║  ██║██████╔╝         ██║
	╚══════╝╚═╝  ╚═╝╚═════╝          ╚═╝
	                                    

  			**** CALC ****
  
   This routine will function like a desk calculator
   There are 26 integer registers, named 'a' thru 'z'
  
   This calculator depends on a LEX description which outputs either VARIABLE or INTEGER.
   The return type via yylval is integer 

   When we need to make yylval more complicated, we need to define a pointer type for yylval 
   and to instruct YACC to use a new type so that we can pass back better values
 
   The registers are based on 0, so we substract 'a' from each single letter we get.

   based on context, we have YACC do the correct memmory look up or the storage depending
   on position

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
*/


	/* begin specs */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "symtable.h"

#define MAX_VARS 3
extern int debugsw;

int yylex(); /* Added this to supress warn*/

int regs[MAX_VARS]; /* probs make dynamic*/
int regc = 0;
int base;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s\n", s);
}


#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 73 "lab4.y"
typedef union YYSTYPE
{
	int value;
	char* string;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 102 "y.tab.c"

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

#define INTEGER 257
#define VARIABLE 258
#define T_INT 259
#define UMINUS 260
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    2,    2,    4,    3,    3,    3,    5,    5,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
};
static const YYINT yylen[] = {                            2,
    2,    2,    0,    4,    0,    3,    3,    1,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    2,    1,    1,
};
static const YYINT yydefred[] = {                         3,
    0,    0,    0,    0,    2,    0,    0,   20,    0,    0,
    0,    0,    0,    0,    7,    0,   19,   18,    0,    0,
    0,    0,    0,    0,    0,    0,    6,    4,    0,   10,
    0,    0,    0,    0,   13,   14,   15,
};
static const YYINT yydgoto[] = {                          1,
   12,    2,    4,    5,   13,
};
static const YYINT yysindex[] = {                         0,
    0, -255, -249,  -40,    0,  -49,    3,    0,  -36,  -38,
  -38,   19,   23,   33,    0,  -38,    0,    0,  -26,  -38,
  -38,  -38,  -38,  -38,  -38,  -38,    0,    0,   19,    0,
   39,  -19,  -15,  -15,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    1,    0,   29,    0,    0,    0,    0,   -7,    0,
    0,   34,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   40,    0,
   -2,   -4,    4,   10,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   49,    0,    0,    0,    0,
};
#define YYTABLESIZE 259
static const YYINT yytable[] = {                         11,
    5,   11,   19,    3,   10,   16,   10,   17,    6,   14,
   26,   21,   15,   12,   30,   24,   22,   26,   23,   11,
   25,   26,   24,   22,   16,   23,   24,   25,    1,   19,
   19,   25,   27,   16,   19,   19,   16,   19,   17,   19,
    5,   12,   28,    8,   12,    5,   12,   11,   12,    9,
   11,    0,   11,    0,   11,   26,   21,    0,   18,   19,
   24,   22,    0,   23,   29,   25,    0,    0,   31,   32,
   33,   34,   35,   36,   37,   26,   21,    0,    0,    0,
   24,   22,    0,   23,    0,   25,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   20,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   19,    0,    0,   16,
    0,   17,    0,    0,    0,    0,    0,   12,    0,    0,
    0,    0,    0,   11,    0,    0,    0,    0,    0,    0,
    0,    0,   20,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    7,    8,    9,    8,   17,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    5,    5,    5,
};
static const YYINT yycheck[] = {                         40,
    0,   40,   10,  259,   45,   10,   45,   10,  258,   59,
   37,   38,   10,   10,   41,   42,   43,   37,   45,   10,
   47,   37,   42,   43,   61,   45,   42,   47,    0,   37,
   38,   47,   10,   38,   42,   43,   41,   45,   41,   47,
   40,   38,   10,   10,   41,   45,   43,   38,   45,   10,
   41,   -1,   43,   -1,   45,   37,   38,   -1,   10,   11,
   42,   43,   -1,   45,   16,   47,   -1,   -1,   20,   21,
   22,   23,   24,   25,   26,   37,   38,   -1,   -1,   -1,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,  124,
   -1,  124,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,
   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  256,  257,  258,  257,  258,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  256,  257,  258,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 260
#define YYUNDFTOKEN 268
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,
0,0,0,0,"';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'|'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"INTEGER","VARIABLE","T_INT","UMINUS",0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : P",
"P : DECLS list",
"DECLS : DECLS DECL",
"DECLS :",
"DECL : T_INT VARIABLE ';' '\\n'",
"list :",
"list : list stat '\\n'",
"list : list error '\\n'",
"stat : expr",
"stat : VARIABLE '=' expr",
"expr : '(' expr ')'",
"expr : expr '-' expr",
"expr : expr '+' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : '-' expr",
"expr : VARIABLE",
"expr : INTEGER",

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
#line 184 "lab4.y"
	/* end of rules, start of program */

int main()
{ 
	yyparse();
}
#line 322 "y.tab.c"

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
case 4:
#line 101 "lab4.y"
	{
	fprintf(stderr, "Found a variable with the value %s\n", yystack.l_mark[-2].string);
	if( Search(yystack.l_mark[-2].string) == 1){
		fprintf(stderr, "ERROR: Vairable \"%s\" already exists! \n", yystack.l_mark[-2].string);
		fprintf(stderr, "\t VARIABLE T_INT \"%s\" not created.\n", yystack.l_mark[-2].string );
	}
	else if( regc >= MAX_VARS ){
		fprintf(stderr, "ERROR: number of vars too great, MAX_VARS = %d\n", MAX_VARS);
		fprintf(stderr, "\t VARIABLE T_INT \"%s\" not created.\n", yystack.l_mark[-2].string );
	}
	else
	{
		Insert(yystack.l_mark[-2].string, regc++);	
	} 
}
break;
case 7:
#line 120 "lab4.y"
	{ 
				yyerrok; 
			}
break;
case 8:
#line 126 "lab4.y"
	{ 
				fprintf(stderr,"the awnser is %d\n", yystack.l_mark[0].value);					
			}
break;
case 9:
#line 131 "lab4.y"
	{
				/* VARIABLE is a char* */
				/* 		Can't index array based on that*/
				if( Search(yystack.l_mark[-2].string) == 0){
					fprintf(stderr, "ERROR: VARIABLE \"%s\" does not exists! \n", yystack.l_mark[-2].string);
					fprintf(stderr, "\t failed to execute command.\n");
					exit(-1);
				}
				else{
					regs[fetch_addr(yystack.l_mark[-2].string)] = yystack.l_mark[0].value; 
				}
				
			}
break;
case 10:
#line 147 "lab4.y"
	{ yyval.value = yystack.l_mark[-1].value; }
break;
case 11:
#line 149 "lab4.y"
	{ yyval.value = yystack.l_mark[-2].value - yystack.l_mark[0].value; }
break;
case 12:
#line 151 "lab4.y"
	{ yyval.value = yystack.l_mark[-2].value + yystack.l_mark[0].value; }
break;
case 13:
#line 153 "lab4.y"
	{ yyval.value = yystack.l_mark[-2].value * yystack.l_mark[0].value; }
break;
case 14:
#line 155 "lab4.y"
	{ yyval.value = yystack.l_mark[-2].value / yystack.l_mark[0].value; }
break;
case 15:
#line 157 "lab4.y"
	{ yyval.value = yystack.l_mark[-2].value % yystack.l_mark[0].value; }
break;
case 16:
#line 159 "lab4.y"
	{ yyval.value = yystack.l_mark[-2].value & yystack.l_mark[0].value; }
break;
case 17:
#line 161 "lab4.y"
	{ yyval.value = yystack.l_mark[-2].value | yystack.l_mark[0].value; }
break;
case 18:
#line 163 "lab4.y"
	{ yyval.value = -1 * yystack.l_mark[0].value; }
break;
case 19:
#line 165 "lab4.y"
	{ 
			if( Search(yystack.l_mark[0].string) == 0){
				fprintf(stderr, "ERROR: VARIABLE \"%s\" does not exists! \n", yystack.l_mark[0].string);
				fprintf(stderr, "\t failed to get value of VARIABLE.\n");
				exit(-1);
			}
			else{
				yyval.value = regs[fetch_addr(yystack.l_mark[0].string)];
				fprintf(stderr,"found a VARIABLE value = %s\n",yystack.l_mark[0].string); 
			}
		}
break;
case 20:
#line 178 "lab4.y"
	{
			yyval.value=yystack.l_mark[0].value;
			fprintf(stderr,"found an integer\n");
		}
break;
#line 624 "y.tab.c"
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
