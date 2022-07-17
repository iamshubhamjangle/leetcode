/*
Partition_Equal_Subset_Sum.cpp

Given an array arr[] of size N, check if it can be partitioned into two parts such that 
the sum of elements in both parts is the same.

Input: N = 4, arr = {1, 5, 11, 5}
Output: YES

Input: N = 3, arr = {1, 3, 5}
Output: NO

https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int equalPartition(int n, int arr[]) {
        for(int i=0; i<n; i++) {
        	for(int j=0; j<n; j++) {
        		if(i==j) continue;

        	}
        } 
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}