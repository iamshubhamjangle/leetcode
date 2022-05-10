/* Subarray_with_0_sum.cpp
Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.
Example 1:
Input:
5
4 2 -3 1 6

Output: 
Yes

https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1#
Method 1: Bruteforce. time: O(N*N), space: O(1)
Method 2: Using Prefix sum
	- if a element is repeating in prefix sum it means The sum of elements inbetween must be zero
	- if the sum == 0
	- current element is zero a[i] == 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Method 1: Bruteforce. time: O(N*N), space: O(1)
    // bool subArrayExists(int arr[], int n) {
    // 	for(int i=0; i<n; i++) {
    // 		int sum = 0;
    // 		for(int j=i; j<n; j++) {
    // 			sum += arr[j];
    // 			if(sum == 0) {
    // 				return true;
    // 			}
    // 		}
    // 	}
    // 	return false;
    // }

    // Method 2: Using Prefix sum
    // if a element is repeating in prefix sum it means The sum of elements inbetween must be zero
    // if the sum == 0
    // current element is zero a[i] == 0
    bool subArrayExists(int arr[], int n) {
    	unordered_map<int, int> mp;
    	int sum=0;
    	for(int i=0; i<n; i++) {
    		sum += arr[i];
    		if(mp[sum] || sum == 0 || arr[i] == 0) {
    			return true;
    		}
    		mp[sum]++;
    	}

    	return false;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}