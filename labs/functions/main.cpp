/*
Functions Lab
Updated By: Mia Weber
CSI III
Date: 15/Sept/2021

Program prompts the user to enter two points in the form (x1, y1) and (x2, y2) and finds the distance between the two points using a function
Algorithm steps:
1. Define a function called findDistance() that takes four parameters x1,y1 and x2,y2 as two poitns
    a. finds the distance between them using the equation: sart((x2-x1)^2+ (y2-y1)^2)
    b. returns the calcualted distance value
2. Prompt user to enter two points in (x,y) format
3. Store them into 4 individual vars
4. call function getDistance by passing 4 entered numbers as arguments
5. display results with proper description. format output numbers to 2 decimal points.
6. test and validate program output is correct for a given set of input points
7. BONUS: use a loop to repeat step 2-6 until the user wants to quit
*/

#include <iostream>
#include <cstdio>
#include <cassert>
#include <cmath>

using namespace std;

const float epsilon = 1e-5; //0.00001 accurary up to 5 decimal points; margin of error

//function prototypes

//function that calculates the distance between two points
//x1,y1 and x2,y2 and returns the calculated value
double findDistance(int, int, int, int);

//test function that runs automated testing
void test();

//function clears the screen system call
//NOTE: system call is not a security best practice!
void clearScreen() {
    //use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else  
        system("clear");
    #endif
}

int main() {
    int x1, y1, x2, y2; //vars to store two poitns (x1,y1) and (x2,y2)
    char ch;

    //FIXME-bonus - add loop until user wants to quit
    //the loop will execute the following block of code
    {
        clearScreen();
        cout << "Program calculates distance between 2 points on a 2D coordinate." <<endl;
        cout << "Enter a point in the form (x,y): ";
        //parse the input stream
        cin >> ch >> x1 >> ch >> y1 >> ch; //value stored in ch is ignored
        printf("(x1,y1) = (%d, %d)\n",x1,y1);

        cout << "Enter a second point in the form (x,y: ";
        //FIXME 3 - read/parse the second point and store data into variablesl x2 and y2
        //FIXME 4 - call test function

        //FIXME5 - call findDistance() passing proper arguments
        //FIXME6 - using printf function display the returned distance with proper description
    }

    cin.ignore(1000, '\n');
    cout << "Enter to quit the program: ";
    cin.get();
    cout << "Goodbye..." << endl;
    return 0;
} 

double findDistance(int x1, int y1, int x2, int y2) {
    //FIXME7 - find the distance between (x1, y1) and (x2, y2)
    //following the algorithm in step 1
    //return the calculated distance
    return 0.000000;
}

//test function that tests findDistance function with 3 test cases
void test() {
    float result = findDistance(4,3,5,1);
    float expected = 2.236067f;
    assert( fabs(result-expected) <= epsilon); //accept the result if it's less than the error of margin
    //FIXME8 - add at least two mores test cases
    cerr << "all tests passed..." <<endl;
}