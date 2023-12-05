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

AST_p cria_exp(tipoExp tipo){
    AST_p aux = (AST_p)malloc(sizeof(AST_t));
    int i;

    aux->str = (char*)malloc(64);
    
    for(i = 0; i<MAX_FILHOS; i++)
    {
        aux->filhos[i] = NULL;
    }
    aux->irmaos = NULL;
    aux->n_filhos = 0;
    aux->tipo_no = EXP;
    aux->tipo_exp = tipo;
    return aux;
}

AST_p cria_stmt(tipoStmt tipo){
    AST_p aux = (AST_p)malloc(sizeof(AST_t));
    int i;

    aux->str = (char*)malloc(64);

    for(i = 0; i<MAX_FILHOS; i++)
    {
        aux->filhos[i] = NULL;
    }
    aux->irmaos = NULL;
    aux->n_filhos = 0;
    aux->tipo_no = STMT;
    aux->tipo_stmt = tipo;
    return aux;
}

AST_p cria_decl(tipoDecl tipo){
    AST_p aux = (AST_p)malloc(sizeof(AST_t));
    int i;

    aux->str = (char*)malloc(64);

    for(i = 0; i<MAX_FILHOS; i++)
    {
        aux->filhos[i] = NULL;
    }
    aux->irmaos=NULL;
    aux->n_filhos = 0;
    aux->tipo_no = DECL;
    aux->tipo_decl = tipo;
    return aux;
}