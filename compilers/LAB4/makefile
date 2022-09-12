# Jason Ivey SID: 800696866 - Jiveyguy@nmsu.edu

#  __       ________    _______       __   __       
# /_/\     /_______/\ /_______/\     /__/\/__/\     
# \:\ \    \::: _  \ \\::: _  \ \    \  \ \: \ \__  
#  \:\ \    \::(_)  \ \\::(_)  \/_    \::\_\::\/_/\ 
#   \:\ \____\:: __  \ \\::  _  \ \    \_:::   __\/ 
#    \:\/___/\\:.\ \  \ \\::(_)  \ \        \::\ \  
#     \_____\/ \__\/\__\/ \_______\/         \__\/  
                                                  

# Sep 12th 2022                                        
                                        
# all rule, default when running "make" in this dir
all: lab4

# c compile and target
lab4: lab4.l lab4.y symtable.c symtable.h 
	lex lab4.l
	yacc -d lab4.y
	gcc lex.yy.c symtable.c y.tab.c -o lab4

run:
	./lab4