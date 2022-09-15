CC = g++
CFLAGS = -Wall -g3 -static

main: main.o min_cut.o test_min_cut.o sparse_graph.o vertex.o file_reader.o
	$(CC) $(CFLAGS) -o output main.o min_cut.o test_min_cut.o sparse_graph.o vertex.o file_reader.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

min_cut.o: min_cut.cpp
	$(CC) $(CFLAGS) -c min_cut.cpp

test_min_cut.o: test_min_cut.cpp
	$(CC) $(CFLAGS) -c test_min_cut.cpp

sparse_graph.o: ../../../Graph/src/sparse_graph.cpp
	$(CC) $(CFLAGS) -c ../../../Graph/src/sparse_graph.cpp

vertex.o: ../../../Graph/src/vertex.cpp
	$(CC) $(CFLAGS) -c ../../../Graph/src/vertex.cpp

file_reader.o: ../../../FileHandling/src/file_reader.cpp
	$(CC) $(CFLAGS) -c ../../../FileHandling/src/file_reader.cpp