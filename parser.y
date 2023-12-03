%{
#include "scanner.h"
#include "lib.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct TreeNode {
    char* label;
    struct TreeNode** children;
    int n_children;
} TreeNode;

TreeNode* create_node(char* label, int n_children, ...) {
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->label = label;
    node->n_children = n_children;
    node->children = (TreeNode**) malloc(n_children * sizeof(TreeNode*));

    va_list args;
    va_start(args, n_children);
    for (int i = 0; i < n_children; i++) {
        node->children[i] = va_arg(args, TreeNode*);
    }
    va_end(args);

    return node;
}

void printTree(TreeNode* node, int level) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("%s\n", node->label);

    for (int i = 0; i < node->n_children; i++) {
        printTree(node->children[i], level + 1);
    }
}

void freeTree(TreeNode* node) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < node->n_children; i++) {
        freeTree(node->children[i]);
    }

    free(node->children);
    free(node);
}


%}

%union {
    char* str;
    TreeNode* node;
    p_no token_info;
}

%token NUMERO IDENTIFICADOR MAIS MAIOR ATRIBUICAO DIVISAO MENOS MULTIPLICACAO
%token L_PAR R_PAR L_CHAVES R_CHAVES L_BRAC R_BRAC VIRGULA COMMA
%token MENOR MAIOR_IGUAL MENOR_IGUAL DIFERENTE IF INT ELSE VOID WHILE RETURN

%type <node> programa declaracao_lista declaracao var_declaracao tipo_especificador fun_declaracao params param_list param composto_decl local_declaracoes statement_list statement expressao_decl selecao_decl iteracao_decl retorno_decl expressao var simples_expressao relacional soma_expressao soma termo mult fator ativacao args arg_list

%start programa

%%

programa: declaracao_lista {
    $$ = create_node("programa", 1, $1);
    printTree($$, 0);
    freeTree($$);
};

declaracao_lista: declaracao_lista declaracao {
    $$ = create_node("declaracao_lista", 2, $1, $2);
} 
| /* vazio */ {
    $$ = create_node("declaracao_lista", 0);
};

declaracao: var_declaracao {
    $$ = $1;
}    
| fun_declaracao {
    $$ = $1;
};

var_declaracao: tipo_especificador IDENTIFICADOR COMMA {
    $$ = create_node("var_declaracao", 2, create_node($1, NULL, NULL), create_node($2, NULL, NULL));
}
| tipo_especificador IDENTIFICADOR L_BRAC NUMERO R_BRAC COMMA {
    $$ = create_node("var_declaracao", 3, create_node($1, NULL, NULL), create_node($2, NULL, NULL), create_node($4, NULL, NULL));
};

tipo_especificador: INT {
    $$ = create_node("tipo_especificador", 1, create_node($1, NULL, NULL));
}
| VOID {
    $$ = create_node("tipo_especificador", 1, create_node($1, NULL, NULL));
};

fun_declaracao: tipo_especificador IDENTIFICADOR L_PAR params R_PAR composto_decl {
    $$ = create_node("fun_declaracao", 3, create_node($1, NULL, NULL), create_node($2, NULL, NULL), $4, $6);
};

params: param_list {
    $$ = create_node("params", 1, $1);
} 
| VOID {
    $$ = create_node("params", 1, create_node($1, NULL, NULL));
};

param_list: param_list COMMA param {
    $$ = create_node("param_list", 2, $1, $3);
}  
| param {
    $$ = create_node("param_list", 1, $1);
};

param: tipo_especificador IDENTIFICADOR COMMA  {
    $$ = create_node("param", 2, create_node($1, NULL, NULL), create_node($2, NULL, NULL));
}
| tipo_especificador IDENTIFICADOR L_BRAC R_BRAC COMMA {
    $$ = create_node("param", 3, create_node($1, NULL, NULL), create_node($2, NULL, NULL));
};

composto_decl: L_CHAVES local_declaracoes statement_list R_CHAVES {
    $$ = create_node("composto_decl", 2, $2, $3);
};

local_declaracoes: local_declaracoes var_declaracao {
    $$ = create_node("local_declaracoes", 2, $1, $2);
}
| /* vazio */ {
    $$ = create_node("local_declaracoes", 0);
};

statement_list: statement_list statement {
    $$ = create_node("statement_list", 2, $1, $2);
}
| /* vazio */ {
    $$ = create_node("statement_list", 0);
};

statement: expressao_decl {
    $$ = $1;
}
| composto_decl {
    $$ = $1;
}

| selecao_decl {
    $$ = $1;
}

| iteracao_decl {
    $$ = $1;
}

| retorno_decl {
    $$ = $1;
};

expressao_decl: expressao COMMA {
    $$ = create_node("expressao_decl", 1, $1);
}
| COMMA {
    $$ = create_node("expressao_decl", 0);
};

selecao_decl: IF L_PAR expressao R_PAR statement {
    $$ = create_node("selecao_decl", 2, $3, $5);
}
| IF L_PAR expressao R_PAR statement ELSE statement {
    $$ = create_node("selecao_decl", 3, $3, $5, $7);
};

iteracao_decl: WHILE L_PAR expressao R_PAR statement {
    $$ = create_node("iteracao_decl", 2, $3, $5);
};

retorno_decl: RETURN COMMA {
    $$ = create_node("retorno_decl", 0);
    printTree($$, 0);
    freeTree($$);
}
| RETURN expressao COMMA {
    $$ = create_node("retorno_decl", 1, $2);
    printTree($$, 0);
    freeTree($$);
};

expressao: var ATRIBUICAO expressao COMMA {
    $$ = create_node("expressao", 2, $1, $3);
    printTree($$, 0);
    freeTree($$);
}
| simples_expressao {
    $$ = $1;
};

var: IDENTIFICADOR COMMA {
    $$ = create_node("var", 1, create_node($1, NULL, NULL));
    printTree($$, 0);
    freeTree($$);
}
| IDENTIFICADOR L_BRAC expressao R_BRAC COMMA {
    $$ = create_node("ArrayVar", 2, create_node($1, NULL, NULL), $3);
    printTree($$, 0);
    freeTree($$);
};

simples_expressao: soma_expressao relacional soma_expressao {
    $$ = create_node("simples_expressao", 3, $1, $2, $3);
    printTree($$, 0);
    freeTree($$);
}
| soma_expressao {
    $$ = $1;
};

relacional: MENOR {
    $$ = create_node("relacional", 1, create_node($1, NULL, NULL));
}
| MAIOR {
    $$ = create_node("relacional", 1, create_node($1, NULL, NULL));
}

| MENOR_IGUAL {
    $$ = create_node("relacional", 1, create_node($1, NULL, NULL));
}

| DIFERENTE {
    $$ = create_node("relacional", 1, create_node($1, NULL, NULL));
}

| MAIOR_IGUAL {
    $$ = create_node("relacional", 1, create_node($1, NULL, NULL));
}

| COMMA {
    $$ = create_node("relacional", 0);
};

soma_expressao: soma_expressao MAIS termo COMMA {
    $$ = create_node("soma_expressao", 2, $1, $3);
    printTree($$, 0);
    freeTree($$);
}
| termo COMMA {
    $$ = $1;
};

soma: MAIS {
    $$ = create_node("soma", 1, create_node($1, NULL, NULL));
}

| MENOS {
    $$ = create_node("soma", 1, create_node($1, NULL, NULL));
};

termo: termo MULTIPLICACAO fator COMMA {
    $$ = create_node("termo", 2, $1, $3);
    printTree($$, 0);
    freeTree($$);
}
| fator COMMA {
    $$ = $1;
};

mult: MULTIPLICACAO {
    $$ = create_node("mult", 0);
}
| DIVISAO {
    $$ = create_node("div", 0);
};

fator: L_PAR expressao R_PAR COMMA {
    $$ = $2;
}
| var COMMA {
    $$ = $1;
}

| ativacao COMMA {
    $$ = $1;
}

| NUMERO COMMA {
    $$ = create_node("NUMERO", 1, create_node($1, NULL, NULL));
    printTree($$, 0);
    freeTree($$);
};

ativacao: IDENTIFICADOR L_PAR args R_PAR COMMA {
    $$ = create_node("ativacao", 2, create_node($1, NULL, NULL), $3);
    printTree($$, 0);
    freeTree($$);
};

args: arg_list {
    $$ = create_node("args", 1, $1);
}
| /* vazio */ {
    $$ = create_node("args", 0);
};

arg_list: arg_list COMMA expressao COMMA {
    $$ = create_node("arg_list", 2, $1, $3);
    printTree($$, 0);
    freeTree($$);
}
| expressao COMMA {
    $$ = create_node("arg_list", 1, $1);
    printTree($$, 0);
    freeTree($$);
};

%%

int main() {
    yyparse();
    return 0;
}

void yylex() {
    yylval.token_info = get_token();
}

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
}
