/*
Find_duplicates_in_an_array
	Method 1: using map. time: O(N log N), space: 2 * O(N) 
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