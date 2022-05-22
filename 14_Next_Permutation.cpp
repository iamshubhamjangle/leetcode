/*
Next_Permutation 

Implement the next permutation, which rearranges the list of numbers into Lexicographically 
next greater permutation of list of numbers. If such arrangement is not possible, 
it must be rearranged to the lowest possible order i.e. sorted in an ascending order. 
You are given an list of numbers arr[] of size N.

Input: N = 6
arr = {1, 2, 3, 6, 5, 4}
Output: {1, 2, 4, 3, 5, 6}

https://practice.geeksforgeeks.org/problems/next-permutation5226/1

Method 1:  time: O(N), space: O(1)
    - find arr[i-1] < arr[i] from reverse.
    - reverse(arr[i], arr[n-1]);
    - while(l >= 0 && r < N){ if(arr[r] > arr[l]) {swap(arr[i], arr[i+1]); break;} r++}
*/



#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int i = N - 1;
        while(i > 0 && arr[i] <= arr[i - 1]){
            i--;
        }
        reverse(arr.begin() + i, arr.end());
        int l = i - 1, r = i;
        while(l >= 0 && r < N){
            if(arr[r] > arr[l]){
                swap(arr[l], arr[r]);
                break;
            }
            r++;
        }
        return arr;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}