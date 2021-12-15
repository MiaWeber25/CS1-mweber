/*
    Final Project - TicTacToe
    CSCI 111 Fall 2021
    14/Dec/2021
    By: Mia Weber
*/
//Helpful website: https://www.geeksforgeeks.org/implementation-of-tic-tac-toe-game/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>

//header file with function prototypes 
#include "functions.hpp"
//include header file for userTurn function prototypes 
#include "userTurn.hpp"

using namespace std;


bool gameOver = false; //boolean variable to determine if the game is still in play or not
int turns = 0; //integer variable to track how many turns have elapsed (used for determining Tie & stats)
char gameBoard[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
}; //2D char array to store values in the game board. Initialized to spaces.
string wantContinue; //string variable to allow user to play until they want to quit
//char variables to allow user to select either X or O
char userCoin; 
char computerCoin;


//MAIN FUNCTION
int main() {
    playerStats stats;
    cout << "Hi! Welcome to TicTacToe! What is your name?" << endl;
    cin >> stats.name;
    printMenu(stats); //print the menu options
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

//CLEAR BOARD FUNCTION
//sets all elements in the array to spaces
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
void printMenu(playerStats & stats) {
    clearScreen(); //clear the screen
    
    //print the menu options:
    int option = 0;
    cout << "Welcome to TicTacToe " << stats.name << "!" << endl;
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
        //determine which char represents the user
        //COME BACK AND ADD A VERIFICATION THAT USER ENTERED X or O.
        cout << "Choose X or O: ";
            cin >> userCoin;
            if (userCoin == 'X') {
                computerCoin = 'O';
            } else {
                computerCoin = 'X';
            }
    switch(option) {
        case 1:
        {
            //call the outputStats function to prompt for output file
            clearScreen(); //clear the screen
            playGame('E', stats); //start game play and pass difficulty level
            break;
        }
        case 2:
        {
            //call the outputStats function to prompt for output file
            clearScreen(); //clear the screen
            playGame('M', stats); //start game play and pass difficulty level
            break;
        }
        case 3:
        {
            //call the outputStats function to prompt for output file
            clearScreen(); //clear the screen
            playGame('H', stats); //start game play and pass difficulty level
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
    char returnValue;
     for (int i=0; i<3; i++) { 
        //check to see if first space = second space = third space and make sure a character is placed there --> win by row
        if(gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][0] != ' ') {
            //return gameBoard[i][0];
            returnValue = gameBoard[i][0];
            break;
        } 
    //check the column
        //check to see if first space = second space = third space and make sure character is placed there --> win by column
        if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != ' '){
            //return gameBoard[0][i];
            returnValue = gameBoard[0][i];
            break;
        } 
    //check the diagonal
        //check to see if first space = second space = third space and make sure character is placed there --> win by diagonal
        if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && gameBoard[0][0] != ' ') {
            //return gameBoard[0][i];
            returnValue = gameBoard[0][0];
            break;
        }
        if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && gameBoard[0][2] != ' ') {
            returnValue = gameBoard[0][2];
            break;
        }
         else { //no one has one --> tie
            if (turns == 9) {
                //return 'T';
                returnValue = 'T';
            } else { //no one has won --> go on with turns
                //cout << "returning G for go on";
                returnValue = 'G';
            }
        }
     }
    return returnValue;

}
    

//PLAY GAME FUNCTION
void playGame(char difficulty, playerStats &stats) {
    //flag = turns (declared in functios.hpp)
    bool gameOver = false;
    bool playerTurn = true; //is it the player's turn?
    while (gameOver == false) { 
        if (playerTurn == true) { //it's the player's turn
            userTurn(turns, gameBoard, userCoin); //call userTurn function
            checkVictory(turns); //second attempt at checkVictory
            playerTurn = false;
        } else { //it's the computer's turn
            computerTurn(difficulty); //call computerTurn function
            checkVictory(turns); //new attempt at checkVictory
            playerTurn = true;
        }
        clearScreen(); //I WILL NEED TO UNCOMMENT THIS EVENTUALLY!!!!!
        boardPrint(gameBoard); //print the new game board.
        //checkVictory(turns); //WILL WANT TO CALL CHECKVICTORY HERE (WHERE TO CALL THIS?)
        if (checkVictory(turns) == userCoin) {
            gameOver = true;
            recordWin(stats);
            // break;
        } else if (checkVictory(turns) == computerCoin) {
            gameOver = true;
            recordLoss(stats);
            //break;
        } else if (checkVictory(turns) == 'T') {
            gameOver = true;
            recordTie(stats);
            // break;

        } 
         //it returned 'G' so continue with the game
        if(gameOver == true) {
            cout << "Do you want to play again? [y|n]" << endl;
            cin >> wantContinue;
            if(wantContinue == "Y" || wantContinue == "y") {
                clearBoard();
                printMenu(stats);
            }
        }
     }

}

//COMPUTER TURN FUNCTION
void computerTurn(char difficulty) {
    if (difficulty == 'E') { //call gameLogicE
        gameLogicE();
    } else if (difficulty == 'M') { //call gameLogicM
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
    //int rand1 = 0;
    int rand1 = 0;
    //int rand2 = 0;
    int rand2 = 0;
    //int nums;
    //int nums2;
    while(emptySpace == true) { //make sure that the space is empty
        //generate random numbers between 0 and 3
        srand((unsigned int)time(NULL)); //seed the value --> found a way around
        rand1 = rand() %3;
        //nums = rand1;
        rand2 = rand() %3;
        //nums2 = rand2;
        //cout << "rand1: " << rand1;
        //cout << endl << "rand2: " << rand2;
        //check to see if that space is empty
        if(gameBoard[rand1][rand2] == ' ') {
            gameBoard[rand1][rand2] = computerCoin; //place an 'O' in that space
            emptySpace = false; //mark the space as not empty
        } else {
            continue; //space is already filled, generate 2 new random numbres
        }
    }
    turns +=1; //increment turns
}

//MEDIUM GAME LOGIC FUNCTION (computer just tries to win but not to block)
void gameLogicM() {
    if(!completeSequence(computerCoin, computerCoin)) {
        gameLogicE();
    }
    turns +=1;
}

//HARD GAME LOGIC FUNCTION (computer tries to block and win)
void gameLogicH() { //THIS NEEDS TO CALL CHECKVICTORY!
    //see if you can win and see if you can block
    if(!completeSequence(computerCoin, computerCoin) && !completeSequence(userCoin, computerCoin)) {
        gameLogicE();
    } 
    turns +=1;
}

void recordWin(playerStats &stats) {
    cout << "Win!" << endl;
    //update the win count
    stats.numWins += 1;
}

void recordLoss(playerStats &stats) {
    cout << "Loss!" << endl;
    //update the loss count
    stats.numLoss += 1;
}

void recordTie(playerStats &stats) {
    cout << "Tie!" << endl;
    //update the ties count
    stats.numTies += 1;
}

bool completeSequence(char seekCoin, char placeCoin) {
    bool iWon = false;
    for (int j=0; j<3; j++) {
        string rowSequence;
        rowSequence.push_back(gameBoard[j][0]);
        rowSequence.push_back(gameBoard[j][1]);
        rowSequence.push_back(gameBoard[j][2]);
        //if there is a space and two userCoins, then place a computerCoin in the space
        if (count(rowSequence.begin(), rowSequence.end(), seekCoin) == 2  && count(rowSequence.begin(), rowSequence.end(), ' ') == 1) {
            gameBoard[j][rowSequence.find(' ')] = placeCoin;
            iWon = true;
        }

        string colSequence;
        colSequence.push_back(gameBoard[0][j]);
        colSequence.push_back(gameBoard[1][j]);
        colSequence.push_back(gameBoard[2][j]);
        if (count(colSequence.begin(), colSequence.end(), seekCoin) == 2 && count(colSequence.begin(), colSequence.end(), ' ') == 1) {
            gameBoard[colSequence.find(' ')][j] = placeCoin;
            iWon = true;
        }
    }
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

void outputStats(playerStats &stats) {
    //calculate stats
    //playerStats stats; DO THIS IN MAIN INSTEAD

    string outputFile;
    cout << "Good Job! Please enter the name of a file to output game statistics to: " << endl;
    cin >> outputFile;
        
    ofstream fout;
    fout.open(outputFile);
    //write statistics!
    fout << "Player Name: " << stats.name << endl;
    fout << "Number of player victories: " << stats.numWins << endl;
    fout << "Number of player losses: " << stats.numLoss << endl;
    fout << "Number of games played: " << stats.gamesPlayed << endl;
    //close file
    fout.close();
}




