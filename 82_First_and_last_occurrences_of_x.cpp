/*
First_and_last_occurrences_of_x.cpp

Given a sorted array arr containing n elements with possibly duplicate elements, 
the task is to find indexes of first and last occurrences of an element x in the given array.

Input : n=9, x=5, arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output: 2 5

Input : n=9, x=7, arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
Output:  6 6

https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
    - Method 1: Loop over and find first second. TC: O(N), SC: O(1)
    - Method 2: Binary search. TC: O(log N), SC: O(N)

*/

#include<bits/stdc++.h>
using namespace std;

// Method 1: Loop over and find first second. TC: O(N), SC: O(1)
vector<int> find1(int arr[], int n , int x ) {
    int first = -1;
    int second = -1;

    for(int i=0; i<n; i++) {
        if(first == -1 && arr[i] == x) {
            first = i;
        }
        if(first != -1 && arr[i] == x) {
            second = i;
        }
    }

    if(first == -1) return {-1, -1};

    if(second == -1) return {first, first};

    return {first, second};
}

// Method 2: Binary search. TC: O(log N), SC: O(N)
/* if x is present in arr[] then returns the index of
   FIRST occurrence of x in arr[0..n-1], otherwise
   returns -1 */
int first(int arr[], int low, int high, int x, int n) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return first(arr, (mid + 1), high, x, n);
        else
            return first(arr, low, (mid - 1), x, n);
    }
    return -1;
}
 
/* if x is present in arr[] then returns the index of
   LAST occurrence of x in arr[0..n-1], otherwise
   returns -1 */
int last(int arr[], int low, int high, int x, int n) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == n - 1 || x < arr[mid + 1]) && arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            return last(arr, low, (mid - 1), x, n);
        else
            return last(arr, (mid + 1), high, x, n);
    }
    return -1;
}


vector<int> find(int arr[], int n , int x ) {
    int f = first(arr, 0, n - 1, x, n);
    int l = last(arr, 0, n - 1, x, n);

    return {f, l};
}


// Method 3: Using STL binary_search TC: O(log n) SC: O(1)
vector<int> find(int arr[], int n , int x ) {
    // edge case if x dont exist in arr
    if(!binary_search(arr, arr+n, x))
        return {-1,-1};
    
    int first = -1;
    int last = -1;
    
    first = lower_bound(arr, arr+n, x) - arr;
    last = upper_bound(arr, arr+n, x) - arr - 1;
    
    return {first, last};
}


int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}