/**
*    Parser: made by Roberto Poletti with Bison     
*
*    Il parser, a seguito di ripetute chiamate al lexer mediante yylex(), riceve sotto-sequenze di token 
*    che portano al riconoscimento progressivo delle regole sintattiche del linguaggio.
*    Al termine del riconoscimento di ogni regola sintattica viene eseguita l'azione semantica C presente 
*    alla fine della regola e racchiusa tra graffe.
**/

/*   Dichiarazioni black-box  */

%{
     #include <stdio.h>
     #include <stdlib.h>
     #include "ast.h"
     #define YYSTYPE Node *
     Node *root = NULL; //radice dell'albero sintattico astratto
     extern Lexval lexval;
     extern char *yytext;
     extern int num_line;
%}

/**
*   Dichiarazioni white-box 
*   
*   Vengono dichiarati tutti i token previsti dal lessico Tela e resi disponibili al lexer. Ad ogni chiamata di yylex() viene restituito 
*   uno fra questi in elenco.
*
**/

%token MODULE ID TYPE VAR CONST START END IF THEN ELSIF ELSE WHILE DO ERROR PLUS MINUS MULT DIV
%token RETURN READ WRITE AND OR NOT EQ NEQ GE GT LE LT INTCONST REALCONST CHARCONST STRCONST BOOLCONST

/**
*    Regole di traduzione
*
*    Al termine del riconoscimento di una regola sintattica viene generato un sotto-albero sintattico tramite l'uso di pseudo-variabili. 
*    Ogni sotto-albero è una rappresentazione gerarchica del costrutto sintattico riconosciuto e ne mantiene le informazioni rilevanti, 
*    prelevate in modo incrementale dal codice sorgente.
*    Il sotto-albero generato viene collegato all'albero sintattico astratto del programma, che rispecchia in tutto e per tutto la struttura
*    del suo codice sorgente.
*
**/

%%

program             : module-decl{$$ = nontermnode(N_PROGRAM); $$->child1 = $1; root = $$;}
                    ;

module-decl         : MODULE ID{$$ = idnode();} '(' opt-param-list ')' ':' TYPE{$$ = typenode();} opt-var-sect opt-const-sect 
                         opt-module-list module-body 
                         {
                              $$ = nontermnode(N_MODULE_DECL); 
                              $$->child1 = $3; 
                              $3->brother = $5; 
                              $5->brother = $9; 
                              $9->brother = $10; 
                              $10->brother = $11; 
                              $11->brother = nontermnode(N_OPT_MODULE_LIST); 
                              $11->brother->child1 = $12; 
                              $11->brother->brother = $13; 
                         }
                    ;

opt-param-list      : param-list{$$ = nontermnode(N_OPT_PARAM_LIST); $$->child1 = $1;}
                    | {$$ = nontermnode(N_OPT_PARAM_LIST);}
                    ;

param-list          : param-decl ',' param-list {$$ = $1; $1->brother = $3;}
                    | param-decl{$$ = $1;}
                    ;

param-decl          : ID{$$ = idnode();} ':' TYPE {$4 = typenode(); $$ = nontermnode(N_PARAM_DECL); $$->child1 = $2; $$->child2 = $4;}
                    ;

opt-var-sect        : VAR decl-list {$$ = nontermnode(N_OPT_VAR_SECT); $$->child1 = $2;}
                    | {$$ =nontermnode(N_OPT_VAR_SECT);}
                    ;

decl-list           : decl ';' decl-list {$$ = $1; $1->brother = $3;}
                    | decl ';'{$$ = $1;}
                    ;
        
decl                : id-list ':' TYPE {$$ = nontermnode(N_DECL); $$->child1 = nontermnode(N_ID_LIST); $3 = typenode(); $$->child1->child1 = $1; $$->child2 = $3;}
                    ;

id-list             : ID{$$ = idnode();} ',' id-list {$$ = $2; $2->brother = $4;}
                    | ID {$$ = idnode();}
                    ;

opt-const-sect      : CONST const-list {$$ = nontermnode(N_OPT_CONST_SECT); $$->child1 = $2;}
                    | {$$ = nontermnode(N_OPT_CONST_SECT);}
                    ;

const-list          : const-decl const-list {$1->brother->brother = $2; $$ = $1;}
                    | const-decl {$$ = $1;}
                    ;

const-decl          : decl '=' expr ';' {$1->brother = $3; $$ = $1;}
                    ;

opt-module-list     : module-decl opt-module-list {$$ = $1; $1->brother = $2;}
                    | {$$ = NULL;}
                    ;

module-body         : START ID{$$ = idnode();} stat-list END ID {$$ = nontermnode(N_MODULE_BODY); $6 = idnode(); $3->brother = nontermnode(N_STAT_LIST); 
                         $3->brother->child1 = $4; $3->brother->brother = $6; $$->child1 = $3;}
                    ;

stat-list           : stat ';' stat-list {$$ = $1; $1->brother = $3;}
                    | stat ';' {$$ = $1;}
                    ;

stat                : assign-stat {$$ = $1;}
                    | if-stat {$$ = $1;}
                    | while-stat {$$ = $1;}
                    | return-stat {$$ = $1;}
                    | read-stat {$$ = $1;}
                    | write-stat {$$ = $1;}
                    | module-call {$$ = $1;}
                    ;

assign-stat         : ID{$$ = idnode();} '=' expr {$$ = nontermnode(N_ASSIGN_STAT); $$->child1 = $2; $$->child2 = $4;}
                    ;

if-stat             : IF expr THEN stat-list opt-elsif-stat-list opt-else-stat END {$$ = nontermnode(N_IF_STAT); $$->child1 = $2; 
                         $$->child1->brother = nontermnode(N_STAT_LIST); $$->child1->brother->child1 = $4; $$->child2 = nontermnode(N_OPT_ELSIF_STAT_LIST); 
                              $$->child2->child1 = $5; $$->child2->child2 = $6;}
                    ;

opt-elsif-stat-list : ELSIF expr THEN stat-list opt-elsif-stat-list {$$ = $2; $2->brother = nontermnode(N_STAT_LIST); $2->brother->child1 = $4; 
                         $2->brother->brother = $5;}
                    | {$$ = NULL;}
                    ;

opt-else-stat       : ELSE stat-list {$$ = nontermnode(N_STAT_LIST); $$->child1 = $2;}
                    | {$$ = NULL;}
                    ;

while-stat          : WHILE expr DO stat-list END {$$ = nontermnode(N_WHILE_STAT); $$->child1 = $2; $$->child2 = nontermnode(N_STAT_LIST); $$->child2->child1 = $4;}
                    ;
               
return-stat         : RETURN opt-expr {$$ = nontermnode(N_RETURN_STAT); $$->child1 = $2;}
                    ;

opt-expr            : expr {$$ = $1;}
                    | {$$ = NULL;}
                    ;

read-stat           : READ '(' id-list ')' {$$ = nontermnode(N_READ_STAT); $$->child1 = nontermnode(N_ID_LIST); $$->child1->child1 = $3;}
                    ;

write-stat          : WRITE '(' expr-list ')' {$$ = nontermnode(N_WRITE_STAT); $$->child1 = nontermnode(N_EXPR_LIST); $$->child1->child1 = $3;}
                    ;

expr-list           : expr ',' expr-list {$$ = $1; $1->brother = $3;}
                    | expr {$$ = $1;}
                    ;

expr                : expr bool-op bool-term {$2->child1 = $1; $2->child2 = $3; $$ = $2;}
                    | bool-term {$$ = $1;}
                    ;

bool-op             : AND {$$ = logicnode(O_AND);}
                    | OR {$$ = logicnode(O_OR);}
                    ;

bool-term           : rel-term rel-op rel-term {$$ = $2; $2->child1 = $1; $2->child2 = $3;}
                    | rel-term {$$ = $1;}
                    ;

rel-op              : EQ {$$ = relnode(O_EQ);}
                    | NEQ {$$ = relnode(O_NEQ);}
                    | LT {$$ = relnode(O_LT);}
                    | LE {$$ = relnode(O_LE);}
                    | GT {$$ = relnode(O_GT);}
                    | GE {$$ = relnode(O_GE);}
                    ;

rel-term            : rel-term low-bin-op low-term {$$ = $2; $2->child1 = $1; $2->child2 = $3;}
                    | low-term {$$ = $1;}
                    ;

low-bin-op          : PLUS {$$ = mathnode(O_PLUS);}
                    | MINUS {$$ = mathnode(O_MINUS);}
                    ;

low-term            : low-term high-bin-op factor {$2->child1 = $1; $2->child2 = $3; $$ = $2;}
                    | factor {$$ = $1;}
                    ;

high-bin-op         : MULT {$$ = mathnode(O_MULT);}
                    | DIV {$$ = mathnode(O_DIV);}
                    ;

factor              : unary-op factor {$$ = $1; $1->child1 = $2;}
                    | '(' expr ')' {$$ = $2;}
                    | ID {$$ = idnode();}
                    | constant {$$ = $1;}
                    | module-call {$$ = $1;}
                    | cond-expr {$$ = $1;}
                    | TYPE{$$ = castnode();} '(' expr ')' {$2->child1 = $4; $$ = $2;}
                    ;

unary-op            : MINUS {$$ = negnode(O_CHANGE_SIGN);}
                    | NOT {$$ = negnode(O_NOT);}
                    ;

constant            : CHARCONST {$$ = charconstnode();}
                    | INTCONST {$$ = intconstnode();}
                    | REALCONST {$$ = realconstnode();}
                    | STRCONST {$$ = strconstnode();}
                    | BOOLCONST {$$ = boolconstnode();}
                    ;

module-call         : ID{$$ = idnode();} '(' opt-expr-list ')' {$$ = nontermnode(N_MODULE_CALL); $$->child1 = $2; $$->child2 = $4;}
                    ;

opt-expr-list       : expr-list {$$ = $1;}
                    | {$$ = NULL;}
                    ;

cond-expr           : IF expr THEN expr opt-elsif-expr-list ELSE expr END {$$ = nontermnode(N_COND_EXPR); $$->child1 = $2; $2->brother = $4; 
                         $$->child2 = nontermnode(N_OPT_ELSIF_EXPR_LIST); $$->child2->child1 = $5; $$->child2 ->child2 = $7;}
                    ;

opt-elsif-expr-list : ELSIF expr THEN expr opt-elsif-expr-list {$$ = $2; $2->brother = $4; $4->brother = $5;}  
                    | {$$ = NULL;}
                    ;
%%

/**   
*    Funzioni ausiliarie  
*    
*    Ogni funzione è specializzata nella costruzione di uno specifico nodo previsto dalla sintassi 
*    del linguaggio Tela.
*
**/

void yyerror(){
     fprintf(stderr, "Linea %d: errore di sintassi sul simbolo \"%s\"\n", num_line, yytext);
     exit(-1);
}

Node *nontermnode(SymName name){
     Node *p = newnode(T_NONTERMINAL, name);
     return p;
}

Node *relnode(RelOp operation){
     Node *p = nontermnode(N_REL_EXPR);
     p->lexval.ival = operation;
     return p;
}

Node *idnode(){
     Node *p = newnode(T_TERMINAL, T_ID);
     p->lexval.sval = lexval.sval;
     return p;
}

Node *typenode(){
     Node *p = newnode(T_TERMINAL, T_TYPE);
     p->lexval.ival = lexval.ival;
     return p;
}

Node *logicnode(BoolOp operation){
     Node *p = nontermnode(N_LOGIC_EXPR);
     p->lexval.ival = operation;
     return p;
}

Node *mathnode(MathOp operation){
     Node *p = nontermnode(N_MATH_EXPR);
     p->lexval.ival = operation;
     return p;
}

Node *negnode(NegOp operation){
     Node *p = nontermnode(N_NEG_EXPR);
     p->lexval.ival = operation;
     return p;
}

Node *castnode(){
     Node *p = nontermnode(N_CAST);
     p->lexval.ival = lexval.ival;
     return p;
}

Node *intconstnode(){
     Node *p = newnode(T_TERMINAL, T_INTCONST);
     p->lexval.ival = lexval.ival;
     return p;
}

Node *charconstnode(){
     Node *p = newnode(T_TERMINAL, T_CHARCONST);
     p->lexval.cval = lexval.cval;
     return p;
}

Node *realconstnode(){
     Node *p = newnode(T_TERMINAL, T_REALCONST);
     p->lexval.rval = lexval.rval;
     return p;
}

Node *strconstnode(){
     Node *p = newnode(T_TERMINAL, T_STRCONST);
     p->lexval.sval = lexval.sval;
     return p;
}

Node *boolconstnode(){
     Node *p = newnode(T_TERMINAL, T_BOOLCONST);
     p->lexval.bval = lexval.bval;
     return p;
}

Node *newnode(SymType type, SymName name){
     Node *p = malloc(sizeof(Node));
     p->type = type;
     p->name = name;
     p->line = num_line;
     p->child1 = p->child2 = p->brother = NULL;
     return p;
}
