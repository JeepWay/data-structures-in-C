#include <stdbool.h>

typedef struct queue {
    int front, rear, size;
    bool isFull;
    unsigned capacity;
    int* array;
} Queue;

// Function to create a queue of given capacity
Queue* createQueue(unsigned capacity);

// Queue is full when size becomes equal to the capacity
bool isQueueFull(Queue* queue);

// Queue is empty when size is 0
bool isQueueEmpty(Queue* queue);

// Function to add an item to the queue
void enqueue(Queue* queue, int item);

// Function to remove an item from queue
int dequeue(Queue* queue);

// Function to get front item of queue
int front(Queue* queue);

// Function to get rear item of queue
int rear(Queue* queue);

// Function to free queue
void freeQueue(Queue* queue);

// Function to print queue
void printQueue(Queue* queue);







