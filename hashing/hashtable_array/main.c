#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "hashtable_array.h"

#define BUCKETS 10
#define SLOTS 2

void test_insert_case1() {
    printf("----- Start Test Insert Case1 -----\n");
    HashTable* ht = createHashTable(BUCKETS, SLOTS);
    insert(ht, 1, "data1");
    insert(ht, 2, "data2");
    insert(ht, 3, "data3");
    insert(ht, 4, "data4");
    insert(ht, 8, "data8");
    insert(ht, 9, "data9");
    insert(ht, 10, "data10");
    insert(ht, 11, "data11");
    printTable(ht);
    /*
    Bucket  0:    10  NULL
    Bucket  1:     1    11
    Bucket  2:     2  NULL
    Bucket  3:     3  NULL
    Bucket  4:     4  NULL
    Bucket  5:  NULL  NULL
    Bucket  6:  NULL  NULL
    Bucket  7:  NULL  NULL
    Bucket  8:     8  NULL
    Bucket  9:     9  NULL
    */
    freeHashTable(ht);
    printf("-----------------------------------\n\n");
}

void test_insert_case2() {
    printf("----- Start Test Insert Case2 -----\n");
    HashTable* ht = createHashTable(BUCKETS, SLOTS);
    insert(ht, 1, "data1");
    insert(ht, 2, "data2");
    insert(ht, 3, "data3");
    insert(ht, 4, "data4");
    insert(ht, 8, "data8");
    insert(ht, 9, "data9");
    insert(ht, 10, "data10");
    insert(ht, 11, "data11");
    insert(ht, 21, "data21");
    insert(ht, 19, "data19");
    insert(ht, 29, "data29");
    insert(ht, 39, "data39");
    printTable(ht);
    /*
    Bucket  0:    10    29
    Bucket  1:     1    11
    Bucket  2:     2    21 
    Bucket  3:     3    39
    Bucket  4:     4  NULL
    Bucket  5:  NULL  NULL
    Bucket  6:  NULL  NULL
    Bucket  7:  NULL  NULL
    Bucket  8:     8  NULL
    Bucket  9:     9    19
    */
    freeHashTable(ht);
    printf("-----------------------------------\n\n");
}

void test_delete_case1() {
    printf("----- Start Test Delete Case1 -----\n");
    HashTable* ht = createHashTable(BUCKETS, SLOTS);
    insert(ht, 1, "data1");
    insert(ht, 2, "data2");
    insert(ht, 3, "data3");
    insert(ht, 4, "data4");
    insert(ht, 8, "data8");
    insert(ht, 9, "data9");
    insert(ht, 10, "data10");
    insert(ht, 11, "data11");
    insert(ht, 21, "data21");
    insert(ht, 19, "data19");
    insert(ht, 29, "data29");
    insert(ht, 39, "data39");
    delete(ht, 9);
    printTable(ht);
    /*
    Bucket  0:    10    39 
    Bucket  1:     1    11 
    Bucket  2:     2    21 
    Bucket  3:     3  NULL 
    Bucket  4:     4  NULL 
    Bucket  5:  NULL  NULL 
    Bucket  6:  NULL  NULL 
    Bucket  7:  NULL  NULL 
    Bucket  8:     8  NULL 
    Bucket  9:    19    29
    */
    freeHashTable(ht);
    printf("-----------------------------------\n\n");
}

void test_delete_case2() {
    printf("----- Start Test Delete Case2 -----\n");
    HashTable* ht = createHashTable(BUCKETS, SLOTS);
    insert(ht, 1, "data1");
    insert(ht, 2, "data2");
    insert(ht, 3, "data3");
    insert(ht, 4, "data4");
    insert(ht, 8, "data8");
    insert(ht, 9, "data9");
    insert(ht, 10, "data10");
    insert(ht, 11, "data11");
    insert(ht, 21, "data21");
    insert(ht, 19, "data19");
    insert(ht, 29, "data29");
    insert(ht, 39, "data39");
    delete(ht, 10);
    printTable(ht);
    /*
    Bucket  0:    29    39
    Bucket  1:     1    11
    Bucket  2:     2    21 
    Bucket  3:     3  NULL
    Bucket  4:     4  NULL
    Bucket  5:  NULL  NULL
    Bucket  6:  NULL  NULL
    Bucket  7:  NULL  NULL
    Bucket  8:     8  NULL
    Bucket  9:     9    19
    */
    freeHashTable(ht);
    printf("-----------------------------------\n\n");
}

void test_delete_case3() {
    printf("----- Start Test Delete Case3 -----\n");
    HashTable* ht = createHashTable(BUCKETS, SLOTS);
    insert(ht, 1, "data1");
    insert(ht, 2, "data2");
    insert(ht, 3, "data3");
    insert(ht, 4, "data4");
    insert(ht, 8, "data8");
    insert(ht, 9, "data9");
    insert(ht, 10, "data10");
    insert(ht, 11, "data11");
    insert(ht, 21, "data21");
    insert(ht, 19, "data19");
    insert(ht, 29, "data29");
    insert(ht, 39, "data39");
    delete(ht, 19);
    printTable(ht);
    /*
    Bucket  0:    10    39
    Bucket  1:     1    11
    Bucket  2:     2    21 
    Bucket  3:     3  NULL
    Bucket  4:     4  NULL
    Bucket  5:  NULL  NULL
    Bucket  6:  NULL  NULL
    Bucket  7:  NULL  NULL
    Bucket  8:     8  NULL
    Bucket  9:     9    29
    */
    freeHashTable(ht);
    printf("-----------------------------------\n\n");
}

void test_delete_case4() {
    printf("----- Start Test Delete Case4 -----\n");
    HashTable* ht = createHashTable(BUCKETS, SLOTS);
    insert(ht, 1, "data1");
    insert(ht, 2, "data2");
    insert(ht, 3, "data3");
    insert(ht, 4, "data4");
    insert(ht, 8, "data8");
    insert(ht, 9, "data9");
    insert(ht, 10, "data10");
    insert(ht, 11, "data11");
    insert(ht, 21, "data21");
    insert(ht, 19, "data19");
    insert(ht, 29, "data29");
    insert(ht, 39, "data39");
    delete(ht, 1);
    printTable(ht);
    /*
    Bucket  0:    10    29
    Bucket  1:    11    21
    Bucket  2:     2    39 
    Bucket  3:     3  NULL
    Bucket  4:     4  NULL
    Bucket  5:  NULL  NULL
    Bucket  6:  NULL  NULL
    Bucket  7:  NULL  NULL
    Bucket  8:     8  NULL
    Bucket  9:     9    19
    */
    freeHashTable(ht);
    printf("-----------------------------------\n\n");
}

void test_search_case1() {
    printf("------- Start Test Search Case1 -------\n");
    HashTable* ht = createHashTable(BUCKETS, SLOTS);
    insert(ht, 1, "data1");
    insert(ht, 2, "data2");
    insert(ht, 3, "data3");
    insert(ht, 4, "data4");
    insert(ht, 8, "data8");
    insert(ht, 9, "data9");
    insert(ht, 10, "data10");
    insert(ht, 11, "data11");
    insert(ht, 21, "data21");
    insert(ht, 19, "data19");
    insert(ht, 29, "data29");
    insert(ht, 39, "data39");
    search(ht, 21);
    // Key 21 is found at bucket 2, slot 1
    search(ht, 39);
    // Key 39 is found at bucket 3, slot 1
    search(ht, 9);
    // Key 9 is found at bucket 9, slot 0
    printTable(ht);
    /*
    Bucket  0:    10    29
    Bucket  1:     1    11
    Bucket  2:     2    21 
    Bucket  3:     3    39
    Bucket  4:     4  NULL
    Bucket  5:  NULL  NULL
    Bucket  6:  NULL  NULL
    Bucket  7:  NULL  NULL
    Bucket  8:     8  NULL
    Bucket  9:     9    19
    */
    freeHashTable(ht);
    printf("---------------------------------------\n\n");
}

void test_isIn_case1() {
    printf("------- Start Test IsIn Case1 -------\n");
    HashTable* ht = createHashTable(BUCKETS, SLOTS);
    insert(ht, 1, "data1");
    insert(ht, 2, "data2");
    insert(ht, 3, "data3");
    insert(ht, 4, "data4");
    insert(ht, 8, "data8");
    insert(ht, 9, "data9");
    insert(ht, 10, "data10");
    insert(ht, 11, "data11");
    insert(ht, 21, "data21");
    insert(ht, 19, "data19");
    insert(ht, 29, "data29");
    insert(ht, 39, "data39");
    assert(isIn(ht, 21) == true);
    assert(isIn(ht, 39) == true);
    assert(isIn(ht, 9) == true);
    assert(isIn(ht, 100) == false);
    assert(isIn(ht, 0) == false);
    assert(isIn(ht, 6) == false);
    printTable(ht);
    /*
    Bucket  0:    10    29
    Bucket  1:     1    11
    Bucket  2:     2    21 
    Bucket  3:     3    39
    Bucket  4:     4  NULL
    Bucket  5:  NULL  NULL
    Bucket  6:  NULL  NULL
    Bucket  7:  NULL  NULL
    Bucket  8:     8  NULL
    Bucket  9:     9    19
    */
    freeHashTable(ht);
    printf("---------------------------------------\n\n");
}

void test_find_case1() {
    printf("------- Start Test Find Case1 -------\n");
    HashTable* ht = createHashTable(BUCKETS, SLOTS);
    insert(ht, 1, "data1");
    insert(ht, 2, "data2");
    insert(ht, 3, "data3");
    insert(ht, 4, "data4");
    insert(ht, 8, "data8");
    insert(ht, 9, "data9");
    insert(ht, 10, "data10");
    insert(ht, 11, "data11");
    insert(ht, 21, "data21");
    insert(ht, 19, "data19");
    insert(ht, 29, "data29");
    insert(ht, 39, "data39");
    assert(strcmp((char*)find(ht, 21), "data21") == 0);
    assert(strcmp((char*)find(ht, 39), "data39") == 0);
    assert(strcmp((char*)find(ht, 9), "data9") == 0);
    assert(find(ht, 100) == NULL);
    assert(find(ht, 0) == NULL);
    assert(find(ht, 6) == NULL);
    printTable(ht);
    /*
    Bucket  0:    10    29
    Bucket  1:     1    11
    Bucket  2:     2    21 
    Bucket  3:     3    39
    Bucket  4:     4  NULL
    Bucket  5:  NULL  NULL
    Bucket  6:  NULL  NULL
    Bucket  7:  NULL  NULL
    Bucket  8:     8  NULL
    Bucket  9:     9    19
    */
    freeHashTable(ht);
    printf("---------------------------------------\n\n");
}

int main() {
    test_insert_case1();
    test_insert_case2();
    test_delete_case1();
    test_delete_case2();
    test_delete_case3();
    test_delete_case4();
    test_search_case1();
    test_isIn_case1();
    test_find_case1();
    return 0;
}