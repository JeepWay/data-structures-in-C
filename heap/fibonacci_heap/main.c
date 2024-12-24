#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "fibonacci_heap.h"

void test_insert_case1() {
    printf("------- Start Insert Case1 -------\n");
    heap_t* heap = create_fibo_heap();
    heap = insert_fibo_heap(heap, 10);
    heap = insert_fibo_heap(heap, 20);
    heap = insert_fibo_heap(heap, 5);
    heap = insert_fibo_heap(heap, 30);
    heap = insert_fibo_heap(heap, 25);
    assert(heap->head->key == 10);
    assert(heap->min->key == 5);
    level_order_fibo_heap(heap->head);
    /*
    10
    20
    5
    30
    25
    */
    free_fibo_heap(heap);
    printf("----------------------------------\n\n");
}

void test_extract_min_case1() {
    printf("---- Start Extract Min Case1 -----\n");
    heap_t* heap = create_fibo_heap();
    heap = insert_fibo_heap(heap, 10);
    heap = insert_fibo_heap(heap, 20);
    heap = insert_fibo_heap(heap, 5);
    heap = insert_fibo_heap(heap, 30);
    heap = insert_fibo_heap(heap, 25);
    heap = extract_min_fibo_heap(heap);
    /*
         10
       /    \
      20    25
            /
           30
    */
    assert(heap->head->key == 10);
    assert(heap->min->key == 10);
    assert(heap->min->degree == 2);
    assert(heap->min->child->key == 20);
    assert(heap->min->child->r_sib->key == 25);
    assert(heap->min->child->r_sib->child->key == 30);
    level_order_fibo_heap(heap->head);
    /*
    10 20 25 30
    */
    free_fibo_heap(heap);
    printf("----------------------------------\n\n");
}

void test_decrease_key_case1() {
    printf("----- Start Decrease Key Case1 -----\n");
    heap_t* heap = create_fibo_heap();
    heap = insert_fibo_heap(heap, 10);
    heap = insert_fibo_heap(heap, 20);
    heap = insert_fibo_heap(heap, 5);
    heap = insert_fibo_heap(heap, 30);
    heap = insert_fibo_heap(heap, 25);
    heap = extract_min_fibo_heap(heap);
    heap = decrease_key(heap, 30, 22);
    /*
         10 ----- 8
       /    \
      20    25
    */
    assert(heap->head->key == 10);
    assert(heap->min->key == 8);
    assert(heap->head->degree == 2);
    assert(heap->head->child->key == 20);
    assert(heap->head->child->child_cut == false);
    assert(heap->head->child->r_sib->key == 25);
    assert(heap->head->child->r_sib->child_cut == true);
    level_order_fibo_heap(heap->head);
    /*
    10 20 25
    8
    */
    free_fibo_heap(heap);
    printf("------------------------------------\n\n");
}

void test_insert_case2() {
    printf("------- Start Insert Case2 -------\n");
    heap_t* heap = create_fibo_heap();
    heap = insert_fibo_heap(heap, 10);
    heap = insert_fibo_heap(heap, 20);
    heap = insert_fibo_heap(heap, 5);
    heap = insert_fibo_heap(heap, 30);
    heap = insert_fibo_heap(heap, 25);
    heap = extract_min_fibo_heap(heap);
    heap = decrease_key(heap, 30, 22);
    heap = insert_fibo_heap(heap, 15);
    heap = insert_fibo_heap(heap, 12);
    /*
         10 ----- 8 --- 15 --- 12
       /    \
      20    25
    */
    assert(heap->head->key == 10);
    assert(heap->min->key == 8);
    assert(heap->head->degree == 2);
    assert(heap->head->child->key == 20);
    assert(heap->head->child->r_sib->key == 25);
    level_order_fibo_heap(heap->head);
    /*
    12 15
    10 20 25
    */
    free_fibo_heap(heap);
    printf("----------------------------------\n\n");
}

void test_extract_min_case2() {
    printf("---- Start Extract Min Case2 -----\n");
    heap_t* heap = create_fibo_heap();
    heap = insert_fibo_heap(heap, 10);
    heap = insert_fibo_heap(heap, 20);
    heap = insert_fibo_heap(heap, 5);
    heap = insert_fibo_heap(heap, 30);
    heap = insert_fibo_heap(heap, 25);
    heap = extract_min_fibo_heap(heap);
    heap = decrease_key(heap, 30, 22);
    heap = insert_fibo_heap(heap, 15);
    heap = insert_fibo_heap(heap, 12);
    heap = extract_min_fibo_heap(heap);
    /*
         12 ----- 10
        /        /  \
       15       20  25
    */
    assert(heap->head->key == 12);
    assert(heap->min->key == 10);
    assert(heap->min->degree == 2);
    assert(heap->min->child->key == 20);
    assert(heap->min->child->r_sib->key == 25);
    level_order_fibo_heap(heap->head);
    /*
    12 15
    10 20 25
    */
    free_fibo_heap(heap);
    printf("----------------------------------\n\n");
}

int main() {
    test_insert_case1();
    test_extract_min_case1();
    test_decrease_key_case1();
    test_insert_case2();
    test_extract_min_case2();
    return 0;
}