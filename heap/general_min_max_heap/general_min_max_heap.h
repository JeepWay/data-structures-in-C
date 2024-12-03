#include <limits.h>
#define INIT_HEAP_CAPACITY 20
#define MAX_HEAP_CAPACITY  INT_MAX
#define HEAP_START_INDEX 0
#define PARENT(i) (((i)-1)/2)
#define LEFT(i) ((2*(i))+1)
#define RIGHT(i) ((2*(i))+2)
#define SWAP(type, a, b) { type temp = a; a = b; b = temp; }

typedef struct {
    int key;
    void* data;
} Element;

typedef struct {
    int capacity;
    int size;
    Element** arr;
} MinMaxHeap;

MinMaxHeap* createMinMaxHeap();

int getLevel(int index);

bool isMaxLevel(int index);

void verifyMin(MinMaxHeap* h, int index, Element* item);

void verifyMax(MinMaxHeap* h, int index, Element* item);

int min_child_grandchild(MinMaxHeap* h, int index);

int max_child_grandchild(MinMaxHeap* h, int index);

void insertMinMaxHeap(MinMaxHeap* heap, Element* item);

Element* extractMinOfMinMaxHeap(MinMaxHeap* heap);

Element* getMinOfMinMaxHeap(MinMaxHeap* heap);

Element* extractMaxOfMinMaxHeap(MinMaxHeap* heap);

Element* getMaxOfMinMaxHeap(MinMaxHeap* heap);

void levelOrderTraversal(MinMaxHeap* heap);

#define LEVEL_ORDER_TRAVERSAL(type, heap, printFunc) \
    do {                                             \
        for (int i = 0; i < (heap)->size; i++) {     \
            printFunc((type*)((heap)->arr[i]));     \
        }                                            \
        printf("\n");                                \
    } while (0) 

void freeMinMaxHeap(MinMaxHeap* heap);

