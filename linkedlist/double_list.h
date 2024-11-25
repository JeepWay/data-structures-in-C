typedef struct listnode {
    int data;
    struct listnode *next;
    struct listnode *prev;
} ListNode;

ListNode* createListNode(int data);

ListNode* addListNode(ListNode* head, int data);

int lengthLinkedList(ListNode* head);

void freeLinkedList(ListNode* head);

void printLinkedList(ListNode* head);