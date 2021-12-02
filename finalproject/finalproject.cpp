/*
    TicTacToe Game
    By: Mia Weber
    01/Dec/2021
    CSCI 111 Final Project

    Algorithm Steps:
    1. 
*/
#include <iostream>
#include <string>
#include <cstdio>
#include <cassert>
#include <fstream>
#include <iomanip>
//my header files
#include "functions.hpp"

using namespace std;

//FUNCTION PROTOTYPES **I should template some of my functions too!
bool printBoard(); //function to print the game board. called every time a new game is started
void clearBoard(); //function to clear the board & screen. called before printBoard every time a new game is started (will I need this?) 
void recordWin(); //updates stats data on the win and displays message to the player informing them of a PLAYER WIN
void recordLoss(); //updates stats data on the loss and displays message to the player informing them of a PLAYER LOSS 
void recordTie(); //updates stats data on the tie and displays messgage to the player informing them of a PLAYER AND COMPUTER TIE
void gamePlay(); //prompts user to enter either 'X' or 'O' as well as the square in which they would like to make a move. Implements alternating logic between computer and player. Determines if recordWin, recordLoss, or recordTie need to be called after every move
void gameLogicE(); //implements the level easy game logic for the computer player
void gameLogicM(); //implements the level medium game logic for the computer player
void gameLogicH(); //implements the level hard game logic for the computer player
string outputStats(); //prompts the user for a file to print the stats from printPlayerStats();
void printPlayerStats(string& outfile); //print the information from playerStats struct & userInfo struct to a seperate scoreboard file after the user quit the game

struct userInfo; //struct to store users name, and eventually their record of wins, losses, and ties
struct playerStats; //struct to store stats including: total wins, total losses, total ties, total games played, and **prints the top scores in order (using a seperate vector to store scores)

int main() {
    printBoard();
    return 0;
}
/* printBoard
-->use switch statements to print a menu to allow the user to choose between E, M, and H
*/
bool printBoard() {
    int option = 0;
    cout << "Welcome to TicTacToe!\n";
    cout << "Below are the menu options:\n";
    cout << "[1] Easy\n";
    cout << "[2] Medium\n";
    cout << "[3] Hard\n";
    cout << "[4] Quit\n";
    cout << "Enter one of the menu options [1-4]: ";
    
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
    } while (true);

    switch(option) {
        case 1:
        {
            //call the outputStats function to prompt for output file
            outputStats();
            //call the gameLogicE function
            gameLogicE();
            break;
        }
        case 2:
        {
            //call the outputStats function to prompt for output file
            outputStats();
            //call the gameLogicM function
            gameLogicM();
            break;
        }
        case 3:
        {
            //call the outputStats function to prompt for output file
            outputStats();
            //call the gameLogicH function
            gameLogicH();
            break;
        }
        case 4:
        default:
            return false; //exit the program
    }
    return true;
}

void gamePlay() { //do I want to set this up so that the user can determine the size of the board?
   //just set up for now as a general outline - I will want to reference each space as a corresponding element in the vector. 
   //vector <int> board;
   cout << setfill('-') << setw(17) << " " << endl;
   for(int i=0; i<3; i++) {
       cout << "|  ";
       for(int j=0; j<3;j++) {
           cout << "  |  ";
       }
       cout << endl << setfill('-') << setw(17) << " " << endl;
   }
}

void gameLogicE() {
    gamePlay();
}

void gameLogicM() {
    gamePlay();
}

void gameLogicH() {
    gamePlay();
}

string outputStats() {
    string outfile;
    cout << "Enter name of file to write game statistics to:\n";
    cin >> outfile;
    return outfile;
}

void printPlayerStats(string& outfile) { //When to call this one is a little tricky...
    ofstream fout;
    fout.open(outfile);
    fout << "test!" << endl;
}