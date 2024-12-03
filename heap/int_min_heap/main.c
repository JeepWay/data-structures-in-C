#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "int_min_heap.h"

int main() {
    MinHeap *heap = createMinHeap();

    insertMinHeap(heap, 1);
    insertMinHeap(heap, 30);
    insertMinHeap(heap, 20);
    insertMinHeap(heap, 25);
    insertMinHeap(heap, 21);
    deleteMinHeap(heap, 1);
    insertMinHeap(heap, 5);
    insertMinHeap(heap, 40);
    deleteMinHeap(heap, 5);

    levelOrderTraversal(heap); // 20 21 25 30 40
    printf("Min of minheap: %d\n", getMinOfMinHeap(heap)); // 20

    updateKeyMinHeap(heap, 21, 13);
    levelOrderTraversal(heap); // 13 20 25 30 40

    printf("Extracted min of minheap: %d\n", extractMinOfMinHeap(heap)); // 13
    levelOrderTraversal(heap); // 20 30 25 40

    freeHeap(heap);
    return 0;
}