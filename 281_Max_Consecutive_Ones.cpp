/*
Max_Consecutive_Ones.cpp

Given a binary array nums, return the maximum number of consecutive 1's in the array.

Input: nums = [1,1,0,1,1,1]
Output: 3

Input: nums = [1,0,1,1,0,1]
Output: 2

https://leetcode.com/problems/max-consecutive-ones/
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxi = 0;

        for(int i=0; i<nums.size(); i++) {
        	if(nums[i] == 1) {
        		count++;
        	} else {
        		count = 0;
        	}
    		maxi = max(count, maxi);
        }

        return maxi;
    }


    // int findMaxConsecutiveOnes(vector<int>& nums) {
    //     int count = 0;
    //     int maxi = 0;

    //     for(int i=0; i<nums.size(); i++) {
    //     	count = (nums[i] == 1) ? count+1 : 0;
    // 		maxi = max(count, maxi);
    //     }

    //     return maxi;
    // }
};