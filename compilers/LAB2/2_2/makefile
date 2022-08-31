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

all: yacc_r lex_r gcc_r

yacc_r: lab2docalc.y
	yacc -d lab2docalc.y   

lex_r: lab2docalc.l
	lex lab2docalc.y

gcc_r: y.tab.c lex.yy.c
	gcc y.tab.c lex.yy.c -o lab2_2
	
run:
	./lab2_2