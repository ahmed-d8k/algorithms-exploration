CC = g++
CFLAGS = -Wall -g3 -static

main: main.o distance_graph.o test_distance_graph.o vertex.o
	$(CC) $(CFLAGS) -o output main.o distance_graph.o test_distance_graph.o vertex.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

distance_graph.o: src/distance_graph.cpp
	$(CC) $(CFLAGS) -c src/distance_graph.cpp

test_distance_graph.o: tests/test_distance_graph.cpp
	$(CC) $(CFLAGS) -c tests/test_distance_graph.cpp

vertex.o: src/vertex.cpp
	$(CC) $(CFLAGS) -c src/vertex.cpp