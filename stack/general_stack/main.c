#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "general_stack.h"

typedef struct {
    int item;
    struct ListNode* left;
    struct ListNode* right;
} ListNode;

void printInt(const int* data) {
    printf("%d ", *data);
}

void printChar(const char* data) {
    printf("%c ", *data);
}

void printString(const char* data) {
    printf("%s ", data);
}

void printListNode(const ListNode* data) {
    printf("%d ", data->item);
}

void test_int_stack() {
    printf("--------------- Start Test Int Stack ---------------\n");
    Stack* intStack = createStack();
    int a = 10, b = 20, c = 30, d = 40;
    pushStack(intStack, &a);
    pushStack(intStack, &b);
    pushStack(intStack, &c);
    pushStack(intStack, &d);

    printf("top: %d\n", *(int*)topStack(intStack)); // top: 40
    popStack(intStack);
    printf("top: %d\n", *(int*)topStack(intStack)); // top: 30

    printf("stack size: %d\n", sizeStack(intStack));// stack size: 3
    PRINT_STACK(int, intStack, printInt);           // stack datas from top: 30 20 10
    freeStack(intStack);
    printf("----------------------------------------------------\n\n");
}

void test_char_stack() {
    printf("--------------- Start Test Char Stack ---------------\n");
    Stack* charStack = createStack();
    char a = 'a', b = 'b', c = 'c', d = 'd';
    pushStack(charStack, &a);
    pushStack(charStack, &b);
    pushStack(charStack, &c);
    pushStack(charStack, &d);

    printf("top: %c\n", *(char*)topStack(charStack));   // top: d
    popStack(charStack);
    printf("top: %c\n", *(char*)topStack(charStack));   // top: c

    printf("stack size: %d\n", sizeStack(charStack));   // stack size: 3
    PRINT_STACK(char, charStack, printChar);            // stack datas from top: c b a
    freeStack(charStack);
    printf("-----------------------------------------------------\n\n");
}

void test_string_stack() {
    printf("--------------- Start Test String Stack ---------------\n");
    Stack* stringStack = createStack();
    char* a = "Hello", *b = "World", *c = "C Programming", *d = "Language";
    pushStack(stringStack, a);
    pushStack(stringStack, b);
    pushStack(stringStack, c);
    pushStack(stringStack, d);

    printf("top: %s\n", (char*)topStack(stringStack));  // top: Language
    popStack(stringStack);
    printf("top: %s\n", (char*)topStack(stringStack));  // top: C Programming

    printf("stack size: %d\n", sizeStack(stringStack)); // stack size: 3
    PRINT_STACK(char, stringStack, printString);        // stack datas from top: C Programming World Hello
    freeStack(stringStack);
    printf("-------------------------------------------------------\n\n");
}

void test_listnode_stack() {
    printf("--------------- Start Test ListNode Stack ---------------\n");
    Stack* listNodeStack = createStack();
    ListNode a = {10, NULL, NULL}, b = {20, NULL, NULL};
    ListNode c = {30, NULL, NULL}, d = {40, NULL, NULL};
    pushStack(listNodeStack, &a);
    pushStack(listNodeStack, &b);
    pushStack(listNodeStack, &c);
    pushStack(listNodeStack, &d);

    printf("top: %d\n", ((ListNode*)topStack(listNodeStack))->item); // top: 40
    popStack(listNodeStack);
    printf("top: %d\n", ((ListNode*)topStack(listNodeStack))->item); // top: 30

    printf("stack size: %d\n", sizeStack(listNodeStack));   // stack size: 3
    PRINT_STACK(ListNode, listNodeStack, printListNode);    // stack datas from top: 30 20 10
    freeStack(listNodeStack);
    printf("----------------------------------------------------------\n\n");
}


int main() {
    test_int_stack();
    test_char_stack();
    test_string_stack();
    test_listnode_stack();
    return 0;
}