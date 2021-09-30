/*
    Mia Weber
    29/Sept/2021
    Jack-O'-Lantern Juxtaposition --> Kattis
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

int answer(int n, int t, int m) {
//s*2-R1
return (n*t*m); 
}

void test() {
    assert(answer(500,25,2) == 25000);
    assert(answer(4,3,1) == 12);
    assert(answer(250,42,12) == 126000);
    cerr << "All test cases passed...\n";
}

void solve() {
    int n;
    int t;
    int m;
    cin >> n >> t >> m;
    cout << answer(n,t,m) << endl;
}