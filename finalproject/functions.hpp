#pragma once

void clearScreen();
void clearBoard();
bool random2(); //fix this later!
void printMenu();
void boardPrint(char(*[3]));
char checkVictory(int);
void playGame(char);
void computerTurn(char);
void gameLogicE();
void gameLogicM();
void gameLogicH();
void recordWin();
void recordLoss();
void recordTie();
bool completeSequence(char, char);
struct placement {
    int row;
    int col;
};


//rectangle object with methods for area, perimeter, and print. struct then acts as a namespace and you use ::
//rect.print();






/*
    for (int i=0; i<9; i++) {
        //check to see if first space = second space = third space and make sure a character is placed there --> win by row
        if(gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][0] != ' ') {
            cout << "win by row!";
            return gameBoard[i][0];
        } 
    //check the column
        //check to see if first space = second space = third space and make sure character is placed there --> win by column
        else if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != ' '){
            cout << "win by column!";
            return gameBoard[0][i];
        } 
    //check the diagonal
        //check to see if first space = second space = third space and make sure character is placed there --> win by diagonal
        else if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != ' ') {
            cout << "win by diagonal!";
            return gameBoard[0][i];
        } else { //no one has one --> tie
            if (turns == 9) {
                cout << "returning T for tie";
                return 'T';
            } else { //no one has won --> go on with turns
                cout << "returning G for go on";
                return 'G';
            }
        } 
    }
    */



















//best practice is DON'T define functions in a header file
/*


struct rectangle { **in .hpp (not best practice, but find a way to encorporate )
    float length, width;
    float area() {
        return length*width;
    }
};


*/