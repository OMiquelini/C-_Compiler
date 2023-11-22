#ifndef SCANNER_H
#define SCANNER_H

#include "lib.h"

/********************************************************************************************************************
 Desenvolvido em Outubro de 2023 por:
 Matheus Miquelini Andrello
 Tiago Miranda
**********************************************************************************************************************/

int DFA_func(p_buffer b, FILE *fp, p_no no);
arvore_p criar_no(int valor, char *str, int token);
arvore_p inserir_no(arvore_p raiz, int valor, char *str, int token);

p_no allocate_no();
p_buffer allocate_buffer();
void deallocate_buffer(p_buffer b);
void deallocate_no(p_no no);
char get_next_char(p_buffer b, FILE *fp);
int fill_buffer(p_buffer b, FILE *fp);
void unget_char(p_buffer b,char c);

#endif

