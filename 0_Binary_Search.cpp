/*
Binary_Search.cpp

Given a sorted array of size N and an integer K, find the position at which K is 
present in the array using binary search.

Example 1:
Input: 	N = 5
		arr[] = {1 2 3 4 5} 
		K = 4
Output: 3

https://practice.geeksforgeeks.org/problems/binary-search/1
	- Method 1: Recursive. TC: O(log N) SC: O(1)
	- Method 2: Iterative. TC: O(log N) SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  	// Method 1: Binary Search - Recursive. TC: O(log N) SC: O(1)
  	int helper(int arr[], int k, int left, int right) {
        if(left > right)
        	return -1;

        int mid = (left + right) / 2;

        if(arr[mid] == k)
        	return mid;

        if(k < arr[mid])
        	return helper(arr, k, left, mid-1);
        else
        	return helper(arr, k, mid+1, right);
  	}

    // Method 2: Iterative. TC: O(log N) SC: O(1)
  	int helper2(int arr[], int k, int left, int right) {
  		while(left < right) {
  			int mid = (left + right) / 2;
  			
  			if(arr[mid] == k)
  				return mid;

  			if(k < arr[mid])
  				right = mid - 1;
  			else
  				left = mid + 1;
  		}

  		return -1;
  	}

    int binarysearch(int arr[], int n, int k) {
        return helper2(arr, k, 0, n-1);
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}