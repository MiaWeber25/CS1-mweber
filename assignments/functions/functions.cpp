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
float * largest(float, float); 
void test(); //test function for automated testing

//find the sum of two numbers
float sum(float num1, float num2) {
    float result = num1 + num2; 
    return result;
}

//find the product of two numbers
float product(float num1, float num2) {
    float result = num1 * num2;
    return result;
}

//find the quotient of two numbers
float quotient(float num1, float num2) {
    float result = num1 / num2;
    return result;
}

//find the difference of two numbers
float difference(float num1, float num2) {
    float result = num1 - num2;
    return result;
}

//find the remainder of two numbers
float remain(float num1, float num2) { //negative numbers = takes sign of numerator when in reality a remainder is always positive 
    float result = abs(fmod(num1,num2));  //solution = use abolute value
    return result;
}

//find one number to the power of another number
float power(float num1, float num2) {
    float result = powf(num1,num2);
    //printf("result: %f %f %f \n", num1, num2, result);
    return result;
}

//find the square root of two numbers
float root1(float num1) { //HOW TO DETERMINE WHICH NUMBER TO SQRT? --> used the first one...
    float result = sqrt(num1);    
    return result;
}
float root2(float num2) {
    float result = sqrt(num2);
    return result;
}

//find the largest of two numbers
/*float largest(float num1, float num2) {
    float result;
    float small;
    if (num1>num2) {
        result = num1;
        
    } else {
        result = num2;
    } 
    return result;
}
*/
float * largest(float num1, float num2) {
    float arr[2];
    if (num1 > num2) {
        arr[0] = num1;
        arr[1] = num2;
    } else {
        arr[0] = num2;
        arr[1] = num1;
    }
    return arr;
}

//automated testing function
void test() {
    const float margin_error = 1e-5; //define a margin of error because comparing floating points
    
    //SUM() TEST
    float result = sum(-4,12); //negative int
    float expected = 8.0;
    assert(abs(result-expected) <= margin_error); 
   
    result = sum(3.23, 7.34); //floating points
    expected = 10.57;
    assert(abs(result-expected) <= margin_error);

    //PRODUCT() ###TEST THIS IS FAILING WHYYYYYYYY
    result = product(-4,12); //negative int
    expected = -48.0;
    assert(abs(result-expected) <= margin_error);

    result = product(3.23, 7.34); //floating points
    expected = 23.7082;
    assert(abs(result-expected) <= margin_error);

    //QUOTIENT() TEST
    result = quotient(-4,12); //negative int
    expected = -0.3333333;
    assert(abs(result-expected) <= margin_error);

    result = quotient(3.23, 7.34); //floating points
    expected = 0.44005449;
    assert(abs(result-expected) <= margin_error);

    //DIFFERENCE() TEST
    result = difference(-4,12); //negative int
    expected = -16.0;
    assert(abs(result-expected) <= margin_error);

    result = difference(3.23, 7.34); //floating points
    expected = -4.11;
    assert(abs(result-expected) <= margin_error);

    //REIMAIN() TEST
    result = remain(-4,12); //negative int --> THIS WILL FAIL NOW. I WANT 4, but will get -4
    expected = 4.0;
    assert(abs(result-expected) <= margin_error);

    result = remain(3.23, 7.34); //floating points
    expected = 3.23;
    assert(abs(result-expected) <= margin_error);

    //POWER() TEST
    result = power(-4,12); //negative int
    expected = 16777216.0;
    assert(abs(result-expected) <= margin_error);

    result = power(3.23, 7.34); // floating points
    expected = 5464.452148;
    assert(abs(result-expected) <= margin_error);

    //ROOT1() TEST 
    result = root1(12); //negative int should return NaN
    expected = 3.46410161514;
    assert(abs(result-expected) <= margin_error); 

    //ROOT2() TEST
    result = root2(3.23); // floating points
    expected = 1.79722007556;
    assert(abs(result-expected) <= margin_error);

    //LARGEST() TEST --> HOW TO TEST FOR THIS... 
    float *result_array = largest(-4,12);
    expected = 12;
    assert(abs(result_array[0]-expected) <= margin_error);

    result_array = largest(3.23, 7.34);
    expected = 7.34;
    assert(abs(result_array[0]-expected) <= margin_error);
  
}


//MAIN FUNCTION
int main() {
    
    //these must be passed (by reference?) to the functions above.
    float n1; float n2; char ch;
    cout << "Please enter two numbers seperated by a comma: \n";
    cin >> n1 >> ch >> n2;
    //call functions here
    cout << '\n' << "SUM: " << n1 << " + " << n2 << " = " << sum(n1,n2) << endl;

    cout << '\n' << "PRODUCT: " << n1 << " * " << n2 << " = " << product(n1,n2) << endl;

    cout << '\n' << "QUOTIENT: " << n1 << " / " << n2 << " = " << quotient(n1,n2) << endl;

    cout << '\n' << "DIFFERENCE: " << n1 << " - " << n2 << " = " << difference(n1,n2) << endl;

    cout << '\n' << "REMAINDER: " << n1 << " % " << n2 << " = " << remain(n1,n2) << endl; 

    cout << '\n' << "EXPONENTIATION: " << n1 << " ^ " << n2 << " = " << power(n1,n2) <<endl;

    cout << '\n' << "SQUARE ROOT: " << "√ " << n1 << " = " << root1(n1) << " √ " << n2 << " = " << root2(n2) << endl;

    float *result = largest(n1,n2);
    printf("\nLARGEST:  %f > %f \n", result[0], result[1]);
    //cout << '\n' << arr[0] << " > " << arr[1] << endl;
    
    test();

    return 0;
}


