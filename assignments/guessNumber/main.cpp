/*  
    Guess The Number
    By: Mia Weber
    Date: 18/Oct/2021
    CSCI 111

    Design and implement the "guess the number game"
    
    Algorithm Steps: 
    1. greet the player
    2. create a loop to allow the user to play as many times as possible
    3. use the loop to call functions 
        3a. randomNumber, readNumber, checkGuess
    4. write test casses to ensure that all functions are functioning correctly
    5. check to see if the number the user entered was correct
    6. inform the user if the player won or lost and reveal the secret number
*/

#include <iostream>
#include <string>
#include <math.h>
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <random> //library for random number generation

using namespace std;

//FUNCTION PROTOTYPES
int randomNumber();
int readNumber();
int checkGuess(int, int);
void game();
//WILL I NEED A SEPERATE FUNCTION FOR COUNTERS???
int counters();


//RANDOM NUMBER FUNCTION
int randomNumber() {
    srand(time(NULL));
    int correct_num = rand() % 20 + 1;
    cout << correct_num;
    return correct_num;
}


//READ NUMBER FUNCTION
int readNumber() {
    int guessed_number;
    cout << "enter your guess: ";
    cin >> guessed_number;
    return guessed_number;
}

//CHECK GUESS FUNCTION
int checkGuess(int &correct_num, int &guessed_num) {
    if (correct_num == guessed_num) {
        return 0;
    } if (correct_num < guessed_num) {
        return -1;
    } else {
        return 2;
    }
}

//ASSERT STATEMENTS FOR CHECK GUESS FUNCTION

void game() {
    //for loop for 6 tries
    randomNumber();
    //readNumber();
}

int main() {
    game();
}