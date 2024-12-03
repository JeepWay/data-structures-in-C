#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "general_min_heap.h"

int main() {
    MinHeap *heap = createMinHeap();

    Element e1 = {1, "data1"};
    Element e2 = {30, "data2"};
    Element e3 = {20, "data3"};
    Element e4 = {25, "data4"};
    Element e5 = {21, "data5"};
    insertMinHeap(heap, &e1);
    insertMinHeap(heap, &e2);
    insertMinHeap(heap, &e3);
    insertMinHeap(heap, &e4);
    insertMinHeap(heap, &e5);
    deleteMinHeap(heap, 1);
    Element e6 = {5, "data6"};
    Element e7 = {40, "data7"};
    insertMinHeap(heap, &e6);
    insertMinHeap(heap, &e7);
    deleteMinHeap(heap, 5);

    levelOrderTraversal(heap); // 20 21 25 30 40
    printf("Key of min element: %d\n", getMinOfMinHeap(heap)->key);     // 20
    printf("Data of min element: %s\n", getMinOfMinHeap(heap)->data);   // data3

    updateKeyMinHeap(heap, 21, 13);
    levelOrderTraversal(heap); // 13 20 25 30 40

    Element* min = extractMinOfMinHeap(heap); 
    printf("Key of extracted element: %d\n", min->key);     // 13
    printf("Data of extracted element: %s\n", min->data);   // data5
    levelOrderTraversal(heap); // 20 30 25 40

    freeHeap(heap);
    return 0;
}