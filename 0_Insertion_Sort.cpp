/*
Insertion_Sort.cpp

Example 1:
Input : N = 5, arr[] = { 4, 1, 3, 9, 7}
Output:1 3 4 7 9

Example 2:
Input: N = 10, arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
Output:1 2 3 4 5 6 7 8 9 10

https://practice.geeksforgeeks.org/problems/insertion-sort/1
Method: TC: O(N*N)	SC: O(1)
	- loop i from 1 position, backup current
	- loop j from i-1 till 0. if(current < j+1) arr[j+1] = arr[j]
*/
#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


class Solution {
    public:
    // Method: TC: O(N*N)	SC: O(1)
    //	- loop i from 1 position, backup current
    //	- loop j from i-1 till 0. if(current < j+1) arr[j+1] = arr[j]
    void insertionSort(int arr[], int n) {
        for(int i=1; i<n; i++) {
        	int current = arr[i];
        	int j;

        	for(j = i-1; j>=0; j--) {
        		if(current < arr[j]) {
        			arr[j+1] = arr[j];
        		} else {
					break;        			
        		}
        	}

        	arr[j+1] = current;
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
	    ob.insertionSort(arr, n);
	    printArray(arr, n);
    }
    return 0;
}