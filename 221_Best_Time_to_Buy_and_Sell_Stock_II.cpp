/*
Best_Time_to_Buy_and_Sell_Stock_II.cpp
Unlimited Transactions

Input: prices = [7,1,5,3,6,4]
Output: 7

Input: prices = [1,2,3,4,5]
Output: 4

Input: prices = [7,6,4,3,1]
Output: 0

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// // 1. Two Pointer. TC: O(N) SC: O(1)
 //    int maxProfit(vector<int>& prices) {
 //        int n = prices.size();
 //        if(n <= 1) return 0;

 //        int i = 0;
 //        int j = 1;
 //        int buyPrice = INT_MIN;
 //        int profit = 0;
 //        bool buyed = false;


 //        while(j < n) {
 //        	if(prices[i] < prices[j] && !buyed) {
 //        		buyed = true;
 //        		buyPrice = prices[i];
 //        	}
 //        	if(prices[i] > prices[j] && buyed) {
 //        		buyed = false;
 //        		profit += prices[i] - buyPrice;
 //        	}
 //        	i++;
 //        	j++;
 //        }

 //        if(buyed) {
 //        	buyed = false;
 //        	profit += prices[i] - buyPrice;
 //        }

 //        return profit;
 //    }


    // // Recursion. TC: O(2^n) SC: O(1) ASC: O(N)
    // int solve(int ind, int canBuy, int n, vector<int> &prices) {
    // 	// When we have exhaused the days
    // 	if(ind == n) {
    // 		return 0;
    // 	}

    // 	int profit;

    // 	if(canBuy) {
    // 		int buy 	= solve(ind+1, 0, n, prices) - prices[ind];	// if we buy
    // 		int notBuy 	= solve(ind+1, 1, n, prices) - 0;			// if we not buy
    // 		profit = max(buy, notBuy);
    // 	} 
    // 	else {	// if we cannot buy, we have to sell 
    // 		int sell 	= solve(ind+1, 1, n, prices) + prices[ind];	// sell
    // 		int notSell = solve(ind+1, 0, n, prices) + 0;			// not sell
    // 		profit = max(sell, notSell);
    // 	}

    // 	return profit;
    // }

    // int maxProfit(vector<int> &prices) {
    // 	int n = prices.size();
    // 	// int ind = 0;		// ind start from 0
    // 	// int canBuy = 1;		// initially we can buy
    // 	return solve(0, 1, n, prices);
    // }



    // // 2. Memoisation. TC: O(n*2) SC: O(n*2) ASC: O(N)
    // int solve(int ind, int canBuy, int n, vector<int> &prices, vector<vector<int>> &dp) {
    // 	// When we have exhaused the days
    // 	if(ind == n) {
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
    // 		int sell 	= solve(ind+1, 1, n, prices, dp) + prices[ind];	// sell
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



    // // 3. Tabulation. TC: O(n*2) SC: O(n*2)
    // int maxProfit(vector<int> &prices) {
    // 	int n = prices.size();
    // 	vector<vector<int>> dp(n+1, vector<int>(2, 0));

    // 	// if (ind == n) return 0; for ind n and any boolean put it as 0;
    // 	dp[n][0] = 0;
    // 	dp[n][1] = 0;

    // 	for(int ind=n-1; ind>=0; ind--) {
    // 		for(int canBuy=0; canBuy<=1; canBuy++) {
		  //   	int profit = 0;

		  //   	if(canBuy) {
		  //   		int buy 	= dp[ind+1][0] - prices[ind];
		  //   		int notBuy 	= dp[ind+1][1] - 0;
		  //   		profit = max(buy, notBuy);
		  //   	} 
		  //   	else {
		  //   		int sell 	= dp[ind+1][1] + prices[ind];
		  //   		int notSell = dp[ind+1][0] + 0;
		  //   		profit = max(sell, notSell);
		  //   	}

		  //   	dp[ind][canBuy] = profit;	
    // 		}
    // 	}

    // 	return dp[0][1];
    // }



    // // 4. Space Optimisation. TC: O(n*2) SC: O(n*2)
    // int maxProfit(vector<int> &prices) {
    // 	int n = prices.size();
    // 	vector<int> prev(2, 0);
    // 	vector<int> curr(2, 0);

    // 	// if (ind == n) return 0; for ind n and any boolean put it as 0;
    // 	prev[0] = 0;
    // 	prev[1] = 0;

    // 	for(int ind=n-1; ind>=0; ind--) {
    // 		for(int canBuy=0; canBuy<=1; canBuy++) {
		  //   	int profit = 0;

		  //   	if(canBuy) {
		  //   		int buy 	= prev[0] - prices[ind];
		  //   		int notBuy 	= prev[1] - 0;
		  //   		profit = max(buy, notBuy);
		  //   	} 
		  //   	else {
		  //   		int sell 	= prev[1] + prices[ind];
		  //   		int notSell = prev[0] + 0;
		  //   		profit = max(sell, notSell);
		  //   	}

		  //   	curr[canBuy] = profit;	
    // 		}
    // 		prev = curr;
    // 	}

    // 	return prev[1];
    // }


    // 5. Using 4 variables ??
    int maxProfit(vector<int> &prices) {
        int n = prices.size();

        int prevBuy, prevNotBuy, currBuy, currNotBuy;

        // if (ind == n) return 0; for ind n and any boolean put it as 0;
        prevNotBuy = 0;
        prevBuy = 0;

        for(int ind=n-1; ind>=0; ind--) {
            int buy     = prevNotBuy - prices[ind];
            int notBuy  = prevBuy - 0;
            currBuy = max(buy, notBuy);

            int sell    = prevBuy + prices[ind];
            int notSell = prevNotBuy + 0;
            currNotBuy = max(sell, notSell);

            prevBuy = currBuy;
            prevNotBuy = currNotBuy;
        }

        return prevBuy;
    }
};

int main(){
	Solution s;
	vector<int> prices;

	prices = {7,1,5,3,6,4};
	cout << s.maxProfit(prices) << endl;   // 7
	prices = {1,2,3,4,5};
	cout << s.maxProfit(prices) << endl;   // 4
	prices = {7,6,4,3,1};
	cout << s.maxProfit(prices) << endl;   // 0
}