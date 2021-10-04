/* 
    Mia Weber
    30/Sept/2021
    Take Two Stones --> Kattis
*/

#include <iostream>
#include <string>
#include <cassert>
#include <math.h>

using namespace std;

void test();
string answer(int stone);
void solve();

int main(int argc, char* argv[]) {
    if (argc > 1 && string(argv[1]) == "test")
        test();
    else 
        solve();
    return 0;
}

string answer(int stone) {
    int evenOdd = stone % 2;
    if (evenOdd %2 == 0) {
        return("Bob");
    } else {
        return("Alice");
    } 
}

void test() { 
    
    assert(answer(1000000) == "Bob");
    assert(answer(6) == "Bob");
    assert(answer(25) == "Alice");
    cerr << "All test cases passed...\n";
}

void solve() {
    int s;
    cin >> s ;
    cout << answer(s) << endl;
}