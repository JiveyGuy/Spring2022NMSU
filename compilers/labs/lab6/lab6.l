/* 
# ██╗      █████╗ ██████╗  ██████╗ 
# ██║     ██╔══██╗██╔══██╗██╔════╝ 
# ██║     ███████║██████╔╝███████╗ 
# ██║     ██╔══██║██╔══██╗██╔═══██╗
# ███████╗██║  ██║██████╔╝╚██████╔╝
# ╚══════╝╚═╝  ╚═╝╚═════╝  ╚═════╝ 

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

Editted by Jason Ivey, Sep 25, 2022:
    added new patterns
    adde line count feature

input: text
    assumptions: yacc will handle syntax error

                 var names are letters numbers, 
                    but don't start with numbers


output: tokens

*/

%{
    
    #include "y.tab.h"
    int line_num = 1;
    int DEBUG = 1; //Change 0 before submit
    int hex_to_int(char * hex_input);
%}


%%

"&&"            {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_AND\n");
                    return T_AND;           
                }

"="             {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_ASSIGN\n");
                    return T_ASSIGN;        
                }

"bool"          {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_BOOLTYPE\n");
                    return T_BOOLTYPE;      
                }

"break"         {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_BREAK\n");
                    return T_BREAK;         
                }

"char_lit"      {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_CHARCONSTANT\n");
                    return T_CHARCONSTANT;  
                }

"continue"      {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_CONTINUE\n");
                    return T_CONTINUE;      
                }

"."             {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_DOT\n");
                    return T_DOT;           
                }

"else"          {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_ELSE\n");
                    return T_ELSE;          
                }

"=="            {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_EQ\n");
                    return T_EQ;            
                }

"extern"        {
                    if ( DEBUG == 1 ) printf("DEBUG: found T_EXTERN\n");
                    return T_EXTERN;        
                }

"false"         {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_FALSE\n");
                    return T_FALSE;         
                }

"for"           {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_FOR\n");
                    return T_FOR;           
                }

"func"          {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_FUNC\n");
                    return T_FUNC;          
                }

">="            {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_GEQ\n");
                    return T_GEQ;           
                }

">"             {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_GT\n");
                    return T_GT;            
                }

"identifier"    {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_ID\n");
                    return T_ID;            
                }

"if"            {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_IF\n");
                    return T_IF;            
                }

"int_lit"       {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_INTCONSTANT\n");
                    return T_INTCONSTANT;   
                }

"int"           {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_INTTYPE\n");
                    return T_INTTYPE;       
                }

"<<"            {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_LEFTSHIFT\n");
                    return T_LEFTSHIFT;     
                }

"<="            {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_LEQ\n");
                    return T_LEQ;           
                }

"!="            {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_NEQ\n");
                    return T_NEQ;           
                }

"null"          {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_NULL\n");
                    return T_NULL;          
                }

"||"            {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_OR\n");
                    return T_OR;            
                }

"package"       {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_PACKAGE\n");
                    return T_PACKAGE;       
                }

"return"        {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_RETURN\n");
                    return T_RETURN;        
                }

">>"            {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_RIGHTSHIFT\n");
                    return T_RIGHTSHIFT;    
                }

"string_lit"    {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_STRINGCONSTANT\n");
                    return T_STRINGCONSTANT;
                }

"string"        {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_STRINGTYPE\n");
                    return T_STRINGTYPE;    
                }

"true"          {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_TRUE\n");
                    return T_TRUE;          
                }

"var"           {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_VAR\n");
                    return T_VAR;           
                }

"void"          {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_VOID\n");
                    return T_VOID;          
                }

"while"         {
                    if ( DEBUG == 1 ) printf( "DEBUG: found T_WHILE\n");
                    return T_WHILE;         
                }
               
\'.\'           {
                    yylval.value = yytext[1];
                    return T_CHARCONSTANT;
                }

\".*\"          {
                    yylval.value = yytext[1];
                    return T_STRINGCONSTANT;
                }

[a-zA-Z][a-z_A-Z0-9]*    {
                    
                    yylval.string = strdup(yytext);

                    if(DEBUG == 1)
                    {
                        fprintf(stderr, "DEBUG: T_ID found.\n", line_num);
                        printf("DEBUG: T_ID = %s\n", strdup(yytext)); 
                    }

                    return T_ID;
                }


[0-9][0-9]*    {
                    
                    yylval.value = atoi((char *)yytext);

                    if(DEBUG == 1)
                    {
                        fprintf(stderr, "DEBUG: T_INTCONSTANT found. %d\n", line_num);
                        fprintf(stderr, "DEBUG: T_INTCONSTANT = %d\n", atoi((char *)yytext));
                    }

                    return T_INTCONSTANT;
                }

0x[A-Z0-9][A-Z0-9]*    {
                    if(DEBUG == 1)
                    {
                        fprintf(stderr,"DEBUG: Hex-Digit found.\n");
                    }
                    yylval.value = hex_to_int((char *)yytext);
                    return T_INTCONSTANT;
                }

\/\/.*          { 
                    /* comment line for double slash Return nothing, keep going */
                }

[ \t]           {
                    if(DEBUG == 1)
                    {
                        fprintf(stderr, "DEBUG: White space found.\n", line_num);
                    }
                }

[=()\[\]{}\-+*/%\!;,]    {
                    if(DEBUG == 1)
                    {
                        fprintf(stderr, "DEBUG: Token found.\n", line_num);
                        fprintf(stderr, "DEBUG: Token = %s\n", (char *)yytext);
                    }
                    return (*yytext);
                }

\n    {
                    if(DEBUG == 1)
                    {
                        fprintf(stderr, "DEBUG: newline token found. line_num++\n", line_num);
                    }
                    line_num++;
                    return (*yytext);
      }

%%

int yywrap(void)
{ 
    return 1;
}

// hex input of 0x[A-Z0-9][A-Z0-9]* 
int hex_to_int(char * hex_input)
{
  return (int)strtol(hex_input, NULL, 0);
}