#ifndef HASHTABLE_H
#define HASHTABLE_H

#define MAX_CHAR 20     /* maxium identifier size */
#define TABLE_SIZE 13   /* prime number */

typedef struct element{
    char key[MAX_CHAR];
    void* data;
    struct element* next;
} Element;

Element* createElement(char* key, void* data);

typedef struct {
    int size;
    Element** table;
} HashTable;

HashTable* createHashTable();

int transformKey(char* key);

int hash(char* key);

void insert(HashTable* ht, char* key, void* data);

bool isIn(HashTable* ht, char* key);

void* find(HashTable* ht, char* key);

void delete(HashTable* ht, char* key);

void printKeysOfBuckets(HashTable* ht);

void printNumberOfKeysOfBuckets(HashTable* ht);

void freeHashTable(HashTable* ht);

#endif