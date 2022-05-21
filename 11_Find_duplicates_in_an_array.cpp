/*
Find_duplicates_in_an_array

Given an array a[] of size N which contains elements from 0 to N-1, 
you need to find all the elements occurring more than once in the given array.

Input:
N = 4
a[] = {0,3,1,2}
Output: -1

Input:
N = 5
a[] = {2,3,1,2,3}
Output: 2 3 

https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1
	Method 1: using map. time: O(N), space: 2 * O(N) 
	Method 2: O(N log N), space: O(N) 
    	- sort() and (arr[i] == arr[i+1] && num != arr[i+1])
*/


#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    // vector<int> duplicates(int arr[], int n) {
    //     vector<int> ans;
    //     map<int, int> count;
    // 	for(int i=0; i<n; i++) {
    // 		count[arr[i]]++;
    // 	}

    // 	for(auto x: count) {
    // 		if(x.second > 1) {
    // 			ans.push_back(x.first);
    // 		}
    // 	}

    // 	if(ans.size() == 0) return {-1};
    // 	return ans;
    // }

    // Method 2: O(N log N), space: O(N) 
    // sort() and (arr[i] == arr[i+1] && num != arr[i+1])
    vector<int> duplicates(int arr[], int n) {
        sort(arr, arr+n);
        
        vector<int> ans;
        int num = -1;

        for(int i=0; i<n; i++) {
        	if(arr[i] == arr[i+1] && num != arr[i+1]) {
        		ans.push_back(arr[i]);
        		num = arr[i];
        	}
        }

    	if(ans.size() == 0) return {-1};

    	return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}