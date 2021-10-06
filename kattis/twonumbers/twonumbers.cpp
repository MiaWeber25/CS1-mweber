/* 
    Mia Weber
    05/Oct/2021
    Add Two Numbers --> Kattis
*/

#include <iostream>
#include <string>
#include <cassert>
#include <math.h>

using namespace std;

void test();
int answer(int n1, int n2);
void solve();

int main(int argc, char* argv[]) {
    if (argc > 1 && string(argv[1]) == "test")
        test();
    else 
        solve();
    return 0;
}

int answer(int n1, int n2) {
   return n1 + n2;
}

void test() { 
    
    assert(answer(1000000, 8876666) == 9876666 );
    assert(answer(4324, 10001) == 14325);
    assert(answer(25, 966) == 991);
    cerr << "All test cases passed...\n";
}

void solve() {
    int num1;
    int num2;
    cin >> num1 >> num2 ;
    cout << answer(num1, num2) << endl;
}