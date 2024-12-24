#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h> 
#include "fibonacci_heap.h"
#include "../../queue/general_circular_array_n_slot_queue/general_array_queue.h"

fibo_node_t* create_fibo_node(int key) {
    fibo_node_t* node = malloc(sizeof(fibo_node_t));
    node->key = key;
    node->degree = 0;
    node->child_cut = false;
    node->parent = NULL;
    node->child = NULL;
    node->r_sib = node;
    node->l_sib = node;
    return node;
}

heap_t *create_fibo_heap() {
	heap_t *heap = calloc(1, sizeof(heap_t));
	return heap;
}

heap_t* insert_fibo_heap(heap_t* heap, int key) {
    fibo_node_t* node = create_fibo_node(key);

    if (heap->head == NULL) {
        heap->head = node;
        heap->min = node;
    } else {
        // insert node to the tail of the linked list
        fibo_node_t* tail = heap->head->l_sib;
        node->r_sib = heap->head;
        node->l_sib = tail;
        tail->r_sib = node;
        heap->head->l_sib = node;
    }
    // update min node
    if (node->key < heap->min->key) {
        heap->min = node;
    }
    return heap;
}

heap_t* extract_min_fibo_heap(heap_t* heap) {
    if (heap->head == NULL) return NULL;
    // remove min node from the heap
    // make circular linked list to a single linked list
    fibo_node_t* min = heap->min;
    fibo_node_t* sibling_cur = heap->min->r_sib;
    if (min == sibling_cur) { 
        sibling_cur = NULL;  // no sibling min tree
    } else {
        min->l_sib->r_sib = min->r_sib;
        min->r_sib->l_sib = min->l_sib;
    }
    // collect child min trees
    fibo_node_t* child_cur = heap->min->child;
    if (child_cur != NULL) {
        fibo_node_t* tail = child_cur;
        tail->parent = NULL;
        while (tail->r_sib != child_cur) {
            tail = tail->r_sib;
            tail->parent = NULL;
        }
    }
    free(min);

    heap_t* min_tree_list = create_fibo_heap();
    min_tree_list = insertion_sort(min_tree_list, sibling_cur);
    min_tree_list = insertion_sort(min_tree_list, child_cur);
    heap = meld_fibo_heap(min_tree_list);
    return heap;
}

heap_t* delete_fibo_heap(heap_t* heap, int key) {
    if (heap->head == NULL) return NULL;
    fibo_node_t* target = find_key(heap, key);

    // remove target node from the parent's child linked list
    fibo_node_t* sibling_cur;
    if (target->parent == NULL) {   /* target is the root node */
        sibling_cur = target->r_sib;
        if (target->r_sib == target) {
            // target doesn't have sibling nodes
            sibling_cur = NULL;
        } else  {
            // target has sibling nodes
            target->l_sib->r_sib = target->r_sib;
            target->r_sib->l_sib = target->l_sib;
        }
        // remove target node from the parent node
        if (target->parent != NULL)
            target->parent->degree--;
        target->parent = NULL;
        target->child_cut = false;
        target->r_sib = target;
        target->l_sib = target;
    } else {    /* target isn't the root node */ 
        fibo_node_t* cur_parent = target->parent;
        // remove target node from the parent's child linked list
        sibling_cur = heap->head;
        fibo_node_t* sib = target->parent->child;
        if (target == sib) { 
            // target is the first child
            if (target->r_sib == target) {
                // target is the only child
                target->parent->child = NULL;
            } else {
                // target has sibling nodes
                target->r_sib->l_sib = target->l_sib;
                target->l_sib->r_sib = target->r_sib;
                target->parent->child = target->r_sib;
            }
        } else {
            // target isn't the first child
            target->l_sib->r_sib = target->r_sib;
            target->r_sib->l_sib = target->l_sib;
        }
        // remove target node from the parent node
        if (target->parent != NULL)
            target->parent->degree--;
        target->parent = NULL;
        target->child_cut = false;
        target->r_sib = target;
        target->l_sib = target;
        // cascading cut
        while(cur_parent->parent != NULL) { // non root nodes
            if (cur_parent->child_cut == false) {
                cur_parent->child_cut = true;
                break;
            } else {
                // remove cur_parent node from the parent's child linked list
                fibo_node_t* sib = cur_parent->parent->child;
                if (cur_parent == sib) { 
                    // cur_parent is the first child
                    if (cur_parent->r_sib == cur_parent) {
                        // cur_parent is the only child
                        cur_parent->parent->child = NULL;   
                    } else {
                        // cur_parent has sibling nodes
                        cur_parent->r_sib->l_sib = cur_parent->l_sib;
                        cur_parent->l_sib->r_sib = cur_parent->r_sib;
                        cur_parent->parent->child = cur_parent->r_sib;
                    }
                } else {
                    // cur_parent isn't the first child
                    cur_parent->r_sib->l_sib = cur_parent->l_sib;
                    cur_parent->l_sib->r_sib = cur_parent->r_sib;
                }
                // remove cur_parent node from the parent node
                if (cur_parent->parent != NULL)
                    cur_parent->parent->degree--;
                cur_parent->parent = NULL;
                cur_parent->child_cut = false;
                cur_parent->r_sib = cur_parent;
                cur_parent->l_sib = cur_parent;
                // re-insert cur_parent to the tail of the linked list
                fibo_node_t* tail = heap->head->l_sib;
                cur_parent->r_sib = heap->head;
                cur_parent->l_sib = tail;
                tail->r_sib = cur_parent;
                heap->head->l_sib = cur_parent;
                // update min node
                if (cur_parent->key < heap->min->key) {
                    heap->min = cur_parent;
                }
                // move to the upper parent node
                cur_parent = cur_parent->parent;
            }
        }
    }
    // collect child min trees of target
    fibo_node_t* child_cur = target->child;
    if (child_cur != NULL) {
        fibo_node_t* tail = child_cur;
        tail->parent = NULL;
        while (tail->r_sib != child_cur) {
            tail = tail->r_sib;
            tail->parent = NULL;
        }
    }
    free(target);

    heap_t* min_tree_list = create_fibo_heap();
    min_tree_list = insertion_sort(min_tree_list, sibling_cur);
    min_tree_list = insertion_sort(min_tree_list, child_cur);
    heap = meld_fibo_heap(min_tree_list);
    return heap;
}

heap_t* decrease_key(heap_t* heap, int old_key, int value) {
    if (heap->head == NULL) return NULL;

    fibo_node_t* target = find_key(heap, old_key);
    target->key -= value;

    if (target->parent == NULL) { /* target is the root node */
        // update min node
        if (target->key < heap->min->key) {
            heap->min = target;
        }
        return heap;
    } 

    /* target isn't the root node */
    if (target->key > target->parent->key) {
        return heap;
    } else {
        fibo_node_t* cur_parent = target->parent;
        // remove target node from the parent's child linked list
        fibo_node_t* sibling_cur = target->parent->child;
        if (target == sibling_cur) { 
            // target is the first child
            if (target->r_sib == target) {
                // target is the only child
                target->parent->child = NULL;   
            } else {
                // target has sibling nodes
                target->r_sib->l_sib = target->l_sib;
                target->l_sib->r_sib = target->r_sib;
                target->parent->child = target->r_sib;
            }
        } else {
            // target isn't the first child
            target->r_sib->l_sib = target->l_sib;
            target->l_sib->r_sib = target->r_sib;
        }
        // remove target node from the parent node
        if (target->parent != NULL)
            target->parent->degree--;
        target->parent = NULL;
        target->child_cut = false;
        target->r_sib = target;
        target->l_sib = target;
        // re-insert target to the tail of the linked list
        fibo_node_t* tail = heap->head->l_sib;
        target->r_sib = heap->head;
        target->l_sib = tail;
        tail->r_sib = target;
        heap->head->l_sib = target;
        // update min node
        if (target->key < heap->min->key) {
            heap->min = target;
        }
        // cascading cut
        while(cur_parent->parent != NULL) { // non root nodes
            if (cur_parent->child_cut == false) {
                cur_parent->child_cut = true;
                break;
            } else {
                // remove cur_parent node from the parent's child linked list
                fibo_node_t* sibling_cur = cur_parent->parent->child;
                if (cur_parent == sibling_cur) { 
                    // cur_parent is the first child
                    if (cur_parent->r_sib == cur_parent) {
                        // cur_parent is the only child
                        cur_parent->parent->child = NULL;   
                    } else {
                        // cur_parent has sibling nodes
                        cur_parent->r_sib->l_sib = cur_parent->l_sib;
                        cur_parent->l_sib->r_sib = cur_parent->r_sib;
                        cur_parent->parent->child = cur_parent->r_sib;
                    }
                } else {
                    // cur_parent isn't the first child
                    cur_parent->r_sib->l_sib = cur_parent->l_sib;
                    cur_parent->l_sib->r_sib = cur_parent->r_sib;
                }
                // remove cur_parent node from the parent node
                if (cur_parent->parent != NULL)
                    cur_parent->parent->degree--;
                cur_parent->parent = NULL;
                cur_parent->child_cut = false;
                cur_parent->r_sib = cur_parent;
                cur_parent->l_sib = cur_parent;
                // re-insert cur_parent to the tail of the linked list
                fibo_node_t* tail = heap->head->l_sib;
                cur_parent->r_sib = heap->head;
                cur_parent->l_sib = tail;
                tail->r_sib = cur_parent;
                heap->head->l_sib = cur_parent;
                // update min node
                if (cur_parent->key < heap->min->key) {
                    heap->min = cur_parent;
                }
                // move to the upper parent node
                cur_parent = cur_parent->parent;
            }
        }
    }
    return heap;
}

fibo_node_t* find_key(heap_t* heap, int key) {
    // find the node with key
    fibo_node_t* target = NULL;
    fibo_node_t* cur = heap->head;
    Queue* queue = createQueue(100);
    do {
        enqueue(queue, cur);
        while(!isQueueEmpty(queue)) {
            fibo_node_t* node = (fibo_node_t*)dequeue(queue);
            if (node->key == key) {
                target = node;
                break;
            }
            fibo_node_t* child_cur = node->child;
            if (child_cur != NULL) {
                do {
                    enqueue(queue, child_cur);
                    child_cur = child_cur->r_sib;
                } while (child_cur != node->child);
            }
        }
        cur = cur->r_sib;
        if (target != NULL) break;
    } while (cur != heap->head);
    freeQueue(queue);
    assert(target != NULL);
    return target;
}

heap_t* insertion_sort(heap_t* list, fibo_node_t* sources) {
    if (sources == NULL) return list;
    // insert the source nodes into the linked list based on the degree and key
    fibo_node_t* cur = sources;
    do {
        fibo_node_t* saved_next = cur->r_sib;
        cur->r_sib = NULL;
        cur->l_sib = NULL;
        // insert cur node into linked list
        if (list->head == NULL) {
            cur->r_sib = cur;
            cur->l_sib = cur;
            list->head = cur;
            list->min = cur;
        } else {
            if (cur->degree < list->head->degree || 
                (cur->degree == list->head->degree && cur->key < list->head->key)) {
                // case1: insert node to the head of the linked list
                cur->r_sib = list->head;
                cur->l_sib = list->head->l_sib;
                list->head->l_sib->r_sib = cur;
                list->head->l_sib = cur;
                list->head = cur;
            } else {
                // case2: insert node behind the head of the linked list
                fibo_node_t* tail = list->head;
                while (tail->r_sib != list->head) {
                    if (cur->degree < tail->r_sib->degree ||
                        (cur->degree == tail->r_sib->degree && cur->key < tail->r_sib->key)) {
                        break;
                    }
                    tail = tail->r_sib;
                }
                cur->r_sib = tail->r_sib;
                cur->l_sib = tail;
                tail->r_sib->l_sib = cur;
                tail->r_sib = cur;
            }
        }
        // update min node
        if (cur->key < list->min->key) {
            list->min = cur;
        }
        // move to the next source node
        cur = saved_next;   
    } while(cur != sources);
    return list;
}

fibo_node_t* merge_fibo_node(fibo_node_t* b1, fibo_node_t* b2) {
    assert(b1 != NULL && b2 != NULL);
    // assume b1 has smaller key
    if (b1->key > b2->key) {
        swap(fibo_node_t*, b1, b2);
    }
    b2->parent = b1;
    b2->child_cut = false;

    // modify circular linked list of b1's child
    if (b1->child == NULL) {
        b2->r_sib = b2;
        b2->l_sib = b2;
        b1->child = b2;
    } else {
        // find insert position based on key
        if (b2->key < b1->child->key) {
            // case1: insert node to the child of b1
            b2->r_sib = b1->child;
            b2->l_sib = b1->child->l_sib;
            b1->child->l_sib->r_sib = b2;
            b1->child->l_sib = b2;
            b1->child = b2;
        } else {
            // case2: insert node behind the child of b1
            fibo_node_t* tail = b1->child;
            while (tail->r_sib != b1->child) {
                if (b2->key < tail->r_sib->key)
                    break;
                tail = tail->r_sib;
            }
            b2->r_sib = tail->r_sib;
            b2->l_sib = tail;
            tail->r_sib->l_sib = b2;
            tail->r_sib = b2;
        }
    }
    b1->degree++;
    return b1;
}

heap_t* meld_fibo_heap(heap_t* heap_list) {
    if (heap_list->head == NULL) return NULL;
    // level_order_fibo_heap(heap_list->head);
    fibo_node_t* cur = heap_list->head;
    fibo_node_t* tree_table[MAX_DEGREE] = {NULL};
    while(1) {
        fibo_node_t* saved_next = cur->r_sib;
        if (tree_table[cur->degree] == NULL) {
            // update list head
            heap_list->head->l_sib->r_sib = saved_next;
            saved_next->l_sib = heap_list->head->l_sib;
            heap_list->head = saved_next;
            // save to the tree_table
            cur->r_sib = cur;
            cur->l_sib = cur;
            tree_table[cur->degree] = cur;
        } else {
            // update list head
            heap_list->head->l_sib->r_sib = saved_next;
            saved_next->l_sib = heap_list->head->l_sib;
            heap_list->head = saved_next;
            cur->r_sib = cur;
            cur->l_sib = cur;
            fibo_node_t* h_tmp = tree_table[cur->degree];
            tree_table[cur->degree] = NULL;
            if (cur == saved_next) {   // no more tree to merge
                heap_list->head = NULL;
                heap_list->min = NULL;
            } 
            cur = merge_fibo_node(cur, h_tmp);
            tree_table[cur->degree] = cur;
            // convert tree_table to list
            for(int i = 0; i < MAX_DEGREE; i++) {
                if (tree_table[i] != NULL) {
                    heap_list = insertion_sort(heap_list, tree_table[i]);
                    tree_table[i] = NULL;
                }
            }
            cur = heap_list->head;
            continue;
        }
        if (cur == saved_next)
            break;
        else
            cur = saved_next;
    }

    // change the `tree_table` into a fibonacci heap
    heap_t* new_heap = create_fibo_heap();
    cur = NULL;
    for (int i = 0; i < MAX_DEGREE; i++) {
        if (tree_table[i] != NULL) {
            if (new_heap->head == NULL) {
                cur = tree_table[i];
                cur->r_sib = cur;
                cur->l_sib = cur;
                new_heap->head = cur;
                new_heap->min = cur;
            } else {
                tree_table[i]->r_sib = new_heap->head;
                tree_table[i]->l_sib = new_heap->head->l_sib;
                new_heap->head->l_sib->r_sib = tree_table[i];
                new_heap->head->l_sib = tree_table[i];
                if (tree_table[i]->key < new_heap->min->key)
                    new_heap->min = tree_table[i];
            }
        }
    }
    return new_heap;
}

void level_order_fibo_heap(fibo_node_t* start) {
    if (start == NULL) {
        printf("Empty heap\n");
        return;
    } 
    fibo_node_t* cur = start;
    Queue* queue = createQueue(100);
    do {
        printf("%d ", cur->key);
        enqueue(queue, cur);
        while(!isQueueEmpty(queue)) {
            fibo_node_t* node = (fibo_node_t*)dequeue(queue);
            fibo_node_t* child_cur = node->child;
            if (child_cur != NULL) {
                do {
                    printf("%d ", child_cur->key);
                    enqueue(queue, child_cur);
                    child_cur = child_cur->r_sib;
                } while (child_cur != node->child);
            }
        }
        printf("\n");
        cur = cur->r_sib;
    } while (cur != start);
    freeQueue(queue);
}

void free_fibo_heap(heap_t* heap) {
    if (heap->head == NULL) return;
    fibo_node_t* cur = heap->head;
    Queue* queue = createQueue(100);
    do {
        enqueue(queue, cur);
        while(!isQueueEmpty(queue)) {
            fibo_node_t* node = (fibo_node_t*)dequeue(queue);
            fibo_node_t* child_cur = node->child;
            if (child_cur != NULL) {
                do {
                    enqueue(queue, child_cur);
                    child_cur = child_cur->r_sib;
                } while (child_cur != node->child);
            }
            free(node);
        }
        cur = cur->r_sib;
    } while (cur != heap->head);
    freeQueue(queue);
    free(heap);
}