COMPILER = g++
COMPILER_FLAGS = -Wall -std=c++17
PROGRAM_NAME = sort_two_numbers
CPP_FILES = sort_two_numbers.cpp 

build:
	$(COMPILER) $(COMPILER_FLAGS) $(CPP_FILES) -o $(PROGRAM_NAME)

run: 
	./$(PROGRAM_NAME)

unit_tests:
	./$(PROGRAM_NAME) test

kattis_tests:
	cat 1.in | ./$(PROGRAM_NAME) | diff - 1.ans;
	cat 2.in | ./$(PROGRAM_NAME) | diff - 2.ans;
	echo "all Kattis sample tests cases passed..."

clean:
	rm -f $(PROGRAM_NAME) *.o