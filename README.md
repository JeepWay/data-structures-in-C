# Data Structures in C
![License](https://img.shields.io/github/license/JeepWay/data-structures-in-C)
![Language](https://img.shields.io/badge/Language-C-blue)

This project contains implementations of various data structures in C.

[📂]()
## Table of Contents
- **[Stacks](https://github.com/JeepWay/data-structures-in-C/tree/main/stack)**
    - Stack using Arrays (general) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/stack/general_stack)
    - Stack using Arrays (int) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/stack/int_stack)
- **[Queues](https://github.com/JeepWay/data-structures-in-C/tree/main/queue)**
    - Queue using Arrays with N-1 slots (general) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/queue/general_circular_array_n-1_slot_queue)
    - Queue using Arrays with N-1 slots (int) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/queue/general_circular_array_n_slot_queue)
    - Circular Queue using Single Linked List [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/queue/general_single_list_queue)
- **[Linked Lists](https://github.com/JeepWay/data-structures-in-C/tree/main/linked_list)**
    - Singly Linked List (grneral) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/linked_list/general_single_list)
    - Singly Linked List (int) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/linked_list/int_single_list)
    - Doubly Linked Lists (grneral) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/linked_list/general_double_list)
    - Doubly Linked Lists (int) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/linked_list/int_double_list)
- **[Trees](https://github.com/JeepWay/data-structures-in-C/tree/main/tree)**
    - Binary Trees [📂]()
    - Binary Search Trees [📂]()
- **[Sets](https://github.com/JeepWay/data-structures-in-C/tree/main/set)**
    - Disjoint Sets [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/set/disjoint_set)
- **[Graphs](https://github.com/JeepWay/data-structures-in-C/tree/main/graph)**
    - Kruskal's Minimum Spanning Tree [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/graph/Kruskal_mst)
- **[Hasing]()**
- **[Heap Structures](https://github.com/JeepWay/data-structures-in-C/tree/main/heap)**
    - Min Heap (general) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/heap/general_min_heap)
    - Min Heap (int) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/heap/int_min_heap)
    - Max Heap (int) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/heap/int_max_heap)
    - Min-Max Heap (general) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/heap/general_min_max_heap)
    - Deap (general) [📂](https://github.com/JeepWay/data-structures-in-C/tree/main/heap/general_deap)

## Makefile Usage
### Stack
* Stack of general data type:
    ```bash
    make test TARGET=general_stack
    ```
* Stack of integer data type:
    ```bash
    make test TARGET=int_stack
    ```

### Queue
```bash
make test TARGET=general_circular_array_n_slot_queue

make test TARGET=general_circular_array_n-1_slot_queue

make test TARGET=general_single_list_queue
```
### Linked List
```bash
make test TARGET=general_single_linked_list

make test TARGET=int_single_linked_list

make test TARGET=general_double_linked_list

make test TARGET=int_double_linked_list
```
### Min/Max Heap
```bash
make test TARGET=int_min_heap

make test TARGET=int_max_heap

make test TARGET=general_min_heap
```
### Min-Max Heap
```bash
make test TARGET=general_min_max_heap
```
### Clean up
```bash
make clean
```

## Acknowledgments
Inspired by and references from:
* [bartobri/data-structures-c](https://github.com/bartobri/data-structures-c)
* [AnishLohiya/DSA](https://github.com/AnishLohiya/DSA)
