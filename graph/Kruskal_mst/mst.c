#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "mst.h"

Edge* createEdge(int u, int v, int w) {
    Edge *e = malloc(sizeof(Edge));
    e->u = u;
    e->v = v;
    e->w = w;
    return e;
}

MinHeap* createMinHeap() {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = INIT_HEAP_CAPACITY;
    heap->size = START_INDEX;
    heap->edges = (Edge**)malloc(heap->capacity * sizeof(Edge*));
    for (int i = 0; i < heap->capacity; i++)
        heap->edges[i] = NULL;
    return heap;
}

void insertMinHeap(MinHeap* heap, Edge* e) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->edges = (Edge**)realloc(heap->edges, sizeof(Edge**) * heap->capacity);
    }

    heap->edges[heap->size++] = e;
    
    int cur = heap->size - 1;
    while(cur >= 0 && heap->edges[PARENT(cur)]->w > heap->edges[cur]->w) {
        SWAP(Edge*, heap->edges[PARENT(cur)], heap->edges[cur]);
        cur = PARENT(cur);
    }
}

Edge* extractMinOfMinHeap(MinHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return NULL;
    }

    Edge* min = heap->edges[START_INDEX];
    heap->edges[START_INDEX] = heap->edges[heap->size - 1];
    heap->size--;
    heapifyMinHeap(heap, START_INDEX);
    return min;
}

void heapifyMinHeap(MinHeap* heap, int rootIndex) {
    Edge* e = heap->edges[rootIndex];
    int childIndex = LEFT(rootIndex);

    while (childIndex <= (heap->size - 1)) {
        if (childIndex < (heap->size - 1)) {
            if (heap->edges[childIndex]->w > heap->edges[childIndex + 1]->w) {
                childIndex++;   // right child is smaller
            }
        }

        if (e->w <= heap->edges[childIndex]->w) {
            break;
        } else {
            heap->edges[PARENT(childIndex)] = heap->edges[childIndex];
            childIndex = LEFT(childIndex);  // move to left child
        }
    }
    heap->edges[PARENT(childIndex)] = e;
}

void levelOrderTraversal(MinHeap* heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d %d %d\n", heap->edges[i]->w, heap->edges[i]->u, heap->edges[i]->v);
    }
    printf("\n");
}

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

int findSetAndCompress(Set* set, int x) {
    if (set->parent[x] == INIT_PARENT) {
        return x;
    }
    set->parent[x] = findSetAndCompress(set, set->parent[x]);
    return set->parent[x];
}

void unionSetWeight(Set* set, int x, int y) {
    int rootX = findSetAndCompress(set, x);
    int rootY = findSetAndCompress(set, y);

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

Edge** findKruskalMST(int** G, int n, int *costs) {
    MinHeap *heap = createMinHeap();
    int edge_num = 0; 
    for (int i = 0; i < n; i++) {
        for (int j =  i + 1; j < n; j++) {
            if (G[i][j] != 0) {
                Edge* e = createEdge(i+1, j+1, G[i][j]);
                insertMinHeap(heap, e);
                edge_num++;
            }
        }
    }

    Set* set = createSet(n+1);
    int MST_len = 0;
    Edge** MST = malloc((n-1) * sizeof(Edge*));
    for (int i = 0; i < edge_num; i++) {
        Edge* e = extractMinOfMinHeap(heap);
        // printf("(u, v, w): (%d, %d, %d)\n", e->u, e->v, e->w);

        int setU = findSetAndCompress(set, e->u);
        int setV = findSetAndCompress(set, e->v);
        if (setU != setV) {
            *costs += e->w;
            MST[MST_len++] = e;
            // printf("Union %d %d\n", e->u, e->v);
            unionSetWeight(set, e->u, e->v);
        }

        if (MST_len == (n - 1))  break;
    }
    return MST;
}

