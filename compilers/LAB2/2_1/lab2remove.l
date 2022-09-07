         /* simple lex program which removes comments from a source program
            The main key is that a variable "comment" is set when the start of a comment
            is seen and then unset when the ending set is seen.  It is possible to have
            two starts closed by on end.

            Shaun Cooper
            January 2015

            Editted by Jason Ivey 2022:
            I added a line counter called "line_c" starting
            at 1 because most text editors display line numbers
            starting at 1.

            Added a line counter to incriment using "++" when \n
            is found.

            Added int type to main so it wont give default return
            type warning. 

 
         */
        int comment = 0; /* Made this so it is 0 until comment start is detected */ 
        int debug = 1; /* prints out debug statements if desired */
        int line_c = 1;  /* line counter */
%%
int yylex();
"/*"	{
        if (comment && debug) // made this so that this only print if db & prev comment
          fprintf(
            stderr,
            " >>>>>>>> line %d: Possible Nested comment <<<<<<<<<<\n",
            line_c
          ); /* Adds line_c to fprintf */

        comment = 1;
	    }

"*/"	  {
          if (!comment) printf("%s",yytext); /*print out if it is not in a comment */
  	  comment = 0;
	}
"\n"    {
          line_c++;
          if( comment == 0)
            printf("\n");
}
.       { if (!comment)printf("%s",yytext);}

%%

int yywrap(void)
{ 
  return 1;
}
// added int type
int main()
{
  yylex();
  
}

