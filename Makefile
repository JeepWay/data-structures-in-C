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


%.o: %.c
	@$(CC) -c -o $@ $<

clean:
	@echo "clean project"
	del /S *.o  
	del /S *.exe