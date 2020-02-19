/**
*    Made by Roberto Poletti
*
*    Prototipi necessari per la realizzazione di un analizzatore semantico.
*
**/

#include "symbol_table.h"
#include <string.h>
#include <stdlib.h>

/**
*   Prototipi per l'attraversamento dell'AST in fase di analisi
*   semantica.
**/

Bool program(Node *);
Bool module_decl(Node *);
Bool opt_var_sect(Node *);
Bool opt_module_list(Node *);
Bool opt_const_sect(Node *);
Bool module_body(Node *, char *);
Bool stat_list(Node *);
Bool stat(Node *);
Bool logic_expr(Node *);
Bool rel_expr(Node *);
Bool math_expr(Node *);
Bool neg_expr(Node *);
Bool not_expr(Node *);
Bool negate_expr(Node *);
Bool module_call(Node *);
Bool actual_parameter(Node *, Type);
Bool cond_expr(Node *);
Bool opt_elsif_expr_list(Node *);
Bool cast(Node *);
Bool assign_stat(Node *);
Bool if_stat(Node *);
Bool opt_elsif_stat_list(Node *);
Bool while_stat(Node *);
Bool return_stat(Node *);
Bool read_stat(Node *);
Bool write_stat(Node *);
Bool id(Node *);
Bool decl(Node *, Type *);
Bool opt_param_list(Node *);

/**
*   Prototipi per l'analisi semantica.
**/

Bool sem_check(Node *);
Bool search_for_return_stat(Node *);
Bool search_for_return_in_elsif(Node *);
Bool ok_expr(Node *);
Type infer(Node *);
Bool type_equal(Type, Type);
Bool equal(char *, char *);

/**
*  Prototipi per la generazione di errori semantici.
**/

void sem_error_at(int, char *);
void sem_error_on_at(int, char *, char *);
void sem_error_on(char *, char *);
