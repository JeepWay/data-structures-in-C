#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>
#include "../linkedlist/double_list.h"

int main(void) {
    ListNode *head = createListNode(5);
    head = addListNode(head, 10);
    head = addListNode(head, 20);
    head = addListNode(head, 10);
    printf("Length: %d\n", lengthLinkedList(head));     // Length: 4
    printLinkedList(head);                          // Print from head: 5 10 20 10
    freeLinkedList(head);

    return 0;
}