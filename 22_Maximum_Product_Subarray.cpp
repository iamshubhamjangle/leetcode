/*Maximum_Product_Subarray.cpp

Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.
Example 1:
Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180


*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

	// Bruteforce - O(N*N)
	// long long maxProduct(vector<int> arr, int n) {
	// 	long long product = 0;
	// 	for(int i=0; i<n; i++) {
	// 		long long localProduct = 1;
	// 		for(int j=i; j<n; j++) {
	// 			if(arr[j] == 0) break;
	// 			localProduct *= arr[j];
	// 			if(localProduct > product) product = localProduct;
	// 			if(localProduct < product && product == 0) product = localProduct;
	// 		}
	// 	}
	// 	return product;
	// }

    // O(N)
	long long maxProduct(vector<int> arr, int n) {
	    long long pref = 1, suff = 1, res = INT_MIN;
	    for(int i=0; i<n; i++) {
	        pref *= arr[i];
	        suff *= arr[n-i-1];
	        res = max(res, max(pref, suff));
	        if(pref == 0) pref = 1;
	        if(suff == 0) suff = 1;
	    }
	    return res;
	}

};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}