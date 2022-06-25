/*
Sum_of_Middle_Elements_of_two_sorted_arrays.cpp

Given 2 sorted arrays Ar1 and Ar2 of size N each. 
Merge the given arrays and find the sum of the two middle elements of the merged array.

Input : N = 5, Ar1[] = {1, 2, 4, 6, 10}, Ar2[] = {4, 5, 6, 9, 12}
Output: 11

Input : N = 5, Ar1[] = {1, 12, 15, 26, 38}, Ar2[] = {2, 13, 17, 30, 45}
Output: 32

https://practice.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays2305/1

*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Method 1: two pointer merge TC: NlogN. SC: O(1)
    int findMidSum1(int arr1[], int arr2[], int n) {
        int i = n-1;
        int j = 0;

        while(i >= j) {
            if(arr1[i] > arr2[j]) {
                swap(arr1[i], arr2[j]);
                sort(arr2, arr2 + n);
            } else {
                i--;
            }
        }

        sort(arr1, arr1 + n);
        return arr1[n-1] + arr2[0];
    }

    int findMidSum(int arr1[], int arr2[], int n) {
        int i=0;
        int j=0;
        int idx = (2*n)/2;  //so our median will be arr[idx] + arr[idx+1]
        int sum = 0;
        int count = 0;

        while(count <= idx) {
            if(arr1[i] <= arr2[j]) {
                if(count == idx-1 || count == idx) {
                    sum += arr1[i];
                }
                i++;
                count++;
            } else {
                if(count == idx-1 || count == idx) {
                    sum += arr2[j];
                }
                j++;
                count++;
            }
        }
        return sum;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}