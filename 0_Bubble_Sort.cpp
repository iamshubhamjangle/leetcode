/*
Bubble_Sort.cpp

Given an Integer N and a list arr. Sort the array using bubble sort algorithm.

Example 1:
Input : N = 5, arr[] = {4, 1, 3, 9, 7}
Output: 1 3 4 7 9

Example 2:
Input : N = 10, arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
Output: 1 2 3 4 5 6 7 8 9 10

https://practice.geeksforgeeks.org/problems/bubble-sort/1
	Method 1: TC: O(N-2 * N) SC: O(N)
        - while (n >= 0) swap if i > i+1
*/

// void swap2(int &a, int &b) {
// 	int temp = move( a );   
// 	a = move(b);       
// 	b = move(temp);
// }

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void bubbleSort(int arr[], int n) {
    	while(n >= 0) {
    		for(int i=0; i<=n-2; i++) {
    			if(arr[i] > arr[i+1])
    				swap(arr[i], arr[i+1]);
    		}
    		n--;
    	}
    }
};

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
int main() {
    int arr[1000],n,T,i;
    cin >> T;
    while(T--){
	    cin >> n;
	    for(i=0;i<n;i++)
	      cin >> arr[i];
	      
	    Solution ob;  
	      
	    ob.bubbleSort(arr, n);
	    printArray(arr, n);
    }
    return 0;;
}