/*
Best_Time_to_Buy_and_Sell_Stock_with_Cooldown.cpp

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
*/

#include <bits/stdc++.h>
using namespace std;


// Recursion.
// class Solution {
// public:
// 	int solve(int i, int canBuy, vector<int>&prices) {
// 		if(i >= prices.size()) {
// 			return 0;
// 		}

// 		int profit = 0;		// profit = sell - buy
// 		if(canBuy) {
// 			int buy 	=-prices[i] + solve(i+1, 0, prices);
// 			int notBuy 	= 0 		+ solve(i+1, 1, prices);
// 			profit 		= max(buy, notBuy);
// 		} else {
// 			int sell 	= prices[i] + solve(i+2, 1, prices);
// 			int notSell = 0 		+ solve(i+1, 0, prices);
// 			profit 		= max(sell, notSell);
// 		}

// 		return profit;
// 	}
	
	
//     int maxProfit(vector<int>& prices) {
// 		int n = prices.size();
// 		int canBuy = 1;	// initially we can buy
// 		// lets start with last position
// 		return solve(0, canBuy, prices);
//     }
// };


// Memoisation
// class Solution {
// public:
// 	int solve(int i, int canBuy, vector<int>&prices, vector<vector<int>> &dp) {
// 		if(i >= prices.size()) {
// 			return 0;
// 		}

// 		if(dp[i][canBuy] != -1) return dp[i][canBuy];

// 		int profit = 0;		// profit = sell - buy
// 		if(canBuy) {
// 			int buy 	=-prices[i] + solve(i+1, 0, prices, dp);
// 			int notBuy 	= 0 		+ solve(i+1, 1, prices, dp);
// 			profit 		= max(buy, notBuy);
// 		} else {
// 			int sell 	= prices[i] + solve(i+2, 1, prices, dp);
// 			int notSell = 0 		+ solve(i+1, 0, prices, dp);
// 			profit 		= max(sell, notSell);
// 		}

// 		return dp[i][canBuy] = profit;
// 	}
	
	
//     int maxProfit(vector<int>& prices) {
// 		int n = prices.size();
// 		int canBuy = 1;	// initially we can buy
// 		vector<vector<int>> dp(n, vector<int>(2, -1));
// 		return solve(0, canBuy, prices, dp);
//     }
// };


int main(){
	Solution s;

	vector<int> prices;

	prices = {1,2,3,0,2};
	cout << s.maxProfit(prices) << endl;	// 3
	
	prices = {1};
	cout << s.maxProfit(prices) << endl;	// 0

	prices = {1,2};
	cout << s.maxProfit(prices) << endl;	// 1
}