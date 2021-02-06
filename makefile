CXX=g++
DEBUG=-g
RM=rm -f
CFLAGS=-g -c -Wall


test: builders.o builder.o linkedlist.o structuretype.o event.o stack.o
	$(CXX) $(DEBUG) builders.o builder.o linkedlist.o structuretype.o event.o stack.o -o builders

builders.o: builders.cpp
	$(CXX) $(CFLAGS) builders.cpp

builder.o: builder.cpp
	$(CXX) $(CFLAGS) builder.cpp

# test_stack: teststack.o stack.o structuretype.o event.o
# 	$(CXX) $(DEBUG) teststack.o stack.o structuretype.o event.o -o teststack

# test_ll: testlist.o linkedlist.o structuretype.o event.o
# 	$(CXX) $(DEBUG) testlist.o linkedlist.o structuretype.o event.o -o testlist

# teststack.o: teststack.cpp 
# 	$(CXX) $(CFLAGS) teststack.cpp

# testlist.o: testlist.cpp 
# 	$(CXX) $(CFLAGS) testlist.cpp

stack.o: stack.cpp
	$(CXX) $(CFLAGS) stack.cpp

event.o: event.cpp
	$(CXX) $(CFLAGS) event.cpp

linkedlist.o: linkedlist.cpp
	$(CXX) $(CFLAGS) linkedlist.cpp

structuretype.o: structuretype.cpp
	$(CXX) $(CFLAGS) structuretype.cpp

# run from root dir of the project
.PHONY: run_docker
run_docker:
	docker run -it -v $(shell pwd)/:/tmp gdb:latest sh	

# will only run in docker container (all files in /tmp dir)
.PHONY: debug
debug: clean test
	gdb --args ./builders medium.txt

# will only run in docker container (all files in /tmp dir)
.PHONY: leak_check
leak_check: clean test
	valgrind --leak-check=full ./builders medium.txt

.PHONY: run
run: clean test
	time -p ./builders huge.txt > result.txt
	cmp huge.txt.out result.txt

clean: 
	$(RM) test *.o *~D
