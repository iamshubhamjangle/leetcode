/*
Rearrange_Array_Alternately.cpp
https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1#
Method 1: Rearrange_Array_Alternately
	- take vector "v" loop until half and put the elements in arr[n-1-i] and arr[i]
	- time: O(N) and space: O(N) 

Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.

Example 1:

Input:
N = 6
arr[] = {1,2,3,4,5,6}
Output: 6 1 5 2 4 3
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
	void rearrange(long long *arr, int n) { 
		vector<int>v;
		for(int i=0;i<n/2+1;i++){
		   v.push_back(arr[n-1-i]);
		   v.push_back(arr[i]);
		}
		for(int i=0;i<n;i++)
		    arr[i]=v[i];
	}
};

int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 