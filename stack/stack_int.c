#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "constants.h"
#include "stack_int.h"

IntStack* createIntStack() {
    IntStack *s = (IntStack*)malloc(sizeof(IntStack));
    initIntStack(s);
    return s;
}

void initIntStack(IntStack *s) {
    s->topIndex = EMPTY_INDEX;
    s->capacity = INIT_STACK_SIZE;
    s->elements = (int*)malloc(s->capacity * sizeof(int));
}

bool isFullIntStack(IntStack *s) {
    return(s->topIndex >= (s->capacity - 1));
}

bool isEmptyIntStack(IntStack *s) {
    return(s->topIndex == EMPTY_INDEX);
}

void resizeIntStack(IntStack *s) {
    s->capacity *= 2;
    s->elements = (int*)realloc(s->elements, sizeof(int) * s->capacity);
}

void pushIntStack(IntStack *s, int *c) {
    if (isFullIntStack(s)) {
        resizeIntStack(s);
    }
    s->elements[++(s->topIndex)] = *c;
}

int* popIntStack(IntStack *s) {
    if (isEmptyIntStack(s)) {
        return NULL;    // Return a pointer to the NULL for empty stack
    }
    return &(s->elements[s->topIndex--]);
}

int* topIntStack(IntStack *s) {
    if (isEmptyIntStack(s)) {
        return NULL;    // Return a pointer to the NULL for empty stack
    }
    return &(s->elements[s->topIndex]);
}

int sizeIntStack(IntStack *s) {
    return s->topIndex + 1;
}

void freeIntStack(IntStack *s) {
    free(s->elements);
    free(s);
}

void printIntStack(IntStack *s) {
    printf("topIndex:%d, capacity:%d\n", s->topIndex, s->capacity);
    printf("stack elements from top: ");
    for (int i = s->topIndex; i >= 0; i--) {
        printf("%d ", s->elements[i]);
    }
    printf("\n");
}