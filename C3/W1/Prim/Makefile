SRC = main.cpp tests/test_prim.cpp src/prim.cpp ../../../FileHandling/src/file_reader.cpp ../../../DistanceGraph/src/distance_graph.cpp ../../../DistanceGraph/src/vertex.cpp
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
	rm -f $(OBJ) $(TARG)