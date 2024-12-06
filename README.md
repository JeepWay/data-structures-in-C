# Data Structures in C
![License](https://img.shields.io/github/license/JeepWay/data-structures-in-C)
![Language](https://img.shields.io/badge/Language-C-blue)

This project contains implementations of various data structures in C.

## Table of Contents
- **[Stacks](https://github.com/JeepWay/data-structures-in-C/tree/main/stack)**
  - Stack using Arrays (general) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/stack/general_stack)
  - Stack using Arrays (int) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/stack/int_stack)
- **[Queues](https://github.com/JeepWay/data-structures-in-C/tree/main/queue)**
  - Queue using Arrays with N-1 slots (general) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/queue/general_circular_array_n-1_slot_queue)
  - Queue using Arrays with N slots (int) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/queue/general_circular_array_n_slot_queue)
  - Circular Queue using Single Linked List [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/queue/general_single_list_queue)
- **[Linked Lists](https://github.com/JeepWay/data-structures-in-C/tree/main/linked_list)**
  - Singly Linked List (grneral) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/linked_list/general_single_list)
  - Singly Linked List (int) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/linked_list/int_single_list)
  - Doubly Linked Lists (grneral) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/linked_list/general_double_list)
  - Doubly Linked Lists (int) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/linked_list/int_double_list)
- **[Trees](https://github.com/JeepWay/data-structures-in-C/tree/main/tree)**
  - Binary Trees [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/tree/binary_tree)
  - Binary Search Trees [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/tree/binary_search_tree)
- **[Sets](https://github.com/JeepWay/data-structures-in-C/tree/main/set)**
  - Disjoint Sets [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/set/disjoint_set)
- **[Graphs](https://github.com/JeepWay/data-structures-in-C/tree/main/graph)**
  - Kruskal's Minimum Spanning Tree [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/graph/Kruskal_mst)
- **[Hashing]()**
- **[Heap Structures](https://github.com/JeepWay/data-structures-in-C/tree/main/heap)**
  - Min Heap (general) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/heap/general_min_heap)
  - Min Heap (int) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/heap/int_min_heap)
  - Max Heap (int) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/heap/int_max_heap)
  - Min-Max Heap (general) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/heap/general_min_max_heap)
  - Deap (general) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/heap/general_deap)
  - Min Leftist tree (general) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/heap/general_min_leftist_tree)

## Makefile Usage
### Stacks
* Stack of `general` data type [📃](https://github.com/JeepWay/data-structures-in-C/blob/main/stack/general_stack/main.c)
    ```bash
    make test TARGET=general_stack
    ```
* Stack of `integer` data type [📃](https://github.com/JeepWay/data-structures-in-C/blob/main/stack/int_stack/main.c)
    ```bash
    make test TARGET=int_stack
    ```
### Queues
* Queue of `general` data type using arrays with N-1 slots [📃](https://github.com/JeepWay/data-structures-in-C/blob/main/queue/general_circular_array_n-1_slot_queue/main.c)
    ```bash
    make test TARGET=general_circular_array_n-1_slot_queue
    ```
* Queue of `general` data type using arrays with N slots [📃](https://github.com/JeepWay/data-structures-in-C/blob/main/queue/general_circular_array_n_slot_queue/main.c)
    ```bash
    make test TARGET=general_circular_array_n_slot_queue
    ```
* Circular of `general` data type using single linked list [📃](https://github.com/JeepWay/data-structures-in-C/blob/main/queue/general_single_list_queue/main.c)
    ```bash
    make test TARGET=general_single_list_queue
    ```
### Linked Lists
* Singly linked list of `general` data type [📃](https://github.com/JeepWay/data-structures-in-C/tree/main/linked_list/general_single_list/main.c)
    ```bash
    make test TARGET=general_single_linked_list
    ```
* Singly linked list of `integer` data type [📃](https://github.com/JeepWay/data-structures-in-C/tree/main/linked_list/int_single_list/main.c)
    ```bash
    make test TARGET=int_single_linked_list
    ```
* Doubly linked list of `general` data type [📃](https://github.com/JeepWay/data-structures-in-C/blob/main/linked_list/general_double_list/main.c)
    ```bash
    make test TARGET=general_double_linked_list
    ```
* Doubly linked list of `integer` data type [📃](https://github.com/JeepWay/data-structures-in-C/blob/main/linked_list/int_double_list/main.c)
    ```bash
    make test TARGET=int_double_linked_list
    ```
### Trees
* Binary tree [📃](https://github.com/JeepWay/data-structures-in-C/tree/main/tree/binary_tree/main.c)
    ```bash
    make test TARGET=binary_tree
    ```
* Binary search tree [📃](https://github.com/JeepWay/data-structures-in-C/tree/main/tree/binary_search_tree/main.c)
    ```bash
    make test TARGET=binary_search_tree
    ```
### Sets
* Disjoint sets [📃](https://github.com/JeepWay/data-structures-in-C/blob/main/set/disjoint_set/main.c)
    ```bash
    make test TARGET=disjoint_set
    ```
### Hashing
### Heap Structures
* Min heap of `general` data type [📃](https://github.com/JeepWay/data-structures-in-C/blob/main/heap/general_min_heap/main.c)
    ```bash
    make test TARGET=general_min_heap
    ```
* Min heap of `integer` data type [📃](https://github.com/JeepWay/data-structures-in-C/blob/main/heap/int_min_heap/main.c)
    ```bash
    make test TARGET=int_min_heap
    ```
* Max heap of `integer` data type [📃](https://github.com/JeepWay/data-structures-in-C/blob/main/heap/int_max_heap/main.c)
    ```bash
    make test TARGET=int_max_heap
    ```
* Min-max heap of `general` data type [📃](https://github.com/JeepWay/data-structures-in-C/blob/main/heap/general_min_max_heap/main.c)
    ```bash
    make test TARGET=general_min_max_heap
    ```
* Deap of `general` data type [📃](https://github.com/JeepWay/data-structures-in-C/blob/main/heap/general_deap/main.c)
    ```bash
    make test TARGET=general_deap
    ```
* Min leftist tree of `general` data type [📃](https://github.com/JeepWay/data-structures-in-C/blob/main/heap/general_min_leftist_tree/main.c)
    ```bash
    make test TARGET=general_min_leftist_tree
    ```
### Clean up object and executable files
```bash
make clean
```

## Acknowledgments
Inspired by and references from:
* [bartobri/data-structures-c](https://github.com/bartobri/data-structures-c)
* [AnishLohiya/DSA](https://github.com/AnishLohiya/DSA)
