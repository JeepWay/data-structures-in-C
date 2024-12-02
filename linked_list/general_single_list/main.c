#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "general_single_list.h"

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

void test_int_single_list() {
    printf("--------------- Start Test Int Single list ---------------\n");
    int a = 10, b = 20, c = 30, d = 40;
    ListNode *head = createListNode(&a);
    head = addListNode(head, &b);
    head = addListNode(head, &c);
    head = addListNode(head, &d);

    assert(lengthLinkedList(head) == 4);
    PRINT_LINKED_LIST(int, head, printInt);
    /**
     * Print from head: 10 20 30 40
     */

    assert(*(int*)getNthNode(head, 0) == 10);
    assert(*(int*)getNthNode(head, 1) == 20);
    assert(*(int*)getNthNode(head, 2) == 30);
    assert(*(int*)getNthNode(head, 3) == 40);
    assert(getNthNode(head, 4) == NULL);

    head = invertLinkedList(head);
    assert(lengthLinkedList(head) == 4);
    PRINT_LINKED_LIST(int, head, printInt);
    /**
     * Print from head: 40 30 20 10
     */

    freeLinkedList(head);
    printf("----------------------------------------------------------\n\n");
}

void test_person_single_list() {
    printf("------------------ Start Test Person Single list ------------------\n");
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

    assert(((Person*)getNthNode(head, 0))->name == "Alice");
    assert(((Person*)getNthNode(head, 0))->age == 10);
    assert(((Person*)getNthNode(head, 1))->name == "Bob");
    assert(((Person*)getNthNode(head, 2))->name == "Cindy");
    assert(((Person*)getNthNode(head, 3))->name == "David");

    head = invertLinkedList(head);
    assert(lengthLinkedList(head) == 4);
    PRINT_LINKED_LIST(Person, head, printPerson);
    /**
     * Print from head: (David, 40), (Cindy, 30), (Bob, 20), (Alice, 10),
     */
    freeLinkedList(head);
    printf("-------------------------------------------------------------------\n\n");
}

int main() {
    test_int_single_list();
    test_person_single_list();
    return 0;
}
