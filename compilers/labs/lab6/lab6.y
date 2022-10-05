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
#define DEBUG

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
%type <astnode> Externs ExternDefn ExternParmList FieldDecl MethodDecls
%type <astnode> ArrayType FullExternParmList FieldDecls MethodDecl
%type <astnode> MethodParmList FullMethodParmList Block VarDecls VarDecl
%type <astnode> BoolConstant Constant BreakStatement ContinueStatement
%type <astnode> Statement Statements ReturnStatement Lvalue MethodCall
%type <astnode> Expr Additiveexpression Term Factor MethodCallList
%type <astnode> FullMethodCallList

%type <asttype> MethodType Type ExternType

%type <operator> Relop Multop Addop

%start program
%union
{
  int value;
  char* string;
  struct ASTnodetype *astnode; //keeps track of our nodes
  enum AST_Decaf_Types asttype;
  enum AST_Operators operator;
}

%%  /* end specs, begin rules */
program             : Externs T_PACKAGE T_ID '{' FieldDecls MethodDecls '}' 
                    { 
                        PROGRAM = ASTCreateNode(A_PROGRAM);
                        PROGRAM->S1 = $1;
                        PROGRAM->S2 = ASTCreateNode(A_PACKAGE);
                        PROGRAM->S2->name = $3;
                        PROGRAM->S2->S1 = $5; //field $5
                        PROGRAM->S2->S2 = $6; //method
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
                        $$->name = $3;
                        $$->A_Declared_TYPE = $7;
                        $$->S1 = $5;
                      }
                    ;

ExternParmList      : /*empty*/ {$$ = NULL;}
                    | FullExternParmList {$$ = $1;}
                    ;

FullExternParmList  : ExternType 
                      {
                        $$ = ASTCreateNode( A_EXTERN_TYPE );
                        $$->A_Declared_TYPE = $1;
                      }
                    | ExternType ',' ExternParmList 
                      {
                        $$ = ASTCreateNode( A_EXTERN_TYPE );
                        $$->A_Declared_TYPE = $1;
                        $$->next = $3;
                      } 
                    ;

FieldDecls          : /*empty*/ 
                      {$$ = NULL;}
                    | FieldDecl FieldDecls
                      {
                        $$ = $1;
                        $$->next = $2;
                      }
                    ;
        
FieldDecl           : T_VAR T_ID Type ';' 
                      {
                        $$ = ASTCreateNode( A_VARDEC );
                        $$->name = $2;
                        $$->A_Declared_TYPE = $3;
                      }
                    | T_VAR T_ID ArrayType ';' 
                      {
                        $$ = ASTCreateNode( A_VARDEC );
                        $$->name = $2;
                        $$->S1 = $3;
                        $$->A_Declared_TYPE = $3->A_Declared_TYPE;
                      }
                    | T_VAR T_ID Type T_ASSIGN Constant ';'
                      {
                        $$ = ASTCreateNode( A_VARDEC );
                        $$->name = $2;
                        $$->A_Declared_TYPE = $3;
                        $$->S2 = $5;
                      }  
                    ;
        
MethodDecls         : /*empty*/
                      {$$ = NULL;}
                    | MethodDecl MethodDecls
                      {
                        $$ = $1;
                        $$->next = $2;
                      }
                    ;
        
MethodDecl          : T_FUNC T_ID '(' MethodParmList ')' MethodType Block 
                      {
                        $$ = ASTCreateNode( A_METHODDEC );
                        $$->name = $2;
                        $$->A_Declared_TYPE = $6;
                        $$->S1   = $4;
                        $$->S2   = $7; // $7
                      }
                    ;

MethodParmList      : /*empty*/
                      {$$ = NULL;}
                    | FullMethodParmList
                      {
                        $$ = $1;
                      }
                    ;

FullMethodParmList  : T_ID Type
                      {
                        $$ = ASTCreateNode( A_METHOD_ID );
                        $$->name = $1;
                        $$->A_Declared_TYPE = $2;
                      }
                    | T_ID Type ',' FullMethodParmList 
                      {
                        $$ = ASTCreateNode( A_METHOD_ID );
                        $$->name = $1;
                        $$->A_Declared_TYPE = $2;
                        $$->next = $4;
                      }
                    ;
        
Block               : '{' VarDecls Statements '}' 
                      {
                        $$ = ASTCreateNode( A_BLOCK );
                        $$->S1 = $2;
                        $$->S2 = $3;
                      }
                    ;
        
VarDecls            : /*empty*/
                      {$$ = NULL;}
                    | VarDecl VarDecls 
                      {
                        $$ = $1;
                        $$->next = $2;
                      }
                    ;
        
VarDecl             : T_VAR T_ID Type ';'
                      {
                        $$ = ASTCreateNode( A_VARDEC );
                        $$->name = $2;
                        $$->A_Declared_TYPE = $3;
                      }
                    | T_VAR T_ID ArrayType ';' 
                      {
                        $$ = ASTCreateNode( A_VARDEC );
                        $$->name = $2;
                        $$->S1 = $3;
                        $$->A_Declared_TYPE = $3->A_Declared_TYPE;
                      }
                      ;
        
Statements          : /*empty*/
                      {$$ = NULL;}
                    | Statement Statements
                      {
                        $$ = $1;
                        $$->next = $2;
                      }
                    ;
        
Statement           : Block             {$$ = $1;}
                    | MethodCall ';'    {$$ = NULL;}
                    | Assign ';'        {$$ = NULL;} 
                    | IfStatement       {$$ = NULL;} 
                    | BreakStatement    {$$ = $1;} 
                    | WhileStatement    {$$ = NULL;} 
                    | ReturnStatement   {$$ = $1;} 
                    | ContinueStatement {$$ = $1;} 
                    ;

IfStatement         : T_IF '(' Expr ')' Block T_ELSE Block
                    | T_IF '(' Expr  ')' Block ;

BreakStatement      : T_BREAK ';' 
                      {
                        $$ = ASTCreateNode( A_BREAK );
                      } 
                     ;

WhileStatement      : T_WHILE '(' Expr ')' Block ;

ReturnStatement      : T_RETURN ';'
                      {
                        $$ = ASTCreateNode( A_RETURN );
                      } 
                     | T_RETURN '(' ')' ';'
                      {
                        $$ = ASTCreateNode( A_RETURN );
                      } 
                     | T_RETURN '(' Expr ')' ';' 
                      {
                        $$ = ASTCreateNode( A_RETURN );
                        $$->S1 = $3;
                      }
                     ;

ContinueStatement    : T_CONTINUE ';' 
                      {
                        $$ = ASTCreateNode( A_CONTINUE );
                      } 
                    ;
        
Assign              : Lvalue T_ASSIGN Expr ; 
        
Lvalue              : T_ID 
                      {
                        $$ = ASTCreateNode( A_VAR_RVAL );
                        $$->name = $1;
                      }
                    | T_ID '[' Expr ']'
                      {
                        $$ = ASTCreateNode( A_VAR_RVAL );
                        $$->name = $1;
                        $$->S1   = $3;
                      } 
                    ;
            
MethodCall          : T_ID '(' MethodCallList ')'
                      {
                        $$ = ASTCreateNode( A_METHOD_CALL );
                        $$->name = $1;
                        $$->S1 = $3;
                      } 
                    ;

MethodCallList      : /*empty*/
                     {$$ = NULL;}
                    | FullMethodCallList {$$ = $1;} ;

FullMethodCallList  : Expr {$$ = $1;}
                    | Expr ',' Expr 
                      {
                        $$ = ASTCreateNode( A_EXPR );
                        $$->S1 = $1;
                        $$->S1 = $3;
                      }
                    ;

Expr                : Additiveexpression {$$ = $1;}
                    | Expr Relop Additiveexpression 
                      {
                        $$ = ASTCreateNode( A_EXPR );
                        $$->S1 = $1;
                        $$->operator = $2;
                        $$->S2 = $3;
                      }
                    ;

Relop               : T_LEQ   {$$ = A_LEQ;}
                    | T_GT    {$$ = A_GT ;}
                    | T_LT    {$$ = A_LT ;}
                    | T_GEQ   {$$ = A_GEQ;}
                    | T_EQ    {$$ = A_EQ ;}
                    | T_NEQ   {$$ = A_NEQ;}
                    ;

Additiveexpression  : Term {$$ = $1;}
                    | Additiveexpression Addop Term
                      {
                        $$ = ASTCreateNode( A_EXPR );
                        $$->S1 = $1;
                        $$->operator = $2;
                        $$->S2 = $3;
                      }
                    ;

Addop               : '+' {$$ = A_PLUS;  }
                    | '-' {$$ = A_MINUS; } ;

Term                : Factor {$$ = $1;}
                    | Term Multop Factor
                      {
                        $$ = ASTCreateNode( A_EXPR );
                        $$->S1 = $1;
                        $$->operator = $2;
                        $$->S2 = $3;
                      }
                    ;

Multop              : '*'           {$$ = A_TIMES;}
                    | '/'           {$$ = A_DIV;}
                    | '%'           {$$ = A_MOD;}
                    | T_AND         {$$ = A_AND;}
                    | T_OR          {$$ = A_OR;}
                    | T_LEFTSHIFT   {$$ = A_LS;}
                    | T_RIGHTSHIFT  {$$ = A_RS;}
                    ;

Factor              : Lvalue
                    | MethodCall
                    | Constant {$$ = $1;}
                    | '(' Expr ')' {$$ = $2;}
                    | '!' Factor 
                      {
                        $$ = ASTCreateNode( A_EXPR );
                        $$->operator = A_NOT;
                        $$->S1 = $2;
                      }
                    | '-' Factor
                      {
                        $$ = ASTCreateNode( A_UMINUS );
                        $$->operator = A_NOT;
                        $$->S1 = $2;
                      }


ExternType          : T_STRINGTYPE {$$ = A_Decaf_STRING;}
                    | Type {$$ = $1;} ;

Type                 : T_INTTYPE {$$ = A_Decaf_INT;}
                     | T_BOOLTYPE {$$ = A_Decaf_BOOL;} 
                     ;

MethodType           : T_VOID 
                      {$$ = A_Decaf_VOID;}
                     | Type {$$ = $1;};

BoolConstant         : T_TRUE
                      {
                        $$ = ASTCreateNode( A_CONSTANT_BOOL );
                        $$->value = 1;
                      }
                     | T_FALSE 
                      {
                        $$ = ASTCreateNode( A_CONSTANT_BOOL );
                        $$->value = 0;
                      }

ArrayType            : '[' T_INTCONSTANT ']' Type 
                      {
                        $$ = ASTCreateNode( A_ARRAY_TYPE );
                        $$->value = $2;
                        $$->A_Declared_TYPE = $4;
                      }
                     ;

Constant             : T_INTCONSTANT 
                      {
                        $$ = ASTCreateNode( A_CONSTANT_INT );
                        $$->value = $1;
                      }
                     | T_STRINGCONSTANT 
                      {
                        $$ = ASTCreateNode( A_CONSTANT_STRING );
                        $$->name = $1;
                      }
                     | BoolConstant {$$ = $1;} ;

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