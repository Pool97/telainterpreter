/**
*    Made by Roberto Poletti
*
*    Header file contenente tutte le definizioni e i prototipi associati 
*    all'albero sintattico astratto (AST).
**/

#define LEXVAL
#include "def.h"

/**
*   Qualifiche dei nodi
**/

typedef enum{
    O_EQ,
    O_NEQ,
    O_GT,
    O_GE,
    O_LT,
    O_LE
}RelOp;

typedef enum{
    O_AND, 
    O_OR
}BoolOp;

typedef enum{
    O_PLUS,
    O_MINUS,
    O_MULT,
    O_DIV
}MathOp;

typedef enum{
    O_CHANGE_SIGN,
    O_NOT
}NegOp;

/**
*   Attributi semantici
**/

typedef enum{
    N_PROGRAM, N_MODULE_DECL,
    N_OPT_PARAM_LIST,
    N_OPT_VAR_SECT,
    N_OPT_CONST_SECT,
    N_OPT_MODULE_LIST,
    N_MODULE_BODY,
    N_PARAM_DECL,
    N_DECL,
    N_ID_LIST,
    N_STAT_LIST,
    N_ASSIGN_STAT,
    N_IF_STAT,
    N_WHILE_STAT,
    N_RETURN_STAT,
    N_READ_STAT,
    N_WRITE_STAT,
    N_MODULE_CALL,
    N_OPT_ELSIF_STAT_LIST,
    N_EXPR_LIST,
    N_LOGIC_EXPR,
    N_REL_EXPR,
    N_MATH_EXPR,
    N_NEG_EXPR,
    N_COND_EXPR,
    N_OPT_ELSIF_EXPR_LIST,
    N_CAST,
    T_TYPE,
    T_ID,
    T_CHARCONST,
    T_INTCONST,
    T_REALCONST,
    T_STRCONST,
    T_BOOLCONST,
}SymName;

typedef enum{
    T_NONTERMINAL,
    T_TERMINAL
}SymType;

/**
*    Definizione di un nodo generico dell'AST.
**/

typedef struct node{
    SymType type;
    SymName name;
    Lexval lexval;
    int line;
    struct node *child1, *child2, *brother;
}Node;

/**
*   Prototipi, rispettivamente per:
*       - Stampare a schermo l'AST del programma sorgente
*       - Iniziare l'analisi sintattica del codice sorgente
*       - Generare un errore sintattico contestualizzato
*
**/

void treeprint(Node *, int);
int yyparse();
void yyerror();

/**
*  Prototipi per la generazione dei nodi dell'AST
**/

Node *nontermnode(SymName);
Node *idnode();
Node *relnode();
Node *typenode();
Node *logicnode();
Node *mathnode(MathOp);
Node *negnode(NegOp);
Node *castnode();
Node *node();
Node *intconstnode();
Node *charconstnode();
Node *realconstnode();
Node *strconstnode();
Node *boolconstnode();
Node *newnode(SymType, SymName);


/**
*  Prototipi getters per l'accesso a informazioni contenute nei nodi 
**/

Bool is_null(Node *);
char *get_name(Node *);
int get_line(Node *);
int get_qualifier(Node *);
