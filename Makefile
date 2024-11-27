CC = gcc
CFLAGS = -Wall -g

OBJS_STACK = stack/stack.o stack/stack_char.o stack/stack_string.o stack/stack_int.o 

TARGET = test_stack

test: $(TARGET)
	./$<

test_stack_int: test/test_stack_int.o stack/stack_int.o 
	@$(CC) $(CFLAGS) -o $@ $^

test_min_heap: test/test_min_heap.o heap/min_heap.o
	@$(CC) $(CFLAGS) -o $@ $^

test_max_heap: test/test_max_heap.o heap/max_heap.o
	@$(CC) $(CFLAGS) -o $@ $^

test_queue_circular1: test/test_queue_circular1.o queue/queue_circular_array1.o
	@$(CC) $(CFLAGS) -o $@ $^

test_queue_circular2: test/test_queue_circular2.o queue/queue_circular_array2.o
	@$(CC) $(CFLAGS) -o $@ $^

test_single_list: test/test_single_list.o linkedlist/single_list.o
	@$(CC) $(CFLAGS) -o $@ $^

test_double_list: test/test_double_list.o linkedlist/double_list.o
	@$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	@$(CC) -c -o $@ $<

clean:
	@echo "clean project"
	del /S *.o  
	del /S *.exe