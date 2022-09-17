/*
4Sum.cpp

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

https://leetcode.com/problems/4sum/
*/

class Solution {
public:
	// Bruteforce. Sort. 3 loops + binary search last element. TC: O(N^3 logN + NlogN).
	// time complexity. loop + insert into set + sorting

	// Optimal. two loops and two pointer. TC: O(N^3) SC: O(1)
    vector<vector<int>> fourSum(vector<int>& nums, long long int target) {
        vector<vector<int>> res;

        if(nums.empty()) return res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++) {
        	for(int j=i+1; j<n; j++) {
        		long long int target2 = target - nums[j] - nums[i];
        		// two pointer to find other two nums;
        		// skip the duplicate while traversing
        		int front = j+1;
        		int back  = n-1;

        		while(front < back) {
        			long long int two_sum = nums[front] + nums[back];
        			if(two_sum < target2) {
        				front++;
        			} else if( two_sum > target2) {
        				back--;
        			} else {
        				vector<int> temp;
        				temp.push_back(nums[i]);
        				temp.push_back(nums[j]);
        				temp.push_back(nums[front]);
        				temp.push_back(nums[back]);
        				res.push_back(temp);

        				// skip duplicates at two pointer
        				while(front<back && nums[front] == temp[2]) front++;
        				while(front<back && nums[back] == temp[3]) back--;
        			}
        		}
        		while(j+1 < n && nums[j+1] == nums[j]) j++;
        	}
        	while(i+1 < n && nums[i+1] == nums[i]) i++;
        }
        return res;
    }
};

