#ifndef SCANNER_H
#define SCANNER_H

#include "lib.h"

/********************************************************************************************************************
 Desenvolvido em Outubro de 2023 por:
 Matheus Miquelini Andrello
 Tiago Miranda
**********************************************************************************************************************/

int DFA_func(p_buffer b, FILE *fp, p_no no);
char get_next_char(p_buffer b, FILE *fp);
int fill_buffer(p_buffer b, FILE *fp);
void unget_char(p_buffer b,char c);
void get_token(p_buffer b, FILE *fpi, p_no no, arvore_p raiz_reservada, FILE *fpo);

#endif

