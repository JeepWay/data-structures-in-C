#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "int_max_heap.h"

int main() {
    MaxHeap *heap = createMaxHeap();

    insertMaxHeap(heap, 1);
    insertMaxHeap(heap, 30);
    insertMaxHeap(heap, 20);
    insertMaxHeap(heap, 25);
    insertMaxHeap(heap, 21);
    deleteMaxHeap(heap, 1);
    insertMaxHeap(heap, 5);
    insertMaxHeap(heap, 40);
    deleteMaxHeap(heap, 5);

    levelOrderTraversal(heap);  // 40 25 30 21 20 
    printf("Max of maxheap: %d\n", getMaxOfMaxHeap(heap)); // 40

    updateKeyMaxHeap(heap, 21, 77);
    levelOrderTraversal(heap); // 77 40 30 25 20

    printf("Extracted max of maxheap: %d\n", extractMaxOfMaxHeap(heap)); // 77
    levelOrderTraversal(heap); // 40 25 30 20

    freeHeap(heap);
    return 0;
}