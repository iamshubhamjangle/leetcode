/*
Value_equal_to_index_value.cpp

Input: 
N = 5
Arr[] = {15, 2, 45, 12, 7}
Output: 2

Input: 
N = 1
Arr[] = {1}
Output: 1

Constraints:
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ 106

https://practice.geeksforgeeks.org/problems/value-equal-to-index-value1330/1
Method 1: if i+1 = arr[i]. add to vector. TC: O(N), SC: O(N)

*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
	vector<int> valueEqualToIndex(int arr[], int n) {
		vector<int> ans;
	    for(int i=0; i<n; i++) {
	    	if(arr[i] == i+1)
	    		ans.push_back(i+1);
	    }
	    return ans;
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.valueEqualToIndex(arr, n);
        if (ans.empty()) {
            cout << "Not Found";
        } else {
            for (int x: ans) {
                cout << x << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}