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
void tryToWin();
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