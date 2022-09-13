// Should main function be enabled?
#define MAIN 1
// Will debug be shown? 
// #define DEBUG 1

// Namespace header
#ifndef SYMTABLE
	#define SYMTABLE

	// Modified stuct to use symbol instead of label
	struct SymbTab
	{
		char *symbol; // name of var
		int addr; // addr of var
		struct SymbTab *next; //pointer to next var symbtab node
	};

	// ========= PROTOTYPES

	// debug: takes in char array and prints if DEBUG defined
	void debug(char s[]);

	// Insert, takes in label and addr and inserts to table
	void Insert(char s[], int addr);

	// Simple print of everything in sym table
	void Display();

	// Delete : removes label from symbol table
	void Delete(char s[]);

	// Search returns if symbol exists
	int Search(char s[]);
#endif