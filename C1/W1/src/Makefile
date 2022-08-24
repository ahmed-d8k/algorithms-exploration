
CC = g++
CFLAGS = -Wall -g3 -static

main: main.o karatsuba.o test_karatsuba.o
	$(CC) $(CFLAGS) -o output main.o karatsuba.o test_karatsuba.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

karatsuba.o: karatsuba.cpp
	$(CC) $(CFLAGS) -c karatsuba.cpp

test_karatsuba.o: test_karatsuba.cpp
	$(CC) $(CFLAGS) -c test_karatsuba.cpp
