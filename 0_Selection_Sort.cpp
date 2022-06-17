/*
Selection_Sort.cpp

https://practice.geeksforgeeks.org/problems/selection-sort/1#
Method 1: TC: O(N*N), SC: O(1)
	- loop over the array, let curr be i
	- Find min from i+1, end
	- swap(i+1, minIndex)
*/

#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 

class Solution
{
    public:
    int minimumInRange(int arr[], int start, int end) {
    	int minIndex = start;
    	for(int i=start; i<=end; i++) {
    		if(arr[i] < arr[minIndex])
    			minIndex = i;
    	}
    	return minIndex;
    }


    void selectionSort(int arr[], int n) {
       	if(n <= 1) return;

       	int start = 0;
       	int end = n-1;

       	while(start < end) {
       		int minIndex = minimumInRange(arr, start+1, end);
       		if(arr[start] > arr[minIndex]) {
       			swap(arr[start], arr[minIndex]);
       		}
       		start++;
       	}
    }
};



int main()
{
    int arr[1000],n,T,i;
    cin >> T;
    while(T--){
	    cin >> n;
	    for(i=0;i<n;i++)
	      cin >> arr[i];
	      
	    Solution ob;  
	    ob.selectionSort(arr, n);
	    printArray(arr, n);
    }
    return 0;
}