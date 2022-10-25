/*
Count_Inversions.cpp

https://www.codingninjas.com/codestudio/problems/615
*/

#include <bits/stdc++.h>
using namespace std;

void merge(long long arr[], int l, int m, int r, long long &count) {
    int n1 = m-l+1;
    int n2 = r-m;

    int arrL[n1], arrR[n2];    // two subarray of same size

    for(int i=0; i<n1; i++)    // copy elements into subarray from [l -> l+n1]
        arrL[i] = arr[l+i];

    for(int i=0; i<n2; i++)    // copy elements into subarray from [m+1 -> m+1+n2]
        arrR[i] = arr[m+1+i];

    int i = 0;    // arrL pointer
    int j = 0;    // arrR pointer
    int k = l;    // pointer to fill input arr from subarrays

    while(i < n1 && j < n2) {
        if(arrL[i] <= arrR[j]) {
            arr[k++] = arrL[i++];
        } else {
            arr[k++] = arrR[j++];
            count += (n1-i);			// ******************* ADDED IN MERGE SORT ******************* //
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

void mergeSort(long long arr[], int l, int r, long long &count) {
    if(l < r) {
        int m = l + (r-l)/2;    // find mid
        mergeSort(arr, l, m, count);    // left subarray
        mergeSort(arr, m+1, r, count);    // right subarray
        merge(arr, l, m, r, count);    // merge
    }
}

long long getInversions(long long *arr, int n){
    long long count = 0;
    mergeSort(arr, 0, n-1, count);
    return count;
}