#include <limits.h>
#define INIT_HEAP_CAPACITY 20
#define MAX_HEAP_CAPACITY  INT_MAX
#define HEAP_EMPTY_VALUE INT_MIN
#define HEAP_START_INDEX 0
#define PARENT(i) ((i - 1) / 2)
#define LEFT(i) (2 * i + 1)
#define RIGHT(i) (2 * i + 2)
#define SWAP(type, a, b) { type temp = a; a = b; b = temp; }

typedef struct MaxHeap {
    int capacity;
    int size;
    int* arr;
} MaxHeap;

MaxHeap* createMaxHeap();

void insertMaxHeap(MaxHeap* h, int key);

void deleteMaxHeap(MaxHeap* h, int key);

void heapifyMaxHeap(MaxHeap* h, int rootIndex);

void updateKeyMaxHeap(MaxHeap* h, int oldKey, int newKey);

int extractMaxOfMaxHeap(MaxHeap* h);

int getMaxOfMaxHeap(MaxHeap* h);

void levelOrderTraversal(MaxHeap* h);

void freeHeap(MaxHeap* h);