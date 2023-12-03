/********************************************************************************************************************
 Desenvolvido em Novembro de 2023 por:
 Matheus Miquelini Andrello
 Tiago Miranda
**********************************************************************************************************************/

%{
#include "scanner.h"
#include "stdio.h"
#include "stdlib.h"

#define YYSTYPE AST_p

AST_p raiz;

int yylex();
void yyerror(const char *s);

%}

%token  NUMERO IDENTIFICADOR MAIS MAIOR ATRIBUICAO DIVISAO MENOS MULTIPLICACAO
%token  L_PAR R_PAR L_CHAVES R_CHAVES L_BRAC R_BRAC COMMA SEMICOLON
%token  MENOR MAIOR_IGUAL MENOR_IGUAL DIFERENTE IGUAL IF INT ELSE VOID WHILE RETURN


%type programa declaracao_lista declaracao var_declaracao tipo_especificador fun_declaracao params param_list param composto_decl local_declaracoes statement_list statement expressao_decl selecao_decl iteracao_decl retorno_decl expressao var simples_expressao relacional soma_expressao soma termo mult fator ativacao args arg_list

%start programa

%%

programa: declaracao_lista {
    raiz = $1;
};

declaracao_lista: declaracao_lista declaracao {
    $$ = create_node("declaracao_lista", 2, $1, $2);
} 
| declaracao { 
    $$ = create_node("declaracao_lista", 0);
};

declaracao: var_declaracao {
    $$ = $1;
}    
| fun_declaracao {
    $$ = $1;
};

var_declaracao: tipo_especificador IDENTIFICADOR SEMICOLON {
    $$ = create_node("var_declaracao", 2, create_node($1->label, 0, NULL), create_node($2->label, 0, NULL));
}
| tipo_especificador IDENTIFICADOR L_BRAC NUMERO R_BRAC SEMICOLON {
    $$ = create_node("var_declaracao", 3, create_node($1->label, 0, NULL), create_node($2->label, 0, NULL), create_node($4->label, 0, NULL));
};

tipo_especificador: INT {
    $$ = create_node("tipo_especificador", 1, create_node($1->label, 0, NULL));
}
| VOID {
    $$ = create_node("tipo_especificador", 1, create_node($1->label, 0, NULL));
};

fun_declaracao: tipo_especificador IDENTIFICADOR L_PAR params R_PAR composto_decl {
    $$ = create_node("fun_declaracao", 3, create_node($1->label, 0, NULL), create_node($2->label, 0, NULL), $4, $6);
};

params: param_list {
    $$ = create_node("params", 1, $1);
} 
| VOID {
    $$ = create_node("params", 1, create_node($1->label, 0, NULL));
};

param_list: param_list COMMA param {
    $$ = create_node("param_list", 2, $1, $3);
}  
| param {
    $$ = create_node("param_list", 1, $1);
};

param: tipo_especificador IDENTIFICADOR  {
    $$ = create_node("param", 2, create_node($1->label, 0, NULL), create_node($2->label, 0, NULL));
}
| tipo_especificador IDENTIFICADOR L_BRAC R_BRAC {
    $$ = create_node("param", 3, create_node($1->label, 0, NULL), create_node($2->label, 0, NULL));
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

expressao_decl: expressao SEMICOLON {
    $$ = create_node("expressao_decl", 1, $1);
}
| SEMICOLON { 
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

retorno_decl: RETURN SEMICOLON {
    $$ = create_node("retorno_decl", 0);
}
| RETURN expressao SEMICOLON {
    $$ = create_node("retorno_decl", 1, $2);
};

expressao: var ATRIBUICAO expressao {
    $$ = create_node("expressao", 2, $1, $3);
}
| simples_expressao {
    $$ = $1;
};

var: IDENTIFICADOR {
    $$ = create_node("var", 1, create_node($1->label, 0, NULL));
}
| IDENTIFICADOR L_BRAC expressao R_BRAC {
    $$ = create_node("ArrayVar", 2, create_node($1->label, 0, NULL), $3);
};

simples_expressao: soma_expressao relacional soma_expressao {
    $$ = create_node("simples_expressao", 3, $1, $2, $3);
}
| soma_expressao {
    $$ = $1;
};

relacional: MENOR {
    $$ = create_node("relacional", 1, create_node($1->label, 0, NULL));
}
| MAIOR {
    $$ = create_node("relacional", 1, create_node($1->label, 0, NULL));
}

| MENOR_IGUAL {
    $$ = create_node("relacional", 1, create_node($1->label, 0, NULL));
}

| DIFERENTE {
    $$ = create_node("relacional", 1, create_node($1->label, 0, NULL));
}

| MAIOR_IGUAL {
    $$ = create_node("relacional", 1, create_node($1->label, 0, NULL));
}

| IGUAL { //fazer == aqui
    $$ = create_node("relacional", 1, create_node($1->label, 0, NULL));
};

soma_expressao: soma_expressao soma termo {
    $$ = create_node("soma_expressao", 2, $1, $3);
}
| termo {
    $$ = $1;
};

soma: MAIS {
    $$ = create_node("soma", 1, create_node($1->label, 0, NULL));
}

| MENOS {
    $$ = create_node("soma", 1, create_node($1->label, 0, NULL));
};

termo: termo mult fator {
    $$ = create_node("termo", 2, $1, $3);
}
| fator {
    $$ = $1;
};

mult: MULTIPLICACAO {
    $$ = create_node("mult", 0);
}
| DIVISAO {
    $$ = create_node("div", 0);
};

fator: L_PAR expressao R_PAR {
    $$ = $2;
}
| var {
    $$ = $1;
}

| ativacao {
    $$ = $1;
}

| NUMERO {
    $$ = create_node("NUMERO", 1, create_node($1->label, 0, NULL));
};

ativacao: IDENTIFICADOR L_PAR args R_PAR {
    $$ = create_node("ativacao", 2, create_node($1->label, 0, NULL), $3);
};

args: arg_list {
    $$ = create_node("args", 1, $1);
}
| /* vazio */ {
    $$ = create_node("args", 0);
};

arg_list: arg_list COMMA expressao {
    $$ = create_node("arg_list", 2, $1, $3);
}
| expressao {
    $$ = create_node("arg_list", 1, $1);
};

%%

int yylex() {
    return (257+get_token());
}

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
}
