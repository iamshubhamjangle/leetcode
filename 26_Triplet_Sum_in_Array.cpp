/* Triplet_Sum_in_Array

Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.

Input: n = 6, X = 13, arr[] = [1 4 45 6 10 8]
Output: 1

Input: n = 5, X = 10, arr[] = [1 2 4 3 6]
Output: 1

https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1
Method 1: bruteforce - O(N*N*N)
Method 2: unordered_map - loop twice and search for third element in map - O(N*N)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	// Method 1: Bruteforce O(N*N*N), space: O(1)
    // bool find3Numbers(int a[], int n, int X) {
    //     for(int i=0; i<n; i++) {
    //     	for(int j=i+1; j<n; j++) {
    //     		for(int k=j+1; k<n; k++) {
    //     			if(a[i] + a[j] + a[k] == X) {
    //     				return true;
    //     			}
    //     		}
    //     	}
    //     }
    //     return false;
    // }

	// Method 2: unordered_map - loop twice and search for third element in map - O(N*N)
    bool find3Numbers(int a[], int n, int X) {
    	unordered_map<int, int> um;
    	for(int i=0; i<n; i++) {
    		um[a[i]]++;
    	}

        for(int i=0; i<n-1; i++) {
        	for(int j=i+1; j<n-1; j++) {
        		int thirdValue = X - (a[i] + a[j]);
        		if(um[thirdValue] > 0) {
        			return true;
        		}
        	}
        }
        return false;
	}
};

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, sum;
		cin >> n >> sum;
		int a[n];
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		Solution ob;
		cout << ob.find3Numbers(a, n, sum) << endl;
	}
}

