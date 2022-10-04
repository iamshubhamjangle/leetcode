/*
Best_Time_to_Buy_and_Sell_Stock.cpp

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/3 
*/

class Solution {
public:
    // 1. Bruteforce. Check profit of each pairs. return max.
    // TC: O(N*N) SC: O(1)

    // 2. Store min and find a max to sell.
    // TC: O(N) SC: O(1)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int maxProfit = 0;
        int least = INT_MAX;
        int profit = 0;

        for(int i=0; i<n; i++) {
            least = min(prices[i], least);
            profit = prices[i] - least;
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};