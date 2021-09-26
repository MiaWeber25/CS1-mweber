/*
    HW 3 Functions and Testing
    Created By: Mia Weber
    Date: 22/sept/2021

    This program performs some arithmetic operations on two given numbers (entered by user)
    Useful resources:

    Algorithm steps:
    1. 
*/
#include <iostream>
#include <cmath>
#include <iomanip> 
#include <string>

using namespace std; 

//FUNCTION PROTOTYPES 
float sum(float,float); //must work for ints and floats
float product(float, float); //must work for ints and floats
float quotient(float, float); //must work for ints and floats
float difference(float, float); //must work for ints and floats
//float remain(float, float); //must work for ints and floats
float power(float, float); //must work for ints and floats
float root(float, float); //must work for ints and floats
float largest(float, float); 
void test(); //test function for automated testing


float sum(float num1, float num2) {
    cout << '\n' << num1 << " + " << num2 << " = " << num1+num2 << endl;

    return 0;
}

float product(float num1, float num2) {
    cout << '\n' << num1 << " * " << num2 << " = " << num1*num2 << endl;

    return 0;
}

float quotient(float num1, float num2) {
    cout << '\n' << num1 << " / " << num2 << " = " << num1/num2 << endl;

    return 0;
}

float difference(float num1, float num2) {
    cout << '\n' << num1 << " - " << num2 << " = " << num1-num2 << endl;
    
    return 0;
}

float remain(int num1, int num2) { //HOW DO I DO MOD WITH FLOATING POINTS? 
    cout << '\n' << num1 << " % " << num2 << " = " << num1%num2 << endl;

    return 0;
}
float power(float num1, float num2) {
    cout << '\n' << num1 << " ^ " << num2 << " = " << pow(num1,num2) <<endl;

    return 0;
}
float root(float num1) { //HOW TO DETERMINE WHICH NUMBER TO SQRT? --> used the first one...
    cout << '\n' << "√ " << num1 << " = " << sqrt(num1) << endl;

    return 0;
}
float largest(float num1, float num2) {
    if (num1>num2) {
        cout << '\n' << num1 << " > " << num2 << endl;
    } else {
        cout << '\n' <<num2 << " > " << num1 << endl;
    }
    return 0;
}
void test() {
    //neg numbers
    //decimal numbers
    //neg decimal numbers
}


//MAIN FUNCTION
int main() {
    //these must be passed (by reference?) to the functions above.
    float n1; float n2; char ch;
    cout << "Please enter two numbers seperated by a comma: \n";
    cin >> n1 >> ch >> n2;
    //call functions here
    sum(n1,n2); 
    product(n1,n2);
    quotient(n1,n2);
    difference(n1,n2); 
    remain(n1,n2); 
    largest(n1,n2);
    root(n1);
    power(n1,n2);
    test();

    return 0;
}


