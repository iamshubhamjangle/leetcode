/*
Count_pairs_with_given_sum.cpp

https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1
Method 1: Bruteforce - time: O(N*N), space: O(1)
Method 2: Using sorting - time: O(N log N)
Method 3: Using hashmap/unordered_map - complexity-O(n)

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

	int getPairsCount(int arr[], int n, int k) {
	 //2- using Urting - complexity-O(nlogn) for sorting + O(n) for loop ~= O(nlogn)

	    // int left=0;
	    // int right=n-1;
	    // int count=0;      
	    
	    // sort(arr,arr+n); 
	    
	    // while(left<=right){
	    //     if(arr[left]+arr[right] == k){
	    //         count++;
	    //     }
	    //     else if(arr[left]+arr[right]>k){
	    //         right--;
	    //     }
	    //     else{
	    //         left++;
	    //     }
	    // }
	    // return count;
	    
	    
	    //3- OPTIMAL SOLUTION using hashmap/unordered_map - complexity-O(n)
	    unordered_map<int,int> m;
	    
	    int count=0;
	    for(int i=0;i<n;i++){
	        int b=k-arr[i];
	        
	        if(m[b]){
	            count=count+m[b];
	        }
	        m[arr[i]]++;
	    }
	    return count;
	}
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