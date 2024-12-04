#include <limits.h>
#include <stdbool.h>
#define INIT_HEAP_CAPACITY 20
#define MAX_HEAP_CAPACITY  INT_MAX
#define HEAP_START_INDEX 1
#define MIN_HEAP_START_INDEX 1
#define MAX_HEAP_START_INDEX 2
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
} Deap;

Deap* createDeap();

int getLevel(int index);

bool _isInMinHeap(Deap* h, int index);

int _getPartner(Deap* h, int index);

void _minHeapInsert(Deap *h, int index);

void _maxHeapInsert(Deap *h, int index);

void insertDeap(Deap* h, Element* item);

void modifyInsertDeap(Deap* h, int cur);

Element* extractMinOfDeap(Deap* h);

Element* getMinOfDeap(Deap* h);

Element* extractMaxOfDeap(Deap* h);

Element* getMaxOfDeap(Deap* h);

void levelOrderTraversal(Deap* h);

#define LEVEL_ORDER_TRAVERSAL(type, heap, printFunc) \
    do {                                             \
        for (int i = MIN_HEAP_START_INDEX; i < (heap)->size; i++) {     \
            printFunc((type)((heap)->arr[i]));     \
        }                                            \
        printf("\n");                                \
    } while (0) 

void freeDeap(Deap* h);
