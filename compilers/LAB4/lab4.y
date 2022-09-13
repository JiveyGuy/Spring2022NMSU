%{

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
#include <stdlib.h>
#include "symtable.h"

#define MAX_VARS 3
extern int debugsw;

int yylex(); // Added this to supress warn

int regs[MAX_VARS]; // probs make dynamic
int regc = 0;
int base;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s\n", s);
}


%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */

%start P
%union
{
	int value;
	char* string;
}

%token <value>  INTEGER
%token <string> VARIABLE
%token T_INT

%type <value> expr

%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%left UMINUS

%%	/* end specs, begin rules */

P : DECLS list
	;

DECLS : DECLS DECL 
	| /* empty */
	;

DECL : T_INT VARIABLE ';' '\n' {
	fprintf(stderr, "Found a variable with the value %s\n", $2);
	if( Search($2) == 1){
		fprintf(stderr, "ERROR: Vairable \"%s\" already exists! \n", $2);
		fprintf(stderr, "\t VARIABLE T_INT \"%s\" not created.\n", $2 );
	}
	else if( regc >= MAX_VARS ){
		fprintf(stderr, "ERROR: number of vars too great, MAX_VARS = %d\n", MAX_VARS);
		fprintf(stderr, "\t VARIABLE T_INT \"%s\" not created.\n", $2 );
	}
	else
	{
		Insert($2, regc++);	
	} 
}

list	:	/* empty */
	|	list stat '\n'
	|	list error '\n'
			{ 
				yyerrok; 
			}
	;

stat	:	expr /* fixed spelling of awnser and spacing */
			{ 
				fprintf(stderr,"the awnser is %d\n", $1);					
			}

	|	VARIABLE '=' expr
			{
				// VARIABLE is a char* 
				// 		Can't index array based on that
				if( Search($1) == 0){
					fprintf(stderr, "ERROR: VARIABLE \"%s\" does not exists! \n", $1);
					fprintf(stderr, "\t failed to execute command.\n");
					exit(-1);
				}
				else{
					regs[fetch_addr($1)] = $3; 
				}
				
			}
	;

expr	:	'(' expr ')'
			{ $$ = $2; }
	|	expr '-' expr
			{ $$ = $1 - $3; }
	|	expr '+' expr
			{ $$ = $1 + $3; }
	|	expr '*' expr
			{ $$ = $1 * $3; }
	|	expr '/' expr
			{ $$ = $1 / $3; }
	|	expr '%' expr
			{ $$ = $1 % $3; }
	|	expr '&' expr
			{ $$ = $1 & $3; }
	|	expr '|' expr
			{ $$ = $1 | $3; }
	|	'-' expr %prec UMINUS  /* fixed by removing left expr */
			{ $$ = -1 * $2; }
	|	VARIABLE
		{ 
			if( Search($1) == 0){
				fprintf(stderr, "ERROR: VARIABLE \"%s\" does not exists! \n", $1);
				fprintf(stderr, "\t failed to get value of VARIABLE.\n");
				exit(-1);
			}
			else{
				$$ = regs[fetch_addr($1)];
				fprintf(stderr,"found a VARIABLE value = %s\n",$1); 
			}
		}

	|	INTEGER
		{
			$$=$1;
			fprintf(stderr,"found an integer\n");
		}
	;

%%	/* end of rules, start of program */

int main()
{ 
	yyparse();
}