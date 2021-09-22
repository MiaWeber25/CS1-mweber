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

//constant to ensure answer is within margin or error (0.00001 accuracy up to 5 decimal points)
const float epsilon = 1e-5; 

//FUNCTION PROTOTYPES
double findDistance(int, int, int, int); //function that calculates distance between (x1,y1) and (x2,y2)

void test(); //function that runs automated testing

void clearScreen(); //function that clears console

bool want_continue(bool); //function that checks if the user wants to enter more points

//NOTE: system call is not a security best practice!
void clearScreen() {
    //use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else  
        system("clear");
    #endif
}

bool want_continue() {
    char response;
    bool repeat = false; //set to false automatically to avoid infinite loop
    
    cout << "Would you like to enter more points? Y/N\n"; //ask if user wants to enter more points
    cin >> response;
    cin.ignore(1000, '\n'); //ignore white space after cin

    if (response == 'Y') { //if the user enters 'Y' then set repeat to true (used in while loop in main)
        repeat = true;
        return repeat;
    } 
    else if (response == 'N') { //if the user enters 'N' then set repeat to false (therefore skipping the while loop)
        repeat = false;
        cout << "Enter to quit the program: "; //allows the user to exit the program without entering more points
        cin.get();
        cout << "Goodbye..." << endl;
        return repeat;
    }
}

double findDistance(int x1, int y1, int x2, int y2) { //function that actually does the math to find the distance
    //FIXME7 - find the distance between (x1, y1) and (x2, y2) #FIXED#
    double distance = sqrt(pow(x2-x1,2) + pow(y2-y1,2)); 
    return distance;
    }

//test function that tests findDistance function with 3 test cases
//use a loop to iterate through an array of test case data? (i++)
void test() {
    float result = findDistance(4,3,5,1);
    float expected = 2.236067f;
    assert(fabs(result-expected) <= epsilon); //accept the result if it's less than the error of margin
    //FIXME8 - add at least two mores test cases #FIXED#

    result = findDistance(-4,3,5,1);
    expected = 9.219544;
    assert(fabs(result-expected) <= epsilon);
   
    result = findDistance(4,-3,5,1);
    expected = 4.123106;
    assert(fabs(result-expected) <= epsilon);

    result = findDistance(-4,-3,-5,-1);
    expected = 2.236068;
    assert(fabs(result-expected) <= epsilon);

    cerr << "all tests passed..." <<endl;
    }

int main() {
   bool repeat = true; //initialize repeat to true in order to enter while loop
    int x1, y1, x2, y2; //vars to store two points (x1,y1) and (x2,y2)
    char ch; 

    //FIXME bonus - add loop until user wants to quit #FIXED#
    while (repeat == true) { //while the user wants to repeat, prompt for points and calculate distance between them
        clearScreen();
        cout << "Program calculates distance between 2 points on a 2D coordinate." <<endl;
        cout << "Enter a point in the form (x,y): ";

        //parse the input stream
        cin >> ch >> x1 >> ch >> y1 >> ch; //take the values entered and ignore (,)
        printf("(x1,y1) = (%d, %d)\n",x1,y1);

        cout << "Enter a second point in the form (x,y): ";

        //FIXME 3 - read/parse the second point and store data into variablesl x2 and y2 #FIXED#
        cin >> ch >> x2 >> ch >> y2 >> ch;
        printf("(x2,y2) = (%d, %d)\n",x2,y2);

        //FIXME 4 - call test function #FIXED#
        test(); 
       
        //FIXME5 - call findDistance() passing proper arguments #FIXED#
        double calculated_distance = findDistance(x1,y1,x2,y2);
        
        //FIXME6 - using printf function display the returned distance with proper description #FIXED# 
        printf("The distance between those points is: %lf\n",calculated_distance);
        
        cin.ignore(1000, '\n'); 
        repeat = want_continue(); //call want_continue function to see if user wants to enter more points
    } 
    assert(repeat == false); //if they don't want to repeat, then provide user the option to exit the program
    return 0; 
} 
