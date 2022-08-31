%{

/*  This lex routine uses a counting array to match alphabeticstrings 
     and make a frequency count.

     The real item to notice is that yywrap() is called at EOF and then is run
     to do what we need to do.   yywrap() returns true when we have a successful 
     end to the program.  We may want to return false (0) if we want to lexing process 
     to fail 

	Original:
	    Shaun Cooper
	    January 2015

	Edit:
	    Jason Ivey
	    August 2022
*/

/* J.Ivey:8222022 Global vars!*/
int lgths[100];
int num_count=1;
%}
%%
[a-zA-Z]+	{  /* this matches one or more lower/Upper alpha chars,
						> when matched inport length of sequence into
						> array lgths through ++ operator */
	         lgths[yyleng]++; 
	     	} 
[0-9]+		{ /* match one or more digit sequence and increment num_count */
			  num_count++;
			}
.|\n		{ /*no action*/ };

%%
int yywrap()
{ /* int yywrap() : J.Ivey:8222022 Mandatory user subroutine for on exit.*/
	int i;
	printf("Length  No. words\n");
	// for loop goes through each item in the array
	for (i=0; i<100; i++) 
	{
		// if the array is non-zero
		if (lgths[i] > 0) 
		{
			/* J.Ivey:8222022 stdout: a double col. of index|count*/
			printf("%5d%10d\n",i,lgths[i]);
		}
	}
	/* J.Ivey:8222022 Report number of numbers to stdout*/
	printf("Number of numbers = %d\n", num_count);
	return 1;
}

int main()
{ 
	/* J.Ivey:8222022 Run lex FSM*/
	return yylex();
}