/*
    Mia Weber
    30/Nov/2021
    A New Alphabet Kattis Problem Description Here: https://open.kattis.com/problems/anewalphabet
    Write a function that takes plaintext and uses map to return cyphertext

    Algorithm Steps:
    1. Create a map of char to string to store the cypher information
    2. Read and parse input stream, seperate into chars and store into char vector "plainText"
    3. Iterate over char vector and determine if each element matches a key in cyper map
        - if it does - add the value associated with the key to the cypherText string
        - if it does not - add the char value to the cypherText string
    4. print the cypherText string as the output
*/

#include <iostream>
#include <string>
#include <cassert>
#include <math.h>
#include <map>
#include <vector>

using namespace std;

//FUNCTION PROTOTYPES
string answer(string&);
void solve();

void test() {
    //input value test #1
    string testInput1 = "I finished the PROblem!";
    assert(answer(testInput1) == "| #|[]\\[]|$[-]3|) ']['[-]3 |D|Z0813[]\\/[]!");
    //input value test #2
    string testInput2 = "MY name is, MiA!! yay!";
    assert(answer(testInput2)== "[]\\/[]`/ []\\[]@[]\\/[]3 |$, []\\/[]|@!! `/@`/!");
    //input value test #3
    string testInput3 = "TThe finall tesT&!";
    assert(answer(testInput3)== "']['']['[-]3 #|[]\\[]@11 ']['3$']['&!");
    cerr << "All test cases passed...\n";
}

int main(int argc, char* argv[]) {
    if (argc == 2 and string(argv[1]) == "test") {
        test();
    }
    else {
        solve();
    }
}

//solve function that realizes algorithm steps above
string answer(string& input) {
    map <char, string> cypher; //map called cypher that stores the cypher keys and values
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
    cypher['m'] = "[]\\/[]";
    cypher['n'] = "[]\\[]";
    cypher['o'] = "0";
    cypher['p'] = "|D";
    cypher['q'] = "(,)";
    cypher['r'] = "|Z";
    cypher['s'] = "$";
    cypher['t'] = "']['";
    cypher['u'] = "|_|";
    cypher['v'] = "\\/";
    cypher['w'] = "\\/\\/";
    cypher['x'] = "}{";
    cypher['y'] = "`/";
    cypher['z'] = "2";

    //seperate the input into chars and store in a char vector called plainText
    vector<char> plainText(input.begin(), input.end());
    //create a string variable called cypherText to use store the final answer later
    string cypherText;

    for (char i: plainText) { //iterate over the plainText char vector
        auto it = cypher.find(tolower(i)); //determine if the char from plainText matches a key in cypher (convert to lowercase also!)
        if (it != cypher.end()) { //if it appears then add the value to cypherText string
            cypherText+=it->second;
        }
        else { //if it doesn't appear then add the char value to cypherText string
            cypherText.push_back(i);
        }
    }
    return cypherText; //return the correct encrypted message stored in cypherText string
}

void solve() {
    //read in the input from the user and store in string called input
    string input;
    getline(cin, input);
    cout << answer(input) << endl;
}
