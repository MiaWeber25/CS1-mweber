COMPILER = g++
COMPILER_FLAGS = -Wall -std=c++17
PROGRAM_NAME = functions
CPP_FILES = main.cpp userTurn.cpp

build:
	$(COMPILER) $(COMPILER_FLAGS) $(CPP_FILES) -o $(PROGRAM_NAME)

run: 
	./$(PROGRAM_NAME)

unit_tests:
	./$(PROGRAM_NAME) test

clean:
	rm -f $(PROGRAM_NAME) *.o