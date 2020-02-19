all: myParser parser
myParser:
	+$(MAKE) -C Parser
	+$(MAKE) -C Lexer

parser: Lexer/lexer.c Parser/parser.tab.c Parser/ast.c SemanticAnalyzer/symbol_table.c SemanticAnalyzer/checker.c main.c Interpreter/interpreter.c
	gcc -Wall -g3 -o telai main.c Lexer/lexer.c Parser/parser.tab.c Parser/ast.c SemanticAnalyzer/symbol_table.c Interpreter/interpreter.c Interpreter/runtime_env.c SemanticAnalyzer/checker.c 

