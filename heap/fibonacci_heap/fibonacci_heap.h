#include <stdlib.h>
#include <stdbool.h>

#define MAX_DEGREE 20
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define swap(type, a, b) { type tmp = a; a = b; b = tmp; }

typedef struct fibo_node_t {
    int key;
    int degree;
    bool child_cut;
    struct fibo_node_t* parent;
    struct fibo_node_t* child;
    struct fibo_node_t* r_sib;
    struct fibo_node_t* l_sib;
} fibo_node_t;

typedef struct heap_t {
	fibo_node_t *head;
    fibo_node_t *min;
} heap_t;

fibo_node_t* create_fibo_node(int key);

heap_t *create_fibo_heap();

/** 
 * New node is inserted to the tail of the linked list, in terms of the head pointer of the heap.
 */
heap_t* insert_fibo_heap(heap_t* heap, int key);

/**
 * Consolidation is performed after every extract-min and delete operation.
 * Consolidation is done by meld_fibo_heap() function.
 */
heap_t* extract_min_fibo_heap(heap_t* heap);

/**
 * Consolidation is performed after every extract-min and delete operation.
 * Consolidation is done by meld_fibo_heap() function.
 * Cascading cuts are performed during delete, decrease-key operations.
 */
heap_t* delete_fibo_heap(heap_t* heap, int key);

/**
 * Cascading cuts are performed during delete, decrease-key operations.
 */
heap_t* decrease_key(heap_t* heap, int old_key, int new_key);

/**
 * Assume the key is in the heap.
 */
fibo_node_t* find_key(heap_t* heap, int key);

/**
 * Sorting the given min tree list and the source nodes based on the degree and key.
 * */
heap_t* insertion_sort(heap_t* list, fibo_node_t* source);

/**
 * After merge, the `child_cut` of the root node with larger key is reset to false.
 * Assume b1 has smaller key, if not, swap b1 and b2.
 * Insert b2 to b1's child linked list according to the key in ascending order(from left to right).
 * */
fibo_node_t* merge_fibo_node(fibo_node_t* b1, fibo_node_t* b2);

/**
 * Convert the min tree linked list to fibonacci heap.
 * When multiple roots have the same degree, the two roots with the smallest key are merged first.
 * */
heap_t* meld_fibo_heap(heap_t* heap_list);

/**
 * Level order traversal print each min tree in the root node linked list, start with head pointer of heap.
 * Keys in the same min tree are printed in the same line.
 * Keys in different min trees are printed in separate lines.
 * */
void level_order_fibo_heap(fibo_node_t* start);

void free_fibo_heap(heap_t* heap);
