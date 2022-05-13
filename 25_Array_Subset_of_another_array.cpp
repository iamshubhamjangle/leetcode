/*
Array_Subset_of_another_array.cpp

Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted.

Input: a1[] = {11, 1, 13, 21, 3, 7}, a2[] = {11, 3, 7, 1}
Output: Yes

Input: a1[] = {1, 2, 3, 4, 5, 6}, a2[] = {1, 2, 4}
Output: Yes

Input: a1[] = {10, 5, 2, 23, 19}, a2[] = {19, 5, 3}
Output: No

https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1#
Method 1: unordered_map, check element exist in um. time: O(N), space: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> um;

    for(int i=0; i<n; i++ ){
    	um[a1[i]]++;
    }

    for(int j=0; j<m; j++) {
    	if(um[a2[j]] > 0) continue;
    	return "No";
    }

    return "Yes";
}