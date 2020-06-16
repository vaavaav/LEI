#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "datastructures.h"

int main(){
    int structure;
    printf("-DATA STRUCTURES-\n");
    do{
        printf("\n(1) - Binary Trees\n(2) - Hash Tables\n(3) - Graphs\n(0) - Exit\n");
        printf(">structure: ");
        scanf("%d",&structure);
        switch(structure)
        {
        case 1:
            BT();
            break;
        case 2:
            hashing();
            break;
        case 3:
            graphs();
            break;
        default:
            break;
        }
    }while(structure);
    return 0;
}