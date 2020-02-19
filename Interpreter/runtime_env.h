/**
    Made by Roberto Poletti.
    
    Header file contenente le definizioni e i prototipi per la realizzazione dell'ambiente runtime Tela.
    Un programma Tela è gestito tramite tre memorie:
        - Memoria codice: è una linked list di unità di programma eseguibili.
        - Activation Stack: in cui vengono allocati i record di attivazione dei moduli a seguito di ogni chiamata di modulo.
        - Object Stack: per semplicità gli oggetti locali (vars, params, constants) non sono allocati nel precedente stack ma in questo.

**/

#define CHUNK 200 //lunghezza massima in caratteri di ogni argomento inserito da CLI.
#include "../SemanticAnalyzer/symbol_table.h"
#include <stdlib.h>
#include <string.h>
extern Type infer(Node *);
extern Symbol *current_module;
extern Symbol *program_module;

/**
*   Record dell'Object Stack.
**/

typedef struct object_record{
    Type type;
    Lexval lexval;
}ObjectRecord;

/**
*   Elemento dell'Object Stack.
**/

typedef struct ostack_elem{
    ObjectRecord record;
    struct ostack_elem *next;
}OstackElement;

/**
*   Record dell'Activation Stack.
**/

typedef struct activation_record{
    int numobj;
    OstackElement *objects;
    struct activation_record *alink;
}ActivationRecord;

/**
*   Elemento dell'Activation Stack.
**/

typedef struct astack_elem{
    ActivationRecord record;
    struct astack_elem *next;
}AstackElement;

/**
*    Linked list contenente le unità di programma.
**/

typedef struct program_unit{
    Node *entry_point; //non punta alla prima istruzione di basso livello dell'unità di programma ma alla radice del sotto-albero associato all'unità.
    int nesting_level; //livello di innestamento di un modulo (= 1 se è il modulo principale in quanto è il modulo globale)
    Symbol *scope; //riferimento al simbolo del modulo associato all'unità di programma.
    struct program_unit *next; //riferimento alla prossima unità della linked list
}ProgramUnit;

void create_runtime_env(Node *, int, char *[]);
Bool first_call(int);

/**
*    Prototipi per la gestione della memoria codice.
**/

void create_program_units(Node *, int);
ProgramUnit *new_program_unit(Node *, int);
void append_program_unit(ProgramUnit *);
ProgramUnit *select_program_unit(int);

/**
*    Prototipi per la gestione degli stack.
**/

ActivationRecord *new_act_record();
void pop_act_record();
void push_act_record(ActivationRecord);
AstackElement *peek_act_record();
ObjectRecord new_obj_record(Type, Lexval *);
void pop_obj_record();
void push_obj_record(ObjectRecord);
ObjectRecord *search_object(char *, int);
ObjectRecord new_obj_record(Type, Lexval *);

/**
*   Prototipi per l'accesso a variabili locali e non.
**/

ActivationRecord *compute_access_link(int, int);
ActivationRecord *get_act_record_of_object(char *);
ActivationRecord *traverse_static_chain(int);

/**
*   Prototipi per la lettura degli argomenti inseriti da CLI.
**/

void read_main_parameters(Node *, int);
Lexval read_cli(Type, Lexval, int);