/*
    Mia Weber
    30/Nov/2021
    A New Alphabet 
*/

#include <iostream>
#include <string>
#include <cassert>
#include <math.h>
#include <map>
#include <algorithm> 
#include <vector>

using namespace std;

void test();
void answer(int&, int &);
void solve();

int main(int argc, char* argv[]) {
    if (argc > 1 && string(argv[1]) == "test") {
        //test();
    }
    else 
        solve();
    return 0;
}

void solve() {
    map <char, string> cypher; 
    //eng2Span["one"] = "uno";
    cypher['a'] = "@";
    cypher['b'] = "8";
    cypher['c'] = "(";
    cypher['d'] = "|)";
    cypher['e'] = '3';
    cypher['f'] = "#";
    cypher['g'] = "6";
    cypher['h'] = "[-]";
    cypher['i'] = "|";
    cypher['j'] = "_|";
    cypher['k'] = "|<";
    cypher['l'] = "1";
    cypher['m'] = "[]\\/[]"; //SEE IF THIS WORKS...
    cypher['n'] = "[]\\[]"; //SEE IF THIS WORKS...
    cypher['o'] = "0";
    cypher['p'] = "|D";
    cypher['q'] = "(,)";
    cypher['r'] = "|Z";
    cypher['s'] = "$";
    cypher['t'] = "']['";
    cypher['u'] = "|_|";
    cypher['v'] = "\\//"; //SEE IF THIS WORKS...
    cypher['w'] = "\\//\\//"; //SEE IF THIS WORKS...
    cypher['x'] = "}{";
    cypher['y'] = "`//";
    cypher['z'] = "2";

    for (int i=0; i<27; i++) {
        cout << cypher[i] << endl; 
    }


}

void answer() {


}