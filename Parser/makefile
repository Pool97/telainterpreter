parser.tab.o : parser.tab.c
	cc -g -c parser.tab.c
	
parser.tab.h parser.tab.c: parser.y def.h 
	bison -dv parser.y --debug
