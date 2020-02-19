/**
*    Semantic analyzer: made by Roberto Poletti.
*
*    Attraversando l'albero astratto del programma sorgente, l'analizzatore semantico verifica che la regola semantica 
*    associata a un certo costrutto sintattico sia soddisfatta nello specifico caso attraverso la computazione degli 
*    attributi semantici. Dire che la regola semantica è soddisfatta significa affermare che un'istanza di un particolare
*    costrutto del linguaggio è di senso compiuto. Esempio: 1 < 2 è di senso compiuto, 1 < 'c' non è semanticamente valida.
*    
*    Il linguaggio Tela, essendo a scope statico, permette all'analizzatore di attuare type inference. Grazie a ciò circa 
*    il 90% delle regole semantiche ricadono nella categoria del controllo dei tipi, il restante 10% sono di natura generale.
**/

#include "checker.h"

extern Symbol *current_module;

Bool program(Node *p){
    return module_decl(p->child1);
}

Bool module_decl(Node *p){
    Node *p_id_module = p->child1;
    Node *p_opt_param_list = p_id_module->brother;
    Node *p_opt_var_sect = p_opt_param_list->brother->brother;
    Node *p_opt_const_sect = p_opt_var_sect->brother;
    Node *p_opt_module_list = p_opt_const_sect->brother;
    Node *p_module_body = p_opt_module_list->brother;
    
    Symbol *new_scope = lookup(get_name(p_id_module));

    go_down_in(new_scope);

    return opt_param_list(p_opt_param_list) && opt_var_sect(p_opt_var_sect) && opt_const_sect(p_opt_const_sect) 
        && opt_module_list(p_opt_module_list) && module_body(p_module_body, get_name(p_id_module));
}

Bool opt_module_list(Node *p){
    for(Node *p1 = p->child1; p1 != NULL; p1 = p1->brother)
        if(!module_decl(p1))
            return FALSE;

    return TRUE;
}

Bool opt_param_list(Node *p){
    for(Node *p1 = p->child1; p1 != NULL; p1 = p1->brother)
        if(!decl(p1, NULL))
            return FALSE;

    return TRUE;
}

Bool opt_var_sect(Node *p){
    for(Node *p1 = p->child1; p1 != NULL; p1 = p1->brother)
        if(!decl(p1, NULL))
            return FALSE;

    return TRUE;
}

Bool opt_const_sect(Node *p){
    Type type;

    for(Node *p1 = p->child1; p1 != NULL; p1 = p1->brother->brother){
        if(!decl(p1, &type) || !ok_expr(p1->brother))
            return FALSE;

        if(!type_equal(type, infer(p1->brother))){
            sem_error_at(get_line(p1), "Constant value is not compatible with the declared type.");
            return FALSE;
        }
    }

    return TRUE;
}

Bool decl(Node *p, Type *type){
    Type decl_type = p->child2->lexval.ival;

    if(type_equal(decl_type, VOID)){
        sem_error_at(get_line(p), "Declarations of void type are not allowed!");
        return FALSE;
    }

    if(type != NULL)
        *type = decl_type;

    return TRUE;
}

Bool module_body(Node *p, char *id){
    Node *p_name1 = p->child1;
    Node *p_stat_list = p_name1->brother;
    Node *p_name2 = p_stat_list->brother;
    
    Bool return_ok = get_type(id) != VOID ? search_for_return_stat(p_stat_list) : TRUE;

    if(!return_ok){
        sem_error_on("Return statement not found for module \"%s\".", id);
        return FALSE;
    }
    
    if(!equal(get_name(p_name1), get_name(p_name2))){
        sem_error_on("Names that delimit the module body of \"%s\" are different.", id);
        return FALSE;
    }

    if(!equal(id, get_name(p_name2))){
        sem_error_on("The module name \"%s\" is different from the names that delimit the body.", id);
        return FALSE;
    }

    if(!stat_list(p_stat_list))
        return FALSE;

    go_up();
    return TRUE;
}

Bool stat_list(Node *p){
    for(Node *p1 = p->child1; p1 != NULL; p1 = p1->brother)
        if(!stat(p1))
            return FALSE;

    return TRUE;
}

Bool stat(Node *p){
    switch (p->name){
        case N_ASSIGN_STAT:
            return assign_stat(p);
        case N_IF_STAT:
            return if_stat(p);
        case N_READ_STAT:
            return read_stat(p);
        case N_WRITE_STAT:
            return write_stat(p);
        case N_WHILE_STAT:
            return while_stat(p);
        case N_RETURN_STAT:
            return return_stat(p);
        case N_MODULE_CALL:
            return module_call(p);
        default:
            return FALSE;
    }
}

Bool logic_expr(Node *p){
    Node *expr1 = p->child1;
    Node *expr2 = p->child2;

    if(!ok_expr(expr1) || !ok_expr(expr2))
        return FALSE;
    
    if(!type_equal(infer(expr1), BOOL) || !type_equal(infer(p->child2), BOOL)){
        sem_error_at(get_line(p), "One or both operands have non-boolean value.");
        return FALSE;
    }

    return TRUE;
}

Bool rel_expr(Node *p){
    Node *expr1 = p->child1;
    Node *expr2 = p->child2;

    if(!ok_expr(expr1) || !ok_expr(expr2))
        return FALSE;

    if(!type_equal(infer(expr1), infer(expr2))){
         sem_error_at(get_line(p), "Operands must have same types.");
         return FALSE;
    }
    
    return TRUE;
}

Bool math_expr(Node *p){
    Node *expr1 = p->child1;
    Node *expr2 = p->child2;

    if(!ok_expr(expr1) || !ok_expr(expr2))
        return FALSE;

    Bool not_int = !type_equal(infer(expr1), INT) || !type_equal(infer(expr2), INT);
    Bool not_real = !type_equal(infer(expr1), REAL) || !type_equal(infer(expr2), REAL);
    
    if(not_int && not_real){
        sem_error_at(get_line(p), "Operands have different types. Check that both are integers or reals.");
        return FALSE;
    }
    
    return TRUE;
}

Bool neg_expr(Node *p){
    return get_qualifier(p) == O_NOT ? not_expr(p) : negate_expr(p);
}

Bool not_expr(Node *p){
    Node * n_expr = p->child1;

    if(!ok_expr(n_expr))
            return FALSE;

    if(!type_equal(infer(n_expr), BOOL)){
        sem_error_at(get_line(p), "Invalid type. Operand must have boolean type.");
        return FALSE;
    }

    return TRUE;
}

Bool negate_expr(Node *p){
    Node *n_expr = p->child1;
    if(!type_equal(infer(n_expr), INT) && !type_equal(infer(n_expr), REAL)){
        sem_error_at(get_line(p), "Invalid type. Operand must have integer or real type.");
        return FALSE;
    }

    return TRUE;
}

Bool module_call(Node *p){
    Node *p_module_id = p->child1;
    char *module_id = get_name(p_module_id);

    if(!id(p_module_id))
        return FALSE;

    if(get_class(module_id) != C_MOD){
        char *msg = "\"%s\" is not a module.";
        sem_error_on_at(get_line(p), msg, module_id);
        return FALSE;
    }

    int num = 0;
    for(Node *p1 = p->child2; p1 != NULL; p1 = p1->brother, ++num);

    if(num != get_module_num(module_id)){
        char *msg = "The number of actual and formal parameters differs for module \"%s\".";
        sem_error_on_at(get_line(p), msg, module_id);
        return FALSE;
    }

    if(num != 0){
        Node *p_actual = p->child2;
        Symbol *p_formal = get_module_descr(module_id);

        for(; p_actual != NULL; p_actual = p_actual->brother, p_formal = p_formal->next){
            if(!actual_parameter(p_actual, p_formal->type))
                return FALSE;
        }
    }

    return TRUE;
}

Bool actual_parameter(Node *p, Type formal_parameter_type){
    if(!ok_expr(p))
        return FALSE;

    if(!type_equal(infer(p), formal_parameter_type)){
        char *msg = "Parameter is incompatible with the formal parameter.";
        sem_error_at(get_line(p), msg);
        return FALSE;
    }

    return TRUE;
}

Bool cond_expr(Node *p){
    Node *expr1 = p->child1;
    Node *expr2 = expr1->brother;
    Node *expr3 = p->child2->child2;
    Node *p_opt_elsif = p->child2;
    
    if(!ok_expr(expr1) || !ok_expr(expr2) || !ok_expr(expr3))
        return FALSE;

    if(!type_equal(infer(expr1), BOOL)){
        sem_error_at(get_line(expr1), "The condition must be a boolean expression.");
        return FALSE;
    }
    
    if(!type_equal(infer(expr2), infer(expr3))){
        sem_error_at(get_line(p), "Expressions must have same type.");
        return FALSE;
    }

    if(!is_null(p_opt_elsif)){
        if(!ok_expr(p_opt_elsif))
            return FALSE;

        if(!type_equal(infer(p_opt_elsif), infer(expr2))){
            sem_error_at(get_line(p_opt_elsif), "Expressions must have same type.");
            return FALSE;
        }
    }

    return TRUE; 
}

Bool opt_elsif_expr_list(Node *p){
    for(Node *p1 = p->child1; p1 != NULL; p1 = p1->brother->brother){
        if(!ok_expr(p1))
            return FALSE;
        
        if(!type_equal(infer(p1), BOOL)){
            sem_error_at(get_line(p1), "The condition must be a boolean expression.");
            return FALSE;
        }
    }

    Node *p1 = p->child1;
    
    do{
        p1 = p1->brother;
        if(!ok_expr(p1))
            return FALSE;

        if(!type_equal(infer(p1), infer(p->child1->brother))){
            sem_error_at(get_line(p1), "Expressions must have same type.");
            return FALSE;
        }

        p1 = p1->brother;
    }while(p1 != NULL);

    return TRUE;
}

Bool cast(Node *p){
    Node *p_cast_expr = p->child1;

    if(!ok_expr(p_cast_expr))
        return FALSE;

    if(!type_equal(infer(p_cast_expr), INT) && !type_equal(infer(p_cast_expr), REAL)){
        sem_error_at(get_line(p), "Expression must be integer or real, according to cast type.");
        return FALSE;
    }

    if(type_equal(infer(p), INT) && !type_equal(infer(p_cast_expr), REAL)){
        sem_error_at(get_line(p), "Expression must be real.");
        return FALSE;
    }
    
    if(type_equal(infer(p), REAL) && !type_equal(infer(p_cast_expr), INT)){
        sem_error_at(get_line(p), "Expression must be integer.");
        return FALSE;
    }
    
    if(!type_equal(infer(p), INT) && !type_equal(infer(p), REAL)){
        sem_error_at(get_line(p), "Only cast from int to real and viceversa are allowed.");
        return FALSE;
    }

    return TRUE;
}

Bool assign_stat(Node *p){
    Node *p_id = p->child1;
    
    if(!id(p_id))
        return FALSE;

    if(get_class(get_name(p_id)) != C_VAR && get_class(get_name(p_id)) != C_PAR){
        char *msg = "\"%s\" must be a declared variable or function parameter.";
        sem_error_on_at(get_line(p_id), msg, get_name(p_id));
        return FALSE;
    }

    if(!ok_expr(p->child2))
        return FALSE;

    if(!type_equal(infer(p_id), infer(p->child2))){
        sem_error_at(get_line(p_id), "Invalid type in assignment.");
        return FALSE;
    }

    return TRUE;
}

Bool if_stat(Node *p){
    Node *p_condition = p->child1;
    Node *p_if_statement = p_condition->brother;

    if(!ok_expr(p_condition))
        return FALSE;
   
    if(!type_equal(infer(p_condition), BOOL))
        sem_error_at(get_line(p_condition), "The condition must be a boolean expression.");

    if(!stat_list(p_if_statement) || !opt_elsif_stat_list(p->child2))
        return FALSE;

    return TRUE;
}

Bool opt_elsif_stat_list(Node *p){
    Node *p_first_condition = p->child1;
    Node *p_else = p->child2;
    
    for(Node *p1 = p_first_condition; p1 != NULL; p1 = p1->brother->brother){
        if(!ok_expr(p1))
            return FALSE;

        if(!type_equal(infer(p1), BOOL)){
            sem_error_at(get_line(p1), "The condition must be a boolean expression.");
            return FALSE;
        }
        
        if(!stat_list(p1->brother))
            return FALSE;
    }

    return is_null(p) || stat_list(p_else);
}

Bool while_stat(Node *p){
    Node *p_condition = p->child1;
    
    if(!ok_expr(p_condition))
        return FALSE;

    if(!type_equal(infer(p_condition), BOOL)){
        sem_error_at(get_line(p_condition), "Loop condition must be a boolean expression.");
        return FALSE;
    }

    return stat_list(p->child2);
}

Bool return_stat(Node *p){
    Node *p_expr = p->child1;
    
    if(!is_null(p)){
        if(!ok_expr(p_expr))
            return FALSE;

        if(!type_equal(get_module_type(), infer(p_expr))){
            sem_error_at(get_line(p_expr), "Invalid return type.");
            return FALSE;
        }
    }else{
        if(!type_equal(get_module_type(), VOID)){
            sem_error_at(get_line(p), "Invalid return type.");
            return FALSE;
        }
    }

    return TRUE;
}

Bool read_stat(Node *p){
    Node *p_id_list = p->child1;
    
    for(Node *p_id = p_id_list->child1; p_id != NULL; p_id = p_id->brother){
        if(!id(p_id))
            return FALSE;
        
        if(get_class(get_name(p_id)) != C_VAR && get_class(get_name(p_id)) != C_PAR){
            char *msg = "\"%s\" must be a declared variable or function parameter.";
            sem_error_on_at(get_line(p_id), msg, get_name(p_id));
            return FALSE;
        }
    }

    return TRUE;
}

Bool write_stat(Node *p){
    Node *p_expr_list = p->child1;

    for(Node *p_expr = p_expr_list->child1; p_expr != NULL; p_expr = p_expr->brother){
        if(!ok_expr(p_expr))
            return FALSE;
    }

    return TRUE;
}

Bool id(Node *p){
    if(!is_visible(get_name(p))){
        char *msg = "\"%s\" is not declared in this scope.";
        sem_error_on_at(get_line(p), msg, get_name(p));
        return FALSE;
    }
    return TRUE;
}

Bool sem_check(Node *root){
    return program(root);
}

Bool search_for_return_stat(Node *p_stat_list){
    Bool return_found = FALSE;
    for(Node *p = p_stat_list->child1; p != NULL; p = p->brother){
        switch(p->name){
            case N_IF_STAT:
                return_found = search_for_return_stat(p->child1->brother) || search_for_return_in_elsif(p->child2);
                break;
            case N_WHILE_STAT:
                return_found = search_for_return_stat(p->child2);
                break;
            case N_RETURN_STAT:
                return TRUE;
            default:
                break;
        }

        if(return_found)
            return TRUE;
    }
    return FALSE;
}

Bool search_for_return_in_elsif(Node *p){
    for(Node *p1 = p->child1; p1 != NULL; p1 = p1->brother->brother)
        if(search_for_return_stat(p1->brother))
            return TRUE;

    return search_for_return_stat(p->child2);
}

Bool ok_expr(Node *p){
    switch(p->name){
        case T_BOOLCONST:
        case T_CHARCONST:
        case T_INTCONST:
        case T_REALCONST:
        case T_STRCONST:
            return TRUE;
        case T_ID:
            if(!id(p))
                return FALSE;
            else if(get_class(get_name(p)) == C_MOD){
                sem_error_on_at(get_line(p), "\"%s\" must be a declared variable or function parameter.", get_name(p));
                return FALSE;
            }
            return TRUE;
        case N_CAST:
            return cast(p);
        case N_COND_EXPR:
            return cond_expr(p);
        case N_MATH_EXPR:
            return math_expr(p);
        case N_NEG_EXPR:
            return neg_expr(p);
        case N_REL_EXPR:
            return rel_expr(p);
        case N_LOGIC_EXPR:
            return logic_expr(p);
        case N_OPT_ELSIF_EXPR_LIST:
            return opt_elsif_expr_list(p);
        case N_MODULE_CALL:
            return module_call(p);
        default:
            return FALSE;
    }
}

Type infer(Node *p){
    switch(p->name){
        case N_CAST:
            return get_qualifier(p);
        case N_REL_EXPR:
            return BOOL;
        case T_INTCONST:
            return INT;
        case T_BOOLCONST:
            return BOOL;
        case T_REALCONST:
            return REAL;
        case T_CHARCONST:
            return CHAR;
        case T_STRCONST:
            return STRING;
        case T_ID: 
            return get_type(get_name(p));
        case N_COND_EXPR:
            return infer(p->child1->brother);
        case N_MATH_EXPR:
            return infer(p->child1);
        case N_NEG_EXPR:
            return (get_qualifier(p) == O_NOT) ? BOOL : infer(p->child1);
        case N_LOGIC_EXPR:
            return BOOL;
        case N_OPT_ELSIF_EXPR_LIST:
            return is_null(p) ? NIL : infer(p->child1->brother);
        case N_MODULE_CALL:
            return get_type(get_name(p->child1));
        default:
            return NIL;
    }
}

Bool type_equal(Type type1, Type type2){
    return type1 == type2;
}

Bool equal(char *name1, char *name2){
    return strcmp(name1, name2) == 0;
}

void sem_error_at(int line, char *msg){
    fprintf(stderr,"\nError at line %d: %s\n", line, msg);
    free(msg);
    exit(-1);
}

void sem_error_on_at(int line, char *msg, char *object){
    char *msg_f = malloc(strlen(msg) + strlen(object) +2);
    sprintf(msg_f, msg, object);
    sem_error_at(line, msg_f);
}

void sem_error_on(char *msg, char *object){
    char *p = malloc(strlen(msg) + 1 + strlen(object) + 1);
    sprintf(p, msg, object);
    printf("Error: %s \n", p);
    free(p);
    exit(-1);
}
