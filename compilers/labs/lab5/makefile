# Jason Ivey SID: 800696866 - Jiveyguy@nmsu.edu

# /_/\     /_______/\ /_______/\     /_____/\    
# \:\ \    \::: _  \ \\::: _  \ \    \::::_\/_   
#  \:\ \    \::(_)  \ \\::(_)  \/_    \:\/___/\  
#   \:\ \____\:: __  \ \\::  _  \ \    \_::._\:\ 
#    \:\/___/\\:.\ \  \ \\::(_)  \ \    /_____\/ 
#     \_____\/ \__\/\__\/ \_______\/    \_____/   
                                                  

# Sep 12th 2022                                        
                                        
# all rule, default when running "make" in this dir
all: lab5

# c compile and target
lab4: lab5.y lab5.l symtable.c symtable.h 
	yacc -d lab5.y
	lex lab5.l
	gcc y.tab.h y.tab.c lex.yy.c symtable.c -o lab5
# simple exec rule
run:
	./lab5
# make the dir clena of generated code
clean:
	rm lex.yy.c y.tab.c y.tab.h lab5 