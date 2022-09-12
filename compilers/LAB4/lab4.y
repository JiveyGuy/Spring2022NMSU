%{

/*
 *			**** CALC ****
 *
 * This routine will function like a desk calculator
 * There are 26 integer registers, named 'a' thru 'z'
 *
 */

/* This calculator depends on a LEX description which outputs either VARIABLE or INTEGER.
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
		

*/


	/* begin specs */
#include <stdio.h>
#include <ctype.h>
#include "symtable.h"

int yylex(); // Added this to supress warn

int regs[26];
extern int debugsw;
int base;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s\n", s);
}


%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */

%start list

%token INTEGER
%token VARIABLE

%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%left UMINUS


%%	/* end specs, begin rules */

list	:	/* empty */
	|	list stat '\n'
	|	list error '\n'
			{ yyerrok; }
	;

stat	:	expr /* fixed spelling of awnser and spacing */
			{ fprintf(stderr,"the awnser is %d\n", $1); }
	|	VARIABLE '=' expr
			{ regs[$1] = $3; }
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
			$$ = regs[$1];
			fprintf(stderr,"found a variable value = %d\n",$1); 
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
