/*
    Final Project - TicTacToe
    CSCI 111 Fall 2021
    14/Dec/2021
    By: Mia Weber
    Program implements TicTacToe logic on three levels: easy, medium, and hard. Game statistics are written to output file of player's choice.
*/
//Helpful website: https://www.geeksforgeeks.org/implementation-of-tic-tac-toe-game/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>

//header file with function prototypes 
#include "main.hpp"
//include header file for userTurn function prototypes 
#include "userTurn.hpp"

using namespace std;

//MAIN FUNCTION
/*
    ~initializes gameBoard, stats, coins, asks user for name and gets output file name
    ~calls printMenu()
*/
int main() {
    char gameBoard[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
    };
    playerStats stats;
    peopleCoins coins;
    int turns = 0; //reset turns
    //what is the user's name?
    cout << "Hi! Welcome to TicTacToe! What is your name?" << endl;
    cin >> stats.name;
    //what is the output file name?
    cout << "Please enter the name of a file to output game statistics to: " << endl;
    cin >> stats.outputFile;
    printMenu(stats, turns, coins, gameBoard); //print the menu options
    return 0;
}

//CLEAR SCREEN FUNCTION
/*
    ~clears the screen using a system call
*/
void clearScreen() {
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

//CLEAR BOARD FUNCTION
/*
    ~sets all elements in the array gameBoard to spaces
*/
void clearBoard(char gameBoard[3][3]) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            gameBoard[i][j] = ' ';
        }
    }
}

//CONTINUE LOOP FUNCTION
/*
    ~continues the loop in printMenu() until the user wants to quit
*/
bool continueLoop() { 
    return false;
}

//PRINT MENU FUNCTION
/*
    ~takes struct of statistics, number of turns, struct of coins, and the gameBoard as input
    ~returns void
    ~prints the menu and uses switch statement to call appropriate function
    ~sets the userCoin and computerCoin based on player selection
*/
void printMenu(playerStats & stats, int &turns, peopleCoins &coins, char gameBoard[3][3]) {
    clearScreen(); //clear the screen
    
    //print the menu options:
    int option = 0;
    //clearScreen();
    cout << "Welcome to TicTacToe " << stats.name << "!" << endl;
    clearScreen();
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
    } while (continueLoop() == false);
        //determine which char represents the user & verify user input
        bool correctSelection = false;
        while(correctSelection == false) {
            cout << "Choose X or O: ";
                cin >> coins.userCoin;
                if (coins.userCoin == 'X') {
                    coins.computerCoin = 'O';
                    correctSelection = true;
                } else if (coins.userCoin == 'O') {
                    coins.computerCoin = 'X';
                    correctSelection = true;
                } else {
                    cout << "Please enter either 'X' or 'O'..." << endl;
                }
        }
    //switch statement to call appropriate functions
    switch(option) {
        case 1:
        {
            clearScreen(); //clear the screen
            playGame('E', stats, turns, coins, gameBoard); //start game play and pass difficulty level
            break;
        }
        case 2:
        {
            clearScreen(); //clear the screen
            playGame('M', stats, turns, coins, gameBoard); //start game play and pass difficulty level
            break;
        }
        case 3:
        {
            clearScreen(); //clear the screen
            playGame('H', stats, turns, coins, gameBoard); //start game play and pass difficulty level
            break;
        }
        case 4:
        default:
            cout << "Goodbye! Your game statistics are located in " << stats.outputFile << "!" << endl;
            outputStats(stats);
            break; //exit the program
    }
}

//PRINT BOARD FUNCTION
/*
    ~takes the gameBoard as input
    ~returns void
    ~prints the board to the terminal
*/
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

//CHECK VICTORY FUNCTION
/*
    ~takes number of turns and the gameBoard as inputs
    ~returns the char of who won, loss, a T indicating tie or a G indicating "go on"
    ~determines if someone has won or if there is a tie
*/
char checkVictory(int &turns, char gameBoard[3][3]) { 
    //check the row for a victory
     for (int i=0; i<3; i++) { 
        //check to see if first space = second space = third space and make sure a character is placed there --> win by row
        if(gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][0] != ' ') {
            //there is a victory! return which coin won
            return gameBoard[i][0];
        } 
    //check the column
        //check to see if first space = second space = third space and make sure character is placed there --> win by column
        if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != ' '){
            //there is a victory! return which coin won
            return gameBoard[0][i];
        } 
    //check the diagonal
        //check to see if first space = second space = third space and make sure character is placed there --> win by diagonal
        if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && gameBoard[0][0] != ' ') {
            //there is a victory! return which coin won
            return gameBoard[0][0];
        }
        if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && gameBoard[0][2] != ' ') {
            //there is a victory! return which coin won
            return gameBoard[0][2];
        }
     }
    //check to see if there is a tie
    if (turns == 9) {
        //there is a tie! return 'T' to indicate a tie
        return 'T';
    }      
    //no one has won and there is no tie! return 'G' to indicate to continue the game 
    return 'G';
}
    
//PLAY GAME FUNCTION
/*
    ~takes difficulty level, struct of statistics, number of turns, struct of coins, and the gameBoard as input
    ~returns void
    ~calls playerTurn and conputerTurn and checks to see if there was a victory after each turn
*/
void playGame(char difficulty, playerStats &stats, int &turns, peopleCoins &coins, char gameBoard[3][3]) {
    string wantContinue; //allows the user to play until they want to quit
    bool gameOver = false;
    bool playerTurn = true; //is it the player's turn?
    while (gameOver == false) { 
        if (playerTurn == true) { //it's the player's turn
            userTurn(turns, gameBoard, coins.userCoin); //call userTurn function
            checkVictory(turns, gameBoard); //second attempt at checkVictory
            playerTurn = false;
        } else { //it's the computer's turn
            computerTurn(difficulty, turns, coins, gameBoard); //call computerTurn function
            checkVictory(turns, gameBoard); //new attempt at checkVictory
            playerTurn = true;
        }
        turns+=1; //increment turns!
        clearScreen();
        boardPrint(gameBoard); //print the new game board.
        //call checkVictory and determine if a result needs to be reported...
        if (checkVictory(turns, gameBoard) == coins.userCoin) {
            gameOver = true;
            recordWin(stats);
        } else if (checkVictory(turns, gameBoard) == coins.computerCoin) {
            gameOver = true;
            recordLoss(stats);
        } else if (checkVictory(turns, gameBoard) == 'T') {
            gameOver = true;
            recordTie(stats);
        } 
         //it returned 'G' so continue with the game
        if(gameOver == true) {
            cout << "Do you want to play again? [y|n]" << endl;
            cin >> wantContinue;
            if(wantContinue == "Y" || wantContinue == "y") {
                clearBoard(gameBoard);
                turns = 0;
                printMenu(stats, turns, coins, gameBoard);
            } else {
                cout << "Goodbye! Your game statistics are located in " << stats.outputFile << "!" << endl;
                outputStats(stats);
            }
        }
     }

}

//COMPUTER TURN FUNCTION
/*
    ~takes difficulty level, number of turns, struct of coins, and the gameBoard as inputs
    ~returns void
    ~calls the correct gameLogic function based on user selection in printMenu()
*/
void computerTurn(char difficulty, int &turns, peopleCoins &coins, char gameBoard[3][3]) {
    if (difficulty == 'E') { //call gameLogicE
        gameLogicE(turns, coins, gameBoard);
    } else if (difficulty == 'M') { //call gameLogicM
        gameLogicM(turns, coins, gameBoard);
    } else { //call gameLogicH
        gameLogicH(turns, coins, gameBoard);
    }
}

//EASY GAME LOGIC FUNCTION
/*
    ~takes number of turns, struct of coins, and the gameBoard as inputs
    ~returns void
    ~implements the easy game logic which places a computerCoin in a random empty space
*/
void gameLogicE(int &turns, peopleCoins &coins, char gameBoard[3][3]) {
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
        srand((unsigned int)time(NULL)); //seed the value --> adds time to execution but makes it more random
        rand1 = rand() %3;
        //nums = rand1;
        rand2 = rand() %3;
        //check to see if that space is empty
        if(gameBoard[rand1][rand2] == ' ') {
            gameBoard[rand1][rand2] = coins.computerCoin; //place a computerCoin in that space
            emptySpace = false; //mark the space as not empty
        } else {
            continue; //space is already filled, generate 2 new random numbres
        }
    }
}

//MEDIUM GAME LOGIC FUNCTION
/*
    ~takes number of turns, struct of coins, and the gameBoard as inputs
    ~returns void
    ~implements the medium game logic where the computer tries to win but DOES NOT try to block the player
*/
void gameLogicM(int &turns, peopleCoins &coins, char gameBoard[3][3]) {
    char userCoin;
    char computerCoin;
    userCoin = coins.userCoin;
    computerCoin = coins.computerCoin;
    //see if you can win
    if(!completeSequence(computerCoin, computerCoin, gameBoard)) {
        //if you can't win, then just place a computerCoin randomly
        gameLogicE(turns, coins, gameBoard);
    }
}

//HARD GAME LOGIC FUNCTION
/*
    ~takes number of turns, struct of coins, and the gameBoard as inputs
    ~returns void
    ~implements the hard game logic where the computer BOTH tries to win and tries to block the player
*/
void gameLogicH(int &turns, peopleCoins &coins, char gameBoard[3][3]) { 
    char userCoin;
    char computerCoin;
    userCoin = coins.userCoin;
    computerCoin = coins.computerCoin;
    //see if you can win & see if you can block
    if(!completeSequence(computerCoin, computerCoin, gameBoard) && !completeSequence(userCoin, computerCoin, gameBoard)) {
        //if you can't win or block the player, then place a computerCoin randomly
        gameLogicE(turns, coins, gameBoard);
    } 
}

//RECORD WIN FUNCTION
/*
    ~takes struct of statistics as input
    ~returns void
    ~updates the statistics to indicate a player victory and indicates that a game is complete
*/
void recordWin(playerStats &stats) {
    cout << "Win!" << endl;
    //update the win count
    stats.numWins += 1;
    stats.gamesPlayed += 1;
}

//RECORD LOSS FUNCTION
/*
    ~takes struct of statistics as input
    ~returns void
    ~updates the statistics to indicate a player loss and indicates that a game is complete
*/
void recordLoss(playerStats &stats) {
    cout << "Loss!" << endl;
    //update the loss count
    stats.numLoss += 1;
    stats.gamesPlayed += 1;
}

//RECORD TIE FUNCTION
/*
    ~takes struct of statistics as input
    ~returns void
    ~updates the statistics to indicate a tie and indicates that a game is complete
*/
void recordTie(playerStats &stats) {
    cout << "Tie!" << endl;
    //update the ties count
    stats.numTies += 1;
    stats.gamesPlayed += 1;
}

//COMPLETE SEQUENCE FUNCTION
/*
    ~takes a coin to look for, a coin to place on the gameBoard, and the gameBoard as input
    ~returns a boolean value that indicates if the computer was able to block or win (ie. complete three in a row)
    ~implements both tryToWin logic and tryToBlock logic in one function. Attempts to fill out a row completely either to win or to block a player win
*/
bool completeSequence(char seekCoin, char placeCoin, char gameBoard[3][3]) {
    bool iWon = false;
    for (int j=0; j<3; j++) {
        //create a string of all the chars placed in each row
        string rowSequence;
        rowSequence.push_back(gameBoard[j][0]);
        rowSequence.push_back(gameBoard[j][1]);
        rowSequence.push_back(gameBoard[j][2]);
        //if there is a space and two userCoins, then place a computerCoin in the space
        if (count(rowSequence.begin(), rowSequence.end(), seekCoin) == 2  && count(rowSequence.begin(), rowSequence.end(), ' ') == 1) {
            gameBoard[j][rowSequence.find(' ')] = placeCoin;
            iWon = true;
        }
        //create a string of all the chars placed in each column
        string colSequence;
        colSequence.push_back(gameBoard[0][j]);
        colSequence.push_back(gameBoard[1][j]);
        colSequence.push_back(gameBoard[2][j]);
        if (count(colSequence.begin(), colSequence.end(), seekCoin) == 2 && count(colSequence.begin(), colSequence.end(), ' ') == 1) {
            gameBoard[colSequence.find(' ')][j] = placeCoin;
            iWon = true;
        }
    }
    //create a string of all the chars places in each diagonal
    string diagSequence;
    diagSequence.push_back(gameBoard[0][0]);
    diagSequence.push_back(gameBoard[1][1]);
    diagSequence.push_back(gameBoard[2][2]);
    if (count(diagSequence.begin(), diagSequence.end(), seekCoin) == 2 && count(diagSequence.begin(), diagSequence.end(), ' ') == 1) {
        //find the location of the space
        int spaceLocation = diagSequence.find(' ');
        gameBoard[spaceLocation][spaceLocation] = placeCoin;
        iWon = true;
    }
    //create a string of all the chars places in each reverse diagonal
    diagSequence = "";
    diagSequence.push_back(gameBoard[0][2]);
    diagSequence.push_back(gameBoard[1][1]);
    diagSequence.push_back(gameBoard[2][0]);
    if (count(diagSequence.begin(), diagSequence.end(), seekCoin) == 2 && count(diagSequence.begin(), diagSequence.end(), ' ') == 1) {
        //find the location of the space
        int spaceLocation = diagSequence.find(' ');
        gameBoard[spaceLocation][spaceLocation-2] = placeCoin;
        iWon = true;
    }
    return iWon;
}

//OUTPUT STATS FUNCTION
/*
    ~takes struct of statistics as input
    ~returns void
    ~writes game statistics (name, number of wins, number of losses, number of ties, and number of games played) to output file of user choice
*/
void outputStats(playerStats &stats) {
    ofstream fout;
    fout.open(stats.outputFile);
    //write statistics!
    fout << "Player Name: " << stats.name << endl;
    fout << "Number of player victories: " << stats.numWins << endl;
    fout << "Number of player losses: " << stats.numLoss << endl;
    fout << "Number of tie games: " << stats.numTies << endl;
    fout << "Number of games played: " << stats.gamesPlayed << endl;
    //close file
    fout.close();
}


/*FUTURE OPTIMIZATIONS:
1. only check for a victory after five turns have passed (there is not way to win without five turns)
2. break into more c++ files in order to clarify code even further
3. rather than simply placing a computerCoin in a random space if it can't win or block, 
   it could place a computerCoin next to an existing computerCoin to build towards a win
*/

