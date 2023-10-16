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

int soma_ascii(char *str);
arvore_p criar_no(int valor, char *str);
arvore_p inserir_no(arvore_p raiz, int valor, char *str);
char *busca_no(arvore_p raiz, int valor, char *str);

