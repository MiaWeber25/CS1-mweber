//this is where your function definitions can be (I can make multiple of these to classify them together)
//my makefile will need to have 
//CPP = finalproject.cpp functions.cpp
//Helpful website: https://www.geeksforgeeks.org/implementation-of-tic-tac-toe-game/
#include <iostream>
#include <iomanip>
#include <cstdlib>

//include header file for main functions file
#include "functions.hpp"
//include header file for userTurn functions
#include "userTurn.hpp"
//I could also make a test.cpp file to test all the functions (will need to include assert.h and my functions.hpp in order to test my functions)
using namespace std;


bool gameOver = false; //DELETE LATER?
int turns = 0; //variable to track how many turns have elapsed 
//2D array to store values in the game board. Initialized to spaces.
char gameBoard[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};
string wantContinue;


//MAIN FUNCTION
int main() {
    printMenu(); //print the menu options
    return 0;
}

//CLEAR SCREEN FUNCTION
void clearScreen() {
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

void clearBoard() {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            gameBoard[i][j] = ' ';
        }
    }
}

bool random2() { //DELETE LATER???

    return false;
}

//PRINT MENU FUNCTION
void printMenu() {
    clearScreen(); //clear the screen
    
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
            //input is invalid, prompt user to enter another value
            cout << "Invalid option, please enter a value between 1 and 4" << endl;
        }
    } while (random2() == false);
    //switch statement to call appropriate functions
    switch(option) {
        case 1:
        {
            //call the outputStats function to prompt for output file
            clearScreen(); //clear the screen
            playGame('E'); //start game play and pass difficulty level
            break;
        }
        case 2:
        {
            //call the outputStats function to prompt for output file
            clearScreen(); //clear the screen
            playGame('M'); //start game play and pass difficulty level
            break;
        }
        case 3:
        {
            //call the outputStats function to prompt for output file
            clearScreen(); //clear the screen
            playGame('H'); //start game play and pass difficulty level
            break;
        }
        case 4:
        default:
            cout << "Goodbye!\n";
            break; //exit the program
    }
}

//PRINT BOARD FUNCTION
void boardPrint(char gameBoard[3][3]) {
    cout << setfill('-') << setw(20) << " " << endl; //17
   for(int i=0; i<3; i++) {
       cout << "|  ";
       for(int j=0; j<3;j++) {
           cout << gameBoard[i][j];
           cout << "  |  ";
       }
       cout << endl << setfill('-') << setw(20) << " " << endl; //17
   }
}


//ISSUES WITH checkVictory IF STATEMENT LOGIC. FIGURE OUT LATER...

//CHECK VICTORY FUNCTION
char checkVictory(int turns) { //pass this function the array (and size of the array)????
    //char whoWon; //DO I NEED TO USE THIS????
    //check the row
    for (int i=0; i<9; i++) {
        //check to see if first space = second space = third space and make sure a character is placed there --> win by row
        if(gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][0] != ' ') {
            return gameBoard[i][0];
        } 
    //check the column
        //check to see if first space = second space = third space and make sure character is placed there --> win by column
        else if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != ' '){
            return gameBoard[0][i];
        } 
    //check the diagonal
        //check to see if first space = second space = third space and make sure character is placed there --> win by diagonal
        else if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != ' ') {
            return gameBoard[0][i];
        } else { //no one has one --> tie
            if (turns == 9) {
                return 'T';
            } else { //no one has won --> go on with turns
                return 'G';
            }
        } 
    }
}

//PLAY GAME FUNCTION
void playGame(char difficulty) {
    //flag = turns (declared in functios.hpp)
    bool gameOver = false;
    bool playerTurn = true; //is it the player's turn?
    while (gameOver == false) { 
        if (playerTurn == true) { //it's the player's turn
            userTurn(turns, gameBoard); //call userTurn function
            playerTurn = false;
        } else { //it's the computer's turn
            computerTurn(difficulty); //call computerTurn function
            playerTurn = true;
        }
        clearScreen();
        boardPrint(gameBoard); //print the new game board. IMPLEMENT A CLEAR FUNCTION HERE! clearBoard() then printBoard()
        //checkVictory(turns); //WILL WANT TO CALL CHECKVICTORY HERE (WHERE TO CALL THIS?)
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
        if(gameOver == true) {
            cout << "Do you want to play again? [y|n]" << endl;
            cin >> wantContinue;
            if(wantContinue == "Y" || wantContinue == "y") {
                clearBoard();
                printMenu();
            }
        }
     }

}

//COMPUTER TURN FUNCTION
void computerTurn(char difficulty) {
    if (difficulty == 'E') { //call gameLogicE
        gameLogicE();
    } else if (difficulty == 'M') { //call gameLogicM
        //cout << "calling gameLogicM()" << endl;
        gameLogicM();
    } else { //call gameLogicH
        gameLogicH();
    }
}

//EASY GAME LOGIC FUNCTION (random generated computer 'O' placement)
void gameLogicE() {
//GENERATE RANDOM PLACEMENT:
    //1. generate random numbers
    //2. see if that space is taken yet 
        //yes - generate another random number
        //no - place a 'O' in that space
    bool emptySpace = true;
    int rand1 = 0;
    int rand2 = 0;
    while(emptySpace == true) { //make sure that the space is empty
        //generate random numbers between 0 and 3
        rand1 = rand() %4;
        rand2 = rand() %4;
        //check to see if that space is empty
        if(gameBoard[rand1][rand2] == ' ') {
            gameBoard[rand1][rand2] = 'O'; //place an 'O' in that space
            emptySpace = false; //mark the space as not empty
        } else {
            continue; //space is already filled, generate 2 new random numbres
        }
    }
    turns +=1; //increment turns
    //NEED TO IMPROVE THIS BECAUSE IT ISN'T WORKING RIGHT NOW...
    /*
    
    */
}

//MEDIUM GAME LOGIC FUNCTION (computer just tries to win but not to block)
void gameLogicM() {
    tryToWin();
    turns +=1;
    //checkVictory(turns);
}

//HARD GAME LOGIC FUNCTION (computer tries to block and win)
void gameLogicH() { //THIS NEEDS TO CALL CHECKVICTORY!
    //see if you can win!
    //placement computerSelection;
    turns +=1;
    checkVictory(turns);
    //userTurn();
    //tryToWin();
    
}

void recordWin() {
    cout << "Win!" << endl;
}

void recordLoss() {
    cout << "Loss!" << endl;
}

void recordTie() {
    cout << "Tie!" << endl;
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
}






