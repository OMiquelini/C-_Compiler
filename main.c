#include "scanner.h"


/********************************************************************************************************************
 Desenvolvido em Outubro de 2023 por:
 Matheus Miquelini Andrello
 Tiago Miranda
**********************************************************************************************************************/


int main(int argc, char *argv[])
{
    int i;
    int vetor_ascii[]={207, 331, 425, 434, 537, 672};
    char *vetor_palavras[]={"if","int", "else", "void", "while", "return"};
    int token_reservada[]={IF,INT, ELSE, VOID, WHILE, RETURN};
    arvore_p raiz_reservada = NULL;
    p_no lex = allocate_no(), aux;
    p_buffer buffer = allocate_buffer();
    if(argc != 2)
    {
        printf("Usage: <file_name>\n");
        return 1;
    }
    for(i=0;i<6;i++)
    {
        raiz_reservada = inserir_no(raiz_reservada, vetor_ascii[i], vetor_palavras[i],token_reservada[i]);
    }
    FILE *fp = fopen(argv[1],"r");
    if(fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    if(DFA_func(buffer, fp, lex)==-1)
    {
        printf("Compilation has stoped due to lexical error\n");
        return -1;
    }
    else
    {
        FILE *output = fopen("output.txt", "w");
        if(output == NULL)
        {
            printf("Error opening file\n");
            return 1;
        }
        aux = lex;
        while(aux != NULL)
        {
            if(aux->token == ID)
            {
                aux->ascii=soma_ascii(aux->lexema);
                aux->token = busca_no(raiz_reservada, aux->ascii, aux->lexema);
            }
            fprintf(output, "%d %s %d\n", aux->token, aux->lexema, aux->linha);
            aux = aux->prox;
        }
        aux = lex;
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
            aux=aux->prox;
        }
        
        fclose(output);
    }

    deallocate_buffer(buffer);
    deallocate_no(lex);
    fclose(fp);
    return 0;
}