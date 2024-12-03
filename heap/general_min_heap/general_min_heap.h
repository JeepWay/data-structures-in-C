#include <limits.h>
#define INIT_HEAP_CAPACITY 20
#define MAX_HEAP_CAPACITY  INT_MAX
#define HEAP_EMPTY_VALUE INT_MAX
#define HEAP_START_INDEX 0
#define PARENT(i) ((i - 1) / 2)
#define LEFT(i) (2 * i + 1)
#define RIGHT(i) (2 * i + 2)
#define SWAP(type, a, b) { type temp = a; a = b; b = temp; }

typedef struct {
    int key;
    void* data;
} Element;

typedef struct {
    int capacity;
    int size;
    Element** arr;
} MinHeap;

MinHeap* createMinHeap();

void insertMinHeap(MinHeap* heap, Element* item);

void deleteMinHeap(MinHeap* heap, int key);

void heapifyMinHeap(MinHeap* heap, int rootIndex);

void updateKeyMinHeap(MinHeap* heap, int oldKey, int newKey);

Element* extractMinOfMinHeap(MinHeap* heap);

Element* getMinOfMinHeap(MinHeap* heap);

void levelOrderTraversal(MinHeap* heap);

void freeHeap(MinHeap* heap);