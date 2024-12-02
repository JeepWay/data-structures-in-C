#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "general_list_queue.h"

/**
 * implement queue using single linked list
 **/
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

bool isQueueFull(Queue* q){
    return false;
}

bool isQueueEmpty(Queue* q){
    return q->front == NULL;
}

void enqueue(Queue* q, void* data) {
    Q_node *newNode = (Q_node*)malloc(sizeof(Q_node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (q->front == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

void* dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return NULL;
    } else {
        Q_node *temp = q->front;
        void* data = temp->data;
        q->front = q->front->next;
        q->size--;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        free(temp);
        return data;
    }
}

void* front(Queue* q) {
    if (isQueueEmpty(q)) {
        return NULL;
    } else {
        return q->front->data;
    }
}

void* rear(Queue* q) {
    if (isQueueEmpty(q)) {
        return NULL;
    } else {
        return q->rear->data;
    }
}

void freeQueue(Queue* q) {
    Q_node *cur = q->front;
    while (cur != NULL) {
        Q_node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(q);
}

