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
    int linha_horizontal = 2;
    int coluna_inicial_horizontal = 1;
    int tamanho_navio = 3;

    // Validação se o navio horizontal cabe no tabuleiro
    if (coluna_inicial_horizontal + tamanho_navio <= 10) {
        // Posiciona o navio horizontalmente
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[linha_horizontal][coluna_inicial_horizontal + i] = 3;
        }
        printf("Navio horizontal posicionado na linha %d, colunas %d-%d.\n",
               linha_horizontal + 1, coluna_inicial_horizontal + 1, coluna_inicial_horizontal + tamanho_navio);
    } else {
        printf("Erro: Navio horizontal não cabe na posição desejada.\n");
    }

    printf("\n");

    // --- Posicionamento do Navio Vertical ---
    printf("Posicionando navio vertical...\n");
    int linha_inicial_vertical = 6;
    int coluna_vertical = 8;

    // Validação se o navio vertical cabe no tabuleiro
    if (linha_inicial_vertical + tamanho_navio <= 10) {
        // Posiciona o navio verticalmente
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[linha_inicial_vertical + i][coluna_vertical] = 3;
        }
        printf("Navio vertical posicionado na coluna %d, linhas %d-%d.\n",
               coluna_vertical + 1, linha_inicial_vertical + 1, linha_inicial_vertical + tamanho_navio);
    } else {
        printf("Erro: Navio vertical não cabe na posição desejada.\n");
    }

    printf("\n");

    // --- Posicionamento do Navio Diagonal Principal ---
    printf("Posicionando navio diagonal principal...\n");
    int linha_inicial_diagonal_principal = 0;
    int coluna_inicial_diagonal_principal = 0;

    // Validação se o navio diagonal principal cabe no tabuleiro
    if (linha_inicial_diagonal_principal + tamanho_navio <= 10 &&
        coluna_inicial_diagonal_principal + tamanho_navio <= 10) {
        // Posiciona o navio na diagonal principal
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[linha_inicial_diagonal_principal + i][coluna_inicial_diagonal_principal + i] = 3;
        }
        printf("Navio diagonal principal posicionado a partir de (%d, %d) com tamanho %d.\n",
               linha_inicial_diagonal_principal + 1, coluna_inicial_diagonal_principal + 1, tamanho_navio);
    } else {
        printf("Erro: Navio diagonal principal não cabe na posição desejada.\n");
    }

    printf("\n");

    // --- Posicionamento do Navio Diagonal Secundária ---
    printf("Posicionando navio diagonal secundária...\n");
    int linha_inicial_diagonal_secundaria = 0;
    int coluna_inicial_diagonal_secundaria = 10 - tamanho_navio; // Equivalente a TAMANHO_TABULEIRO - TAMANHO_NAVIO

    // Validação se o navio diagonal secundária cabe no tabuleiro
    if (linha_inicial_diagonal_secundaria + tamanho_navio <= 10 &&
        coluna_inicial_diagonal_secundaria >= 0) {
        // Posiciona o navio na diagonal secundária
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[linha_inicial_diagonal_secundaria + i][coluna_inicial_diagonal_secundaria - i] = 3;
        }
        printf("Navio diagonal secundária posicionado a partir de (%d, %d) com tamanho %d.\n",
               linha_inicial_diagonal_secundaria + 1, coluna_inicial_diagonal_secundaria + 1, tamanho_navio);
    } else {
        printf("Erro: Navio diagonal secundária não cabe na posição desejada.\n");
    }

    printf("\n");

    // --- Validação de Sobreposição (Simplificada) ---
    printf("Validando sobreposição (simplificada)...\n");
    int sobreposicao = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (tabuleiro[i][j] == 3) { // Equivalente a NAVIO
                int contador_navios = 0;
                // Verifica se há mais de um navio na mesma posição (uma forma simplificada de verificar sobreposição)
                if (tabuleiro[i][j] == 3) contador_navios++;
                // Você pode adicionar mais verificações nas vizinhanças se precisar de uma validação mais robusta
                if (contador_navios > 1) {
                    sobreposicao = 1;
                    break;
                }
            }
        }
        if (sobreposicao) break;
    }

    if (sobreposicao) {
        printf("Aviso: Foi detectada sobreposição de navios (validação simplificada).\n");
    } else {
        printf("Não foram detectadas sobreposições de navios (validação simplificada).\n");
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