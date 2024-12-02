#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "int_double_list.h"

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

    freeLinkedList(head);
    return 0;
}