CC = g++
CFLAGS = -Wall -g3 -static

main: main.o file_reader.o test_file_reader.o
	$(CC) $(CFLAGS) -o output main.o file_reader.o test_file_reader.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

file_reader.o: file_reader.cpp
	$(CC) $(CFLAGS) -c file_reader.cpp

test_file_reader.o: test_file_reader.cpp
	$(CC) $(CFLAGS) -c test_file_reader.cpp

