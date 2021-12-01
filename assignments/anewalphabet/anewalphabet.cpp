/*
    Mia Weber
    30/Nov/2021
    A New Alphabet Kattis Problem Here: https://open.kattis.com/problems/anewalphabet 
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
    cypher['v'] = "\\/"; //SEE IF THIS WORKS...
    cypher['w'] = "\\/\\/"; //SEE IF THIS WORKS...
    cypher['x'] = "}{";
    cypher['y'] = "`/";
    cypher['z'] = "2";

    string input;
    getline(cin, input);
    //cout << "This is the input: " << input << endl; //FOR TESTING PURPOSES - DELETE LATER

    vector<char> plainText(input.begin(), input.end());
    //vector<string> cypherText;
    string cypherText;

    for (char i: plainText) { //iterate over the plainText 
        //tolower(plainText[i]);
        //cout << tolower(i) << " "; //i is the individual char in plainText
       /* for (auto e: cypher) { //iterate over the cypher map
            if(e.first == i) //is it plainText[i] or just i
                cypherText.push_back(e.second); //add the value to final vector
            else {
                //string(plainText[i]);
                //cypherText.push_back(plainText[i]); //otherwise, add the origional value to the final vector
                cypherText.push_back("*");
            }
        }*/
        auto it = cypher.find(i);
        if (it != cypher.end()) {
            //cypherText.push_back(it->second); //WORKED FOR THE VECTOR
            cypherText+=it->second;
        }
        else {
            //string(i);
            cypherText.push_back(i);
        }
       // i++; DO I NEED THIS? I DON'T THINK THAT I DO...
    } 
    for (auto m: cypherText) {
        cout << m << " ";
    }
    cout << endl;
}


void answer() {


}