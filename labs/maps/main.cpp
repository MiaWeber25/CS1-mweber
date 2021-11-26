/*
Kattis - Seven Wonders
Updatd By: Mia Weber
Date: 23/Nov/2021
Read Seven Wonders Problem Statement: https://open.kattis.com/problems/sevenwonders
Algorithm steps:
1. Read cards into a string variable
2. use map<char, int> to keep track of count of each card played
  - update map: for each card, update its count
3. find regular points following the instruction
  - points = sum of (each card_count)^2
4. add bonus points if any
  - find # of sets of three cards and mulitiply it by 7 and add it to the total points
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <map>
#include <string>

using namespace std;

using pos_int = unsigned int; // create type alias

// function prototypes
pos_int answer(const string& cards);
void testAnswer();
void solve();

int main(int argc, char* argv[]) {
    if (argc == 2 and string(argv[1]) == "test")
        testAnswer();
    else
        solve();
}

// solving the problem for kattis
void solve() {
    string cards;
    // string consists of only uppercase letters (no spaces) upto 50 chars
    // FIXME3 ##ADDRESSED##
    // read string into cards
    cin >> cards;
    //getline(cin, cards); //THIS IS ADDING A 0 TO THE END OF CARDS --> SEE IF THIS BECOMES A PROBLEM LATER.
    //cout << "cards: " << cards; //NEED TO DELETE LATER
    //cout << "answer(cards): " << answer(cards) << endl;
    cout << answer(cards) << endl;
}

pos_int answer(const string& cards) {
    // implment algorithm step 2
    // wonders is a map from char to int
    map<char, int> wonders;
    // for each card in cards
    for (char card: cards) {
      // check if card is already in wonders map
      auto find = wonders.find(card);
      if (find == wonders.end()) {// card not found
        // add it to the wonders map
        wonders[card] = 1;
      }
      else {// FIXME4: update value of card ##ADDRESSED##
        wonders[card]+= 1; //DO YOU JUST WANT TO INCREMENT IT BY ONE OR BY NUMBER OF OCCURANCES IN THE INPUT STRING? 
      }
    //cout << card << " " << wonders[card] << endl; //I THINK THIS IS WORKING, BUT I NEED TO BE SURE THAT MAPS ONLY CONCSITS OF THE LAST ELEMENTS AND NOT THE ENTIRE THING THAT GETS PRINTED HERE (SINCE IT'S INSIDE THE FOR LOOP).
    }
    // algorithm step 3 - calculate points
    pos_int points = 0, min_card = 999999;
    for (auto pair: wonders) { // for is pair of <card, count>
      // FIXME5 - Update the points by adding count^2 ##ADDRESSED## //PROBLEM IS THAT I HAVE NO REAL WAY TO TEST IF THIS IS WORKING CORRECTLY THE WAY THAT I WANT IT TO BE...
      points = pair.second^2;
      min_card = (pair.second < min_card)?pair.second:min_card;
    }
    // step 4 - add bonus points if any
    if (wonders.size() == 3) // if there are 3 unique cards
      points += min_card*7;

    return points;
}

// unit testing answer()
void testAnswer() {
    // FIXME6
    // write at least two test cases to test answer()
    cerr << "All test cases passed!\n";
}