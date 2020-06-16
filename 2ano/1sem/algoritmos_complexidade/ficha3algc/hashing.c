#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int hashing(){
    HashTable t;
    HashTableT2 t2;
    int controlo, mode, HT; 
    char key[KEYSIZE];



    printf("-HASH TABLES-\n\n");
    do{
        printf("HashTable Type:\n(1) - Standard\n(2) - Channing\n(0) - Return\n");
        printf("\n>type:");
        scanf("%d",&HT);
        if(HT == 1){                          //Standard Hash Table 
            InitializeTable(t);
            do{
                printf("Mode:\n(1) - Linear Probing\n(2) - Quadratic Probing\n(0) - Return\n");
                printf("\n>mode:");
                scanf("%d",&mode);            //"mode" controls Linear and Quadratic uses of the table. Can only be switched after exiting this section
                if(mode){                     //Avoiding to progress even if chosen to exit 
                    printf("Commands:\n(1) - Print Table on Screen\n(2) - Insert Key In Hash Table\n(3) - Retrieve Index of Key in Hash Table\n(4) - Delete Key from Hash Table\n(0) - Clear Table and Return\n");
                    do{ 
                        printf("\n>command:");
                        scanf("%d",&controlo);  
                        printf("\n");
                        switch(controlo){
                            case 1:
                                printSHT(t);
                                break;
                            case 2:
                                printf("Key:");
                                scanf("%s", key);
                                if(mode == 1)   
                                    InsertTable_LP(t,key,NULL);
                                else
                                    InsertTable_QP(t,key,NULL);
                                break;
                            case 3:
                                printf("Key:");
                                scanf("%s", key);
                                printf("Key \"%s\" has index: %d\n", key, (mode == 1) ? RetrieveTable_LP(t,key) : RetrieveTable_QP(t,key));
                                break;
                            case 4:
                               printf("Key:");
                                scanf("%s", key);
                                if(mode == 1) 
                                    DeleteTable_LP(t,key);
                                else
                                    DeleteTable_QP(t,key);
                                break;
                            case 0:
                                printf("Clearing Table...\n");
                                ClearTable(t);
                            default:
                                break;
                        }
                    }while(controlo);
                }
            }while(mode);
        }
        else if(HT == 2){                       //Channing Hash Tables
            InitializeTableT2(t2);
            printf("Commands:\n(1) - Print Table on Screen\n(2) - Insert Key In Hash Table\n(3) - Retrieve Address of Key in Hash Table\n(4) - Delete Key from Hash Table\n(0) - Clear Table and Return\n");
            do{ 
                printf("\n>command:");
                scanf("%d",&controlo);
                printf("\n");
                switch(controlo){
                    case 1:
                        printCHT(t2);
                        break;
                    case 2:
                        printf("Key:");
                        scanf("%s", key);
                        InsertTableT2(t2,key,NULL);
                        break;
                    case 3:
                        printf("Key:");
                        scanf("%s", key);
                        printf("Key \"%s\" has address: %d\n", key, RetrieveTableT2(t2,key));
                        break;
                    case 4:
                        printf("Key:");
                        scanf("%s", key);
                        DeleteTableT2(t2,key);
                        break;
                    case 0:
                        printf("Clearing Table...\n");
                        ClearTableT2(t2);
                    default:
                        break;
                }
            }while(controlo);
        }
    }while(HT);
    return 0;
}
