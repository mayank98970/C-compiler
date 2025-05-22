all:
	bison -d compiler.y
	flex compiler.l
	gcc -o compiler compiler.tab.c lex.yy.c -lfl

clean:
	rm -f compiler lex.yy.c compiler.tab.c compiler.tab.h
