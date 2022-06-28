/*
First_element_to_occur_k_times.cpp

Given an array of N integers. Find the first element that occurs atleast K number of times.

Input :
N = 7, K = 2
A[] = {1, 7, 4, 3, 4, 8, 7}
Output :
4

Constraints:
1 <= N, K <= 105
1<= A <= 106

https://practice.geeksforgeeks.org/problems/first-element-to-occur-k-times5150/1


*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int firstElementKTime(int a[], int n, int k) {\
    	unordered_map<int, int> um;
		for(int i=0; i<n; i++) {
			um[a[i]]++;
			if(um[a[i]] >= k) {
				return a[i];
			}
		}
		return -1;
    }
};

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution ob;
	    cout<<ob.firstElementKTime(a, n, k)<<endl;
	}
	
	return 0;
}