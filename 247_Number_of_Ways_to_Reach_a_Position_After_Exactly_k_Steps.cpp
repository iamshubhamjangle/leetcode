/*
Number_of_Ways_to_Reach_a_Position_After_Exactly_k_Steps.cpp

Given a positive integer k, return the number of different ways to reach the 
position endPos starting from startPos, such that you perform exactly k steps. 
Since the answer may be very large, return it modulo 109 + 7.

Input: startPos = 1, endPos = 2, k = 3
Output: 3

Input: startPos = 2, endPos = 5, k = 10
Output: 0

https://leetcode.com/contest/weekly-contest-309/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// // Method 1: Recursion
	// int solve(int s, int e, int k) {
	// 	if(k == 0) {
	// 		return s == e;
	// 	}

	// 	int minus = solve(s-1, e, k-1);
	// 	int plus  = solve(s+1, e, k-1);
	// 	return minus + plus;
	// }

 //    int numberOfWays(int startPos, int endPos, int k) {
 //        return solve(startPos, endPos, k);
 //    }

	int dp[1000][1001] = {};
	int dfs(int d, int k) {
	    if (d >= k)
	        return d == k;
	    if (dp[d][k] == 0)
	        dp[d][k] = (1 + dfs(d + 1, k - 1) + dfs(d + (d ? -1 : 1), k - 1)) % 1000000007;
	    return dp[d][k] - 1;
	} 
	int numberOfWays(int startPos, int endPos, int k) {
	    return dfs(abs(startPos - endPos), k);
	}
};

int main(){
	Solution s;
	cout << s.numberOfWays(1,2,3) << endl;
	cout << s.numberOfWays(2,5,10) << endl;
}