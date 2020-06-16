#include <stdio.h>
#include "infoNIB.h"

void acao(int op, char nib[]){
    switch (op)
    {
        case 1:
            ler(nib);
            break;
        case 2:
            banco(nib);
            break;
        case 3:
            nconta(nib);
            break;
        case 4:
            nContr(nib);
            break;
        case 5:
            form(nib);
            break;
        case 6:
            break;
        default:
            break;
    }
}

int main()
{
    int op;
    char nib[22];
    printf("/----------------------------------------------------------------\\\n");
    printf("|            Bem-vindo a caixa de informacoes bancaria           |\n");
    printf("\\----------------------------------------------------------------/");
    do {
        printf("\n\n               -- Que informacoes pretende obter? --          \n\n");
        printf("    -(1)-->  Ler o NIB                   Banco do NIB  <--(2)-\n");
        printf("    -(3)-->  Numeros de conta     Numeros de controlo  <--(4)-\n");
        printf("    -(5)-->  NIB Formatado            Validade do NIB  <--(6)-\n");
        printf("                                               Sair    <--(0)-\n");
        scanf("%d", &op);
        acao(op, nib);
    } while (op != 0);
    return 0;
}