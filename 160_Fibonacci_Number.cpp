/*
Fibonacci_Number.cpp

Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

https://leetcode.com/problems/fibonacci-number/
1. Recursive TC: O(2^N) SC: O(1)
2. Memoisation TC: O(N) SC: O(N)
3. Tabulation (Top-down) TC: O(N) SC: O(N)
4. Space Optimization. TC: O(N) SC: O(1)


*/
#include <bits/stdc++.h>
using namespace std;

    // 1. Recursive TC: O(2^N) SC: O(1)
    int fib(int n) {
        if(n <= 1) 
            return n;

        return fib(n-1) + fib(n-2);
    }

    // Overlapping subproblems
    // 2. Memoisation TC: O(N) SC: O(N)
    int helper(int n, vector<int> &dp) {
        if(n <= 1) 
            return n;

        if(dp[n] != -1) 
            return dp[n];

        return dp[n] = helper(n-1, dp) + helper(n-2, dp);
    }

    int fib(int n) {
        vector<int> dp(n+1, -1);	// size n+1 and init with -1
        return helper(n, dp);
    }

    // 3. Tabulation (Top-down) TC: O(N) SC: O(N)
    int fib(int n) {
        if(n<=1) return n;
        
        vector<int> dp(n+1, -1);	// size n+1 and init with -1
        dp[0] = 0;
        dp[1] = 1;

        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
    

    // 4. Space Optimization. TC: O(N) SC: O(1)
    int fib(int n) {
        if(n <= 1) return n;
        
        int prev0 = 0;
        int prev1 = 1;

        for(int i=2; i<=n; i++) {
            int cur = prev0 + prev1;
            prev0 = prev1;
            prev1 = cur;
        }

        return prev1;
    }

int main(){
	int t;
	cin >> t;		//input no. of test cases
	while(t--){
		int n;
		cin >> n;
		cout << fib(n);
		cout << endl;
	}
}
