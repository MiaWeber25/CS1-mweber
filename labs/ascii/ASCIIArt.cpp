/* 
    StdIO Lab
    ASCII Art - using literals and variables

    Updated By: Mia Weber #FIXME1
    Date: 09/01/2021

    This program produces ASCII art on the colsole.

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
    //FIXME3: declare a variable to store name of user = userName #FIXED#
    string userName;
    //FIXME4: prompt user to enter their name and store the value in variable #FIXED#
    cout << "enter your name: ";
    cin >> userName;
    //FIXME5: greet the name using the variable as the following output: must output: Nice meeting you, <name>! #FIXED# 
    cout << "\nNice to meet you, " << userName + "!\n";

    cout << "\nHope you like my Tom & Jerry ASCII art...\n\n";

    string line1 = "        |\\_/|    ******************************    (\\_/)\n";
    cout << line1;

    //FIXME6: use variable to print the second line of the graphic #FIXED#
    string line2 = "       / @ @ \\   *          ASCII Lab         *   (='.'=)\n";
    cout << line2;
    //FIXME7: print the third line of the graphics #FIXED#
    
    string line3 = "      ( > 0 < )  *         By: Mia Weber      *   (\")_(\")\n";
    cout << line3;
   
    //FIXME8: use variable to print the fourth line #FIXED#
    string line4 = "        >>x<<    *          CSCI 111          *\n";
    cout << line4;
    
    //FIXME9: use variable to print the fifth line #FIXED#
    string line5 = "        / O \\    ******************************\n";
    cout << line5;
    //NOTE: You can add more lines or print more ASCII arts of your choice if you'd like...
    
    //FIXME10: make the console wait for user input #FIXED#    
    
    string wait;
    cout << "Goodbye... hit enter to exit the program: \n";
    cin.ignore();
    getline(cin, wait); //remember it's getline() not cin.getline
    
    //exit program by returning 0 status to the system
    return 0; 
}
