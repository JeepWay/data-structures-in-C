#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "binomial_heap.h"

void test_2_insertions_case1() {
    printf("--------- Start 2 Insertions Case1 ---------\n");
    heap_t* heap = create_bino_heap();
    assert(get_min(heap) == NULL);

    heap = insert_bino_heap(heap, 1);
    assert(get_min(heap)->key == 1);
    assert(get_min(heap)->degree == 0);

    heap = insert_bino_heap(heap, 2);
    assert(get_min(heap)->key == 1);
    assert(get_min(heap)->degree == 1);
    /* output heap
          1
         /
        2
    */

    level_order_bino_heap(heap);
    /*
    Min tree from top linked list
    Degree 1: 1 2 
    */
    printf("--------------------------------------------\n\n");
}

void test_2_insertions_case2() {
    printf("--------- Start 2 Insertions Case2 ---------\n");
    heap_t* heap = create_bino_heap();
    assert(get_min(heap) == NULL);
    
    heap = insert_bino_heap(heap, 2);
    assert(get_min(heap)->key == 2);
    assert(get_min(heap)->degree == 0);

    heap = insert_bino_heap(heap, 1);
    assert(get_min(heap)->key == 1);
    assert(get_min(heap)->degree == 1);
    /* output heap
          1
         /
        2
    */

    level_order_bino_heap(heap);
    /*
    Min tree from top linked list
    Degree 1: 1 2 
    */
    printf("--------------------------------------------\n\n");
}

void test_3_insertions_case1() {
    printf("--------- Start 3 Insertions Case1 ---------\n");
    heap_t* heap = create_bino_heap();
    assert(get_min(heap) == NULL);

    heap = insert_bino_heap(heap, 1);
    assert(get_min(heap)->key == 1);
    assert(get_min(heap)->degree == 0);

    heap = insert_bino_heap(heap, 2);
    assert(get_min(heap)->key == 1);
    assert(get_min(heap)->degree == 1);

    heap = insert_bino_heap(heap, 3);
    assert(get_min(heap)->key == 1);
    assert(get_min(heap)->degree == 1);
    assert(get_min(heap)->sibling->key == 3);
    assert(get_min(heap)->sibling->degree == 0);
    /* output heap
          1 -- 3
         /
        2
    */

    print_bino_heap(heap);
    /*
    Min tree from min node
    key: 1, degree: 1
    key: 3, degree: 0
    */

    level_order_bino_heap(heap);
    /*
    Min tree from top linked list
    Degree 1: 1 2
    Degree 0: 3
    */
    printf("--------------------------------------------\n\n");
}

void test_4_insertions_case1() {
    printf("--------- Start 4 Insertions Case1 ---------\n");
    heap_t* heap = create_bino_heap();
    assert(get_min(heap) == NULL);

    heap = insert_bino_heap(heap, 1);
    assert(get_min(heap)->key == 1);
    assert(get_min(heap)->degree == 0);

    heap = insert_bino_heap(heap, 2);
    assert(get_min(heap)->key == 1);
    assert(get_min(heap)->degree == 1);

    heap = insert_bino_heap(heap, 3);
    assert(get_min(heap)->key == 1);
    assert(get_min(heap)->degree == 1);
    assert(get_min(heap)->sibling->key == 3);
    assert(get_min(heap)->sibling->degree == 0);

    heap = insert_bino_heap(heap, 4); 
    assert(get_min(heap)->key == 1);
    assert(get_min(heap)->degree == 2);
    assert(get_min(heap)->child->key == 3);
    assert(get_min(heap)->child->degree == 1);
    assert(get_min(heap)->child->sibling->key == 2);
    assert(get_min(heap)->child->sibling->degree == 0);
    /* output heap
           1
         /  |
        3   2
        |
        4
    */

    level_order_bino_heap(heap);
    /*
    Min tree from top linked list
    Degree 2: 1 3 2 4
    */
    printf("--------------------------------------------\n\n");
}

void test_many_insertions_case1(){
    printf("-------- Start Many Insertions Case1 -------\n");
    heap_t* heap = create_bino_heap();
    heap = insert_bino_heap(heap, 20);
    heap = insert_bino_heap(heap, 10);
    heap = insert_bino_heap(heap, 5);
    heap = insert_bino_heap(heap, 18);
    heap = insert_bino_heap(heap, 6);
    heap = insert_bino_heap(heap, 12);
    heap = insert_bino_heap(heap, 14);
    heap = insert_bino_heap(heap, 4);
    heap = insert_bino_heap(heap, 22);
    /* output heap
             4      ------- 22
         /   |    |
        5    6   14
      /  |   |
     10 18  12 
     |
    20       
    */

    print_bino_heap(heap);
    /*
    Min tree from min node
    key: 4, degree: 3
    key: 22, degree: 0
    */

    level_order_bino_heap(heap);
    /*
    Min tree from top linked list
    Degree 3: 4 5 6 14 10 18 12 20
    Degree 0: 22
    */
    printf("--------------------------------------------\n\n");
}

void test_insertions_delete_case1() {
    printf("------ Start Insertions & Delete Case1 -----\n");
    heap_t* heap = create_bino_heap();
    heap = insert_bino_heap(heap, 20);
    heap = insert_bino_heap(heap, 10);
    heap = insert_bino_heap(heap, 5);
    heap = insert_bino_heap(heap, 18);
    heap = insert_bino_heap(heap, 6);
    heap = insert_bino_heap(heap, 12);
    heap = insert_bino_heap(heap, 14);
    heap = insert_bino_heap(heap, 4);
    heap = insert_bino_heap(heap, 22);
    /* output heap
             4      ------- 22
         /   |    |
        5    6   14
      /  |   |
     10 18  12 
     |
    20       
    */

    assert(get_min(heap)->key == 4);
    heap = delete_min_bino_heap(heap);
    /* output heap
             5 
         /   |    |
        6   10   18
      /  |   |
     14 12  20
      |
     22 
    */
    print_bino_heap(heap);
    /*
    Min tree from min node
    key: 5, degree: 3
    */

    level_order_bino_heap(heap);
    /*
    Degree 3: 5 6 10 18 14 12 20 22
    */

    bino_node_t* cur = heap->head->child;
    printf("Min tree from min node\n");
    do {
        printf("key: %d, degree: %d\n", cur->key, cur->degree);
        cur = cur->sibling;
    } while (cur != heap->head->child);
    /*
    Min tree from min node
    key: 6, degree: 2
    key: 10, degree: 1
    key: 18, degree: 0
    */
    printf("--------------------------------------------\n\n");
}


int main() {
    test_2_insertions_case1();
    test_2_insertions_case2();
    test_3_insertions_case1();
    test_4_insertions_case1();
    test_many_insertions_case1();
    test_insertions_delete_case1();
    return 0;
}
