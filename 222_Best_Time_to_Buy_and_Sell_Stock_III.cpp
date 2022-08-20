/*
Best_Time_to_Buy_and_Sell_Stock_III.cpp

You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6

Input: prices = [1,2,3,4,5]
Output: 4

Input: prices = [7,6,4,3,1]
Output: 0

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// // 1. Recursion. TC: O(exponential) SC: O(N)
	// // cap will only reduce when one trans is complete (Buy - Sell cycle)
	// int solve(int ind, int canBuy, int cap, int n, vector<int> &prices) {
	// 	if(ind == n || cap == 0)
	// 		return 0;

	// 	if(canBuy == 1) {
	// 		int buy 	= -prices[ind] + solve(ind+1, 0, cap, n, prices);
	// 		int notBuy 	= 0 + solve(ind+1, 1, cap, n, prices); 
	// 		return max(buy, notBuy);
	// 	}
	// 	else {
	// 		int sell	= prices[ind] + solve(ind+1, 1, cap-1, n, prices);
	// 		int notSell	= 0 + solve(ind+1, 0, cap, n, prices);
	// 		return max(sell, notSell);
	// 	}
	// }

 //    int maxProfit(vector<int>& prices) {
 //    	int n = prices.size();
	// 	return solve(0, 1, 2, n, prices);	// index, canbuy ,capacity
 //    }



	// // 2. Memoization. TC: O(N*2*3) SC: O(N*2*3) ASC: O(N)
	// // cap will only reduce when one trans is complete (Buy - Sell cycle)
	// int solve(int ind, int canBuy, int cap, int n, vector<int> &prices, vector<vector<vector<int>>> &dp) {
	// 	if(ind == n || cap == 0)
	// 		return 0;

	// 	if(dp[ind][canBuy][cap] != -1)
	// 		return dp[ind][canBuy][cap];


	// 	if(canBuy == 1) {
	// 		int buy 	= -prices[ind] + solve(ind+1, 0, cap, n, prices, dp);
	// 		int notBuy 	= 0 + solve(ind+1, 1, cap, n, prices, dp);
	// 		return dp[ind][canBuy][cap] = max(buy, notBuy);
	// 	}
	// 	else {
	// 		int sell	= prices[ind] + solve(ind+1, 1, cap-1, n, prices, dp);
	// 		int notSell	= 0 + solve(ind+1, 0, cap, n, prices, dp);
	// 		return dp[ind][canBuy][cap] = max(sell, notSell);
	// 	}
	// }

 //    int maxProfit(vector<int>& prices) {
 //    	int n = prices.size();
 //    	vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
	// 	return solve(0, 1, 2, n, prices, dp);
 //    }



	// // 3. Tabulation. TC: O(N*2*3) SC: O(N*2*3) ASC: O(N)
 //    int maxProfit(vector<int>& prices) {
 //    	int n = prices.size();
 //    	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

 //    	for(int ind=n-1; ind>=0; ind--) {
 //    		for(int canBuy=0; canBuy<=1; canBuy++) {
 //    			for(int cap=1; cap<=2; cap++) {
	// 				if(canBuy == 1) {
	// 					int buy 	= -prices[ind] + dp[ind+1][0][cap];
	// 					int notBuy 	= 0 + dp[ind+1][1][cap];
	// 					dp[ind][canBuy][cap] = max(buy, notBuy);
	// 				}
	// 				else {
	// 					int sell	= prices[ind] + dp[ind+1][1][cap-1];
	// 					int notSell	= 0 + dp[ind+1][0][cap];
	// 					dp[ind][canBuy][cap] = max(sell, notSell);
	// 				}
 //    			}
 //    		}
 //    	}

	// 	return dp[0][1][2];
 //    }




	// 4. Space Optimize. TC: O(N*2*3) SC: O(2*3)
    int maxProfit(vector<int>& prices) {
    	int n = prices.size();
    	vector<vector<int>> prev(2, vector<int>(3, 0));
    	vector<vector<int>> curr(2, vector<int>(3, 0));

    	for(int ind=n-1; ind>=0; ind--) {
    		for(int canBuy=0; canBuy<=1; canBuy++) {
    			for(int cap=1; cap<=2; cap++) {
					if(canBuy == 1) {
						int buy 	= -prices[ind] + prev[0][cap];
						int notBuy 	= 0 + prev[1][cap];
						curr[canBuy][cap] = max(buy, notBuy);
					}
					else {
						int sell	= prices[ind] + prev[1][cap-1];
						int notSell	= 0 + prev[0][cap];
						curr[canBuy][cap] = max(sell, notSell);
					}
    			}
    		}
    		prev = curr;
    	}

		return prev[1][2];
    }



	// // Method 2: Using dp[n][4] instead of dp[n][2][3] //ind, canBuy, cap
	// // 1. Recursion. TC: O(exponential) SC: O(N)
	// // cap will only reduce with each trans(Buy / Sell)
	// int solve(int ind, int cap, int n, vector<int> &prices) {
	// 	if(ind == n || cap == 4)
	// 		return 0;

	// 	if(cap % 2 == 0) {
	// 		int buy 	= -prices[ind] + solve(ind+1, cap+1, n, prices);
	// 		int notBuy 	= 0 + solve(ind+1, cap, n, prices); 
	// 		return max(buy, notBuy);
	// 	}
	// 	else {
	// 		int sell	= prices[ind] + solve(ind+1, cap+1, n, prices);
	// 		int notSell	= 0 + solve(ind+1, cap, n, prices);
	// 		return max(sell, notSell);
	// 	}
	// }

 //    int maxProfit(vector<int>& prices) {
 //    	int n = prices.size();
	// 	return solve(0, 0, n, prices);	// index, capacity = max trans we can perform (given)
 //    }
};

int main(){
	Solution s;
	vector<int> prices;

	prices = {3,3,5,0,0,3,1,4};
	cout << s.maxProfit(prices) << endl;	// 6
	prices = {1,2,3,4,5};
	cout << s.maxProfit(prices) << endl;	// 4
	prices = {7,6,4,3,1};
	cout << s.maxProfit(prices) << endl;	// 0
}