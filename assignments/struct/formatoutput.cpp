#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cassert>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    
int colWidth = 20;
    cout << setw(101) << setfill('=') << " " << setfill(' ') << endl;
    cout << setw(20) << left << "fname" 
        << setw(20) << left << "lname";
    for(int i=0; i<4; i++) {
        string testHeader = "test" + to_string(i+1);
        cout << setw(10) << right << testHeader;
    }
    cout << setw(10) << right << "avg."; // << endl;
    cout << setw(10) << right << "grade" << endl;
    cout << setw(101) << setfill('=') << " " << endl;

    return 0;
}
struct StudentGrade {
    string firstName;
    string lastName;
    int grades[3];
    float averageGrade;
    char letterGrade;
};

void printOutput() { 
    // write column headers
    

    /* write records
    cout << setfill(' ') << fixed << setprecision(1);
    for(StudentGrade s; s<gradebook.size(); s++) {
        cout << setw(colWidth) << left << s.firstName
            << setw(colWidth) << left << s.lastName;
        for(int i=0; i<3; i++)
            cout << setw(10) << right << s.grades[i];
        cout << setw(15) << right << s.averageGrade << endl;
    }
    cout << setw(90) << setfill('*') << " " << endl;
*/
}