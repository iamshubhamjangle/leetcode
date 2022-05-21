/*
Minimize_the_Heights_II.cpp

Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once. After modifying, height should be a non-negative integer. 
Find out the minimum possible difference of the height of shortest and longest towers after you have modified each tower.

Note: It is compulsory to increase or decrease by K to each tower.

Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5

Input:
K = 3, N = 5
Arr[] = {3, 9, 12, 16, 20}
Output:
11

Method 1: time: O(N log N), space: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
       sort(arr,arr+n);
       int diff=arr[n-1]-arr[0];
       
       int least,most,mini,maxi;
       least=arr[0]+k;
       most=arr[n-1]-k;
       
       for(int i=0;i<n-1;i++){
           mini=min(arr[i+1]-k,least);
           maxi=max(arr[i]+k,most);
           
           if(mini<0)
               continue;
           else 
               diff=min(diff,maxi-mini);
       }
       return diff;
    }

    // Method 2
    // int getMinDiff(int arr[], int n, int k)
    // {
    //     sort(arr, arr + n);
    //     int ans = arr[n - 1] - arr[0]; // Maximum possible height difference

    //     int tempmin, tempmax;
    //     tempmin = arr[0];
    //     tempmax = arr[n - 1];

    //     for (int i = 1; i < n; i++) {
    //         if(arr[i] - k < 0) // if on subtracting k we got negative then continue 
    //         continue;
    //         tempmin= min(arr[0] + k,arr[i] - k); // Minimum element when we
    //                                                 // add k to whole array
    //         tempmax = max(arr[i - 1] + k, arr[n - 1] - k); // Maximum element when we
    //                                                          // subtract k from whole array
    //         ans = min(ans, tempmax - tempmin); 
    //     }
    //     return ans;
    // }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}