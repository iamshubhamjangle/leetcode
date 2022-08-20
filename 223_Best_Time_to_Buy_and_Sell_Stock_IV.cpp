/*
Best_Time_to_Buy_and_Sell_Stock_IV.cpp 
(At most k transaction allowed)

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Input: k = 2, prices = [2,4,1]
Output: 2

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Recursion TC: O(2^n) exponential, SC: O(1), ASC: O(N)
	int solve(int ind, int canBuy, int cap, vector<int> &prices, int n) {
		if(ind == n || cap == 0)
			return 0;

		if(canBuy == 1) {
			int buy = -prices[ind] + solve(ind+1, 0, cap, prices, n);
			int notBuy = 0 + solve(ind+1, 1, cap, prices, n);
			return max(buy, notBuy);
		} else {
			int sell = prices[ind] + solve(ind+1, 1, cap-1, prices, n);
			int notSell = 0 + solve(ind+1, 0, cap, prices, n);
			return max(sell, notSell);
		}
	}

    int maxProfit(int k, vector<int>& prices) {
    	int n = prices.size();
		return solve(0, 1, k, prices, n);
    }



	// Memoisation TC: O(n*2*k), SC: O(n*2*k), ASC: O(N)
	int solve(int ind, int canBuy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>> &dp) {
		if(ind == n || cap == 0)
			return 0;

		if(dp[ind][canBuy][cap] != -1)
			return dp[ind][canBuy][cap];

		int profit = 0;

		if(canBuy == 1) {
			int buy = -prices[ind] + solve(ind+1, 0, cap, prices, n, dp);
			int notBuy = 0 + solve(ind+1, 1, cap, prices, n, dp);
			profit = max(buy, notBuy);
		} else {
			int sell = prices[ind] + solve(ind+1, 1, cap-1, prices, n, dp);
			int notSell = 0 + solve(ind+1, 0, cap, prices, n, dp);
			profit = max(sell, notSell);
		}

		return dp[ind][canBuy][cap] = profit;
	}

    int maxProfit(int k, vector<int>& prices) {
    	int n = prices.size();
    	vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
		return solve(0, 1, k, prices, n, dp);
    }



	// Tabulation TC: O(n*2*k), SC: O(n*2*k)
    int maxProfit(int k, vector<int>& prices) {
    	int n = prices.size();
    	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

    	// base condition. Not required to be initialised.
		for(int ind=0; ind<n; ind++)
    		for(int canBuy=0; canBuy<=1; canBuy++)
    			dp[ind][canBuy][0] = 0;
		for(int canBuy=0; canBuy<=1; canBuy++)
    		for(int cap=0; cap<=k; cap++)
    			dp[n][canBuy][cap] = 0;

    	for(int ind=n-1; ind>=0; ind--) {
    		for(int canBuy=0; canBuy<=1; canBuy++) {
    			for(int cap=1; cap<=k; cap++) {
			    	int profit = 0;

					if(canBuy == 1) {
						int buy = -prices[ind] + dp[ind+1][0][cap];
						int notBuy = 0 + dp[ind+1][1][cap];
						profit = max(buy, notBuy);
					} else {
						int sell = prices[ind] + dp[ind+1][1][cap-1];
						int notSell = 0 + dp[ind+1][0][cap];
						profit = max(sell, notSell);
					}

					dp[ind][canBuy][cap] = profit;
    			}
    		}
    	}

		return dp[0][1][k];
    }



	// Space Optimisation TC: O(n*2*k), SC: O(2*k)
    int maxProfit(int k, vector<int>& prices) {
    	int n = prices.size();
    	vector<vector<int>> ahead(2, vector<int>(k+1, 0));
    	vector<vector<int>> curr(2, vector<int>(k+1, 0));


    	for(int ind=n-1; ind>=0; ind--) {
    		for(int canBuy=0; canBuy<=1; canBuy++) {
    			for(int cap=1; cap<=k; cap++) {
			    	int profit = 0;

					if(canBuy == 1) {
						int buy = -prices[ind] + ahead[0][cap];
						int notBuy = 0 + ahead[1][cap];
						profit = max(buy, notBuy);
					} else {
						int sell = prices[ind] + ahead[1][cap-1];
						int notSell = 0 + ahead[0][cap];
						profit = max(sell, notSell);
					}

					curr[canBuy][cap] = profit;
    			}
    		}
    		ahead = curr;
    	}

		return curr[1][k];
    }


	Method 2: Using n*canBuy method
	// Recursion. TC: O(exponential) SC: O(1) ASC: O(N)
	int solve(int ind, int cap, vector<int> &prices, int k, int n) {
		if(ind == n || cap == k) {
			return 0;
		}

		int profit = 0;

		if(cap % 2 == 0) {
			int buy 	= -prices[ind] + solve(ind+1, cap+1, prices, k, n);
			int notBuy  = 0 + solve(ind+1, cap, prices, k, n);
			profit = max(buy, notBuy);
		} else {
			int sell 	= prices[ind] + solve(ind+1, cap+1, prices, k, n);
			int notSell = 0 + solve(ind+1, cap, prices, k, n);
			profit = max(sell, notSell);
		}

		return profit;
	}


    int maxProfit(int k, vector<int>& prices) {
    	int n = prices.size();
    	return solve(0, 0, prices, k*2, n);
	}


	// Memoization. TC: O(N*K*2) SC: O(N*K*2) ASC: O(N)
	int solve(int ind, int cap, vector<int> &prices, int k, int n, vector<vector<int>> &dp) {
		if(ind == n || cap == k) {
			return 0;
		}

		if(dp[ind][cap] != -1)
			return dp[ind][cap];

		int profit = 0;

		if(cap % 2 == 0) {
			int buy 	= -prices[ind] + solve(ind+1, cap+1, prices, k, n, dp);
			int notBuy  = 0 + solve(ind+1, cap, prices, k, n, dp);
			profit = max(buy, notBuy);
		} else {
			int sell 	= prices[ind] + solve(ind+1, cap+1, prices, k, n, dp);
			int notSell = 0 + solve(ind+1, cap, prices, k, n, dp);
			profit = max(sell, notSell);
		}

		return dp[ind][cap] = profit;
	}

    int maxProfit(int k, vector<int>& prices) {
    	int n = prices.size();
    	vector<vector<int>> dp(n, vector<int>(2*k, -1));
    	return solve(0, 0, prices, k*2, n, dp);
	}


	// Tabulation. TC: O(N*2*k) SC: O(N*2*k)
    int maxProfit(int k, vector<int>& prices) {
    	int n = prices.size();
    	vector<vector<int>> dp(n+1, vector<int>(2*k + 1, 0));

    	for(int ind=n-1; ind>=0; ind--) {
    		for(int cap=2*k-1; cap>=0; cap--) {
				int profit = 0;

				if(cap % 2 == 0) {
					int buy 	= -prices[ind] + dp[ind+1][cap+1];
					int notBuy  = 0 + dp[ind+1][cap];
					profit = max(buy, notBuy);
				} else {
					int sell 	= prices[ind] + dp[ind+1][cap+1];
					int notSell = 0 + dp[ind+1][cap];
					profit = max(sell, notSell);
				}

				dp[ind][cap] = profit;
    		}
    	}

    	return dp[0][0];
	}



	// Space Optimisation. TC: O(N*2*k) SC: O(2*k)
    int maxProfit(int k, vector<int>& prices) {
    	int n = prices.size();
    	vector<int> ahead(2*k + 1, 0);
    	vector<int> curr(2*k + 1, 0); 

    	for(int ind=n-1; ind>=0; ind--) {
    		for(int cap=2*k-1; cap>=0; cap--) {
				int profit = 0;

				if(cap % 2 == 0) {
					int buy 	= -prices[ind] + ahead[cap+1];
					int notBuy  = 0 + ahead[cap];
					profit = max(buy, notBuy);
				} else {
					int sell 	= prices[ind] + ahead[cap+1];
					int notSell = 0 + ahead[cap];
					profit = max(sell, notSell);
				}

				curr[cap] = profit;
    		}
    		ahead = curr;
    	}

    	return ahead[0];
	}
};

int main(){
	Solution s;
	vector<int> prices;

	prices = {2,4,1};
	cout << s.maxProfit(2, prices) << endl;
	prices = {3,2,6,5,0,3};
	cout << s.maxProfit(2, prices) << endl;	
}
