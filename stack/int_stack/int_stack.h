#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <limits.h>
#define INIT_STACK_SIZE 20
#define EMPTY_STACK_VALUE  INT_MAX
#define EMPTY_INDEX -1

typedef struct {
    int topIndex;
    int capacity;   // changes dynamically
    int* datas; 
} IntStack;

IntStack* createIntStack();

bool isFullIntStack(IntStack *s);

bool isEmptyIntStack(IntStack *s);

void pushIntStack(IntStack *s, int data);

void popIntStack(IntStack *s);

int topIntStack(IntStack *s);

int sizeIntStack(IntStack *s);

void freeIntStack(IntStack *s);

void printIntStack(IntStack *s);

#endif // STACK_H