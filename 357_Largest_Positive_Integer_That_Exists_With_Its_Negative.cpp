/*
Largest_Positive_Integer_That_Exists_With_Its_Negative.cpp

https://leetcode.com/contest/weekly-contest-315/problems/largest-positive-integer-that-exists-with-its-negative/
*/


class Solution {
public:
    int findMaxK(vector<int>& nums) {
    	int n = nums.size();
    	if(n <= 1) return -1;

        int l = 0;
        int r = n-1;

        sort(nums.begin(), nums.end());

        while(l < r) {
        	if(abs(nums[l]) == abs(nums[r])) {
        		return abs(nums[l]);
        	}
        	if(abs(nums[l]) > abs(nums[r]))
        		l++;
        	else
        		r--;
        }

        return -1;
    }
};


