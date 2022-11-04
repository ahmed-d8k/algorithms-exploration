SRC = main.cpp
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