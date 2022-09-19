/* 
    ██╗      █████╗ ██████╗     ██╗  ██╗
    ██║     ██╔══██╗██╔══██╗    ██║  ██║
    ██║     ███████║██████╔╝    ███████║
    ██║     ██╔══██║██╔══██╗    ╚════██║
    ███████╗██║  ██║██████╔╝         ██║
    ╚══════╝╚═╝  ╚═╝╚═════╝          ╚═╝
                                    

    Small LEX routine which returns two formal tokens
    (INTEGER and VARIABLE) along with single string 
    elements like '+'.

    This LEX definition is the companion to the docalc.y
    YACC routine which is a simple calculator

Author: Shaun Cooper
    January 2015

Editted by Jason Ivey, Sep 4, 2022:
    Made debug = 0
    added () to token list

Editted by Jason Ivey, Sep 12, 2022:
    added int rule
    added ; to catchall

input: text
    assumptions: yacc will handle syntax error

                 var names are letters numbers, 
                    but don't start with numbers


output: tokens

*/

%{
    int mydebug = 0; //Change 0 before submit
    #include "y.tab.h"
%}


%%
int         {
    return(T_INT);
}

[a-z][a-z_0-9]*		{
    if (mydebug) 
        fprintf(stderr, "Variable found\n"); 
    
    yylval.string = strdup(yytext); 

    return(VARIABLE);
}

\-?[0-9][0-9]*	{
    if (mydebug) 
        fprintf(stderr,"Digit found\n"); 

    yylval.value = atoi((const char *)yytext); 

    return(INTEGER);
}

[ \t]		{
    if (mydebug)
        fprintf(stderr,"Whitespace found\n");
}

[;=()\-+*/%&|] 	{ /* added () */
    if (mydebug)
        fprintf(stderr,"return a token %c\n",*yytext);

    return (*yytext);
}

\n 		{
    if (mydebug)
        fprintf(stderr,"cariage return %c\n",*yytext); 
    
    return (*yytext);
}

%%

int yywrap(void)
{ 
    return 1;
}