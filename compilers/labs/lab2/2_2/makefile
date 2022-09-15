# Jason Ivey SID: 800696866 - Jiveyguy@nmsu.edu
#  /$$                 /$$        /$$$$$$          /$$$$$$ 
# | $$                | $$       /$$__  $$        /$$__  $$
# | $$        /$$$$$$ | $$$$$$$ |__/  \ $$       |__/  \ $$
# | $$       |____  $$| $$__  $$  /$$$$$$/         /$$$$$$/
# | $$        /$$$$$$$| $$  \ $$ /$$____/         /$$____/ 
# | $$       /$$__  $$| $$  | $$| $$             | $$      
# | $$$$$$$$|  $$$$$$$| $$$$$$$/| $$$$$$$$       | $$$$$$$$
# |________/ \_______/|_______/ |________//$$$$$$|________/
#                                        |______/          
#  "Lab 1" - NMSU 2022, Aug, 22nd
#     Explanantion for: 
#         a = 3 + 5
#         a
# Firstly a letter is found, 
# lowercase 'a' -> 0 which is the index which the result will
# be stored into in the regs[] array. 
# Then the expression = is sent which will return the result 
# on the right side. due to the variable rule in yacc. 
# We then find an integer and push it up the tree then a add
# sign which will be made the parent node, once the second
# integer is found it will be added with the other in the expr + expr
# rule, this will be the result stored in the regs array. 
#  
# a:
# When this sentence is ran the program simply returns the 
# regs array at [a] -> [0] 


all: yacc_r lex_r gcc_r

yacc_r: lab2docalc.y
	yacc -d lab2docalc.y   

lex_r: lab2docalc.l
	lex lab2docalc.l

gcc_r: y.tab.c lex.yy.c
	gcc y.tab.c lex.yy.c -o lab2_2
	
run:
	./lab2_2