#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
// #include "hashtable_array.h"


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

void insert(HashTable* ht, int key, void* data);

void search(HashTable* ht, int key) ;

void delete(HashTable* ht, int key);

void printTable(HashTable* ht);

void freeHashTable(HashTable* ht);





Element* createElement(int key, void* data) {
    Element* e = calloc(1, sizeof(Element));
    // assert(strlen(key) < MAX_CHAR);
    // strcpy(e->key, key);
    e->key = key;
    e->data = data;
    return e;
}

HashTable* createHashTable(int buckets, int slots) {
    HashTable* ht = malloc(sizeof(HashTable));
    ht->buckets = buckets;
    ht->slots = slots;
    ht->table = malloc(ht->buckets * sizeof(Element**));
    for (int i = 0; i < ht->buckets; i++) {
        ht->table[i] = calloc(ht->slots, sizeof(Element*));
    }
    return ht;
}

/**
 * simple additive approach to create a natural number that is within the integer range 
 * */
int transformKey(char* key) {
    int number = 0;
    while(*key) {
        number += *key++;
    }
    return number;
}

/** 
 * transform key to a natural number, and return this result modulus the table size
 * */
int hash(HashTable* ht, int key) {
    // return (transformKey(key) % ht->buckets);
    return (key % ht->buckets);
}

/**
 * Insert an element with linear probing strategy when collision occurs
 */
void insert(HashTable* ht, int key, void* data) {
    Element* e = createElement(key, data);
    int hash_value = hash(ht, e->key);
    int bucket = hash_value;
    int slot = 0;

    while(ht->table[bucket][slot] != NULL) {
        if (ht->table[bucket][slot]->key == e->key) {
            printf("Duplicate key\n");
            return;
        }
        slot++;
        if (slot == ht->slots) {
            slot = 0;
            bucket = (bucket + 1) % ht->buckets;
        }
        if (bucket == hash_value && slot == 0) {
            printf("Hash table is full\n");
            return;
        }
    }
    ht->table[bucket][slot] = e;
}

bool isIn(HashTable* ht, int key) {
    int hash_value = hash(ht, key);
    int bucket = hash_value;
    int slot = 0;

    while(ht->table[bucket][slot] != NULL) {
        if (ht->table[bucket][slot]->key == key) {
            return true;
        }
        slot++;
        if (slot == ht->slots) {
            slot = 0;
            bucket = (bucket + 1) % ht->buckets;
        }
        if (bucket == hash_value && slot == 0) {
            break;
        }
    }
    return false;
}

void* find(HashTable* ht, int key) {
    int hash_value = hash(ht, key);
    int bucket = hash_value;
    int slot = 0;

    while(ht->table[bucket][slot] != NULL) {
        if (ht->table[bucket][slot]->key == key) {
            return ht->table[bucket][slot]->data;
        }
        slot++;
        if (slot == ht->slots) {
            slot = 0;
            bucket = (bucket + 1) % ht->buckets;
        }
        if (bucket == hash_value && slot == 0) {
            break;
        }
    }
    return NULL;
}

void search(HashTable* ht, int key) {
    int hash_value = hash(ht, key);
    int bucket = hash_value;
    int slot = 0;

    while(ht->table[bucket][slot] != NULL) {
        if (ht->table[bucket][slot]->key == key) {
            printf("Key %d is found at bucket %d, slot %d\n", key, bucket, slot);
            return;
        }
        slot++;
        if (slot == ht->slots) {
            slot = 0;
            bucket = (bucket + 1) % ht->buckets;
        }
        if (bucket == hash_value && slot == 0) {
            break;
        }
    }
    printf("Key not found\n");
}

void delete(HashTable* ht, int key) {
    int hash_value = hash(ht, key);
    int bucket = hash_value;
    int slot = 0;

    while(ht->table[bucket][slot] != NULL) {
        if (ht->table[bucket][slot]->key == key) {
            // printf("Delete key: %d %d\n", bucket, slot);
            ht->table[bucket][slot] = NULL;
            int cur_bucket = bucket;
            int cur_slot = slot;
            int next_bucket = bucket;
            int next_slot = slot;
            while(1) {
                next_slot++;
                if (next_slot == ht->slots) {
                    next_slot = 0;
                    next_bucket = (next_bucket + 1) % ht->buckets;
                }
                Element* next_e = ht->table[next_bucket][next_slot];
                
                if (next_e == NULL || (next_bucket == bucket && next_slot == slot)) {
                    // printf("NULL position: %d %d\n", next_bucket, next_slot);
                    return;
                } else {
                    int next_hash = hash(ht, next_e->key);
                    if (next_hash == cur_bucket) {  /* correct bucket, move forward */
                        // printf("Correct bucket, wrong slot: %d %d, key: %d, need move forward\n", next_bucket, next_slot, next_e->key);
                        ht->table[cur_bucket][cur_slot] = ht->table[next_bucket][next_slot];
                        ht->table[next_bucket][next_slot] = NULL;
                        cur_bucket = next_bucket;
                        cur_slot = next_slot;
                        continue;
                    } else if (next_hash != cur_bucket && next_hash == next_bucket) {
                        // printf("Correct position: %d %d, key: %d\n", next_bucket, next_slot, next_e->key);
                        continue;
                    } else if (next_hash != cur_bucket && next_hash != next_bucket) {
                        if (cur_bucket == next_bucket) {
                            // printf("wrong bucket, wrong slot: %d %d, key: %d, need move forward\n", next_bucket, next_slot, next_e->key);
                            ht->table[cur_bucket][cur_slot] = ht->table[next_bucket][next_slot];
                            ht->table[next_bucket][next_slot] = NULL;
                            cur_bucket = next_bucket;
                            cur_slot = next_slot;
                            continue;
                        }
                        else if ((next_hash < cur_bucket && next_hash < next_bucket && next_bucket > cur_bucket) ||
                            (next_hash < cur_bucket && next_hash > next_bucket && next_bucket < cur_bucket) ||
                            (next_hash > cur_bucket && next_hash > next_bucket && next_bucket > cur_bucket)
                        ) {
                            // printf("wrong bucket, wrong slot: %d %d, key: %d, need move forward\n", next_bucket, next_slot, next_e->key);
                            ht->table[cur_bucket][cur_slot] = ht->table[next_bucket][next_slot];
                            ht->table[next_bucket][next_slot] = NULL;
                            cur_bucket = next_bucket;
                            cur_slot = next_slot;
                            continue;
                        } else {
                            // printf("wrong bucket, wrong slot: %d %d, key: %d, don't move\n", next_bucket, next_slot, next_e->key);
                            continue;
                        }
                    }
                }
            }
        }
        slot++;
        if (slot == ht->slots) {
            slot = 0;
            bucket = (bucket + 1) % ht->buckets;
        }
        if (bucket == hash_value && slot == 0) {
            break;
        }
    }
    printf("Key not found\n");
    return;
}

void printTable(HashTable* ht) {
    for (int i = 0; i < ht->buckets; i++) {
        printf("Bucket %2d: ", i);
        for (int j = 0; j < ht->slots; j++) {
            if (ht->table[i][j] != NULL) {
                printf("%5d ", ht->table[i][j]->key);
            } else {
                printf("%5s ", "NULL");
            }
        }
        printf("\n");
    }
}

void freeHashTable(HashTable* ht) {
    for (int i = 0; i < ht->buckets; i++) {
        for (int j = 0; j < ht->slots; j++) {
            if (ht->table[i][j] != NULL) {
                free(ht->table[i][j]);
            }
        }
        free(ht->table[i]);
    }
    free(ht->table);
    free(ht);
}
