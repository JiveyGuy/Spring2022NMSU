#define MAIN 1
#define DEBUG 1

#ifndef SYMTABLE
#define SYMTABLE

struct SymbTab
{
	char *symbol;
	int addr;
	struct SymbTab *next;
};

// ========= PROTOTYPES
void debug(char s[]);
void Insert(char s[], int addr);
void Display();
void Delete(char s[]);
int Search(char s[]);
#endif