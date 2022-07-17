/*
[Contest-Easy]Maximum_Number_of_Pairs_in_Array.cpp
https://leetcode.com/problems/maximum-number-of-pairs-in-array/
*/


class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0) return {0,0};
        if(n == 1) return {0,1};
        
        int pairs = 0;
        int left = n;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-1; i++) {
            if(nums[i] == nums[i+1]) {
                pairs++;
                left-=2;
                i++;
            }
        }
        
        return {pairs, left};
    }
};