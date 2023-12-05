# C-_Compiler
Compilador para a linguagem C- desenvolvido por Matheus Miquelini e Tiago Miranda para a disciplina Compiladores na UNIFESP.

TODO: 
    1: (DONE) Corrigir último lexema e implementar atribuição de tokens unitários para os operadores.
    2: (DONE)  Modificar funcionamento do lexer para funcionar sob demanda.
    3: (DONE) Parser: criar função para salvar (feito) a arvore gerada e imprimir.
    4: (TODO) Parser: Corrigir ligação dos ponteiros para nós filhos e irmaos, e corrigir atribuição dos labels dos nos para as linhas com //nok
    5: (TODO) Tabela de símbolos
    6: (TODO) Analisador semantico

PROBLEMAS ATUAIS:
    1: Aparentemente o código está gerando a árvore corretamente, porém não está tratando o EOF corretamente. Precisamos adicionar como token para finalizar a geração? R: Não esta gerando a árvore, porém agora está tratando o EOF corretamente
    2: parser é apenas chamado, a arvore não é salva em nenhum lugar. R:raiz da árvore é salva, porem ponteiros para filhos e irmãos estão incorretos

GUIDE:
    Compilar usando make, ir em parser.tab.h na linha 75 e trocar "typedef int YYSTYPE;" por "typedef AST_p YYSTYPE;"
    Na hora de rodar, usar ./compilador (arquivo entrada)
    No arquivo output será salvo os tokens, lexemas e linha, junto com a arvore sintática e a tabela de simbolos