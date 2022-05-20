/*
Move all negative elements to end

Input : 
N = 8
arr[] = {1, -1, 3, 2, -7, -5, 11, 6 }
Output : 
1  3  2  11  6  -1  -7  -5

https://practice.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1

Move_all_negative_elements_to_end
Method 1: use temp array	time: O(3N), space: O(N)
	- copy negative elements to temp array then positive elements
	- copy the temp array to main array
Method 2: TC: O(N), SC: O(1)
	- two pointer approach

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // void segregateElements(int arr[],int n)
    // {
    // 	int temp[n];
    // 	int tempIndex = 0;
    // 	for(int i=0; i<n; i++) {
    // 		if(arr[i] >= 0) {
    // 			temp[tempIndex] = arr[i];
    // 			tempIndex++;
    // 		}
    // 	}
    // 	for(int i=0; i<n; i++) {
    // 		if(arr[i] < 0) {
    // 			temp[tempIndex] = arr[i];
    // 			tempIndex++;
    // 		}
    // 	}
    // 	for(int i=0; i<n; i++) {
    // 		arr[i] = temp[i];
    // 	}
    // }

    // Method 2: TC: O(N), SC: O(1)
	void segregateElements(int arr[],int n) {
    	if(n <= 0) return;

    	int i = 0;
    	int j = n-1;

    	while(i<j) {
    		if(arr[j] < 0) {
    			j--;
    			continue;
    		}
    		if(arr[i] >= 0) {
    			i++;
    			continue;
    		}
    		swap(arr[i], arr[j]);
    	}
    }
};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}