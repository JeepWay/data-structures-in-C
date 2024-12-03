#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "int_min_heap.h"

MinHeap* createMinHeap() {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->capacity = INIT_HEAP_CAPACITY;
    h->size = HEAP_START_INDEX;
    h->arr = (int*)malloc(sizeof(int) * h->capacity);
    return h;
}

void insertMinHeap(MinHeap* h, int key) {
    if (h->size == h->capacity && (h->capacity * 2) < MAX_HEAP_CAPACITY) {
        h->capacity *= 2;
        h->arr = (int*)realloc(h->arr, sizeof(int) * h->capacity);
    }

    h->arr[h->size++] = key;
    
    int cur = h->size - 1;
    while(cur >= 0 && h->arr[PARENT(cur)] > h->arr[cur]) {
        SWAP(int, h->arr[PARENT(cur)], h->arr[cur]);
        cur = PARENT(cur);
    }
}

void deleteMinHeap(MinHeap* h, int key) {
    if (h->size == 0) {
        printf("Heap is empty.\n");
        return;
    }

    bool hasKey = false;
    int current;
    for (current = 0; current < h->size; current++) {
        if (h->arr[current] == key) {
            h->arr[current] = h->arr[h->size - 1];
            h->size--;
            hasKey = true;
            break;
        }
    }

    if (hasKey) {
        for (current; current >= 0; current--) {
            heapifyMinHeap(h, current);
        }
    } else {
        printf("Key %d not found.\n", key);
    }
}

void heapifyMinHeap(MinHeap* h, int rootIndex) {
    int key = h->arr[rootIndex];
    int childIndex = LEFT(rootIndex);

    while (childIndex <= (h->size - 1)) {
        if (childIndex < (h->size - 1)) {
            if (h->arr[childIndex] > h->arr[childIndex + 1]) {
                childIndex++;   // right child is smaller
            }
        }

        if (key <= h->arr[childIndex]) {
            break;
        } else {
            h->arr[PARENT(childIndex)] = h->arr[childIndex];
            childIndex = LEFT(childIndex);  // move to left child
        }
    }
    h->arr[PARENT(childIndex)] = key;
}

void updateKeyMinHeap(MinHeap* h, int oldKey, int newKey) {
    if (h->size == 0) {
        printf("Heap is empty.\n");
        return;
    }

    bool hasKey = false;
    int current;
    for (current = 0; current < h->size; current++) {
        if (h->arr[current] == oldKey) {
            h->arr[current] = newKey;
            hasKey = true;
            break;
        }
    }

    if (hasKey) {
        for (current; current >= 0; current--) {
            heapifyMinHeap(h, current);
        }
    } else {
        printf("Key %d not found.\n", oldKey);
    }
}

int extractMinOfMinHeap(MinHeap* h) {
    if (h->size == 0) {
        printf("Heap is empty.\n");
        return HEAP_EMPTY_VALUE;
    }

    int min = h->arr[HEAP_START_INDEX];
    deleteMinHeap(h, min);
    return min;
}

int getMinOfMinHeap(MinHeap* h) {
    if (h->size == 0) {
        printf("Heap is empty.\n");
        return HEAP_EMPTY_VALUE;
    }
    return h->arr[HEAP_START_INDEX];
}

void levelOrderTraversal(MinHeap* h) {
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

void freeHeap(MinHeap* h) {
    free(h->arr);
    free(h);
}

