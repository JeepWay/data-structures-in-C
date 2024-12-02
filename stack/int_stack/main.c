#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "int_stack.h"

int main() {
    IntStack *stack = createIntStack();
    printf("topIndex:%d, capacity:%d\n", stack->topIndex, stack->capacity); // -1, 20
    
    int a = 10, b = 20, c = 30, d = 40;
    pushIntStack(stack, 10);
    pushIntStack(stack, 20);
    pushIntStack(stack, 30);
    pushIntStack(stack, 40);

    printf("top: %d\n", topIntStack(stack)); // top: 40
    popIntStack(stack);
    printf("top: %d\n", topIntStack(stack)); // top: 30

    printf("stack size: %d\n", sizeIntStack(stack));    // stack size: 3
    printIntStack(stack);   // stack datas from top: 30 20 10

    popIntStack(stack);
    popIntStack(stack);
    printf("top: %d\n", topIntStack(stack)); // top: 10
    popIntStack(stack);     // stack is empty
    printf("top: %d\n", topIntStack(stack)); // top: 2147483647

    freeIntStack(stack);
    return 0;
}