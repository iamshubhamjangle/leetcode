/*
Sum_of_Middle_Elements_of_two_sorted_arrays.cpp

Given 2 sorted arrays Ar1 and Ar2 of size N each. 
Merge the given arrays and find the sum of the two middle elements of the merged array.

Input : N = 5, Ar1[] = {1, 2, 4, 6, 10}, Ar2[] = {4, 5, 6, 9, 12}
Output: 11

Input : N = 5, Ar1[] = {1, 12, 15, 26, 38}, Ar2[] = {2, 13, 17, 30, 45}
Output: 32

https://practice.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays2305/1
    - Method 1: two pointer diagonal merge & sort arr2. TC: N*NlogN. SC: O(1)
    - Method 2: using two pointer merge to new array. TC: O(N+M) SC: O(N)
    - Method 3: using two pointer and count. TC: O(N+M) SC: O(1)
     -Method 4: Binary Search. TC: O(logN). SC: O(1)

*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Method 1: two pointer diagonal merge & sort arr2. TC: N*NlogN. SC: O(1)
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

    // Method 2: using two pointer merge to new array. TC: O(N+M) SC: O(N)
    int findMidSum2(int arr1[], int arr2[], int n) {
        vector<int> ans;
        int m = n;
        int i = 0;
        int j = 0;

        while(i<n && j<n) {
            if(arr1[i] <= arr2[j]) {
                ans.push_back(arr1[i]);
                i++;
            } else {
                ans.push_back(arr2[j]);
                j++;
            }
        }

        while(i<n) {
            ans.push_back(arr1[i]);
            i++;
        }

        while(j<m) {
            ans.push_back(arr2[j]);
            j++;
        }

        int idx = (n+m) / 2;
        return (ans[idx] + ans[idx-1]);
    }

    // Method 3: using two pointer and count. TC: O(N+M) SC: O(1)
    int findMidSum(int arr1[], int arr2[], int n) {
        int m = n;
        int i = 0;
        int j = 0;
        int count = 0;
        int idx = (n+m) / 2;
        int sum = 0;

        while(i<n && j<n) {
            if(arr1[i] <= arr2[j]) {
                count++;
                if (count == idx) sum += arr1[i];
                if (count == idx + 1) {sum += arr1[i]; break;}
                i++;
            } else {
                count++;
                if (count == idx) sum += arr2[j];
                if (count == idx + 1) {sum += arr2[j]; break;}
                j++;
            }
        }

        while(i<n && count <= idx+1) {
            count++;
            if (count == idx) sum += arr1[i];
            if (count == idx + 1) {sum += arr1[i]; break;}
            i++;
        }

        while(j<m && count <= idx+1) {
            count++;
            if (count == idx) sum += arr2[j];
            if (count == idx + 1) {sum += arr2[j]; break;}
            j++;
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
        cout << "ans: " << ans << "\n";
    }
    return 0;
}