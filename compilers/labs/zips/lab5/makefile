# Jason Ivey SID: 800696866 - Jiveyguy@nmsu.edu

# /_/\     /_______/\ /_______/\     /_____/\    
# \:\ \    \::: _  \ \\::: _  \ \    \::::_\/_   
#  \:\ \    \::(_)  \ \\::(_)  \/_    \:\/___/\  
#   \:\ \____\:: __  \ \\::  _  \ \    \_::._\:\ 
#    \:\/___/\\:.\ \  \ \\::(_)  \ \    /_____\/ 
#     \_____\/ \__\/\__\/ \_______\/    \_____/   
                                                  

# Made: Sep 12th 2022     
# Last Edit Made: Sep 26th 2022                                     
                                        
# all rule, default when running "make" in this dir
all: lab5

# c compile and target
lab5: lab5.y lab5.l
	yacc -d lab5.y --warnings=none
	lex lab5.l
	gcc lex.yy.c y.tab.c -o lab5

# simple exec rule
run:
	./lab5 

fail:
	./lab5 < ErrorTest.decaf
	./lab5 < ErrorTest1.decaf
	./lab5 < ErrorTest2.decaf
	./lab5 < ErrorTest3.decaf
	./lab5 < ErrorTest4.decaf
	
good:
	./lab5 < GoodTest.decaf

# make the dir clean of generated code
clean:
	rm -f lex.yy.c y.tab.c y.tab.h lab5 
