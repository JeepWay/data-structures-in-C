#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constants.h"
#include "max_heap.h"

MaxHeap* createMaxHeap() {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->capacity = INIT_HEAP_CAPACITY;
    heap->size = HEAP_START_INDEX;
    heap->arr = (int*)malloc(sizeof(int) * heap->capacity);
    return heap;
}

void insertMaxHeap(MaxHeap* heap, int key) {
    if (heap->size == heap->capacity && (heap->capacity * 2) < MAX_HEAP_CAPACITY) {
        heap->capacity *= 2;
        heap->arr = (int*)realloc(heap->arr, sizeof(int) * heap->capacity);
    }

    heap->arr[heap->size++] = key;
    
    int cur = heap->size - 1;
    while(cur >= 0 && heap->arr[PARENT(cur)] < heap->arr[cur]) {
        int temp = heap->arr[PARENT(cur)];
        heap->arr[PARENT(cur)] = heap->arr[cur];
        heap->arr[cur] = temp;
        cur = PARENT(cur);
    }
}

void deleteMaxHeap(MaxHeap* heap, int key) {
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
            heapifyMaxHeap(heap, current);
        }
    } else {
        printf("Key %d not found.\n", key);
    }
}

void heapifyMaxHeap(MaxHeap* heap, int rootIndex) {
    int key = heap->arr[rootIndex];
    int childIndex = LEFT(rootIndex);

    while (childIndex <= (heap->size - 1)) {
        if (childIndex < (heap->size - 1)) {
            if (heap->arr[childIndex] < heap->arr[childIndex + 1]) {
                childIndex++;   // right child is smaller
            }
        }

        if (key >= heap->arr[childIndex]) {
            break;
        } else {
            heap->arr[PARENT(childIndex)] = heap->arr[childIndex];
            childIndex = LEFT(childIndex);  // move to left child
        }
    }
    heap->arr[PARENT(childIndex)] = key;
}

void updateKeyMaxHeap(MaxHeap* heap, int oldKey, int newKey) {
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
            heapifyMaxHeap(heap, current);
        }
    } else {
        printf("Key %d not found.\n", oldKey);
    }
}

int extractMaxOfMaxHeap(MaxHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return -99999;
    }

    int max = heap->arr[HEAP_START_INDEX];
    deleteMaxHeap(heap, max);
    return max;
}

int getMaxOfMaxHeap(MaxHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return -99999;
    }
    return heap->arr[HEAP_START_INDEX];
}

void levelOrderTraversal(MaxHeap* heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

void freeHeap(MaxHeap* heap) {
    free(heap->arr);
    free(heap);
}