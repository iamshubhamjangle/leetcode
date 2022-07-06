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
	- Method 1: Binary Search on sorted part of array. TC: O(N) SC: O(1) 
	- Method 2: Binary search directly on whole array
*/

#include<bits/stdc++.h>
using namespace std;


// Method 1: Binary Search on sorted part of array. TC: O(N) SC: O(1) 
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




// Method 2: Binary search directly on whole array
// at any position one part of vector will be sorted we will seearch our element in that part
// also reduce the serach space in each iteration
int Search(vector<int> arr, int k) {
    int n = arr.size();
    int l = 0;
    int h = n-1;
    // l   = 0 5
    // h   = 8 8
    // mid = 4 6 
    while(l <= h) {
        int mid = l + (h-l)/2;
        
        if(arr[mid] == k) return mid;
        
        if(arr[l] < arr[mid]) { // left side is sorted
            if(arr[l] <= k && k < arr[mid]) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        } 
        else {          // right side should be sorted
            if(arr[mid] < k && k <= arr[h]) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
    }
    
    return -1;
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
