COMPILER = g++
COMPILER_FLAGS = -Wall -std=c++17
PROGRAM_NAME = anewalphabet
CPP_FILES = anewalphabet.cpp 

build:
	$(COMPILER) $(COMPILER_FLAGS) $(CPP_FILES) -o $(PROGRAM_NAME)

run: 
	./$(PROGRAM_NAME)

unit_tests:
	./$(PROGRAM_NAME) test

kattis_tests:
	cat base.in | ./$(PROGRAM_NAME) | diff - base.ans;
	cat frequency.in | ./$(PROGRAM_NAME) | diff - frequency.ans;
	cat new.in | ./$(PROGRAM_NAME) | diff - new.ans;
	echo "all Kattis sample tests cases passed..."

clean:
	rm -f $(PROGRAM_NAME) *.o