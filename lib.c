#include "lib.h"

int soma_ascii(char *str)
{
    int soma = 0;
    for (int i = 0; i < strlen(str); i++) {
        soma += str[i];
    }
    return soma;
}

void reservada(p_no lista, arvore_p raiz_reservada)
{
        if(lista->token == ID)
        {
            lista->ascii=soma_ascii(lista->lexema);
            lista->token = busca_no(raiz_reservada, lista->ascii, lista->lexema);
        }
    return;
}

void imprime_token(p_no lista, FILE *output)
{
    fprintf(output,"linha: %d lexema: %s token: %d\n", lista->linha, lista->lexema, lista->token);
    return;
}

void token_operadores(p_no lista)
{
        if(lista->token==3||lista->token==4)
        {
            if(strcmp(lista->lexema,  "+")==0){lista->token=MAIS;}
            else if(strcmp(lista->lexema,  "-")==0){lista->token=MENOS;}
            else if(strcmp(lista->lexema,  "<")==0){lista->token=MENOR;}
            else if(strcmp(lista->lexema,  ">")==0){lista->token=MAIOR;}
            else if(strcmp(lista->lexema,  "=")==0){lista->token=ATRIBUICAO;}
            else if(strcmp(lista->lexema,  "*")==0){lista->token=MULTIPLICACAO;}
            else if(strcmp(lista->lexema,  "/")==0){lista->token=DIVISAO;}
            else if(strcmp(lista->lexema,  "(")==0){lista->token=L_PAR;}
            else if(strcmp(lista->lexema,  ")")==0){lista->token=R_PAR;}
            else if(strcmp(lista->lexema,  "{")==0){lista->token=L_CHAVES;}
            else if(strcmp(lista->lexema,  "}")==0){lista->token=R_CHAVES;}
            else if(strcmp(lista->lexema,  "[")==0){lista->token=L_BRAC;}
            else if(strcmp(lista->lexema,  "]")==0){lista->token=R_BRAC;}
            else if(strcmp(lista->lexema,  ",")==0){lista->token=VIRGULA;}
            else if(strcmp(lista->lexema,  ";")==0){lista->token=COMMA;}
            else if(strcmp(lista->lexema,  ">=")==0){lista->token=MAIOR_IGUAL;}
            else if(strcmp(lista->lexema,  "!=")==0){lista->token=DIFERENTE;}
        }
    return;
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