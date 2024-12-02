#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

typedef struct listnode {
    int data;
    struct listnode *next;
} ListNode;

ListNode* createListNode(int data);

ListNode* addListNode(ListNode* head, int data);

int lengthLinkedList(ListNode* head);

void freeLinkedList(ListNode* head);

void printLinkedList(ListNode* head);

int getNthNode(ListNode* head, int n);

ListNode* invertLinkedList(ListNode* head);     // 206. Reverse Linked List

ListNode* rotateRight(ListNode* head, int k);    // 61. Rotate List

ListNode* oddEvenList(ListNode* head);   // 328. Odd Even Linked List

#endif  // SINGLE_LIST_H