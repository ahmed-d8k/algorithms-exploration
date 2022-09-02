CC = g++
CFLAGS = -Wall -g3 -static

main: main.o quicksort.o test_quicksort.o
	$(CC) $(CFLAGS) -o output main.o quicksort.o test_quicksort.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

quicksort.o: quicksort.cpp
	$(CC) $(CFLAGS) -c quicksort.cpp

test_quicksort.o: test_quicksort.cpp
	$(CC) $(CFLAGS) -c test_quicksort.cpp