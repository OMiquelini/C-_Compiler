#include "scanner.h"

int main(int argc, char *argv[])
{
    int i;
    int vetor_ascii[]={207, 331, 425, 434, 537, 672};//inserir valores ascii das palavras reservadas
    char *vetor_palavras[]={"if","int", "else", "void", "while", "return"};//inserir palavras reservadas em ordem dos seus valores em ascii
    arvore_p raiz_reservada = NULL;
    if(argc != 2)
    {
        printf("Usage: <file_name>\n");
        return 1;
    }
    for(i=0;i<7;i++)
    {
        raiz_reservada = inserir_no(raiz_reservada, vetor_ascii[i], vetor_palavras[i]);
    }
}