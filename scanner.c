#include "scanner.h"

/********************************************************************************************************************
 Desenvolvido em Outubro de 2023 por:
 Matheus Miquelini Andrello
 Tiago Miranda
**********************************************************************************************************************/

int tabela_transicoes[N_ESTADOS][N_SIMBOBOLOS]={
    /*INICIAL*/ {ID, NUM, OP1, OP1, ATRIB, OP1, DIV, OP2, OP2, OP1, OP1, Q7, OP1, OP1, OP1, OP1, OP1, OP1, INICIAL},
    /*NUM*/     {FINAL, NUM, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
    /*ID*/      {ID, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
    /*OP1*/     {FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
    /*OP2*/     {FINAL, FINAL, FINAL, FINAL, OP1, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
    /*ATRIB*/   {FINAL, FINAL, FINAL, FINAL, OP1, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
    /*DIV*/     {FINAL, FINAL, FINAL, FINAL, FINAL, Q8, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
    /*Q7*/      {LIXO, LIXO, LIXO, LIXO, OP1, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO},
    /*Q8*/      {Q8, Q8, Q8, Q8, Q8, Q9, Q8, Q8, Q8, Q8, Q8, Q8, Q8, Q8, Q8, Q8, Q8, Q8, Q8},
    /*Q9*/      {Q8, Q8, Q8, Q8, Q8, Q9, INICIAL, Q8, Q8, Q8, Q8, Q8, Q8, Q8, Q8, Q8, Q8, Q8, Q8},
    /*FINAL*/   {FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
    /*LIXO*/    {LIXO, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO, LIXO}
};

int DFA_func(p_buffer b, FILE *fp, p_no no)
{
    int estado_atual = INICIAL, estado_ant = INICIAL;
    int i = 0;
        char c =' ';
    while (estado_atual!=FINAL){
        c = get_next_char(b, fp);
        estado_ant = estado_atual;
        if (isalpha(c)) {
            estado_atual = tabela_transicoes[estado_atual][alfa];
        } else if (isdigit(c)) {
            estado_atual = tabela_transicoes[estado_atual][digito];
        } else if (c == '+') {
            estado_atual = tabela_transicoes[estado_atual][mais];
        } else if (c == '-') {
            estado_atual = tabela_transicoes[estado_atual][menos];
        } else if (c == '(') {
            estado_atual = tabela_transicoes[estado_atual][L_parentesis];
        } else if (c == ')') {
            estado_atual = tabela_transicoes[estado_atual][R_parentesis];
        } else if (c == '[') {
            estado_atual = tabela_transicoes[estado_atual][L_colchete];
        } else if (c == ']') {
            estado_atual = tabela_transicoes[estado_atual][R_colchete];
        } else if (c == '{') {
            estado_atual = tabela_transicoes[estado_atual][L_chaves];
        } else if (c == '}') {
            estado_atual = tabela_transicoes[estado_atual][R_chaves];
        } else if (c == '<') {
            estado_atual = tabela_transicoes[estado_atual][menor];
        } else if (c == ';') {
            estado_atual = tabela_transicoes[estado_atual][ponto_virgula];
        } else if (c == ',') {
            estado_atual = tabela_transicoes[estado_atual][virgula];
        } else if (c == '!') {
            estado_atual = tabela_transicoes[estado_atual][exclama];
        } else if (c == '>') {
            estado_atual = tabela_transicoes[estado_atual][maior];
        } else if (c == '=') {
            estado_atual = tabela_transicoes[estado_atual][igual];
        } else if (c == '/') {
            estado_atual = tabela_transicoes[estado_atual][barra];
        } else if (c == '*') {
            estado_atual = tabela_transicoes[estado_atual][vezes];
        } else if (isspace(c)) {
            estado_atual = tabela_transicoes[estado_atual][Space];
        } else if(c==EOF){
            estado_atual = tabela_transicoes[estado_atual][Space];
        } else {
            printf("Lixo\n");
            estado_atual = LIXO;
        }
        if (estado_atual == LIXO && estado_ant == Q7) {
            printf("Erro lexico na linha %d: esperado caractere '=' mas recebeu '%c'\n", b->line,c);
            return -1;
        } else if(estado_atual == LIXO){
            printf("Erro lexico na linha %d: caractere '%c' não aceito pela linguagem\n", b->line,c);
            return -1;
        } else if ((estado_atual != FINAL) && (!isspace(c))) {
            no->lexema[i] = c;
            no->linha = b->line;
            i++;
        }
        
    }
    unget_char(b, c);
    no->token = estado_ant;
    no->lexema[i] = '\0';
    return 0;
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
    if (c=='\n')
    {
        b->line++;
    }
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

void get_token(p_buffer b, FILE *fpi, p_no no, arvore_p raiz_reservada, FILE *fpo)
{
    if(DFA_func(b, fpi, no)==-1)
    {
        printf("Erro lexico\n");
    }
    else
    {
        reservada(no, raiz_reservada);
        token_operadores(no);
        imprime_token(no, fpo);
    }
}