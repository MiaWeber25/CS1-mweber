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


int answer(int size, int pile[]) {
    //alternate for players turns (variable and flag)
        //store element in correct player_sum variable and then change element to 0
    //stop iterating when all elements in the array are = 0
    //find and return the larger player_sum variable
    //**this just prints array for testing purposes** 
    //for (int j=0; j<size; j++) {
      //  cout << "first pile" << pile[j] << endl;
   // }
    //sort the array pile
    sort(pile, pile + size, greater<int>());
    //print the array for checking purposes 
    for (int j=0; j<size; j++) {
        cout << "second pile: " << pile[j] << endl;
    }
    //ALTERNATE FOR PLAYERS TURNS
    int aliceSum = 0;
    int bobSum = 0;
    //iterate over the array pile
    for (int j = 0; j < size; j++) { 
        //check to see if index is even or odd. Even index = Alice's pick & Odd index = Bob's pick.
        if (j % 2 == 0) {
            aliceSum += pile[j];
        } else if (j % 2 == 1) {
            bobSum += pile[j];
        }
    }
    cout << "alice Sum: " << aliceSum << endl;
    cout << "bob Sum: " << bobSum << endl;

}

void test() {
    //I NEED THREE TESTS + KATTIS TESTS
    //assert(answer(___, ___) == _____);
    //assert(answer(___, ___) == _____);
    //assert(answer(___, ___) == _____);
    cerr << "All test cases passed...\n";
}

void solve() {
    int size;
    //create a new dynamic array to store the values of the integers
    int * pile = new int[size]; //REMEMBER TO DELETE THIS STACK MEMORY!!!
    cin >> size;
    //read in the integers from the command line and store them in the array pile
    for (int i=0; i< size; i++) {
        cin >> pile[i];
    }
    //**this just prints array for testing purposes** 
    //for (int j=0; j<size; j++) {
     //   cout << pile[j] << endl;
    //}
    answer(size, pile);
    //cout << answer(size, & pile) << endl;
}