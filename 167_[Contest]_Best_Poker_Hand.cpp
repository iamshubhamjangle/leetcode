/*
[Contest]_Best_Poker_Hand.cpp

https://leetcode.com/contest/biweekly-contest-83/problems/best-poker-hand/
1. Use two unordered_map to check repeating counts TC: O(N) SC: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

// void solve();
string bestHand(vector<int>& ranks, vector<char>& suits) {
    unordered_map<char, int> um;
    for(int i=0; i<suits.size(); i++) {
        um[suits[i]]++;
    }
    int maxInSuits = 0;
    for(auto it: um) {
        maxInSuits = max(maxInSuits, it.second);
    }
    if(maxInSuits == suits.size()) return "Flush";

    unordered_map<int,int> um2;
    int maxInRanks = 0;
    for(int i=0; i<ranks.size(); i++) {
        um2[ranks[i]]++;
    }
    for(auto it: um2) {
        maxInRanks = max(maxInRanks, it.second);
    }
    if(maxInRanks >= 3) return "Three of a Kind";
    if(maxInRanks == 2) return "Pair";

    return "High Card";
}

int main(){
    int t;
    cin >> t;        //input no. of test cases
    while(t--){
        vector<int> ranks = {4,4,2,4,4};
        vector<char> suits = {'a','b','c','d','a'};
        cout << bestHand(ranks, suits);
    }
}
