/*
Search_an_element_in_sorted_and_rotated_array.cpp

Given a sorted and rotated array A of N distinct elements which 
is rotated at some point, and given an element K. The task is to 
find the index of the given element K in the array A.

Input : N = 9
		A[] = {5,6,7,8,9,10,1,2,3}
		K = 10
Output: 5

Input : N = 3
		A[] = {3,1,2}
		K = 1
Output: 1

https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array0959/1/?category#
Method 1: Binary Search on sorted part of array. TC: O(log N) SC: O(1) 
*/

#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int low, int high, int k) {
	if(low > high) {
		return -1;
	}

	int mid = (low + high) / 2;

	if(arr[mid] == k)
		return mid;

	if(k < arr[mid])
		return binarySearch(arr, low, mid-1, k);
	else
		return binarySearch(arr, mid+1, high, k);
}

int Search(vector<int> arr, int k) {
	int n = arr.size();
	int i = 0;
	int j = n-1;

    while(arr[i] > arr[j])
    	j--;

    int ans = binarySearch(arr, i, j, k);
    if(ans == -1) {
    	ans = binarySearch(arr, j+1, n-1, k);
    }

    return ans;
}

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}
