/*
Remove_Duplicates_from_Sorted_Array.cpp

Input: nums = [1,1,2]
Output: 2

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5

https://leetcode.com/problems/remove-duplicates-from-sorted-array/
	- Using Second Vector. TC: O(2N) SC: O(N)
    - Two Pointer. TC: O(N) SC: O(1)
*/

class Solution {
public:
	// TC: O(2N) SC: O(N)
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;

        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i=1; i<n; i++) {
        	if(nums[i] != nums[i-1])
        		ans.push_back(nums[i]);
        }

        for(int i=0; i<ans.size(); i++) {
        	nums[i] = ans[i];
        }

        return ans.size();
    }


    // TC: O(N) SC: O(1)
    int removeDuplicates(vector<int>& nums) {
    	int n = nums.size();
    	if(n <= 1) return n;

    	int p = 1;

    	for(int i=1; i<n; i++) {
    		if(nums[i] != nums[i-1]) {
    			nums[p++] = nums[i];
    		}
    	}

    	return p;
    }
};
