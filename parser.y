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

%start programa

%%

programa: declaracao_lista {
    raiz = $1;
};

declaracao_lista: declaracao_lista declaracao {
    
} 
| declaracao { 
        $$ = $1;
};

declaracao: var_declaracao {
        $$ = $1;
}    
| fun_declaracao {
        $$ = $1;  
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
        $$ = $1;
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
        $$ = $1;
}
| SEMICOLON { 
        $$ = NULL;
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
        $$ = $1;
}
| /* vazio */ {
        $$ = NULL;
};

arg_list: arg_list COMMA expressao {
}
| expressao {
        $$ = $1;
};

%%

int yylex() {
    return (get_token());
}

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
}
