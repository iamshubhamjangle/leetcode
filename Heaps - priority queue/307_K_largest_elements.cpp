/*
K_largest_elements.cpp

Given an array of N positive integers, print k largest elements from the array.

https://practice.geeksforgeeks.org/problems/k-largest-elements3736/1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
	// //Brute. Sorting. TC: O(nlogn) SC: O(1)
	// vector<int> kLargest(int arr[], int n, int k) {
	//     vector<int> ans;

	//     sort(arr, arr+n, greater<int>());
	//     for(int i=0; i<k; i++) {
	//     	ans.push_back(arr[i]);
	//     }

	//     return ans;
	// }

    
    vector<int> kLargest(int arr[], int n, int k) {
    	vector<int> ans;
    	priority_queue<int, vector<int>, greater<int>> pq;

    	for(int i=0; i<n; i++) {
    		pq.push(arr[i]);
    		if(pq.size() > k) pq.pop();
    	}

    	for(int i=0; i<k; i++) {
    		ans.push_back(pq.top());
    		pq.pop();
    	}

    	reverse(ans.begin(), ans.end());

    	return ans;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for(int i = 0; i < n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout << endl;
        
    }
    return 0;
}


