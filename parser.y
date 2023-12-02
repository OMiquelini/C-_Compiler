%{
#include "scanner.h"
%}

%union {
    p_no token_info;
}

%token NUMERO IDENTIFICADOR MAIS MAIOR ATRIBUICAO DIVISAO MENOS MULTIPLICACAO
%token L_PAR R_PAR L_CHAVES R_CHAVES L_BRAC R_BRAC VIRGULA COMMA
%token MENOR MAIOR_IGUAL MENOR_IGUAL DIFERENTE IF INT ELSE VOID WHILE RETURN

%start programa

%%

programa: declaracao_lista ;

declaracao_lista: declaracao_lista declaracao | declaracao;

declaracao: var_declaracao | fun_declaracao;

var_declaracao: tipo_especificador IDENTIFICADOR COMMA | tipo_especificador IDENTIFICADOR L_BRAC NUMERO R_BRAC COMMA;

tipo_especificador: INT | VOID;

fun_declaracao: tipo_especificador IDENTIFICADOR L_PAR params R_PAR composto_decl;

params: param_list | VOID;

param_list: param_list COMMA param | param;

param: tipo_especificador IDENTIFICADOR COMMA | tipo_especificador IDENTIFICADOR L_BRAC R_BRAC COMMA;

composto_decl: L_CHAVES local_declaracoes statement_list R_CHAVES;

local_declaracoes: local_declaracoes var_declaracao | /* vazio */;

statement_list: statement_list statement | /* vazio */;

statement: expressao_decl | composto_decl | selecao_decl | iteracao_decl | retorno_decl;

expressao_decl: expressao COMMA | COMMA;

selecao_decl: IF L_PAR expressao R_PAR statement | IF L_PAR expressao R_PAR statement ELSE statement;

iteracao_decl: WHILE L_PAR expressao R_PAR statement;

retorno_decl: RETURN COMMA | RETURN expressao COMMA;

expressao: var ATRIBUICAO expressao COMMA | simples_expressao;

var: IDENTIFICADOR COMMA | IDENTIFICADOR L_BRAC expressao R_BRAC COMMA;

simples_expressao: soma_expressao relacional soma_expressao | soma_expressao;

relacional: MENOR | MAIOR | MENOR_IGUAL | DIFERENTE | MAIOR_IGUAL | COMMA ;

soma_expressao: soma_expressao MAIS termo COMMA | termo COMMA ;

soma: MAIS | MENOS ;

termo: termo MULTIPLICACAO fator COMMA | fator COMMA ;

mult: MULTIPLICACAO | DIVISAO ;

fator: L_PAR expressao R_PAR COMMA | var COMMA | ativacao COMMA | NUMERO COMMA ;

ativacao: IDENTIFICADOR L_PAR args R_PAR COMMA ;

args: arg_list | /* vazio */ ;

arg_list: arg_list COMMA expressao COMMA | expressao COMMA ;

%%

int main() {
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
}
