/* 
    Mia Weber
    30/Sept/2021
    R2 --> Kattis
*/

#include <iostream>
#include <string>
#include <cassert>
#include <math.h>

using namespace std;

void test();
int answer(int r1, int s);
void solve();

int main(int argc, char* argv[]) {
    if (argc > 1 && string(argv[1]) == "test")
        test();
    else 
        solve();
    return 0;
}

int answer(int r1, int s) {
//s*2-R1
return ((s*2)-r1); 
}

void test() {
    assert(answer(11,15) == 19);
    assert(answer(4,3) == 2);
    assert(answer(25,4) == -17);
    cerr << "All test cases passed...\n";
}

void solve() {
    int r1;
    int s;
    cin >> r1 >> s;
    cout << answer(r1, s) << endl;
}