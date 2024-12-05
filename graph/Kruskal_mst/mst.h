#include <stdlib.h>

typedef struct {
    int u;
    int v;
    int w;
} Edge;

Edge* createEdge(int u, int v, int w);

#define PARENT(i) (((i)-1)/2)
#define LEFT(i) ((2*(i))+1)
#define RIGHT(i) ((2*(i))+2)
#define INIT_HEAP_CAPACITY 20
#define START_INDEX 0
#define SWAP(type, a, b) { type temp = a; a = b; b = temp; }

typedef struct MinHeap {
    int capacity;
    int size;
    Edge** edges;
} MinHeap;

MinHeap* createMinHeap();

void insertMinHeap(MinHeap* heap, Edge* e);

Edge* extractMinOfMinHeap(MinHeap* heap);

void heapifyMinHeap(MinHeap* heap, int rootIndex);

void levelOrderTraversal(MinHeap* heap);

#define INIT_PARENT -1
#define max(x, y) (((x) > (y)) ? (x) : (y))
typedef struct set {
    int* parent;
    int* count;
    int* height;
    int size;
} Set;

Set* createSet(int size);

int findSetAndCompress(Set* set, int x);

void unionSetWeight(Set* set, int x, int y);

Edge** findKruskalMST(int** G, int n, int *costs);

