/*
    Created By: Mia Weber
    Date: 03/Nov/2021
    Falling Apart - Kattis Problem located HERE: https://open.kattis.com/problems/fallingapart 

    Program does _____
    ALGORITHM STEPS:
    1.
    2.
    3.
*/

//use function[s] design your solution in such a way that it can be tested independently using assert statements
//write a test function that automatically tests (using assert functions) three different input valeus other than the ones provided by the problem
    // test must be called when an argument "test" is passed to main
//screenshot of code, testing, and kattis accepted submission
//update README

#include <string>
#include <algorithm>
#include <iterator> //DO I NEED THIS ONE? --> begin() and end()
#include <iostream> 
#include <cassert>
#include <math.h>


using namespace std;

//FUNCITON PROTOTYPE
void test();
//int answer(int * pile[], int size);
void solve();


int main(int argc, char* argv[]) {
    if (argc > 1 && string(argv[1]) == "test")
        test();
    else 
        solve();
    return 0;
}


void answer(int size, int pile[], int & aliceSum, int & bobSum) {
    //sort the array pile
    sort(pile, pile + size, greater<int>());
   
    //iterate over the array pile
    for (int j = 0; j < size; j++) { 
        //check to see if index is even or odd. Even index = Alice's pick & Odd index = Bob's pick.
        if (j % 2 == 0) {
            aliceSum += pile[j];
        } else if (j % 2 == 1) {
            bobSum += pile[j];
        }
    }
}

void test() {
    //I could have a problem with aliceSum an bobSum not resetting for each test but we'll see...
    int aliceSum = 0;
    int bobSum = 0;

 //TEST CASE #1
    int size = 4;
    int pile1[] = {5, 7, 8, 2};
    answer(size, pile1, aliceSum, bobSum);
    assert(aliceSum == 13 && bobSum == 9);
//TEST CASE #2
    size = 8;
    aliceSum = 0;
    bobSum = 0;
    int pile2[] = {8, 2, 3, 1, 7, 3, 7, 1};
    answer(size, pile2, aliceSum, bobSum);
    assert(aliceSum == 19 && bobSum == 13);
//TEST CASE #3
    size = 3;
    aliceSum = 0;
    bobSum = 0;
    int pile3[] = {2, 9, 14};
    answer(size, pile3, aliceSum, bobSum);
    assert(aliceSum == 16 && bobSum == 9);

    cerr << "All test cases passed...\n";
}

void solve() {
    int size;
    int aliceSum = 0;
    int bobSum = 0;
    //create a new dynamic array to store the values of the integers
    int * pile = new int[size]; //REMEMBER TO DELETE THIS STACK MEMORY!!!
    cin >> size;
    //read in the integers from the command line and store them in the array pile
    for (int i=0; i< size; i++) {
        cin >> pile[i];
    }
    answer(size, pile, aliceSum, bobSum);
    cout << aliceSum << " " << bobSum << endl;
}