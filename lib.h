/********************************************************************************************************************
 Desenvolvido em Outubro de 2023 por:
 Matheus Miquelini Andrello
 Tiago Miranda
**********************************************************************************************************************/

#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>


#define N_SIMBOBOLOS 19
#define N_ESTADOS 12

enum Estados{INICIAL, NUM, ID, OP1, OP2, ATRIB, DIV, Q7, Q8, Q9, FINAL, LIXO};

enum Simbolos{alfa, digito, menos, mais, igual, vezes, barra, maior, menor, ponto_virgula, virgula, exclama,
              L_parentesis, R_parentesis, L_colchete, R_colchete, L_chaves, R_chaves, Space };//TODO: adicionar espaço em branco

enum Tokens{NUMERO=1, IDENTIFICADOR, MAIS, MAIOR, ATRIBUICAO, DIVISAO, MENOS, MULTIPLICACAO, L_PAR, R_PAR, L_CHAVES, R_CHAVES, L_BRAC, R_BRAC, VIRGULA, COMMA, MENOR, MAIOR_IGUAL, MENOR_IGUAL, DIFERENTE, IF,INT, ELSE, VOID, WHILE, RETURN};

//struct do nó da arvore binária das palavras reservadas
typedef struct arvore_t
{
    int ascii;
    char *palavra;
    int tok;
    struct arvore_t *direita;
    struct arvore_t *esquerda;
} arvore_t;

typedef arvore_t *arvore_p;

//buffer para leitura do arquivo
typedef struct buff{
    int buffer_size;
    int last_pos;
    int line;
    char vetor[256];
}t_buffer;

typedef t_buffer *p_buffer;

//struct do nó do scanner
typedef struct no{
    char *lexema;
    int token;
    int linha;
    int ascii;
}t_no;

//struct da arvore do parser
typedef struct AST_t {
    char* label;
    struct AST_t** filhos;
    int n_filhos;
} AST_t;

typedef AST_t *AST_p;

typedef t_no *p_no;

//funções do scanner
int soma_ascii(char *str);
int busca_no(arvore_p raiz, int valor, char *str);
void reservada();
void imprime_token();
void token_operadores();
arvore_p criar_no(int valor, char *str, int token);
arvore_p inserir_no(arvore_p raiz, int valor, char *str, int token);
p_no allocate_no();
p_buffer allocate_buffer();
void deallocate_buffer(p_buffer b);
void deallocate_no(p_no no);

//funções do parser
AST_p create_node(char* label, int n_children, ...);
void printTree(AST_p node, int level);
void freeTree(AST_p node);

extern FILE *fpi;
extern FILE *fpo_tokens;
extern arvore_p raiz_reservada;
extern p_no lex;
extern p_buffer buffer;

#endif