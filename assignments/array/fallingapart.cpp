/*
    Created By: Mia Weber
    Date: 03/Nov/2021
    Falling Apart - Kattis Problem located HERE: https://open.kattis.com/problems/fallingapart 

    Program takes number of dropped integers, as well as the integers that were dropped as input and outputs Alice's total and Bob's total.
    ALGORITHM STEPS:
    1. Put the valeus of the dropped integers into an array with a size of the number of dropped integers
    2. Sort the array from greatest value to lowest value
    3. Use the fact that all even indexes will be chosen by Alice (becuse she picks first) & all odd indexes will be chosen by Bob to iterate over array and update variables 
    4. output the total for Alice and the total for Bob.
*/

#include <string>
#include <algorithm>
#include <iterator> 
#include <iostream> 
#include <cassert>
#include <math.h>

using namespace std;

//FUNCITON PROTOTYPE
//void answer(int size, int pile[], int & aliceSum, int & bobSum);
void test();
void solve();

//main function that allows you to call test directly from the command line.
int main(int argc, char* argv[]) {
    if (argc > 1 && string(argv[1]) == "test")
        test();
    else 
        solve();
    return 0;
}

//answer function calculates the output. Takes size, the array, and sum values to update for Alice and Bob
void answer(int size, int pile[], int & aliceSum, int & bobSum) {
    //sort the array from greatest to smallest
    sort(pile, pile + size, greater<int>());
    //iterate over the array
    for (int j = 0; j < size; j++) { 
        //check to see if the index is even or odd. Even index = Alice's pick & Odd index = Bob's pick.
        if (j % 2 == 0) {
            //if the index is even, add the value located at that index to Alice's total
            aliceSum += pile[j];
        } else {
            //otherwise, add the value located at that index to Bob's total
            bobSum += pile[j];
        }
    }
}

//test function tests answer function with assert statements
void test() {

 //TEST CASE #1
    int size = 4;
    int aliceSum = 0;
    int bobSum = 0;
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

//solve function calls answer function and prints the correct output
void solve() {
    int size;
    int aliceSum = 0;
    int bobSum = 0;
    //create a new dynamic array to store the values of the integers
    int * pile = new int[size];
    //read in the integers from the command line and store them in the array pile
    cin >> size;
    for (int i=0; i< size; i++) {
        cin >> pile[i];
    }
    //call the answer function and pass it correct parameters
    answer(size, pile, aliceSum, bobSum);
    cout << aliceSum << " " << bobSum << endl;
    //deletes the dynamic array
    delete [] pile;
}