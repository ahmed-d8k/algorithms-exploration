CC = g++
CFLAGS = -Wall -g3 -static

main: main.o count_inversions.o test_count_inversions.o file_reader.o
	$(CC) $(CFLAGS) -o output main.o count_inversions.o test_count_inversions.o file_reader.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

count_inversions.o: count_inversions.cpp
	$(CC) $(CFLAGS) -c count_inversions.cpp

test_count_inversions.o: test_count_inversions.cpp
	$(CC) $(CFLAGS) -c test_count_inversions.cpp

file_reader.o: ../../../FileHandling/src/file_reader.cpp
	$(CC) $(CFLAGS) -c ../../../FileHandling/src/file_reader.cpp