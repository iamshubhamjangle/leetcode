/*
Combination_Sum.cpp

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Input: candidates = [2], target = 1
Output: []

https://leetcode.com/problems/combination-sum/
Method: TC: 2^n * k,	SC: k*n 
*/


class Solution {
public:
    vector<vector<int>> ans;

  	void solve(int i, vector<int> &arr, vector<int> &temp, int target) {
  		if(i == arr.size()) {
	  		if(target == 0) {
  				ans.push_back(temp);
  			}
  			return;
  		}

  		if(arr[i] <= target) {
	  		temp.push_back(arr[i]);
	  		solve(i, arr, temp, target - arr[i]);	// pick (i will remain same as elements can repeat)
	  		temp.pop_back();
  		}

  		solve(i+1, arr, temp, target);		// nopick
  	}

    vector<vector<int>> combinationSum(vector<int> &arr, int target) {
        ans.clear();
        vector<int> temp;
        solve(0, arr, temp, target);
		sort(ans.begin(), ans.end());
        return ans;
    }
};