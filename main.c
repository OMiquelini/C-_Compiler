/********************************************************************************************************************
 Desenvolvido em Outubro de 2023 por:
 Matheus Miquelini Andrello
 Tiago Miranda
**********************************************************************************************************************/

#include "scanner.h"
#include "parser.tab.h"
extern FILE* yyin;


int main(int argc, char *argv[])
{
    int i;
    int vetor_ascii[]={207, 331, 425, 434, 537, 672};
    char *vetor_palavras[]={"if","int", "else", "void", "while", "return"};
    int token_reservada[]={IF,INT, ELSE, VOID, WHILE, RETURN};
    AST_p raiz_sintatica;
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

    fpo_tokens = fopen("output.txt","w");
    if(fpi == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    fprintf(fpo_tokens,"========Tokens========\n");
    raiz_sintatica = parse();

    fprintf(fpo_tokens,"\n========Árvore Sintática========\n");
    print_AST(raiz_sintatica, 0);

    char *escopo_atual="global";

    fprintf(fpo_tokens,"\n========Symbol Table========\n");
    traverseAST(raiz_sintatica, escopo_atual); 
    print_SimTab();

    deallocate_buffer(buffer);
    free(raiz_sintatica);
    deallocate_no(lex);
    fclose(fpi);
    fclose(fpo_tokens);
    return 0;
}