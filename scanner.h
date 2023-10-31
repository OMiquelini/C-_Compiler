#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//struct do nó da arvore binária
typedef struct arvore_t
{
    int ascii;
    char *palavra;
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
    int linha;
    struct no *prox;
}t_no;

typedef t_no *p_no;

int DFA_func(p_buffer b, FILE *fp, p_no no);
int soma_ascii(char *str);
arvore_p criar_no(int valor, char *str);
arvore_p inserir_no(arvore_p raiz, int valor, char *str);
char *busca_no(arvore_p raiz, int valor, char *str);

p_no allocate_no();
p_buffer allocate_buffer();
void deallocate_buffer(p_buffer b);
void deallocate_no(p_no no);
char get_next_char(p_buffer b, FILE *fp);
int fill_buffer(p_buffer b, FILE *fp);
void unget_char(p_buffer b,char c);

