/*
    HW 3 Functions and Testing
    Created By: Mia Weber
    Date: 22/sept/2021

    This program performs some arithmetic operations on two given numbers (entered by user)
    Useful resources:
    https://stackoverflow.com/questions/11720656/modulo-operation-with-negative-numbers 
    
    Algorithm steps:
    1. define functiosn to add(+), multiply(*), divide(/), sumbtract(-), find the remainer(fmod), perform exponentiation(powf), find a square root(sqrt), and find the larger of two numbers(>)
    2. call each function in turn in order to print the math results to the console 
*/
#include <iostream>
#include <cmath>
#include <iomanip> 
#include <string>

using namespace std; 

//FUNCTION PROTOTYPES #all have to work for integers and floating points
float sum(float,float); 
float product(float, float); 
float quotient(float, float); 
float difference(float, float); 
//float remain(float, float); // doesn't compile with this... 
float power(float, float);
float root(float, float);
float largest(float, float); 
void test(); //test function for automated testing

//find the sum of two numbers
float sum(float num1, float num2) {
    cout << '\n' << num1 << " + " << num2 << " = " << num1+num2 << endl;

    return 0;
}

//find the product of two numbers
float product(float num1, float num2) {
    cout << '\n' << num1 << " * " << num2 << " = " << num1*num2 << endl;

    return 0;
}

//find the quotient of two numbers
float quotient(float num1, float num2) {
    cout << '\n' << num1 << " / " << num2 << " = " << num1/num2 << endl;

    return 0;
}

//find the difference of two numbers
float difference(float num1, float num2) {
    cout << '\n' << num1 << " - " << num2 << " = " << num1-num2 << endl;
    
    return 0;
}

//find the remainder of two numbers
float remain(float num1, float num2) { //negative numbers = takes sign of numerator when in reality a remainder is always positive 
    cout << '\n' << num1 << " % " << num2 << " = " << abs(fmod(num1,num2)) << endl;  //solution = use abolute value

    return 0;
}

//find one number to the power of another number
float power(float num1, float num2) {
    cout << '\n' << num1 << " ^ " << num2 << " = " << powf(num1,num2) <<endl;

    return 0;
}

//find the square root of two numbers
float root(float num1, float num2) { //HOW TO DETERMINE WHICH NUMBER TO SQRT? --> used the first one...
    cout << '\n' << "√ " << num1 << " = " << sqrt(num1) << endl;

    cout << '\n' << "√ " << num2 << " = " << sqrt(num2) << endl;
   
    return 0;
}

//find the largest of two numbers
float largest(float num1, float num2) {
    if (num1>num2) {
        cout << '\n' << num1 << " > " << num2 << endl;
    } else {
        cout << '\n' <<num2 << " > " << num1 << endl;
    }
    return 0;
}

//automated testing function
void test() {
    const float margin_error = 1e-5; //define a margin of error because comparing floating points
    
    //SUM() TEST
    float result = sum(-4,12); //negative int
    float expected = 8.0;
    assert(result == expected <= margin_error); 
   
    result = sum(3.23, 7.34); //floating points
    expected = 10.57;
    assert(result == expected <= margin_error);

    //PRODUCT() ###TEST THIS IS FAILING WHYYYYYYYY
    result = product(-4,12); //negative int
    expected = -48.0;
    assert(result == expected <= margin_error);

    result = product(3.23, 7.34); //floating points
    expected = 23.7082;
    assert(result == expected <= margin_error);

    //QUOTIENT() TEST
    result = quotient(-4,12); //negative int
    expected = -0.3333;
    assert(result == expected <= margin_error);

    result = quotient(3.23, 7.34); //floating points
    expected = 0.4400;
    assert(result == expected <= margin_error);

    //DIFFERENCE() TEST
    result = difference(-4,12); //negative int
    expected = -16.0;
    assert(result == expected <= margin_error);

    result = difference(3.23, 7.34); //floating points
    expected = -4.11;
    assert(result == expected <= margin_error);

    //REIMAIN() TEST
    result = remain(-4,12); //negative int --> THIS WILL FAIL NOW. I WANT 4, but will get -4
    expected = 4.0;
    assert(result == expected <= margin_error);

    result = remain(3.23, 7.34); //floating points
    expected = 3.23;
    assert(result == expected <= margin_error);

    //POWER() TEST
    result = power(-4,12); //negative int
    expected = 16777216.0;
    assert(result == expected <= margin_error);

    result = power(3.23, 7.34); // floating points
    expected = 5464.4507;
    assert(result == expected <= margin_error);

    //ROOT() TEST --> HOW TO MAKE THIS TEST FOR BOTH... CALLED ONLY ONCE, BUT COMPUTING TWO DIFFERENT THINGS...
    float neg_root = isnan(num1);
    //result = root(-4,12); //negative int
    //expected = nan;
    //assert(result == expected <= margin_error);

    //result = root(3.23, 7.34); //floating points 
    //expected = 

    //LARGEST() TEST --> HOW TO TEST FOR THIS... 
    
}


//MAIN FUNCTION
int main() {
    //these must be passed (by reference?) to the functions above.
    float n1; float n2; char ch;
    cout << "Please enter two numbers seperated by a comma: \n";
    cin >> n1 >> ch >> n2;
    //call functions here
    cout << "SUM: " << sum(n1,n2) << endl; 
    cout << "PRODUCT: " << product(n1,n2) << endl;
    cout << "QUOTIENT: " << quotient(n1,n2) << endl;
    cout << "DIFFERENCE: " << difference(n1,n2) << endl; 
    cout << "REMAINDER: " << remain(n1,n2) << endl; 
    cout << "EXPONENTIATION: " << power(n1,n2) << endl;
    cout << "SQUARE ROOT: " << root(n1,n2) << endl;
    cout << "LARGEST: " << largest(n1,n2) << endl;
    
    test();

    return 0;
}


