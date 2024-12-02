#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "general_double_list.h"

ListNode* createListNode(void* data) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    if (node) {
        node->data = data;
        node->next = node;
        node->prev = node;
    }
    return node;
}

ListNode* addListNode(ListNode* head, void* data) {
    assert(head != NULL);
    assert(data != NULL);

    ListNode* tmp = head;
    do {
        tmp = tmp->next;
    } while (tmp->next != head);

    ListNode* node = createListNode(data);
    node->next = tmp->next;
    node->prev = tmp;
    tmp->next = node;
    return head;
}

int lengthLinkedList(ListNode* head) {
    ListNode* tmp = head;
    int count = 0;
    do {
        count++;
        tmp = tmp->next;
    } while (tmp != head);
    return count;
}

void freeLinkedList(ListNode* head) {
    ListNode* tmp = head->next;
    do {
        ListNode *node = tmp;
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        tmp = tmp->next;
        if (node->data) {
            free(node->data);
        }
        free(node);
    } while(tmp != head);
    free(head);
}

