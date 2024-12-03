#include <limits.h>
#define INIT_HEAP_CAPACITY 20
#define MAX_HEAP_CAPACITY  INT_MAX
#define HEAP_EMPTY_VALUE INT_MAX
#define HEAP_START_INDEX 0
#define PARENT(i) ((i - 1) / 2)
#define LEFT(i) (2 * i + 1)
#define RIGHT(i) (2 * i + 2)
#define SWAP(type, a, b) { type temp = a; a = b; b = temp; }

typedef struct MinHeap {
    int capacity;
    int size;
    int* arr;
} MinHeap;

MinHeap* createMinHeap();

void insertMinHeap(MinHeap* h, int key);

void deleteMinHeap(MinHeap* h, int key);

void heapifyMinHeap(MinHeap* h, int rootIndex);

void updateKeyMinHeap(MinHeap* h, int oldKey, int newKey);

int extractMinOfMinHeap(MinHeap* h);

int getMinOfMinHeap(MinHeap* h);

void levelOrderTraversal(MinHeap* h);

void freeHeap(MinHeap* h);