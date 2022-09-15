# Jason Ivey SID: 800696866 - Jiveyguy@nmsu.edu

# all rule, default when running "make" in this dir
all: lex_r gcc_r

# lex gen rule
lex_r: lab2remove.l
	lex lab2remove.l

# compile rule
gcc_r: lex.yy.c
	gcc lex.yy.c -o lab2_1

# cleaning things up is always nice
clean: 
	rm lab2_1 lex.yy.c 

# better than pressing up arrow 4 times	
# (This runs the program)
run:
	./lab2_1 < comment.tst