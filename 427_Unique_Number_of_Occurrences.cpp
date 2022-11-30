/*
Unique_Number_of_Occurrences.cpp

https://leetcode.com/problems/unique-number-of-occurrences/
*/

class Solution {
public:
    // check if already in set. TC: O(N) SC: O(2N)
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> um;
        unordered_set<int> us;
        for(auto &n: arr) um[n]++;
        for(auto &m: um) {
            if(us.find(m.second) != us.end()) return false;
            us.insert(m.second);
        }
        return true;
    }
    
    // compare size of both map & set.  TC: O(N) SC: O(2N)
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        unordered_set<int> s;
        for (auto n : arr) ++m[n];
        for (auto& p : m) s.insert(p.second);
        return m.size() == s.size();
    }
};