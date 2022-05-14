/*
Smallest_subarray_with_sum_greater_than_x

Given an array of integers (A[]) and a number x, find the smallest subarray with sum greater than the given value.
Note: The answer always exists. It is guaranteed that x doesn't exceed the summation of a[i] (from 1 to N).

Input: A[] = {1, 4, 45, 6, 0, 19}, x  =  51
Output: 3

Input: A[] = {1, 10, 5, 2, 7}, x  = 9
Output: 1

https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1
	- Method 1: Bruteforce. time: O(N*N), space: O(1)
	- Method 2: Two pointer approach. TC = O(2n) = O(n) and SC = O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
  	// Method 1: Bruteforce. time: O(N*N), space: O(1)
   //  int smallestSubWithSum(int arr[], int n, int x) {
   //      int mi = INT_MAX;
   //      for(int i=0; i<n; i++) {
   //      	int sum = 0;
   //      	for(int j=i; j<n; j++) {
   //      		sum += arr[j];
   //      		if(sum > x) mi = min(mi, j-i+1);
   //      	}
   //      }
   //      return mi;
   //  }

  	// Method 2: Two pointer approach. TC = O(2n) = O(n) and SC = O(1)
		int smallestSubWithSum(int arr[], int n, int x) {
       int sum = 0;							//sum
       int s = 0, e = 0;				//start, end
       int len = INT_MAX;				//length
       for(e = 0; e < n; e++) {
           sum += arr[e];
           while(sum > x && s < n) {
               len = min(len, e - s + 1);
               sum -= arr[s];
               s++;
           }
       }
       return len;
    }

};

int main() {
	int t;
	cin >> t;
	while(t--)
	{
		int n,x;
		cin >> n >> x;
		int a[n];
		for(int i=0; i<n; i++)
		cin >> a[i];
		Solution obj;
		cout << obj.smallestSubWithSum(a,n,x) << endl;
	}
	return 0;
}

