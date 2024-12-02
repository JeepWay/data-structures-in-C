#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

typedef struct listnode {
    void *data;
    struct listnode *next;
} ListNode;

ListNode* createListNode(void* data);

ListNode* addListNode(ListNode* head, void* data);

int lengthLinkedList(ListNode* head);

void freeLinkedList(ListNode* head);

#define PRINT_LINKED_LIST(type, head, printFunc)       \
    do {                                              \
        printf("Print from head: ");                  \
        ListNode* tmp = (head);                       \
        while (tmp) {                                 \
            printFunc((type*)(tmp->data));            \
            tmp = tmp->next;                          \
        }                                             \
        printf("\n");                                 \
    } while (0)

void* getNthNode(ListNode* head, int n);

ListNode* invertLinkedList(ListNode* head);     // 206. Reverse Linked List

ListNode* rotateRight(ListNode* head, int k);   // 61. Rotate List

ListNode* oddEvenList(ListNode* head);          // 328. Odd Even Linked List

#endif  // SINGLE_LIST_H