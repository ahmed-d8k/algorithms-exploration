#CC = g++
#CFLAGS = -Wall -static -g3

#main: main.o test_median_maintenance.o
#	$(CC) $(CFLAGS) -o output main.o test_median_maintenance.o

#main.o: main.cpp
#	$(CC) $(CFLAGS) -c main.cpp

#test_median_maintenance.o: tests/test_median_maintenance.cpp
#	$(CC) $(CFLAGS) -c tests/test_median_maintenance.cpp



SRCS = main.cpp tests/test_median_maintenance.cpp src/median_maintenance.cpp ../../Heap/src/max_heap.cpp ../../Heap/src/min_heap.cpp ../../Heap/src/heap.cpp  
TARG = output
CC = g++
CFLAGS = -Wall -static -g3
LIBS = -lm

OBJS = $(SRCS:.cpp=.o)

all: $(TARG)

$(TARG): $(OBJS)
	$(CC) -o $(TARG) $(OBJS) 

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARG)
