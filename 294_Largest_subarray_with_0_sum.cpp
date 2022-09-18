/*
Largest_subarray_with_0_sum.cpp

Given an array having both positive and negative integers. 
The task is to compute the length of the largest subarray with sum 0.

Input : N = 8, A[] = {15,-2,2,-8,1,7,10,23}
Output: 5

https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
*/

/*
1. Generate all subarray and find the sum. TC: O(N^3) SC: O(1)
2. Kadane's Algorithm. TC: O(N^2) SC: O(1)
3. Prefix sum. TC: O(N) SC: O(N)

*/

class Solution{
    public:
    // Prefix sum: Store the prefix sum in hashmap and a running sum variable.
    // If running sum exist in hashmap we have same sum at two place
	// which means subarray betwenn has sum = 0;
    int maxLen(vector<int>&A, int n) {   
		unordered_map<int,int> um;
		int maxi = 0;
		int runningSum = 0;

		for(int i=0; i<n; i++) {
			runningSum += A[i];
			if(runningSum == 0) {
				// found a zero sum upto ith index, so length will be i+1
				maxi = i+1;
			} else {
				if(um.find(runningSum) != um.end()) {
					int length = i - um[runningSum];
					maxi = max(maxi, length);
				} else {
					um[runningSum] = i;
				}
			}
		}

		return maxi;
    }
};