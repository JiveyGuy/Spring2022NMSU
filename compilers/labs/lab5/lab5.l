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

// ==============ALL TOKEN PATERNS
T_AND            { return 1;  } // {} &&
T_ASSIGN         { return 2;  } // =
T_BOOLTYPE       { return 3;  } // bool
T_BREAK          { return 4;  } // break
T_CHARCONSTANT   { return 5;  } // char_lit (see section on Character literals)
T_CONTINUE       { return 6;  } // continue
T_DOT            { return 7;  } // .
T_ELSE           { return 8;  } // else`    g i t
T_EQ             { return 9;  } // ==
T_EXTERN         { return 10; } // extern
T_FALSE          { return 11; } // false
T_FOR            { return 12; } // for
T_FUNC           { return 13; } // func
T_GEQ            { return 14; } // >=
T_GT             { return 15; } // >
T_ID             { return 16; } // identifier (see section on Identifiers)
T_IF             { return 17; } // if
T_INTCONSTANT    { return 18; } // int_lit (see section on Integer literals)
T_INTTYPE        { return 19; } // int
T_LEFTSHIFT      { return 20; } // <<
T_LEQ            { return 21; } // <=
T_NEQ            { return 22; } // !=
T_NULL           { return 23; } // null
T_OR             { return 24; } // ||
T_PACKAGE        { return 25; } // package
T_RETURN         { return 26; } // return
T_RIGHTSHIFT     { return 27; } // >>
T_STRINGCONSTANT { return 28; } // string_lit (see section on String literals)
T_STRINGTYPE     { return 29; } // string
T_TRUE           { return 30; } // true
T_VAR            { return 31; } // var
T_VOID           { return 32; } // void
T_WHILE          { return 33; } // while

%%

int yywrap(void)
{ 
    return 1;
}