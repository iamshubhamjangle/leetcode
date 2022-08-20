/*
Best_Time_to_Buy_and_Sell_Stock_with_Cooldown.cpp

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Input: prices = [1,2,3,0,2]
Output: 3

Input: prices = [1]
Output: 0

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// // Recursion. TC: O(2^n) SC: O(1) ASC: O(N)
 //    int solve(int ind, int canBuy, int n, vector<int> &prices) {
 //    	// When we have exhaused the days
 //    	if(ind >= n) {		//-- >=
 //    		return 0;
 //    	}

 //    	int profit;

 //    	if(canBuy) {
 //    		int buy 	= solve(ind+1, 0, n, prices) - prices[ind];	// if we buy
 //    		int notBuy 	= solve(ind+1, 1, n, prices) - 0;			// if we not buy
 //    		profit = max(buy, notBuy);
 //    	} 
 //    	else {	// if we cannot buy, we have to sell 
 //    		int sell 	= solve(ind+2, 1, n, prices) + prices[ind];	// sell
 //    		int notSell = solve(ind+1, 0, n, prices) + 0;			// not sell
 //    		profit = max(sell, notSell);
 //    	}

 //    	return profit;
 //    }

 //    int maxProfit(vector<int> &prices) {
 //    	int n = prices.size();
 //    	// int ind = 0;		// ind start from 0
 //    	// int canBuy = 1;		// initially we can buy
 //    	return solve(0, 1, n, prices);
 //    }



    // // 2. Memoisation. TC: O(n*2) SC: O(n*2) ASC: O(N)
    // int solve(int ind, int canBuy, int n, vector<int> &prices, vector<vector<int>> &dp) {
    // 	// When we have exhaused the days
    // 	if(ind >= n) {		//-- >=
    // 		return 0;
    // 	}

    // 	if(dp[ind][canBuy] != -1)
    // 		return dp[ind][canBuy];

    // 	int profit;

    // 	if(canBuy) {
    // 		int buy 	= solve(ind+1, 0, n, prices, dp) - prices[ind];	// if we buy
    // 		int notBuy 	= solve(ind+1, 1, n, prices, dp) - 0;			// if we not buy
    // 		profit = max(buy, notBuy);
    // 	} 
    // 	else {	// if we cannot buy, we have to sell 
    // 		int sell 	= solve(ind+2, 1, n, prices, dp) + prices[ind];	// sell
    // 		int notSell = solve(ind+1, 0, n, prices, dp) + 0;			// not sell
    // 		profit = max(sell, notSell);
    // 	}

    // 	return dp[ind][canBuy] = profit;
    // }

    // int maxProfit(vector<int> &prices) {
    // 	int n = prices.size();
    //  // int ind = 0;		// ind start from 0
    // 	// int canBuy = 1;		// initially we can buy
    // 	vector<vector<int>> dp(n, vector<int>(2, -1));
    // 	return solve(0, 1, n, prices, dp);
    // }



	// // Tabulation  TC: O(n*2) SC: O(n*2)
 //    int maxProfit(vector<int> &prices) {
 //    	int n = prices.size();
 //    	vector<vector<int>> dp(n+2, vector<int>(2, 0));

 //    	// if (ind == n) return 0; for ind n and any boolean put it as 0;
 //    	dp[n][0] = 0;
 //    	dp[n][1] = 0;

 //    	for(int ind=n-1; ind>=0; ind--) {
 //    		for(int canBuy=0; canBuy<=1; canBuy++) {
	// 	    	int profit = 0;

	// 	    	if(canBuy) {
	// 	    		int buy 	= dp[ind+1][0] - prices[ind];
	// 	    		int notBuy 	= dp[ind+1][1] - 0;
	// 	    		profit = max(buy, notBuy);
	// 	    	} 
	// 	    	else {
	// 	    		int sell 	= dp[ind+2][1] + prices[ind];
	// 	    		int notSell = dp[ind+1][0] + 0;
	// 	    		profit = max(sell, notSell);
	// 	    	}

	// 	    	dp[ind][canBuy] = profit;	
 //    		}
 //    	}
 //    	return dp[0][1];
 //    }

      


	/**
	 * space optimisation can be tricky as we have to manage 3 rows.
	 * Let try to avoid the 2nd loop as its only does 2 things. canBuy = 0, canBuy = 1;
	**/
	// Tabulation  TC: O(n*2) SC: O(n*2)
       int maxProfit(vector<int> &prices) {
    	int n = prices.size();
    	vector<vector<int>> dp(n+2, vector<int>(2, 0));

    	// if (ind == n) return 0; for ind n and any boolean put it as 0;
    	dp[n][0] = 0;
    	dp[n][1] = 0;

    	for(int ind=n-1; ind>=0; ind--) {
			int buy 	= dp[ind+1][0] - prices[ind];
			int notBuy 	= dp[ind+1][1] - 0;
			dp[ind][1] = max(buy, notBuy);

			int sell 	= dp[ind+2][1] + prices[ind];
			int notSell = dp[ind+1][0] + 0;
			dp[ind][0] = max(sell, notSell);
    	}
    	return dp[0][1];
    }
};

int main(){
	Solution s;
	vector<int> prices;

	prices = {1,2,3,0,2};
	cout << s.maxProfit(prices) << endl;	// 3

	prices = {1};
	cout << s.maxProfit(prices) << endl;	// 0
}

