/**
*    Ambiente runtime Tela: made by Roberto Poletti.
*
*    L'interprete Tela crea e gestisce un ambiente runtime in cui si presuppone che un programma Tela venga eseguito 
*    in modo da rispettare i vincoli della semantica del linguaggio. Le problematiche di cui si occupa l'ambiente sono:
*        - Organizzazione della memoria
*        - Meccanismi per l'accesso alle variabili (locali e non)
*        - Collegamenti tra moduli a runtime
*        - Meccanismo di passaggio dei parametri
*
**/

#include "runtime_env.h"
#define MAX_ARGS 10 //numero massimo di argomenti per l'esecuzione di un programma Tela

AstackElement *astack; //puntatore al fondo dell'Activation Stack
OstackElement *ostack; //puntatore al fondo dell'Object Stack

AstackElement *ap; //puntatore alla prossima cella libera dell'Activation Stack
OstackElement *op; //puntatore alla prossima cella libera dell'Object Stack

ProgramUnit *ep; //puntatore alla prima unità di programma della memoria codice

int num_inputs;
char *inputs[MAX_ARGS];

void create_runtime_env(Node *root, int argc, char *argv[]){
    num_inputs = argc;
    memcpy(inputs, argv, sizeof(char *) * 10);
    ap = astack = malloc(sizeof(AstackElement));
    op = ostack = malloc(sizeof(OstackElement));
    current_module = program_module;
    create_program_units(root->child1, 0);
}

Bool first_call(int oid_callee){
    AstackElement *tracer = astack;
    if(oid_callee != 1)
        return FALSE;

    for(; tracer != ap; tracer = tracer->next){
        if(tracer->record.alink == NULL)
            return FALSE;
    }

    return TRUE;
}

/**
*   Gestione della memoria codice.
**/

void create_program_units(Node *root_decl, int nesting_level){
    Symbol *new_scope = lookup(get_name(root_decl->child1));
    Node *opt_module_list = root_decl->child1->brother->brother->brother->brother->brother;
    go_down_in(new_scope);
    append_program_unit(new_program_unit(root_decl, nesting_level));

    for(Node *m_decl = opt_module_list->child1; m_decl != NULL; m_decl = m_decl->brother){
        create_program_units(m_decl, ++nesting_level);
        nesting_level--;
        go_up();
    }
}

ProgramUnit *new_program_unit(Node *entry_point, int nl){
    ProgramUnit *program_unit = malloc(sizeof(ProgramUnit));
    program_unit->entry_point = entry_point;
    program_unit->scope = current_module;
    program_unit->nesting_level = nl;
    return program_unit;
}

void append_program_unit(ProgramUnit *entry_point){
    ProgramUnit **tracer = &ep;
    
    while(*tracer)
        tracer = &(*tracer)->next;
    
    *tracer = entry_point;
}

ProgramUnit *select_program_unit(int oid){
    ProgramUnit *pointer = ep;
    for(int i = 1; i < oid; i++)
        pointer = pointer->next;
    
    return pointer;
}

/**
*   Gestione degli stack.
**/

ActivationRecord *new_act_record(){
    ActivationRecord *act_record = malloc(sizeof(ActivationRecord));
    act_record->objects = op;
    return act_record;
}   

void pop_act_record(){
    ap = peek_act_record();
}

void push_act_record(ActivationRecord new_record){
    ap->record = new_record;
    if(ap->next == NULL)
        ap->next = malloc(sizeof(AstackElement));
    ap = ap->next;
}


AstackElement *peek_act_record(){
    AstackElement *pointer = astack;
    for(; pointer->next != ap; pointer = pointer->next);
    return pointer;
}

ObjectRecord new_obj_record(Type type, Lexval *lexval){
    ObjectRecord *record = malloc(sizeof(ObjectRecord));
    record->type = type;

    if(lexval == NULL){ 
        switch(type){
            case INT:
                record->lexval.ival = 0;
                break;
            case STRING:
                record->lexval.sval = malloc(sizeof(char) * CHUNK);
                break;
            case REAL:
                record->lexval.rval = 0.0;
                break;
            case CHAR:
                record->lexval.cval = '\0';
                break;
            case BOOL:
                record->lexval.bval = FALSE;
                break;
            default:
                break;
        }
    }else
        record->lexval = *lexval;

    return *record;
}

void pop_obj_record(){
    op = (*peek_act_record()).record.objects;
}

void push_obj_record(ObjectRecord new_record){
    op->record = new_record;
    if(op->next == NULL)
        op->next= malloc(sizeof(OstackElement));
    op = op->next;
}

ObjectRecord *search_object(char *obj_name, int oid){
    ActivationRecord *act_record = get_act_record_of_object(obj_name);
    OstackElement *act_objects = act_record->objects;

    if(oid > act_record->numobj){
        fprintf(stdout, "Runtime error: %s is not instantiated yet. \n", obj_name);
        exit(-1);
    }

    for(int i = 1; i < oid; i++)
        act_objects = act_objects->next;
    
    return &(act_objects->record);
}

/**
*   Accesso a variabili locali e non.
**/

ActivationRecord *compute_access_link(int caller_nl, int called_nl){
    if(called_nl == 0) //cioè modulo globale
        return NULL;
    else if(called_nl == caller_nl + 1) //cioè chi sta chiamando è il genitore
        return &(*peek_act_record()).record;
    else if(called_nl == caller_nl) //se è il fratello o sé stessi
        return (*peek_act_record()).record.alink;
    else
        return traverse_static_chain(caller_nl - called_nl + 1);
}

ActivationRecord *get_act_record_of_object(char *obj_name){
    int chaining_steps = 0;
    steps_from_first_scope(current_module, obj_name, &chaining_steps);
    return traverse_static_chain(chaining_steps);
}

ActivationRecord *traverse_static_chain(int num_chaining_steps){
    ActivationRecord *chain_element = &(*peek_act_record()).record;
        
    for(int i = 0; i < num_chaining_steps; i++)
        chain_element = chain_element->alink;
        
    return chain_element;
}

/**
*   Lettura degli argomenti inseriti da CLI.
**/

void read_main_parameters(Node *p, int num){
    int index = 2;

    if(num != num_inputs - 2){
        fprintf(stdout, "Runtime error: number of inputs for main module is not compatible with module signature. \n");
        exit(-1);
    }

    for(Node *param = p->child1; param != NULL; param = param->brother){
        Lexval result = read_cli(infer(param->child1), param->lexval, index);
        push_obj_record(new_obj_record(infer(param->child1), &result));
        index++;
    }
}

Lexval read_cli(Type type, Lexval lexval, int index){
    switch(type){
        case INT:
            lexval.ival = atoi(inputs[index]);
            break;
        case STRING:
            lexval.sval = inputs[index];
            break;
        case REAL:
            lexval.rval = atof(inputs[index]);
            break;
        case BOOL:
            lexval.bval = (inputs[index])[0] == 'f' ? FALSE : TRUE;
            break;
        case CHAR:
            lexval.cval = (inputs[index])[0];
        default:
            break;
    }

    return lexval;
}