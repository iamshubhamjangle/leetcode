/*
Count_Pairs_Of_Similar_Strings.cpp

https://leetcode.com/contest/weekly-contest-324/problems/count-pairs-of-similar-strings/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordsEqual(string &word1, string &word2) {
        unordered_set<char> s1;
        unordered_set<char> s2;
        for(auto ch: word1) s1.insert(ch);
        for(auto ch: word2) s2.insert(ch);
        return s1 == s2;
    }

    int similarPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(wordsEqual(words[i], words[j])) ans++;
            }
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<string> words;
    words = {"aba","aabb","abcd","bac","aabc"};
    cout << s.similarPairs(words) << endl;
    
    words = {"aabb","ab","ba"};
    cout << s.similarPairs(words) << endl;

    words = {"nba","cba","dba"};
    cout << s.similarPairs(words) << endl;

    words = {"zgtzytjkre","jjzdbxyutj","umghhnlihq","mdxjukhqsm","mqdplhuvqr","xpdhateywu","ugedwkxapc","vjpryhictr"};
    cout << s.similarPairs(words) << endl;

}