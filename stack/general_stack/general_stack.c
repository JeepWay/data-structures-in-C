#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "general_stack.h"

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->topIndex = EMPTY_INDEX;
    s->capacity = INIT_STACK_SIZE;
    s->datas = (void**)calloc(s->capacity, sizeof(void*));
    return s;
}

bool isFullStack(Stack *s) {
    return(s->topIndex >= (s->capacity - 1));
}

bool isEmptyStack(Stack* stack) {
    return stack->topIndex == EMPTY_INDEX;
}

void pushStack(Stack* s, void* data) {
    if (isFullStack(s)) {
        s->capacity *= 2;
        s->datas = realloc(s->datas, s->capacity * sizeof(void*));
        for (int i = s->topIndex + 1; i < s->capacity; i++) {
            s->datas[i] = NULL;
        }
    }
    s->datas[++(s->topIndex)] = data;
}

void popStack(Stack* s) {
    if (isEmptyStack(s))    return;
    s->datas[s->topIndex] = NULL;
    s->topIndex--;
}

void* topStack(Stack* s) {
    if (isEmptyStack(s)) {
        return NULL;
    }
    return s->datas[s->topIndex];
}

int sizeStack(Stack *s) {
    return s->topIndex + 1;
}

void freeStack(Stack* s) {
    for (int i = 0; i < s->capacity; i++)
        free(s->datas[i]);
    free(s->datas);
    free(s);
}


