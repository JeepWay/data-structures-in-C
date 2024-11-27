#define PARENT(i) ((i - 1) / 2)
#define LEFT(i) (2 * i + 1)
#define RIGHT(i) (2 * i + 2)

typedef struct MaxHeap {
    int capacity;
    int size;
    int* arr;
} MaxHeap;

MaxHeap* createMaxHeap();

void insertMaxHeap(MaxHeap* heap, int key);

void deleteMaxHeap(MaxHeap* heap, int key);

void heapifyMaxHeap(MaxHeap* heap, int rootIndex);

void updateKeyMaxHeap(MaxHeap* heap, int oldKey, int newKey);

int extractMaxOfMaxHeap(MaxHeap* heap);

int getMaxOfMaxHeap(MaxHeap* heap);

void levelOrderTraversal(MaxHeap* heap);

void freeHeap(MaxHeap* heap);