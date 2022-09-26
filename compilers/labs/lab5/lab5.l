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
    int hex_to_int(char * hex_input);
%}


%%

"&&"            {return T_AND;           }
"="             {return T_ASSIGN;        }
"bool"          {return T_BOOLTYPE;      }
"break"         {return T_BREAK;         }
"char_lit"      {return T_CHARCONSTANT;  }
"continue"      {return T_CONTINUE;      }
"."             {return T_DOT;           }
"else"          {return T_ELSE;          }
"=="            {return T_EQ;            }
"extern"        {return T_EXTERN;        }
"false"         {return T_FALSE;         }
"for"           {return T_FOR;           }
"func"          {return T_FUNC;          }
">="            {return T_GEQ;           }
">"             {return T_GT;            }
"identifier"    {return T_ID;            }
"if"            {return T_IF;            }
"int_lit"       {return T_INTCONSTANT;   }
"int"           {return T_INTTYPE;       }
"<<"            {return T_LEFTSHIFT;     }
"<="            {return T_LEQ;           }
"!="            {return T_NEQ;           }
"null"          {return T_NULL;          }
"||"            {return T_OR;            }
"package"       {return T_PACKAGE;       }
"return"        {return T_RETURN;        }
">>"            {return T_RIGHTSHIFT;    }
"string_lit"    {return T_STRINGCONSTANT;}
"string"        {return T_STRINGTYPE;    }
"true"          {return T_TRUE;          }
"var"           {return T_VAR;           }
"void"          {return T_VOID;          }
"while"         {return T_WHILE;         }

\'.\'                  {
                    yylval.value = yytext[1];
                    return T_CHARCONSTANT;
                }

\".*\"                  {
                    yylval.value = yytext[1];
                    return T_STRINGCONSTANT;
                }

[a-zA-Z][a-z_A-Z0-9]*    {
                    if(DEBUG == 1)
                    {
                        fprintf(stderr, "DEBUG: Letter found.\n", line_num);
                    
                    }
                    yylval.string = strdup(yytext);
                    return T_ID;
                }


[0-9][0-9]*    {
                    if(DEBUG == 1)
                    {
                        fprintf(stderr, "DEBUG: Digit found.\n", line_num);
                    }
                    yylval.value = atoi((char *)yytext);
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
                    }
                    return (*yytext);
                }

\n    {
                    if(DEBUG == 1)
                    {
                        fprintf(stderr, "DEBUG: newline token found.\n", line_num);
                    }
                    line_num++;
                    if(DEBUG == 1)
                    {
                        fprintf(stderr, "DEBUG: newline line_num incr.\n", line_num);
                    }
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