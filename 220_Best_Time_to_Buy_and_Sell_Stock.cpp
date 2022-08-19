/*
Best_Time_to_Buy_and_Sell_Stock.cpp

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Input: prices = [7,1,5,3,6,4]
Output: 5

Input: prices = [7,6,4,3,1]
Output: 0

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	// // Brute force. TC: O(n*n) SC: O(1) 
 //    int maxProfit(vector<int>& prices) {
 //    	int n = prices.size();
 //    	int profit = 0;

 //    	for(int i=0; i<n; i++) {
 //    		int maxi = 0;
	// 		for(int j=i+1; j<n; j++) {
	// 			maxi = max(maxi, prices[j]);
	// 		}
	// 		profit = max(profit, maxi - prices[i]);
 //    	}

 //    	return profit;
 //    }

	// DP - Optimized, TC: O(N) SC: O(1)
    int maxProfit(vector<int>& prices) {
    	int n = prices.size();
    	int profit = 0;
    	int mini = prices[0];

    	for(int i=1; i<n; i++) {
    		profit = max(profit, prices[i] - mini);
    		mini = min(mini, prices[i]);
    	}

    	return profit;
    }
};

int main(){
	Solution s;
	vector<int> prices;

	prices = {7,1,5,3,6,4};
	cout << s.maxProfit(prices) << endl;	//Output: 5

	prices = {7,6,4,3,1};
	cout << s.maxProfit(prices) << endl;	//Output: 0
}