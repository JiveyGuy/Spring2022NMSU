/*

	██╗      █████╗ ██████╗     ██╗  ██╗
	██║     ██╔══██╗██╔══██╗    ██║  ██║
	██║     ███████║██████╔╝    ███████║
	██║     ██╔══██║██╔══██╗    ╚════██║
	███████╗██║  ██║██████╔╝         ██║
	╚══════╝╚═╝  ╚═╝╚═════╝          ╚═╝
                                    

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

		// main control loop for i/o
		do
		{
			op = -1; //reset after every run so that bad input does not default to last option

			printf("\n\tSYMBOL TABLE IMPLEMENTATION\n");
			printf("\t\t1.INSERT\n\t\t2.DISPLAY\n\t\t3.DELETE\n\t\t4.SEARCH\n\t\t5.END\n");
			printf("\n\tEnter your option : ");

			scanf("%d",&op);

			switch(op)
			{
				case 1: // INSERT
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

				case 2: // DISPLAY
					Display();
				break;

				case 3: // SEARCH
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

				case 4: // DISPLAY
					printf("\n\tEnter the symbol to be searched : ");
					scanf("%s",la);

					y=Search(la);

					printf("\n\tSearch Result:");

					if(y==1)
						printf("\n\tThe symbol is present in the symbol table\n");
					else
						printf("\n\tThe symbol is not present in the symbol table\n");
				break;

				case 5: // END
					exit(0);

				// Handle bad input
				default:
					printf("\n\tUnrecognized input, select another option!");
			}
		} while(op < 6);

	}  /* end of main */
#endif

// output: will return int addr 
// input: symbol
int fetch_addr(char s[]){

	// is s does not exist in list
	if(Search(s) == 0){
		debug("fetch_addr:: barf due to undef char s[]");
		exit(-1);
	}

	int i, index;
	struct SymbTab *p;
	p=first;

	// this iterates the linked list until symbol == s (input symbol)
	for(i=0; i<size; i++)
	{
		if(strcmp(p->symbol, s) == 0)
			return i;
		
		p=p->next;
	}

	debug("fetch_addr:: error could not find char s[] ");
	return -1;
}

void debug(char s[]){
	#ifdef DEBUG		
		printf("DEBUG:: %s\n",s);
	#endif
}

// Insert new value into the list
// output: N/A
// input: symbol: str, addr: int
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

	if(size==0) // empty list
	{
		first=p;
		last=p;
	}
	else // non-empty list
	{
		last->next=p;
		last=p;
	}

	size++;

}

// Show the values stored in the list
// output: N/A
// input: N/A
void Display()
{
	debug("Display:: called.");
	int i;
	struct SymbTab *p;
	p=first;
	printf("\n\tSYMBOL\t\tADDRESS\n");

	// iterate linked list to print addr and symbol
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
// output: 0 => not found, 1 => found
// input: s: str
int Search(char s[])
{
	int i,flag=0;
	struct SymbTab *p;
	p=first;

	// iterate list and set flag=1 if symbol found
	for(i=0;i<size;i++)
	{
		if(strcmp(p->symbol,s)==0)
			flag=1;

		p=p->next;
	}

	return flag;
}

// Delete function : when given a symbol remove it from the list
// output: N/A
// input: symbol: str
void Delete(char s[])
{
	int a;
	struct SymbTab *p,*q;
	p=first;
	a=Search(s);

	// if symbol does not exist in list 
	if(a==0)
		printf("\n\tLabel not found\n");
	else // if symbol does exist in list 
	{
		if(strcmp(first->symbol,s)==0) // if first->symbol = input symbol
			first=first->next;
		else if(strcmp(last->symbol,s)==0) // if last->symbol = input symbol
		{
			q=p->next;
			while(strcmp(q->symbol,s)!=0)  // iterate until symbol is gone
			{
				p=p->next;
				q=q->next;
			}
			p->next=NULL;
			last=p;
		}
		else // if neither symbol = input symbol
		{
			q=p->next;
			while(strcmp(q->symbol,s)!=0) // iterate until symbol is gone
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