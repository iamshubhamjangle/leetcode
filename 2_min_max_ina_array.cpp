/*
Find minimum and maximum element in an array: 
Input:
N = 6
A[] = {3, 2, 1, 56, 10000, 167}
Output:
min = 1, max =  10000

https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1
Method 1: time: O(N), space: O(1)
	- assign min & max to first element
	- loop through array and check if element is greater/less then min & max. 

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}


pair<long long, long long> getMinMax(long long a[], int n) {
    long long maximum = a[0];
    long long minimum = a[0];

    for(int i=0; i<n; i++) {
    	if(a[i] > maximum) {
    		maximum = a[i];
    	} 
    	else if(a[i] < minimum) {
    		minimum = a[i];
    	}
    }

    return {minimum, maximum};
}