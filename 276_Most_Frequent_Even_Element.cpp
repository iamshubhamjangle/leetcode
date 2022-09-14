/*
[Contest]_Most_Frequent_Even_Element.cpp

Given an integer array nums, return the most frequent even element.
If there is a tie, return the smallest one. If there is no such element, return -1.

https://leetcode.com/contest/weekly-contest-310/problems/most-frequent-even-element/
*/

class Solution {
public:
    // 1. iterate, map of freq for even. iterate on map find the smallest most freq.
    // TC: O(N) SC: O(N)
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> um;

        for(auto i: nums) {
            if(i%2 == 0) um[i]++;
        }

        int ans = -1;
        int ansFreq = -1;
        for(auto i: um) {
            if(i.second > ansFreq || (i.second == ansFreq && i.first < ans)) {
                ans = i.first;
                ansFreq = i.second;
            }
        }

        return ans;
    }
};