/*
    Conditional Lab
    Mia Weber
    27/sept/2021

Program finds statistical values of two given numbers using user-defined functions.
A menu-driven program that demonstrates user-defined functions, automated testing conditional statements, and loops.
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cassert>

using namespace std;

//FUNCTION PROTOTYPES

void printMenu(void); //prints menu options
void getTwoNumbers(double &, double &); //prompts user to enter 2 nums and stored in parameters
double findSum(const double &, const double &); //finds the sum of 2 numbers
double findDifference(const double &, const double &); //subtracts the 2nd number from the first
double findProduct(const double &, const double &); //finds product of two numbers
double findQuotient(const double &, const double &); //finds quotient of first number divided by second number
void findAverage(const double &, const double &, const double&); //finds the average of two variables
double findLarger(const double &, const double &); //finds the larger of two numbers
double findSmaller(const double &, const double &); //finds the smaller of two numbers
void test();
bool program();

//function to clear the screen (system call not best practice!)
void clearScreen() {
    //"clear" in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else 
        system("clear");
    #endif
}

int main(int argc, char* argv[]) {
    bool keepRunning = true;
    if(argc == 2 && string(argv[1]) == "test") {
        test();
        exit(EXIT_SUCCESS); //exit the program
    } else {
        while (true) {
            if (!program()) 
                break;
            cin.ignore(100,'\n');
            cout << "Enter to continue...";
            cin.get();
            clearScreen();
        }
    }
    cin.ignore(100, '\n');
    cout << "Enter to quit the program.\n";
    cout << "Good bye..." << endl;
    cin.get();
    return 0;
}

void printMenu(void) {
    cout << "Menu options:\n";
    cout << "[1] Add two numbers\n";
    cout << "[2] Subtract two numbers\n";
    cout << "[3] Multiply two numbres\n";
    cout << "[4] Divide two numbers\n";
    cout << "[5] Find larger of two numbres\n";
    cout << "[6] Find smaller of two numbres\n";
    cout << "[7] Find the average of two numbers\n";
    cout << "[8] Quit the program\n";
    cout << "Enter one of the menu options [1-8]: ";
}

void getTwoNumbers(double &n1, double &n2) {
    cout << "Enter two numbers seperated by a space: ";
    cin >> n1 >> n2;
}

double findSum(const double &n1, const double &n2) {
    return (n1 +n2);
}

double findDifference(const double &n1, const double &n2) {
    //FIXME3 - subtract n2 from n1 and return the difference #FIXED#
    return (n1-n2);
}

double findProduct(const double &n1, const double &n2) {
    //FIXME4 - multiply n1 by n2 and return the product #FIXED#
    return(n1*n2);
}

void findAverage(const double &n1, const double &n2, double &avg) {
    //FIXME5 - find the average of n1 and n2 and update avg #FIXED#
    double avg = ((findSum(n1,n2))/2);
    //FIXME6 - Call findSum function to find the sum of n1 and n2

}

double findLarger(const double &n1, const double &n2) {
    //find the larger of n1 and n2 and return it
    double larger = (n1 >= n2) ? n2 : n2;
    return larger;
}



