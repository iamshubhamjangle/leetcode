/*
Longest_Consecutive_Sequence.cpp

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Input: nums = [100,4,200,1,3,2]
Output: 4

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

https://leetcode.com/problems/longest-consecutive-sequence/
*/

// 1. Bruteforce. Sort -> Iterate. TC: O(NlogN) SC: O(1)
// 2. Optimised. UnorderedSet -> Iterate (find min and count) TC: O(3N) SC: O(N)

class Solution {
public:
	// 2. Optimised. UnorderedSet -> Iterate (find min and count) TC: O(3N) SC: O(N)
    int longestConsecutive(vector<int>& nums) {
		unordered_set<int> us(nums.begin(), nums.end());	// this is faster
		// for(auto i: nums) us.insert(i);

    	int maxCount = 0;
		for(auto i: nums) {
			if(us.find(i-1) == us.end()) {
				int count = 0;
				while(us.find(i) != us.end()){
					count++;
					i++;
				}
				maxCount = max(count, maxCount);
			}
		}

		return maxCount;
    }
};