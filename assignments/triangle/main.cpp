/* 
    HW 2 Area and Perimeter of a Triangle  
    Created By: Mia Weber
    Date: 09/13/2021

    This program finds and displays the perimeter and area of a given triangle.
    This program also verifies that the given side lengths will make a triangle. 

    Useful resource for functions: https://www.tutorialspoint.com/cplusplus/cpp_functions.htm 
    Useful resource for nan(Not a Number): https://www.tutorialspoint.com/checking-if-a-double-or-float-is-nan-in-cplusplus  
   
    Algorithm steps:
    1. prompt the user to enter three sides of a triangle
    2. calculate and print the perimeter of the given triangle
    3. calculate and print the area of a triangle using Heron's formula 
    4. BONUS: test if 3 sides actually form a triangle. 
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;
//perimeter function - called to calculate perimeter of triangle
float perimeter(float len1, float len2, float len3) {
    float result = len1 + len2 + len3; //math that outputs the perimeter of the triangle 
    cout << "\nThe perimeter of your triangle is: " << result << endl; //print the perimeter 
    return (0);
}

//area function - called to calculate area of triangle
float area(float len1, float len2, float len3) {
    float s = (len1+len2+len3)/2; //calculate the semiperimiter 
    float result = sqrt(s*(s-len1)*(s-len2)*(s-len3)); //math that outputs the area of the triangle
    cout << "\nThe area of your triangle is: " << result << endl; //print the area

//PROBLEM: if result = 0 it will go through if statement. if result = NaN it won't even enter logic statement...
//FIXED: seperated isan() and result == 0 into if and else if.

    //if else statement to notify user if triangle is correct
    if (isnan(result)) {
        cout<< "\nYou have failed to correctly make a triangle!\n";
    } else if (result == 0) {
        cout<< "\nYou have failed to correctly make a triangle!\n";
    } else if (result >=0.1) {
        cout<< "\nYou have correctly made a triangle.\n";
    }
    return (0);
}

//main function - take user input and print output of functions above
int main() {
    //local variable declaration
    float length1;
    float length2;
    float length3;

    //SIDE LENGTH ONE
    cout << "Please enter the lenth of side 1 of your triangle: \n";
    cin >> length1; //store user input into length1
    cin.ignore(256,'\n'); //use cin.ignore to ignore the extra space between calling cins (ex: I call cin again below)

    //SIDE LENGTH TWO 
    cout << "Please enter the length of side 2 of your triangle: \n";
    cin >> length2; //store user input into length2
    cin.ignore(256,'\n');

    //SIDE LENGTH THREE
    cout << "Please enter the length of side 3 of your triangle: \n";
    cin >> length3; //store user input into length3

    //CALL PERIMETER FUNCTION
   perimeter(length1, length2, length3);
   
    //CALL AREA FUNCTION
    area(length1, length2, length3);
    
    return 0;
}

