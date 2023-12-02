/********************************************************************************************************************
 Desenvolvido em Outubro de 2023 por:
 Matheus Miquelini Andrello
 Tiago Miranda
**********************************************************************************************************************/

#include "scanner.h"
extern FILE* yyin;


int main(int argc, char *argv[])
{
    int i;
    int vetor_ascii[]={207, 331, 425, 434, 537, 672};
    char *vetor_palavras[]={"if","int", "else", "void", "while", "return"};
    int token_reservada[]={IF,INT, ELSE, VOID, WHILE, RETURN};
    raiz_reservada = NULL;
    lex = allocate_no();
    buffer = allocate_buffer();
    if(argc != 2)
    {
        printf("Usage: <file_name>\n");
        return 1;
    }
    for(i=0;i<6;i++)
    {
        raiz_reservada = inserir_no(raiz_reservada, vetor_ascii[i], vetor_palavras[i],token_reservada[i]);
    }
    fpi = fopen(argv[1],"r");
    if(fpi == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    fpo = fopen("output.txt","w");
    if(fpi == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    for(i=0;i<28;i++)
        get_token();

    deallocate_buffer(buffer);
    deallocate_no(lex);
    fclose(fpi);
    fclose(fpo);
    return 0;
}