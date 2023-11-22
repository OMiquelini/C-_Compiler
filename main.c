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
    p_no lex = allocate_no();
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
        printf("abri o arquivo\n");
        reservada(lex, raiz_reservada);
        //token_operadores(lex);
        token_string(lex);
        imprime_token(lex, output);
        fclose(output);
    }

    deallocate_buffer(buffer);
    deallocate_no(lex);
    fclose(fp);
    return 0;
}