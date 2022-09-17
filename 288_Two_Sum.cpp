/*
Two_Sum.cpp

Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.

Input: nums = [2,7,11,15], target = 9
Output: [0,1]

Input: nums = [3,3], target = 6
Output: [0,1]

https://leetcode.com/problems/two-sum/
*/

class Solution {
public:
	// 1. Bruteforce. TC: O(N*N) SC: O(1)
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     vector<int> ans;
        
    //     for(int i=0; i<n; i++) {
    //         for(int j=i+1; j<n; j++) {
    //             if(nums[i] + nums[j] == target) {
    //                 ans.push_back(i);
    //                 ans.push_back(j);
    //                 break;
    //             }
    //         }
    //     }
        
    //     return ans;
    // }

    
	// 2. Using HashMap. TC: O(N) SC: O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
    	int n = nums.size();
    	unordered_map<int, int> um;	// num = index

    	for(int i=0; i<n; i++) {
    		if(um.find(target - nums[i]) != um.end()) {	// is the target - curr exist?
    			return {um[target - nums[i]], i};		// return index, curr index
    		}
    		um[nums[i]] = i;	// add curr to map with index
    	}

    	return {};
    }
};