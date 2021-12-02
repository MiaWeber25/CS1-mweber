//this is where your function definitions can be (I can make multiple of these to classify them together)
//my makefile will need to have 
//CPP = finalproject.cpp functions.cpp
#include <iostream>


#include "functions.hpp" //this allows you to import your function prototypes in this file as well
//i could also make a test.cpp file to test all the functions (will need to include assert.h and my functions.hpp in order to test my functions)
using namespace std;

//vector<vector<char>>gameBoard;
char gameBoard[3][3];

struct placement {
    int row;
    int col;
};

int main() {
    printMenu();
    //gamePlay();
    return 0;
}
void clearScreen() {
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}


void printMenu() {
    //print the menu options:
    int option = 0;
    cout << "Welcome to TicTacToe!\n";
    cout << "Below are the menu options:\n";
    cout << "[1] Easy\n";
    cout << "[2] Medium\n";
    cout << "[3] Hard\n";
    cout << "[4] Quit\n";
    cout << "Enter one of the menu options [1-4]: ";
    //check if the selected option is in range
    do {
        if (cin >> option && option >= 1 && option <= 4) {
            //input is valid, break loop
            break;
        }
        else {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid option, please enter a value between 1 and 4" << endl;
        }
    } while (true);
    //switch statement to call appropriate functions
    switch(option) {
        case 1:
        {
            //call the outputStats function to prompt for output file
            //call the gameLogicE function
            clearScreen();
            gamePlay();
            break;
        }
        case 2:
        {
            //call the outputStats function to prompt for output file
            //outputStats();
            //call the gameLogicM function
            clearScreen();
            gamePlay();
            break;
        }
        case 3:
        {
            //call the outputStats function to prompt for output file
            //outputStats();
            //call clearscreen! 
            clearScreen();
            gamePlay();
            break;
        }
        case 4:
        default:
            cout << "Goodbye!\n";
            break; //exit the program
    }
}

void gamePlay() {
    cout << "rows are numbered top to bottom as 1-3\n" << "columns are numbered left to right as 1-3\n";
    //printGrid(vector containing the player's positions);
    placement userSelection;
   // do {
   // } while(checkResult==false);
    //loop to verify that user input is in range of game board
    while (true) {
        cout << "please enter your selection row first seperated by a space. ex: 3 2\n";
        cin >> userSelection.row >> userSelection.col;

        //check if choice is in range
        if (userSelection.row >=1 && userSelection.col >=1 and userSelection.row <= 3 && userSelection.col <= 3) {
            gameBoard[userSelection.row][userSelection.col] = 'X';
            break;
        } else {
            cin.clear();
        } 
        cout << "Your selection is out of range! Please enter another.\n";
    }


}
/*
void checkResult() {
    //iterate over the 2D array gameBoard
    int xCount;
    int oCount;
    for (int r; r<3; r++) { //row
        for (int c; c <3; c++) { //col
            if(gameBoard[r][c] == 'X') 
                xCount+=1;
            else if (gameBoard[r][c] == 'O')
                oCount+=1;
            else 
                continue;
        }
    }
    if(xCount == 3) 
        recordPlayerWin();
    else if (oCount == 3)
        recordPlayerLoss();
    else
        recordTie();
}
*/

void checkResult() {
    //iterate over gameBoard 
    for(int r =0; r <3; r++) { //row
        for(int c = 0; c <3; c++) { //col
            if(gameBoard[r][c] == 'X' || gameBoard[r][c] == 'O')
                checkSurroundings(r, c, gameBoard[r][c]);
        }
    }

}


void checkSurroundings(int& r, int& c, char& token) {
    //check to see if there is a matching token the surrounding spaces
    
}












