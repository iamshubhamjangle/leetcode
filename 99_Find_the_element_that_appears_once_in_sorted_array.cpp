/*
Find_the_element_that_appears_once_in_sorted_array.cpp

Given a sorted array arr[] of size N. Find the element that appears only 
once in the array. All other elements appear exactly twice.

Input:
N = 11
arr[] = {1, 1, 2, 2, 3, 3, 4, 50, 50, 65, 65}
Output: 4

Expected Time Complexity: O(log N)
Expected Auxiliary Space: O(1)

https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array0624/1
	- Method 1: Basic comparision i == i+1. TC: O(N) SC: O(1) 
	- Method 2: Using XOR operator. TC: O(N). SC: O(1)
	- Method 3: Binary Search. TC: O(logN) SC: O(1)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  	// Method 1: Basic comparision i == i+1. TC: O(N) SC: O(1) 
    int findOnce1(int arr[], int n) {
    	for(int i=0; i<n-1;) {
    		if(arr[i] == arr[i+1])
    			i += 2;
    		else
    			return arr[i];
    	}

    	if(n % 2 != 0) return arr[n-1];
    	return -1;
    }

    // Method 2: Using XOR operator. TC: O(N). SC: O(1)
    // XOR properties
    // n ^ 0 = n
    // n ^ n = 0
	int findOnce2(int arr[], int n) {
		int element = arr[0];
		for(int i=1; i<n; i++) {
			element ^= arr[i];
    	}
    	return element;
    }

    // Method 3: Binary Search. TC: O(logN) SC: O(1)
    // This won't work if there is no unique element in arr
    // arr[mid^1] ---> XOR 1
    // for even it return n+1 i.e. next index
    // for odd it return n-1  i.e. prev index
	int findOnce(int arr[], int n) {
		int low  = 0;
		int high = n-2;
		while(low <= high) {
			int mid = (low + (high - low) / 2);
			if(arr[mid] == arr[mid^1]) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		return arr[low];
	}

};


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++) {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}