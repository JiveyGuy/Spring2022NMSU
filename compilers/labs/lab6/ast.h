/*   Abstract syntax tree code


 Header file   
 Shaun Cooper January 2020

*/

#include<stdio.h>
#include<malloc.h>

#ifndef AST_H
#define AST_H
static int mydebug = 1;

/* define the enumerated types for the AST.  THis is used to tell us what 
sort of production rule we came across */

enum AST_Tree_Element_Type {
   A_PACKAGE,
   A_METHODDEC,
   A_NUMBER,
   A_WHILESTMT,
   A_IFSTMT,
   A_BLOCK,
   A_EXPR,
   A_PARAM,
   A_VARDEC,
   A_EXTERN,
   A_EXTERN_TYPE,
   A_PROGRAM,
   A_ARRAY_TYPE,
   A_METHOD_ID,
   A_CONSTANT_INT,
   A_CONSTANT_STRING,
   A_CONSTANT_BOOL,
   A_BREAK,
   A_CONTINUE,
   A_RETURN,
   A_VAR_RVAL,
   A_METHOD_CALL,
   A_METHOD_CALL_LIST,
   A_ASSIGN
      //missing, 

};


enum AST_Operators {
   A_PLUS,
   A_MINUS,
   A_TIMES,
   A_MOD,
   A_DIV,
   A_AND,
   A_OR,
   A_LS,
   A_RS,
   A_NOT,
   A_UMINUS,
   A_LEQ,
   A_GT ,
   A_LT ,
   A_GEQ,
   A_EQ ,
   A_NEQ
      //missing
};

enum AST_Decaf_Types {
   A_Decaf_INT,
   A_Decaf_BOOL,
   A_Decaf_VOID,
   A_Decaf_STRING
};

/* define a type AST node which will hold pointers to AST structs that will
   allow us to represent the parsed code 
*/
typedef struct ASTnodetype
{
     enum AST_Tree_Element_Type type;
     enum AST_Operators operator;
     char * name;
     int value;
     enum AST_Decaf_Types A_Declared_TYPE;
     ///.. missing
     struct ASTnodetype *S1,*S2, *next ; /* used for holding IF and WHILE components -- not very descriptive */
} ASTnode;


/* uses malloc to create an ASTnode and passes back the heap address of the newley created node */
ASTnode *ASTCreateNode(enum AST_Tree_Element_Type mytype);

void PT(int howmany); // prints howmany spaces


ASTnode *program;  // Global Pointer for connection between YACC and backend

/*  Print out the abstract syntax tree */
void ASTprint(int level,ASTnode *p); // prints tree with level horizontal spaceing

// Will print a node p
void P_Print( ASTnode *p);
// Will print the type of a node. 
void print_node_type(enum AST_Tree_Element_Type mytype);

#endif // of AST_H