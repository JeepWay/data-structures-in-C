#include <stdbool.h>

typedef struct IntStack {
    int topIndex;
    int capacity;   // changes dynamically
    int* elements; 
} IntStack;

IntStack* createIntStack();

void initIntStack(IntStack *s);

bool isFullIntStack(IntStack *s);

bool isEmptyIntStack(IntStack *s);

void resizeIntStack(IntStack *s);     // internal function

void pushIntStack(IntStack *s, int* num);

int* popIntStack(IntStack *s);

int* topIntStack(IntStack *s);

int sizeIntStack(IntStack *s);

void freeIntStack(IntStack *s);

void printIntStack(IntStack *s);