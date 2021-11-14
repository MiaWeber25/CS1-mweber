/* 
    CS1 - File I/O Lab

    Updated By: Mia Weber
    Date: 09/Nov/2021

    This program reads numbers from a file and finds statistical values from those numbers .
    Lab demonstrates the file io and vector application.
    Statistical value's definitions for mean, media, mode, etc. can be found here: https://www.purplemath.com/modules/meanmode.htm
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cassert>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

const float EPSILON = 1e-4; //accurary up to 4 decimal places

//FUNCTION PROTOTYPES
void readData(vector<int> &, const string);
int findMax(const vector<int> &);
int findMin(const vector<int> &);
float findMean(const vector<int> &); //average
int findRange(const vector<int> &);
float findMedian(vector<int>);
//bonus implement findMode function HERE
int findMode(const vector<int> &);
void writeData(const vector<int> & numbers);
void test();

int main(int argc, char* argv[]) {
    if (argc == 2 && string(argv[1]) == "test") {
        //test();
        return 0;
    }
    vector<int> numbers;
    string inFile;
    cout << "Enter input file name: ";
    getline(cin, inFile);
    readData(numbers, inFile);
    writeData(numbers);
    cout << "All done. Enter to exit...";
    cin.get();
    return 0;
}

void readData(vector<int> & numbers, const string inputFileName) {
    //FIXME3: Open inputFile Name for reading data ##ADDRESSED##
    cout << inputFileName << endl;
    ifstream fin;
    fin.open(inputFileName, ios::in); 
    //read the data until eof marker and store each num into numbers vector
    int line;
    //prime the input stream: 
    fin >> line; 
    //while loop to add each value to numbers vector
    while (fin) { //same thing as while(fin.good())
        numbers.push_back(line);  
        fin >> line;
        //cout << "while loop line" << line << endl;
    } 
    //FOR LOOP FOR TESTING PUROSES
    for (int i=0; i<7; i++) {
        cout << numbers[i] <<endl;
    }
    int num; //NOT USING THIS - GIVEN IN CODE SNIPPET
}

void writeData(const vector<int> & numbers) {
    //FIXME4
    //Algorithm Steps:
    //1. Prompt user to enter output file name #ADDRESSED#
    string outfile;
    cout << "Enter output file name: ";
    //2. Store and use the file name to open the file in write mode #ADDRESSED# 
    cin >> outfile;
    ofstream fout;
    fout.open(outfile); //open in write mode
    //3. Write output as shown in output.txt file wiht proper formatting using iomanip ***STILL NEED TO DO***
    fout << "List of Numbers: ";
    for (int i=0;i<numbers.size(); i++) {
        fout << numbers[i] << " ";
    }
    fout << " " << setfill(' ') << endl;
    /*
    fout << endl << endl << setw(40) << setfill('=') << endl;
    fout << "Statistical Results";
    fout << setw(40) << setfill('=') << endl;
    fout << endl << "Max" << endl;
    fout << endl << findMax(numbers) << endl;
    fout << findMean(numbers);
    fout << findMedian(numbers); //this isn't working. why?? 
    fout <<findMin(numbers);
    cout << "Min: " << findMin(numbers) << endl;
    cout << "Max: " << findMax(numbers) << endl;
    cout << "Range: " << findRange(numbers) << endl;
    cout << "Mode: " << findMode(numbers) << endl;
*/
fout << endl << setw(50) << setfill('=') << " " << setfill(' ') << endl;
fout << fixed << setprecision(2); 
fout << setw(25) << setfill(' ') << setfill(' ') << "Statistical Results" << setw(25)  << endl;
fout << setw(50) << setfill('=') << " " << setfill(' ') << endl;
fout << setw(25) << left << "Apple" << setw(25) << right << 5.99 << endl;
fout << setw(25) << left << "Carrots" << setw(25) << right << 2.55 << endl;
fout << setw(50) << setfill('*') << " " << setfill(' ') << endl;

}

int findMax(const vector<int> & nums) {
    int max = nums[0];
    //for(int n: nums) 
        //max = (n>max) ? n : max;
    //for(int n = 0; n < nums.size(); n++) {
    //    max = (n>max) ? n : max;
   // }
    return *max_element(nums.begin(), nums.end());
}

//<< *min_element(a.begin(), a.end());

int findMin(const vector<int> & nums) {
    //FIXME5: implement function to find and return min value from nums vector
    //int min = nums[0];
    //for (int i = 0; i<nums.size(); i++) {
       // min = (i<min) ? i : min;
    //}
    return *min_element(nums.begin(), nums.end());
}

float findMean(const vector<int> & nums) {
    //same as average
    long long int sum = 0;
    for (int n = 0; n < nums.size(); n++) {
        sum += nums[n];
    }
    return sum/float(nums.size());
}

int findRange(const vector<int> & nums) {
    //FIXME6: implement function that finds and returns the range value
    //range = max - min
    return findMax(nums) - findMin(nums);;
}

float findMedian(vector<int> nums) {
    sort(nums.begin(), nums.end());
    float median;
    if (nums.size() % 2 == 0) { //even set
        median = (nums[nums.size()/2] + nums[nums.size()/2-1])/float(2);
    } else { //odd set
        median = nums[nums.size()/2];
    }
    return median;
}

int findMode(const vector<int> & nums) {
    int mode = 0;
    int count;
    for (int i = 0; i< nums.size(); i++) {
        int tempCount = 0;
        for (int j = 0; j<nums.size(); j++) {
            if (nums[i] == nums[j]) {
                ++tempCount;
            }
        }
        if (tempCount > count) {
            count = tempCount;
            mode = nums[i];
        } else {
            mode = 8;
        }

    }
    /*if (count > 1) {
        return mode;
    } else {
        return 0;
    }
    */
   return mode;
}


/*
void test() {
    vector<int> numbers = {100, 10, 5, 0, -99, 10, 99};
    //cout findMedian(numbers) << " " << findMean(numbers)-17.857142 << endl;
    assert(fabs(findMean(numbers)-17.857142) <= EPSILON);
    assert(findMax(numbers) == 100);
    assert(findMedian(numbers) == 10);
    vector<int> numbers1 = {10, 10, 10, 0, -10, -10};
    assert(fabs(findMean(numbers1)-1.6667) <= EPSILON);
    assert(findMax(numbers1) == 5);
    assert(findMedian(numbers1) == 5);
    //fIXME7: Write at least two test cases for other functions.

    cerr << "all test cases passed!\n";
}
*/