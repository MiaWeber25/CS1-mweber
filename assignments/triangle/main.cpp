/* 
    HW 2 Area and Perimeter of a Triangle  
    Created By: Mia Weber
    Date: 09/13/2021

    This program finds and displays the perimeter and area of a given triangle.
    This program also verifies that the given side lengths will make a triangle. 

    Useful resource for functions: https://www.tutorialspoint.com/cplusplus/cpp_functions.htm 
   
    Algorithm steps:
    1. prompt the user to enter three sides of a triangle
    2. calculate and print the area of a triangle using Heron's formula
    3. calculate and print the perimeter of the given triangle
    4. BONUS: test if 3 sides actually form a triangle. 
*/

#include <iostream>
#include <string>

using namespace std;

//area function - called to calculate area
float area(float len1, float len2, float len3) {
    float result;
    //result = //math that outputs the area of the triangle
    cout << "The area of your triangle is: " << result << endl;
    return (0); 
}

float perimeter(float len1, float len2, float len3) {
    float result;
    result = len1 + len2 + len3; //math that outputs the perimeter of the triangle 
    cout << "The perimeter of your triangle is: " << result << endl;
    return (0);
}

//perimeter function - called to calculate perimeter
    //int perimeter(float length1, float length2, float length3) {
        //float result;
       // result = length1 + length2 + length3; //math that outputs the perimeter of the triangle 
       // return (result);
    //}

//main function - take user input and print output of functions above
int main() {
    //local variable declaration: 
    float length1;
    float length2;
    float length3;


    //SIDE LENGTH ONE
    cout << "Please enter the lenth of side 1 of your triangle: \n";
    cin >> length1;
    cin.ignore(256,'\n');

    //SIDE LENGTH TWO 
    cout << "Please enter the length of side 2 of your triangle: \n";
    cin >> length2;
    cin.ignore(256,'\n');
    
    //SIDE LENGTH THREE
    cout << "Please enter the length of side 3 of your triangle: \n";
    cin >> length3;

    //CALCULATE AREA
    area(length1, length2, length3);
    

    //CALCULATE PERIMETER
   perimeter(length1, length2, length3);
    

    //if else statement to notify user if triangle is correct
    //NOT 180 = --> USE THE PATHAGORIAN THEREUM
    if (length1 + length2 + length3 == 180) {
        cout<< "You have correctly made a triangle!";
    } else {
        cout<< "You have failed to correctly make a triangle.";
    }

    return 0;
}