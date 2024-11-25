#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "single_list.h"

ListNode* createListNode(int data) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;
    return node;
}

ListNode* addListNode(ListNode* head, int data) {
    ListNode* tmp = head;
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = createListNode(data);
    return head;
}

int getNthNode(ListNode* head, int n) {
    ListNode* tmp = head;
    for (int i = 0; i < n; i++) {
        if (tmp->next) {
            tmp = tmp->next;
        } else {
            return -999;
        }
    }
    return tmp->data;
}

ListNode* invertLinkedList(ListNode* head) {
    ListNode* r = NULL;
    ListNode* q = NULL;
    ListNode* p = head;
    while (p) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
    return head;
}

int lengthLinkedList(ListNode* head) {
    ListNode* tmp = head;
    int count = 0;
    while (tmp) {
        count++;
        tmp = tmp->next;
    } 
    return count;
}

void freeLinkedList(ListNode* head) {
    ListNode* tmp = head;
    while (tmp) {
        ListNode* node = tmp;
        tmp = tmp->next;
        free(node);
    }
}

void printLinkedList(ListNode* head) {
    ListNode* tmp = head;
    printf("Print from head: ");
    while (tmp) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}


ListNode* rotateRight(ListNode* head, int k) {
    if(!head || !head->next)    return head;

    ListNode *tmp = head;
    ListNode *last = NULL;
    int len = 0;
    while (tmp) {
        len++;
        last = tmp;
        tmp = tmp->next;
    } 

    // k == len indicates no change
    k = k % len;
    if(k == 0)  return head;

    tmp = NULL; // before newHead
    ListNode *newHead = head; 
    for (int i = 0; i < len - k; i++) {
        tmp = newHead;
        newHead = newHead->next;
    }
    tmp->next = NULL;
    last->next = head;
    return newHead;
}

ListNode* oddEvenList(ListNode* head) {
    if(!head || !(head->next))  return head;

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *even_head = head->next;

    while(even && even->next){
        ListNode *oddNext = odd->next->next;
        ListNode *evenNext = even->next->next;
        odd->next =  oddNext;
        even->next = evenNext;
        odd = oddNext;
        even = evenNext;
    }
    odd->next = even_head;
    return head;
}