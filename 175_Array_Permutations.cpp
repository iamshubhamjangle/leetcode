/*
Array_Permutations.cpp

https://leetcode.com/problems/permutations/

1. Recusion. Use DS and map to handle permutation.
	- TC: O(n! * n) 	// n! for permutation. n or loop 0 to n-1
	- SC: O(n) + O(n)	// map, and ds
	- Auxilary SC: O(n) // depth of recursion

2. Recusion. Using swapping technique to get permutation.
	- TC: O(n! * n)		// n! for permutation. n for loop 0 to n-1
	- SC: O(1)			// O(n!) for returning the ans
	- Auxi. SC: O(n)	// depth of recursion
*/

// 1
void findPermute(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, unordered_map<int, bool> &um) {
    if(ds.size() == nums.size()) {
        ans.push_back(ds);
        return;
    }
    for(int i=0; i<nums.size(); i++) {
        if(um[nums[i]]) continue;
        ds.push_back(nums[i]);
        um[nums[i]] = true;
        findPermute(nums, ds, ans, um);
        um[nums[i]] = false;
        ds.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    unordered_map<int, bool> um;
    findPermute(nums, ds, ans, um);
    return ans;
}


// 2
void findPermute(int idx, vector<int> &nums, vector<vector<int>> &ans) {
	if(idx == nums.size()) {
		ans.push_back(nums);
		return;
	}

	for(int i=idx; i<nums.size(); i++) {
		swap(nums[idx], nums[i]);
		findPermute(idx+1, nums, ans);
		swap(nums[idx], nums[i]);
	}
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    findPermute(0, nums, ans);
    return ans;
}

