/*
Sort_Characters_By_Frequency.cpp

https://leetcode.com/problems/sort-characters-by-frequency/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// TC: O(3N + (26)logN) SC: O(2N)
    string frequencySort(string s) {
        unordered_map<char, int> um;
        for(auto c: s) um[c]++;
        
        vector<pair<int, char>> v;  // freq, char
        for(auto i=um.begin(); i!=um.end(); i++) {
            v.push_back({i->second, i->first});
        }
        
        sort(v.begin(), v.end(), greater<pair<int,char>>());

        string ans;
        for(auto p: v) {
            int n = p.first;
            while(n--) ans += p.second;
        }
        return ans;
    }


    // Heaps: TC: O(3N + logN) SC: O(2N)
    string frequencySort(string s) {
        unordered_map<char,int> freq;           //for frequency of characters
        priority_queue<pair<int,char>> maxheap; //maxheap according to frequency of characters
        for(char c: s)
            freq[c]++;
        for(auto it: freq)
            maxheap.push({it.second,it.first}); //heap will be constructed on the basis of frequency
        s="";   
        while(!maxheap.empty()){
            s+=string(maxheap.top().first,maxheap.top().second); //frequency times the character
            maxheap.pop();
        }
        return s;
    }
};

int main(){
	Solution solution;
	string s = "tree";
	string ans = solution.frequencySort(s);
	cout << ans << endl;
	
}