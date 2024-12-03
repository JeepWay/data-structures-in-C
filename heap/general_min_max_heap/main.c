#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "general_min_max_heap.h"

void printKey(const Element* item) {
    printf("%d ", item->key);
}

void printStringData(const Element* item) {
    printf("%s ", (char*)item->data);
}

int main() {
    MinMaxHeap* h = createMinMaxHeap();
    Element e1 = {9, "data1"};
    Element e2 = {31, "data2"};
    Element e3 = {40, "data3"};
    Element e4 = {70, "data4"};
    Element e5 = {7, "data5"};
    Element e6 = {12, "data6"};
    Element e7 = {15, "data7"};
    Element e8 = {45, "data8"};
    Element e9 = {50, "data9"};
    Element e10 = {30, "data10"};
    Element e11 = {20, "data11"};
    Element e12 = {10, "data12"};

    insertMinMaxHeap(h, &e1);
    insertMinMaxHeap(h, &e2);
    insertMinMaxHeap(h, &e3);
    insertMinMaxHeap(h, &e4);
    insertMinMaxHeap(h, &e5);
    insertMinMaxHeap(h, &e6);
    insertMinMaxHeap(h, &e7);
    insertMinMaxHeap(h, &e8);
    insertMinMaxHeap(h, &e9);
    insertMinMaxHeap(h, &e10);
    insertMinMaxHeap(h, &e11);
    insertMinMaxHeap(h, &e12);
    assert(h->size == 12);
    assert(getMinOfMinMaxHeap(h)->key == 7);
    assert(strcmp(getMinOfMinMaxHeap(h)->data, "data5") == 0);
    assert(getMaxOfMinMaxHeap(h)->key == 70);
    assert(strcmp(getMaxOfMinMaxHeap(h)->data, "data4") == 0);
    LEVEL_ORDER_TRAVERSAL(Element, h, printKey);    // 7 70 40 31 9 10 15 45 50 30 20 12 

    Element* min = extractMinOfMinMaxHeap(h);
    assert(h->size == 11);
    assert(min->key == 7);
    assert(strcmp(min->data, "data5") == 0);
    LEVEL_ORDER_TRAVERSAL(Element, h, printKey);    // 9 70 40 31 12 10 15 45 50 30 20

    min = extractMinOfMinMaxHeap(h);
    assert(h->size == 10);
    assert(min->key == 9);
    assert(strcmp(min->data, "data1") == 0);
    LEVEL_ORDER_TRAVERSAL(Element, h, printKey);    // 10 70 40 31 12 20 15 45 50 30
    
    Element* max = extractMaxOfMinMaxHeap(h);
    assert(h->size == 9);
    assert(max->key == 70);
    assert(strcmp(max->data, "data4") == 0);
    LEVEL_ORDER_TRAVERSAL(Element, h, printKey);    // 10 50 40 30 12 20 15 45 31
    LEVEL_ORDER_TRAVERSAL(Element, h, printStringData); // data12 data9 data3 data10 data6 data11 data7 data8 data2

    freeMinMaxHeap(h);
}
