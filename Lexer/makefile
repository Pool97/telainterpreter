lexer.o: lexer.c
	cc -g3 -c lexer.c 
lexer.c: lexer.l ../Parser/parser.tab.h ../Parser/def.h
	flex -o lexer.c lexer.l 
