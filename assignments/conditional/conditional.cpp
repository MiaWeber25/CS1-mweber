/* 
    HW 4 CLI Menu, Conditionals, Functions and Testing  
    Created By: Mia Weber
    Date: 10/11/2021

    This program uses a command line interface (CLI) based menu-driven program that computes certain 
    values including sum, product, max, min, averge, oddity, etc. *see function prototypes for full list.
    This program also uses automated testing (assert) in order to test the functions

    Useful resource for 
    Useful resource for  
   
    Algorithm steps:
    1. Greet user by name and prompt them to enter 5 numbers
    2. Display menu options for each function and then call the function that cooresponds to user's choice (switch statement)
    3. Allow the user to calculate values (and therefore call functions) until they want to quit the program
    4. test functions 
*/
#include <string>
#include <cassert>
#include <math.h>
#include <iostream>

using namespace std;

//FUNCTION PROTOTYPES:
//get user input function
void numbers(double &, double &, double &, double &, double &);
//menu function
void menu();
//program function
bool run();
//sum function
double findSum(double &, double &, double &, double &, double &);
//product function //NEED TO TEMPLATE THIS FUNCTION SO THAT IT CAN TAKE MULTIPLE TYPES
//double findProduct(double &, double &, double &, double &, double &);
//average function
double findAverage(double &, double &, double &, double &, double &);
//largest function
double findLargest(double &, double &, double &, double &, double &);
//smallest function
double findSmallest(double &, double &, double &, double &, double &);
//floor of sum function
double findFloor(double &, double &, double &, double &, double &);

//FUNCTIONS:

void menu() {
    cout << "Please choose an opperation to perform:\n";
    cout << "[1] Find Sum\n";
    cout << "[2] Find Product\n";
    cout << "[3] Find Average\n";
    cout << "[4] Find Largest\n";
    cout << "[5] Find Smallest\n";
    cout << "[6] Find Floor\n";
    cout << "[7] Exit Program\n";
    cout << "Please choose an opperation now: \n";
}

void numbers(double &n1, double &n2, double &n3, double &n4, double &n5) {
    cout << "please enter 5 numbers seperated by spaces: \n";
    cin >> n1 >> n2 >> n3 >> n4 >> n5;
}

bool run() {
    int menu_option;
    double num1 =0, num2=0, num3=0, num4=0, num5=0;
    menu();
    cin >> menu_option;

//menu_option can use switch because it is taking an integer (integral-expression)
    bool want_continue = true;
    //while (want_continue == true) {
        //cout << "enter to continue: ";    } 
        switch (menu_option) {
            case 1: {
                numbers(num1, num2, num3, num4, num5);
                double sum = findSum(num1, num2, num3, num4, num5);
                printf("%.2f + %.2f + %.2f + %.2f + %.2f = %.2f\n", num1, num2, num3, num4, num5, sum);
                break;
            } case 2: {
                numbers(num1, num2, num3, num4, num5);
                //double product = findProduct(num1, num2, num3, num4, num5);
                //printf("%.2f * %.2f * %.2f * %.2f * %.2f = %.2f\n", num1, num2, num3,num4, num5, product);
                break;
            } case 3: {
                numbers(num1, num2, num3, num4, num5);
                double average = findAverage(num1, num2, num3, num4, num5);
                printf("The average of %.2f, %.2f, %.2f, %.2f, and %.2f is %.2f\n", num1, num2, num3, num4, num5, average);
                break;
            } case 4: {
                numbers(num1, num2, num3, num4, num5);
                double large = findLargest(num1, num2, num3, num4, num5);
                printf("The largest in %.2f, %.2f, %.2f, %.2f, and %.2f is %.2f\n", num1, num2, num3, num4, num5, large);
                break;
            } case 5: {
                numbers(num1, num2, num3, num4, num5);
                double small = findSmallest(num1, num2, num3, num4, num5);
                printf("The smallest in %.2f, %.2f, %.2f, %.2f, and %.2f is %.2f\n", num1, num2, num3, num4, num5, small);
                break;
            }case 6: {
                numbers(num1, num2, num3, num4, num5);
                double the_floor = findFloor(num1, num2, num3, num4, num5);
                printf("the floor of %.2f, %.2f, %.2f, %.2f, and %.2f is %.2f\n", num1, num2, num3, num4, num5, the_floor);
                break;
            } case 7: {
                //want_continue = false;
                return false;
        } 
    }
    return true;
}


double findSum(double &n1, double &n2, double &n3, double &n4, double &n5) {
    return n1 + n2 + n3 + n4 + n5;
}
/*
template<class T>
T findProduct(T &n1, T &n2, T &n3, T &n4, T &n5) {
    return n1 * n2 * n3 * n4 * n5;
}
*/
double findAverage(double &n1, double &n2, double &n3, double &n4, double &n5) {
    return (findSum(n1, n2, n3, n4, n5)/5);
}

double findLargest(double &n1, double &n2, double &n3, double &n4, double &n5) {
    double largest = n1;
    if (n2 > largest) {
        largest = n2;
    } if (n3 > largest) {
        largest = n3;
    } if (n4 > largest) {
        largest = n4;
    } if (n5 > largest) {
        largest = n5;
    }
    return largest;
}

double findSmallest(double &n1, double &n2, double &n3, double &n4, double &n5) {
    double smallest = n1;
    if (n2 < smallest) {
        smallest = n2;
    } if (n3 < smallest) {
        smallest = n3;
    } if (n4 < smallest) {
        smallest = n4;
    } if (n5 < smallest) {
        smallest = n5;
    }
    return smallest;
}

double findFloor(double &n1, double &n2, double &n3, double &n4, double &n5) {

    return 0;
}

int main() {
    cout << "Please enter your name: \n";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;    
    run();
    return 0;
}