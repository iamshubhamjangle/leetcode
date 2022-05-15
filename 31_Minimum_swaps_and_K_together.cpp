/* Minimum_swaps_and_K_together 

Given an array arr of n positive integers and a number k. One can apply a swap operation on the array any number of times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] . Find the minimum number of swaps required to bring all the numbers less than or equal to k together, i.e. make them a contiguous subarray.

Input : arr[ ] = {2, 1, 5, 6, 3}, K = 3
Output :  1

Input :  arr[ ] = {2, 7, 9, 5, 8, 7, 4}, K = 6 
Output :   2 

Method 1: Bruteforce. TC: O(N*N), SC: O(1).
    - not solved yet

Method 2: using sliding window method.TC: O(N), SC: O(1)
    - find elements less than k.
    - take window of size equal k. find ans = bad_numbers in first window.
    - iterate through whole array now, as we go to next element bad_number may increase / decrease
    - find the ans = min(ans, bad_number);

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 1: using sliding window method.TC: O(N), SC: O(1)
    // int minSwap(int arr[], int n, int k) {
    //     int count = 0;  //elements less than k
    //     for(int i=0; i<n; i++) {
    //         if(arr[i] <= k) count++;
    //     }

    //     int badNums = 0;    //element > k in first window
    //     for(int i=0; i<count; i++) {
    //         if(arr[i] > k) badNums++;
    //     }

    //     int ans = badNums;
    //     for(int i=0, j=count; j<n; j++, i++) {
    //         if(arr[i] > k) badNums--;   // out of window element > k, decrement
    //         if(arr[j] > k) badNums++;   // upcoming element to window > k, increment
    //         ans = min(ans, badNums);
    //     }

    //     return ans;
    // }
};

int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}