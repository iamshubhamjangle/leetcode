/*
Best_time_to_buy_and_sell_stock.cpp
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minSoFar = INT_MAX;
        int maxProfit = 0;

        for(auto &n: prices) {
            if(n < minSoFar) {
                minSoFar = n;
            } else {
                int currProfit = n - minSoFar;
                maxProfit = max(maxProfit, currProfit);
            }
        }

        return maxProfit;
    }
};