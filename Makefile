CC = gcc
CFLAGS = -Wall -g

OBJS_STACK = stack/stack.o stack/stack_char.o stack/stack_string.o stack/stack_int.o 

TARGET = test_stack

test: $(TARGET)
	./$<

general_stack: stack/general_stack/main.o stack/general_stack/general_stack.o
	@$(CC) $(CFLAGS) -o $@ $^
	
int_stack: stack/int_stack/main.o stack/int_stack/int_stack.o
	@$(CC) $(CFLAGS) -o $@ $^

general_single_linked_list: linked_list/general_single_list/main.o linked_list/general_single_list/general_single_list.o
	@$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	@$(CC) -c -o $@ $<

clean:
	@echo "clean project"
	del /S *.o  
	del /S *.exe