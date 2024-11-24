#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constants.h"
#include "queue_arr.h"

/**
 * implement queue using type 2 circular array
 **/
Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = INIT_INDEX;
    queue->rear = INIT_INDEX;
    queue->size = 0;
    queue->isFull = false;
    queue->array = (int*)malloc(sizeof(int) * queue->capacity);
    return queue;
}

bool isQueueFull(Queue* queue){
    return queue->rear==queue->front && queue->isFull;
}

bool isQueueEmpty(Queue* queue){
    return queue->front==queue->rear && !queue->isFull;
}

void enqueue(Queue* queue, int x) {
    if (isQueueFull(queue)) {
        printf("Queue is full\n");
        return;
    } else {
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->array[queue->rear] = x;
        queue->size++;
        if (queue->rear == queue->front) {
            queue->isFull = true;
        }
    }
}

int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty\n");
        return EMPTY_VALUE;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
        int item = queue->array[queue->front];
        queue->size--;
        if (queue->front == queue->rear) {
            queue->isFull = false;
        }
        return item;
    }
}

int front(Queue* queue) {
    if (isQueueEmpty(queue)) {
        return EMPTY_VALUE; // queue is empty
    } else {
        return queue->array[(queue->front + 1) % queue->capacity];
    }
}

int rear(Queue* queue) {
    if (isQueueEmpty(queue)) {
        return EMPTY_VALUE; // queue is empty
    } else {
        return queue->array[queue->rear];
    }
}

void freeQueue(Queue* queue) {
    free(queue->array);
    free(queue);
}

void printQueue(Queue* queue) {
    printf("frontIndex: %d, rearIndex: %d\n", queue->front, queue->rear);
    printf("front: %d, rear: %d\n", front(queue), rear(queue));

    int front = queue->front;
    printf("Print from front to rear: ");
    for(int i = 0; i < queue->size; i++) {
        front = (front + 1) % queue->capacity;
        printf("%d ", queue->array[front]);
    }
    printf("\n\n");
}