/*
Merge_Without_Extra_Space_

Given two sorted arrays arr1[] of size N and arr2[] of size M. 
Each array is sorted in non-decreasing order. 
Merge the two arrays into one sorted array in non-decreasing order without using any extra space.

Input:
N = 4, M = 5
arr1[] = {1, 3, 5, 7}
arr2[] = {0, 2, 6, 8, 9}
Output: 0 1 2 3 5 6 7 8 9

Input:
N = 2, M = 3
arr1[] = {10, 12}
arr2[] = {5, 18, 20}
Output: 5 10 12 18 20v

https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1
	Method 1: loop over arr1 and swap with arr2[0] then sort arr2 - time: O(N*NlogN), space: O(1)
	Method 2: start diagonally, swap and at end sort both arr. time: O(N logN), space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	// Method 1: loop over and swap TLE - time: O(N*NlogN), space: O(1)
	// void merge(int arr1[], int arr2[], int n, int m) {
	//     int x = 0;
	//     while(x < n){
	//     	if(arr1[x] > arr2[0]) {
	//     		swap(arr1[x], arr2[0]);
	//     		sort(arr2, arr2 + m);
	//     	}
	//     	x++;
	//     }
	// }

	// Method 2: start diagonally, and sort. time: O(N logN), space: O(1)
	void merge(int arr1[], int arr2[], int n, int m) {
	    int i=n-1,j=0;
	    while(i>=0 && j<m){
	        if(arr1[i]>arr2[j]){
	            swap(arr1[i],arr2[j]);
	            i--;
	        }
	        else j++;   
	    }
	    sort(arr1,arr1+n);
    	sort(arr2,arr2+m);
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}