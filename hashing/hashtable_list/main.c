#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "hashtable_list.h"

void testDulpicateKey() {
    printf("-------- Start Test Duplicate Key --------\n");
    HashTable* ht = createHashTable();
    insert(ht, "1", NULL);
    insert(ht, "2", NULL);
    insert(ht, "1", NULL); /* Duplicate entry with key: 1 */
    freeHashTable(ht);
    printf("------------------------------------------\n\n");
}

void testKeysOfBuckets(){
    printf("------- Start Test Keys of Buckets -------\n");
    HashTable* ht = createHashTable();
    insert(ht, "1", NULL);
    insert(ht, "2", NULL);
    insert(ht, "14", NULL);
    insert(ht, "21", NULL);
    insert(ht, "3", NULL);
    insert(ht, "4", NULL);
    insert(ht, "5", NULL);
    insert(ht, "8", NULL);
    insert(ht, "22", NULL);
    printKeysOfBuckets(ht);
    /*
    Keys of bucket 0: 4
    Keys of bucket 1: 5
    Keys of bucket 2:
    Keys of bucket 3:
    Keys of bucket 4: 8
    Keys of bucket 5:
    Keys of bucket 6:
    Keys of bucket 7:
    Keys of bucket 8: 21
    Keys of bucket 9: 22
    Keys of bucket 10: 1 14
    Keys of bucket 11: 2
    Keys of bucket 12: 3
    */
    freeHashTable(ht);
    printf("------------------------------------------\n\n");
}

void testNumOfKeys() {
    printf("----- Start Test Num of Keys of Buckets -----\n");
    HashTable* ht = createHashTable();
    insert(ht, "1", NULL);
    insert(ht, "2", NULL);
    insert(ht, "14", NULL);
    insert(ht, "21", NULL);
    insert(ht, "3", NULL);
    insert(ht, "4", NULL);
    insert(ht, "5", NULL);
    insert(ht, "8", NULL);
    insert(ht, "22", NULL);
    printNumberOfKeysOfBuckets(ht);
    /*
    Bucket 0 has 1 keys
    Bucket 1 has 1 keys
    Bucket 2 has 0 keys
    Bucket 3 has 0 keys
    Bucket 4 has 1 keys
    Bucket 5 has 0 keys
    Bucket 6 has 0 keys
    Bucket 7 has 0 keys
    Bucket 8 has 1 keys
    Bucket 9 has 1 keys
    Bucket 10 has 2 keys
    Bucket 11 has 1 keys
    Bucket 12 has 1 keys
    */
    freeHashTable(ht);
    printf("---------------------------------------------\n\n");
}

void test_find() {
    printf("----- Start Test Find -----\n");
    HashTable* ht = createHashTable();
    insert(ht, "1", "data1");
    insert(ht, "2", "data2");
    insert(ht, "14", "data14");
    insert(ht, "21", "data21");
    insert(ht, "3", "data3");
    insert(ht, "4", "data4");
    insert(ht, "5", "data5");
    insert(ht, "8", "data8");
    insert(ht, "22", "data22");

    assert(strcmp((char*)find(ht, "1"), "data1") == 0);
    assert(strcmp((char*)find(ht, "2"), "data2") == 0);
    assert(strcmp((char*)find(ht, "14"), "data14") == 0);
    assert(strcmp((char*)find(ht, "21"), "data21") == 0);
    assert(strcmp((char*)find(ht, "3"), "data3") == 0);
    assert((char*)find(ht, "6") == NULL);
    assert((char*)find(ht, "7") == NULL);
    assert((char*)find(ht, "10") == NULL);

    printf("Key 1: %s\n", (char*)find(ht, "1"));
    printf("Key 22: %s\n", (char*)find(ht, "22"));
    freeHashTable(ht);
    printf("---------------------------\n\n");
}

void test_isIn_and_delete() {
    printf("----- Start Test inIn and Delete -----\n");
    HashTable* ht = createHashTable();
    insert(ht, "1", NULL);
    insert(ht, "2", NULL);
    insert(ht, "14", NULL);
    insert(ht, "21", NULL);
    insert(ht, "3", NULL);
    insert(ht, "4", NULL);
    insert(ht, "5", NULL);
    insert(ht, "8", NULL);
    insert(ht, "22", NULL);

    assert(isIn(ht, "1") == true);
    assert(isIn(ht, "2") == true);
    assert(isIn(ht, "14") == true);
    assert(isIn(ht, "21") == true);
    assert(isIn(ht, "3") == true);
    assert(isIn(ht, "6") == false);
    assert(isIn(ht, "7") == false);
    assert(isIn(ht, "10") == false);

    if (isIn(ht, "1")) {
        delete(ht, "1");
    }
    assert(isIn(ht, "1") == false);

    printKeysOfBuckets(ht);
    /*
    Keys of bucket 0: 4
    Keys of bucket 1: 5
    Keys of bucket 2:
    Keys of bucket 3:
    Keys of bucket 4: 8
    Keys of bucket 5:
    Keys of bucket 6:
    Keys of bucket 7:
    Keys of bucket 8: 21
    Keys of bucket 9: 22
    Keys of bucket 10: 14
    Keys of bucket 11: 2
    Keys of bucket 12: 3
    */
    freeHashTable(ht);
    printf("--------------------------------------\n\n");
}

int main() {
    testDulpicateKey();
    testKeysOfBuckets();
    testNumOfKeys();
    test_find();
    test_isIn_and_delete();
    return 0;
}