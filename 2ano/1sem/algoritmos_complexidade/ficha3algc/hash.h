#ifndef HASH_H
#define HASH_H

#define HASHSIZE 7 //número primo
#define EMPTY ""
#define DELETED "-"
#define KEYSIZE 9
typedef char KeyType[KEYSIZE];
typedef void *Info;




//Standard Hash Tables
// 
typedef struct entry {
  KeyType key;
  Info info;
} Entry, HashTable[HASHSIZE];

//Channing Hash Tables
//
typedef struct entryT2{
  KeyType key;
  Info info;
  struct entryT2 *next;
} EntryT2, *HashTableT2[HASHSIZE];

// Standard Hash Tables 
//
//Funtions Auxs
//
void printSHT (HashTable t);
//
//Linear Probing
//
int Hash(KeyType K);
void InitializeTable(HashTable t);
void ClearTable(HashTable t);
void InsertTable_LP(HashTable t, KeyType k, Info info);
void DeleteTable_LP(HashTable t, KeyType k);
int RetrieveTable_LP(HashTable t, KeyType k);
//
//Quadratic Probing
//
void InsertTable_QP(HashTable t, KeyType k, Info info);
void DeleteTable_QP(HashTable t, KeyType k);
int RetrieveTable_QP(HashTable t, KeyType k);
//END





//Channing Hash Tables
//
//Functions Aux
void printCHT(HashTableT2 t);
//
//
void InitializeTableT2(HashTableT2 t);
void ClearTableT2(HashTableT2 t);
void InsertTableT2(HashTableT2 t, KeyType k, Info info);
void DeleteTableT2(HashTableT2 t, KeyType k);
EntryT2 *RetrieveTableT2(HashTableT2 t, KeyType k);
//END
#endif 