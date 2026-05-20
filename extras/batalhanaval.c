#include <stdio.h>

#define QTD_NAVIOS 5

void desenharTela(char meuTab[10][10], char inimigoTab[10][10], int numJogador) {
    printf("\n===========================================================\n");
    printf("                  ALMIRANTE JOGADOR %d\n", numJogador);
    printf("===========================================================\n\n");
    
    printf("        SEU TABULEIRO                  RADAR INIMIGO\n");
    printf("     0 1 2 3 4 5 6 7 8 9            0 1 2 3 4 5 6 7 8 9\n");
    printf("   -----------------------        -----------------------\n");
    
    for (int i = 0; i < 10; i++) {
        printf("%c   |", 'A' + i);
        
        for (int j = 0; j < 10; j++) {
            printf("%c|", meuTab[i][j]);
        }
        
        printf("      %c   |", 'A' + i); 
        
        for (int j = 0; j < 10; j++) {
            if (inimigoTab[i][j] == 'N') {
                printf(" |"); 
            } else {
                printf("%c|", inimigoTab[i][j]); 
            }
        }
        printf("\n");
    }
    printf("   -----------------------        -----------------------\n\n");
}

void posicionarNavios(char tabuleiro[10][10], int numJogador) {
    char jogada[10];
    char orientacao;
    
    printf("\n>>> JOGADOR %d, PREPARE SUA FROTA! <<<\n", numJogador);

    for (int i = 0; i < QTD_NAVIOS; i++) {
        int tamanho;
        if (i == 0) tamanho = 4;
        else if (i == 1) tamanho = 3;
        else if (i >= 2 && i <= 4) tamanho = 1;
        else tamanho = 2;

        int posicaoValida = 0;

        while (posicaoValida == 0) {
            printf("\nNavio %d (Tamanho: %d)\n", i + 1, tamanho);
            printf("Digite a coordenada inicial (ex: A5): ");
            scanf("%s", jogada);

            int linha = jogada[0] - 'A';
            if (jogada[0] >= 'a' && jogada[0] <= 'z') linha = jogada[0] - 'a';
            int coluna = jogada[1] - '0';

            if (linha < 0 || linha > 9 || coluna < 0 || coluna > 9) {
                printf("Coordenada invalida! Use letras de A a J e numeros de 0 a 9.\n");
                continue;
            }

            if (tamanho > 1) {
                printf("Orientacao (H para Horizontal, V para Vertical): ");
                scanf(" %c", &orientacao);
                if (orientacao == 'h') orientacao = 'H';
                if (orientacao == 'v') orientacao = 'V';
            } else {
                orientacao = 'H';
            }

            int temErro = 0;
            for (int k = 0; k < tamanho; k++) {
                int linhaTeste = linha;
                int colTeste = coluna;

                if (orientacao == 'H') colTeste += k;
                if (orientacao == 'V') linhaTeste += k;

                if (linhaTeste > 9 || colTeste > 9) {
                    temErro = 1;
                } 
                else if (tabuleiro[linhaTeste][colTeste] != ' ') {
                    temErro = 1;
                }
            }

            if (temErro == 1) {
                printf("Posicao invalida! O navio sai do mapa ou sobrepoe outro. Tente de novo.\n");
            } else {
                for (int k = 0; k < tamanho; k++) {
                    if (orientacao == 'H') tabuleiro[linha][coluna + k] = 'N';
                    if (orientacao == 'V') tabuleiro[linha + k][coluna] = 'N';
                }
                posicaoValida = 1;
            }
        }
        
        char tabVazio[10][10];
        for(int x=0; x<10; x++) for(int y=0; y<10; y++) tabVazio[x][y] = ' ';
        desenharTela(tabuleiro, tabVazio, numJogador);
    }
    
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("FROTA POSICIONADA! PASSE A VEZ.\n");
}

int main() {
    char tabJogador1[10][10];
    char tabJogador2[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabJogador1[i][j] = ' ';
            tabJogador2[i][j] = ' ';
        }
    }

    posicionarNavios(tabJogador1, 1);
    posicionarNavios(tabJogador2, 2);

    int jogadorAtual = 1;
    char jogada[10];
    int jogoAtivo = 1;

while (jogoAtivo) {
        char (*meuTab)[10] = (jogadorAtual == 1) ? tabJogador1 : tabJogador2;
        char (*tabInimigo)[10] = (jogadorAtual == 1) ? tabJogador2 : tabJogador1;

        desenharTela(meuTab, tabInimigo, jogadorAtual);

        printf("Almirante Jogador %d, ordene o disparo (ex: F4): ", jogadorAtual);
        scanf("%s", jogada);

        int linha = jogada[0] - 'A';
        if (jogada[0] >= 'a' && jogada[0] <= 'z') linha = jogada[0] - 'a';
        int coluna = jogada[1] - '0';

        if (linha < 0 || linha > 9 || coluna < 0 || coluna > 9) {
            printf("\n=> Coordenada fora do mapa! Tente novamente.\n");
            continue; 
        }

        if (tabInimigo[linha][coluna] == 'X' || tabInimigo[linha][coluna] == '0') {
            printf("\n=> Voce ja disparou nessa coordenada! Escolha outro alvo.\n");
            continue;
        }

        if (tabInimigo[linha][coluna] == 'N') {
            printf("\n[ FOGO! ] Tiro certeiro! Voce ganhou um novo disparo.\n");
            tabInimigo[linha][coluna] = '0';
            
            int sobrouNavio = 0;
            for (int x = 0; x < 10; x++) {
                for (int y = 0; y < 10; y++) {
                    if (tabInimigo[x][y] == 'N') {
                        sobrouNavio = 1;
                    }
                }
            }

            if (sobrouNavio == 0) {
                desenharTela(meuTab, tabInimigo, jogadorAtual);
                printf("\n=======================================================\n");
                printf("  *** VITORIA ESTRATEGICA! O JOGADOR %d DESTRUIU A FROTA INIMIGA! ***\n", jogadorAtual);
                printf("=======================================================\n\n");
                jogoAtivo = 0;
            }
            continue; 
        } 
        else {
            printf("\n[ AGUA... ] O tiro acertou o mar.\n");
            tabInimigo[linha][coluna] = 'X'; // Erro vira 'X'
            
            jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
        }
    }

    return 0;
}