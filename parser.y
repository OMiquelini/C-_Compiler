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
char *str_aux;
void yyerror(const char *s);

%}

%token NUMERO IDENTIFICADOR MAIS MAIOR ATRIBUICAO DIVISAO MENOS MULTIPLICACAO L_PAR R_PAR L_CHAVES R_CHAVES L_BRAC R_BRAC COMMA SEMICOLON MENOR MAIOR_IGUAL MENOR_IGUAL DIFERENTE IGUAL IF INT ELSE VOID WHILE RETURN

%start programa

%%

programa: declaracao_lista {
        //printf("programa\n");
        raiz = $1;
};

declaracao_lista: 
        declaracao_lista declaracao {
                //printf("declaracao_lista\n");
                YYSTYPE aux = $1;
                while(aux->irmaos != NULL){
                aux = aux->irmaos;
                }
                aux->irmaos = $2;
                $$ = $1;
                }
        | declaracao { 
                //printf("declaracao_lista\n");
                $$ = $1;
        };

declaracao:
        var_declaracao {
                //printf("declaracao\n");
                $$ = $1;
        }    
        | fun_declaracao {
                //printf("declaracao\n");
                $$ = $1;
        };

id : IDENTIFICADOR {
        str_aux = strdup(lex->lexema);
        };

var_declaracao: 
        tipo_especificador id SEMICOLON {
                //printf("var_declaracao\n");
                $$=$1;
                $$->str=str_aux;//nok
                $$->tipo_var = Var;
        }
        | tipo_especificador id L_BRAC NUMERO R_BRAC SEMICOLON {
                //printf("var_declaracao\n");
                $$=$1;
                $$->str=str_aux;//nok
                $$->tipo_var = Array;
        };

tipo_especificador: INT {
                //printf("tipo_especificador\n"); 
                $$=cria_decl(Var);
                $$->tipo_var = Int;
        }
        | VOID {
                //printf("tipo_especificador\n"); 
                $$=cria_decl(Var);
                $$->tipo_var = Void;
        };

fun_declaracao:
        tipo_especificador id 
        {
                //printf("fun_declaracao\n"); 
                $$ = $1;
                $$->str=str_aux;//nok
                $$->tipo_decl = Func;
        }
        L_PAR params R_PAR composto_decl {
                //printf("fun_declaracao\n"); 
                $$ = $3;
                $$->filhos[0] = $5;
                $$->filhos[1] = $7;
                $$->n_filhos = 2;
        };

params:
        param_list {
                //printf("params\n"); 
                $$ = $1;

        } 
        | VOID {
                //printf("params\n");
                $$=cria_decl(Param);
                $$->tipo_var = Void;
        };

param_list:
        param_list COMMA param {
                //printf("param_list\n");
                YYSTYPE aux = $1;
                while(aux->irmaos != NULL){
                aux = aux->irmaos;
                }
                aux->irmaos = $2;
                $$ = $1;
        }  
        | param {
                //printf("param_list\n");
                $$ = $1;     
        };

param:
        tipo_especificador id  {
                //printf("param\n");
                $$ = $1;
                $$->str=str_aux;

        }
        | tipo_especificador id L_BRAC R_BRAC {
                //printf("param\n");
                $$ = $1;
                $$->tipo_decl = Param;
                $$->tipo_var = Array;
                $$->str=str_aux;//nok
        };

composto_decl: L_CHAVES local_declaracoes statement_list R_CHAVES {
                //printf("composto_decl\n");
                $$=cria_stmt(Comp);
                $$->filhos[0]=$2;
                $$->filhos[1]=$3;
                $$->n_filhos = 2;

        };

local_declaracoes: local_declaracoes var_declaracao {
                //printf("local_declaracoes\n");
                YYSTYPE aux = $1;
                if(aux == NULL)
                {
                        $$ = $2;
                }
                else
                {
                        while(aux->irmaos != NULL){
                        aux = aux->irmaos;
                        }
                        aux->irmaos = $2;
                        $$ = $1;
                }
        }
        | /* vazio */ {
                //printf("local_declaracoes\n");
                $$ = NULL;
        };

statement_list: statement_list statement {
                //printf("statement_list\n");
                YYSTYPE aux = $1;
                if(aux == NULL)
                {
                        $$ = $2;
                }
                else
                {
                        while(aux->irmaos != NULL){
                        aux = aux->irmaos;
                        }
                        aux->irmaos = $2;
                        $$ = $1;
                }
        }
        | /* vazio */ {
                //printf("statement_list\n");
                $$ = NULL;
        };

statement:
        expressao_decl {
                //printf("statement\n");
                $$ = $1;
        }
        | composto_decl {
                //printf("statement\n");
                $$ = $1;
        }
        | selecao_decl {
                //printf("statement\n");
                $$ = $1;
        }
        | iteracao_decl {
                //printf("statement\n");
                $$ = $1;
        }
        | retorno_decl {
                //printf("statement\n");
                $$ = $1;
        };

expressao_decl:
        expressao SEMICOLON {
                //printf("expressao_decl\n");
                $$ = $1;
        }
        | SEMICOLON { 
                //printf("expressao_decl\n");
                $$ = NULL;
        };

selecao_decl:
        IF L_PAR expressao R_PAR statement {
                //printf("selecao_decl\n");
                $$=cria_stmt(If);
                $$->filhos[0] = $3;
                $$->filhos[1] = $5;
                $$->n_filhos = 2;
        }
        | IF L_PAR expressao R_PAR statement ELSE statement {
                //printf("selecao_decl\n");
                $$=cria_stmt(If);
                $$->filhos[0] = $3;
                $$->filhos[1] = $5;
                $$->filhos[2] = $7;
                $$->n_filhos = 3;
        };

iteracao_decl:
        WHILE L_PAR expressao R_PAR statement {
                //printf("iteracao_decl\n");
                $$=cria_stmt(While);
                $$->filhos[0] = $3;
                $$->filhos[1] = $5;
                $$->n_filhos = 2;
        };

retorno_decl:
        RETURN SEMICOLON {
                //printf("retorno_decl\n");
                $$=cria_stmt(Return);
        }
        | RETURN expressao SEMICOLON {
                //printf("retorno_decl\n");
                $$=cria_stmt(Return);
                $$->filhos[0] = $2;
                $$->n_filhos = 1;
        };

expressao:
        var ATRIBUICAO expressao {
                //printf("expressao\n");
                $$=cria_exp(Op);
                $$->str=strdup(lex->lexema);//nok
                $$->filhos[0]=$1;
                $$->filhos[1]=$3;
                $$->n_filhos=2;
        }
        | simples_expressao {
                //printf("expressao\n");
                $$=$1;
        };

var:
        id {
                //printf("var\n");
                $$=cria_exp(Id);
                $$->str=str_aux;//nok
        }
        | id{
                //printf("var\n");
                $$=cria_exp(array);
                $$->str=str_aux;//nok
        } L_BRAC expressao R_BRAC {
                //printf("var\n");
                $$=$2;
                $$->filhos[0]=$4;
                $$->n_filhos = 1;
        };

simples_expressao:
        soma_expressao relacional soma_expressao {
                //printf("simples_expressao\n");
                $$ = $2;
                $$->filhos[0] = $1;
                $$->filhos[1] = $3;
                $$->n_filhos = 2;
        }
        | soma_expressao {
                //printf("simples_expressao\n");
                $$ = $1;
        };

relacional:
        MENOR {
                //printf("relacao\n");
                $$=cria_exp(Op);
                $$->str="<";//ok
        }
        | MAIOR {
                //printf("relacao\n");
                $$=cria_exp(Op);
                $$->str=">";//ok
        }

        | MENOR_IGUAL {
                //printf("relacao\n");
                $$=cria_exp(Op);
                $$->str="<=";//ok
        }

        | DIFERENTE {
                //printf("relacao\n");
                $$=cria_exp(Op);
                $$->str="!=";//ok
        }

        | MAIOR_IGUAL {
                //printf("relacao\n");
                $$=cria_exp(Op);
                $$->str=">=";//ok
        }

        | IGUAL {
                //printf("relacao\n");
                $$=cria_exp(Op);
                $$->str="==";//ok
        };

soma_expressao:
        soma_expressao soma termo {
                //printf("soma_expressao\n");
                $$ = $2;
                $$->filhos[0] = $1;
                $$->filhos[1] = $3;
                $$->n_filhos = 2;
        }
        | termo {
                //printf("soma_expressao\n");
                $$=$1;
        };

soma:
        MAIS {
                //printf("soma\n");
                $$=cria_exp(Op);
                $$->str="+";//ok
        }

        | MENOS {
                //printf("soma\n");
                $$=cria_exp(Op);
                $$->str="-";//ok
        };

termo:
        termo mult fator {
                //printf("termo\n");
                $$=$2;
                $$->filhos[0]=$1;
                $$->filhos[1]=$3;
                $$->n_filhos = 2;
        }
        | fator {
                //printf("termo\n");
                $$ = $1;
        };

mult:
        MULTIPLICACAO {
                //printf("mult\n");
                $$=cria_exp(Op);
                $$->str="*";//ok
        }
        | DIVISAO {
                //printf("mult\n");
                $$=cria_exp(Op);
                $$->str="/";//ok
        };

fator:
        L_PAR expressao R_PAR {
                //printf("fator\n");
                $$ = $2;
        }
        | var {
                //printf("fator\n");
                $$ = $1;
        }

        | ativacao {
                //printf("fator\n");
                $$ = $1;
        }

        | NUMERO {
                //printf("fator\n");
                $$=cria_exp(Const);
                $$->str=strdup(lex->lexema);//ok
        };

ativacao:
        id{
                //printf("ativacao\n");
                $$=cria_exp(Ativ);
                $$->str=str_aux;//nok
        } L_PAR args R_PAR {
                //printf("ativacao\n");
                $$=$2;
                $$->filhos[0]=$4;
                $$->n_filhos = 1;
        };

args:
        arg_list {
                //printf("args\n");
                $$ = $1;
        }
        | /* vazio */ {
                //printf("args\n");
                $$ = NULL;
        };

arg_list:
        arg_list COMMA expressao {
                //printf("arg_list\n");
                YYSTYPE aux = $1;
                while(aux->irmaos != NULL){
                aux = aux->irmaos;
                }
                aux->irmaos = $2;
                $$ = $1;
        }
        | expressao {
                //printf("arg_list\n");
                $$ = $1;
        };

%%

int yylex() {
    return (get_token());
}

void yyerror(const char *s) {
    printf("Erro de sintaxe na linha %d\n", lex->linha);
}

AST_p parse()
{
        yyparse();
        return raiz;
}
