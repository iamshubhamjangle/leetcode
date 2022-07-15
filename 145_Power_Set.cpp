/*
Power_Set.cpp

Given a string S, Find all the possible 
subsequences of the String in lexicographically-sorted order.

Input : str = "abc"
Output: a ab abc ac b bc c

Input: str = "aa"
Output: a a aa

https://practice.geeksforgeeks.org/problems/power-set4302/1
Method: TC: O(2n) SC: O(n * 2n)
Recursive one including, one without.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
    void powerSet(string s, int i, string ans, vector<string> &v) {
        if(i == s.length()) {
            if(ans != "")
                v.push_back(ans);
            return;
        }
        powerSet(s, i+1, ans + s[i], v);
        powerSet(s, i+1, ans, v);
    }

	vector<string> AllPossibleStrings(string s){
	    vector<string> v;
	    powerSet(s, 0, "", v);  // string, index, curr string, answer vector
	    sort(v.begin(), v.end());
	    return v;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
