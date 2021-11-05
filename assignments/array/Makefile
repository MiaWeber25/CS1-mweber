COMPILER = g++
COMPILER_FLAGS = -Wall -std=c++17
PROGRAM_NAME = fallingapart
CPP_FILES = fallingapart.cpp 

build:
	$(COMPILER) $(COMPILER_FLAGS) $(CPP_FILES) -o $(PROGRAM_NAME)

run: 
	./$(PROGRAM_NAME)

unit_tests:
	./$(PROGRAM_NAME) test

kattis_tests:
	cat sample1.in | ./$(PROGRAM_NAME) | diff - sample1.ans;
	cat sample2.in | ./$(PROGRAM_NAME) | diff - sample2.ans;
	echo "all Kattis sample tests cases passed..."

clean:
	rm -f $(PROGRAM_NAME) *.o