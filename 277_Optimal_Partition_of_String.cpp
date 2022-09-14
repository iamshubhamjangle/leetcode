/*
Optimal_Partition_of_String.cpp

Input: s = "abacaba"
Output: 4

Input: s = "ssssss"
Output: 6

https://leetcode.com/contest/weekly-contest-310/problems/optimal-partition-of-string/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionString(string s) {
        int ans = 1;
        int mp[26] = {};

        for(int i=0; i<s.size(); i++) {
        	if(mp[s[i] - 'a']) {		// element is already in map
        		++ans;					// partition
        		fill(begin(mp), end(mp), 0); // reset the counter
        	}

        	mp[s[i] - 'a']++;
        }

        return ans;
    }
};

int main(){
	Solution s;
	cout << s.partitionString("abacaba") << endl;
	cout << s.partitionString("ssssss") << endl;
}
