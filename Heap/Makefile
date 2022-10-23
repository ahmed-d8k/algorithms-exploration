#CC = g++
#CFLAGS = -Wall -static -g3

#main: main.o test_heap.o
#	$(CC) $(CFLAGS) -o output main.o test_heap.o

#main.o: main.cpp
#	$(CC) $(CFLAGS) -c main.cpp

#test_heap.o: tests/test_heap.cpp
#	$(CC) $(CFLAGS) -c tests/test_heap.cpp

SRCS = main.cpp tests/test_heap.cpp src/heap.cpp src/min_heap.cpp src/max_heap.cpp
TARG = output
CC = g++
CFLAGS = -Wall -static -g3
LIBS = -lm
O_PATH = src

OBJS = $(SRCS:.cpp=.o)

all: $(TARG)

$(TARG): $(OBJS)
	$(CC) -o $(TARG) $(OBJS) 

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARG)