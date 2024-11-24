CC = gcc
CFLAGS = -Wall -g

OBJS_STACK = stack/stack.o stack/stack_char.o stack/stack_string.o stack/stack_int.o 

TARGET = test_stack

test: $(TARGET)
	./$<

test_stack_int: test/test_stack_int.o stack/stack_int.o 
	@$(CC) $(CFLAGS) -o $@ $^

test_queue_circular1: test/test_queue_circular1.o queue/queue_circular_array1.o
	@$(CC) $(CFLAGS) -o $@ $^

test_queue_circular2: test/test_queue_circular2.o queue/queue_circular_array2.o
	@$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	@$(CC) -c -o $@ $<

clean:
	@echo "clean project"
	del /S *.o  
	del /S *.exe