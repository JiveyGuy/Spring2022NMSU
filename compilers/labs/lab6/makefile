# Jason Ivey SID: 800696866 - Jiveyguy@nmsu.edu


# ██╗      █████╗ ██████╗  ██████╗ 
# ██║     ██╔══██╗██╔══██╗██╔════╝ 
# ██║     ███████║██████╔╝███████╗ 
# ██║     ██╔══██║██╔══██╗██╔═══██╗
# ███████╗██║  ██║██████╔╝╚██████╔╝
# ╚══════╝╚═╝  ╚═╝╚═════╝  ╚═════╝ 
                                 
# Sep 26th 2022                                        
                                        
# all rule, default when running "make" in this dir
all: lab6

# c compile and target
lab6: ast.c ast.h
	lex lab6.l
	yacc -d lab6.y
	gcc lex.yy.c y.tab.c -o lab6
	mv lex.yy.c y.tab.c y.tab.h lab6 ./target 

# simple exec rule
run:
	cd ./target
	./lab6 
	cd ..

fail:
	./lab6 < ./tests/ErrorTest.decaf
	
good:
	./lab6 < ./tests/GoodTest.decaf

# make the dir clean of generated code
clean:
	rm -f ./target/lex.yy.c ./target/y.tab.c ./target/y.tab.h ./target/lab6 