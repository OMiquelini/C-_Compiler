/********************************************************************************************************************
 Desenvolvido em Novembro de 2023 por:
 Matheus Miquelini Andrello
 Tiago Miranda
**********************************************************************************************************************/

%{
#include "lib.h"
#include "scanner.h"
#include "stdio.h"
#include "stdlib.h"

#define YYSTYPE AST_p

AST_p raiz;

int yylex();
void yyerror(const char *s);

%}

%token NUMERO IDENTIFICADOR MAIS MAIOR ATRIBUICAO DIVISAO MENOS MULTIPLICACAO L_PAR R_PAR L_CHAVES R_CHAVES L_BRAC R_BRAC COMMA SEMICOLON MENOR MAIOR_IGUAL MENOR_IGUAL DIFERENTE IGUAL IF INT ELSE VOID WHILE RETURN

%type <AST_p> programa declaracao_lista declaracao var_declaracao tipo_especificador fun_declaracao params param_list param composto_decl local_declaracoes statement_list statement expressao_decl selecao_decl iteracao_decl retorno_decl expressao var simples_expressao relacional soma_expressao soma termo mult fator ativacao args arg_list

%start programa

%%

programa: declaracao_lista {
    raiz = $1;
};

declaracao_lista: declaracao_lista declaracao {
    
} 
| declaracao { 
    
};

declaracao: var_declaracao {
    
}    
| fun_declaracao {
    
};

var_declaracao: tipo_especificador IDENTIFICADOR SEMICOLON {
    
}
| tipo_especificador IDENTIFICADOR L_BRAC NUMERO R_BRAC SEMICOLON {
};

tipo_especificador: INT {
}
| VOID {
};

fun_declaracao: tipo_especificador IDENTIFICADOR L_PAR params R_PAR composto_decl {
};

params: param_list {
} 
| VOID {
};

param_list: param_list COMMA param {
}  
| param {
};

param: tipo_especificador IDENTIFICADOR  {
}
| tipo_especificador IDENTIFICADOR L_BRAC R_BRAC {
};

composto_decl: L_CHAVES local_declaracoes statement_list R_CHAVES {
};

local_declaracoes: local_declaracoes var_declaracao {
}
| /* vazio */ {
};

statement_list: statement_list statement {
}
| /* vazio */ {
};

statement: expressao_decl {
}
| composto_decl {
}

| selecao_decl {
}

| iteracao_decl {
}

| retorno_decl {
};

expressao_decl: expressao SEMICOLON {
}
| SEMICOLON { 
};

selecao_decl: IF L_PAR expressao R_PAR statement {
}
| IF L_PAR expressao R_PAR statement ELSE statement {
};

iteracao_decl: WHILE L_PAR expressao R_PAR statement {
};

retorno_decl: RETURN SEMICOLON {
}
| RETURN expressao SEMICOLON {
};

expressao: var ATRIBUICAO expressao {
}
| simples_expressao {
};

var: IDENTIFICADOR {
}
| IDENTIFICADOR L_BRAC expressao R_BRAC {
};

simples_expressao: soma_expressao relacional soma_expressao {
}
| soma_expressao {
};

relacional: MENOR {
}
| MAIOR {
}

| MENOR_IGUAL {
}

| DIFERENTE {
}

| MAIOR_IGUAL {
}

| IGUAL { //fazer == aqui
};

soma_expressao: soma_expressao soma termo {
}
| termo {
};

soma: MAIS {
}

| MENOS {
};

termo: termo mult fator {
}
| fator {
};

mult: MULTIPLICACAO {
}
| DIVISAO {
};

fator: L_PAR expressao R_PAR {
}
| var {
}

| ativacao {
}

| NUMERO {
};

ativacao: IDENTIFICADOR L_PAR args R_PAR {
};

args: arg_list {
}
| /* vazio */ {
};

arg_list: arg_list COMMA expressao {
}
| expressao {
};

%%

int yylex() {
    return (get_token());
}

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
}
