#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "general_single_list.h"

ListNode* createListNode(void* data) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    if (node) {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

ListNode* addListNode(ListNode* head, void* data) {
    assert(head != NULL);
    assert(data != NULL);

    ListNode* tmp = head;
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = createListNode(data);
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
    ListNode* cur = head;
    while (cur) {
        ListNode* node = cur;
        cur = cur->next;
        if (node->data) {
            free(node->data);
        }
        free(node);
    }
}

void* getNthNode(ListNode* head, int n) {
    ListNode* tmp = head;
    for (int i = 0; i < n; i++) {
        if (tmp->next) {
            tmp = tmp->next;
        } else {
            return NULL;
        }
    }
    return tmp->data;
}

ListNode* invertLinkedList(ListNode* head) {
    ListNode *last = NULL;
	ListNode *middle = NULL;
	ListNode *front = head;
	while(front != NULL){
		last = middle;
		middle = front;
		front = front->next;
		middle->next = last;
	}
	head = middle;
	return head;
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

