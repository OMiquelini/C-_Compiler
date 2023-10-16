#include "scanner.h"

int soma_ascii(char *str)
{
    int soma = 0;
    for (int i = 0; i < strlen(str); i++) {
        soma += str[i];
    }
    return soma;
}

//função para criar o nó com a palavra reservada e seu valor em ascii
arvore_p criar_no(int valor, char *str)
{
    arvore_p novo_no = (arvore_p)malloc(sizeof(arvore_t));
    if (novo_no == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }
    novo_no->ascii = valor;
    novo_no->palavra = str;
    novo_no->direita = NULL;
    novo_no->esquerda = NULL;
    return novo_no;
}

//função para inserir o nó na arvore
arvore_p inserir_no(arvore_p raiz, int valor, char *str)
{
    if (raiz == NULL) {
        return criar_no(valor, str);
    }
    if (valor < raiz->ascii) {
        raiz->esquerda = inserir_no(raiz->esquerda, valor, str);
    } else if (valor > raiz->ascii) {
        raiz->direita = inserir_no(raiz->direita, valor, str);
    }
    return raiz;
}

char *busca_no(arvore_p raiz, int valor, char *str)
{
    while (raiz != NULL)
    {
        if (valor < raiz->ascii) {
            raiz = raiz->esquerda;
        } else if (valor > raiz->ascii) {
            raiz = raiz->direita;
        } else if (strcmp(str,raiz->palavra)){
            return raiz->palavra;
        }
        else{
            return "ID";
        }
    }
    
}