#include <stdio.h>

#define NUM_ESTADOS 4 // Incluindo um estado de lixo
#define NUM_SIMBOLOS 2

// Defina os estados do DFA
enum Estados { Q0, Q1, Q2, Q3 }; // Q3 é o estado de lixo

// Defina os símbolos de entrada
enum Simbolos { A, B };

// Defina a tabela de transições
int tabela_transicoes[NUM_ESTADOS][NUM_SIMBOLOS] = {
    {Q1, Q3},  // Transições para Q0 com entrada A e B
    {Q2, Q3},  // Transições para Q1 com entrada A e B
    {Q2, Q3},  // Transições para Q2 com entrada A e B
    {Q3, Q3}   // Transições para Q3 (estado de lixo) com entrada A e B
};

// Função para verificar se uma sequência de entrada é aceita pelo DFA
int verificarEntrada(char entrada[]) {
    int estado_atual = Q0;

    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] == 'A') {
            estado_atual = tabela_transicoes[estado_atual][A];
        } else if (entrada[i] == 'B') {
            estado_atual = tabela_transicoes[estado_atual][B];
        } else {
            estado_atual = Q3;  // Transição para o estado de lixo em caso de símbolo inválido
        }
    }

    if (estado_atual == Q2) {
        return 1;  // Sequência aceita
    } else {
        return 0;  // Sequência rejeitada
    }
}

int main() {
    char entrada[] = "ABXAB";
    int aceita = verificarEntrada(entrada);

    if (aceita) {
        printf("A entrada é aceita pelo DFA.\n");
    } else {
        printf("A entrada é rejeitada pelo DFA.\n");
    }

    return 0;
}
