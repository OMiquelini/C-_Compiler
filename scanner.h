/********************************************************************************************************************
 Desenvolvido em Outubro de 2023 por:
 Matheus Miquelini Andrello
 Tiago Miranda
**********************************************************************************************************************/

#ifndef SCANNER_H
#define SCANNER_H

#include "lib.h"

int DFA_func();
char get_next_char();
int fill_buffer();
void unget_char(char c);
int get_token();

#endif

