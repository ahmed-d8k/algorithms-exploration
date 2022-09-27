CC = g++
CFLAGS = -Wall -g3 -static

main: main.o test_strong_connection.o strong_connection.o sparse_digrph.o divertex.o
	$(CC) $(CFLAGS) -o output main.o test_strong_connection.o strong_connection.o sparse_digrph.o divertex.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

test_strong_connection.o: tests/test_strong_connection.cpp
	$(CC) $(CFLAGS) -c tests/test_strong_connection.cpp

strong_connection.o: src/strong_connection.cpp
	$(CC) $(CFLAGS) -c src/strong_connection.cpp

sparse_digrph.o: ../../DiGraph/src/sparse_digrph.cpp
	$(CC) $(CFLAGS) -c ../../DiGraph/src/sparse_digrph.cpp

divertex.o: ../../DiGraph/src/divertex.cpp
	$(CC) $(CFLAGS) -c ../../DiGraph/src/divertex.cpp