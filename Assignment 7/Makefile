a7_220101122: yy.tab.c lex.yy.c
	gcc yy.tab.c lex.yy.c -o a7_220101122 -lfl

a7_220101122.tab.c: a7_220101122.y
	yacc -d a7_220101122.y

lex.yy.c: a7_220101122.l yy.tab.h
	flex a7_220101122.l

clean:
	rm -f yy.tab.c yy.tab.h lex.yy.c a7_220101122 *.txt
