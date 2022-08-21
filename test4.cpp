#include <bits/stdc++.h>
using namespace std;



// Input: nums = [2,4,-2], k = 5
// Output: 2

// Input: nums = [1,-2,3,4,-10,12], k = 16
// Output: 10

class Solution {
public:
	// Recursion. TC: O(2^n + nlogn) SC: O(1) ASC: O(N)
	void solve(int ind, long long sum, vector<int> &nums, vector<long long> &ans, int n, int k) {
		if(ind < 0) {
			ans.push_back(sum);
			return;
		}

		// take
		solve(ind-1, sum + nums[ind], nums, ans, n, k);
		solve(ind-1, sum, nums, ans, n, k);
	}

    long long kSum(vector<int>& nums, int k) {
		int n = nums.size();
		vector<long long> ans;

		solve(n-1, 0, nums, ans, n, k);
		sort(ans.rbegin(), ans.rend());

		return ans[k-1];
    }
};

int main(){
	Solution s;
	vector<int> nums;

	nums = {2,4,-2};
	cout << s.kSum(nums, 5) << endl;	// Output: 2 
	nums = {1,-2,3,4,-10,12};
	cout << s.kSum(nums, 16) << endl;	// Output: 10
	nums = {-487322177,-656480132,850198596,-291605661,-272668395,110865952,-162529283,-145886963,202657909,125667049,-282090943,120877054,-85849348,-482630078,-802177895,-574862206,374637017,804297842};
	cout << s.kSum(nums, 1707) << endl;	// Output:
}