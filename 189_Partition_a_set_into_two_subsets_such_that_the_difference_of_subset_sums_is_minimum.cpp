/*
Partition_a_set_into_two_subsets_such_that_the_difference_of_subset_sums_is_minimum.cpp

Input:
2
4
1 2 3 4
3
8 6 5

Output:
0
3

https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
- Tabulation - get whether subset is possible / not for each column(target)
- Space Optimisation. TC: O(2N) + O(N*K) SC: O(K)

*/


#include <bits/stdc++.h>
using namespace std;

// Space Optimisation. TC: O(2N) + O(N*K) SC: O(K)
int minSubsetSumDifference(vector<int>& arr, int n) {
	int totSum = accumulate(arr.begin(), arr.end(), 0);
	int k = totSum;

	// 1. declare dp
	vector<bool> prev(k+1, 0) ,cur(k+1, 0);

	// 2. Declare base cases
	prev[0] = cur[0] = true;
	prev[arr[0]] = true;

	// 3. for the recurrance. fill dp idx, target grid
	for(int ind = 1; ind<n; ind++) {
		for(int target = 1; target <= k; target++) {
			bool notTake = prev[target];
			bool take 	 = false;
			if(target >= arr[ind])							// take only if curr element is <= target or else sum will get negative
				take = prev[target - arr[ind]];

			cur[target] = take || notTake;
		}
		prev = cur;
	}

	int mini = 1e8;
	for(int s1 = 0; s1 <= totSum; s1++) {
		if(prev[s1] == true) {
			mini = min(mini, abs((totSum - s1) - s1));
		}
	}

	return mini;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> arr;
		for(int i=0; i<n; i++) {
			int x; cin >> x;
			arr.push_back(x);
		}
		cout << minSubsetSumDifference(arr, n) << endl;
	}
}

