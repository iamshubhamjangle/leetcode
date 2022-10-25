/*
Find_Missing_and_repeating_numbers.cpp

https://www.codingninjas.com/codestudio/problems/873366
*/

#include <bits/stdc++.h> 

// Method 0: Brute. Find each number frequency and if present or not.
// TC: O(N*N) SC: O(1)

// Method 1: Sort and check each element. 
// TC: O(NlogN) SC: O(1)
pair<int,int> missingAndRepeating(vector<int> &arr, int n) {
	sort(arr.begin(), arr.end());
    int count = 1;
    int repeated = 0;
    
    for(int i=0; i<n; i++) {
        if(count == arr[i]) {
            count++;
        }
        if(repeated == 0 && (i > 0) && arr[i] == arr[i-1]) {
            repeated = arr[i];
        }
    }

    return {count, repeated};
}
