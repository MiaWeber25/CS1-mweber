/*
    Loops Lab
    Updated By: Mia Weber
    CSCI 111
    Date: 13/Oct/2021

    Program prints geometric shapes of given height with * using loops.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//FUNCTION PROTYPES
void printTriangle(int);
void printFlippedTriangle(int);
void clearScreen();
int main (int, char*[]);

//function takes height as argument to print the triangle of that height with *
void printTriangle(int height) {
    int row = 1;
    //row
    while (row <= height) {
        //column
        for (int col = 1; col <= row; col++) {
            cout << "* ";
        }
        row += 1;
        cout << endl;
    }
    cout << endl;
}
//function that takes height as an argument and prints a triangle with * of given height
//FIXME3...#FIXED#
void printFlippedTriangle(int height) {
    //row
    for(int row = 1; row <= height; row++) {
        //column
        for (int col = height; col >= row; col--) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;

}
//function that takes an integer as height and prints square of the given height with *
//FIXME4...#FIXED#
void printSquare(int height) {
    int row = 1;
    //row
    while (row <= height) {
        //column
        for (int col = 0; col <= height; col++) {
            cout << "* ";
        }
        row +=1;
        cout << endl;
    }
    cout << endl;
}
//function clears the screen using system call
//NOTE: system call is not a security best practice!
void clearScreen() {
    //use "clear" command in Mac
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

int main(int argc, char* argv[]) {

//add a loop to make the program continue to run until the user wants to quit
//FIXME5...#FIXED#
  while (true) {

//call clearScreen function to clear the screen for each round of the loop
//FIXME6...#FIXED#
    clearScreen();
    int height;
    cout << "Program prints geometric shapes of given height with *\n";
    cout << "Please enter the height of the shape: ";
    cin >> height;

//call printTriangle, printFlippedTriangle, and printSquare passing proper argument
//FIXME 7 & FIXME 8...#FIXED#
    printTriangle(height);
    printFlippedTriangle(height);
    printSquare(height);

//promt the user to enter y/Y to continue or anything else to quit
//FIXME9...#FIXED#
    string user_input;
    cout << "please enter [y|Y] to continue or any other key to quit...";
    cin >> user_input;

//use conditional statements to break the loop or continue the loop
//FIXME10...#FIXED#
    if (user_input == "y" || user_input == "Y") {
      //clearScreen();
      continue;
      //printTriangle(height);

    } else  {
        break;
    }
  }
  return 0;
}
