/*
Subsets_II.cpp

https://leetcode.com/problems/subsets-ii/

1. Take-notake with set<>
	- 
2. Take-notake with avoiding duplicate.
	- TC: O(2^n * n) SC: O(2^N * K) Auxiliary Space: O(N)
	-	// 2^n for recursion, n for copying `
*/


// Method 2
void findSubsets(int idx, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans) {
	ans.push_back(ds);
	for(int i=idx; i<nums.size(); i++) {
		// if we are at 1st idx pick it as we dont consider its prev
		// if we are not at 1st and curr == prev dont pick it.
		if(i != idx && nums[i] == nums[i-1]) continue;
		ds.push_back(nums[i]);
		findSubsets(i+1, nums, ds, ans);
		ds.pop_back();
	}
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int>> ans;
	vector<int> ds;
	sort(nums.begin(), nums.end());
	findSubsets(0, nums, ds, ans);
	return ans;
}

