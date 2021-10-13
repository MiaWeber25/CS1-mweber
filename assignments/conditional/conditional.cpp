/*
    HW 4 CLI Menu, Conditionals, Functions and Testing
    Created By: Mia Weber
    Date: 10/11/2021

    This program uses a command line interface (CLI) based menu-driven program that computes certain
    values including sum, product, max, min, averge, oddity, etc. *see function prototypes for full list.
    This program also uses automated testing (assert) in order to test the functions

    Useful resource for assert with const parameters https://stackoverflow.com/questions/17771406/c-initial-value-of-reference-to-non-const-must-be-an-lvalue

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
#include <cstdio>

using namespace std;

//FUNCTION PROTOTYPES:
//get user input function
void numbers(const double &, const double &, const double &, const double &, const double &);
//menu function
void menu(int, char[]);
//program function
bool run();
//test function
void test();
//sum function
double findSum(const double &, const double &, const double &, const double &, const double &);
//product function //NEED TO TEMPLATE THIS FUNCTION SO THAT IT CAN TAKE MULTIPLE TYPES
//double findProduct(double &, double &, double &, double &, double &);
template<class T> T findProduct(const T &, const T &, const T &, const T &, const T &);
//average function
double findAverage(const double &, const double &, const double &, const double &, const double &);
//largest function
double findLargest(const double &, const double &, const double &, const double &, const double &);
//smallest function
double findSmallest(const double &, const double &, const double &, const double &, const double &);
//floor of sum function
int findFloor(const double &, const double &, const double &, const double &, const double &);

//FUNCTIONS:
//argc ==> argument count
//argv[] ==> character array to determine if test is called
//remember to use a pointer because you can't initialize char arrays without it.
int main(int argc, char* argv[]) {
    //determine if two arguments are entered and then determine if "Test" was the second argument - then call test function
    if (argc == 2 && string(argv[1]) == "test") {
        test();
    }
    cout << "Please enter your name: \n";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    while(true) {
        if (!run()) {
            break;
        }
        cin.ignore(100, '\n');
        cout << "Enter to Continue:";
        cin.get();
    }
    cin.ignore(100, '\n');
    cout << "Enter to quit the program.\n";
    cin.get();
    return 0;
}
//MENU FUNCTION
void menu() {
    cout << "\nPlease choose an opperation to perform:\n";
    cout << "[1] Find Sum\n";
    cout << "[2] Find Product\n";
    cout << "[3] Find Average\n";
    cout << "[4] Find Largest\n";
    cout << "[5] Find Smallest\n";
    cout << "[6] Find Floor\n";
    cout << "[7] Exit Program\n";
    cout << "Please choose an opperation now: \n";
}
//GET USER INPUT FUNCTION
void numbers(double & n1, double & n2, double & n3, double & n4, double & n5) {
    cout << "please enter 5 numbers seperated by spaces: \n";
    cin >> n1 >> n2 >> n3 >> n4 >> n5;
}
//FIND THE SUM FUNCTION
double findSum(const double &n1, const double &n2, const double & n3, const double & n4, const double & n5) {
    return (n1 + n2 + n3 + n4 + n5);
}
//FIND THE PRODUCT TEMPLATED FUNCTION
template<class T>
T findProduct(const T &n1, const T &n2, const T &n3, const T &n4, const T &n5) {
    return n1 * n2 * n3 * n4 * n5;
}
//FIND THE AVERAGE FUNCTION
double findAverage(const double &n1, const double &n2, const double &n3, const double &n4, const double &n5) {
    return (findSum(n1, n2, n3, n4, n5)/5);
}
//FIND THE LARGEST FUNCTION
double findLargest(const double &n1, const double &n2, const double &n3, const double &n4, const double &n5) {
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
//FIND THE SMALLEST FUNCTION
double findSmallest(const double &n1, const double &n2, const double &n3, const double &n4, const double &n5) {
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
//FIND IF THE FLOOR IS EVEN, ODD, or 0 FUNCTION
int findFloor(const double &n1, const double &n2, const double &n3, const double &n4, const double &n5) {
    int the_floor = int(floor(findSum(n1, n2, n3, n4, n5)));
    //cout << the_floor;
    if (int(floor(findSum(n1, n2, n3, n4, n5))) == 0) {
      //cout << the_floor;
      return 2;
    }
    if (the_floor % 2 == 1.00) {
      //cout << the_floor;
      return 1;
    } else if (the_floor % 2 == 0.00) {
      //cout << the_floor;
      return 0;
    }
}
//TEST FUNCTION
void test() {
    double margin_of_error = 0.0021;
    assert(findSum(-20, -30, -2, -3, -54) == -109);
    assert(findSum(10.34, 23.5, 3.34, 63.2, 2.567) == 102.947);
    assert(findSum(2.3, 5.6, 23.4, 78.887, 34.2) ==144.387);

    assert(findProduct(-20, -30, -2, -3, -54) + 194400 < margin_of_error); //add because expected result is negative (-- = +)
    assert(findProduct(10.34, 23.5, 3.34, 63.2, 2.567) - 131667.265 < margin_of_error);
    assert(findProduct(2.3, 5.6, -23.4, -78.887, 34.2) - 813136.146 < margin_of_error);

    assert(findAverage(-20, -30, -2, -3, -54) == -21.8);
    assert(findAverage(10.34, 23.5, 3.34, 63.2, 2.567) == 20.5894);
    assert(findAverage(2.3, 5.6, -23.4, -78.887, 34.2) == -12.0374);

    assert(findLargest(-20, -30, -2, -3, -54) == -2);
    assert(findLargest(10.34, 23.5, 3.34, 63.2, 2.567) == 63.2);
    assert(findLargest(2.3, 5.6, -23.4, -78.887, 34.2) == 34.2);

    assert(findSmallest(-20, -30, -2, -3, -54) == -54);
    assert(findSmallest(10.34, 23.5, 3.34, 63.2, 2.567) == 2.567);
    assert(findSmallest(2.3, 5.6, -23.4, -78.887, 34.2) == -78.887);

    assert(findFloor(-20, -30, -2, -3, -54) == 1);
    assert(findFloor(10.34, 23.5, 3.34, 63.2, 2.567) == 0);
    assert(findFloor(2.3, 5.6, -23.4, -78.887, 34.2) == 0);

    cout << "all test cases passed.\n";
}
//RUN PROGRAM FUNCTION
bool run() {
    int menu_option;
    double num1 =0, num2=0, num3=0, num4=0, num5=0;
    menu();
    cin >> menu_option;

//menu_option can use switch because it is taking an integer (integral-expression)
        switch (menu_option) {
            case 1: {
                numbers(num1, num2, num3, num4, num5);
                double sum = findSum(num1, num2, num3, num4, num5);
                printf("%.2f + %.2f + %.2f + %.2f + %.2f = %.2f\n", num1, num2, num3, num4, num5, sum);
                break;
            } case 2: {
                numbers(num1, num2, num3, num4, num5);
                //printf(findProduct<double>(num1, num2, num3, num4, num5))
                double product = findProduct(num1, num2, num3, num4, num5);
                printf("%.2f * %.2f * %.2f * %.2f * %.2f = %.2f\n", num1, num2, num3,num4, num5, product);
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
            } case 6: {
                numbers(num1, num2, num3, num4, num5);
                int the_floor = findFloor(num1, num2, num3, num4, num5);
                if (the_floor == 1) {
                  printf("the floor of %.2f, %.2f, %.2f, %.2f, and %.2f is odd\n", num1, num2, num3, num4, num5);
                } else if (the_floor == 0) {
                  printf("the floor of %.2f, %.2f, %.2f, %.2f, and %.2f is even\n", num1, num2, num3, num4, num5);
                } else if (the_floor == 2)
                printf("the floor of %.2f, %.2f, %.2f, %.2f, and %.2f is 0\n", num1, num2, num3, num4, num5);
                break;
            } case 7: {
                return false;
        }
    }
    return true;
}
