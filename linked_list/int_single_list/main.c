#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "int_single_list.h"

int main(void) {
    ListNode *head = createListNode(10);
    head = addListNode(head, 20);
    head = addListNode(head, 30);
    head = addListNode(head, 40);
    assert(lengthLinkedList(head) == 4);
    printLinkedList(head);
    /**
     * Print from head: 10 20 30 40
     */

    assert(getNthNode(head, 0) == 10);
    assert(getNthNode(head, 1) == 20);
    assert(getNthNode(head, 2) == 30);
    assert(getNthNode(head, 3) == 40);
    assert(getNthNode(head, 4) == INT_MAX);

    head = invertLinkedList(head);
    assert(lengthLinkedList(head) == 4);
    printLinkedList(head);
    /**
     * Print from head: 40 30 20 10
     */

    freeLinkedList(head);
    return 0;
}