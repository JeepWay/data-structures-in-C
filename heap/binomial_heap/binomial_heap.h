#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX_DEGREE 20
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define swap(type, a, b) { type tmp = a; a = b; b = tmp; }

typedef struct bino_node_t {
    int key;
    int degree;
    struct bino_node_t* parent;
    struct bino_node_t* child;
    struct bino_node_t* sibling;
} bino_node_t;

typedef struct heap_t {
	bino_node_t *head;
} heap_t;

bino_node_t* create_bino_node(int key);

heap_t* create_bino_heap();

heap_t* insert_bino_heap(heap_t* heap, int key);

bino_node_t* get_min(heap_t* heap);

heap_t* delete_min_bino_heap(heap_t* heap);

bino_node_t* merge_bino_node(bino_node_t* b1, bino_node_t* b2);

bino_node_t* meld_bino_heap(heap_t* h1, heap_t* h2);

void level_order_bino_heap(heap_t* heap);

void print_bino_heap(heap_t* heap);

void _print_tree_table(bino_node_t* tree_table[]);  // For debugging

