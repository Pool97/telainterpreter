/**
*    Made by Roberto Poletti
*    
*    Header file contenente le definizioni e i prototipi utili per la creazione e la gestione 
*    della symbol table gerarchica Tela.
*
**/

#define TOT 25
#define SHIFT 8
#define OTHER
#include "../Parser/def.h"
#undef OTHER
#include "../Parser/ast.h"


/**
*   Attributi di un simbolo della tabella.
**/

typedef enum{
    C_VAR, C_CON, C_MOD, C_PAR, C_NIL
}Class;

typedef struct Symbol Symbol;
typedef Symbol *SymbolTable[TOT]; 
typedef struct Formals Formals;

struct Formals{
    int num;
    Symbol *descr;
};

/**
*    Definizione di un simbolo.
**/

struct Symbol{
    char *name;    //nome dell'identificatore
    int oid;    //numero univoco per ogni identificatore: assoluto per i moduli, relativo per variabili, parametri e costanti
    Class class;    //classificatore: indica se l'identificatore è un nome di modulo, variabile, parametro o costante
    Type type;     //tipo dell'identificatore
    SymbolTable *p_sym_table;   //non nullo solo per i moduli, è la symbol table associata allo scope del modulo
    Formals formals;    //non nullo solo per i moduli, puntatore alla linked list dei parametri formali del modulo
    Symbol *next;   //puntatore al prossimo simbolo con pari hash nell'hashtable
    Symbol *back;   //puntatore allo scope padre, utile per la risalita degli scope
};

/**
*   Prototipi per l'accesso agli elementi della symbol table.
**/

Symbol *lookup(char *);
Symbol *lookup_in_bucket(Symbol **, char *);
Symbol *lookup_in(Symbol *, char *);
Symbol *lookup_from(Symbol *, char *);
Class get_class(char *);
Bool is_visible(char *);
Type get_type(char *);
Type get_module_type();
int get_module_num(char *);
Symbol *get_module_descr(char *);


/**
*   Prototipi per la gestione della symbol table.
**/

void create_st(Node *);
Symbol *new_symbol(char *, Class, Type);
void insert(Symbol *);
Symbol **select_bucket(int, SymbolTable *);
void append_to_bucket(Symbol **, Symbol *);
void link_formal_parameter(Symbol *, Symbol *);

/**
*   Prototipi per l'esplorazione degli scope di un programma Tela.
**/

void go_down_in(Symbol *);
void go_up_from(Symbol *);
void go_up();
void keep_outer_scope_of(Symbol *);
void steps_from_first_scope(Symbol *, char *,  int *);

#ifdef PROTOTYPES_AST

/**
*   Prototipi per l'attraversamento dell'AST in fase di creazione 
*   della symbol table.
**/

static void program(Node *);
static void module_decl(Node *);
static void id_module(Node *, Class, Type);
static void opt_param_list(Node *);
static void param_decl(Node *);
static void id_param_decl(Node *, Class, Type);
static void opt_var_sect(Node *);
static void decl(Node *, Class);
static void id_decl(Node *, Class, Type);
static void id_list(Node *, Class, Type);
static void opt_const_sect(Node *);
static void opt_module_list(Node *);

#endif