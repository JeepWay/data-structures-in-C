#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../queue/queue_arr.h"

void testEnqueueToFull() {
    printf("--------------- Start Test EnqueueToFull ---------------\n\n");

    Queue *queue = createQueue(5);
    enqueue(queue, 10);
    enqueue(queue, 11);
    enqueue(queue, 12);
    enqueue(queue, 13);
    printQueue(queue);
    /**
     * frontIndex: 0, rearIndex: 4
     * front: 10, rear: 13
     * Print from front to rear: 10 11 12 13
     */

    dequeue(queue);
    dequeue(queue);
    enqueue(queue, 14);
    enqueue(queue, 15);
    printQueue(queue);
    /**
     * frontIndex: 2, rearIndex: 1
     * front: 12, rear: 15
     * Print from front to rear: 12 13 14 15
     */

    enqueue(queue, 16); 
    enqueue(queue, 17); 
    /** Queue is full */
    printQueue(queue);
    /**
     * frontIndex: 2, rearIndex: 2
     * front: 12, rear: 16
     * Print from front to rear: 12 13 14 15 16  << use all N space of array
     */
    printf("--------------- End Test EnqueueToFull ---------------\n\n");
}

void testDequeueToEmpty() {
    printf("--------------- Start Test DequeueToEmpty ---------------\n\n");

    Queue *queue = createQueue(5);
    enqueue(queue, 10);
    enqueue(queue, 11);
    enqueue(queue, 12);
    enqueue(queue, 13);
    printQueue(queue);
    /**
     * frontIndex: 0, rearIndex: 4
     * front: 10, rear: 13
     * Print from front to rear: 10 11 12 13
     */

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    printQueue(queue);
    /**
     * frontIndex: 3, rearIndex: 4
     * front: 13, rear: 13
     * Print from front to rear: 13
     */

    dequeue(queue);
    printQueue(queue);
    /**
     * frontIndex: 4, rearIndex: 4
     * front: -9999, rear: -9999
     * Print from front to rear:
     */

    dequeue(queue); 
    /** Queue is empty */
    dequeue(queue);
    /** Queue is empty */
    printf("--------------- End Test DequeueToEmpty ---------------\n\n");
}

int main() {
    testEnqueueToFull();
    testDequeueToEmpty();
    return 0;
}
