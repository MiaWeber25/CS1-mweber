/* 
    StdIO Lab
    ASCII Art - using literals and variables

    Updated By: Mia Weber #FIXME1
    Date: 09/01/2021

    This program produces an ASCII art on the colsole.

    Algorithm steps:
    1. Use variables to store data/values
    2. Write a series of cout statements to print the data/values
*/

#include <iostream> //library for input and output
#include <string> //library for string data

using namespace std; //resolve cout, cin, and endl names

//main entry point of the program
int main()
{
    string userName;
    cout << "enter your name: ";
    cin >> userName; //getline(cin, userName);
    cout << "Nice to meet you, " << userName + "!\n";
    //FIXME3: declare a variable to store name FIXED 09/02
    //FIXME4: prompt user to enter their name and store the value in variable FIXED 09/02

    //FIXME5: greet the name using the variable as the following output
    //must output: Nice meeting you, <name>! 

    cout << "\nHope you like my Tom & Jerry ASCII art...\n\n";

    string line1 = " |\\_/|   *****************************    (\\_/)\n";
    cout << line1;

    //FIXME6: use variable to print the second line of the graphic
    string line2 = "/ @ @ /  *       ASCII Lab           *   (='.'=)";
    cout << line2;
    //FIXME7: print the third line of the graphics
    //string line3 = "( > 0 < )  *     By: Mia Weber      *   (")_(")";
    //cout << line3;
    //FIXME8: use variable to print the fourth line
    string line4 = "";
    //FIXME9: use variable to print the fifth line
    string line5 = "";
    //NOTE: You can add more lines or print more ASCII arts of your choice if you'd like...

    cout <<"\nGoodbye... hit enter to exit the program: " << '\n';
    //FIXME10: make the console wait for user input

    return 0; //exit program by returning 0 status to the system
}