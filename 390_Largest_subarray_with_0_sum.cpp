/*
Largest_subarray_with_0_sum.cpp

Input : N = 8, A[] = {15,-2,2,-8,1,7,10,23}
Output: 5

https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	// TLE: Brute TC: O(N^3) SC: O(1)
	int _maxLen(vector<int> &arr, int n) {
		int maxLen = INT_MIN;

		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				int sum = 0;
				for(int k=i; k<=j; k++) {
					sum += arr[k];
				}
				if(sum == 0)
					maxLen = max(maxLen, j-i+1);
			}
		}

		return maxLen;
	}


	// To generate all subarray - Kadane's algo.
	// TLE. TC: O(N^2) SC: O(1)
	int __maxLen(vector<int> &arr, int n) {
		int maxLen = 0;

		for(int i=0; i<n; i++) {
			int currSum = 0;
			for(int j=i; j<n; j++) {
				currSum += arr[j];
				if(currSum == 0) {
					maxLen = max(maxLen, j-i+1);
				}
			}
		}

		return maxLen;
	}


	// If sum of point A to B is 3, Then sum of point A to C is 3. That means sum of B to C is 0.
	// TC: O(N) + O(logN) for hashmap. SC: O(N)
	int maxLen(vector<int> &arr, int n) {
		int sum = 0;
		int maxLen = 0;
		unordered_map<int,int> um; 	// {sum, position}

		for(int i=0; i<n; i++) {
			sum += arr[i];

			if(sum == 0) {
				maxLen = i+1;
			} else {
				if(um.find(sum) != um.end()) {
					maxLen = max(maxLen, i - um[sum]);
				} else {
					um[sum] = i;
				}
			}
		}

		return maxLen;
	}
};

int main(){
	Solution s;
	vector<int> A;

	A = {15,-2,2,-8,1,7,10,23};
	cout << s.maxLen(A, 8) << endl;
}