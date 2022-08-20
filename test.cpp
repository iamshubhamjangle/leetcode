#include <bits/stdc++.h>
using namespace std;

## Background
- We can Buy or Sell (This is done using `canBuy` variable)
- When `canBuy` == 1, we have to buy or we can skip and move to next index
- When `canBuy` == 0, we have to sell or we can skip and move to next index
- Transaction completes when buy and sell is completed, so we will subtract the fee while sell.

### Recursion. TC: O(exponential) SC: O(1) ASC: O(N)
```cpp
int solve(int ind, int canBuy, vector<int> &prices, int n, int fee) {
	if(ind == n)
		return 0;

	int profit = 0;

	if(canBuy) {
		int buy 	= -prices[ind] + solve(ind+1, 0, prices, n, fee);
		int notBuy 	= 0 + solve(ind+1, 1, prices, n, fee);
		profit = max(buy, notBuy);
	} else {
		int sell 	= prices[ind] - fee + solve(ind+1, 1, prices, n, fee);
		int notSell = 0 + solve(ind+1, 0, prices, n, fee);
		profit = max(sell, notSell);
	}

	return profit;
}

int maxProfit(vector<int>& prices, int fee) {
	int n = prices.size();
	return solve(0, 1, prices, n, fee);	// ind, canBuy, arr, fee
}
```



### Memo. TC: O(N*2) SC: O(N*2) ASC: O(N)
```cpp
int solve(int ind, int canBuy, vector<int> &prices, int n, int fee, vector<vector<int>> &dp) {
	if(ind == n)
		return 0;

	if(dp[ind][canBuy] != -1) 
		return dp[ind][canBuy];

	int profit = 0;

	if(canBuy) {
		int buy 	= -prices[ind] + solve(ind+1, 0, prices, n, fee, dp);
		int notBuy 	= 0 + solve(ind+1, 1, prices, n, fee, dp);
		profit = max(buy, notBuy);
	} else {
		int sell 	= prices[ind] - fee + solve(ind+1, 1, prices, n, fee, dp);
		int notSell = 0 + solve(ind+1, 0, prices, n, fee, dp);
		profit = max(sell, notSell);
	}

	return dp[ind][canBuy] = profit;
}

int maxProfit(vector<int>& prices, int fee) {
	int n = prices.size();
	vector<vector<int>> dp(n, vector<int>(2, -1));
	return solve(0, 1, prices, n, fee, dp);	// ind, canBuy, arr, fee
}
```



### Tabulation. TC: O(N*2) SC: O(N*2)
```cpp
int maxProfit(vector<int>& prices, int fee) {
	int n = prices.size();
	vector<vector<int>> dp(n+1, vector<int>(2, 0));

	// Base Conditions
	// dp[n][0] = 0;
	// dp[n][1] = 0;

	for(int ind=n-1; ind>=0; ind--) {
	for(int canBuy=0; canBuy<=1; canBuy++) {
		int profit = 0;

		if(canBuy) {
			int buy 	= -prices[ind] + dp[ind+1][0];
			int notBuy 	= 0 + dp[ind+1][1];
			profit = max(buy, notBuy);
		} else {
			int sell 	= prices[ind] - fee + dp[ind+1][1];
			int notSell = 0 + dp[ind+1][0];
			profit = max(sell, notSell);
		}

		dp[ind][canBuy] = profit;
	}
}

return dp[0][1];
}
```



### Space Optimized. TC: O(N*2) SC: O(2)
```cpp
int maxProfit(vector<int>& prices, int fee) {
	int n = prices.size();
	vector<int> ahead(2, 0);
	vector<int> curr(2, 0);

	// Base conditions
	// ahead[0] = 0;
	// ahead[1] = 0;

	for(int ind=n-1; ind>=0; ind--) {
		for(int canBuy=0; canBuy<=1; canBuy++) {
			int profit = 0;

			if(canBuy) {
				int buy 	= -prices[ind] + ahead[0];
				int notBuy 	= 0 + ahead[1];
				profit = max(buy, notBuy);
			} else {
				int sell 	= prices[ind] - fee + ahead[1];
				int notSell = 0 + ahead[0];
				profit = max(sell, notSell);
			}

			curr[canBuy] = profit;
		}
		ahead = curr;
	}

	return ahead[1];
}
```



### Optimized Pro Plus. TC: O(N*2) SC: O(2)
```cpp
int maxProfit(vector<int>& prices, int fee) {
	int n = prices.size();
	// you may also you four variables instead.
	vector<int> ahead(2, 0);
	vector<int> curr(2, 0);

	for(int ind=n-1; ind>=0; ind--) {
		int buy 	= -prices[ind] + ahead[0];
		int notBuy 	= 0 + ahead[1];
		curr[1] = max(buy, notBuy);
	
		int sell 	= prices[ind] - fee + ahead[1];
		int notSell = 0 + ahead[0];
		curr[0] = max(sell, notSell);
		ahead = curr;
	}

	return ahead[1];
}
```