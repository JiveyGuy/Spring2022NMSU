/* 
/_/\     /_______/\ /_______/\     /_____/\    
\:\ \    \::: _  \ \\::: _  \ \    \::::_\/_   
 \:\ \    \::(_)  \ \\::(_)  \/_    \:\/___/\  
  \:\ \____\:: __  \ \\::  _  \ \    \_::._\:\ 
   \:\/___/\\:.\ \  \ \\::(_)  \ \    /_____\/ 
    \_____\/ \__\/\__\/ \_______\/    \_____/ 
                                    

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
    int DEBUG = 0; //Change 0 before submit
    int hex_to_int(char * hex_input); // takes a hexidecimal string of the form 0xAAAA
    int debug(char * msg, int line_count); // simplified debug behavior. 
%}


%%

"&&"            {
                    debug("DEBUG: T_ID found.", line_num);
                    return T_AND;
                }
"="             {
                    debug("DEBUG: T_ASSIGN found.", line_num);
                    return T_ASSIGN;        
                }
"bool"          {
                    debug("DEBUG: T_BOOLTYPE found.", line_num);
                    return T_BOOLTYPE;      
                }

"break"         {
                    debug("DEBUG: T_BREAK found.", line_num);
                    return T_BREAK;         
                }

"char_lit"      {
                    debug("DEBUG: T_CHARCONSTANT found.", line_num);
                    return T_CHARCONSTANT;  
                }

"continue"      {
                    debug("DEBUG: T_CONTINUE found.", line_num);
                    return T_CONTINUE;      
                }

"."             {
                    debug("DEBUG: T_DOT found.", line_num);
                    return T_DOT;           
                }

"else"          {
                    debug("DEBUG: T_ELSE found.", line_num);
                    return T_ELSE;          
                }

"=="            {
                    debug("DEBUG: T_EQ found.", line_num);
                    return T_EQ;            
                }

"extern"        {
                    debug("DEBUG: T_EXTERN found.", line_num);
                    return T_EXTERN;        
                }

"false"         {
                    debug("DEBUG: T_FALSE found.", line_num);
                    return T_FALSE;         
                }

"for"           {
                    debug("DEBUG: T_FOR found.", line_num);
                    return T_FOR;           
                }

"func"          {
                    debug("DEBUG: T_FUNC found.", line_num);
                    return T_FUNC;          
                }

">="            {
                    debug("DEBUG: T_GEQ found.", line_num);
                    return T_GEQ;           
                }

">"             {
                    debug("DEBUG: T_GT found.", line_num);
                    return T_GT;            
                }

"<"             {
                    debug("DEBUG: T_GT found.", line_num);
                    return T_LT;            
                }

"identifier"    {
                    debug("DEBUG: T_ID found.", line_num);
                    return T_ID;            
                }

"if"            {
                    debug("DEBUG: T_IF found.", line_num);
                    return T_IF;            
                }

"int_lit"       {
                    debug("DEBUG: T_INTCONSTANT found.", line_num);
                    return T_INTCONSTANT;   
                }

"int"           {
                    debug("DEBUG: T_INTTYPE found.", line_num);
                    return T_INTTYPE;       
                }

"<<"            {
                    debug("DEBUG: T_LEFTSHIFT found.", line_num);
                    return T_LEFTSHIFT;     
                }

"<="            {
                    debug("DEBUG: T_LEQ found.", line_num);
                    return T_LEQ;           
                }

"!="            {
                    debug("DEBUG: T_NEQ found.", line_num);
                    return T_NEQ;           
                }

"null"          {
                    debug("DEBUG: T_NULL found.", line_num);
                    return T_NULL;          
                }

"||"            {
                    debug("DEBUG: T_OR found.", line_num);
                    return T_OR;            
                }

"package"       {
                    debug("DEBUG: T_PACKAGE found.", line_num);
                    return T_PACKAGE;       
                }

"return"        {
                    debug("DEBUG: T_RETURN found.", line_num);
                    return T_RETURN;        
                }

">>"            {
                    debug("DEBUG: T_RIGHTSHIFT found.", line_num);
                    return T_RIGHTSHIFT;    
                }

"string_lit"    {
                    debug("DEBUG: T_STRINGCONSTANT found.", line_num);
                    return T_STRINGCONSTANT;
                }

"string"        {
                    debug("DEBUG: T_STRINGTYPE found.", line_num);
                    return T_STRINGTYPE;    
                }

"true"          {
                    debug("DEBUG: T_TRUE found.", line_num);
                    return T_TRUE;          
                }

"var"           {
                    debug("DEBUG: T_VAR found.", line_num);
                    return T_VAR;           
                }

"void"          {
                    debug("DEBUG: T_VOID found.", line_num);
                    return T_VOID;          
                }

"while"         {
                    debug("DEBUG: T_WHILE found.", line_num);
                    return T_WHILE;         
                }


\'.\'                  {
                    debug("DEBUG: T_CHARCONSTANT found.", line_num);
                    yylval.value = yytext[1];
                    return T_CHARCONSTANT;
                }

\".*\"                  {
                    debug("DEBUG: T_STRINGCONSTANT found.", line_num);
                    yylval.value = yytext[1];
                    return T_STRINGCONSTANT;
                }

[a-zA-Z][a-z_A-Z0-9]*    {
                    debug("DEBUG: T_ID found.", line_num);
                    yylval.string = strdup(yytext);
                    return T_ID;
                }


[0-9][0-9]*    {
                    debug("DEBUG: Digit found.", line_num);
                    yylval.value = atoi((char *)yytext);
                    return T_INTCONSTANT;
                }

0x[A-Z0-9][A-Z0-9]*    {
                    debug("DEBUG: Hex-Digit found.", line_num);
                    yylval.value = hex_to_int((char *)yytext);
                    return T_INTCONSTANT;
                }

\/\/.*          { 
                    debug("DEBUG: comment line found.", line_num);
                    /* comment line for double slash Return nothing, keep going */
                }

[ \t]           {
                    debug("DEBUG: White space found.", line_num);            
                }

[=\(\)\[\]{}\-+*/\%\!;,]    {
                    debug("DEBUG: Token found.", line_num);
                    return (*yytext);
                }

\n    {
                    debug( "DEBUG: newline token found.", line_num);
                    line_num++;
                    // return (*yytext); //error here "syntax error" (fixed be removing)
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

int debug(char * msg, int line_count){
    if(DEBUG == 1){
        fprintf(stderr, "At line[%d]: %s\n", line_num, msg);
    }
}