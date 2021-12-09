#pragma once

//void printBoard(); //function to print the game board. called every time a new game is started
void clearBoard(); //function to clear the board & screen. called before printBoard every time a new game is started (will I need this?) 
void recordLoss(); //updates stats data on the win and displays message to the player informing them of a PLAYER WIN
void recordWin(); //updates stats data on the loss and displays message to the player informing them of a PLAYER LOSS 
void recordTie(); //updates stats data on the tie and displays messgage to the player informing them of a PLAYER AND COMPUTER TIE
void gamePlay(); //prompts user to enter either 'X' or 'O' as well as the square in which they would like to make a move. Implements alternating logic between computer and player. Determines if recordWin, recordLoss, or recordTie need to be called after every move
void gameLogicE(); //implements the level easy game logic for the computer player
void gameLogicM(); //implements the level medium game logic for the computer player
void gameLogicH(); //implements the level hard game logic for the computer player
//string outputStats(); //prompts the user for a file to print the stats from printPlayerStats();
//void printPlayerStats(string&); //print the information from playerStats struct & userInfo struct to a seperate scoreboard file after the user quit the game

//TAKE 2:
void printMenu(); //step 1
int main(); //call printMenu & prompt user for a menu selection until the user wants to quit
void gamePlay(); //called through switch statements in main --> step 2
void checkSurroundings(int& r, int& c, char& token);
//bool checkResult(); 
char checkVictory(int);
void tryToWin();
void boardPrint(char(*[3]));
//char gameBoard[3][3];


void playGame(char);
void computerTurn(char);
struct placement {
    int row;
    int col;
};


//rectangle object with methods for area, perimeter, and print. struct then acts as a namespace and you use ::
//rect.print();


























//best practice is DON'T define functions in a header file
/*


struct rectangle { **in .hpp (not best practice, but find a way to encorporate )
    float length, width;
    float area() {
        return length*width;
    }
};


*/