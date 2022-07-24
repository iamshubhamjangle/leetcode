/*
[Contest]_First_Letter_to_Appear_Twice.cpp

https://leetcode.com/problems/first-letter-to-appear-twice/
1. Using map. TC: O(N) SC: O(N)
2. Using Vector(26) TC: O(N) SC: O(26)

*/

#include <bits/stdc++.h>
using namespace std;

// Using map. TC: O(N) SC: O(N)
char repeatedCharacter(string s) {
	unordered_map<char, int> um;
	char ans;

	for(int i=0; i<s.length(); i++) {
		if(um[s[i]]) {
			ans = s[i];
			break;
		}
		um[s[i]]++;
	}

	return ans;
}

// Above solution can be improved using fixed size vector.
// Using Vector(26) TC: O(N) SC: O(26)
char repeatedCharacter(string s) {
    vector<int> v(26);
    for(char c:s){
        v[c-'a']++;
        if(v[c-'a']>1)return c;
    }
    return 'a';
}

int main(){
	int t;
	cin >> t;		//input no. of test cases
	while(t--){
		string s;
		cin >> s;
		cout << repeatedCharacter(s) << endl;	//run this 't' times
	}
}
