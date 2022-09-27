/*
Minimum_Cost_of_ropes.cpp

Input : n = 4, arr[] = {4, 3, 2, 6}
Output: 29

Input : n = 5, arr[] = {4, 2, 7, 6, 9}
Output: 62 

https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
*/


// When we have to optimise: we take the two minimum number in each iteration.

#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

class Solution {
    public:
    // 1. Min Heap to track two min in heap. TC: O(NlogN) SC: O(N) 
    long long minCost(long long arr[], long long n) {
        priority_queue<lli, vector<lli>, greater<lli>> pq(arr, arr+n);
        lli totalCost = 0;

        while(pq.size() > 1) {
        	lli a = pq.top(); pq.pop();
        	lli b = pq.top(); pq.pop();

        	pq.push(a + b);
        	totalCost += (a + b);
        }

        return totalCost;
    }
};

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

