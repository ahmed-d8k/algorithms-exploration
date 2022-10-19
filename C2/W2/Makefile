CC = g++
CFLAGS = -Wall -g3 -static

main: main.o shortest_path.o test_shortest_path.o distance_graph.o vertex.o file_reader.o
	$(CC) $(CFLAGS) -o output main.o shortest_path.o test_shortest_path.o distance_graph.o vertex.o file_reader.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

shortest_path.o: src/shortest_path.cpp
	$(CC) $(CFLAGS) -c src/shortest_path.cpp

test_shortest_path.o: tests/test_shortest_path.cpp
	$(CC) $(CFLAGS) -c tests/test_shortest_path.cpp

distance_graph.o: ../../DistanceGraph/src/distance_graph.cpp
	$(CC) $(CFLAGS) -c ../../DistanceGraph/src/distance_graph.cpp

vertex.o: ../../DistanceGraph/src/vertex.cpp
	$(CC) $(CFLAGS) -c ../../DistanceGraph/src/vertex.cpp

file_reader.o: ../../FileHandling/src/file_reader.cpp
	$(CC) $(CFLAGS) -c ../../FileHandling/src/file_reader.cpp