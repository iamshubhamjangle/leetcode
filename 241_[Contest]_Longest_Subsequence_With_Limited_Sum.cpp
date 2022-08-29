/*
[Contest]_Longest_Subsequence_With_Limited_Sum.cpp

You are given an integer array nums of length n, and an integer array queries of length m.
Return an array answer of length m where answer[i] is the maximum size of a subsequence 
that you can take from nums such that the sum of its elements is less than or equal to queries[i].

Input: nums = [4,5,2,1], queries = [3,10,21]
Output: [2,3,4]

Input: nums = [2,3,4,5], queries = [1]
Output: [0]

https://leetcode.com/contest/weekly-contest-308/problems/longest-subsequence-with-limited-sum/
*/

#include <bits/stdc++.h>
using namespace std;

/*
0 0 1
2
*/

class Solution {
public:
	int maxSizeSumSubsequenceOfSumK(int k, int sum, vector<int> &nums, int n) {
		if(k == 0) {
			if(nums[k] < )
		}

		// take
		int take = 1 + maxSizeSumSubsequenceOfSumK(k-1, sum + nums[k], nums, n);
		// notake
		int notake = 0 + maxSizeSumSubsequenceOfSumK(k-1, sum, nums, n);

		return max(take, notake);
	}

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
 		vector<int> ans;
 		int n = nums.size();
 		int m = queries.size();

 		for(int i=0; i<m; i++) {
 			int x = maxSizeSumSubsequenceOfSumK(m, 0, nums, n-1);	// max size of subseq of sum k
 			ans.push_back(x);
 		}

 		return ans;
    }
};

void print(vector<int> &v) {
	for(auto i: v) cout << i << ", ";
	cout << endl;
}

int main(){
	vector<int> nums, queries, ans;
	Solution s;

	nums = {4,5,2,1};
	queries = {3,10,21};
	ans = s.answerQueries(nums, queries);
	print(ans);

	nums = {2,3,4,5};
	queries = {1};
	ans = s.answerQueries(nums, queries);
	print(ans);
}
