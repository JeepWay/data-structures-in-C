#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>
#include "../linkedlist/single_list.h"

int main(void) {
    ListNode *head = createListNode(1);
    head = addListNode(head, 10);
    head = addListNode(head, 20);
    head = addListNode(head, 10);
    printf("Length: %d\n", lengthLinkedList(head));
    printLinkedList(head);
    /**
     * Length: 4
     * Print from head: 1 10 20 10
     */

    printf("Get 0th node: %d\n", getNthNode(head, 0));  // 1
    printf("Get 1st node: %d\n", getNthNode(head, 1));  // 10
    printf("Get 2nd node: %d\n", getNthNode(head, 2));  // 20
    printf("Get 3rd node: %d\n", getNthNode(head, 3));  // 10
    printf("Get 4th node: %d\n", getNthNode(head, 4));  // -999

    head = invertLinkedList(head);
    printf("Length: %d\n", lengthLinkedList(head));
    printLinkedList(head);
    /**
     * Length: 4
     * Print from head: 10 20 10 1
     */

    return 0;
}