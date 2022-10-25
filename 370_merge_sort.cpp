/*
merge_sort.cpp

*/

#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r) {
	int n1 = m-l+1;
	int n2 = r-m;

	int arrL[n1], arrR[n2];	// two subarray of same size

	for(int i=0; i<n1; i++)	// copy elements into subarray from [l -> l+n1]
		arrL[i] = arr[l+i];

	for(int i=0; i<n2; i++)	// copy elements into subarray from [m+1 -> m+1+n2]
		arrR[i] = arr[m+1+i];

	int i = 0;	// arrL pointer
	int j = 0;	// arrR pointer
	int k = l;	// pointer to fill input arr from subarrays

	while(i < n1 && j < n2) {
		if(arrL[i] <= arrR[j]) {
			arr[k++] = arrL[i++];
		} else {
			arr[k++] = arrR[j++];
		}
	}

	// If i or j was exhaused above put the rest or arrL/arrR to arr
	while(i < n1) {
		arr[k++] = arrL[i++];
	}

	while(j < n2) {
		arr[k++] = arrR[j++];
	}
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
    	int m = l + (r-l)/2;	// find mid
    	mergeSort(arr, l, m);	// left subarray
    	mergeSort(arr, m+1, r);	// right subarray
    	merge(arr, l, m, r);	// merge
    }
}

void printArray(int arr[], int n) {
	for(int i=0; i<n; i++) cout << arr[i] << " ";
	cout << endl;
}

int main(){
	int arr[] = {10,9,8,7,6,5,4,3,2,1,0};
	int n = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, 0, n-1);
	printArray(arr, n);
}