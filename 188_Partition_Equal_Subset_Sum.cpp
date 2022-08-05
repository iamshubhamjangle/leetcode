/*
Partition_Equal_Subset_Sum.cpp

Input:
2
6
3 1 1 2 2 1
5
5 6 5 11 6

Output:
true
false

https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980
- Same as subset sum of k. Just find k/2 for even sum.
- Space Optimisation. TC: O(N*K) SC: O(K)

*/
#include <bits/stdc++.h>
using namespace std;


// Space Optimisation. TC: O(N*K) SC: O(K)
bool subsetSumToK(vector<int> &arr, int n, int k) {
	// 1. declare dp
	vector<bool> prev(k+1, 0) ,cur(k+1, 0);

	// 2. Declare base cases
	prev[0] = cur[0] = true;
	if(arr[0] <= k) prev[arr[0]] = true;

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

	return prev[k];
}

bool canPartition(vector<int> &arr, int n) {
	int sum = accumulate(arr.begin(), arr.end(), 0);
	if(sum%2 != 0) return false;
	return subsetSumToK(arr, n, sum/2);
}

int main(){
	int n; vector<int> arr = {};

	n = 6;
	arr = {3,1,1,2,2,1};
	cout << canPartition(arr, n) << endl;
	
	n = 5;
	arr = {5,6,5,11,6};
	cout << canPartition(arr, n) << endl;
}
