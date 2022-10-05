/*   
    Abstract syntax tree code

    This code is used to define an AST node, 
    routine for printing out the AST
    defining an enumerated type so we can 
    figure out what we need to do with this.
    The ENUM is basically going to be every
    non-terminal and terminal in our language.

    Shaun Cooper February 2020

    Editted by Jason Ivey September 2022:
      formatting
    Editted by Jason Ivey October 2022:
      
  
*/

#include<stdio.h>
#include<malloc.h>
#include "ast.h" 


/* 
    uses malloc to create an ASTnode and passes back the heap
    address of the newley created node 
*/
ASTnode *ASTCreateNode(enum AST_Tree_Element_Type mytype)
{
  ASTnode *p;

  if (mydebug)
  {
    fprintf(stderr,"Creating AST Node with type = ");
    print_node_type(mytype);
    printf("\n");
  }
  // get head data
  p        = (ASTnode *)malloc(sizeof(ASTnode)); 

  // set up the Element type
  p->type  = mytype; 
  
  // set default values
  p->S1    = NULL;
  p->S2    = NULL;  
  p->value = 0;

  // return head
  return(p);
  }

void print_node_type(enum AST_Tree_Element_Type mytype){
  switch (mytype) {
      case A_PACKAGE: 
        printf("A_PACKAGE");
      break;
      
      case A_METHODDEC: 
        printf("A_METHODDEC");
      break;
      
      case A_NUMBER: 
        printf("A_NUMBER");
      break;
      
      case A_WHILESTMT: 
        printf("A_WHILESTMT");
      break;
      
      case A_BLOCK: 
        printf("A_BLOCK");
      break;
      
      case A_EXPR: 
        printf("A_EXPR");
      break;
      
      case A_PARAM: 
        printf("A_PARAM");
      break;
      
      case A_VARDEC: 
        printf("A_VARDEC");
      break;
      
      case A_EXTERN: 
        printf("A_EXTERN");
      break;
      
      case A_EXTERN_TYPE: 
        printf("A_EXTERN_TYPE");
      break;
      
      case A_PROGRAM: 
        printf("A_PROGRAM");
      break;
      
      case A_ARRAY_TYPE: 
        printf("A_ARRAY_TYPE");
      break;
      
      case A_METHOD_ID: 
        printf("A_METHOD_ID");
      break;
      
      case A_CONSTANT_INT: 
        printf("A_CONSTANT_INT");
      break;
      
      case A_CONSTANT_STRING: 
        printf("A_CONSTANT_STRING");
      break;
      
      case A_CONSTANT_BOOL: 
        printf("A_CONSTANT_BOOL");
      break;
      
      case A_BREAK: 
        printf("A_BREAK");
      break;
      
      case A_CONTINUE: 
        printf("A_CONTINUE");
      break;
      
      case A_RETURN: 
        printf("A_RETURN");
      break;
      
      case A_VAR_RVAL: 
        printf("A_VAR_RVAL");
      break;

      case A_IFSTMT: 
        printf("A_IFSTMT");
      break;

      case A_METHOD_CALL: 
        printf("A_METHOD_CALL");
      break;

      case A_METHOD_CALL_LIST: 
        printf("A_METHOD_CALL_LIST");
      break; 

      case A_ASSIGN: 
        printf("A_ASSIGN");
      break; 

      default :
        printf("A_UNKOWN");
      break;
    }
}

//  Helper function to print tabbing 
void PT(int howmany)
{
  for (int i = 0; i < howmany; ++i)
  {
   printf(" ");
  }
}

void AST_Print_Type( enum AST_Decaf_Types t)
{
 switch (t)
 {
    case A_Decaf_INT : 
      printf(" INT ");
    break;

    case A_Decaf_BOOL : 
      printf(" BOOL ");
    break;

    case A_Decaf_VOID : 
      printf(" VOID ");
    break; //in video Dr. Cooper said no void. 

    case A_Decaf_STRING : 
      printf(" STRING ");
    break;

    default:
      fprintf(stderr,"Unknown AST DECAF TYPE !!!\n");
    break;
  } // end of switch


}// of AST_Print_Type

// Will print a node p
void P_Print( ASTnode *p){
  
  printf("P_Print p->type = %d", p->type);
  printf("\n");
  
  if(p->value != 0)
    printf("P_Print p->value = %d", p->value);
  if(p->name != NULL)
    printf("P_Print p->name = %s", p->name);

}

/*  Print out the abstract syntax tree */
void ASTprint(int level,ASTnode *p)
{
  int i;
  if (p == NULL )
  {
    return;
  }
  else
  {
    PT(level); /*indent */
    switch (p->type) 
    {
      case A_VARDEC :  printf("Variable ");
        // if (p->operator == A_Decaf_VOID)
        // {
        //   printf("VOID ");
        // }
        printf(" %s",p->name);
        if (p->S1 != NULL)
        {
          printf("[%d]",p->S1->value);
        } 
        AST_Print_Type(p->A_Declared_TYPE);
        // this is a intitial value set
        if( p->S2 != NULL ) {
          printf(" = %d ", p->S2->value);
        }
        
        printf("\n");
      break;

      case A_METHODDEC :  
        printf(" Method %s with type  " ,p->name);
        AST_Print_Type(p->A_Declared_TYPE);
        /* print out the parameter list */
        if (p->S1 == NULL ) 
        { 
          PT(level+2); 
          printf (" (NONE) ");
        }

        else
        { 
          PT(level+3);
          printf( "( \n");
          ASTprint(level+6, p->S1);
          PT(level+3);
          printf( ") ");
        }
        printf("\n");
        ASTprint(level+3, p->S2); // print out the block
      break;

      case A_PARAM :  
        printf("PARAMETER ");
        if (p->operator == A_Decaf_INT)
        {
          printf (" INT ");
        }
        if (p->operator == A_Decaf_BOOL)
        {
          printf (" VOID ");
        }
        if (p->operator == A_Decaf_VOID)
        {
          printf (" BOOLEAN ");
        }
        printf (" %s",p->name);
        if (p->value == -1 )
        { 
          printf("[]");
        }
        printf("\n");                  
      break;

      case A_EXPR :
        printf("EXPR ");
        switch(p->operator)
        {
          case A_PLUS: 
             printf("A_PLUS");
          break;

          case A_MINUS: 
             printf("A_MINUS");
          break;

          case A_TIMES: 
             printf("A_TIMES");
          break;

          case A_MOD: 
             printf("A_MOD");
          break;

          case A_DIV: 
             printf("A_DIV");
          break;

          case A_AND: 
             printf("A_AND");
          break;

          case A_OR: 
             printf("A_OR");
          break;

          case A_LS: 
             printf("A_LS");
          break;

          case A_RS: 
             printf("A_RS");
          break;

          case A_NOT: 
             printf("A_NOT");
          break;

          case A_UMINUS: 
             printf("A_UMINUS");
          break;

          case A_LEQ: 
             printf("A_LEQ");
          break;

          case A_GT : 
             printf("A_GT");
          break;

          case A_LT : 
             printf("A_LT");
          break;

          case A_GEQ: 
             printf("A_GEQ");
          break;

          case A_EQ : 
             printf("A_EQ");
          break;

          case A_NEQ : 
              printf("A_NEQ");
          break;

         default:
          printf("unkown operator ");
        }
        
        printf("\n");
        ASTprint(level+1, p->S1);
        if (p->operator != A_NOT)
        { 
         ASTprint(level+1, p->S2);
        }
      break;

      case A_BLOCK :  
        printf("BLOCK STATEMENT \n");
        ASTprint(level+1, p->S1);
        ASTprint(level+1, p->S2);
      break;

      case A_WHILESTMT :  
        printf("WHILE STATEMENT \n");
        ASTprint(level+1, p->S1);
        ASTprint(level+2, p->S2);
      break;

      case A_NUMBER :  
        printf("NUMBER with value %d\n",p->value);
      break;

      case A_CONSTANT_INT :
        printf("CONSTANT_INT with value %d\n",p->value);
      break;

      case A_CONSTANT_STRING :
        printf("CONSTANT_STRING with value TODO\n");
        // fails with p->name
      break;

      case A_CONSTANT_BOOL :
        printf("CONSTANT_BOOL with value ");
        if (p->value == 1)
        {
          printf("TRUE");
        } 
        else  
        {
          printf("FALSE");
        }
        printf("\n");
      break;

      case A_EXTERN_TYPE :  
        printf("EXTERN_TYPE ");
        AST_Print_Type(p->A_Declared_TYPE);
        ASTprint(level+1, p->S1);
      break;

      case A_EXTERN :  
        printf("EXTERN %s (", p->name);
        ASTprint(level+1, p->S1);
        printf(" )");
        AST_Print_Type(p->A_Declared_TYPE);
        printf("\n");
      break;

      case A_PROGRAM :  
        printf("PROGRAM \n");
        ASTprint(level+1, p->S1);
        ASTprint(level+1, p->S2);
      break;

      case A_PACKAGE :  
        printf("PACKAGE %s \n", p->name);
        ASTprint(level+1, p->S1);
        ASTprint(level+1, p->S2);
      break;

      case A_METHOD_ID :  
        printf("METHOD Variable %s ", p->name);
        AST_Print_Type(p->A_Declared_TYPE);
        printf("\n");
      break;

      case A_BREAK :  
        printf("BREAK statement \n");
      break;

      case A_CONTINUE :  
        printf("CONTINUE statement \n");
      break;

      case A_RETURN :  
        printf("RETURN statement \n");
        ASTprint(level+1, p->S1);
      break;

      default: 
        printf("unknown type in ASTprint\n");
        if( mydebug == 1)
        {
          print_node_type(p->type);
          P_Print(p);
        }
      break;
    }
    ASTprint(level, p->next);
  }

}