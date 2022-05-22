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
    long long counter;

    void Merge(long long A[], long long L, long long mid, long long R){
       long long B[R+1];
       long long i = L, j = mid +1, k = L;
       while(i <= mid && j <= R){
           if(A[i] <= A[j])
               B[k++] = A[i++];
           else{
               B[k++] = A[j++];
               counter += mid - i +1;
       }
     }
     while(i <= mid)
         B[k++] = A[i++];
     while(j <= R)
         B[k++] = A[j++];
         
     for(long long i = L; i <= R; i++)
          A[i] = B[i];
    }

    void MergeSort(long long A[], long long L, long long R){
       if (L<R){
           long long mid = (L+R)/2;
           MergeSort(A, L, mid);
           MergeSort(A, mid+1, R);
           Merge(A, L, mid, R);
       }
    }
    
    long long int inversionCount(long long A[], long long N)
    {
        counter = 0;
        MergeSort(A, 0, N-1);
        return counter;
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