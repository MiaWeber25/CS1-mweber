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

    string input;
    //cin.ignore(' ');
    getline(cin, input);
    cout << "This is the input: " << input << endl; //FOR TESTING PURPOSES - DELETE LATER

    vector<char> plainText(input.begin(), input.end());
    vector<string> cypherText;
    //FOR LOOP FOR TESTING VECTOR METHOD - DELETE LATER
   // for(int i = 0; i<30; i++) {
       // cout << plainText[i] << endl;
        //determine if the plain text char is in cypher map 
       // if (cypher.count(plainText[i])==1) { //if it is present, add that value to cypherText vector
            //found! 
            //cypherText.push_back(cypher.second); 

      //  }
  //  }
    
    for (char i: plainText) { //iterate over the plainText 
        cout << i << " "; //i is the individual char in plainText
        tolower(plainText[i]);
        for (auto e: cypher) { //iterate over the cypher map
            if(e.first == i) //it the char in plainText matches the first element in map
                cypherText.push_back(e.second); //add the value to final vector
                //cout << e.second;
            else {
                //cout << "NO";
                //string(plainText[i]);
                //cypherText.push_back(plainText[i]); //otherwise, add the origional value to the final vector
                cypherText.push_back("*");
            }
        }
    } 
    for (auto m: cypherText) {
        cout << m << " ";
    }
}


void answer() {


}