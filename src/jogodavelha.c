#include <stdio.h>
#include <locale.h>
wchar_t matriz[3][3]; // matriz para o tabuleiro
int jogadas = 0; // contador de jogadas

// Fun��o para exibir o tabuleiro
void exibirTabuleiro() {
    int i, j;
    printf("\n--- Tabuleiro ---\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("-----------------\n");
}

// Fun��o para verificar se algu�m ganhou
int verificarVencedor() {
    int i;

    // Verificar linhas
    for (i = 0; i < 3; i++) {
        if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]) {
            if (matriz[i][0] == 'X') {
                return 1; // jogador 1 venceu
            } else if (matriz[i][0] == 'O') {
                return 2; // jogador 2 venceu
            }
        }
    }

    // Verificar colunas
    for (i = 0; i < 3; i++) {
        if (matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i]) {
            if (matriz[0][i] == 'X') {
                return 1; // jogador 1 venceu
            } else if (matriz[0][i] == 'O') {
                return 2; // jogador 2 venceu
            }
        }
    }

    // Verificar diagonais
    if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]) {
        if (matriz[0][0] == 'X') {
            return 1; // jogador 1 venceu
        } else if (matriz[0][0] == 'O') {
            return 2; // jogador 2 venceu
        }
    }
    if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0]) {
        if (matriz[0][2] == 'X') {
            return 1; // jogador 1 venceu
        } else if (matriz[0][2] == 'O') {
            return 2; // jogador 2 venceu
        }
    }

    return 0; // jogo em andamento
}

// Fun��o para realizar uma jogada
void fazerJogada(int jogador) {
    int linha, coluna;

    printf("Jogador %d, fa�a a sua jogada (linha e coluna): ", jogador);
    scanf("%d %d", &linha, &coluna);
    linha--;
    coluna--;
    if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
        printf("Jogada inv�lida! Tente novamente.\n");
        fazerJogada(jogador);
        return;
    }

    if (matriz[linha][coluna] != ' ') {
        printf("Essa posi��o j� est� ocupada! Tente novamente.\n");
        fazerJogada(jogador);
        return;
    }

    if (jogador == 1) {
        matriz[linha][coluna] = 'X';
    } else {
        matriz[linha][coluna] = 'O';
    }

    jogadas++;
}

// Fun��o para reiniciar o jogo
void reiniciarJogo() {
    int i, j;

    // Limpar o tabuleiro
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz[i][j] = ' ';
        }
    }

    jogadas = 0;
}

int main() {
    setlocale(LC_ALL, "");
    int jogador = 1;
    int vencedor = 0;
    int jogarNovamente = 1;

    while (jogarNovamente) {
        reiniciarJogo();

        // Loop principal do jogo
        while (1) {
            exibirTabuleiro();
            fazerJogada(jogador);
            vencedor = verificarVencedor();

            if (vencedor == 1) {
                exibirTabuleiro();
                printf("Parab�ns! Jogador 1 (X) venceu!\n");
                break;
            } else if (vencedor == 2) {
                exibirTabuleiro();
                printf("Parab�ns! Jogador 2 (O) venceu!\n");
                break;
            } else if (jogadas == 9) {
                exibirTabuleiro();
                printf("Empate! O jogo terminou sem vencedor.\n");
                break;
            }

            jogador = (jogador == 1) ? 2 : 1;
        }

        printf("Deseja jogar novamente? (1 - Sim, 0 - N�o): ");
        scanf("%d", &jogarNovamente);
    }

    return 0;
}
