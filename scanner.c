/********************************************************************************************************************
 Desenvolvido em Outubro de 2023 por:
 Matheus Miquelini Andrello
 Tiago Miranda
**********************************************************************************************************************/

#include "scanner.h"

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

int DFA_func()
{
    int estado_atual = INICIAL, estado_ant = INICIAL;
    int i = 0;
        char c =' ';
    while (estado_atual!=FINAL && estado_ant!=-1){
        c = get_next_char(buffer, fpi);
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
            estado_atual = tabela_transicoes[estado_atual][comma];
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
            estado_atual = -1;//tabela_transicoes[estado_atual][Space];
            lex->token=0;
        } else {
            estado_atual = LIXO;
        }
        if(estado_ant==Q8 && estado_atual==LIXO)
        {
            estado_atual=Q8;
        }
        if (estado_atual==INICIAL)
        {
            i=0;
        }
        
        if (estado_atual == LIXO && estado_ant == Q7) {
            printf("Erro lexico na linha %d: esperado caractere '=' mas recebeu '%c'\n", buffer->line,c);
            return -1;
        } else if(estado_atual == LIXO){
            printf("Erro lexico na linha %d: caractere '%c' não aceito pela linguagem\n", buffer->line,c);
            return -1;
        } else if ((estado_atual != FINAL && estado_atual != Q8 && estado_atual != Q9 && estado_atual !=-1) && (!isspace(c))) {
            lex->lexema[i] = c;
            lex->linha = buffer->line;
            i++;
        }
        
    }
    unget_char(c);
    lex->token = estado_ant;
    if(estado_ant==-1)
        lex->lexema="EOF";
    else
        lex->lexema[i] = '\0';
    return 0;
}


char get_next_char()
{
    if (buffer->vetor[buffer->last_pos] == '\0')
    {
        if (fill_buffer(buffer, fpi) == -1)
        {
            return EOF;
        }
    }

    char c = buffer->vetor[buffer->last_pos];
    if (c=='\n')
    {
        buffer->line++;
    }
    buffer->last_pos++;
    return c;
}

int fill_buffer()
{
    buffer->last_pos = 0;
    if(fgets(buffer->vetor, 256, fpi)==NULL)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void unget_char(char c)
{
    buffer->last_pos--;
    buffer->vetor[buffer->last_pos] = c;
}

int get_token()
{
    if(DFA_func(buffer, fpi, lex)==-1)
    {
        printf("Erro lexico\n");
    }
    else
    {
        reservada();
        token_operadores();
        corrige_tokens();
        imprime_token();
    }
    return lex->token;
}

void token_operadores()
{
        if(lex->token==3||lex->token==4)
        {
            if(strcmp(lex->lexema,  "+")==0){lex->token=MAIS;}
            else if(strcmp(lex->lexema,  "-")==0){lex->token=MENOS;}
            else if(strcmp(lex->lexema,  "<")==0){lex->token=MENOR;}
            else if(strcmp(lex->lexema,  ">")==0){lex->token=MAIOR;}
            else if(strcmp(lex->lexema,  "=")==0){lex->token=ATRIBUICAO;}
            else if(strcmp(lex->lexema,  "*")==0){lex->token=MULTIPLICACAO;}
            else if(strcmp(lex->lexema,  "/")==0){lex->token=DIVISAO;}
            else if(strcmp(lex->lexema,  "(")==0){lex->token=L_PAR;}
            else if(strcmp(lex->lexema,  ")")==0){lex->token=R_PAR;}
            else if(strcmp(lex->lexema,  "{")==0){lex->token=L_CHAVES;}
            else if(strcmp(lex->lexema,  "}")==0){lex->token=R_CHAVES;}
            else if(strcmp(lex->lexema,  "[")==0){lex->token=L_BRAC;}
            else if(strcmp(lex->lexema,  "]")==0){lex->token=R_BRAC;}
            else if(strcmp(lex->lexema,  ",")==0){lex->token=COMMA;}
            else if(strcmp(lex->lexema,  ";")==0){lex->token=SEMICOLON;}
            else if(strcmp(lex->lexema,  ">=")==0){lex->token=MAIOR_IGUAL;}
            else if(strcmp(lex->lexema,  "<=")==0){lex->token=MENOR_IGUAL;}
            else if(strcmp(lex->lexema,  "==")==0){lex->token=IGUAL;}
            else if(strcmp(lex->lexema,  "!=")==0){lex->token=DIFERENTE;}
        }
    return;
}