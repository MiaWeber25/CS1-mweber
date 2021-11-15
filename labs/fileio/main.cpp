/* 
    CS1 - File I/O Lab

    Updated By: Mia Weber
    Date: 09/Nov/2021

    This program reads numbers from a file and finds statistical values from those numbers .
    Lab demonstrates the file io and vector application.
    Statistical value's definitions for mean, media, mode, etc. can be found here: https://www.purplemath.com/modules/meanmode.htm
    Resource for reading in values to vectors: https://www.udacity.com/blog/2021/05/how-to-read-from-a-file-in-cpp.html 
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
        test();
        return 0;
    }
    //function calls: 
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

//function to get inputfile name and add vales in input file to vector
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
    } 
}

//function to write statistical results in output file 
void writeData(const vector<int> & numbers) {
    //FIXME4 ##ADDRESSED##
    //Algorithm Steps:
    //1. Prompt user to enter output file name #ADDRESSED#
    string outfile;
    cout << "Enter output file name: ";
    //2. Store and use the file name to open the file in write mode #ADDRESSED# 
    cin >> outfile;
    ofstream fout;
    fout.open(outfile); //open in write mode
    //3. Write output as shown in output.txt file wiht proper formatting using iomanip ##ADDRESSED##
    fout << "List of Numbers: ";
    for (int i=0;i<numbers.size(); i++) {
        fout << numbers[i] << " ";
    }
    fout << " " << setfill(' ') << endl;
    fout << endl << setw(42) << setfill('=') << " " << setfill(' ') << endl;
    fout << fixed << setprecision(2); 
    fout << setw(25) << setfill(' ') << setfill(' ') << "Statistical Results" << setw(25)  << endl;
    fout << setw(42) << setfill('=') << " " << setfill(' ') << endl;
    fout << setw(5) << left << "Max" << " " << left << "Min" << " ";
    fout << setw(3) << " " << "Mean";//max
    fout << setw(3) << " " << "Median";
    fout << setw(3) << " " << "Range";
    fout << setw(3) << " " << "Mode" << endl; //MODE ISN'T WORKING YET...
    fout << setw(5) << left << findMax(numbers);
    fout << " " << findMin(numbers) << " ";
    fout << setw(2) << " " << findMean(numbers) << " ";
    fout << setw(3) << " " << findMedian(numbers) << " ";
    fout << setw(4) << " " << findRange(numbers);
    fout << setw(5) << " " << findMode(numbers) << endl; //MODE ISN'T WORKING YET...
}

//function to find the maximum value 
int findMax(const vector<int> & nums) {
    return *max_element(nums.begin(), nums.end());
}

//function to find the minumum value
int findMin(const vector<int> & nums) {
    //FIXME5: implement function to find and return min value from nums vector ##ADDRESSED##
    return *min_element(nums.begin(), nums.end());
}
//function to find the mean value (average)
float findMean(const vector<int> & nums) {
    //same as average
    long long int sum = 0;
    for (int n = 0; n < nums.size(); n++) {
        sum += nums[n];
    }
    return sum/float(nums.size());
}

//function to find the range of the values 
int findRange(const vector<int> & nums) {
    //FIXME6: implement function that finds and returns the range value ##ADDRESSED##
    //range = max - min
    return findMax(nums) - findMin(nums);;
}

//function to find the median value
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

//function to find the mode of the values *doesn't work if no mode or if multiple modes (need to use hashmap! --> fix later)
int findMode(const vector<int> & nums) {
    int localCount = 0;
    int greatestValue = 0;
    int mode = 0;
    for (int i=0; i<nums.size(); i++) { //itterate through every element of nums
        localCount = count(nums.begin(), nums.end(), nums[i]); //localCount = number of occurences of nums at i 
        if (localCount > greatestValue) { //WHAT IF IT'S EQUAL TO??
            greatestValue = localCount;
            mode = nums[i];
        } 
    }
    return mode;
}

void test() { //REMEMBER TO ADD TEST CASES IF I GET MODE WORKING!!!
    //TEST #1
    vector<int> numbers;
    numbers.push_back(100);
    numbers.push_back(10);
    numbers.push_back(5);
    numbers.push_back(0);
    numbers.push_back(-99);
    numbers.push_back(10);
    numbers.push_back(99);
    //cout << findMean(numbers) << " " << findMean(numbers)-17.857142 << endl;
    assert(fabs(findMean(numbers)-17.857142) <= EPSILON );
    assert(findMax(numbers) == 100);
    assert(findMedian(numbers) == 10);
    //TEST #2
    vector<int> numbers1;
    numbers1.push_back(10); 
    numbers1.push_back(10);
    numbers1.push_back(10);
    numbers1.push_back(0);
    numbers1.push_back(-10);
    numbers1.push_back(-10);
    assert(fabs(findMean(numbers1) -1.6667) <= EPSILON  );
    assert(findMax(numbers1) == 10);
    assert(findMedian(numbers1) == 5);
    // FIXME7: Write at least two test cases for other functions ##ADDRESSED##
    //TEST #3
    vector<int> numbers2;
    numbers2.push_back(60);
    numbers2.push_back(67);
    numbers2.push_back(-76);
    numbers2.push_back(600);
    numbers2.push_back(23);
    assert(findRange(numbers2) == 676);
    assert(findMax(numbers2) == 600);
    assert(findMedian(numbers2) == 60);
    //TEST #4
    vector<int> numbers3;
    numbers3.push_back(-100);
    numbers3.push_back(-60);
    numbers3.push_back(-600);
    numbers3.push_back(-60);
    numbers3.push_back(-50);
    numbers3.push_back(-1);
    numbers3.push_back(0);
    assert(findMax(numbers3) == 0);
    assert(findRange(numbers3) == 600);
    assert(fabs(findMean(numbers3) - -124.4286) <= EPSILON);

    cerr << "all test cases passed!\n";
}