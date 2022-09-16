/*
Remove_Duplicates_from_Sorted_Array.cpp

Given an integer array nums sorted in non-decreasing order, remove the 
duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same.

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]

https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/


class Solution {
public:
	// 1. Bruteforce. TC: O(NlogN) SC: O(N)
	//	  Put in set (logN) and replace M element to original array and return size of set
	// 2. Optimal Two pointer. TC: O(N) SC: O(1)
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0)
        	return 0;

        int i = 0;
        for(int j=1; j<n; j++) {
        	if(nums[j] != nums[i]) {
        		i++;
        		nums[i] = nums[j];
        	}
        }

        return i+1;
    }
};