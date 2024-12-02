#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "general_double_list.h"

typedef struct {
    char* name;
    int age;
} Person;

void printInt(const int *data) {
    printf("%d ", *data);
}

void printPerson(const Person *data) {
    printf("(%s, %d), ", data->name, data->age);
}

void test_int_double_list() {
    printf("--------------- Start Test Int Double list ---------------\n");
    int* a = (int*)malloc(sizeof(int)); *a = 10;
    int* b = (int*)malloc(sizeof(int)); *b = 20;
    int* c = (int*)malloc(sizeof(int)); *c = 30;
    int* d = (int*)malloc(sizeof(int)); *d = 40;
    ListNode *head = createListNode(a);
    head = addListNode(head, b);
    head = addListNode(head, c);
    head = addListNode(head, d);

    assert(lengthLinkedList(head) == 4);
    PRINT_LINKED_LIST(int, head, printInt);
    /**
     * Print from head: 10 20 30 40
     */

    freeLinkedList(head);
    printf("----------------------------------------------------------\n\n");
}

void test_person_double_list() {
    printf("------------------ Start Test Person Double list ------------------\n");
    Person* p1 = (Person*)malloc(sizeof(Person));
    p1->name = "Alice";     p1->age = 10;  
    Person* p2 = (Person*)malloc(sizeof(Person));
    p2->name = "Bob";       p2->age = 20;
    Person* p3 = (Person*)malloc(sizeof(Person));
    p3->name = "Cindy";     p3->age = 30;
    Person* p4 = (Person*)malloc(sizeof(Person));
    p4->name = "David";     p4->age = 40;
     
    ListNode *head = createListNode(p1);
    head = addListNode(head, p2);
    head = addListNode(head, p3);
    head = addListNode(head, p4);

    assert(lengthLinkedList(head) == 4);
    PRINT_LINKED_LIST(Person, head, printPerson);
    /**
     * Print from head: (Alice, 10), (Bob, 20), (Cindy, 30), (David, 40),
     */

    freeLinkedList(head);
    printf("-------------------------------------------------------------------\n\n");
}


int main(void) {
    test_int_double_list();
    test_person_double_list();
    return 0;
}