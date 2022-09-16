/*
Count_Inversions.cpp

Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. 
If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order 
then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Example 1:
Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).

Example 2:
Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already 
sorted so there is no inversion count.

Example 3:
Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array 
are same, so there is no inversion count.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 5*105
1 ≤ arr[i] ≤ 1018

https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
Method 1: Bruteforce TC: O(N*N), SC: O(1)
Method 2: Merge sort TC: O(N log N), SC

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
  	// Method 1: bruteforce
  //   long long int inversionCount(long long arr[], long long n)
  //   {
  //   	long long int count = 0;
		// for(int i=0; i<n; i++) {
		// 	for(int j=i+1; j<n; j++) {
		// 		if(arr[i] > arr[j] && i < j) {
		// 			count++;
		// 		}
		// 	}
		// }
		// return count;
  //   }

  	// Method 2: Merge sort
    /* This function merges two sorted arrays and returns inversion count in the arrays.*/

    long long int merge(long long int arr[], long long int temp[], int left, int mid, int right) {
        int i = left;
        int j = mid;
        int k = left;
        long long int inv_count = 0;

        // while two pointer are within limits
        // try to merge based on which is smaller
        while((i<=mid-1) && (j<=right)) {
            if(arr[i] <= arr[j]) {
                temp[k] = arr[i];
                k++;
                i++;
            } else {
                temp[k] = arr[j];
                k++;
                j++;
                inv_count = inv_count + (mid - i);
            }
        }

        // push the leftover to temp;
        while(i <= mid-1) {
            temp[k] = arr[i];
            k++; i++;
        }

        while(j <= right) {
            temp[k] = arr[j];
            k++; j++;
        }

        // copy the temp back to arr
        for(i = left; i<=right; i++) {
            arr[i] = temp[i];
        }

        return inv_count;
    }

    // @return inversion count
    long long int mergeSort(long long int arr[], long long int temp[], int left, int right) {
        long long int mid, count = 0;
        if(right > left) {
            mid = (right + left) / 2;

            long long int l = mergeSort(arr, temp, left, mid);
            long long int r = mergeSort(arr, temp, mid+1, right);

            count = l + r + merge(arr, temp, left, mid+1, right);
        }
        return count;
    }
    
    long long int inversionCount(long long arr[], long long n) {
        long long int temp[n];
        return mergeSort(arr, temp, 0, n-1);
    }
};

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        int N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}