/*
    Loops Lab
    Updated By: Mia Weber
    CSCI 111
    Date: 13/Oct/2021

    Program prints geometic shapes of given height with * using loops
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//FUNCITON PROTOTYPES
void printTriangle(int);
void printFlippedTriangle(int);
void clearScreen();
int main(int, char*[]);

//function takes height as an argument to print the triangle of that height with *
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

//implement the function that takes height as an argument and prints a triangle with * of given height
void printFlippedTriangle(int height) {
    //FIXME3... #FIXED#
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

//FIXME4... #FIXED#
//design and implement a function that takes an integer as height and prints a square of the given height wiht *
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
//function clears the screen system call
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
//fIXME5... add a loop to make the program continue to run until the user wants to quit
    bool keepRunning = true;
    while (true) {
      int height;
      cout << "Program prints geometric shapes of given height with *\n";
      cout << "Please enter the height of the shape: ";
      cin >> height;
//FIXME6... call clearScreen function to clear screen for each round of the loop #FIXED#
      clearScreen();
//call printTriangle function passing user entered height
      printTriangle(height);
//fIXME7... call printFlippedTriangle passing proper argument & manually test the function #FIXED#
      printFlippedTriangle(height);
//FIXME8... call the function defined in FIXME4 passing proper argument & manually test the function #FIXED#
      printSquare(height);
//FIXME9... prompt user to enter y/Y to continue anything else to quit
      char user_input;
      cout << "please enter [y|Y] to continue or any other key to quit...\n";
      cin >> user_input;
//FIXME10...use conditional statements to break the loop or continue the loop
      if (user_input != 'y' | user_input != 'Y')
        break;
      else
        keepRunning = true;
        continue;
      //cin.ignore(100,'\n');
      //cin.get();
      //clearScreen();
    }
    return 0;
}
