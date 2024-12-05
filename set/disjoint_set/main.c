#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "set.h"

void testUnionNormal() {
    Set* set = createSet(11);
    unionSetNormal(set, 1, 3);
    unionSetNormal(set, 2, 5);
    unionSetNormal(set, 4, 5);
    unionSetNormal(set, 10, 6);
    unionSetNormal(set, 10, 7);
    unionSetNormal(set, 10, 8);
    unionSetNormal(set, 10, 9);

    assert(countSetNumbers(set) == 4);
    assert(findSet(set, 3) == 1);
    assert(countSetNodes(set, 3) == 2);

    unionSetNormal(set, 10, 1);

    assert(countSetNumbers(set) == 3);
    assert(findSet(set, 3) == 10);
    assert(countSetNodes(set, 3) == 7);

    assert(findSet(set, 0) == 0);
    assert(countSetNodes(set, 0) == 1);
    freeSet(set);
}

void testUnionWeight() {
    Set* set = createSet(11);
    unionSetByWeight(set, 1, 2);
    unionSetByWeight(set, 1, 3);
    unionSetByWeight(set, 1, 4);
    unionSetByWeight(set, 1, 5);
    unionSetByWeight(set, 6, 1);
    unionSetByWeight(set, 7, 8);
    unionSetByWeight(set, 9, 7);
    unionSetByWeight(set, 7, 10);

    assert(countSetNumbers(set) == 3);
    assert(findSet(set, 1) == 1);
    assert(findSet(set, 6) == 1);
    assert(countSetNodes(set, 1) == 6);
    assert(countSetNodes(set, 1) == countSetNodes(set, 6));

    assert(findSet(set, 7) == 7);
    assert(findSet(set, 8) == 7);
    assert(findSet(set, 10) == 7);

    unionSetByWeight(set, 8, 1);

    assert(findSet(set, 8) == 1);
    assert(findSet(set, 1) != 8);
    assert(countSetNodes(set, 1) == 10);
    freeSet(set);
}

void testFindAndCompression() {
    Set* set = createSet(8);
    unionSetNormal(set, 0, 1);
    unionSetNormal(set, 2, 3);
    unionSetNormal(set, 0, 2);
    unionSetNormal(set, 4, 5);
    unionSetNormal(set, 6, 7);
    unionSetNormal(set, 4, 6);
    unionSetNormal(set, 0, 4);

    assert(countSetNumbers(set) == 1);
    assert(countSetNodes(set, 0) == 8);
    assert(countSetNodes(set, 4) == 8);

    assert(findSet(set, 6) == 0);
    assert( set->parent[6] == 4);
    assert(findSet(set, 7) == 0);
    assert( set->parent[7] == 6);
    printf("Parent of set 6: %d, Parent of set 7: %d\n", set->parent[6], set->parent[7]);   // 4, 6

    findSetAndCompress(set, 7);

    assert(findSet(set, 6) == 0);
    assert( set->parent[6] == 0);
    assert(findSet(set, 7) == 0);
    assert( set->parent[7] == 0);
    printf("Parent of set 6: %d, Parent of set 7: %d\n", set->parent[6], set->parent[7]);   // 0, 0
    freeSet(set);
}

int main() {
    testUnionNormal();
    testUnionWeight();
    testFindAndCompression();
    return 0;
}