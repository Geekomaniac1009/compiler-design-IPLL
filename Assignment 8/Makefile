parse: y.tab.c lex.yy.c
	   gcc -o parse y.tab.c lex.yy.c -lfl

y.tab.c: calc_220101122.y
		yacc -d calc_220101122.y

lex.yy.c: calc_220101122.l
		  flex calc_220101122.l

clean: 
		rm -f y.tab.c y.tab.h lex.yy.c parse