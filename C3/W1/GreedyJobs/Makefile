SRC = main.cpp tests/test_greedy_job.cpp src/greedy_job.cpp src/job.cpp ../../../FileHandling/src/file_reader.cpp
TARG = output 
CC = g++
CFLAGS = -Wall -g3 -static
LIB = -lm
OBJ = $(SRC:.cpp=.o)

all: $(TARG)

$(TARG): $(OBJ)
	$(CC) -o $(TARG) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARG)

