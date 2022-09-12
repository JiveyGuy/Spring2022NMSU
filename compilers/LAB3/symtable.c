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
		added comments,
		


*/

// ========= INCLUDES
#include<stdio.h>
/* #include<conio.h> */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

// ========= GLOBALS
int size=0; //Size of the linked list

struct SymbTab
{
	char label[10],symbol[10];
	int addr;
	struct SymbTab *next;
};

// Pointers to start and end nodes
struct SymbTab *first, *last;


// ========= PROTOTYPES
void Insert();
void Display();
void Delete();
int Search(char lab[]);


// ========= FUNCTIONS
// Main control function, called on execution
void main()
{
	int op,y;
	char la[10];

	do
	{
		printf("\n\tSYMBOL TABLE IMPLEMENTATION\n");
		printf("\n\t1.INSERT\n\t2.DISPLAY\n\t3.DELETE\n\t4.SEARCH\n\t6.END\n");
		printf("\n\tEnter your option : ");

		scanf("%d",&op);

		switch(op)
		{
			case 1:
				int n, addr;
				char l[10], symbol[];

				printf("\n\tEnter the label : ");
				scanf("%s",l);

				n = Search(l);

				if(n==1)
				{
					printf(
					"\n\tThe label exists already in the symbol table\n\tDuplicate can.t be inserted"
					);

					break;
				} //Breaks this case if the label is already taken


				printf("\n\tEnter the symbol : ");
				scanf("%s",&symbol);

				printf("\n\tEnter the address : ");
				scanf("%d",&addr);

				Insert(l, symbol, addr); //todo test

				printf("\n\tLabel inserted\n");
			break;

			case 2:
				Display();
			break;

			case 3:
				int a;

				printf("\n\tEnter the label to be deleted : ");
				scanf("%s",l);

				a=Search(l);

				if(a==0){
					printf("\n\tLabel not found, delet aborted.\n");
					break;
				}

				Delete(l); //call delete with label char array
			break;

			case 4:
				printf("\n\tEnter the label to be searched : ");
				scanf("%s",la);

				y=Search(la);

				printf("\n\tSearch Result:");

				if(y==1)
					printf("\n\tThe label is present in the symbol table\n");
				else
					printf("\n\tThe label is not present in the symbol table\n");
			break;

			case 6:
				exit(0);
		}
	} while(op<6);

}  /* end of main */

// Insert new value into the list
void Insert(char l[], char s[], int addr)
{
	struct SymbTab *p;
	p=malloc(sizeof(struct SymbTab));

	strcpy(p->label, l);
	strcpy(p->symbol, s);

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
	int i;
	struct SymbTab *p;
	p=first;
	printf("\n\tLABEL\t\tSYMBOL\t\tADDRESS\n");

	for(i=0;i<size;i++)
	{
		printf("\t%s\t\t%s\t\t%d\n",p->label,p->symbol,p->addr);
		p=p->next;
	}
}

// Search for a given label in the linked list
int Search(char lab[])
{
	int i,flag=0;
	struct SymbTab *p;
	p=first;

	for(i=0;i<size;i++)
	{
		if(strcmp(p->label,lab)==0)
			flag=1;

		p=p->next;
	}
	return flag;
}

// Delete function : when given a label remove it from the list
void Delete(char l[])
{
	struct SymbTab *p,*q;
	p=first;


	if(strcmp(first->label,l)==0)
		first=first->next;

	else if(strcmp(last->label,l)==0)
	{
		q=p->next;
		while(strcmp(q->label,l)!=0)
		{
			p=p->next;
			q=q->next;
		}	if(strcmp(first->label,l)==0)
		first=first->next;

		else if(strcmp(last->label,l)==0)
		{
			q=p->next;
			while(strcmp(q->label,l)!=0)
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
			while(strcmp(q->label,l)!=0)
			{
				p=p->next;
				q=q->next;
			}
			p->next=q->next;
		}
		size--;

		printf("\n\tAfter Deletion:\n");
		Display();
		p->next=NULL;
		last=p;
	}
	else
	{
		q=p->next;
		while(strcmp(q->label,l)!=0)
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