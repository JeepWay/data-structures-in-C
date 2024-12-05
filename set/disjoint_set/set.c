#include <stdlib.h>
#include <stdbool.h>
#include "set.h"
#define max(x, y) (((x) > (y)) ? (x) : (y))

Set* createSet(int size) {
    Set* set = (Set*)malloc(sizeof(Set));
    set->size = size;
    set->parent = (int*)malloc(size * sizeof(int));
    set->count = (int*)malloc(size * sizeof(int));
    set->height = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        set->parent[i] = INIT_PARENT;
        set->count[i] = 1;
        set->height[i] = 1;
    }
    return set;
}

int findSet(Set* set, int x) {
    while(set->parent[x] != INIT_PARENT) {
        x = set->parent[x];
    }
    return x;
}

int findSetAndCompress(Set* set, int x) {
    if (set->parent[x] == INIT_PARENT) {
        return x;
    }
    set->parent[x] = findSetAndCompress(set, set->parent[x]);
    return set->parent[x];
}

void unionSetNormal(Set* set, int x, int y) {
    int rootX = findSet(set, x);
    int rootY = findSet(set, y);

    if (rootX == rootY) return;

    set->parent[rootY] = rootX;

    set->count[rootX] += set->count[rootY];
    set->count[rootY] = set->count[rootX];

    set->height[rootX] = max(set->height[rootX], 1 + set->height[rootY]);
    set->height[rootY] = set->height[rootX];
}

void unionSetByWeight(Set* set, int x, int y) {
    int rootX = findSet(set, x);
    int rootY = findSet(set, y);

    if (rootX == rootY) return;

    if (set->count[rootX] < set->count[rootY]) {
        set->parent[rootX] = rootY;
        set->count[rootY] += set->count[rootX];
        set->count[rootX] = set->count[rootY];
        set->height[rootY] = max(set->height[rootY], 1 + set->height[rootX]);
        set->height[rootX] = set->height[rootY];
    } else {
        set->parent[rootY] = rootX;
        set->count[rootX] += set->count[rootY];
        set->count[rootY] = set->count[rootX];
        set->height[rootX] = max(set->height[rootX], 1 + set->height[rootY]);
        set->height[rootY] = set->height[rootX];
    }
}

void unionSetByHeight(Set* set, int x, int y) {
    int rootX = findSet(set, x);
    int rootY = findSet(set, y);

    if (rootX == rootY) return;

    if (set->height[rootX] < set->height[rootY]) {
        set->parent[rootX] = rootY;
        set->count[rootY] += set->count[rootX];
        set->count[rootX] = set->count[rootY];
        set->height[rootY] = max(set->height[rootY], 1 + set->height[rootX]);
        set->height[rootX] = set->height[rootY];
    } else {
        set->parent[rootY] = rootX;
        set->count[rootX] += set->count[rootY];
        set->count[rootY] = set->count[rootX];
        set->height[rootX] = max(set->height[rootX], 1 + set->height[rootY]);
        set->height[rootY] = set->height[rootX];
    }
}

int countSetNodes(Set* set, int x) {
    int root = findSet(set, x);
    return set->count[root];
}

int countSetNumbers(Set* set) {
    int count = 0;
    for (int i = 0; i < set->size; i++) {
        if (set->parent[i] == INIT_PARENT) {
            count++;
        }
    }
    return count;
}

void freeSet(Set* set) {
    free(set->parent);
    free(set->count);
    free(set->height);
    free(set);
}