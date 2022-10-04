%{

/*
/_/\     /_______/\ /_______/\     /_____/\    
\:\ \    \::: _  \ \\::: _  \ \    \::::_\/_   
 \:\ \    \::(_)  \ \\::(_)  \/_    \:\/___/\  
  \:\ \____\:: __  \ \\::  _  \ \    \_::._\:\ 
   \:\/___/\\:.\ \  \ \\::(_)  \ \    /_____\/ 
    \_____\/ \__\/\__\/ \_______\/    \_____/ 

  Shaun Cooper
    January 2015

  Editted by Jason Ivey, Sep 4, 2022:
    Added mult, uminus, and fixed spelling. 
    Fixed spacing issues. 
    Added int type to main. 
    Made debugsw external. 
    Added int yylex(); to supress warnings. 

  Editted by Jason Ivey, Sep 12, 2022:
      Made debug = 0
      added () to token list

  Editted by Jason Ivey, Sep 25, 2022:
      removed old:
        symbol table
        rules
        debugsw
        base

  Editted by Jason Ivey, Sep 26, 2022:
      fixed missing:
        rules


  INPUT: LEX Description + Text
  OUTPUT: y.tab.c /h 
*/

// begin specs 
#include <stdio.h>
#include <ctype.h>
#include "ast.h"



// Added this to supress warn
extern int yylex(void);
extern int line_num; //counts lines (FROM LEX)

// ast global
struct ASTnodetype *PROGRAM;

// Called by yyparse on error 
void yyerror (s)  
     char *s;
{
  printf ("ERROR @ line #%i: %s\n", line_num, s);
}

%}

/*  
 defines the start symbol, what values come back
 from LEX and how the operators are associated 
*/

//===============TOKENS LIST
%token T_AND            
%token T_ASSIGN         
%token T_BOOLTYPE       
%token T_BREAK          
%token T_CHARCONSTANT   
%token T_CONTINUE       
%token T_DOT            
%token T_ELSE           
%token T_EQ             
%token T_EXTERN         
%token T_FALSE          
%token T_FOR            
%token T_FUNC           
%token T_GEQ            
%token T_GT 
%token T_LT            
%token <string> T_ID                        
%token T_IF             
%token <value> T_INTCONSTANT    
%token T_INTTYPE        
%token T_LEFTSHT_IFT      
%token T_LEQ            
%token T_NEQ            
%token T_NULL           
%token T_OR             
%token T_PACKAGE        
%token T_RETURN         
%token T_RIGHTSHT_IFT     
%token <string> T_STRINGCONSTANT 
%token T_STRINGTYPE     
%token T_TRUE           
%token T_VAR            
%token T_VOID           
%token T_WHILE
%token T_LEFTSHIFT 
%token T_RIGHTSHIFT 

//===============TYPES LIST
%type <astnode> Externs ExternDefn

%start program
%union
{
  int value;
  char* string;
  struct ASTnodetype *astnode; //keeps track of our nodes
}

%%  /* end specs, begin rules */
program             : Externs T_PACKAGE T_ID '{' FieldDecls MethodDecls '}' 
                    { 
                        PROGRAM = $1;
                    }
                  ;
        
Externs             : /*empty*/ 
                      { 
                        $$ = NULL;
                      }
                    | ExternDefn Externs
                      { 
                        $1->next = $2;
                      }
                    ;

ExternDefn          : T_EXTERN T_FUNC T_ID '(' ExternParmList ')' MethodType ';' 
                      { 
                        $$ = ASTCreateNode( A_EXTERN );
                        $$-> name = $3;
                      }
                    ;

ExternParmList      : /*empty*/
                    | FullExternParmList ;

FullExternParmList  : ExternType
                    | ExternType ',' ExternParmList ;

FieldDecls          : /*empty*/
                    | FieldDecl FieldDecls;
        
FieldDecl           : T_VAR T_ID Type ';' ;
        
FieldDecl           : T_VAR T_ID ArrayType ';' ;
        
FieldDecl           : T_VAR T_ID Type  T_ASSIGN Constant ';' ;
        
MethodDecls         : /*empty*/
                    | MethodDecl MethodDecls ;
        
MethodDecl          : T_FUNC T_ID '(' MethodParmList ')' MethodType Block ;

MethodParmList      : /*empty*/
                    | FullMethodParmList ;

FullMethodParmList  : T_ID Type
                    | T_ID Type ',' FullMethodParmList ;
        
Block               : '{' VarDecls Statements '}' ;
        
VarDecls            : /*empty*/
                    | VarDecl VarDecls ;
        
VarDecl             : T_VAR T_ID Type ';'
                    | T_VAR T_ID ArrayType ';' ;
        
Statements          : /*empty*/
                    | Statement Statements;
        
Statement           : Block ;
        
Statement           : Assign ';' ;
        
Assign              : Lvalue T_ASSIGN Expr ; 
        
Lvalue              : T_ID
                    | T_ID '[' Expr ']' ;
        
Statement           : MethodCall ';' ;
        
MethodCall          : T_ID '(' MethodCallList ')' ;

MethodCallList      : /*empty*/
                    | FullMethodCallList ;

FullMethodCallList  : MethodArg
                    | MethodArg ',' FullMethodCallList ;
        
MethodArg           : Expr
                    | T_STRINGCONSTANT ;
        
Statement           : T_IF '(' Expr ')' Block T_ELSE Block;

Statement           : T_IF '(' Expr  ')' Block;

Statement           : T_WHILE '(' Expr ')' Block ;
        
Statement            : T_RETURN ';' ;
                     | T_RETURN '(' ')' ';' ;
                     | T_RETURN '(' Expr ')' ';' ;
        
Statement           : T_BREAK ';' ;
        
Statement           : T_CONTINUE ';' ;

Expr                : Additiveexpression
                    | Expr Relop Additiveexpression ;

Relop               : T_LEQ
                    | T_GT
                    | T_LT
                    | T_GEQ
                    | T_EQ
                    | T_NEQ ;

Additiveexpression  : Term
                    | Additiveexpression Addop Term;

Addop               : '+'
                    | '-' ;

Term                : Factor
                    | Term Multop Factor;

Multop              : '*'
                    | '/'
                    | '%' 
                    | T_AND
                    | T_OR
                    | T_LEFTSHIFT
                    | T_RIGHTSHIFT ;

Factor              : Lvalue
                    | MethodCall
                    | Constant
                    | '(' Expr ')'
                    | '!' Factor
                    | '-' Factor ;

ExternType          : T_STRINGTYPE 
                    | Type ;

Type                 : T_INTTYPE
                     | T_BOOLTYPE ;

MethodType           : T_VOID
                     | Type ;

BoolConstant         : T_TRUE
                     | T_FALSE ;

ArrayType            : '[' T_INTCONSTANT ']' Type ;

Constant             : T_INTCONSTANT 
                     | BoolConstant ;

%%  /* end of rules, start of program */

int main()
{ 
  yyparse();
  printf("Parse complete!\n");
  // We know pogram parse complete PROGRAM->AST
  ASTprint(0, PROGRAM);
}

void debug(char s[]){
  #ifdef DEBUG    
    printf("DEBUG:: %s\n",s);
  #endif
}