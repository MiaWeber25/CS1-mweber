COMPILER = g++
COMPILER_FLAGS = -Wall -std=c++17
PROGRAM_NAME = jack-o-lantern.exe
CPP_FILES = jack-o-lantern.cpp 

build:
	$(COMPILER) $(COMPILER_FLAGS) $(CPP_FILES) -o $(PROGRAM_NAME)

run: 
	./$(PROGRAM_NAME)

unit_tests:
	./$(PROGRAM_NAME) test

kattis_tests:
	cat sample001.in | ./$(PROGRAM_NAME) | diff sample001.ans;
	cat sample002.in | ./$(PROGRAM_NAME) | diff sample002.ans;
	cat sample003.in | ./$(PROGRAM_NAME) | diff sample003.ans;
	echo "all Kattis sample tests cases passed..."

clean:
	rm -f $(PROGRAM_NAME) *.o