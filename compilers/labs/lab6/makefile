# Jason Ivey SID: 800696866 - Jiveyguy@nmsu.edu


# ██╗      █████╗ ██████╗  ██████╗ 
# ██║     ██╔══██╗██╔══██╗██╔════╝ 
# ██║     ███████║██████╔╝███████╗ 
# ██║     ██╔══██║██╔══██╗██╔═══██╗
# ███████╗██║  ██║██████╔╝╚██████╔╝
# ╚══════╝╚═╝  ╚═╝╚═════╝  ╚═════╝ 
                                 
# Made: Sep 26th 2022
# Editted: 
# 	Oct 2:
# 		Moved yacc cmd before lex cmd
# 		made subdirs to organize this large project                                                                                
# all rule, default when running "make" in this dir
all: lab6

# c compile and target
lab6: lab6.y lab6.l ast.c ast.h
	yacc -d lab6.y
	lex lab6.l
	gcc -o lab6 lex.yy.c y.tab.c ast.c

# simple exec rule
run:
	./lab6

test:
	./lab6 < lab6test.decaf

# make the dir clean of generated code
clean:
	rm -f lex.yy.c y.tab.c y.tab.h lab6 