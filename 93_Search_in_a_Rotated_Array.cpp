/*
Search_in_a_Rotated_Array.cpp

Given a sorted and rotated array A of N distinct elements which is rotated at some point, 
and given an element key. The task is to find the index of the given element key in the array A.

Input : N = 9, A[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}, key = 10
Output: 5

Input : N = 4, A[] = {3, 5, 1, 2}, key = 6
Output: -1

https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1
    Method: Binary Search Approach. TC: O(log N) SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int search(int A[], int l, int h, int key){
        while(l <= h) {
            int mid = l + (h - l)/2;
            if(A[mid] == key) {
                return mid;
            }
            else if(A[l] <= A[mid]) {
                if(key >= A[l] and key <= A[mid]) {
                    h = mid - 1;
                }
                else l = mid + 1;
            } else {
                if(key >= A[mid] and key <= A[h]) {
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}