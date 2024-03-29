#include "main.hpp"
#include "userTurn.hpp"

#include <iostream>

using namespace std;

//USER TURN FUNCTION
/*
    ~takes number of turns, the gameBoard, and the userCoin as inputs
    ~returns void
    ~prompts the user for a space where they want to place their userCoin (verifies that the selection is empty and in the range of gameBoard)
*/
void userTurn(int& turns, char gameBoardTest[][3], char userCoin) {
    cout << "rows are numbered top to bottom as 1-3\n" << "columns are numbered left to right as 1-3\n";
    //printGrid(vector containing the player's positions);
    placement userSelection;
    //loop to verify that user input is in range of game board
    while (true) {
        cout << "\nplease enter your selection [row|col] seperated by a space. ex: 3 2\n";
        cin >> userSelection.row >> userSelection.col;
        userSelection.row -= 1; 
        userSelection.col -= 1;

        //check if choice is in range
        if (userSelection.row >=0 && userSelection.col >=0 and userSelection.row <= 2 && userSelection.col <= 2) {
            if (gameBoardTest[userSelection.row][userSelection.col] == ' '){
                gameBoardTest[userSelection.row][userSelection.col] = userCoin;
                
                //boardPrint(gameBoardptr);
                //turns +=1;
                //checkVictory(turns); //first attempt at checkVictory
                return;
            }
        } else {
            cin.clear();
        } 
        cout << "Your selection is out of range! Please enter another.\n";        
    }


}
