#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define N_SIMBOBOLOS 19
#define N_ESTADOS 12

enum Estados{INICIAL, NUM, ID, OP1, OP2, ATRIB, DIV, Q7, Q8, Q9, FINAL, LIXO};

enum Simbolos{alfa, digito, menos, mais, igual, vezes, barra, maior, menor, ponto_virgula, virgula, exclama,
              L_parentesis, R_parentesis, L_colchete, R_colchete, L_chaves, R_chaves, Space };//TODO: adicionar espaço em branco

enum Tokens{NUMERO=1, IDENTIFICADOR, MAIS, MAIOR, ATRIBUICAO, DIVISAO, MENOS, MULTIPLICACAO, L_PAR, R_PAR, L_CHAVES, R_CHAVES, L_BRAC, R_BRAC, VIRGULA, COMMA, MENOR, MAIOR_IGUAL, DIFERENTE, IF,INT, ELSE, VOID, WHILE, RETURN};

//struct do nó da arvore binária
typedef struct arvore_t
{
    int ascii;
    char *palavra;
    int tok;
    struct arvore_t *direita;
    struct arvore_t *esquerda;
} arvore_t;

typedef arvore_t *arvore_p;

typedef struct buff{
    int buffer_size;
    int last_pos;
    int line;
    char vetor[256];
}t_buffer;

typedef t_buffer *p_buffer;

typedef struct no{
    char *lexema;
    int token;
    char *tok;
    int linha;
    int ascii;
    struct no *prox;
}t_no;

typedef t_no *p_no;

int soma_ascii(char *str);
int busca_no(arvore_p raiz, int valor, char *str);

void reservada(p_no lista, arvore_p raiz_reservada);
void imprime_token(p_no lista, FILE *output);
void token_string(p_no lista);
void token_operadores(p_no lista);

#endif