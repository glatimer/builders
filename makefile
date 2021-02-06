CXX=g++
DEBUG=-g
RM=rm -f
CFLAGS=-g -c -Wall


test: builders.o builder.o linkedlist.o structuretype.o 
	$(CXX) $(DEBUG) builders.o builder.o linkedlist.o structuretype.o -o builders

builders.o: builders.cpp
	$(CXX) $(CFLAGS) builders.cpp

builder.o: builder.cpp
	$(CXX) $(CFLAGS) builder.cpp

#linkedlist.o: linkedlist.cpp
#	$(CXX) $(CFLAGS) linkedlist.cpp

#structuretype.o: structuretype.cpp
#	$(CXX) $(CFLAGS) structuretype.cpp

test_ll: testlist.o linkedlist.o structuretype.o event.o
	$(CXX) $(DEBUG) testlist.o linkedlist.o structuretype.o event.o -o testlist

testlist.o: testlist.cpp 
	$(CXX) $(CFLAGS) testlist.cpp

event.o: event.cpp
	$(CXX) $(CFLAGS) event.cpp


linkedlist.o: linkedlist.cpp
	$(CXX) $(CFLAGS) linkedlist.cpp

structuretype.o: structuretype.cpp
	$(CXX) $(CFLAGS) structuretype.cpp

clean: 
	$(RM) test *.o *~D
