#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "general_min_max_heap.h"

MinMaxHeap* createMinMaxHeap() {
    MinMaxHeap* h = (MinMaxHeap*)malloc(sizeof(MinMaxHeap));
    h->capacity = INIT_HEAP_CAPACITY;
    h->size = HEAP_START_INDEX;
    h->arr =  (Element**)calloc(h->capacity, sizeof(Element*));
    return h;
}

int getLevel(int index) {
    int level = 1;  // root level
    while (index > 0) {
        index = PARENT(index);
        level++;
    }
    return level;
}

bool isMaxLevel(int index) {
    return getLevel(index) % 2 == 0;
}

void verifyMin(MinMaxHeap* h, int index, Element* item) {
    int gp = PARENT(PARENT(index));
    while (PARENT(index) != PARENT(PARENT(index)) && h->arr[gp]->key > item->key) {
        h->arr[index] = h->arr[gp];
        index = gp;
        gp = PARENT(PARENT(gp));
    }
    h->arr[index] = item;
}

void verifyMax(MinMaxHeap* h, int index, Element* item) {
    int gp = PARENT(PARENT(index));
    while(PARENT(index) != PARENT(PARENT(index)) && h->arr[gp]->key < item->key) {
        h->arr[index] = h->arr[gp];
        index = gp;
        gp = PARENT(PARENT(gp));
    }
    h->arr[index] = item;
    return;
}

int min_child_grandchild(MinMaxHeap* h, int index) {
    int min = index;
    int left = LEFT(index);
    int right = RIGHT(index);
    int left_child = left < h->size ? left : -1;
    int right_child = right < h->size ? right : -1;

    if (left_child != -1 && h->arr[left_child]->key < h->arr[min]->key) {
        min = left_child;
    }
    if (right_child != -1 && h->arr[right_child]->key < h->arr[min]->key) {
        min = right_child;
    }

    if (isMaxLevel(index)) 
        return min; // min child must be child, not grand_child, if index is in max level

    int left_left = LEFT(left);
    int left_right = RIGHT(left);
    int right_left = LEFT(right);
    int right_right = RIGHT(right);

    int left_left_child = left_left < h->size ? left_left : -1;
    int left_right_child = left_right < h->size ? left_right : -1;
    int right_left_child = right_left < h->size ? right_left : -1;
    int right_right_child = right_right < h->size ? right_right : -1;

    if (left_left_child != -1 && h->arr[left_left_child]->key < h->arr[min]->key) {
        min = left_left_child;
    }
    if (left_right_child != -1 && h->arr[left_right_child]->key < h->arr[min]->key) {
        min = left_right_child;
    }
    if (right_left_child != -1 && h->arr[right_left_child]->key < h->arr[min]->key) {
        min = right_left_child;
    }
    if (right_right_child != -1 && h->arr[right_right_child]->key < h->arr[min]->key) {
        min = right_right_child;
    }
    return min;
}

int max_child_grandchild(MinMaxHeap* h, int index) {
    int max = index;
    int left = LEFT(index);
    int right = RIGHT(index);
    int left_child = left < h->size ? left : -1;
    int right_child = right < h->size ? right : -1;

    if (left_child != -1 && h->arr[left_child]->key > h->arr[max]->key) {
        max = left_child;
    }
    if (right_child != -1 && h->arr[right_child]->key > h->arr[max]->key) {
        max = right_child;
    }

    if (!isMaxLevel(index)) 
        return max; // max child must be child, not grand_child, if index is in min level

    int left_left = LEFT(left);
    int left_right = RIGHT(left);
    int right_left = LEFT(right);
    int right_right = RIGHT(right);

    int left_left_child = left_left < h->size ? left_left : -1;
    int left_right_child = left_right < h->size ? left_right : -1;
    int right_left_child = right_left < h->size ? right_left : -1;
    int right_right_child = right_right < h->size ? right_right : -1;

    if (left_left_child != -1 && h->arr[left_left_child]->key > h->arr[max]->key) {
        max = left_left_child;
    }
    if (left_right_child != -1 && h->arr[left_right_child]->key > h->arr[max]->key) {
        max = left_right_child;
    }
    if (right_left_child != -1 && h->arr[right_left_child]->key > h->arr[max]->key) {
        max = right_left_child;
    }
    if (right_right_child != -1 && h->arr[right_right_child]->key > h->arr[max]->key) {
        max = right_right_child;
    }
    return max;
}

void insertMinMaxHeap(MinMaxHeap* h, Element* item) {
    if (h->size == h->capacity && (h->capacity * 2) < MAX_HEAP_CAPACITY) {
        h->capacity *= 2;
        h->arr = (Element**)realloc(h->arr, h->capacity * sizeof(Element*));
        for (int i = h->size; i < h->capacity; i++) {
            h->arr[i] = NULL;
        }
    }

    h->arr[h->size++] = item;
    int cur = h->size - 1;
    int parent = PARENT(cur);
    if (isMaxLevel(parent)) {
        if (item->key > h->arr[parent]->key) {
            h->arr[cur] = h->arr[parent];
            verifyMax(h, parent, item);
        } else {
            verifyMin(h, cur, item);
        }
    } else {
        if (item->key < h->arr[parent]->key) {
            h->arr[cur] = h->arr[parent];
            verifyMin(h, parent, item);
        } else {
            verifyMax(h, cur, item);
        }
    }
}

Element* extractMinOfMinMaxHeap(MinMaxHeap* h) {
    if (h->size == 0)   return NULL;

    Element* min = h->arr[HEAP_START_INDEX];
    Element* x = h->arr[h->size - 1];
    h->arr[h->size - 1] = NULL;
    h->size--;
    h->arr[HEAP_START_INDEX] = x;
    
    /* find place to insert x */
    int i, last;
    for (i = 0, last = PARENT(h->size-1); i <= last;) {
        int k = min_child_grandchild(h, i);
        if (x->key <= h->arr[k]->key)   
            break;
        else {  /* case 2(b) or 2(c) */
            h->arr[i] = h->arr[k];
            if (k <= RIGHT(i)) { /* case 2(b), k is a child of i */
                i = k;
                break;
            } else {    /* case 2(c), k is a grandchild of i */
                int parent = PARENT(k);
                if (x->key > h->arr[parent]->key)
                    SWAP(Element*, h->arr[parent], x);
                i = k;
            }
        }
    }
    h->arr[i] = x;
    return min;
}

Element* getMinOfMinMaxHeap(MinMaxHeap* h) {
    if (h->size == 0)    return NULL;
    return h->arr[HEAP_START_INDEX];
}

Element* extractMaxOfMinMaxHeap(MinMaxHeap* h) {
    if (h->size == 0)   return NULL;
    if (h->size == 1 || h->size == 2) {
        Element* max = h->arr[h->size - 1];
        h->arr[h->size - 1] = NULL;
        h->size--;
        return max;
    }

    int i = (h->arr[1]->key > h->arr[2]->key) ? 1 : 2;
    Element* max = h->arr[i];
    Element* x = h->arr[h->size - 1];
    h->arr[h->size - 1] = NULL;
    h->size--;
    h->arr[i] = x;

    /* find place to insert x */
    int last;
    for (i, last = PARENT(h->size-1); i <= last;) {
        int k = max_child_grandchild(h, i);
        if (x->key >= h->arr[k]->key)   
            break;
        else {  /* case 2(b) or 2(c) */
            h->arr[i] = h->arr[k];
            if (k <= RIGHT(i)) { /* case 2(b), k is a child of i */
                i = k;
                break;
            } else {    /* case 2(c), k is a grandchild of i */
                int parent = PARENT(k);
                if (x->key < h->arr[parent]->key)
                    SWAP(Element*, h->arr[parent], x);
                i = k;
            }
        }
    }
    h->arr[i] = x;
    return max;
}

Element* getMaxOfMinMaxHeap(MinMaxHeap* h) {
    if (h->size == 0)
        return NULL;
    if (h->size == 1 || h->size == 2)   
        return h->arr[h->size - 1];
    return h->arr[(h->arr[1]->key > h->arr[2]->key) ? 1 : 2];
}

void levelOrderTraversal(MinMaxHeap* heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]->key);
    }
    printf("\n");
}

void freeMinMaxHeap(MinMaxHeap* heap) {
    free(heap->arr);
    free(heap);
}

