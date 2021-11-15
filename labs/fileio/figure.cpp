#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cassert>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

//this works, unless there's no mode
int Mode(const vector<int> &);

int main() {
    vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(10);
    numbers.push_back(10);
    numbers.push_back(0);
    numbers.push_back(-10);
    numbers.push_back(-10);
    numbers.push_back(-10);

    //Mode(numbers);
    cout << Mode(numbers) << endl;
}

int Mode(const vector<int> & nums) {
int localCount = 0;
int greatestValue = 0;
int mode = 0;
for (int i=0; i<nums.size(); i++) { //itterate through every element of nums
    localCount = count(nums.begin(), nums.end(), nums[i]); //localCount = number of occurences of nums at i 
    if (localCount > greatestValue) { //WHAT IF IT'S EQUAL TO??
        //cout << "localCount Before: " << localCount << endl;
        greatestValue = localCount;
        //cout << "localCount After: " << localCount << endl;
        mode = nums[i];
        //cout << "The mode is: " << mode << endl;
    } 
}
    return mode;
}
