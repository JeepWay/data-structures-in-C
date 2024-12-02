#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "general_array_queue.h"

/**
 * implement queue using type 1 circular array
 **/
Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = INIT_INDEX;
    q->rear = INIT_INDEX;
    q->size = 0;
    q->datas = (void**)calloc(q->capacity, sizeof(void*));
    return q;
}

bool isQueueFull(Queue* q){
    return q->size == (q->capacity - 1);
}

bool isQueueEmpty(Queue* q){
    return q->size == 0;
}

void enqueue(Queue* q, void* data) {
    q->rear = (q->rear + 1) % q->capacity;

    if (q->rear == q->front) {
        q->rear = (q->rear - 1) % q->capacity;
        printf("Queue is full\n");
        return;
    } else {
        q->datas[q->rear] = data;
        q->size++;
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

