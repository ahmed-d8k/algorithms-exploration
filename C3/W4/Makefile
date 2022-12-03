SRC = main.cpp src/knapsack.cpp tests/test_knap.cpp ../../FileHandling/src/file_reader.cpp
TARG = output
CC = g++
CFLAGS = -Wall -static -g3
LIBS = -lm

OBJ = $(SRC:.cpp=.o)

all: $(TARG)

$(TARG): $(OBJ)
	$(CC) -o $(TARG) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARG)