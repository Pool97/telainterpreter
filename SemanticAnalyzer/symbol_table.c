/**
*    Symbol table gerarchica Tela: made by Roberto Poletti.
*
*    Questa struttura dati mantiene una serie di informazioni sugli identificatori dichiarati nel 
*    file sorgente .tela, acquisite in modo incrementale attraverso un'analisi dell'AST a partire dalla radice.
*    Ogni livello della gerarchia è composto da una symbol table a un livello, implementata con un hashtable e
*    contenente gli identificatori associati a un ben specifico campo di visibilità.
*    
**/

#define PROTOTYPES_AST
#include <string.h>
#include <stdlib.h>
#include "symbol_table.h"

int mod_count = 0;
int rel_count = 0;

Symbol *program_module;
Symbol *current_module;

int hash(char *id) {
    int h = 0;
    for(int i = 0; id[i] != '\0'; i++)
        h = ((h << SHIFT) + id[i]) % TOT;
    
    return h;
}

/**
*   Accesso agli elementi della symbol table corrente.
*
**/

Type get_module_type(){
    return current_module->type;
}

int get_module_num(char *id){
    return lookup(id)->formals.num;
}

Symbol *get_module_descr(char *id){
    return lookup(id)->formals.descr;
}

Class get_class(char *id){
    Symbol *p_sym = lookup(id);
    return p_sym != NULL? p_sym->class : C_NIL;
}

Bool is_visible(char *id){
    return lookup(id) != NULL;
}

Type get_type(char *id){
    Symbol *p_sym = lookup(id);
    return p_sym != NULL? p_sym->type : NIL;
}

Symbol *lookup(char *id){
    return lookup_from(current_module, id);
}

Symbol *lookup_in_bucket(Symbol **head, char *id){
    Symbol *tracer = *head;
    
    while(tracer != NULL){
        if(strcmp(tracer->name, id) == 0)
            return tracer;

        tracer = tracer->next;
    }

    return NULL;
}

Symbol *lookup_in(Symbol *p_mod, char *id){
    Symbol **head = select_bucket(hash(id), p_mod->p_sym_table);
    return lookup_in_bucket(head, id);
}

Symbol *lookup_from(Symbol *p_mod, char *id){
    if(p_mod == NULL)
        return NULL;
    
    Symbol *search_result = lookup_in(p_mod, id);
    
    if(search_result != NULL)
        return search_result;

    if(p_mod == program_module)
        return p_mod;

    return lookup_from(p_mod->back, id);
}

/**
*    Gestione della symbol table gerarchica.
**/

void create_st(Node *root){
    program(root);
    current_module = program_module;
}

Symbol *new_symbol(char *id, Class class, Type type){
    Symbol *p_sym = malloc(sizeof(Symbol));
    p_sym->name = id;
    p_sym->oid = class == C_MOD ? ++mod_count : ++rel_count;
    p_sym->class = class;
    p_sym->type = type;
    p_sym->next = p_sym->back = NULL;
    p_sym->p_sym_table = class == C_MOD ? malloc(sizeof(SymbolTable)) : NULL;
    return p_sym;
}

void insert(Symbol *p_sym){
    int index = hash(p_sym->name);
    Symbol **head = select_bucket(index, current_module->p_sym_table);
    append_to_bucket(head, p_sym);
}

Symbol **select_bucket(int index, SymbolTable *p_sym_table){
    return &(*(p_sym_table))[index];
}

void append_to_bucket(Symbol **head, Symbol *p_sym){
    Symbol **tracer = head;

    while(*tracer)
        tracer = &(*tracer)->next;

    *tracer = p_sym;
}

void link_formal_parameter(Symbol *p_sym_mod, Symbol *p_sym_param){
    (p_sym_mod->formals.num)++;
    append_to_bucket(&(p_sym_mod->formals.descr), memcpy(malloc(sizeof(Symbol)), p_sym_param, sizeof(Symbol)));
}

/**
*    Esplorazione degli scope.
**/

void go_down_in(Symbol *p_inner_mod){
    if(p_inner_mod != current_module && p_inner_mod != NULL){
        keep_outer_scope_of(p_inner_mod);
        current_module = p_inner_mod;
    }
}

void go_up_from(Symbol *p_inner_mod){
    current_module = p_inner_mod->back;
}

void go_up(){
    current_module = current_module->back;
}

void keep_outer_scope_of(Symbol *p_inner_mod){
    p_inner_mod->back = current_module;
}


void steps_from_first_scope(Symbol *p_mod, char *id, int *steps){
    if(lookup_in(p_mod, id) != NULL)
        return;

    (*steps)++;

    if(p_mod == program_module)
        return;

    return steps_from_first_scope(p_mod->back, id, steps);
}

/**
*    Creazione della symbol table gerarchica.
**/

void program(Node *p){
    module_decl(p->child1);
}

void module_decl(Node *p){
    rel_count = 0;

    id_module(p->child1, C_MOD, p->child1->brother->brother->lexval.ival);
    opt_param_list(p->child1->brother);
    opt_var_sect(p->child1->brother->brother->brother);
    opt_const_sect(p->child1->brother->brother->brother->brother);
    opt_module_list(p->child1->brother->brother->brother->brother->brother);
    go_up_from(current_module);
}

void id_module(Node *p, Class class, Type type){
    Symbol *p_sym = new_symbol(p->lexval.sval, class, type);

    if(p_sym->oid != 1){
        insert(p_sym);
    }else
        program_module = p_sym;

    go_down_in(p_sym);
}

void opt_param_list(Node *p){
    for(Node *p1 = p->child1; p1 != NULL; p1 = p1->brother)
        param_decl(p1);
}

void param_decl(Node *p){
    id_param_decl(p->child1, C_PAR, p->child2->lexval.ival);
}

void id_param_decl(Node *p, Class class, Type type){
    Symbol *p_sym = new_symbol(p->lexval.sval, class, type);
    insert(p_sym);
    link_formal_parameter(current_module, p_sym);
}

void opt_var_sect(Node *p){
     for(Node *p1 = p->child1; p1 != NULL; p1 = p1->brother)
        decl(p1, C_VAR);
}

void decl(Node *p, Class class){
    id_list(p->child1, class, p->child2->lexval.ival);
}

void id_decl(Node *p, Class class, Type type){
    Symbol *p_sym = new_symbol(p->lexval.sval, class, type);
    insert(p_sym);
}

void id_list(Node *p, Class class, Type type){
    for(Node *p1 = p->child1; p1 != NULL; p1 = p1->brother)
        id_decl(p1, class, type);
}

void opt_const_sect(Node *p){
    for(Node *p1 = p->child1; p1 != NULL; p1 = p1->brother->brother)
        decl(p1, C_CON);
}

void opt_module_list(Node *p){
    for(Node *p1 = p->child1; p1 != NULL; p1 = p1->brother)
        module_decl(p1);
}
