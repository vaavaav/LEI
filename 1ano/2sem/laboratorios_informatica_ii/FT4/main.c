#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *ficheiro = fopen("tabuleiro.txt","r+");
    int L, C;
    if(ficheiro == NULL) {
        printf("Erro!");
        exit(1);
    }
    fscanf(ficheiro,"%d %d", &L, &C);
    char tabuleiro[L][C];
    int i,j;
    for(i = 0; i < L; i++)
        for(j = 0; j < C; j++)
            fscanf(ficheiro, "%c ", &tabuleiro[i][j]);


    printf("%d %d", L, C);
    for(i = 0; i < L; i++)
        printf("\n%s",tabuleiro[i]);

    return 0;
}