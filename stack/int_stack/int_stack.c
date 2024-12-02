#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "int_stack.h"

IntStack* createIntStack() {
    IntStack *s = (IntStack*)malloc(sizeof(IntStack));
    s->topIndex = EMPTY_INDEX;
    s->capacity = INIT_STACK_SIZE;
    s->datas = (int*)calloc(s->capacity, sizeof(int));
    return s;
}

bool isFullIntStack(IntStack *s) {
    return(s->topIndex >= (s->capacity - 1));
}

bool isEmptyIntStack(IntStack *s) {
    return(s->topIndex == EMPTY_INDEX);
}

void pushIntStack(IntStack *s, int data) {
    if (isFullIntStack(s)) {
        s->capacity *= 2;
        s->datas = (int*)realloc(s->datas, s->capacity * sizeof(int));
    }
    s->datas[++(s->topIndex)] = data;
}

void popIntStack(IntStack *s) {
    if (isEmptyIntStack(s)) {
        return;
    }
    s->topIndex--;
}

int topIntStack(IntStack *s) {
    if (isEmptyIntStack(s)) {
        return EMPTY_STACK_VALUE;   // Return INT_MAX for empty stack
    }
    return s->datas[s->topIndex];
}

int sizeIntStack(IntStack *s) {
    return s->topIndex + 1;
}

void freeIntStack(IntStack *s) {
    free(s->datas);
    free(s);
}

void printIntStack(IntStack *s) {
    printf("stack datas from top: ");
    for (int i = s->topIndex; i >= 0; i--) {
        printf("%d ", s->datas[i]);
    }
    printf("\n");
}