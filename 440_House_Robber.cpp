/*
House_Robber.cpp

https://leetcode.com/problems/house-robber/description/
*/

class Solution {
public:
	// 1. Brute. TC: O(2^n) SC: O(1) ASC: O(N)
	// front to back approach 0 -> n-1
    int solve(int i, vector<int> &A) {
        if(i >= A.size()) return 0;

        int take   = A[i] + solve(i+2, A);
        int notake = 0 + solve(i+1, A);

        return max(take, notake);
    }

    int rob(vector<int>& A) {
        return solve(0, A);
    }


	// 1. Brute. TC: O(2^n) SC: O(1) ASC: O(N)
	// back to front approach n-1 to 0
    int solve(int i, vector<int> &A) {
        if(i == 0) return A[i];
        if(i < 0) return 0;

        int take   = A[i] + solve(i-2, A);
        int notake = 0 + solve(i-1, A);

        return max(take, notake);
    }

    int rob(vector<int>& A) {
    	int n = A.size();
        return solve(n-1, A);
    }


	// 2. Memoisation. TC: O(N^2) SC: O(N) ASC: O(N)
    int solve(int i, vector<int> &A, vector<int> &dp) {
        if(i == 0) return A[i];
        if(i < 0) return 0;

        if(dp[i] != -1) return dp[i];

        int take   = A[i] + solve(i-2, A, dp);
        int notake = 0 + solve(i-1, A, dp);

        return dp[i] = max(take, notake);
    }

    int rob(vector<int>& A) {
    	int n = A.size();
    	vector<int> dp(n+1, -1);
        return solve(n-1, A, dp);
    }



    // 3. Tabulation. TC: O(N) SC: O(N)
    int rob(vector<int>& A) {
    	int n = A.size();
    	vector<int> dp(n+1, 0);

    	dp[0] = A[0];

    	for(int i=1; i<n; i++) {
			int take = A[i];
			if(i>=2) take += dp[i-2];
			int notake = dp[i-1];

			dp[i] = max(take, notake);
    	}

        return dp[n-1];
    }


    // 4. Space optimisation. TC: O(N) SC: O(1)
    int rob(vector<int>& A) {
    	int n = A.size();
    	int prev0 = A[0];
    	int prev1 = 0;

    	for(int i=1; i<n; i++) {
			int take = A[i];
			if(i>=2) take += prev1;
			int notake = prev0;

			int curr = max(take, notake);
			prev1 = prev0;
			prev0 = curr;
    	}

        return prev0;
    }
};