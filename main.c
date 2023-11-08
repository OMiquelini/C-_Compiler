#include "scanner.h"
#include "parser.h"


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
    int token_reservada[]={7,8,9,10,11,12};
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
        fclose(output);
    }

    deallocate_buffer(buffer);
    deallocate_no(lex);
    fclose(fp);
    return 0;
}