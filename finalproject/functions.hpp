#pragma once
#include <string>

struct playerStats {
    std::string name;
    int numWins;
    int numLoss;
    int numTies;
    int gamesPlayed;
};
void clearScreen();
void clearBoard();
bool random2(); //fix this later!
void printMenu(playerStats &);
void boardPrint(char(*[3]));
char checkVictory(int);
void playGame(char, playerStats &);
void computerTurn(char);
void gameLogicE();
void gameLogicM();
void gameLogicH();
void recordWin(playerStats &);
void recordLoss(playerStats &);
void recordTie(playerStats &);
bool completeSequence(char, char);
//void calculateStats();
void outputStats(playerStats &);
struct placement {
    int row;
    int col;
};