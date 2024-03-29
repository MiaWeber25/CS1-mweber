#pragma once
#include <string>

struct playerStats {
    std::string name;
    std::string outputFile;
    int numWins;
    int numLoss;
    int numTies;
    int gamesPlayed;
};
struct peopleCoins {
    char userCoin;
    char computerCoin;
};
struct placement {
    int row;
    int col;
};
void clearScreen();
void clearBoard(char [3][3]);
bool continueLoop(); 
void printMenu(playerStats &, int &, peopleCoins &, char [3][3]);
void boardPrint(char(*[3]));
char checkVictory(int &, char [3][3]);
void playGame(char, playerStats &, int &, peopleCoins &, char [3][3]);
void computerTurn(char, int &, peopleCoins &, char [3][3]);
void gameLogicE(int &, peopleCoins &, char [3][3]);
void gameLogicM(int &, peopleCoins &, char [3][3]);
void gameLogicH(int &, peopleCoins &, char [3][3]);
void recordWin(playerStats &);
void recordLoss(playerStats &);
void recordTie(playerStats &);
bool completeSequence(char, char, char [3][3]);
void outputStats(playerStats &);
