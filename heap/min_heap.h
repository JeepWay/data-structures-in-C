#define PARENT(i) ((i - 1) / 2)
#define LEFT(i) (2 * i + 1)
#define RIGHT(i) (2 * i + 2)

typedef struct MinHeap {
    int capacity;
    int size;
    int* arr;
} MinHeap;

MinHeap* createMinHeap();

void insertMinHeap(MinHeap* heap, int key);

void deleteMinHeap(MinHeap* heap, int key);

void heapifyMinHeap(MinHeap* heap, int rootIndex);

void updateKeyMinHeap(MinHeap* heap, int oldKey, int newKey);

int extractMinOfMinHeap(MinHeap* heap);

int getMinOfMinHeap(MinHeap* heap);

void levelOrderTraversal(MinHeap* heap);

void freeHeap(MinHeap* heap);