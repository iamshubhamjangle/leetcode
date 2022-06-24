/*
Find_Pair_Given_Difference.cpp

Given an array Arr[] of size L and a number N, you need to write a program 
to find if there exists a pair of elements in the array whose difference is N.

Input : L = 6, N = 78, arr[] = {5, 20, 3, 2, 5, 80}
Output: 1
Explanation: (2, 80) have difference of 78.

Input : L = 5, N = 45, arr[] = {90, 70, 20, 80, 50}
Output: -1
Explanation: There is no pair with difference of 45.

https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1
	Method 1: Bruteforce. TC: O(n*n) SC: O(1)
	Method 2: BinarySearch. TC: O(n*logn) SC: O(1)
*/

#include<bits/stdc++.h>
using namespace std; 

// // Bruteforce TC: O(n*n) SC: O(1) - time: 0.13/1.07
// bool findPair1(int arr[], int size, int n){
//     for(int i=0; i<size; i++) {
//     	for(int j=i+1; j<size; j++) {
//     		if(abs(arr[j] - arr[i]) == n)
//     			return true;
//     	}
//     }

//     return false;
// }



bool findPair(int arr[], int size, int n){
   sort(arr,arr+size);
   for(int i=0;i<size;i++){
       int find=arr[i]+n;
       int start=i+1;
       int end=size-1;
       int mid=start+(end-start)/2;
       while(start<=end){
           if(arr[mid]==find)return true;
           else if(arr[mid]>find) end=mid-1;
           else start=mid+1;
           mid=start+(end-start)/2;
       }
   }
   return false;
   }

int main() {
    int t;
    cin>>t;
    while(t--) {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}