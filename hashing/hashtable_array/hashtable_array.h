#ifndef HASHTABLE_H
#define HASHTABLE_H

#define MAX_CHAR 20     /* maxium identifier size */

typedef struct {
    // char key[MAX_CHAR];
    int key;
    void* data;
} Element;

Element* createElement(int key, void* data);

typedef struct {
    int buckets;
    int slots;
    Element*** table;
} HashTable;

HashTable* createHashTable(int buckets, int slots);

int transformKey(char* key);

int hash(HashTable* ht, int key);

/**
 * insert the key and data into the hash table, if collision occurs, use linear probing to find the next available slot
 */
void insert(HashTable* ht, int key, void* data);

/**
 * return true if the key is in the hash table, otherwise return false
 */
bool isIn(HashTable* ht, int key);

/**
 * return the data of the key, if not found, return NULL
 */
void* find(HashTable* ht, int key);

/**
 * printf the location of the key in the hash table, if not found, print "Key not found"
 */
void search(HashTable* ht, int key) ;

/**
 * delete the key from the hash table, and then forward the next following element to the correct position due to linear probing
 */
void delete(HashTable* ht, int key);

void printTable(HashTable* ht);

void freeHashTable(HashTable* ht);

#endif