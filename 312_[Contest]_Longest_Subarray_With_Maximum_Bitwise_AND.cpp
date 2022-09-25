/*
Longest_Subarray_With_Maximum_Bitwise_AND.cpp

Input: nums = [1,2,3,3,2,2]
Output: 2

Input: nums = [1,2,3,4]
Output: 1

https://leetcode.com/contest/weekly-contest-312/problems/longest-subarray-with-maximum-bitwise-and/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    	// as the array is sorted.
    	// AND will be max for maximum number. if we can find the count of maximum number as they are continuous.
    	// it will be the ans.
    	int n = nums.size();
    	int maxNum = -1;

    	for(int i=0; i<n; i++) {
    		maxNum = max(maxNum, nums[i]);
    	}

    	int maxCount = 0;
    	int count = 0;
    	for(int i=0; i<n; i++) {
    		if(nums[i] == maxNum) {
    			count++;
    		} else {
    			count = 0;
    		}
    		maxCount = max(maxCount, count);
    	}

    	return maxCount;
    }
};

int main(){
	vector<int> nums;
	Solution s;

	nums = {1,2,3,3,2,2};
	cout << s.longestSubarray(nums) << endl;

	nums = {1,2,3,4};
	cout << s.longestSubarray(nums) << endl;

	nums = {311155,311155,311155,311155,311155,311155,311155,311155,201191,311155};
	cout << s.longestSubarray(nums) << endl;
}