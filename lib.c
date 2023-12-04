/********************************************************************************************************************
 Desenvolvido em Outubro de 2023 por:
 Matheus Miquelini Andrello
 Tiago Miranda
**********************************************************************************************************************/

#include "lib.h"

FILE *fpi;
FILE *fpo_tokens;
arvore_p raiz_reservada;
p_no lex;
p_buffer buffer;

int soma_ascii(char *str)
{
    int soma = 0;
    for (int i = 0; i < strlen(str); i++) {
        soma += str[i];
    }
    return soma;
}

void reservada()
{
        if(lex->token == ID)
        {
            lex->ascii=soma_ascii(lex->lexema);
            lex->token = busca_no(raiz_reservada, lex->ascii, lex->lexema);
        }
    return;
}

void imprime_token()
{
    fprintf(fpo_tokens,"linha: %d lexema: %s token: %d\n", lex->linha, lex->lexema, lex->token);
    return;
}

void corrige_tokens()
{
    if(lex->token<=257)
    {
        lex->token+=257;
    }
}

//função para criar o nó com a palavra reservada e seu valor em ascii
arvore_p criar_no(int valor, char *str, int token)
{
    arvore_p novo_no = (arvore_p)malloc(sizeof(arvore_t));
    if (novo_no == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }
    novo_no->ascii = valor;
    novo_no->palavra = str;
    novo_no->tok = token;
    novo_no->direita = NULL;
    novo_no->esquerda = NULL;
    return novo_no;
}

//função para inserir o nó na arvore
arvore_p inserir_no(arvore_p raiz, int valor, char *str, int token)
{
    if (raiz == NULL) {
        return criar_no(valor, str, token);
    }
    if (valor < raiz->ascii) {
        raiz->esquerda = inserir_no(raiz->esquerda, valor, str, token);
    } else if (valor > raiz->ascii) {
        raiz->direita = inserir_no(raiz->direita, valor, str, token);
    }
    return raiz;
}

//função para buscar o nó na arvore
int busca_no(arvore_p raiz, int valor, char *str)
{
    while (raiz != NULL)
    {
        if (valor < raiz->ascii && raiz->esquerda!=NULL) {
            raiz = raiz->esquerda;
        } else if (valor > raiz->ascii && raiz->direita!=NULL) {
            raiz = raiz->direita;
        } else if (!strcmp(str,raiz->palavra)){
            return raiz->tok;
        }else{
             return ID;
        }
    }
    return -1;
    
}

//funcao para alocar buffer
p_buffer allocate_buffer()
{
    p_buffer b = (p_buffer)malloc(sizeof(t_buffer));
    if(b == NULL)
    {
        return NULL;
    }
    b->buffer_size = 256;
    b->last_pos = 0;
    b->line = 0;
    return b;
}

//desalocar buffer
void deallocate_buffer(p_buffer b)
{
    free(b);
}

//desalocar no
void deallocate_no(p_no no)
{
    free(no);
}

//alocar no
p_no allocate_no() {
    p_no novo_no = (p_no)malloc(sizeof(t_no));
    novo_no->lexema=(char*)malloc(64);
    
    if (novo_no != NULL) {
        novo_no->token = 0;
        novo_no->linha = 0;
        novo_no->ascii = 0;
    }   
    return novo_no;
}

//função para criar o nó da arvore AST
AST_p create_node(char* label, int n_filhos, ...) {
    AST_p node = (AST_p)malloc(sizeof(AST_t));
    node->label = strdup(label);
    node->n_filhos = n_filhos;

    if (n_filhos > 0) {
        node->filhos = (AST_p*)malloc(n_filhos * sizeof(AST_p));

        va_list args;
        va_start(args, n_filhos);
        for (int i = 0; i < n_filhos; i++) {
            node->filhos[i] = va_arg(args, AST_p);
        }
        va_end(args);
    } else {
        node->filhos = NULL;
    }

    return node;
}



void printTree(AST_p node, int level) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("%s\n", node->label);

    for (int i = 0; i < node->n_filhos; i++) {
        printTree(node->filhos[i], level + 1);
    }
}

void freeTree(AST_p node) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < node->n_filhos; i++) {
        freeTree(node->filhos[i]);
    }

    free(node->filhos);
    free(node);
}

