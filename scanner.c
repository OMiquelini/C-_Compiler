#include "scanner.h"

#define N_SIMBOBOLOS 19
#define N_ESTADOS 12

//TODO: Renomear estados
enum Estados{INICIAL, NUM, ID, OP1, OP2, ATRIB, DIV, Q7, Q8, Q9, FINAL, LIXO};

enum Simbolos{alfa, digito, menos, mais, igual, vezes, barra, maior, menor, ponto_virgula, virgula, exclama,
              L_parentesis, R_parentesis, L_colchete, R_colchete, L_chaves, R_chaves, Space };//TODO: adicionar espaço em branco

//TODO: Refazer tabela de transição com um estado para cada operador
int tabela_transicoes[N_ESTADOS][N_SIMBOBOLOS]={
    
};

int DFA_func(p_buffer b, FILE *fp, p_no no)
{
    int estado_atual = INICIAL, estado_ant = INICIAL;
    int i = 0;
    char c;
    while(((c=get_next_char(b, fp))!='\0')&&((c=get_next_char(b, fp))!=EOF))
    {
        estado_ant = estado_atual;
        if(isalpha(c))
        {
            estado_atual = tabela_transicoes[estado_atual][alfa];
        }
        else if(isdigit(c))
        {
            estado_atual = tabela_transicoes[estado_atual][digito];
        }
        else if(c =='+')
        {
            estado_atual = tabela_transicoes[estado_atual][mais];
        }
        else if(c =='-')
        {
            estado_atual = tabela_transicoes[estado_atual][menos];
        }
        else if(c =='(')
        {
            estado_atual = tabela_transicoes[estado_atual][L_parentesis];
        }else if(c ==')')
        {
            estado_atual = tabela_transicoes[estado_atual][R_parentesis];
        }
        else if(c =='[')
        {
            estado_atual = tabela_transicoes[estado_atual][L_colchete];
        }
        else if(c ==']')
        {
            estado_atual = tabela_transicoes[estado_atual][R_colchete];
        }
        else if(c =='{')
        {
            estado_atual = tabela_transicoes[estado_atual][L_chaves];
        }
        else if(c =='}')
        {
            estado_atual = tabela_transicoes[estado_atual][R_chaves];
        }
        else if(c =='<')
        {
            estado_atual = tabela_transicoes[estado_atual][menor];
        }
        else if(c ==';')
        {
            estado_atual = tabela_transicoes[estado_atual][ponto_virgula];
        }
        else if(c ==',')
        {
            estado_atual = tabela_transicoes[estado_atual][virgula];
        }
        else if(c =='!')
        {
            estado_atual = tabela_transicoes[estado_atual][exclama];
        }
        else if(c =='>')
        {
            estado_atual = tabela_transicoes[estado_atual][maior];
        }
        else if(c =='=')
        {
            estado_atual = tabela_transicoes[estado_atual][igual];
        }
        else if (c =='/')
        {
            estado_atual = tabela_transicoes[estado_atual][barra];
        }
        else if(c =='*')
        {
            estado_atual = tabela_transicoes[estado_atual][vezes];
        }
        else if(isspace(c))
        {
            estado_atual = tabela_transicoes[estado_atual][Space];
        }
        else
        {
            estado_atual = Q13;
        }
        if (estado_atual==Q13)
        {
            printf("Erro lexico na linha %d: caractere %c não aceito na linguagem",b->line,c);
            return -1;
        }
        else if (estado_atual!=Q5)
        {
            no->lexema[i]=c;
            i++;
        }
        else if(estado_atual==Q5)
        {
            unget_char(b, c);
            no->token = estado_ant;
            no->linha=b->line;
            no->lexema[i]='\0';
            no->prox=allocate_no();
            no=no->prox;
            i=0;
        }
        
    }
    return 0;
}


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

/******************************************************************************************************************************************/
p_buffer allocate_buffer()
{
    p_buffer b = (p_buffer)malloc(sizeof(t_buffer));
    if(b == NULL)
    {
        return NULL;
    }
    b->buffer_size = 256;
    b->last_pos = 0;
    b->line = 1;
    return b;
}

void deallocate_buffer(p_buffer b)
{
    free(b);
}

void deallocate_no(p_no no)
{
    while(no->prox!=NULL)
    {
        p_no aux = no;
        no=no->prox;
        free(aux);
    }
}

char get_next_char(p_buffer b, FILE *fp)
{
    if (b->vetor[b->last_pos] == '\0')
    {
        if (fill_buffer(b, fp) == -1)
        {
            return EOF;
        }
    }

    char c = b->vetor[b->last_pos];
    b->last_pos++;
    return c;
}

int fill_buffer(p_buffer b, FILE *fp)
{
    b->last_pos = 0;
    if(fgets(b->vetor, 256, fp)==NULL)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void unget_char(p_buffer b,char c)
{
    b->last_pos--;
    b->vetor[b->last_pos] = c;
}

p_no allocate_no() {
    p_no novo_no = (p_no)malloc(sizeof(t_no));
    
    if (novo_no != NULL) {
        novo_no->lexema = NULL;
        novo_no->token = 0;
        novo_no->linha = 0;
        novo_no->prox = NULL;
    }   
    return novo_no;
}