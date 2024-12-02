#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

typedef struct listnode {
    void *data;
    struct listnode *next;
    struct listnode *prev;
} ListNode;

ListNode* createListNode(void* data);

ListNode* addListNode(ListNode* head, void* data);

int lengthLinkedList(ListNode* head);

void freeLinkedList(ListNode* head);

#define PRINT_LINKED_LIST(type, head, printFunc)       \
    do {                                              \
        printf("Print from head: ");                  \
        ListNode* tmp = (head);                       \
        do {                                         \
            printFunc((type*)(tmp->data));            \
            tmp = tmp->next;                           \
        } while (tmp != head);                        \
        printf("\n");                                  \
    } while (0)

#endif  // DOUBLE_LIST_H