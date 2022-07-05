/*
Peak_element.cpp

An element is called a peak element if its value is not smaller than the value of its adjacent elements(if they exists).
Given an array arr[] of size N, Return the index of any one of its peak elements.
Note: The generated output will always be 1 if the index that you return is correct. Otherwise output will be 0. 

Input: N = 3
arr[] = {1,2,3}
Possible Answer: 2
Generated Output: 1

Input: N = 2
arr[] = {3,4}
Possible Answer: 1
Output: 1

https://practice.geeksforgeeks.org/problems/peak-element/1
    - bruteforce. TC: O(N) SC: O(1)
	- Binary search. TC: O(log N) SC: O(1)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // bruteforce. TC: O(N) SC: O(1)
    int peakElement1(int arr[], int n) {
        int peak = 0;
        for(int i=0; i<n-1; i++) {
            if(arr[i] < arr[i+1])
                peak = i+1;
        }
        
        return peak;
    }

	// Binary search. TC: O(log N) SC: O(1)
    int peakElement(int arr[], int n) {
    	int l = 0;
    	int h = n-1;
    	while(l<=h) {
    		int mid = l + (h-l)/2;
    		if((mid==0 || arr[mid-1] <= arr[mid]) && (mid==n-1 || arr[mid+1] <= arr[mid]))
    			return mid;
    		if(mid > 0 && arr[mid-1] >= arr[mid])
    			h = mid-1;
    		else
    			l = mid+1;
    	}
    	return -1;
    }

};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n], tmp[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			tmp[i] = a[i];
		}
		bool f=0;
		Solution ob;
		
		int A = ob. peakElement(tmp,n);
		
		if(A<0 and A>=n)
		    cout<<0<<endl;
		else
		{
    		if(n==1 and A==0)
    		    f=1;
    		else if(A==0 and a[0]>=a[1])
    		    f=1;
    		else if(A==n-1 and a[n-1]>=a[n-2])
    		    f=1;
    		else if(a[A]>=a[A+1] and a[A]>= a[A-1])
    		    f=1;
    		else
    		    f=0;
    		cout<<f<<endl;
		}
		
	}
	return 0;
}