//this is where your function definitions can be (I can make multiple of these to classify them together)
//my makefile will need to have 
//CPP = finalproject.cpp functions.cpp
//Helpful website: https://www.geeksforgeeks.org/implementation-of-tic-tac-toe-game/
#include <iostream>
#include <iomanip>
#include <cstdlib>


#include "functions.hpp" //this allows you to import your function prototypes in this file as well
#include "userTurn.hpp"
//I could also make a test.cpp file to test all the functions (will need to include assert.h and my functions.hpp in order to test my functions)
using namespace std;

//vector<vector<char>>gameBoard; //USING VECTOR VS ARRAY (fixed size so array feels easier...)
//char gameBoard[3][3];

bool gameOver = false;
int turns = 0;
char (*gameBoardptr)[3] = gameBoard;

int main() {
    printMenu();
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
void boardPrint(char (*ptrToGameBoard)[3]) {
    cout << setfill('-') << setw(17) << " " << endl;
   for(int i=0; i<3; i++) {
       cout << "|  ";
       for(int j=0; j<3;j++) {
           cout << ptrToGameBoard[i][j];
           cout << "  |  ";
       }
       cout << endl << setfill('-') << setw(17) << " " << endl;
   }
}
//USERTURN FUNCTION GOES HERE


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
    //flag = turns (declared in functios.hpp)
    //int turns = 0;
    bool gameOver = false;
    bool playerTurn = true;
    while (gameOver == false) {
        if (playerTurn == true) { //it's the player's turn
            userTurn(turns, gameBoardptr);
        } else { //it's the computer's turn
            computerTurn(difficulty);
        }
        boardPrint(gameBoardptr);
     }

}

void computerTurn(char difficulty) {
    int a, b;
    cin >> a >> b;
    gameBoard[a][b] = 'O';


    if (difficulty == 'E') { //call gameLogicE
        gameLogicE();
    } else if (difficulty == 'M') { //call gameLogicM
        gameLogicM();
    } else { //call gameLogicH
        gameLogicH();
    }
}

void gameLogicE() {
    //implement some kind of while loop to continue that way I can use break and continue below.
//GENERATE RANDOM PLACEMENT:
    //1. generate random numbers
    //2. see if that space is taken yet 
        //yes - generate another random number
        //no - place a 'O' in that space
    bool emptySpace = false;
    int rand1 = 0;
    int rand2 = 0;
    while(emptySpace == false) {
        rand1 = rand() %4;
        rand2 = rand() %4;
        //cout << rand1 << " " << rand2;
        if(gameBoard[rand1][rand2] == ' ') {
            gameBoard[rand1][rand2] = 'O';
            boardPrint(gameBoardptr);
            emptySpace = true;
        } else {
            continue; 
        }
    }

    //gameBoard[rand() %3][rand() %3] = 'O';
    turns +=1;
    if (checkVictory(turns) == 'X') {
        gameOver = true;
        recordWin();
       // break;
    } else if (checkVictory(turns) == 'O') {
        gameOver = true;
        recordLoss();
        //break;
    } else if (checkVictory(turns) == 'T') {
        gameOver = true;
        recordTie();
       // break;
    } else { //it returned 'G' so continue with the game
        //continue with game
        //continue;
    }
}

void gameLogicM() {
    turns +=1;
    checkVictory(turns);
}

void gameLogicH() { //THIS NEEDS TO CALL CHECKVICTORY!
    //see if you can win!
    //placement computerSelection;
    turns +=1;
    checkVictory(turns);
    //userTurn();
    //tryToWin();
    
}

void recordWin() {

}

void recordLoss() {

}

void recordTie() {

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






