/*
Group_Anagrams.cpp

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

https://leetcode.com/problems/group-anagrams/
*/

class Solution {
public:
	// Map with key as sorted word and value as list of strs.
	// TC: O(N*NlogN) SC: O(N)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	int n = strs.size();
    	unordered_map<string, vector<string>> um;

    	for(auto &s: strs) {
    		string temp = s;
    		sort(temp.begin(), temp.end());
			um[temp].push_back(s);
    	}

    	vector<vector<string>> anagrams;
    	for(auto &it: um)
    		anagrams.push_back(it.second);

    	return anagrams;
    }



    // Method 2: Using counter sort instead of merge sort. O(26*2)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) 
        	mp[strSort(s)].push_back(s);
        
        vector<vector<string>> anagrams;
        for (auto p : mp) 
        	anagrams.push_back(p.second);
        
        return anagrams;
    }

    string strSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};





class Solution {
public:
    
};