/********************************************************************************************************************
 Desenvolvido em Novembro de 2023 por:
 Matheus Miquelini Andrello
 Tiago Miranda
**********************************************************************************************************************/

%{
#include "scanner.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

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

declaracao_lista: 
        declaracao_lista declaracao {
                YYTYPE aux = $1;
                while(aux->irmao != NULL){
                aux = aux->irmao;
                }
                aux->irmao = $2;
                $$ = $1;
        } 
        | declaracao { 
                $$ = $1;
        };

declaracao:
        var_declaracao {
                $$ = $1;
        }    
        | fun_declaracao {
                $$ = $1;  
        };

var_declaracao: 
        tipo_especificador IDENTIFICADOR SEMICOLON {
                $$=$1;
                strcpy($$->str,lex->lexema)
        }
        | tipo_especificador IDENTIFICADOR L_BRAC NUMERO R_BRAC SEMICOLON {
                $$=$1;
                strcpy($$->str,lex->lexema)
                $$->tipo_var = Array;
        };

tipo_especificador: INT { 
                $$=cria_decl();
        }
        | VOID {
                $$=cria_decl();
        };

fun_declaracao:
        tipo_especificador IDENTIFICADOR L_PAR params R_PAR composto_decl {
        };

params:
        param_list {
                $$ = $1;
        } 
        | VOID {
                $$=cria_decl();
        };

param_list:
        param_list COMMA param {
        }  
        | param {
        };

param:
        tipo_especificador IDENTIFICADOR  {
                $$ = $1;
                strcpy($$->str,lex->lexema)
        }
        | tipo_especificador IDENTIFICADOR L_BRAC R_BRAC {
        };

composto_decl: L_CHAVES local_declaracoes statement_list R_CHAVES {
                $$=cria_stmt();
        };

local_declaracoes: local_declaracoes var_declaracao {
        }
        | /* vazio */ {
        };

statement_list: statement_list statement {
        }
        | /* vazio */ {
        };

statement:
        expressao_decl {
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

expressao_decl:
        expressao SEMICOLON {
                $$ = $1;
        }
        | SEMICOLON { 
                $$ = NULL;
        };

selecao_decl:
        IF L_PAR expressao R_PAR statement {
                $$=cria_stmt();
                strcpy($$->str,lex->lexema)
                $$->filhos[0] = $3;
                $$->filhos[1] = $5;
        }
        | IF L_PAR expressao R_PAR statement ELSE statement {
                $$=cria_stmt();
                strcpy($$->str,lex->lexema)
                $$->filhos[0] = $3;
                $$->filhos[1] = $5;
                $$->filhos[2] = $7;
        };

iteracao_decl:
        WHILE L_PAR expressao R_PAR statement {
                $$=cria_stmt();
                strcpy($$->str,lex->lexema)
                $$->filhos[0] = $3;
                $$->filhos[1] = $5;
        };

retorno_decl:
        RETURN SEMICOLON {
                $$=cria_stmt();
                strcpy($$->str,lex->lexema)
        }
        | RETURN expressao SEMICOLON {
                $$=cria_stmt();
                strcpy($$->str,lex->lexema)
                $$->filhos[0] = $2;
        };

expressao:
        var ATRIBUICAO expressao {
                $$=cria_exp(Op);
                $$->str=lex->lexema;
                $$->filhos[0]=$1;
                $$->filhos[1]=$3;
        }
        | simples_expressao {
                $$=$1;
        };

var:
        IDENTIFICADOR {
                $$=cria_exp(Id);
                strcpy($$->str,lex->lexema)//strcpy
        }
        | IDENTIFICADOR{
                $$=cria_exp(array);
                strcpy($$->str,lex->lexema)
        } L_BRAC expressao R_BRAC {
                $$=$2;
                $$->filhos[0]=$4;
        };

simples_expressao:
        soma_expressao relacional soma_expressao {
                $$ = $2;
                $$->filhos[0] = $1;
                $$->filhos[1] = $3;
        }
        | soma_expressao {
                $$ = $1;
        };

relacional:
        MENOR {
                $$=cria_exp(Op);
                strcpy($$->str,lex->lexema)
        }
        | MAIOR {
                $$=cria_exp(Op);
                strcpy($$->str,lex->lexema)
        }

        | MENOR_IGUAL {
                $$=cria_exp(Op);
                strcpy($$->str,lex->lexema)
        }

        | DIFERENTE {
                $$=cria_exp(Op);
                strcpy($$->str,lex->lexema)
        }

        | MAIOR_IGUAL {
                $$=cria_exp(Op);
                strcpy($$->str,lex->lexema)
        }

        | IGUAL {
                $$=cria_exp(Op);
                strcpy($$->str,lex->lexema)
        };

soma_expressao:
        soma_expressao soma termo {
                $$ = $2;
                $$->filhos[0] = $1;
                $$->filhos[1] = $3;
        }
        | termo {
                $$=$1;
        };

soma:
        MAIS {
                $$=cria_exp(Op);
                strcpy($$->str,lex->lexema)
        }

        | MENOS {
                $$=cria_exp(Op);
                strcpy($$->str,lex->lexema)
        };

termo:
        termo mult fator {
                $$=$2;
                $$->filhos[0]=$1;
                $$->filhos[1]=$3;
        }
        | fator {
                $$ = $1;
        };

mult:
        MULTIPLICACAO {
                $$=cria_exp(Op);
                strcpy($$->str,lex->lexema)
        }
        | DIVISAO {
                $$=cria_exp(Op);
                strcpy($$->str,lex->lexema)
        };

fator:
        L_PAR expressao R_PAR {
                $$ = $2;
        }
        | var {
                $$ = $1;
        }

        | ativacao {
                $$ = $1;
        }

        | NUMERO {
                $$=cria_exp(Const);
                strcpy($$->str,lex->lexema)
        };

ativacao:
        IDENTIFICADOR{
                $$=cria_exp(Ativ);
                strcpy($$->str,lex->lexema)
        } L_PAR args R_PAR {
                $$=$2;
                $$->filhos[0]=$4;
        };

args:
        arg_list {
                $$ = $1;
        }
        | /* vazio */ {
        $       $ = NULL;
        };

arg_list:
        arg_list COMMA expressao {
        
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
