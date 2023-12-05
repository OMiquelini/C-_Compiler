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
        printf("programa\n");
        };

declaracao_lista: 
        declaracao_lista declaracao {
                YYSTYPE aux = $1;
                while(aux->irmaos != NULL){
                aux = aux->irmaos;
                }
                aux->irmaos = $2;
                $$ = $1;
        printf("declaracao_lista\n");

        } 
        | declaracao { 
                $$ = $1;
        printf("declaracao_lista\n");

        };

declaracao:
        var_declaracao {
                $$ = $1;
        printf("declaracao\n");

        }    
        | fun_declaracao {
                $$ = $1;
        printf("declaracao\n");

        };

var_declaracao: 
        tipo_especificador IDENTIFICADOR SEMICOLON {
                $$=$1;
                $$->str=strdup(lex->lexema);
        printf("var_declaracao\n");

        }
        | tipo_especificador IDENTIFICADOR L_BRAC NUMERO R_BRAC SEMICOLON {
                $$=$1;
                //$$->str=strdup(lex->lexema)
                $$->tipo_var = Array;
        printf("var_declaracao\n");

        };

tipo_especificador: INT { 
                $$=cria_decl(Var);
                $$->tipo_var = Int;
        printf("tipo_especificador\n");

        }
        | VOID {
                $$=cria_decl(Var);
                $$->tipo_var = Void;
        printf("tipo_especificador\n");

        };

fun_declaracao:
        tipo_especificador IDENTIFICADOR L_PAR params R_PAR composto_decl {
        printf("fun_declaracao\n");

        };

params:
        param_list {
                $$ = $1;
        printf("params\n");

        } 
        | VOID {
                $$=cria_decl(Param);
        printf("params\n");

        };

param_list:
        param_list COMMA param {

        }  
        | param {
        printf("param_list\n");
                
        };

param:
        tipo_especificador IDENTIFICADOR  {
                $$ = $1;
                $$->str=strdup(lex->lexema);
        printf("param\n");

        }
        | tipo_especificador IDENTIFICADOR L_BRAC R_BRAC {
        printf("param\n");

        };

composto_decl: L_CHAVES local_declaracoes statement_list R_CHAVES {
                $$=cria_stmt(Comp);
                $$->filhos[0]=$2;
                $$->filhos[1]=$3;
        printf("composto_decl\n");

        };

local_declaracoes: local_declaracoes var_declaracao {
        printf("local_declaracoes\n");
        }
        | /* vazio */ {
        printf("local_declaracoes\n");
        };

statement_list: statement_list statement {
        printf("statement_list\n");
        }
        | /* vazio */ {
        printf("statement_list\n");
        };

statement:
        expressao_decl {
                $$ = $1;
        }
        | composto_decl {
        printf("statement\n");
                $$ = $1;
        }
        | selecao_decl {
        printf("statement\n");
                $$ = $1;
        }
        | iteracao_decl {
        printf("statement\n");
                $$ = $1;
        }
        | retorno_decl {
        printf("statement\n");
                $$ = $1;
        };

expressao_decl:
        expressao SEMICOLON {
        printf("expressao_decl\n");
                $$ = $1;
        }
        | SEMICOLON { 
        printf("expressao_decl\n");
                $$ = NULL;
        };

selecao_decl:
        IF L_PAR expressao R_PAR statement {
        printf("selecao_decl\n");
                $$=cria_stmt(If);
                $$->filhos[0] = $3;
                $$->filhos[1] = $5;
        }
        | IF L_PAR expressao R_PAR statement ELSE statement {
        printf("selecao_decl\n");
                $$=cria_stmt(If);
                $$->filhos[0] = $3;
                $$->filhos[1] = $5;
                $$->filhos[2] = $7;
        };

iteracao_decl:
        WHILE L_PAR expressao R_PAR statement {
        printf("iteracao_decl\n");
                $$=cria_stmt(While);
                $$->filhos[0] = $3;
                $$->filhos[1] = $5;
        };

retorno_decl:
        RETURN SEMICOLON {
        printf("retorno_decl\n");
                $$=cria_stmt(Return);
        }
        | RETURN expressao SEMICOLON {
        printf("retorno_decl\n");
                $$=cria_stmt(Return);
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
                $$->str=strdup(lex->lexema)
        }
        | IDENTIFICADOR{
                $$=cria_exp(array);
                $$->str=strdup(lex->lexema)
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
                $$->str=strdup(lex->lexema)
        }
        | MAIOR {
                $$=cria_exp(Op);
                $$->str=strdup(lex->lexema)
        }

        | MENOR_IGUAL {
                $$=cria_exp(Op);
                $$->str=strdup(lex->lexema)
        }

        | DIFERENTE {
                $$=cria_exp(Op);
                $$->str=strdup(lex->lexema)
        }

        | MAIOR_IGUAL {
                $$=cria_exp(Op);
                $$->str=strdup(lex->lexema)
        }

        | IGUAL {
                $$=cria_exp(Op);
                $$->str=strdup(lex->lexema)
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
                $$->str=strdup(lex->lexema)
        }

        | MENOS {
                $$=cria_exp(Op);
                $$->str=strdup(lex->lexema)
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
                $$->str=strdup(lex->lexema)
        }
        | DIVISAO {
                $$=cria_exp(Op);
                $$->str=strdup(lex->lexema)
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
                $$->str=strdup(lex->lexema)
        };

ativacao:
        IDENTIFICADOR{
                $$=cria_exp(Ativ);
                $$->str=strdup(lex->lexema)
        } L_PAR args R_PAR {
                $$=$2;
                $$->filhos[0]=$4;
        };

args:
        arg_list {
                $$ = $1;
        }
        | /* vazio */ {
                $$ = NULL;
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
    fprintf(stderr, "Erro de sintaxe: %s na linha %d\n", s, lex->linha);
}

AST_p parse()
{
        yyparse();
        return raiz;
}
