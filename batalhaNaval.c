#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

// Função para criar tabuleiro
void criarTabuleiro(char tabuleiro[TAM][TAM]) {
    int i, j;
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = '~';
        }
    }
}

// Função para imprimir tabuleiro
void imprimirTabuleiro(char tabuleiro[TAM][TAM]) {
    int i, j;
    printf("  ");
    for (j = 0; j < TAM; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (i = 0; i < TAM; i++) {
        printf("%d ", i);
        for (j = 0; j < TAM; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para jogar
void jogar(char tabuleiro[TAM][TAM], int *navios) {
    int i, j, x, y;
    printf("Informe coordenadas para atacar (x y): ");
    scanf("%d %d", &x, &y);
    if (tabuleiro[x][y] == '#') {
        printf("Posição já atacada!\n");
    } else if (tabuleiro[x][y] == 'N') {
        printf("Navio afundado!\n");
        navios[0]--;
        tabuleiro[x][y] = '#';
    } else {
        printf("Água!\n");
        tabuleiro[x][y] = '#';
    }
}

int main() {
    srand(time(NULL)); // Inicializar randomizador
    char tabuleiro[TAM][TAM];
    int navios[1] = {5}; // Número de navios
    criarTabuleiro(tabuleiro);
    
    // Posicionar navios aleatoriamente
    int i;
    for (i = 0; i < navios[0]; i++) {
        int x = rand() % TAM;
        int y = rand() % TAM;
        tabuleiro[x][y] = 'N';
    }
    
    while (navios[0] > 0) {
        imprimirTabuleiro(tabuleiro);
        jogar(tabuleiro, navios);
    }
    
    printf("Você venceu!\n");
    return 0;
}
