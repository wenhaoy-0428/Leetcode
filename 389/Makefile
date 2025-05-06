CC = g++
CFLAGS = -Wall -Wextra -std=c++17

SRC = solution.cpp
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = solution

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp ../util/util.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)