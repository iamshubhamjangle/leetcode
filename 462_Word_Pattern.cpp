/*
Word_Pattern.cpp

https://leetcode.com/problems/word-pattern/
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// TC: O(N) SC: O(N)
    vector<string> stringSplitBy(string s, char splitBy) {
        int n = s.size();
        vector<string> res;
        string word = "";

        for(int i=0; i<=n; i++) {
            if(s[i] == ' ' || i == n) {
                res.push_back(word);
                word = "";
            } else {
                word += s[i];
            }
        }

        return res;
    }

    // TC: O(2N) SC: O(3N)
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> umStringLetter;
        unordered_map<char, string> umLetterString;
        vector<string> vs = stringSplitBy(s, ' ');

        if(vs.size() != pattern.size()) return false;

        for(int i=0; i<vs.size(); i++) {
        	if(umLetterString.find(pattern[i]) == umLetterString.end() &&
        		umStringLetter.find(vs[i]) == umStringLetter.end()) {
        		umLetterString[pattern[i]] = vs[i];
        		umStringLetter[vs[i]] = pattern[i];
        	} else {
        		if(umLetterString[pattern[i]] != vs[i] || umStringLetter[vs[i]] != pattern[i])
        			return false;
        	}
        }
        
        return true;
    }
};

/*
umStringLetter = { "dog": 'a' }
umLetterString = { 'a': "dog" }
*/
int main(){
	Solution s;

	cout << s.wordPattern("abba", "dog cat cat dog") << endl;
	cout << "-----------" << endl;
	cout << s.wordPattern("abba", "dog cat cat fish") << endl;
	cout << "-----------" << endl;
	cout << s.wordPattern("aaaa", "dog cat cat dog") << endl;
	cout << "-----------" << endl;
	cout << s.wordPattern("abba", "dog dog dog dog") << endl;
	cout << "-----------" << endl;
	cout << s.wordPattern("abc", "dog cat dog") << endl;
	cout << "-----------" << endl;
	cout << s.wordPattern("abc", "abc") << endl;
}



