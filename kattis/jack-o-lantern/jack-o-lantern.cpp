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
int answer();
void solve();

int main(int argc, char* argv[]) {
    if (argc > 1 && string(argv[1]) == "test")
        test();
    else 
        answer();
    return 0;
}

int answer(int N, int T, int M) {
    char ch;
    cin >> N >> ch >> T >> ch >> M >> ch;
    int ans = (N+T+M);
    cout << ans;
    return 0;
}

void test() {
    //assert(answer() == );
    //cerr << "All test cases passed...\n";
}

void solve() {
    //cout << answer() << endl;
}



