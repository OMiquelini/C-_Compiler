%{
    // Seção de declarações e definições
%}

%token <type> TOKEN_NAME

%%
    // Regras de produção
%%

// Função principal
int main() {
    // Código para análise sintática
    yyparse();
    return 0;
}
