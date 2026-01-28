// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
#define N 5
#define MAXINOME 50
#define MAXCOR 30
// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
typedef struct{
    char nome[MAXINOME + 1];
    char cor[MAXCOR + 1];
    int tropas;
} Territorio;

// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.
/* Remove \r e \n do final da string (se houver) */
void strip_newline(char *s) {
    if (!s) return;
    size_t len = strcspn(s, "\r\n");
    s[len] = '\0';
}
// Funções de setup e gerenciamento de memória:
/* Limpa o resto da linha do stdin (após scanf) */
void clear_stdin_line(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
// Funções de interface com o usuário:
// Funções de lógica principal do jogo:
// Função utilitária:

// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main(void) {
    // 1. Configuração Inicial (Setup):
    // - Define o locale para português.
    setlocale(LC_ALL, "Portuguese");
    Territorio mapa[N];

    printf("Cadastro de %d territorios\n", N);
    for (int i = 0; i < N; ++i) {
        printf("\n--- Territorio %d/%d ---\n", i + 1, N);

        printf("Nome do territorio: ");
        if (!fgets(mapa[i].nome, sizeof(mapa[i].nome), stdin)) {
            fprintf(stderr, "Erro na leitura do nome. Saindo.\n");
            return 1;
        }
        strip_newline(mapa[i].nome);

        printf("Cor do Exercito dominante: ");
        if (!fgets(mapa[i].cor, sizeof(mapa[i].cor), stdin)) {
            fprintf(stderr, "Erro na leitura da cor. Saindo.\n");
            return 1;
        }
        strip_newline(mapa[i].cor);

        printf("Numero de tropas (inteiro): ");
        while (scanf("%d", &mapa[i].tropas) != 1) {
            printf("Entrada invalida. Digite um numero inteiro para tropas: ");
            clear_stdin_line();
        }
        /* consumir o '\n' deixado pelo scanf para a próxima fgets */
        clear_stdin_line();
    }

    /* Impressao organizada */
    printf("\n===== Estado atual do mapa =====\n");
    printf("+----+----------------------------------------------------+-------------------------------+------------+\n");
    printf("| ID | Nome                                               | Cor do Exercito              | Tropas     |\n");
    printf("+----+----------------------------------------------------+-------------------------------+------------+\n");
    for (int i = 0; i < N; ++i) {
        printf("| %2d | %-50s | %-29s | %10d |\n", i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
    printf("+----+----------------------------------------------------+-------------------------------+------------+\n");

    return 0;
}