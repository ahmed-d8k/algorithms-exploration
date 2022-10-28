
SRC = main.cpp tests/test_two_sum.cpp src/two_sum.cpp ../../FileHandling/src/file_reader.cpp 
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

#$< is the name of the prereq (source file) and $@ is the name of the targ (Object file) 

clean:
	rm -f $(OBJ) $(TARG)
