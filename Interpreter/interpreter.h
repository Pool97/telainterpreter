/**
*   Made by Roberto Poletti
* 
*   Header file contenente le definizioni e i prototipi per l'esecuzione delle istruzioni Tela.
*
**/

#include "runtime_env.h"
extern Bool type_equal(Type, Type);
extern Symbol *current_module;

/**
*    Linked list contenente i parametri attuali letti da input per il modulo principale.
**/

typedef struct buffer{
    Type type;
    Lexval lexval;
    struct buffer *next;
}Buffer;

/**
*   Avvia l'esecuzione del codice.
**/

void interpret(Node * root, int, char *[]);

#ifdef INT_PROTOTYPES

/**
*    Prototipo per l'attraversamento delle sezioni principali del programma Tela nell'AST.
**/

static void module_decl(Node *, Lexval *);
static void opt_var_sect(Node *);
static void opt_const_sect(Node *);
static void var_decl(Node *);
static void const_decl(Node *, Type, Lexval);
static void module_body(Node *, Lexval *);

/**
*   Prototipi per l'esecuzione di statements.
**/

Bool do_stat_list(Node *, Lexval *);
Bool do_stat(Node *, Lexval *);
void do_assign(Node *);
Bool do_if(Node *, Lexval *);
Bool do_elsif(Node *, Lexval *);
Bool do_while(Node *, Lexval *);
void do_read(Node *);
void do_write(Node *);
static Lexval module_call(Node *);
void do_return(Node *, Lexval *);

/**
*   Prototipi accessori all'esecuzione degli statements.
**/

void compute_actual_parameters(Node *);
void jump_to_code(ProgramUnit *, Lexval *);
void call_sequence(Node *, int, int, int);
void return_sequence(Symbol *);
void insert_in_buffer(Buffer **, Type, Lexval);
void print(Type, Lexval);

/**
*   Prototipi per la valutazione di espressioni.
**/

Lexval do_expr(Node *);
Lexval do_logic_expr(Node *);
Lexval do_rel_expr(Node *);
Lexval do_math_expr(Node *);
Lexval do_neg_expr(Node *);
Lexval id_expr(Node *);
Lexval do_cast_expr(Node *);
Lexval do_cond_expr(Node *);
Lexval do_opt_elsif_expr_list(Node *);

/**
*   Prototipi per l'esecuzione di operazioni di negazione.
**/

Lexval do_lneg(Node *);
Lexval do_iumi(Node *);
Lexval do_rumi(Node *);

/**
*   Prototipi per l'esecuzione di operazioni aritmetiche.
**/

Lexval do_iadd(Node *);
Lexval do_radd(Node *);
Lexval do_isub(Node *);
Lexval do_rsub(Node *);
Lexval do_imul(Node *);
Lexval do_rmul(Node *);
Lexval do_idiv(Node *);
Lexval do_rdiv(Node *);

/**
*   Prototipi per l'esecuzione di operazioni relazionali.
**/

Lexval do_eq_expr(Node *);
Lexval do_neq_expr(Node *);
Lexval do_gt_expr(Node *);
Lexval do_ge_expr(Node *);
Lexval do_lt_expr(Node *);
Lexval do_le_expr(Node *);

/**
*   Prototipi per l'esecuzione di operazioni logiche.
**/

Lexval do_and(Node *);
Lexval do_or(Node *);

/**
*    Specificatori di formato previsti dal linguaggio Tela per la stampa a schermo di 
*    variabili, costanti e parametri.
**/

char *formattypes[] = {
    "%c",
    "%d",
    "%f",
    "%s",
    "%s"
};

#endif