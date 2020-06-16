//
// Created by Pedro on 20/02/2019.
//
#include <stdio.h>
#include <string.h>
#include "infoNIB.h"
void ler(char *nib){
    printf("Indique o seu NIB: ");
    scanf("%s", nib);
}

void banco(char *nib){
    char banco[4] = {nib[0], nib[1], nib[2], nib[3]};
    printf("\n   O seu Banco:    ");
    if((strcmp(banco, "0007")) == 0){
        printf("0007 - Novo Banco");
        return;
    }
    if(strcmp(banco, "0010") == 0) {
        printf("0010 - BPI");
        return;
    }
    if(strcmp(banco, "0018") == 0) {
        printf("0018 - Santander Totta");
        return;
    }
    if(strcmp(banco, "0019") == 0){
        printf ("0019 - BBVA");
        return;
    }
    if(strcmp(banco, "0023") == 0){
        printf ("0023 - Activo Bank");
        return;
    }
    if(strcmp(banco, "0025") == 0){
        printf ("0025 - Caixa BI");
        return;
    }
    if(strcmp(banco, "0032") == 0){
        printf ("0032 - Barclays");
        return;
    }
    if(strcmp(banco, "0033") == 0){
        printf ("0033 - Millennium BCP");
        return;
    }
    if(strcmp(banco, "0034") == 0){
        printf ("0034 - BNP Paribas");
        return;
    }
    if(strcmp(banco, "0035") == 0){
        printf ("0035 - CGD");
        return;
    }
    if(strcmp(banco, "0235") == 0){
        printf ("0235 - Banco Carregosa");
        return;
    }
    if(strcmp(banco, "0036") == 0){
        printf ("0036 - Montepio Geral");
        return;
    }
    if(strcmp(banco, "0038") == 0){
        printf ("0038 - Banif (passou para o Santander Totta - 0018)");
        return;
    }
    if(strcmp(banco, "0043") == 0){
        printf ("0043 - Deutsche Bank");
        return;
    }
    if(strcmp(banco, "0045") == 0){
        printf ("0045 - Crédito Agrícola");
        return;
    }
    if(strcmp(banco, "0046") == 0){
        printf ("0046 - Popular");
        return;
    }
    if(strcmp(banco, "0059") == 0){
        printf ("0059 - Caixa Económica da Misericórdia de Angra do Heroísmo");
        return;
    }
    if(strcmp(banco, "0061") == 0){
        printf ("0061 - Big");
        return;
    }
    if(strcmp(banco, "0065") == 0){
        printf ("0065 - Best");
        return;
    }
    if(strcmp(banco, "0079") == 0){
        printf ("0079 - BIC");
        return;
    }
    if(strcmp(banco, "0193") == 0){
        printf ("0193 - Banco CTT");
        return;
    }
    if(strcmp(banco, "0269") == 0){
        printf ("0269 - Bankinter");
        return;
    }
    if(strcmp(banco, "0781") == 0){
        printf ("0781 - Direcção Geral do Tesouro");
        return;
    }
    if(strcmp(banco, "5180") == 0){
        printf ("5180 - Caixa Central de Crédito Agrícola Mútuo");
        return;
    }

}

void nconta(char *nib){
    char numC[12];
    printf("\n    O numero da sua conta:    ");
    for(int i = 8; i < 19; i++)
        numC[i - 8] = nib[i];
    printf("%s\n", numC);
    printf("%d", numC);
}

void nContr(char nib[]){
    printf("\n    Os seus numeros de controlo sao:    ");
    printf("%c%c",nib[19],nib[20]);
}

void form(char *nib){
    int s = 0;
    printf("\nO seu NIB formatado:    ");
    for(int i = 0; i < 26; i++) {
        if (i == 4 || i == 9 || i == 14 || i == 19 || i == 23) {
            printf(" ");
            s++;
        }
        else
            printf("%c",nib[i - s]);
    }

}
