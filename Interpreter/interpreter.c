/**
*    Interpreter: made by Roberto Poletti.
*
*    L'AST rispecchia di fatto la struttura del codice sorgente e ne contiene tutte le informazioni rilevanti. Pertanto, anziché interpretare il 
*    file sorgente si può direttamente "interpretare l'AST".
*    L'interprete è incaricato di eseguire le unità di programma, a partire da quella associata al modulo principale, proseguendo
*    con tutte quelle che vengono di fatto richiamate in tale modulo e così via. Attraversando i sotto-alberi associati alle unità di programma
*    esegue quindi tutti i costrutti sintattici contenuti in ogni unità, in accordo alla loro semantica.
*
**/

#define INT_PROTOTYPES
#include "interpreter.h"

void interpret(Node *root, int argc, char *argv[]){
    setbuf(stdout, NULL);
    create_runtime_env(root, argc, argv);
    print(infer(root->child1->child1), module_call(root->child1));
}

/**
*    Attraversamento delle sezioni principali del programma Tela nell'AST
**/

void module_decl(Node *p, Lexval *lexval){
    Node *p_opt_param_list = p->child1->brother;
    Node *p_opt_var_sect = p_opt_param_list->brother->brother;
    Node *p_opt_const_sect = p_opt_var_sect->brother;
    Node *p_module_body = p_opt_const_sect->brother->brother;

    opt_var_sect(p_opt_var_sect);
    opt_const_sect(p_opt_const_sect);
    module_body(p_module_body, lexval);
}

void opt_var_sect(Node *p){
    for(Node *p_decl = p->child1; p_decl != NULL; p_decl = p_decl->brother)
        var_decl(p_decl);
}

void var_decl(Node *p){
    Type type = p->child2->lexval.ival;
    Node *p_id_list = p->child1;
    int num_obj = 0;
    for(Node *p_id = p_id_list->child1; p_id != NULL; p_id = p_id->brother){
        push_obj_record(new_obj_record(type, NULL));
        num_obj++;
    }
    (*peek_act_record()).record.numobj += num_obj;
}

void opt_const_sect(Node *p){
    for(Node *p1 = p->child1; p1 != NULL; p1 = p1->brother->brother){
        Type const_type = p1->child2->lexval.ival;
        Lexval lexval = do_expr(p1->brother);
        const_decl(p1->child1, const_type, lexval);
    }
}

void const_decl(Node *p, Type type, Lexval lexval){
    int num_obj = 0;
    for(Node *p_id = p->child1; p_id != NULL; p_id = p_id->brother){
        push_obj_record(new_obj_record(type, &lexval));
        num_obj++;
    }
    (*peek_act_record()).record.numobj += num_obj;
}

void module_body(Node *p, Lexval *lexval){
    do_stat_list(p->child1->brother, lexval);
}

/**
*    Esecuzione degli statements Tela.
**/

Bool do_stat_list(Node *p, Lexval *lexval){
    for(Node *p1 = p->child1; p1 != NULL; p1 = p1->brother)
        if(!do_stat(p1, lexval))
            return FALSE;
    return TRUE;
}

Bool do_stat(Node *p, Lexval *lexval){
    switch(p->name){
        case N_ASSIGN_STAT:
            do_assign(p);
            return TRUE;
        case N_WRITE_STAT:
            do_write(p);
            return TRUE;
        case N_READ_STAT:
            do_read(p);
            return TRUE;
        case N_MODULE_CALL:
            *lexval = module_call(p);
            return TRUE;
        case N_WHILE_STAT:
            return do_while(p, lexval);
        case N_IF_STAT:
            return do_if(p, lexval);
        case N_RETURN_STAT:
            do_return(p, lexval);
            return FALSE;
        default:
            return FALSE;
    }
}

void do_assign(Node *p){
    Node *p_id1 = p->child1;
    Node *p_id2 = p->child2;

    Symbol *p_id1_elem = lookup(get_name(p_id1));
    ObjectRecord *o_record1 = search_object(get_name(p_id1), p_id1_elem->oid);

    o_record1->lexval = do_expr(p_id2);
}

Bool do_if(Node *p, Lexval *lexval){
    if(do_expr(p->child1).bval == TRUE){
        if(!do_stat_list(p->child1->brother, lexval))
            return FALSE;
    }else
        return do_elsif(p->child2, lexval);
}

Bool do_elsif(Node *p, Lexval *lexval){
    Bool entered = FALSE;
    for(Node *p1 = p->child1; p1 != NULL && !entered; p1 = p1->brother->brother){
        if(do_expr(p1).bval == TRUE){
            if(!do_stat_list(p1->brother, lexval))
                return FALSE;
            entered = TRUE;
        }
    }

    if(!entered && !is_null(p))       
        return do_stat_list(p->child2, lexval);
    return TRUE;
}

Bool do_while(Node *p, Lexval *lexval){
    while(do_expr(p->child1).bval != FALSE){
        if(!do_stat_list(p->child2, lexval))
            return FALSE;
    }

    return TRUE;
}

void do_read(Node *p){
    for(Node *p_id = p->child1->child1; p_id != NULL; p_id = p_id->brother){
        Symbol *p_id_elem = lookup(get_name(p_id));
        
        ObjectRecord *o_record1 = search_object(p_id_elem->name, p_id_elem->oid);
        Type type_id = p_id_elem->type;
        const char *format = formattypes[type_id];

        switch(type_id){
            case INT:
                scanf(format, &(o_record1->lexval.ival));
                break;
            case STRING:
                if(strcmp(fgets((o_record1->lexval).sval, CHUNK, stdin), "\n") == 0){ 
                    printf("\n");
                    fgets((o_record1->lexval).sval, CHUNK, stdin);
                }
                strtok((o_record1->lexval).sval, "\n");
                break;
            case REAL:
                scanf(format, &(o_record1->lexval.rval));
                break;
            case BOOL:
                scanf(format, &(o_record1->lexval.bval));
                break;
            case CHAR:
                scanf(format, &(o_record1->lexval.cval));
                break;
            default:
                break;
        }
    }
}

void do_write(Node *p){
    Buffer *output_buffer = NULL;
    
    for(Node *p_expr = p->child1->child1; p_expr != NULL; p_expr = p_expr->brother){
        insert_in_buffer(&output_buffer, infer(p_expr), do_expr(p_expr));
    }

    for(Buffer *head = output_buffer; head != NULL; head = head->next)
        print(head->type, head->lexval);

    free(output_buffer);
}

Lexval module_call(Node *p){
    Symbol *callee_module_sym = lookup(get_name(p->child1));
    ProgramUnit *callee_module = select_program_unit(callee_module_sym->oid);
    Lexval call_result = p->lexval;

    call_sequence(p, current_module->oid, callee_module_sym->oid, callee_module_sym->formals.num);
    Symbol *caller_scope = current_module;
    current_module = callee_module->scope;
    jump_to_code(callee_module, &call_result);
    
    return_sequence(caller_scope);
    return call_result;
}

void do_return(Node *p, Lexval *lexval){
    if(!is_null(p))
        *lexval = do_expr(p->child1);
}

/**
*    Funzioni accessorie per l'esecuzione degli statements Tela.
**/

void compute_actual_parameters(Node *p){
    for(Node *param = p->child2; param != NULL; param = param->brother){
        Lexval result = do_expr(param);
        push_obj_record(new_obj_record(infer(param), &result));
    }
}

void jump_to_code(ProgramUnit *module, Lexval *call_result){
    module_decl(module->entry_point, call_result);
}

void call_sequence(Node *p, int oid_caller, int oid_callee, int formals_num){
    ActivationRecord *act_record = new_act_record();
    ProgramUnit *callee = select_program_unit(oid_callee);
    ProgramUnit *caller = select_program_unit(oid_caller);

    act_record->alink = compute_access_link(caller->nesting_level, callee->nesting_level);
    first_call(oid_callee) ? read_main_parameters(p->child1->brother, formals_num) 
        : compute_actual_parameters(p);
    act_record->numobj += formals_num;
    push_act_record(*act_record);
}

void return_sequence(Symbol *old_context){
    pop_obj_record();
    pop_act_record();
    current_module = old_context;
}

void insert_in_buffer(Buffer **buffer, Type type, Lexval lexval){   
    Buffer **tracer = buffer;
    
    while(*tracer != NULL){
        tracer = &((*tracer)->next);
    }

    *tracer = malloc(sizeof(Buffer));
    (*tracer)->type = type;
    (*tracer)->lexval = lexval; 
}

void print(Type type, Lexval lexval){
    switch(type){
        case BOOL:
            printf(formattypes[BOOL], lexval.bval == FALSE ? "false" : "true");
            break;
        case INT:
            printf(formattypes[INT], lexval.ival);
            break;
        case STRING:
            printf(formattypes[STRING], lexval.sval != NULL ? lexval.sval : "");
            break;
        case REAL:
            printf(formattypes[REAL], lexval.rval);
            break;
        case CHAR:
            printf(formattypes[CHAR], lexval.sval);
            break;
        default:
            break;
    }
}

/**
*    Valutazione delle espressioni Tela.
**/

Lexval do_expr(Node *p){
    switch(p->name){
        case T_INTCONST:
        case T_BOOLCONST:
        case T_CHARCONST:
        case T_REALCONST:
            return p->lexval;
        case T_STRCONST:
            if(p->lexval.sval == NULL)
                p->lexval.sval = "";
            return p->lexval;
        case T_ID:
           return id_expr(p);
        case N_REL_EXPR:
            return do_rel_expr(p);
        case N_MATH_EXPR:
            return do_math_expr(p);
        case N_CAST:
            return do_cast_expr(p);
        case N_LOGIC_EXPR:
            return do_logic_expr(p);
        case N_NEG_EXPR:   
            return do_neg_expr(p);
        case N_COND_EXPR:
            return do_cond_expr(p);
        case N_MODULE_CALL:
            return module_call(p);
        default:
            break;
    }
}

Lexval do_logic_expr(Node *p){
    return get_qualifier(p) == O_AND ? do_and(p) : do_or(p);
}

Lexval do_rel_expr(Node *p){
    Lexval lexval = p->child1->lexval;

    switch(get_qualifier(p)){
        case O_EQ:
            return do_eq_expr(p);
        case O_NEQ:
            return do_neq_expr(p);
        case O_GT:
            return do_gt_expr(p);
        case O_GE:
            return do_ge_expr(p);
        case O_LT:
            return do_lt_expr(p);
        case O_LE:
            return do_le_expr(p);
    }

    return lexval;
}

Lexval do_math_expr(Node *p){

    switch(get_qualifier(p)){
        case O_PLUS:
            return type_equal(infer(p), INT) ? do_iadd(p) : do_radd(p);
        case O_MINUS:
            return type_equal(infer(p), INT) ? do_isub(p) : do_rsub(p);
        case O_MULT:
            return type_equal(infer(p), INT) ? do_imul(p) : do_rmul(p);
        case O_DIV:
            return type_equal(infer(p), INT) ? do_idiv(p) : do_rdiv(p);
    }

}

Lexval do_neg_expr(Node *p){
    if(get_qualifier(p) == O_NOT)
        return do_lneg(p);
    else
        return type_equal(infer(p->child1), INT) ? 
            do_iumi(p) : do_rumi(p);  
}

Lexval id_expr(Node *p){
    Symbol *id = lookup(get_name(p));
    ObjectRecord *prova = search_object(get_name(p), id->oid);
    return prova->lexval;
}

Lexval do_cast_expr(Node *p){
    Node *expr = p->child1;
    Lexval lexval = do_expr(expr);

    if(type_equal(get_qualifier(p), INT))
        lexval.ival = (int)(lexval.rval);
    else
        lexval.rval = (float)(lexval.ival);

    return lexval;
}

Lexval do_cond_expr(Node *p){
    Node *expr1 = p->child1;
    Node *expr2 = expr1->brother;
    Node *p_opt_elsif = p->child2;

    return do_expr(expr1).bval == TRUE ? 
        do_expr(expr2) : do_opt_elsif_expr_list(p_opt_elsif);
}

Lexval do_opt_elsif_expr_list(Node *p){    
    for(Node *p1 = p->child1; p1 != NULL; p1 = p1->brother->brother)
        if(do_expr(p1).bval == TRUE)
            return do_expr(p1->brother);
     
    return do_expr(p->child2);
}

/**
*   Esecuzione delle operazioni di negazione.
**/

Lexval do_lneg(Node *p){
    Lexval lexval = p->lexval;
    lexval.bval = !do_expr(p->child1).bval;
    return lexval;
}

Lexval do_iumi(Node *p){
    Lexval lexval = p->lexval;
    lexval.ival = - do_expr(p->child1).ival;
    return lexval;
}

Lexval do_rumi(Node *p){
    Lexval lexval = p->lexval;
    lexval.rval = - do_expr(p->child1).rval;
    return lexval;
}

/**
*   Esecuzione delle operazioni aritmetiche.
**/

Lexval do_iadd(Node *p){
    Lexval lexval = do_expr(p->child1);
    lexval.ival += do_expr(p->child2).ival;  
    return lexval;
}

Lexval do_radd(Node *p){
    Lexval lexval = do_expr(p->child1);
    lexval.rval += do_expr(p->child2).rval;  
    return lexval;
}

Lexval do_isub(Node *p){
    Lexval lexval = do_expr(p->child1);
    lexval.ival -= do_expr(p->child2).ival;  
    return lexval;
}

Lexval do_rsub(Node *p){
    Lexval lexval = do_expr(p->child1);
    lexval.rval -= do_expr(p->child2).rval;  
    return lexval;
}

Lexval do_imul(Node *p){
    Lexval lexval = do_expr(p->child1);
    lexval.ival *= do_expr(p->child2).ival;  
    return lexval;
}

Lexval do_rmul(Node *p){
    Lexval lexval = do_expr(p->child1);
    lexval.rval *= do_expr(p->child2).rval;  
    return lexval;
}

Lexval do_idiv(Node *p){
    Lexval lexval = do_expr(p->child1);
    Lexval expr2 = do_expr(p->child2);
    if(expr2.ival == 0){
        fprintf(stdout, "Runtime error at line %d: division by zero. \n", p->line);
        exit(-1);
    }
    lexval.ival /= expr2.ival;  
    return lexval;
}

Lexval do_rdiv(Node *p){
    Lexval lexval = do_expr(p->child1);
    Lexval expr2 = do_expr(p->child2);
    if(expr2.rval == 0){
        fprintf(stdout, "Runtime error at line %d: division by zero. \n", p->line);
        exit(-1);
    }
    lexval.rval /= expr2.rval;  
    return lexval;
}

/**
*   Esecuzione delle operazioni relazionali.
**/

Lexval do_eq_expr(Node *p){
    Node *expr1 = p->child1;
    Node *expr2 = p->child2;
    Lexval lexval = expr1->lexval;

    switch(infer(expr1)){
        case BOOL:
            lexval.bval = do_expr(expr1).bval == do_expr(expr2).bval;
            break;
        case INT:
            lexval.bval = do_expr(expr1).ival == do_expr(expr2).ival;
            break;
        case CHAR:
            lexval.bval = do_expr(expr1).cval == do_expr(expr2).cval;
            break;
        case REAL:
            lexval.bval = do_expr(expr1).rval == do_expr(expr2).rval;
            break;
        case STRING:
            lexval.bval = strcmp(do_expr(expr1).sval, do_expr(expr2).sval) == 0;
            break;
        default:
            break;
    }
    
    return lexval;
}

Lexval do_neq_expr(Node *p){
    Node *expr1 = p->child1;
    Node *expr2 = p->child2;
    Lexval lexval = p->child1->lexval;

    switch(infer(p->child1)){
        case BOOL:
            lexval.bval = do_expr(expr1).bval != do_expr(expr2).bval;
            break;
        case INT:
            lexval.ival = do_expr(expr1).ival != do_expr(expr2).ival;
            break;
        case CHAR:
            lexval.ival = do_expr(expr1).cval != do_expr(expr2).cval;
            break;
        case REAL:
            lexval.ival = do_expr(expr1).rval != do_expr(expr2).rval;
            break;
        case STRING:
            lexval.ival = strcmp(do_expr(expr1).sval, do_expr(expr2).sval) != 0;
            break;
        default:
            break;
    }
    
    return lexval;
}

Lexval do_gt_expr(Node *p){
    Node *expr1 = p->child1;
    Node *expr2 = p->child2;
    Lexval lexval = expr1->lexval;

    switch(infer(expr1)){
        case CHAR:
            lexval.bval = do_expr(expr1).cval > do_expr(expr2).cval;
            break;
        case INT: 
            lexval.bval = do_expr(expr1).ival > do_expr(expr2).ival;
            break;
        case STRING:
            lexval.bval = strcmp(do_expr(expr1).sval, do_expr(expr2).sval) > 0;
            break;
        case REAL:
            lexval.bval = do_expr(expr1).rval > do_expr(expr2).rval;
        default:
            break;
    }

    return lexval;
}

Lexval do_ge_expr(Node *p){
    Node *expr1 = p->child1;
    Node *expr2 = p->child2;
    Lexval lexval = expr1->lexval;

    switch(infer(p->child1)){
        case CHAR:
            lexval.bval = do_expr(expr1).cval >= do_expr(expr2).cval;
            break;
        case INT: 
            lexval.bval = do_expr(expr1).ival >= do_expr(expr2).ival;
            break;
        case STRING:
            lexval.bval = strcmp(do_expr(expr1).sval, do_expr(expr2).sval) >= 0;
            break;
        case REAL:
            lexval.bval = do_expr(expr1).rval >= do_expr(expr2).rval;
            break;
        default:
            break;
    }

    return lexval;
}

Lexval do_lt_expr(Node *p){
    Node *expr1 = p->child1;
    Node *expr2 = p->child2;
    Lexval lexval = expr1->lexval;

    switch(infer(p->child1)){
        case CHAR:
            lexval.bval = do_expr(expr1).cval < do_expr(expr2).cval;
            break;
        case INT: 
            lexval.bval = do_expr(expr1).ival < do_expr(expr2).ival;
            break;
        case STRING:
            lexval.bval = strcmp(do_expr(expr1).sval, do_expr(expr2).sval) < 0;
            break;
        case REAL:
            lexval.bval = do_expr(expr1).rval < do_expr(expr2).rval;
        default:
            break;
    }

    return lexval;
}

Lexval do_le_expr(Node *p){
    Node *expr1 = p->child1;
    Node *expr2 = p->child2;
    Lexval lexval = expr1->lexval;

    switch(infer(p->child1)){
        case CHAR:
            lexval.bval = do_expr(expr1).cval <= do_expr(expr2).cval;
            break;
        case INT: 
            lexval.bval = do_expr(expr1).ival <= do_expr(expr2).ival;
            break;
        case STRING:
            lexval.bval = strcmp(do_expr(expr1).sval, do_expr(expr2).sval) <= 0;
            break;
        case REAL:
            lexval.bval = do_expr(expr1).rval <= do_expr(expr2).rval;
        default:
            break;
    }

    return lexval;
}

/**
*   Esecuzione delle operazioni logiche.
**/

Lexval do_and(Node *p){
    Node *expr1 = p->child1;
    Node *expr2 = p->child2;
    Lexval lexval = expr1->lexval;

    if(do_expr(expr1).bval == FALSE)
        lexval.bval = FALSE;
    else 
        lexval.bval = do_expr(expr2).bval;

    return lexval;
}

Lexval do_or(Node *p){
    Node *expr1 = p->child1;
    Node *expr2 = p->child2;
    Lexval lexval = expr1->lexval;

    if(do_expr(expr1).bval == TRUE)
        lexval.bval = TRUE;
    else
        lexval.bval = do_expr(expr2).bval;
    return lexval;
}