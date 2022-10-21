CC = g++
CFLAGS = -Wall -static -g3

main: main.o test_median_maintenance.o
	$(CC) $(CFLAGS) -o output main.o test_median_maintenance.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

test_median_maintenance.o: tests/test_median_maintenance.cpp
	$(CC) $(CFLAGS) -c tests/test_median_maintenance.cpp