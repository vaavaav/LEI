#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"


//STANDARD HASH TABLE FUNCTIONS
//Funtions Auxs 
//

void printSHT (HashTable t){
    printf("<INDEX : KEY>\n\n");
    for(int i = 0; i < HASHSIZE; i++){
        if (!strcmp(t[i].key, EMPTY)) printf ("%d :  \n", i);
        else if (!strcmp(t[i].key, DELETED)) printf ("%d : -\n", i);
        else printf ("%d : %s\n", i, t[i].key);
    }
}


//Linear Probing
//

int Hash(KeyType k){
    int sum = 0, i;
    for(i = 0; i < KEYSIZE; i++){
        sum += k[i];
    }
    return(sum % HASHSIZE);
}

void InitializeTable(HashTable t){
    int i;
    for(i = 0; i < HASHSIZE; i++){
        strcpy(t[i].key, EMPTY);
        t[i].info = NULL; 
    }
}


void ClearTable(HashTable t){
    int i;
     for(i = 0; i < HASHSIZE; i++){
        strcpy(t[i].key, DELETED);
        t[i].info = NULL; 
    }
}


void InsertTable_LP(HashTable t, KeyType k, Info info){
    int p, r = 0;
    p = Hash(k);
    while(strcmp(t[p].key,EMPTY) && strcmp(t[p].key,DELETED) && r++ < HASHSIZE)
        p = (p+1)%HASHSIZE;
    if(r <= HASHSIZE){
        strcpy(t[p].key,k);
        t[p].info = info;

    }
}

void DeleteTable_LP(HashTable t, KeyType k){
    int p, r = 0;
    p = Hash(k);
    while(strcmp(t[p].key,k) && r++ < HASHSIZE)
        p = (p+1) % HASHSIZE;
    if(r <= HASHSIZE){
        strcpy(t[p].key, DELETED);
        t[p].info = NULL;
    }
}

int RetrieveTable_LP(HashTable t, KeyType k){
    int p, r = 0;
    p = Hash(k);
    while(strcmp(t[p].key,k) && strcmp(t[p].key,EMPTY) && r++ < HASHSIZE)
        p = (p+1)%HASHSIZE;
    if(r > HASHSIZE || strcmp(t[p].key,k))
        p = -1;
    return p;
}


//Quadratic Probing

int Hash_QP(KeyType k, int s){
    int sum = 0, i;
    for(i = 0; i < KEYSIZE; i++)
        sum += k[i];
    return ((sum + s) % HASHSIZE);
}

void InsertTable_QP(HashTable t, KeyType k, Info info){
    int p, s = 0, r = 0;
    p = Hash_QP(k,s);
    while(strcmp(t[p].key,EMPTY) && strcmp(t[p].key,DELETED) && r++ < HASHSIZE)
        p = Hash_QP(k,++s);
    if(r <= HASHSIZE){
        strcpy(t[p].key,k);
        t[p].info = info;
    }
}

void DeleteTable_QP(HashTable t, KeyType k){
    int p, s = 0, r = 0;
    p = Hash_QP(k,s);
    while(strcmp(t[p].key,k) && strcmp(t[p].key,EMPTY) && r++ < HASHSIZE)
       p = Hash_QP(k,++s);
    if(r <= HASHSIZE && strcmp(t[p].key,EMPTY)){
       strcpy(t[p].key,DELETED);
        t[p].info = NULL;
    }
}

int RetrieveTable_QP(HashTable t, KeyType k){
    int p, s = 0, r = 0;
    p = Hash_QP(k,s);
    while(strcmp(t[p].key,k) && strcmp(t[p].key,EMPTY) && r++ < HASHSIZE)
        p = Hash_QP(k,++s);
    if(r > HASHSIZE || strcmp(t[p].key,k))
        p = -1;    
    return p;
}
//END


//CHANNING HASH TABLE FUNCTIONS

void printCHT(HashTableT2 t){
    int i; 
    EntryT2 *aux;
    printf("<INDEX: KEY1 -> ... -> KEYN -> X (NULL)> \n\n");
    for(i = 0; i < HASHSIZE; i++){
        printf("%d: ",i);
        for(aux = t[i]; aux; aux = aux -> next)
            printf("%s -> ",aux->key);
        printf("X\n");
        
    }
}

void InitializeTableT2(HashTableT2 t){
    int i;
    for(i = 0; i < HASHSIZE; i++)
        t[i] = NULL;
}

void ClearTableT2(HashTableT2 t){
    int i; EntryT2 *aux , *ant;
    for(i = 0; i < HASHSIZE; i++){
        aux = t[i];
        while(aux != NULL){
            ant = aux;
            aux = ant -> next;
            free(ant);
        }
        t[i] = NULL;
    }
}

void InsertTableT2(HashTableT2 t, KeyType k, Info info){
    EntryT2 *aux, *ant; int p;
    p = Hash(k);
    aux = t[p];
    if(aux == NULL){
        t[p] = malloc(sizeof(EntryT2));
        strcpy(t[p]->key,k);
        t[p]->info = info;
        t[p]->next = NULL;
    
    }
    else{
        while(aux != NULL && strcmp(aux -> key, k)){
            ant = aux;
            aux = aux -> next;
        }
        if(aux == NULL){
            ant -> next = malloc(sizeof(EntryT2));
            aux = ant -> next;
            strcpy(aux->key,k);
            aux -> info = info;
            aux -> next = NULL;
        }
    }
}

void DeleteTableT2(HashTableT2 t, KeyType k){
    EntryT2 *aux, *ant; int p;
    p = Hash(k);
    aux = t[p];
    while(aux != NULL && strcmp(aux -> key,k)){
        ant = aux;
        aux = aux -> next;
    }
    if(aux != NULL){
        ant -> next = aux -> next;
        free(aux);
    }
}

EntryT2 *RetrieveTableT2(HashTableT2 t, KeyType k){
    EntryT2 *aux; int p; 
    p = Hash(k);
    aux = t[p];
    while(aux != NULL && strcmp(aux -> key,k))
        aux = aux -> next;
    return aux;
}

//END