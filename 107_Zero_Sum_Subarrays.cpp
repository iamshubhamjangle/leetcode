/*
Zero_Sum_Subarrays.cpp

You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.

Input:
n = 6
arr[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are 
[0], [0], [0], [0], [0,0], and [0,0].

Input:
n = 10
arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
Output: 4
Explanation: The 4 subarrays are [-1 -3 4]
[-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)
 

Constraints:    
1<= n <= 107
-1010 <= arri <= 1010

https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1
    - Method 1: Bruteforce. TC: O(N*N) SC: O(1)
    - Method 2: Hashing. TC: O(N) SC: O(N)
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
    public:
    // Method 1: Bruteforce. TC: O(N*N) SC: O(1)
    ll findSubarray1(vector<ll> arr, int n ) {
    	ll count = 0;
        for(int i=0; i<n; i++) {
        	int sum = arr[i];
        	for(int j=i; j<n; j++) {
        		if(i != j)
        			sum += arr[j];
	        	if(sum == 0)
	        		count++;
        	}
        }
        return count;
    }

    // Method 2: Hashing. TC: O(N) SC: O(N)
    //  - Using prefix sum, If the PS repeats i.e. the elements from i+1 to n are zero sum. 
    ll findSubarray(vector<ll> arr, int n ) {
        unordered_map<int, int> um;

        ll sum = 0;
        ll count = 0;
        um[sum]++;

    	// Iterate through arr & Find prefix sum in hashmap
        // if element already occured it means we got range which will be = zero
        // Hence add the value to count; 
        for(int i=0; i<n; i++) {
            sum += arr[i];
            if(um[sum])
                count += um[sum];
            um[sum]++;
        }

        return count;
    }

};

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}