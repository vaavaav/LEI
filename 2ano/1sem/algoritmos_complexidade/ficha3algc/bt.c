#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "avltrees.h"

int BT(){
    int BT, controlo, input;
    AVLTree avl;
    printf("-BINARY TREES-\n\n");
    do{
        printf("Binary Trees:\n(1) - Standard (NOT AVAILABLE)\n(2) - AVLTrees\n(0) - Return\n");
        printf("\n>type:");
        scanf("%d",&BT);
        if(BT == 1){                          
            printf("Commands:\n(1) - Print Tree on Screen\n(2) - Insert Node In Tree\n(3) - Delete Node from Tree\n(0) - Clear Tree and Return\n");
            do{ 
                printf("\n>command:");
                scanf("%d",&controlo);  
                printf("\n");
                switch(controlo){
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 0:
                        break;
                    default:
                        break;
                }
            }while(controlo);
        }
        else if(BT == 2){                 
            avl = NULL;
            printf("Commands:\n(1) - Print Tree on Screen\n(2) - Insert Node In Tree\n(3) - Delete Node from Tree\n(0) - Clear Tree and Return\n");
            do{ 
                printf("\n>command:");
                scanf("%d",&controlo);
                printf("\n");
                switch(controlo){
                    case 1:
                        printTree(avl);
                        break;
                    case 2:
                        printf("Input:");
                        scanf("%d", &input);
                        avl = insertAVL(avl,input);
                        break;
                    case 3:
                        printf("Input:");
                        scanf("%d", &input);
                        avl = deleteAVL(avl,input);
                        break;
                    case 0:
                        clearAVL(avl);
                        break;
                    default:
                        break;
                }
            }while(controlo);
        }
    }while(BT);
    return 0;
}
