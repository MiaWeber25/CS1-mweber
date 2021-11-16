/*
    HW 8 - File IO and Struct
    By: Mia Weber
    Date: 16/Nov/2021

    Program utilizes file io and the struct data type to calculate statistics on student data

    Algorithm Steps:
    1. Prompt the user to enter an input file name to read data from ***DONE!!***
    2. Read n number of student records from input file into an array ***DONE!!***
    3. Prompt the user to enter an outfile name to write the data to ***DONE!!***
    4. Write functions to find student's average test scores and the letter grade using a standard grading scale
    5. Write a function to sort the array of student records in descending order based on avg test scores
    **BONUS
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

//FUNCTION PROTOTYPES
struct studentData;
void readData(vector<studentData> &, string); //function to read data from input file
void writeData(vector<studentData> &); //function to write data to output file
float findAvg(vector<studentData> &); //WILL THIS TAKE A VECTOR OR A STRUCT?
char findLetterGrade(vector<studentData> &); //WILL THIS TAKE A VECTOR OR A STRUCT?
int sortArray(vector<studentData> &); //function to sort the array in decending order
//BONUS FUNCTION?? 

//create struct to store student data
struct studentData {
    string firstName;
    string lastName;
    float tests[4];
};

//main function to call readData and writeData 
int main() {
    vector<studentData> gradebook;
    string inFile;
    cout << "Please enter input file name:" << endl;
    getline(cin, inFile);
    readData(gradebook, inFile);
    writeData(gradebook);
    cout << "Complete! Enter to exit the program.";
    cin.get();
    return 0;
}

//function to read data from input file
void readData(vector<studentData> & gradebook, string inFile){
    ifstream fin;
    fin.open(inFile, ios::in);
    studentData line;
    fin >> line.firstName >> line.lastName >> line.tests[0] >> line.tests[1] >> line.tests[2] >> line.tests[3];
    while(fin) {
        for(int i=0; i<4;i++) { 
            fin >> line.firstName >> line.lastName >> line.tests[i]; 
        }
        gradebook.push_back(line);
    }
}

//function to write data to output file
void writeData(vector<studentData> & gradebook) {
    string outFile;
    cout << "Please enter the output file name: ";
    getline(cin, outFile);
    ofstream fout;
    fout.open(outFile);
    fout << "input from input file: " << endl;
    for (int i=0; i<gradebook.size(); i++) {
        fout << gradebook[i].firstName << endl;
        fout << gradebook[i].lastName <<endl;
        for (int j=0; j<4; j++) {
            fout << gradebook[i].tests[j] << endl;
        }
    }
    fout << "average: " << findAvg(gradebook) << endl;
}


//float findAvg(vector<studentData> &); //WILL THIS TAKE A VECTOR OR A STRUCT?
//function to find the average of the test scores
float findAvg(vector<studentData> & gradebook) {
    float sum;
    for (int i=0; i<gradebook.size(); i++) {
        for (int j=0; j<4; j++) {
            sum += gradebook[i].tests[j];
        }
    }
    return sum/4;
}