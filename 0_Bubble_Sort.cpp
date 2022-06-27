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
#include <bits/stdc++.h>
using namespace std;

void mySwap2(int &a, int &b) {
	int temp = move(a);   
	a = move(b);       
	b = move(temp);
}

void mySwap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

class Solution {
    public:
    void bubbleSort(int arr[], int n) {
        for(int i=0; i<n-1; i++) {
            bool swapped = false;
            for(int j=0; j<n-i-1; j++) {
                if(arr[j] > arr[j+1]) {
                    swapped = true;
                    swap(arr[j], arr[j+1]);
                    // mySwap(arr, j, j+1);
                    // mySwap2(arr[j], arr[j+1]);
                }
            }
            if(!swapped)
                break;
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