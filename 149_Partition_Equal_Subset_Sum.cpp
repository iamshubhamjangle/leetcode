/*
Partition_Equal_Subset_Sum.cpp

Given an array arr[] of size N, check if it can be partitioned into two parts such that 
the sum of elements in both parts is the same.

Input: N = 4, arr = {1, 5, 11, 5}
Output: YES

Input: N = 3, arr = {1, 3, 5}
Output: NO

https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
Method 1: Bruteforce TC: O(2^n) SC: O(N) - stack
Method 2: DP (knapsack similar) TC: O(N*sum) SC: O(N*sum)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Bruteforce TLE: TC: O(2^n) SC: O(N) - stack space 
    /*
    bool isEqualSumSubset(int arr[], int n, int target) {
        if(n == 0) return target == 0;      // return true if target is zero

        bool take, dontTake;
        take = isEqualSumSubset(arr, n-1, target - arr[n]);
        dontTake = isEqualSumSubset(arr, n-1, target);

        return take || dontTake;
    }

    int equalPartition(int n, int arr[]) {
        int totalSum = accumulate(arr, arr+n, 0);
        if(totalSum & 1) return 0;
        return isEqualSumSubset(arr, n-1, totalSum/2);
    }
    */


    // Following knapsack pattern
    int equalPartition(int n, int arr[]) {
        int sum = accumulate(arr, arr+n, 0);                // calculate sum of arr
        if(sum & 1) return 0;                               // if odd

        bool dp[n+1][sum+1];                                // initialize dp
        for(int i=0; i<=sum; i++) { dp[0][i] = false; }     // First row to false
        for(int i=0; i<=n; i++) { dp[i][0] = true; }        // First column to true;

        for(int i=1; i<=n; i++) {                           // row
            for(int j=1; j<=sum; j++) {                     // column
                if(arr[i-1] <= j){
                    dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
                } else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][sum/2];
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}