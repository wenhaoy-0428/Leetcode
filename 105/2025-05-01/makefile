CC = g++
CFLAGS = -Wall -Wextra -std=c++17 -g -L ../build/lib -l gtest -l gtest_main

SRC = solution.cpp
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = solution

GTEST = ../build/_deps/googletest-src/googletest/include

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp ../util/util.h
	$(CC) $(CFLAGS) -I $(GTEST) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)
