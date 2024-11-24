#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../stack/stack_int.h"

int main() {
    IntStack *stack = createIntStack();
    printf("topIndex:%d, capacity:%d\n", stack->topIndex, stack->capacity); // -1, 2

    int value;
    value = 1;  pushIntStack(stack, &value);
    value = 3;  pushIntStack(stack, &value);
    value = 5;  pushIntStack(stack, &value);
    value = 7;  pushIntStack(stack, &value);

    printf("Popped from int stack: %d\n", *popIntStack(stack)); // 7
    printf("Top from int stack: %d\n", *popIntStack(stack));    // 5

    value = 9;  pushIntStack(stack, &value);
    printIntStack(stack);   // 9 3 1
    return 0;
}