#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h> 
#include "general_list_queue.h"

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

void test_int_queue() {
    printf("------------- Start Test Int Queue -------------\n");
    Queue* intQueue = createQueue();
    int a = 10, b = 20, c = 30, d = 40;
    enqueue(intQueue, &a);
    enqueue(intQueue, &b);
    enqueue(intQueue, &c);
    enqueue(intQueue, &d);

    assert(*(int*)front(intQueue) == 10);
    assert(*(int*)rear(intQueue) == 40);
    assert(intQueue->size == 4);
    assert(isQueueFull(intQueue) == false);
    PRINT_QUEUE(int, intQueue, printInt);  
    /**
     * queue datas from front to rear: 10 20 30 40
     */

    printf("dequeue: %d\n", *(int*)dequeue(intQueue)); // dequeue: 10
    printf("dequeue: %d\n", *(int*)dequeue(intQueue)); // dequeue: 20
    assert(*(int*)front(intQueue) == 30);
    assert(*(int*)rear(intQueue) == 40);
    
    printf("dequeue: %d\n", *(int*)dequeue(intQueue)); // dequeue: 30
    printf("dequeue: %d\n", *(int*)dequeue(intQueue)); // dequeue: 40
    assert(dequeue(intQueue) == NULL);                 // Queue is empty
    assert(isQueueEmpty(intQueue) == true);

    freeQueue(intQueue);
    printf("------------------------------------------------\n\n");
}

void test_char_queue() {
    printf("---------- Start Test Char Queue ----------\n");
    Queue* charQueue = createQueue(5);
    char a = 'a', b = 'b', c = 'c', d = 'd';
    enqueue(charQueue, &a);
    enqueue(charQueue, &b);
    enqueue(charQueue, &c);
    enqueue(charQueue, &d);

    assert(*(char*)front(charQueue) == 'a');
    assert(*(char*)rear(charQueue) == 'd');
    assert(charQueue->size == 4);
    assert(isQueueFull(charQueue) == false);
    PRINT_QUEUE(char, charQueue, printChar);
    /**
     * queue datas from front to rear: a b c d
     */

    printf("dequeue: %c\n", *(char*)dequeue(charQueue));    // dequeue: a
    printf("dequeue: %c\n", *(char*)dequeue(charQueue));    // dequeue: b
    assert(*(char*)front(charQueue) == 'c');
    assert(*(char*)rear(charQueue) == 'd');

    printf("dequeue: %c\n", *(char*)dequeue(charQueue));    // dequeue: c
    printf("dequeue: %c\n", *(char*)dequeue(charQueue));    // dequeue: d
    assert(dequeue(charQueue) == NULL);                     // Queue is empty
    assert(isQueueEmpty(charQueue) == true);
    
    freeQueue(charQueue);
    printf("-------------------------------------------\n\n");
}

void test_string_queue() {
    printf("------------------- Start Test String Queue -------------------\n");
    Queue *stringQueue = createQueue(5);
    char* a = "Hello", *b = "World", *c = "C Programming", *d = "Language";
    enqueue(stringQueue, a);
    enqueue(stringQueue, b);
    enqueue(stringQueue, c);
    enqueue(stringQueue, d);

    assert(strcmp((char*)front(stringQueue), "Hello") == 0);
    assert(strcmp((char*)rear(stringQueue), "Language") == 0);
    assert(stringQueue->size == 4);
    assert(isQueueFull(stringQueue) == false);
    PRINT_QUEUE(char, stringQueue, printString);
    /**
     * queue datas from front to rear: Hello World C Programming Language
     */

    printf("dequeue: %s\n", (char*)dequeue(stringQueue)); // dequeue: Hello
    printf("dequeue: %s\n", (char*)dequeue(stringQueue)); // dequeue: World
    assert(strcmp((char*)front(stringQueue), "C Programming") == 0);
    assert(strcmp((char*)rear(stringQueue), "Language") == 0);

    printf("dequeue: %s\n", (char*)dequeue(stringQueue)); // dequeue: C Programming
    printf("dequeue: %s\n", (char*)dequeue(stringQueue)); // dequeue: Language
    assert(dequeue(stringQueue) == NULL);                 // Queue is empty
    assert(isQueueEmpty(stringQueue) == true);

    freeQueue(stringQueue);
    printf("---------------------------------------------------------------\n\n");
}


void test_listnode_queue() {
    printf("--------------- Start Test ListNode Queue ---------------\n");
    Queue* listNodeQueue = createQueue(5);
    ListNode a = {10, NULL, NULL}, b = {20, NULL, NULL};
    ListNode c = {30, NULL, NULL}, d = {40, NULL, NULL};
    enqueue(listNodeQueue, &a);
    enqueue(listNodeQueue, &b);
    enqueue(listNodeQueue, &c);
    enqueue(listNodeQueue, &d);

    assert(((ListNode*)front(listNodeQueue)) == &a);
    assert(((ListNode*)front(listNodeQueue))->item == 10);
    assert(((ListNode*)rear(listNodeQueue))->item == 40);
    assert(listNodeQueue->size == 4);
    assert(isQueueFull(listNodeQueue) == false);
    PRINT_QUEUE(ListNode, listNodeQueue, printListNode);
    /**
     * queue datas from front to rear: 10 20 30 40
     */

    printf("dequeue: %d\n", ((ListNode*)dequeue(listNodeQueue))->item); // dequeue: 10
    printf("dequeue: %d\n", ((ListNode*)dequeue(listNodeQueue))->item); // dequeue: 20
    assert(((ListNode*)front(listNodeQueue))->item == 30);
    assert(((ListNode*)rear(listNodeQueue))->item == 40);

    printf("dequeue: %d\n", ((ListNode*)dequeue(listNodeQueue))->item); // dequeue: 30
    printf("dequeue: %d\n", ((ListNode*)dequeue(listNodeQueue))->item); // dequeue: 40
    assert(dequeue(listNodeQueue) == NULL);                             // Queue is empty
    assert(isQueueEmpty(listNodeQueue) == true);

    freeQueue(listNodeQueue);
    printf("----------------------------------------------------------\n\n");
}


int main() {
    test_int_queue();
    test_char_queue();
    test_string_queue();
    test_listnode_queue();
    return 0;
}