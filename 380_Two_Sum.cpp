/*
Two_Sum.cpp

Input: nums = [2,7,11,15], target = 9
Output: [0,1]

https://leetcode.com/problems/two-sum/submissions/
*/


class Solution {
public:
    // Brute: TC: O(N*N) SC: O(1)
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(nums[i] + nums[j] == target) return {i,j};
            }
        }
        return {};
    }
    

    
    // Map. TC: O(N) SC: O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
    	unordered_map<int, int> um; 		// num, index
        int n = nums.size();
        
    	for(int i=0; i<n; i++) {
    		if(um.find(target - nums[i]) != um.end()) {
    			return {um[target - nums[i]], i};
    		}
    		um[nums[i]] = i;
    	}
    	return {};
    }
};