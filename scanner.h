#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//TODO: Renomear estados
enum Estados{INICIAL, NUM, ID, OP1, OP2, ATRIB, DIV, Q7, Q8, Q9, FINAL, LIXO};

enum Simbolos{alfa, digito, menos, mais, igual, vezes, barra, maior, menor, ponto_virgula, virgula, exclama,
              L_parentesis, R_parentesis, L_colchete, R_colchete, L_chaves, R_chaves, Space };//TODO: adicionar espaço em branco

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
    int linha;
    int ascii;
    struct no *prox;
}t_no;

typedef t_no *p_no;

int DFA_func(p_buffer b, FILE *fp, p_no no);
int soma_ascii(char *str);
arvore_p criar_no(int valor, char *str, int token);
arvore_p inserir_no(arvore_p raiz, int valor, char *str, int token);
int busca_no(arvore_p raiz, int valor, char *str);

p_no allocate_no();
p_buffer allocate_buffer();
void deallocate_buffer(p_buffer b);
void deallocate_no(p_no no);
char get_next_char(p_buffer b, FILE *fp);
int fill_buffer(p_buffer b, FILE *fp);
void unget_char(p_buffer b,char c);

