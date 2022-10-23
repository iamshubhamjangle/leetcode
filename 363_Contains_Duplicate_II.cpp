/*
Contains_Duplicate_II.cpp

Given an integer array nums and an integer k, return true if there are two distinct 
indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
 
https://leetcode.com/problems/contains-duplicate-ii/
*/

class Solution {
public:
	// bruteforce. TC: O(N*N) SC: O(1)
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    	int n = nums.size();
        for(int i=0; i<n; i++) {
        	for(int j=i+1; j<n; j++) {
        		if(nums[i] == nums[j] && abs(i-j) <= k) return true;
        	}
        }
        return false;
    }

    
    // Using maps to keep track of last visited num and its index. TC: O(N) SC: O(N) 
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> um; // number, index

		for(int i=0; i<n; i++) {
			if(um.find(nums[i]) != um.end()) {
				if(abs(i - um[nums[i]]) <= k) return true;
			}
			um[nums[i]] = i;
		}

		return false;
	}
};