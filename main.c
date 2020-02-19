/**
*    Made by Roberto Poletti 
* 
*    File che dirige l'esecuzione delle varie fasi dell'interprete:
*         - Analisi lessicale
*         - Analisi sintattica: attraverso yyparse, che ripetutamente richiama la funzone yylex di analisi lessicale
*         - Creazione della symbol table gerarchica
*          - Analisi semantica
*          - Interpretazione dell'AST (esecuzione del codice sorgente)
*
*    Se anche una sola delle fasi genera un errore viene bloccata l'intera esecuzione dell'interprete Tela.
**/

#include "SemanticAnalyzer/checker.h"
extern FILE *yyin;
extern Node *root;
extern void interpret(Node *, int, char *[]);

int main(int argc, char *argv[]){ //argv contiene la lista di argomenti inseriti dall'utente (nome file sorgente e argomenti del modulo main)
     int result;
     yyin = fopen(argv[1], "r");
     yyparse();
     create_st(root);
     sem_check(root);
     interpret(root, argc, argv);
     printf("\n");
     return result;
}