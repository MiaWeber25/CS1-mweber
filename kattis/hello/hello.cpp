/* 
    Mia Weber
    29/Sept/2021
    Hello World --> Kattis
*/

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

void test();
string answer();
void solve();

int main(int argc, char* argv[]) {
    if (argc > 1 && string(argv[1]) == "test")
        test();
    else 
        solve();
    return 0;
}

string answer() {
    return "Hello World!";
}

void test() {
    assert(answer() == "Hello World!");
    cerr << "All test cases passed...\n";
}

void solve() {
    cout << answer() << endl;
}


