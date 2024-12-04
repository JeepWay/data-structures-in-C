#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "general_deap.h"

Deap* createDeap() {
    Deap* h = (Deap*)malloc(sizeof(Deap));
    h->capacity = INIT_HEAP_CAPACITY;
    h->size = MIN_HEAP_START_INDEX;
    h->arr = (Element**)calloc(h->capacity, sizeof(Element*));
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

bool _isInMinHeap(Deap* h, int index) {
    int level = getLevel(index);
    // total nodes = 2^level - 1
    int max_index =((1 << level) - 1) - 1;
    int min_index = (1 << (level-1)) - 1;
    int half = (max_index - min_index + 1) / 2;
    if (index < min_index + half)
        return true;
    else
        return false;
}

int _getPartner(Deap* h, int index) {
    int level = getLevel(index);
    int max_index =((1 << level) - 1) - 1;
    int min_index = (1 << (level-1)) - 1;
    int half = (max_index - min_index + 1) / 2;
    if (index < min_index + half) {
        /* min heap, max partner*/
        if (index + half < h->size)
            return index + half;
        else
            return PARENT(index + half);    // no partner
    }
    else {
        /* max heap, min partner */
        if (index - half < h->size) 
            return index - half;
        else
            return PARENT(index - half);    // no partner
    }
}

void _minHeapInsert(Deap *h, int index) {
    while(index > MIN_HEAP_START_INDEX && h->arr[PARENT(index)]->key > h->arr[index]->key) {
        SWAP(Element*, h->arr[index], h->arr[PARENT(index)]);
        index = PARENT(index);
    }
}

void _maxHeapInsert(Deap *h, int index) {
    while(index > MAX_HEAP_START_INDEX && h->arr[PARENT(index)]->key < h->arr[index]->key) {
        SWAP(Element*, h->arr[index], h->arr[PARENT(index)]);
        index = PARENT(index);
    }
}

void insertDeap(Deap* h, Element* item) {
    if (h->size == h->capacity && (h->capacity * 2) < MAX_HEAP_CAPACITY) {
        h->capacity *= 2;
        h->arr = (Element**)realloc(h->arr, h->capacity * sizeof(Element*));
        for (int i = h->size; i < h->capacity; i++) {
            h->arr[i] = NULL;
        }
    }
    h->arr[h->size++] = item;

    if (h->size == 2)   
        return; /*  insert into empty deap */

    int cur = h->size - 1;
    if (!_isInMinHeap(h, cur)) {
        int partner = _getPartner(h, cur);
        // printf("%d %d %d\n", item->key, cur, partner);
        if (item->key < h->arr[partner]->key) {
            SWAP(Element*, h->arr[cur], h->arr[partner]);
            _minHeapInsert(h, partner);
        } else {
            _maxHeapInsert(h, cur);
        }
    } else {
        int partner = _getPartner(h, cur);
        // printf("%d %d %d\n", item->key, cur, partner);
        if (item->key > h->arr[partner]->key) {
            SWAP(Element*, h->arr[cur], h->arr[partner]);
            _maxHeapInsert(h, partner);
        } else {
            _minHeapInsert(h, cur);
        }
    }
}

void modifyInsertDeap(Deap* h, int cur) {
    if (!_isInMinHeap(h, cur)) {
        int partner = _getPartner(h, cur);
        if (h->arr[cur]->key < h->arr[partner]->key) {
            SWAP(Element*, h->arr[cur], h->arr[partner]);
            _minHeapInsert(h, partner);
        } else {
            _maxHeapInsert(h, cur);
        }
    } else {
        int partner = _getPartner(h, cur);
        if (h->arr[cur]->key > h->arr[partner]->key) {
            SWAP(Element*, h->arr[cur], h->arr[partner]);
            _maxHeapInsert(h, partner);
        } else {
            _minHeapInsert(h, cur);
        }
    }
}

Element* extractMinOfDeap(Deap* h) {
    if (h->size == 1)    return NULL;
    if (h->size == 2) {
        Element* min = h->arr[MIN_HEAP_START_INDEX];
        h->arr[MIN_HEAP_START_INDEX] = NULL;
        h->size--;
        return min;
    }
    Element* min = h->arr[MIN_HEAP_START_INDEX];
    Element* tmp = h->arr[h->size - 1];
    h->arr[h->size - 1] = NULL;
    h->size--;

    int cur = MIN_HEAP_START_INDEX;
    while(LEFT(cur) <= (h->size - 1)) {    /* cur has left child */
        int child = LEFT(cur);
        if (child < (h->size - 1)) { /* cur has right child */
            if (h->arr[child]->key > h->arr[child + 1]->key)
                child++;    /* right child is smaller */
        }
        h->arr[cur] = h->arr[child];
        h->arr[child] = NULL;
        cur = child;
    }

    h->arr[cur] = tmp;
    modifyInsertDeap(h, cur);
    return min;
}

Element* getMinOfDeap(Deap* h) {
    if (h->size == 1)    return NULL;
    return h->arr[MIN_HEAP_START_INDEX];
}

Element* extractMaxOfDeap(Deap* h) {
    if (h->size == 1)    return NULL;
    if (h->size == 2) {
        Element* max = h->arr[MIN_HEAP_START_INDEX];
        h->arr[MIN_HEAP_START_INDEX] = NULL;
        h->size--;
        return max;
    }
    Element* max = h->arr[MAX_HEAP_START_INDEX];
    Element* tmp = h->arr[h->size - 1];
    h->arr[h->size - 1] = NULL;
    h->size--;

    int cur = MAX_HEAP_START_INDEX;
    while(LEFT(cur) <= (h->size - 1)) {    /* cur has left child */
        int child = LEFT(cur);
        if (child < (h->size - 1)) { /* cur has right child */
            if (h->arr[child]->key < h->arr[child + 1]->key)
                child++;    /* right child is larger */
        }
        h->arr[cur] = h->arr[child];
        h->arr[child] = NULL;
        cur = child;
    }

    h->arr[cur] = tmp;
    modifyInsertDeap(h, cur);
    return max;
}

Element* getMaxOfDeap(Deap* h) {
    if (h->size == 1)    return NULL;
    if (h->size == 2)   return h->arr[1];
    return h->arr[MAX_HEAP_START_INDEX];
}

void levelOrderTraversal(Deap* h) {
    for (int i = MIN_HEAP_START_INDEX; i < h->size; i++) {
        printf("%d ", h->arr[i]->key);
    }
    printf("\n");
}

void freeDeap(Deap* h) {
    free(h->arr);
    free(h);
}

