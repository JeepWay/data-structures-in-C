#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "hashtable_list.h"

Element* createElement(char* key, void* data) {
    Element* e = (Element*)malloc(sizeof(Element));
    assert(strlen(key) < MAX_CHAR);
    strcpy(e->key, key);
    e->data = data;
    e->next = NULL;
    return e;
}

HashTable* createHashTable() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = TABLE_SIZE;
    ht->table = (Element**)malloc(ht->size * sizeof(Element*));
    for (int i = 0; i < ht->size; i++) {
        ht->table[i] = (Element*)calloc(1, sizeof(Element));
        ht->table[i]->data = (int*)malloc(sizeof(int));
        *((int*)ht->table[i]->data) = 0;    /* used to store the number of keys in this bucket */
    }
    return ht;
}

int transformKey(char* key) {
    /* simple additive approach to create a natural number that is within the integer range */
    int number = 0;
    while(*key) {
        number += *key++;
    }
    return number;
}

int hash(char* key) {
    /* transform key to a natural number, and return this result modulus the table size */
    return (transformKey(key) % TABLE_SIZE);
}

void insert(HashTable* ht, char* key, void* data) {
    Element* e = createElement(key, data);
    int hash_value = hash(e->key);
    Element* cur = ht->table[hash_value];   /* head of the current bucket, as dummy node */
    
    while(cur->next != NULL) {
        if (strcmp(cur->next->key, e->key) == 0) {
            fprintf(stderr,"Duplicate entry with key: %s\n", e->key); 
            return;
        }
        cur = cur->next;
    }
    cur->next = e;
    *((int*)ht->table[hash_value]->data) += 1;
}

bool isIn(HashTable* ht, char* key) {
    int hash_value = hash(key);
    Element* cur = ht->table[hash_value]->next;
    while (cur) {
        if (strcmp(cur->key, key) == 0) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

void* find(HashTable* ht, char* key) {
    int hash_value = hash(key);
    Element* cur = ht->table[hash_value]->next;
    while (cur) {
        if (strcmp(cur->key, key) == 0) {
            return cur->data;
        }
        cur = cur->next;
    }
    return NULL;
}

void delete(HashTable* ht, char* key) {
    int hash_value = hash(key);
    Element* cur = ht->table[hash_value];
    while (cur->next) {
        if (strcmp(cur->next->key, key) == 0) {
            Element* temp = cur->next;
            cur->next = cur->next->next;
            free(temp);
            *((int*)ht->table[hash_value]->data) -= 1;
            return;
        }
        cur = cur->next;
    }
    fprintf(stderr, "Key not found: %s\n", key);
}

void printKeysOfBuckets(HashTable* ht) {
    for (int i = 0; i < ht->size; i++) {
        Element* cur = ht->table[i]->next;
        printf("Keys of bucket %d: ", i);
        while (cur) {
            printf("%s ", cur->key);
            cur = cur->next;
        }
        printf("\n");
    }
}

void printNumberOfKeysOfBuckets(HashTable* ht) {
    for (int i = 0; i < ht->size; i++) {
        printf("Bucket %d has %d keys\n", i, *((int*)ht->table[i]->data));
    }
}

void freeHashTable(HashTable* ht) {
    for (int i = 0; i < ht->size; i++) {
        Element* e = ht->table[i];
        while (e) {
            Element* temp = e;
            e = e->next;
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}
