/********************************************************************************************************************
 Desenvolvido em Outubro de 2023 por:
 Matheus Miquelini Andrello
 Tiago Miranda
**********************************************************************************************************************/

#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#define N_SIMBOBOLOS 19
#define N_ESTADOS 12

enum Estados{INICIAL, NUM, ID, OP1, OP2, ATRIB, DIV, Q7, Q8, Q9, FINAL, LIXO};

enum Simbolos{alfa, digito, menos, mais, igual, vezes, barra, maior, menor, ponto_virgula, comma, exclama,
              L_parentesis, R_parentesis, L_colchete, R_colchete, L_chaves, R_chaves, Space };//TODO: adicionar espaço em branco

//enum Tokens{NUMERO=258, IDENTIFICADOR, MAIS, MAIOR, ATRIBUICAO, DIVISAO, MENOS, MULTIPLICACAO, L_PAR, R_PAR, L_CHAVES, R_CHAVES, L_BRAC, R_BRAC, COMMA, SEMICOLON, MENOR, MAIOR_IGUAL, MENOR_IGUAL, DIFERENTE, IGUAL, IF,INT, ELSE, VOID, WHILE, RETURN};

//struct do nó da arvore binária das palavras reservadas
typedef struct arvore_t
{
    int ascii;
    char *palavra;
    int tok;
    struct arvore_t *direita;
    struct arvore_t *esquerda;
} arvore_t;

typedef arvore_t *arvore_p;

//buffer para leitura do arquivo
typedef struct buff{
    int buffer_size;
    int last_pos;
    int line;
    char vetor[256];
}t_buffer;

typedef t_buffer *p_buffer;

//struct do nó do scanner
typedef struct no{
    char *lexema;
    int token;
    int linha;
    int ascii;
}t_no;

typedef t_no *p_no;

typedef enum {STMT, EXP, DECL}tipoNo;
typedef enum {Var, Func, Param}tipoDecl;
typedef enum {Comp, If, While, Return}tipoStmt;
typedef enum {Void, Int, Array}tipoVar;
typedef enum {Op, Const, Id, array, Ativ}tipoExp;

#define MAX_FILHOS 3

//struct da arvore do parser
typedef struct AST_t {
    struct AST_t* filhos[MAX_FILHOS];
    struct AST_t* irmaos;
    int linha; //linha que apareceu
    char* str; //token ou label
    int n_filhos; //numero de filhos
    int tamanho; //caso seja array, temos que salvar o tamanho
    tipoNo tipo_no; //tipo do no, podendo ser statement, expression ou declaration
    tipoDecl tipo_decl; //tipo da declaracao, podendo ser variavel, funcao ou parametro
    tipoVar tipo_var; //tipo da variavel, podendo ser void, int ou array
    tipoExp tipo_exp; //tipo da expressao, podendo ser operador, constante, id array ou ativador 
    tipoStmt tipo_stmt; //tipo do statement, podendo ser comp, if, while ou return
    int tamanho_array;
} AST_t;

typedef AST_t *AST_p;

//tabela de simbolos
#define HASH_SIZE 997

typedef enum {variavel, funct} Tipo_simbolo;
typedef enum{void_, int_, array_} Tipo_dado;

typedef struct SimbTab_no{
    char *nome;
    char *escopo;
    Tipo_simbolo tipo;
    Tipo_dado dado;
    int linha;
    struct SimbTab_no *prox;
} SimbTab_no;

typedef SimbTab_no *SimbTab_p;

//funções do scanner
int soma_ascii(char *str);
int busca_no(arvore_p raiz, int valor, char *str);
void reservada();
void imprime_token();
void corrige_tokens();
arvore_p criar_no(int valor, char *str, int token);
arvore_p inserir_no(arvore_p raiz, int valor, char *str, int token);
p_no allocate_no();
p_buffer allocate_buffer();
void deallocate_buffer(p_buffer b);
void deallocate_no(p_no no);

//funções do parser
void freeTree(AST_p node);
AST_p parse();
AST_p cria_exp(tipoExp tipo);
AST_p cria_stmt(tipoStmt tipo);
AST_p cria_decl(tipoDecl tipo);
void print_AST(AST_p no, int nivel);

//funções da tabela de símbolos
unsigned int funcao_hash(const char *str);
void insere_simbolo(char *nome, char *escopo, Tipo_simbolo tipo, Tipo_dado dado, int linha);
SimbTab_p lookupSimb(const char *nome, const char *escopo);
void traverseAST(AST_p no, char **escopo_atual);
void print_SimTab();


extern FILE *fpi;
extern FILE *fpo_tokens;
extern arvore_p raiz_reservada;
extern p_no lex;
extern p_buffer buffer;
extern SimbTab_p hash_tab[HASH_SIZE];

#endif