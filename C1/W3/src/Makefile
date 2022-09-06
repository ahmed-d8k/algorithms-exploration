CC = g++
CFLAGS = -Wall -g3 -static

main: main.o quicksort.o test_quicksort.o file_reader.o
	$(CC) $(CFLAGS) -o output main.o quicksort.o test_quicksort.o file_reader.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

quicksort.o: quicksort.cpp
	$(CC) $(CFLAGS) -c quicksort.cpp

test_quicksort.o: test_quicksort.cpp
	$(CC) $(CFLAGS) -c test_quicksort.cpp

file_reader.o: ../../../Filehandling/src/file_reader.cpp
	$(CC) $(CFLAGS) -c ../../../Filehandling/src/file_reader.cpp