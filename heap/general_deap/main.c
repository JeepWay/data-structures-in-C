#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "general_deap.h"

typedef struct {
    int age;
    char name[20];
} Person;

void printKey(const Element* item) {
    printf("%d ", item->key);
}

void printAgeOfPerson(const Element* item) {
    printf("%d ", ((Person*)item->data)->age);
}

void test_getPartner() {
    Deap* h = createDeap();
    h->size = 11;
    assert(_getPartner(h, 1) == 2);
    assert(_getPartner(h, 2) == 1);
    assert(_getPartner(h, 3) == 5);
    assert(_getPartner(h, 4) == 6);
    assert(_getPartner(h, 5) == 3);
    assert(_getPartner(h, 6) == 4);
    assert(_getPartner(h, 7) == 5);
    assert(_getPartner(h, 8) == 5);
    assert(_getPartner(h, 9) == 6);
    assert(_getPartner(h, 10) == 6);
    assert(_getPartner(h, 11) == 7);
    assert(_getPartner(h, 12) == 8);
    assert(_getPartner(h, 13) == 9);
    assert(_getPartner(h, 14) == 10);
    freeDeap(h);
}

void test_isInMinHeap() {
    Deap* h = createDeap();
    h->size = 11;
    assert(_isInMinHeap(h, 1) == true);
    assert(_isInMinHeap(h, 2) == false);
    assert(_isInMinHeap(h, 3) == true);
    assert(_isInMinHeap(h, 4) == true);
    assert(_isInMinHeap(h, 5) == false);
    assert(_isInMinHeap(h, 6) == false);
    assert(_isInMinHeap(h, 7) == true);
    assert(_isInMinHeap(h, 8) == true);
    assert(_isInMinHeap(h, 9) == true);
    assert(_isInMinHeap(h, 10) == true);
    assert(_isInMinHeap(h, 11) == false);
    assert(_isInMinHeap(h, 12) == false);
    assert(_isInMinHeap(h, 13) == false);
    assert(_isInMinHeap(h, 14) == false);
    freeDeap(h);
}


int main() {
    test_getPartner();
    test_isInMinHeap();

    Deap* h = createDeap();
    Person p1 = {20, "John"};   Element e1 = {20, &p1};
    Person p2 = {10, "Jane"};   Element e2 = {10, &p2};
    Person p3 = {40, "Doe"};    Element e3 = {40, &p3};
    Person p4 = {3, "Doe"};     Element e4 = {3, &p4};
    Person p5 = {60, "Doe"};    Element e5 = {2, &p5};
    Person p6 = {7, "Doe"};     Element e6 = {7, &p6};
    Person p7 = {78, "Doe"};     Element e7 = {60, &p7};
    Person p8 = {10, "Jane"};   Element e8 = {1, &p8};
    Person p9 = {80, "Doe"};    Element e9 = {80, &p9};
    insertDeap(h, &e1);
    insertDeap(h, &e2);
    insertDeap(h, &e3);
    insertDeap(h, &e4);
    insertDeap(h, &e5);
    insertDeap(h, &e6);
    insertDeap(h, &e7);
    insertDeap(h, &e8);
    insertDeap(h, &e9);

    assert(h->size == 10);
    assert(getMinOfDeap(h)->key == 1);
    assert(((Person*)getMinOfDeap(h)->data)->age == 10);
    assert(strcmp(((Person*)getMinOfDeap(h)->data)->name, "Jane") == 0);
    assert(getMaxOfDeap(h)->key == 80);
    assert(((Person*)getMaxOfDeap(h)->data)->age == 80);
    assert(strcmp(((Person*)getMaxOfDeap(h)->data)->name, "Doe") == 0);

    LEVEL_ORDER_TRAVERSAL(Element*, h, printKey);   // 1 80 2 7 40 60 20 3 10 
    LEVEL_ORDER_TRAVERSAL(Element*, h, printAgeOfPerson);   // 10 80 60 7 40 78 20 3 10

    Element* min = extractMinOfDeap(h);
    assert(h->size == 9);
    assert(min->key == 1);
    assert(((Person*)min->data)->age == 10);
    assert(strcmp(((Person*)min->data)->name, "Jane") == 0);
    LEVEL_ORDER_TRAVERSAL(Element*, h, printKey);  // 2 80 3 7 40 60 20 10

    Element* max = extractMaxOfDeap(h);
    assert(h->size == 8);
    assert(max->key == 80);
    assert(((Person*)max->data)->age == 80);
    assert(strcmp(((Person*)max->data)->name, "Doe") == 0);
    LEVEL_ORDER_TRAVERSAL(Element*, h, printKey);  // 2 60 3 7 40 10 20

    freeDeap(h);
    return 0;
}