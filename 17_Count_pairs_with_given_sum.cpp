/*
Count_pairs_with_given_sum.cpp


Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
 // Method 1: Bruteforce - time: O(N*N), space: O(1)
 //    int getPairsCount(int arr[], int n, int k) {
 //    	int count = 0;
 //        for(int i=0; i<n; i++) {
 //        	for(int j=i+1; j<n; j++) {
 //        		if(arr[i] + arr[j] == k) {
 //        			count++;
 //        		}
 //        	}
 //        }
 //        return count;
 //    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}