#ifndef GENERAL_LIST_QUEUE_H
#define GENERAL_LIST_QUEUE_H

#include <stdbool.h>

typedef struct node{
	void* data;
	struct node *next;
} Q_node; 

typedef struct queue {
    Q_node *front;
    Q_node *rear;
    int size;
} Queue;

Queue* createQueue();

bool isQueueFull(Queue* queue);

bool isQueueEmpty(Queue* queue);

void enqueue(Queue* queue, void* item);

void* dequeue(Queue* queue);

void* front(Queue* queue);

void* rear(Queue* queue);

void freeQueue(Queue* queue);

#define PRINT_QUEUE(type, queue, printFunc) \
    do { \
        printf("queue datas from front to rear: "); \
        Q_node *cur = (queue)->front; \
        while (cur != NULL) { \
            printFunc((type*)cur->data); \
            cur = cur->next; \
        } \
        printf("\n"); \
    } while(0)

#endif // GENERAL_LIST_QUEUE_H