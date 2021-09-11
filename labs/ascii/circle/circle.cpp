/*
    Circle Lab
    By: Mia Weber
    CSCI 111
    Date: 09-Sept-2021

    This program prompts the user to enter the radius of a circle. 
    It then calculates and displays its area and circumference.

    Algorthim Steps: 
    1. Prompt the user to enter radius of circle and store in a var.
    2. calculate area using area formula and store in a var.
    3. calculate circumference using formula and store value in a var.
    4. output the calculated values for area and circumference
*/

#include <iostream>
#include <string>
#include <cmath> //library for math functions
#include <iomanip> //library for output formatting: setprecision()

using namespace std; 

int main() {
    //declare and initialize vars
    const double pi = 3.14159;
    double radius =0, area=0, circumference=0;

    string name; //var for user's name
    cout << "Hello! What is your full name?\n";
    getline(cin, name);
    //FIXME3: USE GETLINE TO READ USER'S FULLNAME AND STORE INTO VAR #FIXED#

    cout << "Nice to meet you, " << name << "!" << endl;

    //display program info to user
    cout << "\nThis program finds the area and circumference of a circle with the given radius.\n\n";

    //prompt user telling what to do
    cout << name << ", please enter the radius of a circle: ";
    cin >> radius; //read entered value and store it into radius variable

    area = pi * pow(radius, 2); //same as: pi * radius * radius
    //FIXME4: FIND THE CIRCUMFERENCE = #FIXED#
    circumference = 2 * pi * radius; 


    cout << "Your circle has a radius of: " << fixed << setprecision(6) << radius << endl;
    cout << "Your circle has an area of:\t" << area << '\n';
    //FIXME5: OUTPUT THE VALUE OF CIRCUMFERENCE = #FIXED#
    cout << "Your circle has a circumference of:\t" << circumference << '\n';

    //makes the console pause
    cout << "goodbye...\nHit enter to exit the program!" << '\n';
    cin.ignore(1000,'\n'); //ignore 1000 chars or until \n
    //make console wait for user input
    cin.get();
    return 0;

}
