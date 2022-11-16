SRC = main.cpp tests/huff_test.cpp src/huff.cpp ../../../FileHandling/src/file_reader.cpp
TARG = output
CC = g++
CFLAGS = -Wall -g3 -static
LIBS = -lm

OBJ = $(SRC:.cpp=.o)

all: $(TARG)

$(TARG): $(OBJ)
	$(CC) -o $(TARG) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARG) $(OBJ)
