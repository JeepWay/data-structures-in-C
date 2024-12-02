#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "general_array_queue.h"

/**
 * implement queue using type 2 circular array
 **/
Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = INIT_INDEX;
    q->rear = INIT_INDEX;
    q->size = 0;
    q->isFull = false;
    q->datas = (void**)calloc(q->capacity, sizeof(void*));
    return q;
}

bool isQueueFull(Queue* q){
    return (q->rear == q->front) && q->isFull;
}

bool isQueueEmpty(Queue* q){
    return (q->front == q->rear) && !q->isFull;
}

void enqueue(Queue* q, void* data) {
    if (isQueueFull(q)) {
        printf("Queue is full\n");
        return;
    } else {
        q->rear = (q->rear + 1) % q->capacity;
        q->datas[q->rear] = data;
        q->size++;
        if (q->rear == q->front) {
            q->isFull = true;
        }
    }
}

void* dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return NULL;
    } else {
        q->front = (q->front + 1) % q->capacity;
        void* item = q->datas[q->front];
        q->datas[q->front] = NULL;
        q->size--;
        if (q->front == q->rear) {
            q->isFull = false;
        }
        return item;
    }
}

void* front(Queue* q) {
    if (isQueueEmpty(q)) {
        return NULL;
    } else {
        return q->datas[(q->front + 1) % q->capacity];
    }
}

void* rear(Queue* q) {
    if (isQueueEmpty(q)) {
        return NULL;
    } else {
        return q->datas[q->rear];
    }
}

void freeQueue(Queue* q) {
    for (int i = 0; i < q->capacity; i++)
        free(q->datas[i]);
    free(q->datas);
    free(q);
}

