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
        //cria no stmt
        }
        | VOID {
        //cria no stmt
        };

fun_declaracao: tipo_especificador IDENTIFICADOR L_PAR params R_PAR composto_decl {
        };

params: param_list {
        $$ = $1;
        } 
        | VOID {
        //cria no decl
        };

param_list: param_list COMMA param {
        }  
        | param {
        };

param: tipo_especificador IDENTIFICADOR  {
        $$ = $1;
        $$->label = lex->lexema;
        }
        | tipo_especificador IDENTIFICADOR L_BRAC R_BRAC {
        };

composto_decl: L_CHAVES local_declaracoes statement_list R_CHAVES {
        //cria no stmt
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
        //cria no stmt
        $$->label = lex->lexema;
        $$->filhos[0] = $3;
        $$->filhos[1] = $5;
        }
        | IF L_PAR expressao R_PAR statement ELSE statement {
        //cria no stmt
        $$->label = lex->lexema;
        $$->filhos[0] = $3;
        $$->filhos[1] = $5;
        $$->filhos[2] = $7;
        };

iteracao_decl: WHILE L_PAR expressao R_PAR statement {
        //cria no stmt
        $$->label = lex->lexema;
        $$->filhos[0] = $3;
        $$->filhos[1] = $5;
        };

retorno_decl: RETURN SEMICOLON {
        //cria no stmt
        $$->label = lex->lexema;
        }
        | RETURN expressao SEMICOLON {
        $$->label = lex->lexema;
        $$->filhos[0] = $2;
        };

expressao: var ATRIBUICAO expressao {
        //cria no exp
        $$->label=lex->lexema;
        $$->filhos[0]=$1;
        $$->filhos[1]=$3;
        }
        | simples_expressao {
        $$=$1;
        };

var: IDENTIFICADOR {
        //cria no exp
        $$->label = lex->lexema;
        }
        | IDENTIFICADOR L_BRAC expressao R_BRAC {
        //cria no exp
        };

simples_expressao: soma_expressao relacional soma_expressao {
        $$ = $2;
		$$->filhos[0] = $1;
		$$->filhos[1] = $3;
        }
        | soma_expressao {
        $$ = $1;
        };

relacional: MENOR {
        //cria no exp
        $$->label = lex->lexema;
        }
        | MAIOR {
        //cria no exp
        $$->label = lex->lexema;
        }

        | MENOR_IGUAL {
        //cria no exp
        $$->label = lex->lexema;
        }

        | DIFERENTE {
        //cria no exp
        $$->label = lex->lexema;
        }

        | MAIOR_IGUAL {
        //cria no exp
        $$->label = lex->lexema;
        }

        | IGUAL {
        //cria no exp
        $$->label = lex->lexema;
        };

soma_expressao: soma_expressao soma termo {
        $$ = $2;
	$$->filhos[0] = $1;
	$$->filhos[1] = $3;
        }
        | termo {
        $$=$1;
        };

soma: MAIS {
        //cria no exp
        $$->label = lex->lexema;
        }

        | MENOS {
        //cria no exp
        $$->label = lex->lexema;
        };

termo: termo mult fator {
        $$->label = lex->lexema;
        }
        | fator {
        $$ = $1;
        };

mult: MULTIPLICACAO {
        //cria no exp
        $$->label = lex->lexema;
        }
        | DIVISAO {
        //cria no exp
        $$->label = lex->lexema;
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
        //cria no exp
        $$->label = lex->lexema;
        };

ativacao: IDENTIFICADOR L_PAR args R_PAR {
//cria no exp
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
