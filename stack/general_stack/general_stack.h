#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#define INIT_STACK_SIZE 20
#define EMPTY_INDEX -1

typedef struct {
    int topIndex;
    int capacity;
    void** datas;
} Stack;

Stack* createStack();

bool isFullStack(Stack* s);

bool isEmptyStack(Stack* s);

void pushStack(Stack* s, void* data);

void popStack(Stack* s);

void* topStack(Stack* s);

int sizeStack(Stack *s);

void freeStack(Stack* s);

#define PRINT_STACK(type, stack, printFunc)          \
    do {                                             \
        printf("stack datas from top: ");         \
        for (int i = (stack)->topIndex; i >= 0; i--) {\
            printFunc((type*)((stack)->datas[i]));\
        }                                            \
        printf("\n");                                \
    } while (0)

#endif // STACK_H