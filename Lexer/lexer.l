/** 
*	Lexer: made by Roberto Poletti with Flex
*
*	Dato un file sorgente .tela, visto come una lista di caratteri, al riconoscimento di una delle 
*	regexp elencate nelle regole di traduzione viene eseguita la corrispondente azione C racchiusa tra graffe.
*	Lo scopo primario è restituire il token che denota la categoria lessicale di cui la stringa 
*	di caratteri accumulata fa parte. Tuttavia, in corrispondenza di pseudo-simboli come il carriage return o i commenti, 
*	tale azione non risulta necessaria poiché non forniscono informazioni aggiuntive sulla semantica del programma Tela.
*
**/

/*	Dichiarazioni black-box	 */

%{
	#include "../Parser/parser.tab.h"
	#define LEXVAL
	#define OTHER
	#include "../Parser/def.h"
	Lexval lexval;
	int num_line = 1;
	char *clone(char* s);
	Bool atob(char *s);
%}

/** 
*	Dichiarazioni white-box 
*
*	La dichiarazione di una lista di definizioni regolari garantisce modularità nella realizzazione
*	delle regexp che verranno usate da Flex per il riconoscimento dei pattern nel file .tela
*
**/

%option noyywrap

delimiter	[ \t]
spacing		{delimiter}+
comment 	#(.)*\n
letter		[A-Za-z]
nonzero		[1-9]
number		[0-9]
alphanum 	{letter}|{number}
boolconst	true|false
charconst 	'.'
intconst	0|({nonzero}{number}*)
realconst	{intconst}\.{number}+
strconst	\"([^\"])*\"
id 			{letter}{alphanum}*(_{alphanum}+)*
sugar		[\,;:()=]

/*	Regole di traduzione  */

%%

"\n" 			{num_line++;}
{spacing}		;
{comment}		{num_line++;}
{sugar}			{return(yytext[0]);}

"char"			{lexval.ival = CHAR; return(TYPE);}
"int"			{lexval.ival = INT; return(TYPE);}
"real"			{lexval.ival = REAL; return(TYPE);}
"string" 		{lexval.ival = STRING; return(TYPE);}
"bool" 			{lexval.ival = BOOL; return(TYPE);}
"void" 			{lexval.ival = VOID; return(TYPE);}

{charconst}		{lexval.cval = (clone(yytext))[1]; return(CHARCONST);} 
{intconst}		{lexval.ival = atoi(yytext); return(INTCONST);}
{realconst}		{lexval.rval = atof(yytext); return(REALCONST);}
{strconst} 		{lexval.sval = clone(yytext); return(STRCONST);}
{boolconst}		{lexval.bval = atob(yytext); return(BOOLCONST);}

"var"			{return(VAR);}
"const"			{return(CONST);}

"+"				{return(PLUS);}
"-"				{return(MINUS);}
"*"				{return(MULT);}
"/"				{return(DIV);}

"==" 			{return(EQ);}
"!=" 			{return(NEQ);}
">"				{return(GT);}
">="			{return(GE);}
"<"				{return(LT);}
"<="			{return(LE);}

"and"			{return(AND);}
"or"			{return(OR);}
"not"			{return(NOT);}

"if" 			{return(IF);}
"then" 			{return(THEN);}
"elsif"			{return(ELSIF);}
"else"			{return(ELSE);}
"while"			{return(WHILE);}
"do"			{return(DO);}

"module" 		{return(MODULE);}
"begin" 		{return(START);}
"end" 			{return(END);}
"return" 		{return(RETURN);}

"read" 			{return(READ);}
"write"			{return(WRITE);}

{id}			{lexval.sval = clone(yytext); return(ID);}
.				{return(ERROR);}

%%

/*	Funzioni ausiliarie  */


/**	
*	clone	
*
*  	Allocazione della stringa lessicale in un'area di memoria dedicata.					
*	Risulta necessaria in quanto la varabile yytext offerta da Flex viene 
*	continuamente sovrascritta a ogni riconoscimento di una regexp.
*
**/

char *clone(char *s){
	char *p;
	p = malloc(strlen(s)+1);
	strcpy(p, s);
	return strtok(strtok(p,"\""),"\"");
}

/**
*	atob
*
*	Data la stringa lessicale true o false restituisce il 
*	corrispondente valore numerico 1 o 0.
*
**/

Bool atob(char *s){
	return s[0] == 'f' ? FALSE : TRUE;
}
