/* 
    Mia Weber
    07/Oct/2021
    Sort Two Numbers --> Kattis
*/

#include <iostream>
#include <string>
#include <cassert>
#include <math.h>

using namespace std;

void test();
void answer(int&, int&);
void solve();

int main(int argc, char* argv[]) {
    if (argc > 1 && string(argv[1]) == "test")
        test();
    else 
        solve();
    return 0;
}

void answer(int& n1, int& n2, int& smaller, int& larger) {
    if (n1 < n2) {
        smaller = n1;
        larger = n2;
        //cout << smaller << endl;
        //cout << larger << endl; 
    } else {
        smaller = n2;
        //cout << smaller << endl;
        larger = n1;
        //cout << larger << endl;
    }
}

void test() { 
    //int small, large;
    //answer(10000, 0, smaller, larger);
    //assert(answer == 0 10000); 
    //assert(small == 0 && large == 10000);
    //assert(answer(1000000, 8876666) == 9876666 );
    //assert(answer(4324, 10001) == 14325);
    //assert(answer(25, 966) == 991);
    int smaller, larger;
    int test1 = 1000000;
    int test2 = 0;
    answer(test1, test2, smaller, larger);
    assert(smaller < larger);

    test1 = -456;
    test2 = -34;
    answer(test2, test1, smaller, larger);
    assert(smaller < larger);    

    test1 = 7837382;
    test2 = -2345;
    answer(test1, test2, smaller, larger);
    assert(smaller < larger); 
    
    cerr << "All test cases passed...\n";
}

void solve() {
    int n1, n2, smaller, larger;
    cin >> n1 >> n2;
    answer(n1, n2, smaller, larger);
    cout << smaller << ' ' << larger << endl;
}