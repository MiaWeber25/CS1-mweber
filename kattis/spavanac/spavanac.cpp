/* 
    Mia Weber
    06/Oct/2021
    Spavanac --> Kattis
*/

#include <iostream>
#include <string>
#include <cassert>
#include <math.h>
#include <string>

using namespace std;

void test();
string answer(int n1, int n2);
void solve();

int main(int argc, char* argv[]) {
    if (argc > 1 && string(argv[1]) == "test")
        test();
    else 
        solve();
    return 0;
}

string answer(int hours, int mins) {
    int totalmins = (hours * 60) + mins; 
    if (totalmins - 45 >= 0) {
        totalmins -= 45;
    } else {
        int remainding_mins = totalmins - 45;
        totalmins = 1440 + remainding_mins;
    }
    string final_hours = to_string(totalmins / 60);
    string final_mins = to_string(totalmins % 60);

    return final_hours + ' ' + final_mins;
    //convert to minutes by *60
    //if minutes - 45 >= 0, then subtract 45. Else, add your negative remainder to 1440 (minutes in a day) then convert back to hours
    // cast int to string to return them. string ___ = to_string(____/60; this gives hours, if we % then we get the remainding minutes
    //return ___(string) + ' ' + _____(string);
    //for testing, it should be == "9" "20"
}

void test() { 
    
    assert(answer(0, 0) == "23 15");
    assert(answer(23, 0) == "22 15");
    assert(answer(1, 50) == "1 5");
    cerr << "All test cases passed...\n";
}

void solve() {
    int num1;
    int num2;
    cin >> num1 >> num2 ;
    cout << answer(num1, num2) << endl;
}