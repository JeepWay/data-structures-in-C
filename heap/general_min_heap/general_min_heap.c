#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "general_min_heap.h"

MinHeap* createMinHeap() {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->capacity = INIT_HEAP_CAPACITY;
    h->size = HEAP_START_INDEX;
    h->arr =  (Element**)calloc(h->capacity, sizeof(Element*));
    return h;
}

void insertMinHeap(MinHeap* h, Element* item) {
    if (h->size == h->capacity && (h->capacity * 2) < MAX_HEAP_CAPACITY) {
        h->capacity *= 2;
        h->arr = (Element**)realloc(h->arr, h->capacity * sizeof(Element*));
        for (int i = h->size; i < h->capacity; i++) {
            h->arr[i] = NULL;
        }
    }

    h->arr[h->size++] = item;
    
    int cur = h->size - 1;
    while(cur >= 0 && h->arr[PARENT(cur)]->key > h->arr[cur]->key) {
        SWAP(Element*, h->arr[PARENT(cur)], h->arr[cur]);
        cur = PARENT(cur);
    }
}

void deleteMinHeap(MinHeap* h, int key) {
    if (h->size == 0) {
        printf("Heap is empty.\n");
        return;
    }

    bool hasKey = false;
    int cur;
    for (cur = 0; cur < h->size; cur++) {
        if (h->arr[cur]->key == key) {
            h->arr[cur] = h->arr[h->size - 1];
            h->size--;
            hasKey = true;
            break;
        }
    }

    if (hasKey) {
        for (cur; cur >= 0; cur--) {
            heapifyMinHeap(h, cur);
        }
    } else {
        printf("Key %d not found.\n", key);
    }
}

void updateKeyMinHeap(MinHeap* h, int oldKey, int newKey) {
    if (h->size == 0) {
        printf("Heap is empty.\n");
        return;
    }

    bool hasKey = false;
    int cur;
    for (cur = 0; cur < h->size; cur++) {
        if (h->arr[cur]->key == oldKey) {
            h->arr[cur]->key = newKey;
            hasKey = true;
            break;
        }
    }

    if (hasKey) {
        for (cur; cur >= 0; cur--) {
            heapifyMinHeap(h, cur);
        }
    } else {
        printf("Key %d not found.\n", oldKey);
    }
}

void heapifyMinHeap(MinHeap* h, int rootIndex) {
    Element* item = h->arr[rootIndex];
    int key = item->key;
    int childIndex = LEFT(rootIndex);

    while (childIndex <= (h->size - 1)) {
        if (childIndex < (h->size - 1)) {
            if (h->arr[childIndex]->key > h->arr[childIndex + 1]->key) {
                childIndex++;   // right child is smaller
            }
        }

        if (key <= h->arr[childIndex]->key) {
            break;
        } else {
            h->arr[PARENT(childIndex)] = h->arr[childIndex];
            childIndex = LEFT(childIndex);  // move to left child
        }
    }
    h->arr[PARENT(childIndex)] = item;
}

Element* extractMinOfMinHeap(MinHeap* h) {
    if (h->size == 0) {
        printf("Heap is empty.\n");
        return NULL;
    }

    Element* min = h->arr[HEAP_START_INDEX];
    deleteMinHeap(h, min->key);
    return min;
}

Element* getMinOfMinHeap(MinHeap* h) {
    if (h->size == 0) {
        printf("Heap is empty.\n");
        return NULL;
    }
    return h->arr[HEAP_START_INDEX];
}


void levelOrderTraversal(MinHeap* h) {
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->arr[i]->key);
    }
    printf("\n");
}

void freeHeap(MinHeap* h) {
    for (int i = 0; i < h->capacity; i++)
        free(h->arr[i]);
    free(h->arr);
    free(h);
}