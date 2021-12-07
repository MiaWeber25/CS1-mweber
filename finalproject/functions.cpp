//this is where your function definitions can be (I can make multiple of these to classify them together)
//my makefile will need to have 
//CPP = finalproject.cpp functions.cpp
//Helpful website: https://www.geeksforgeeks.org/implementation-of-tic-tac-toe-game/
#include <iostream>
#include <iomanip>


#include "functions.hpp" //this allows you to import your function prototypes in this file as well
//I could also make a test.cpp file to test all the functions (will need to include assert.h and my functions.hpp in order to test my functions)
using namespace std;

//vector<vector<char>>gameBoard; //USING VECTOR VS ARRAY (fixed size so array feels easier...)
//char gameBoard[3][3];

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
bool random2() {

    return false;
}

void printMenu() {
    clearScreen();
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
    } while (random2() == false);
    //switch statement to call appropriate functions
    switch(option) {
        case 1:
        {
            //call the outputStats function to prompt for output file
            //call the gameLogicE function
            clearScreen();
            playGame('E');
            break;
        }
        case 2:
        {
            //call the outputStats function to prompt for output file
            //outputStats();
            //call the gameLogicM function
            clearScreen();
            playGame('M');
            break;
        }
        case 3:
        {
            //call the outputStats function to prompt for output file
            //outputStats();
            //call clearscreen! 
            clearScreen();
            //gameLogicH();
            playGame('H');
            break;
        }
        case 4:
        default:
            cout << "Goodbye!\n";
            break; //exit the program
    }
}

//void boardPrint(char * gameBoard[3][3]) {
void boardPrint() {
    cout << setfill('-') << setw(17) << " " << endl;
   for(int i=0; i<3; i++) {
       cout << "|  ";
       for(int j=0; j<3;j++) {
           cout << gameBoard[i][j];
           cout << "  |  ";
       }
       cout << endl << setfill('-') << setw(17) << " " << endl;
   }
}

void userTurn() {
    cout << "rows are numbered top to bottom as 1-3\n" << "columns are numbered left to right as 1-3\n";
    //printGrid(vector containing the player's positions);
    placement userSelection;
    //loop to verify that user input is in range of game board
    while (true) {
        cout << "please enter your selection row first seperated by a space. ex: 3 2\n";
        cin >> userSelection.row >> userSelection.col;
        userSelection.row -= 1; 
        userSelection.col -= 1;

        //check if choice is in range
        if (userSelection.row >=1 && userSelection.col >=1 and userSelection.row <= 3 && userSelection.col <= 3) {
            gameBoard[userSelection.row][userSelection.col] = 'X';
            //gameLogicH();
            boardPrint();
            break;
        } else {
            cin.clear();
        } 
        cout << "Your selection is out of range! Please enter another.\n";
        //implement computer game logic
        
    }


}

//ISSUES WITH checkVictory IF STATEMENT LOGIC. FIGURE OUT LATER...

//  ***AM I storing empty spaces as ' '? Maybe when I declare the array I will want to store a space everywhere so this actually works (might help with game logic as well...)
char checkVictory(int turns) { //pass this function the array (and size of the array)
    char whoWon;
    //CHECK ROW
    for (int i=0; i<9; i++) {
        //check to see if first space = second space = third space and make sure a character is placed there --> win by row
        if(gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][0] != ' ') {
            return gameBoard[i][0];
        } 
        //CHECK COLUMN
        //check to see if first space = second space = third space and make sure character is placed there --> win by column
        else if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != ' '){
            return gameBoard[0][i];
        } 
        //CHECK DIAGONAL
        //check to see if first space = second space = third space and make sure character is placed there --> win by diagonal
        else if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != ' ') {
            return gameBoard[0][i];
        } else {
            //no one has one
            if (turns == 9) {
                return 'T';
            } else {
                return 'G'; //go on with turns!
            }
        } 
    }
}


void playGame(char difficulty) {
    //flag
    int turns = 0;
    bool playerTurn = true;
    //while () {
        if (playerTurn == true) { //it's the player's turn
            userTurn();
        }
   //  }

}



void gameLogicH() { //THIS NEEDS TO CALL CHECKVICTORY!
    //see if you can win!
    //placement computerSelection;
    //*insert while loop to repeat until game is over
    userTurn();
    tryToWin();
    
}

void tryToWin() {
    
    for (int i=0; i<9; i++) {
        //check to see if you can win by row
        if(gameBoard[i][0] == 'O' && gameBoard[i][1] == 'O' && gameBoard[i][2] == ' ') {
            //place an O and win by row!
            gameBoard[i][2] = 'O';
            //gameBoard[userSelection.row][userSelection.col] = 'X'; DO I WANT TO USE PLACEMENT COMPUTERSELECTION FOR THIS??
        }
        //check to see if you can win by col!
        if(gameBoard[0][i] == 'O' && gameBoard[1][i] == 'O' && gameBoard[2][i] == ' ') {
            //place an O and win by col!
            gameBoard[2][i] = 'O';
        }
        //check to see if you can win by diag!
        if(gameBoard[0][i] == 'O' && gameBoard[1][i] == 'O' && gameBoard[2][i] == ' ') {
            //place an O and win by diag!
            gameBoard[2][i] = 'O';
        }
    }
    for (int j=0; j<3; j++) {
        for (int k=0; k<3; k++) {
            cout << "gameBoard @ " << j << ", " << k << gameBoard[j][k] << endl;
        }
    }
}






