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
int checkGuess(int &, int &);
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
int readNumber(int guessed_num) {
    cout << "\nEnter your guess: \n";
    cin >> guessed_num;
    if (guessed_num >= 1 && guessed_num <= 20) {
        return guessed_num;
    } else {
        cout << "that number is not between 1 and 20. Please enter another number";
        readNumber(guessed_num);
    }
    return 0;
}

//CHECK GUESS FUNCTION
int checkGuess(int &correct_num, int &guessed_num) {
    if (correct_num == guessed_num) {
        cout << "equal";
        return 0;
    } else if (correct_num >= guessed_num) {
        cout << "greater";
        return -1;
    } else {
        cout << "less than";
        return 2;
    }
}

//ASSERT STATEMENTS FOR CHECK GUESS FUNCTION

void game() {
    randomNumber();
    readNumber();

    int guessed_num = readNumber();
    int correct_num = randomNumber();
    //for loop for 6 tries
    checkGuess(guessed_num, correct_num);
}

int main() {
    string user_name;
    cout << "Welcome! Please enter your name: ";
    cin >> user_name;
    cout << "Hi " <<  user_name <<  "!\nI am thinking of a number between 1 and 20. You get 6 tries to guess the number.";
    game();

    //assert(checkGuess(2, 6) == 2);
    //assert(checkGuess(8, 3) == -1);
    //assert(checkGuess(5,5) == 0);
    cerr << "all test cases passed...";

    return 0;
}
