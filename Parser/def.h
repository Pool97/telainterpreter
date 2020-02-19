/**
*   Header file di interfaccia tra il Lexer e gli altri moduli dell'interprete. 
*   Fornisce in particolare la definizione di una stringa lessicale (Lexval) e dei tipi 
*   dichiarabili nel linguaggio Tela.
**/

#include <stdio.h>

#ifdef LEXVAL

typedef enum{
    FALSE, TRUE
}Bool;

typedef union{
    char *sval;
    int ival;
    Bool bval;
    char cval;
    float rval;
}Lexval;

int yylex(void); //tale prototipo è richiesto da Bison per poter richiamare il lexer 
#endif

#ifdef OTHER
extern int num_line; //mantiene il numero di linea del file sorgente che si sta scannerizzando con il lexer

typedef enum{
    CHAR,
    INT,
    REAL,
    STRING,
    BOOL,
    VOID,
    NIL
}Type;


#endif