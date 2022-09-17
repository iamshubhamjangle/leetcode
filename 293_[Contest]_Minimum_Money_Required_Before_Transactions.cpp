/*
[Contest]_Minimum_Money_Required_Before_Transactions.cpp

Input: transactions = [[2,1],[5,0],[4,2]]
Output: 10

Input: transactions = [[3,0],[0,3]]
Output: 3

https://leetcode.com/problems/minimum-money-required-before-transactions/
*/

class Solution {
public:
    // long long minimumMoney(vector<vector<int>>& transactions) {
    //     long long res1 = 0;
    //     long long minVal = 0;
        
    //     for(auto t: transactions) {
    //         minVal = min(t[0], t[1]);
    //         res1 = max(res1, minVal);
    //     }
        
    //     for(auto t: transactions) {
    //         res1 += max(t[0] - t[1], 0);
    //     }
        
    //     return res1;
    // }


    long long minimumMoney(vector<vector<int>>& A) {
        long long res = 0; int v = 0;
        for (auto& a : A) {
            v = max(v, min(a[0], a[1]));
            res += max(a[0] - a[1], 0);
        }
        return res + v;
    }
};