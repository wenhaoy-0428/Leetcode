CC = g++
CFLAGS = -Wall -Wextra -std=c++17 -g

LDFLAGS = -L/usr/local/lib
LDLIBS = -lgtest_main -lgtest

SRC = solution.cpp
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = solution


all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

%.o: %.cpp ../util/util.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)
