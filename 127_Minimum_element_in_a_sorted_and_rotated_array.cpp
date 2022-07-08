/*
Minimum_element_in_a_sorted_and_rotated_array.cpp

A sorted array A[ ] with distinct elements is rotated at some 
unknown point, the task is to find the minimum element in it.

Input : N = 5, arr[] = {4 ,5 ,1 ,2 ,3}
Output: 1

Input : N = 7, arr[] = {10, 20, 30, 40, 50, 5, 7}
Output: 5

https://practice.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/
Method: Binary Search: TC: O(logN) SC: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

// [5,3]
	

class Solution{
public:
	// Method: Binary Search: TC: O(logN) SC: O(1)
	// Edge case: [1,2,3,4,5], [5,3]
	// Normally find the unsorted part bze mid will lie in that here 
	// [4,5,1,2,3] -> if arr[mid] > arr[mid-1] -> 5 > 1 -> return 1

    int findMin(int arr[], int n){
    	int low = 0;
    	int high = n-1;
       while(low <= high) {
			int mid = low + (high - low)/2;
			
			if(mid == 0 && arr[mid] > arr[mid+1])
				return arr[mid + 1];

			if(mid == 0 || arr[mid-1] > arr[mid])	// if at first index || prev > curr. return curr
				return arr[mid];

			if(arr[low] > arr[mid])
				high = mid - 1;
			else if(arr[mid] > arr[high])
				low = mid + 1;
			else
				return arr[low];
       }

       return -1;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}