/*
Sliding_Window_Maximum.cpp

You are given an array of integers nums, there is a sliding window of size k 
which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3, n = 8
Output: [3,3,5,5,6,7]

https://leetcode.com/problems/sliding-window-maximum/
*/

#include <bits/stdc++.h>
using namespace std;
/*
i = 0
j = 0,1,2
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0; i<n-k+1; i++) {
        	int maxi = INT_MIN;
        	for(int j=i; j<i+k; j++) {
        		maxi = max(maxi, nums[j]);
        	}
        	ans.push_back(maxi);
        }

        return ans;
    }
};