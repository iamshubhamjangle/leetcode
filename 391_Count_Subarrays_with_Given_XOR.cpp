/*
Count_Subarrays_with_Given_XOR.cpp

https://www.codingninjas.com/codestudio/problems/1115652
*/

#include <bits/stdc++.h>
using namespace std;

// Brute: TC: O(N^2) SC: O(1)
int _subarraysXor(vector<int> &arr, int x) {
    int n = arr.size();
    int count = 0;
    
    for(int i=0; i<n; i++) {
        int _xor = 0;
        for(int j=i; j<n; j++) {
            _xor ^= arr[j];				// use j here remember
            if(_xor == x) count++;
        }
    }
    
    return count;
}

// Optimal. TC: O(N) SC: O(N)
int subarraysXor(vector<int> &arr, int x) {
    int xr = 0;
    int count = 0;
    map<int,int> mp;

    for(int i=0;i<arr.size();i++){
        xr ^=arr[i];
        if(xr == x) count++;
        if(mp.find(xr ^ x) != mp.end()) 
        	count += mp[xr ^ x];
        mp[xr]++;

    }

    return count;

}