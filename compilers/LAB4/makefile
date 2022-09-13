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
lab4: lab4.y lab4.l symtable.c symtable.h 
	yacc -d lab4.y
	lex lab4.l
	gcc y.tab.h y.tab.c lex.yy.c symtable.c -o lab4

run:
	./lab4

clean:
	rm lex.yy.c y.tab.c y.tab.h lab4 