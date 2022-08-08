/*
Partitions_With_Given_Difference.cpp

Input:
2
4 3
5 2 6 4
4 0
1 1 1 1

Output:
1
6

https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628

*/

#include <bits/stdc++.h>
using namespace std;

int mod = (int) (1e9+7);

// Space Optimisation. TC: O(N*target) SC: O(target)
int findWays(vector<int> &num, int sum) {
	int n = num.size();
	vector<int> prev(sum+1, 0), curr(sum+1, 0);

	if(num[0] == 0) prev[0] = 2;	// if(ind == 0) { if(sum == 0 && num[ind] == 0) return 2; }
	else prev[0] = 1;				// if(ind == 0) { sum == 0 || num[ind] == sum } return 1; }

	if(num[0] != 0 && num[0] <= sum) prev[num[0]] = 1;

	for(int ind=1; ind<n; ind++) {
		for(int j=0; j<=sum; j++) {
			int notake = prev[j];
			int take = 0;
			if(num[ind] <= j) take = prev[j - num[ind]];

			curr[j] = (take + notake) % mod;
		}
		prev = curr;
	}

	return prev[sum];
}


// // Tabulation. Top-Down - 0 to n-1. TC: O(N*target) SC: O(N*target)
// int findWays(vector<int> &num, int sum) {
// 	int n = num.size();
// 	vector<vector<int>> dp(n, vector<int> (sum+1, 0));

// 	if(num[0] == 0) dp[0][0] = 2;	// if(ind == 0) { if(sum == 0 && num[ind] == 0) return 2; }
// 	else dp[0][0] = 1;				// if(ind == 0) { sum == 0 || num[ind] == sum } return 1; }

// 	if(num[0] != 0 && num[0] <= sum) dp[0][num[0]] = 1;

// 	for(int ind=1; ind<n; ind++) {
// 		for(int j=0; j<=sum; j++) {
// 			int notake = dp[ind-1][j];
// 			int take = 0;
// 			if(num[ind] <= j) take = dp[ind-1][j - num[ind]];

// 			dp[ind][j] = (take + notake) % mod;
// 		}
// 	}

// 	return dp[n-1][sum];
// }


/**
* constrains 0 <= num[i] - numbers are positive integer only 
* Hence as per the formula we derived s2 = (totalSum - d) / 2
* 1. totalSum - d >= 0 (positive integers)
* 2. totalSum - d == EVEN (as the division show result in int only)
*/
int countPartitions(int n, int d, vector<int> &arr) {
	int totalSum = accumulate(arr.begin(), arr.end(), 0);

	if(totalSum - d < 0 || (totalSum - d) % 2) return false;
	return findWays(arr, (totalSum - d) / 2);
}


int main(){
	int t;
	cin >> t;		//input no. of test cases
	while(t--){
		int n, d; cin >> n >> d;
		vector<int> arr;
		for(int i=0; i<n; i++) {
			int x; cin >> x;
			arr.push_back(x);
		}
		cout << countPartitions(n, d, arr) << endl;	//run this 't' times
	}
}




