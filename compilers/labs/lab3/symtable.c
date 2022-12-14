/*
dP         .d888888   888888ba  d8888b. 
88        d8'    88   88    `8b     `88 
88        88aaaaa88a a88aaaa8P'  aaad8' 
88        88     88   88   `8b.     `88 
88        88     88   88    .88     .88 
88888888P 88     88   88888888P d88888P 

Source: http://forgetcode.com/C/101-Symbol-table
	This code was pulled from canvas, a campus website for NMSU for the class CS-370
	by Dr. Shaun Cooper.

Jason Ivey, Sep 22:
	Desc: This project is to make a functional symbol table from a linked list

	Changed: 
		Removed modify method,
		indented, 
		moved i/o to main,
		added comments
		removed refs to label
*/

// ========= INCLUDES
#include<stdio.h>
/* #include<conio.h> */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include "symtable.h"

// ========= GLOBALS

// Size of the linked list
int size=0;
// Pointers to start and end nodes
struct SymbTab *first, *last;

// ========= FUNCTIONS

//This removes main if MAIN not defined in header
#ifdef MAIN 
	// Main control function, called on execution
	void main()
	{
		int op, y;
		char la[10];

		do
		{
			op = -1; //reset after every run so that bad input does not default to last option

			printf("\n\tSYMBOL TABLE IMPLEMENTATION\n");
			printf("\t\t1.INSERT\n\t\t2.DISPLAY\n\t\t3.DELETE\n\t\t4.SEARCH\n\t\t5.END\n");
			printf("\n\tEnter your option : ");

			scanf("%d",&op);

			switch(op)
			{
				case 1:
					int n, addr;
					
					char s[10];

					printf("\n\tEnter the symbol : ");
					scanf("%s", s);

					n = Search(s);

					if(n==1)
					{
						printf(
						"\n\tThe symbol exists already in the symbol table\n\tDuplicate can.t be inserted"
						);

						break;
					} //Breaks this case if the symbol is already taken

					printf("\n\tEnter the address : ");
					scanf("%d",&addr);

					Insert(s, addr); //todo test

					printf("\n\tsymbol inserted\n");
				break;

				case 2:
					Display();
				break;

				case 3:
					int a;

					printf("\n\tEnter the symbol to be deleted : ");
					scanf("%s",s);

					a=Search(s);

					if(a==0){
						printf("\n\tsymbol not found, delet aborted.\n");
						break;
					}

					Delete(s); //call delete with symbol char array
				break;

				case 4: 
					printf("\n\tEnter the symbol to be searched : ");
					scanf("%s",la);

					y=Search(la);

					printf("\n\tSearch Result:");

					if(y==1)
						printf("\n\tThe symbol is present in the symbol table\n");
					else
						printf("\n\tThe symbol is not present in the symbol table\n");
				break;

				case 5:
					exit(0);

				// Handle bad input
				default:
					printf("\n\tUnrecognized input, select another option!");
			}
		} while(op < 6);

	}  /* end of main */
#endif


void debug(char s[]){
	#ifdef DEBUG		
		printf("DEBUG:: %s\n",s);
	#endif
}

// Insert new value into the list
void Insert(char s[], int addr)
{
	debug("Insert:: start.");
	char *s_temp = strdup(s);

	struct SymbTab *p;
	p=malloc(sizeof(struct SymbTab));
	debug("Insert:: malloc succ");

	p->symbol = s_temp;
	debug("Insert:: strcopy succ");

	p->addr   = addr;
	p->next   = NULL;

	if(size==0)
	{
		first=p;
		last=p;
	}
	else
	{
		last->next=p;
		last=p;
	}

	size++;

}

// Show the values stored in the list
void Display()
{
	debug("Display:: called.");
	int i;
	struct SymbTab *p;
	p=first;
	printf("\n\tSYMBOL\t\tADDRESS\n");

	for(i=0;i<size;i++)
	{
		printf(
			"\t%s\t\t%d\n",
			p->symbol,
			p->addr
		);

		p=p->next;
	}
}

// Search for a given symbol in the linked list
int Search(char s[])
{
	int i,flag=0;
	struct SymbTab *p;
	p=first;

	for(i=0;i<size;i++)
	{
		if(strcmp(p->symbol,s)==0)
			flag=1;

		p=p->next;
	}
	return flag;
}

// Delete function : when given a symbol remove it from the list
void Delete(char s[])
{
	int a;
	struct SymbTab *p,*q;
	p=first;
	a=Search(s);
	if(a==0)
		printf("\n\tLabel not found\n");
	else
	{
		if(strcmp(first->symbol,s)==0)
			first=first->next;
		else if(strcmp(last->symbol,s)==0)
		{
			q=p->next;
			while(strcmp(q->symbol,s)!=0)
			{
				p=p->next;
				q=q->next;
			}
			p->next=NULL;
			last=p;
		}
		else
		{
			q=p->next;
			while(strcmp(q->symbol,s)!=0)
			{
				p=p->next;
				q=q->next;
			}
			p->next=q->next;
		}
		size--;
		printf("\n\tAfter Deletion:\n");
		Display();
	}
}