#include <stdio.h>

int main() {
    // Declaração e inicialização do tabuleiro
    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // --- Posicionamento do Navio Horizontal ---
    printf("Posicionando navio horizontal...\n");
    int linha_horizontal = 2; // Linha onde o navio será posicionado
    int coluna_inicial_horizontal = 3; 

    // Validação se o navio horizontal cabe no tabuleiro
    if (coluna_inicial_horizontal + 3 <= 10) {
        // Posiciona o navio horizontalmente
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha_horizontal][coluna_inicial_horizontal + i] = 3;
        }
        printf("Navio horizontal posicionado na linha %d, colunas %d-%d.\n",
               linha_horizontal + 1, coluna_inicial_horizontal + 1, coluna_inicial_horizontal + 3);
    } else {
        printf("Erro: Navio horizontal não cabe na posição desejada.\n");
    }

    printf("\n");

    // --- Posicionamento do Navio Vertical ---
    printf("Posicionando navio vertical...\n");
    int linha_inicial_vertical = 5; 
    int coluna_vertical = 6; 

    // Validação se o navio vertical cabe no tabuleiro
    if (linha_inicial_vertical + 3 <= 10) {
        // Posiciona o navio verticalmente
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha_inicial_vertical + i][coluna_vertical] = 3;
        }
        printf("Navio vertical posicionado na coluna %d, linhas %d-%d.\n",
               coluna_vertical + 1, linha_inicial_vertical + 1, linha_inicial_vertical + 3);
    } else {
        printf("Erro: Navio vertical não cabe na posição desejada.\n");
    }

    printf("\n");

    // --- Exibição do Tabuleiro ---
    printf("Tabuleiro com os navios posicionados:\n");
    printf("  ");
    for (int j = 0; j < 10; j++) {
        printf("%d ", j + 1); 
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", i + 1); 
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}