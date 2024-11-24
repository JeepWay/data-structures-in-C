#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constants.h"
#include "queue_arr.h"

/**
 * implement queue using type 1 circular array
 **/
Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = INIT_INDEX;
    queue->rear = INIT_INDEX;
    queue->size = 0;
    queue->array = (int*)malloc(sizeof(int) * queue->capacity);
    return queue;
}

bool isQueueFull(Queue* queue){
    return queue->size == (queue->capacity - 1);
}

bool isQueueEmpty(Queue* queue){
    return queue->size == 0;
}

void enqueue(Queue* queue, int x) {
    queue->rear = (queue->rear + 1) % queue->capacity;

    if (queue->rear == queue->front) {
        queue->rear = (queue->rear - 1) % queue->capacity;
        printf("Queue is full\n");
        return;
    } else {
        queue->array[queue->rear] = x;
        queue->size++;
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
    while (front != queue->rear) {
        front = (front + 1) % queue->capacity;
        printf("%d ", queue->array[front]);
    }
    printf("\n\n");
}