CC = g++
CFLAGS = -Wall -static -g3

main: main.o test_heap.o
	$(CC) $(CFLAGS) -o output main.o test_heap.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

test_heap.o: tests/test_heap.cpp
	$(CC) $(CFLAGS) -c tests/test_heap.cpp