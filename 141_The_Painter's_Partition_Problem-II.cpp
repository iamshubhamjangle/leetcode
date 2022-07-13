/*
The_Painter's_Partition_Problem-II.cpp

Dilpreet wants to paint his dog's home that has n boards with different lengths. 
The length of ith board is given by arr[i] where arr[] is an array of n integers. 
He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

The problem is to find the minimum time to get this job done if all painters start together 
with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} 
or only board {1} or nothing but not boards {2,4,5}.

Input:
n = 5
k = 3
arr[] = {5,10,30,20,15}
Output: 35

https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1/
Method: Binary Search. TC: O(log N) SC: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isValid(int arr[], int n, int k, long long mid) {
        long painter = 1;
        long long sum = 0;
        
        for(long int i=0; i<n; i++) {
            sum += arr[i];
            if(sum > mid) {
                painter++;
                sum = arr[i];
            }
            if(painter > k)
                return false;
        }
        
        return true;
    }
  
    long long minTime(int arr[], int n, int k) {
        long long l = INT_MIN, h = 0;
        for(int i=0; i<n; i++) {
            if(arr[i] > l)
                l = arr[i];
                
            h += arr[i];
        }
        
        long long res = INT_MIN;
        
        while(l <= h) {
            long long mid = l + (h-l)/2;
            
            if(isValid(arr, n, k, mid)) {
                res = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends