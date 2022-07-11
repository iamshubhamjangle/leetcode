/*
Bitonic_Point.cpp

Given an array arr of n elements which is first increasing and then may be decreasing, 
find the maximum element in the array.
Note: If the array is increasing then just print then last element will be the maximum value.

Input: n = 9, arr[] = {1,15,25,45,42,21,17,12,11}
Output: 45

Input: n = 5, arr[] = {1, 45, 47, 50, 5}
Output: 50

https://practice.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1
Method 1: Bruteforce: O(N)
Method 2: Binary Search: O(logn)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int findMaximum(int arr[], int n) {
		int l = 0;
		int h = n-1;

		while(l<=h) {
			int mid = l + (h-l)/2;

			if((mid==0 || arr[mid-1] < arr[mid]) && (mid==n-1 || arr[mid] > arr[mid+1]))
				return arr[mid];

			if(arr[mid] < arr[mid+1])		// increasing side
				l = mid+1;
			else if(arr[mid-1] > arr[mid])		// decreasing side
				h = mid-1;
		}

		return -1;
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}