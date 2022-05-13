/*
Maximum_Profit.cpp

In the stock market, a person buys a stock and sells it on some future date. Given the stock prices of N days in an array A[] and a positive integer K, find out the maximum profit a person can make in at-most K transactions. A transaction is equivalent to (buying + selling) of a stock and new transaction can start only when the previous transaction has been completed.
Input: K = 2, N = 6, A = {10, 22, 5, 75, 65, 80}
Output: 87

Input: K = 3, N = 4, A = {20, 580, 420, 900}
Output: 1040

Input: K = 1, N = 5, A = {100, 90, 80, 50, 25}
Output: 0
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}