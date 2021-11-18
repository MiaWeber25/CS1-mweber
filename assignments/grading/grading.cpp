/*
    HW 8 - File IO and Struct
    By: Mia Weber
    Date: 16/Nov/2021

    Program utilizes file io and the struct data type to calculate statistics on student data

    Algorithm Steps:
    1. Prompt the user to enter an input file name to read data from ***DONE!!***
    2. Read n number of student records from input file into an array ***DONE!!***
    3. Prompt the user to enter an outfile name to write the data to ***DONE!!***
    4. Write functions to find student's average test scores and the letter grade using a standard grading scale ***DONE!!***
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
void findAvg(vector<studentData> &); //WILL THIS TAKE A VECTOR OR A STRUCT?
void findLetterGrade(vector<studentData> &); //WILL THIS TAKE A VECTOR OR A STRUCT?
void sortArray(vector<studentData> &); //function to sort the array in decending order
//BONUS FUNCTION?? 

//create struct to store student data
struct studentData {
    string firstName;
    string lastName;
    float tests[4];
    float avg;
    char letterGrade;
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
    //char space = ' ';
    //fin >> line.firstName >> line.lastName >> line.tests[0] >> line.tests[1] >> line.tests[2] >> line.tests[3];
    while(!fin.eof()) {
         fin >> line.firstName >> line.lastName;
         for (int i=0; i<4; i++) {
            fin >> line.tests[i]; 
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
    //formated output:
    fout << setw(101) << setfill('=') << " " << setfill(' ') << endl;
    fout << setw(20) << left << "fname" 
        << setw(20) << left << "lname";
    for(int i=0; i<4; i++) {
        string testHeader = "test" + to_string(i+1);
        fout << setw(10) << right << testHeader;
    }
    fout << setw(10) << right << "avg.";
    fout << setw(10) << right << "grade" << endl;
    fout << setw(101) << setfill('=') << " " << endl;

    //maipulated formated output: 
    //for loop for first and last name
    for (int i=0; i<gradebook.size(); i++) {
        fout << setw(20) << setfill(' ') <<  left << gradebook[i].firstName;
        fout << setw(20) << left << gradebook[i].lastName;
        //for loop for test scores
        for (int j=0; j<4; j++) {
            fout << setw(10) << right << gradebook[i].tests[j];
        }
        findAvg(gradebook);
        findLetterGrade(gradebook);
        sortArray(gradebook);
        fout << setw(10) << right << gradebook[i].avg;
        fout << setw(10) << right << gradebook[i].letterGrade << endl;
    }
    fout << setw(101) << setfill('*') << " " << endl;

    
}
bool findLarger(studentData & l1, studentData & l2) {
    return (l1.avg > l2.avg);
}
//function to find the average of the test scores
void findAvg(vector<studentData> & gradebook) {
    float sum = 0;
    for (int i=0; i<gradebook.size(); i++) {
        sum = gradebook[i].tests[0] + gradebook[i].tests[1] + gradebook[i].tests[2] + gradebook[i].tests[3];
        float average = sum/4;
        gradebook[i].avg = average;
    }    
}

//function to find the letter grade that corresponds to the average test grade
void findLetterGrade(vector<studentData> & gradebook) {
    for (int i=0; i<gradebook.size(); i++) {
        if (gradebook[i].avg >= 90) 
            gradebook[i].letterGrade = 'A';
        else if (gradebook[i].avg >= 80)
            gradebook[i].letterGrade = 'B';
        else if (gradebook[i].avg >= 70)
            gradebook[i].letterGrade = 'C';
        else if (gradebook[i].avg >= 60)
            gradebook[i].letterGrade = 'D';
    else 
        gradebook[i].letterGrade = 'F';
    }
}

//function to sort the array in descending order based off average test scores
void sortArray(vector<studentData> & gradebook) {
    sort(gradebook.begin(), gradebook.end(), & findLarger);

}
//TO DO: 
//  1. format output ***DONE!!*** **KEEP GOING FOR BONUS INFO!**
//  2. sort array - and print in sorted order
//  3. find bonus info - class avg, class max, class min, total a,b,c,d,f
        // class max: first index of sorted gradebook --> gradebook[0].avg
        // class min: last index of sorted gradebook --> gradebook.back().avg (this might be funky syntax wise...)
        //class average: find average of all the averages
        // percentage of as - need to know total number of students. Iterate through and count a's, b's, c's etc. then add and divide by total num of students for each letter grade
