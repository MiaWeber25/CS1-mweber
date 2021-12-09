#include "functions.hpp"
#include "userTurn.hpp"

#include <iostream>

using namespace std;

void userTurn(int& turns, char (*gameBoardptr)[3]) {
    cout << "rows are numbered top to bottom as 1-3\n" << "columns are numbered left to right as 1-3\n";
    //printGrid(vector containing the player's positions);
    placement userSelection;
    //loop to verify that user input is in range of game board
    while (true) {
        cout << "please enter your selection row first seperated by a space. ex: 3 2\n";
        cin >> userSelection.row >> userSelection.col;
        userSelection.row -= 1; 
        userSelection.col -= 1;

        //check if choice is in range
        if (userSelection.row >=1 && userSelection.col >=1 and userSelection.row <= 3 && userSelection.col <= 3) {
            gameBoard[userSelection.row][userSelection.col] = 'X';
            //boardPrint(gameBoardptr);
            turns +=1;
            checkVictory(turns);
            break;
        } else {
            cin.clear();
        } 
        cout << "Your selection is out of range! Please enter another.\n";        
    }


}
