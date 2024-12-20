#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "binomial_heap.h"
#include "../../queue/general_circular_array_n_slot_queue/general_array_queue.h"

bino_node_t* create_bino_node(int key) {
    bino_node_t* node = malloc(sizeof(bino_node_t));
    node->key = key;
    node->degree = 0;
    node->parent = NULL;
    node->child = NULL;
    node->sibling = node;
    return node;
}

heap_t *create_bino_heap() {
	heap_t *heap = calloc(1, sizeof(heap_t));
	return heap;
}

heap_t* insert_bino_heap(heap_t* heap, int key) {
    bino_node_t* node = create_bino_node(key);
    heap_t* new_heap = create_bino_heap();
    new_heap->head = node;
    heap->head = meld_bino_heap(heap, new_heap);
    free(new_heap);
    return heap;
}

bino_node_t* get_min(heap_t* heap) {
    if (heap->head == NULL) return NULL;
    return heap->head;
}

heap_t* delete_min_bino_heap(heap_t* heap) {
    if (heap->head == NULL) return NULL;

    bino_node_t* min = heap->head;
    // remove min node from the heap
    bino_node_t* sibling_cur = heap->head->sibling;
    if (min == sibling_cur) { 
        sibling_cur = NULL;  // no sibling min tree
    } else {
        bino_node_t* tmp = sibling_cur;
        while (tmp->sibling != heap->head) {
            tmp = tmp->sibling;
        }
        tmp->sibling = sibling_cur;
    }
    free(min);
    bino_node_t* child_cur = heap->head->child;

    // get sbiling and child binomial trees
    heap_t* sibling_cur_heap = create_bino_heap();
    sibling_cur_heap->head = sibling_cur;
    heap_t* child_cur_heap = create_bino_heap();
    child_cur_heap->head = child_cur;
    heap->head = meld_bino_heap(sibling_cur_heap, child_cur_heap);
    return heap;
}

bino_node_t* merge_bino_node(bino_node_t* b1, bino_node_t* b2) {
    assert(b1 != NULL && b2 != NULL);

    // assume b1 has smaller key
    if (b1->key > b2->key) {
        swap(bino_node_t*, b1, b2);
    }

    b2->parent = b1;
    // modify circular linked list of b1's child
    if (b1->child == NULL) {
        b2->sibling = b2;
    } else {
        // find the last child of b1
        bino_node_t* cur = b1->child;
        while (cur->sibling != b1->child) {
            cur = cur->sibling;
        }
        cur->sibling = b2;
        b2->sibling = b1->child;
    }
    b1->child = b2;
    b1->degree++;
    return b1;
}

bino_node_t* meld_bino_heap(heap_t* h1, heap_t* h2) {
    if (h1->head == NULL) return h2->head;
    if (h2->head == NULL) return h1->head;

    bino_node_t* h1_cur = h1->head;
    bino_node_t* h2_cur = h2->head;
    bino_node_t* tree_table[MAX_DEGREE] = {NULL};

    do {
        if (tree_table[h1_cur->degree] == NULL) {
            tree_table[h1_cur->degree] = h1_cur;
            h1_cur = h1_cur->sibling;
        } else {
            // save the next node
            bino_node_t* next = h1_cur->sibling;
            
            while (tree_table[h1_cur->degree] != NULL) {
                bino_node_t* h_tmp = tree_table[h1_cur->degree];
                tree_table[h1_cur->degree] = NULL;
                h1_cur = merge_bino_node(h1_cur, h_tmp);
            }
            tree_table[h1_cur->degree] = h1_cur;
            
            // move to the next node
            h1_cur = next;
        }
    } while (h1_cur != h1->head);

    do {
        if (tree_table[h2_cur->degree] == NULL) {
            tree_table[h2_cur->degree] = h2_cur;
            h2_cur = h2_cur->sibling;
        } else {
            // save the next node
            bino_node_t* next = h2_cur->sibling;

            while (tree_table[h2_cur->degree] != NULL) {
                bino_node_t* h_tmp = tree_table[h2_cur->degree];
                tree_table[h2_cur->degree] = NULL;
                h2_cur = merge_bino_node(h2_cur, h_tmp);
            }
            tree_table[h2_cur->degree] = h2_cur;
            
            // move to the next node
            h2_cur = next;
        }
    } while (h2_cur != h2->head);

    // change the trees in the `tree_table` into a circular linked list
    bino_node_t* cur = NULL;
    bino_node_t* min = NULL;
    for (int i = 0; i < MAX_DEGREE; i++) {
        if (tree_table[i] != NULL) {
            if (cur == NULL) {
                cur = tree_table[i];
                cur->sibling = cur;
                min = tree_table[i];
            } else {
                tree_table[i]->sibling = cur->sibling;
                cur->sibling = tree_table[i];
                if (tree_table[i]->key < min->key)
                    min = tree_table[i];
            }
        }
    }
    return min;
}

void level_order_bino_heap(heap_t* heap) {
    if (heap->head == NULL) {
        printf("Empty heap\n");
        return;
    } 

    bino_node_t* cur = heap->head;
    Queue* queue = createQueue(100);
    printf("Min tree from top linked list\n");
    do {
        printf("Degree %d: %d ", cur->degree, cur->key);
        enqueue(queue, cur);
        while(!isQueueEmpty(queue)) {
            bino_node_t* node = (bino_node_t*)dequeue(queue);
            bino_node_t* child_cur = node->child;
            if (child_cur != NULL) {
                do {
                    printf("%d ", child_cur->key);
                    enqueue(queue, child_cur);
                    child_cur = child_cur->sibling;
                } while (child_cur != node->child);
            }
        }
        printf("\n");
        cur = cur->sibling;
    } while (cur != heap->head);
    freeQueue(queue);
    printf("\n");
}

void print_bino_heap(heap_t* heap) {
    if (heap->head == NULL) {
        printf("Empty heap\n");
        return;
    }

    bino_node_t* cur = heap->head;
    printf("Min tree from min node\n");
    do {
        printf("key: %d, degree: %d\n", cur->key, cur->degree);
        cur = cur->sibling;
    } while (cur != heap->head);
    printf("\n");
}

void _print_tree_table(bino_node_t* tree_table[]) {
    for (int i = 0; i < MAX_DEGREE; i++) {
        if (tree_table[i] != NULL) {
            printf("degree %d, key: %d\n", i, tree_table[i]->key);
        } else {
            printf("degree %d, key: NULL\n", i);
        }
    }
    printf("\n");
}
