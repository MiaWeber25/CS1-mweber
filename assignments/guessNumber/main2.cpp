#include <iostream>
#include <string>
#include <math.h>
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <random> //library for random number generation

using namespace std;

//function that generates and returns a random number between 1 and 20.
int randomNumber() {
  srand(time(NULL));
  int randnum = rand() % 20 + 1;
  cout << randnum << endl; //delete later
  return randnum;
}

//function that prompts the user to take a guess and return the guessed number.
int readNumber() {
  int guessednum;
  cout << "please enter your guess: ";
  cin >> guessednum;
//validate that the guessed number is between 1 and 20.
  if (guessednum <= 20 && guessednum >= 1) {
    cout << guessednum << endl; //delete later
    return guessednum;
  } else {
    readNumber();
  }
  return guessednum;
}

//function that takes two integers and compares them returning 0 if equal, -1 if <, or 2 otherwise.
int checkGuess(int & randnum, int & guessednum) {
//for every guess inform the user if it was equal to, less than, or greater than the hidden random number.
  if (randnum == guessednum){
    cout << "You guessed the number.\n";
    return 0;
  } if (randnum < guessednum) {
    cout << "Too high.\n";
    return -1;
  } else {
    cout << "Too low.\n";
    return 2;
  }
}

//function that implements the logic of the guess the number game
void game() {
//greet the user using their name and print the game rules.
  string name;
  cout << "Welcome to the Guess the Number game! What is your name?\n";
  cin >> name;
  cout << "Hello " << name << "! I'm thinking of a number between 1 and 20." << endl << "you have 6 attempts to guess the number.\n";

//call the random number function to generate a random number.
  int correctNumber = randomNumber();
  int guessedNumber;
//until the game is over, ask the user to enter a guess using the readNumber function.
  for (int i = 0; i < 6; i++) {
    guessedNumber = readNumber();
//use checkGuess function to compare the user entered number with the hidden random number.
    int result = checkGuess(correctNumber, guessedNumber);
    if (result == 0) {
//if the user guesses the number in <= 6 guesses then they win and the game is over.
      cout << "game over. You win!!" <<endl;
      cout << "you guessed the number in " << i + 1 << " attempts. Good job!" << endl;
      break;
    } else {
      continue;
    }
    cout << "oops! You loose." << endl;
  }

}

void test() {
  int testnum1 = 3;
  int testnum2 = 4;
  assert(checkGuess(testnum1, testnum2) == -1);
  assert(checkGuess(testnum2, testnum2) == 0);
  assert(checkGuess(testnum2, testnum1) == 2);
  cerr << "all test cases passed...";
}

//main function
int main() {
  //test();
  while (true) {
    //clearScreen()
    game();
    string user_input;
    cout << "Do you want to play again? [y/n]\n";
    cin >> user_input;

    if (user_input == "y") {
      continue;
    } else {
      break;
    }
  }
  return 0;
}
