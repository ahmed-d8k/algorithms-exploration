CC = g++
CFLAGS = -Wall -g3 -static

main: main.o test_graph.o sparse_graph.o vertex.o dense_graph.o
	$(CC) $(CFLAGS) -o output main.o test_graph.o sparse_graph.o vertex.o dense_graph.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

test_graph.o: test_graph.cpp
	$(CC) $(CFLAGS) -c test_graph.cpp

vertex.o: vertex.cpp
	$(CC) $(CFLAGS) -c vertex.cpp

sparse_graph.o: sparse_graph.cpp
	$(CC) $(CFLAGS) -c sparse_graph.cpp


dense_graph.o: dense_graph.cpp
	$(CC) $(CFLAGS) -c dense_graph.cpp