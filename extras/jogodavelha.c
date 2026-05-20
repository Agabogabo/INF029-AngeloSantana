#include <stdio.h>

void desenharTabuleiro(char tabuleiro[3][3]) {
    printf("\n");
    printf("    1   2   3\n");
    printf("  -------------\n");
    printf("A | %c | %c | %c |\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("  -------------\n");
    printf("B | %c | %c | %c |\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("  -------------\n");
    printf("C | %c | %c | %c |\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf("  -------------\n\n");
}

int verificarJuiz(char tabuleiro[3][3]) {
    char vencedor = ' ';

    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) {
            vencedor = tabuleiro[i][0];
        }
    }

    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][j] != ' ' && tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j]) {
            vencedor = tabuleiro[0][j];
        }
    }

    if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
        vencedor = tabuleiro[0][0];
    }
    if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
        vencedor = tabuleiro[0][2];
    }

    if (vencedor == 'X') return 1;
    if (vencedor == 'O') return 2;

    int temEspaco = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                temEspaco = 1;
            }
        }
    }

    if (temEspaco == 0) return 3; 

    return 0;
}

int main() {
    char tabuleiro[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int jogadorAtual = 1;
    char jogada[10];

    printf("=== JOGO DA VELHA ===\n");

    while (1) {
        desenharTabuleiro(tabuleiro);

        printf("Jogador %d, informe sua jogada (ex: B3): ", jogadorAtual);
        scanf("%s", jogada);

        int linha = jogada[0] - 'A';
        if (jogada[0] >= 'a' && jogada[0] <= 'c') {
            linha = jogada[0] - 'a';
        }
        
        int coluna = jogada[1] - '1';

        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
            printf("\n=> Jogada invalida! Use letras de A a C e numeros de 1 a 3.\n");
            continue;
        }

        if (tabuleiro[linha][coluna] != ' ') {
            printf("\n=> Essa casa ja esta ocupada! Escolha outra.\n");
            continue;
        }

        if (jogadorAtual == 1) {
            tabuleiro[linha][coluna] = 'X';
        } else {
            tabuleiro[linha][coluna] = 'O'; 
        }

        int statusJogo = verificarJuiz(tabuleiro);
        
        if (statusJogo != 0) {
            desenharTabuleiro(tabuleiro);
            
            if (statusJogo == 1) printf("\n~~~~ PARABENS! O Jogador 1 (X) VENCEU! ~~~~\n\n");
            else if (statusJogo == 2) printf("\n~~~~ PARABENS! O Jogador 2 (O) VENCEU! ~~~~\n\n");
            else if (statusJogo == 3) printf("\n~~~~ DEU VELHA! O jogo empatou. ~~~~\n\n");
            
            break;
        }

        if (jogadorAtual == 1) {
            jogadorAtual = 2;
        } else {
            jogadorAtual = 1;
        }
    }

    return 0;
}