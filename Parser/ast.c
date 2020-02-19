#include "ast.h"

char *symnames[] = {
    "PROGRAM",
    "MODULE_DECL",
    "OPT_PARAM_LIST",
    "OPT_VAR_SECT",
    "OPT_CONST_SECT",
    "OPT_MODULE_LIST",
    "MODULE_BODY",
    "PARAM_DECL",
    "DECL",
    "ID_LIST",
    "STAT_LIST",
    "ASSIGN_STAT",
    "IF_STAT",
    "WHILE_STAT",
    "RETURN_STAT",
    "READ_STAT",
    "WRITE_STAT",
    "MODULE_CALL",
    "OPT_ELSIF_STAT_LIST",
    "EXPR_LIST",
    "LOGIC_EXPR",
    "REL_EXPR",
    "MATH_EXPR",
    "NEG_EXPR",
    "COND_EXPR",
    "OPT_ELSIF_EXPR_LIST",
    "CAST",
    "TYPE",
    "ID",
    "CHARCONST",
    "INTCONST",
    "REALCONST",
    "STRCONST",
    "BOOLCONST",
};

char *types [] = {
    "CHAR",
    "INT",
    "REAL",
    "STRING",
    "BOOL",
    "VOID"
};

char *relops[] = {
    "EQ",
    "NEQ",
    "GT",
    "GE",
    "LT",
    "LE"
};

void treeprint(Node *root, int indent){
    int i;
    Node *p;
  
    for(i=0; i<indent; i++){
        printf("    ");
    }
    
    printf("%s", (symnames[root->name]));
    
    if(root->name == T_ID || root->name == T_STRCONST){
        printf(" (%s)", root->lexval.sval);
    }else if(root->name == T_CHARCONST){
        printf(" ('%c')", root->lexval.cval);
    }else if(root->name == T_TYPE){
        printf(" (%s)", types[root->lexval.ival]);
    }else if(root->name == T_INTCONST){
        printf(" (%d)", root->lexval.ival);
    }else if(root->name == T_BOOLCONST){
        printf(" (%s)", (root->lexval.bval == FALSE ? "false" : "true"));
    }else if(root->name == T_REALCONST){
        printf(" (%.3f)", root->lexval.rval);
    }else if(root->name == N_CAST){
        printf(" (%s)", types[root->lexval.ival]);
    }else if(root->name == N_REL_EXPR){
        printf(" (%s)", relops[root->lexval.ival]);
    }
  
    printf("\n");
    
    for(p=root->child1; p != NULL; p = p->brother){
        treeprint(p, indent+1);
    }
    
    for(p=root->child2; p != NULL; p = p->brother){
        treeprint(p, indent+1);
    }
}

char *get_name(Node *p){
    return p->lexval.sval;
}

int get_line(Node *p){
    return p->line;
}

Bool is_null(Node *p){
    switch(p->name){
        case N_OPT_ELSIF_EXPR_LIST:
        case N_RETURN_STAT:
            return p->child1 == NULL;
        case N_OPT_ELSIF_STAT_LIST:
            return p->child2 == NULL;
        default:
            return FALSE;
    }
}

int get_qualifier(Node *p){
    return p->lexval.ival;
}