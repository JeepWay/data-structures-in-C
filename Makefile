CC = gcc
CFLAGS = -Wall -g

TARGET = general_stack

test: $(TARGET)
	./$<

general_stack: stack/general_stack/main.o stack/general_stack/general_stack.o
	@$(CC) $(CFLAGS) -o $@ $^
	
int_stack: stack/int_stack/main.o stack/int_stack/int_stack.o
	@$(CC) $(CFLAGS) -o $@ $^

general_single_linked_list: linked_list/general_single_list/main.o linked_list/general_single_list/general_single_list.o
	@$(CC) $(CFLAGS) -o $@ $^

int_single_linked_list: linked_list/int_single_list/main.o linked_list/int_single_list/int_single_list.o
	@$(CC) $(CFLAGS) -o $@ $^

general_double_linked_list: linked_list/general_double_list/main.o linked_list/general_double_list/general_double_list.o
	@$(CC) $(CFLAGS) -o $@ $^

int_double_linked_list: linked_list/int_double_list/main.o linked_list/int_double_list/int_double_list.o
	@$(CC) $(CFLAGS) -o $@ $^

general_circular_array_n_slot_queue: queue/general_circular_array_n_slot_queue/main.o queue/general_circular_array_n_slot_queue/general_circular_array_n_slot_queue.o
	@$(CC) $(CFLAGS) -o $@ $^

general_circular_array_n-1_slot_queue: queue/general_circular_array_n-1_slot_queue/main.o queue/general_circular_array_n-1_slot_queue/general_circular_array_n-1_slot_queue.o
	@$(CC) $(CFLAGS) -o $@ $^

general_single_list_queue: queue/general_single_list_queue/main.o queue/general_single_list_queue/general_single_list_queue.o
	@$(CC) $(CFLAGS) -o $@ $^

int_min_heap: heap/int_min_heap/main.o heap/int_min_heap/int_min_heap.o
	@$(CC) $(CFLAGS) -o $@ $^

int_max_heap: heap/int_max_heap/main.o heap/int_max_heap/int_max_heap.o
	@$(CC) $(CFLAGS) -o $@ $^

general_min_heap: heap/general_min_heap/main.o heap/general_min_heap/general_min_heap.o
	@$(CC) $(CFLAGS) -o $@ $^

general_min_max_heap: heap/general_min_max_heap/main.o heap/general_min_max_heap/general_min_max_heap.o
	@$(CC) $(CFLAGS) -o $@ $^

general_deap: heap/general_deap/main.o heap/general_deap/general_deap.o
	@$(CC) $(CFLAGS) -o $@ $^

general_min_leftist_tree: heap/general_min_leftist_tree/main.o heap/general_min_leftist_tree/general_min_leftist_tree.o
	@$(CC) $(CFLAGS) -o $@ $^

disjoint_set: set/disjoint_set/main.o set/disjoint_set/set.o
	@$(CC) $(CFLAGS) -o $@ $^

Kruskal_mst: graph/Kruskal_mst/main.o graph/Kruskal_mst/mst.o
	@$(CC) $(CFLAGS) -o $@ $^

binary_tree: tree/binary_tree/main.o tree/binary_tree/binary_tree.o  stack/general_stack/general_stack.o
	@$(CC) $(CFLAGS) -o $@ $^

binary_search_tree: tree/binary_search_tree/main.o tree/binary_search_tree/binary_search_tree.o
	@$(CC) $(CFLAGS) -o $@ $^

graph_bfs: graph/bfs/main.o graph/bfs/bfs.o queue/general_circular_array_n_slot_queue/general_circular_array_n_slot_queue.o
	@$(CC) $(CFLAGS) -o $@ $^

graph_dfs: graph/dfs/main.o graph/dfs/dfs.o stack/general_stack/general_stack.o
	@$(CC) $(CFLAGS) -o $@ $^

hashtable_list: hashing/hashtable_list/main.o hashing/hashtable_list/hashtable_list.o
	@$(CC) $(CFLAGS) -o $@ $^

hashtable_array: hashing/hashtable_array/main.o hashing/hashtable_array/hashtable_array.o
	@$(CC) $(CFLAGS) -o $@ $^

binomial_heap: heap/binomial_heap/main.o heap/binomial_heap/binomial_heap.o queue/general_circular_array_n_slot_queue/general_circular_array_n_slot_queue.o
	@$(CC) $(CFLAGS) -o $@ $^

fibonacci_heap: heap/fibonacci_heap/main.o heap/fibonacci_heap/fibonacci_heap.o queue/general_circular_array_n_slot_queue/general_circular_array_n_slot_queue.o
	@$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	@$(CC) -c -o $@ $<

ifeq ($(OS), Windows_NT)
    OS_TYPE = Window
else
    OS_TYPE = Linux
endif

clean:
ifeq ($(OS_TYPE), Window)
	@echo Clean up *.o and *.exe file on $(OS_TYPE)
	@del /s /q *.o
	@del /s /q *.exe
else
	@echo "Clean up *.o and *.exe file on $(OS_TYPE)"
	@find . -type f -name "*.o" -delete
	@find . -type f -name "*.exe" -exec rm -f {} +
endif
