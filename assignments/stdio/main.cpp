/* 
    HW 1 Std I/O 
    Created By: Mia Weber
    Date: 09/06/2021

    This program prints stages of the hangman game.

    Algorithm steps:
    1. create a variable to store user's name (greet the player)
    2. use variables and std output to print 7 game stages
    3. use string variables to store each level's gallows
*/
#include <iostream> //input output library
#include <string> //string library

using namespace std;


//main function
int main () {
    //prompt user to enter their name
    string userName;
    cout << "Hi! What is your name?\n";
    cin >> userName; 

    //greet the player
    cout << "Hi " << userName + "!\n";
    cout << "This hangman game is not finished yet. Here is what it will look like:\n";
    
    string levelOne =
        "Stage One\n"
        "|-----------\n"
         "|     |\n"
         "|\n"
         "|\n"
         "|\n"
    "=============\n";
    cout << levelOne;

    string levelTwo =
     "Stage Two\n"
     "|-----------\n"
         "|     |\n"
         "|     O\n"
         "|\n"
         "|\n"
    "=============\n";
   
    cout << levelTwo;

    string levelThree = 
    "Stage Three\n"
     "|-----------\n"
         "|     |\n"
         "|     O\n"
         "|     |\n"
         "|\n"
    "=============\n";

    cout << levelThree; 

    string levelFour = 
    "Stage Four\n"
     "|-----------\n"
         "|     |\n"
         "|    \\O\n"
         "|     |\n"
         "|\n"
    "=============\n";

    cout << levelFour;

    string levelFive = 
    "Stage Five\n"
     "|-----------\n"
         "|     |\n"
         "|    \\O/\n"
         "|     |\n"
         "|\n"
    "=============\n";

    cout << levelFive;

    string levelSix = 
    "Stage Six\n"
     "|-----------\n"
         "|     |\n"
         "|    \\O/\n"
         "|     |\n"
         "|    /\n"
    "=============\n";

    cout << levelSix;
    
    string levelSeven = 
    "Stage Seven\n"
     "|-----------\n"
         "|     |\n"
         "|    \\O/\n"
         "|     |\n"
         "|    / \\\n"
    "=============\n";

    cout << levelSeven;

    return 0; 
}