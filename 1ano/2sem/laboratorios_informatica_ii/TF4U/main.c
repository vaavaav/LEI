#include <stdio.h>
#include <stdlib.h>

void Save(FILE *f, int L, int C, char tabuleiro[L][C]){
    int i, j;
    rewind(f);
    fprintf(f, "%d %d\n", L, C);
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++)
            fprintf(f, "%c ", tabuleiro[i][j]);
        fprintf(f, "\n");
    }
    printf("Changes saved with success.\n");
}


int main() {
    int isSaved = 1;
    int op;
    FILE *ficheiro;
    int L, C;
    int i, j;
    char newVal;

    ficheiro = fopen("tabuleiro.txt","r+");
    if(ficheiro == NULL) {
        printf("Erro!");
        exit(1);
    }
    fscanf(ficheiro,"%d %d\n", &L, &C);
    char tabuleiro[L][C];
    for(i = 0; i < L; i++)
        for(j = 0; j < C; j++)
            fscanf(ficheiro, "%c ", &tabuleiro[i][j]);
    do {
    printf("/--------------------------------------------------\\\n");
    printf("|                      Options                     |\n");
    printf("\\-------------------------------------------------/");
    printf("\n\n");
    printf("    -(1)-->  Show File     Change Value  <--(2)-\n");
    printf("    -(3)-->  Save File     Sair          <--(0)-\n");
    scanf("%d", &op);
        switch(op){
            case 1:
                printf("%d %d\n", L, C);
                for(i = 0; i < L; i++) {
                    for (j = 0; j < C; j++)
                        printf("%c", tabuleiro[i][j]);
                    printf("\n");
                }
                isSaved = 0;
                break;
            case 2:
                printf("<Line> <Colune> <NewValue>\n");
                scanf("%d %d %c",&i, &j, &newVal);
                tabuleiro[i-1][j-1] = newVal;
                isSaved = 0;
                break;
            case 3:
                if(isSaved)
                    printf("No changes to save.\n");
                else {
                    Save(ficheiro, L, C, tabuleiro);
                    isSaved = 1;
                }
                break;
            default:
                if(isSaved)
                    fclose(ficheiro);
                else {
                    printf(("     WARNING! Exit without saving?   \n"));
                    printf("    -(1)-->  YES           NO  <--(0)-\n");
                    scanf("%d", &isSaved);
                    if (1 - isSaved)
                        Save(ficheiro, L, C, tabuleiro);
                }
                printf("Exiting...");
                break;
        }
    } while (op != 0);
    return 0;
}