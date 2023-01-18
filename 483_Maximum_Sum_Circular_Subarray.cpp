/*
Maximum_Sum_Circular_Subarray.cpp

https://leetcode.com/problems/maximum-sum-circular-subarray/description/
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int currMax = 0;
        int maxSum = nums[0];
        int currMin = 0;
        int minSum = nums[0];
        int total = 0;

        for(int i=0; i<n; i++) {
            currMax = max(nums[i] + currMax, nums[i]);
            maxSum = max(currMax, maxSum);
            currMin = min(nums[i] + currMin, nums[i]);
            minSum = min(currMin, minSum);
            total += nums[i];
        }

        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};