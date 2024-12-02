#ifndef GENERAL_ARRAY_QUEUE_H
#define GENERAL_ARRAY_QUEUE_H

#include <stdbool.h>
#define INIT_INDEX 0

typedef struct {
    int front, rear, size;
    int capacity;
    bool isFull;
    void** datas;
} Queue;

Queue* createQueue(int capacity);

bool isQueueFull(Queue* queue);

bool isQueueEmpty(Queue* queue);

void enqueue(Queue* queue, void* data);

void* dequeue(Queue* queue);

void* front(Queue* queue);

void* rear(Queue* queue);

void freeQueue(Queue* queue);

#define PRINT_QUEUE(type, queue, printFunc)     \
    do {                                        \
        printf("queue datas from front to rear: "); \
        int front = (queue)->front;                       \
        for(int i = 0; i < (queue)->size; i++) {          \
            front = (front + 1) % (queue)->capacity;  \
            printFunc((type*)((queue)->datas[front]));    \
        }                                      \
        printf("\n");                         \
    } while(0)

#endif // GENERAL_ARRAY_QUEUE_H