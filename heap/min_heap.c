#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constants.h"
#include "min_heap.h"

MinHeap* createMinHeap() {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = INIT_HEAP_CAPACITY;
    heap->size = HEAP_START_INDEX;
    heap->arr = (int*)malloc(sizeof(int) * heap->capacity);
    return heap;
}

void insertMinHeap(MinHeap* heap, int key) {
    if (heap->size == heap->capacity && (heap->capacity * 2) < MAX_HEAP_CAPACITY) {
        heap->capacity *= 2;
        heap->arr = (int*)realloc(heap->arr, sizeof(int) * heap->capacity);
    }

    heap->arr[heap->size++] = key;
    
    int cur = heap->size - 1;
    while(cur >= 0 && heap->arr[PARENT(cur)] > heap->arr[cur]) {
        int temp = heap->arr[PARENT(cur)];
        heap->arr[PARENT(cur)] = heap->arr[cur];
        heap->arr[cur] = temp;
        cur = PARENT(cur);
    }
}

void deleteMinHeap(MinHeap* heap, int key) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return;
    }

    bool hasKey = false;
    int current;
    for (current = 0; current < heap->size; current++) {
        if (heap->arr[current] == key) {
            heap->arr[current] = heap->arr[heap->size - 1];
            heap->size--;
            hasKey = true;
            break;
        }
    }

    if (hasKey) {
        for (current; current >= 0; current--) {
            heapifyMinHeap(heap, current);
        }
    } else {
        printf("Key %d not found.\n", key);
    }
}

void heapifyMinHeap(MinHeap* heap, int rootIndex) {
    int key = heap->arr[rootIndex];
    int childIndex = LEFT(rootIndex);

    while (childIndex <= (heap->size - 1)) {
        if (childIndex < (heap->size - 1)) {
            if (heap->arr[childIndex] > heap->arr[childIndex + 1]) {
                childIndex++;   // right child is smaller
            }
        }

        if (key <= heap->arr[childIndex]) {
            break;
        } else {
            heap->arr[PARENT(childIndex)] = heap->arr[childIndex];
            childIndex = LEFT(childIndex);  // move to left child
        }
    }
    heap->arr[PARENT(childIndex)] = key;
}

void updateKeyMinHeap(MinHeap* heap, int oldKey, int newKey) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return;
    }

    bool hasKey = false;
    int current;
    for (current = 0; current < heap->size; current++) {
        if (heap->arr[current] == oldKey) {
            heap->arr[current] = newKey;
            hasKey = true;
            break;
        }
    }

    if (hasKey) {
        for (current; current >= 0; current--) {
            heapifyMinHeap(heap, current);
        }
    } else {
        printf("Key %d not found.\n", oldKey);
    }
}

int extractMinOfMinHeap(MinHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return 99999;
    }

    int min = heap->arr[HEAP_START_INDEX];
    deleteMinHeap(heap, min);
    return min;
}

int getMinOfMinHeap(MinHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return 99999;
    }
    return heap->arr[HEAP_START_INDEX];
}

void levelOrderTraversal(MinHeap* heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

void freeHeap(MinHeap* heap) {
    free(heap->arr);
    free(heap);
}