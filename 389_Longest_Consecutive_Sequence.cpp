/*
Longest_Consecutive_Sequence.cpp

Input: nums = [-1, 100,4,200,1,3,2]
Output: 4

https://leetcode.com/problems/longest-consecutive-sequence/
*/
#include <bits/stdc++.h>
using namespace std;


// Brute. TC: O(NlogN) SC: O(1)
class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {
    	int n = nums.size();
    	if(n == 0) return 0;
    	if(n == 1) return 1;

		sort(nums.begin(), nums.end());

		int ans = 1;
		int count = 1;
		for(int i=1; i<n; i++) {
			if(nums[i] == nums[i-1])
				continue;
			if(nums[i] == nums[i-1] + 1)
				count++;
			else 
				count = 1;
			ans = max(ans, count);
		}

		return ans;
    }
};


// Optimal: TC: O(N) SC: O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
        unordered_set<int> us(begin(nums), end(nums));

        for(int i=0; i<n; i++) {
        	if(us.find(nums[i] - 1) == us.end()) {
        		// prev doesnt exist
        		int curr = nums[i];
        		int length = 0;
        		while(us.find(curr) != us.end()) {
        			curr++; 
        			length++;
        		}
        		maxLength = max(length, maxLength);
        	}
        }

        return maxLength;
    }
};


int main() {
	Solution s;
	vector<int> nums;
	nums = {9,1,4,7,3,-1,0,5,8,-1,6};
	cout << s.longestConsecutive(nums) << endl;	// 7
	
	nums = {100,4,200,1,3,2};
	cout << s.longestConsecutive(nums) << endl;	// 4

	nums = {1,2,0,1};
	cout << s.longestConsecutive(nums) << endl;	// 3
}