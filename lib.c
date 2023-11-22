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
    p_no aux = lista;
    while(aux != NULL)
    {
        if(aux->token == ID)
        {
            aux->ascii=soma_ascii(aux->lexema);
            aux->token = busca_no(raiz_reservada, aux->ascii, aux->lexema);
        }
        aux = aux->prox;
    }
    return;
}

void token_string(p_no lista)
{
    p_no aux = lista;
        while (aux!=NULL)
        {
            switch (aux->token)
            {
                case NUMERO:
                    aux->tok="NUM";
                    break;
                case IDENTIFICADOR:
                    aux->tok="ID";                    
                    break;
                case MAIS:
                    aux->tok="MAIS";
                    break;
                case MAIOR:
                    aux->tok="MAIOR";     
                    break;
                case MENOS:
                    aux->tok="MENOS";       
                    break;
                case ATRIBUICAO:
                    aux->tok="ATRIBUICAO";           
                    break;
                case DIVISAO:
                    aux->tok="DIVISAO";
                    break;
                case MULTIPLICACAO:
                    aux->tok="MULTIPLICACAO";
                    break;
                case L_PAR:
                    aux->tok="L_PAR";
                    break;
                case R_PAR:
                    aux->tok="R_PAR";
                    break;
                case L_CHAVES:
                    aux->tok="L_CHAVES";
                    break;
                case R_CHAVES:
                    aux->tok="R_CHAVES";
                    break;
                case L_BRAC:
                    aux->tok="L_BRAC";
                    break;
                case R_BRAC:
                    aux->tok="R_BRAC";
                    break;
                case VIRGULA:
                    aux->tok="VIRGULA";
                    break;
                case COMMA:
                    aux->tok="COMMA";
                    break;
                case MENOR:
                    aux->tok="MENOR";
                    break;
                case MAIOR_IGUAL:
                    aux->tok="MAIOR_IGUAL";
                    break;
                case DIFERENTE:
                    aux->tok="DIFERENTE";
                    break;
                case IF:
                    aux->tok="IF";
                    break;
                case INT:
                    aux->tok="INT";
                    break;
                case ELSE:
                    aux->tok="ELSE";
                    break;
                case VOID:
                    aux->tok="VOID";
                    break;
                case WHILE:
                    aux->tok="WHILE";
                    break;
                case RETURN:
                    aux->tok="RETURN";
                    break;
                default:
                    aux->tok="ERRO";
                    break;
                }
            aux = aux->prox;
        }
        return;
}

void imprime_token(p_no lista, FILE *output)
{
    p_no aux = lista;
    while(aux!=NULL)
    {
        fprintf(output,"%d %s %d\n", aux->linha, aux->lexema, aux->token);
        aux = aux->prox;
    }
    return;
}

/*token_operadores(p_no lista)
{
    p_no aux = lista;
    while(aux!=NULL)
    {
        if(aux->token==3||aux->token==5)
        {

        }
    }
}*/