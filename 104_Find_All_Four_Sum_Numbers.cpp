/*
Find_All_Four_Sum_Numbers.cpp

Given an array of integers and another number. Find all the unique quadruple from the 
given array that sums up to the given number.

Input : N = 5, K = 3, A[] = {0,0,2,1,1}
Output: 0 0 1 2 $
Explanation: Sum of 0, 0, 1, 2 is equal to K.

Input : N = 7, K = 23, A[] = {10,2,3,4,5,7,8}
Output: 2 3 8 10 ---- 2 4 7 10 ---- 3 5 7 8 $
Explanation: Sum of 2, 3, 8, 10 = 23, sum of 2, 4, 7, 10 = 23 and sum of 3, 5, 7, 8 = 23.

Expected Time Complexity: O(N3).
Expected Auxiliary Space: O(N2).

Constraints:
1 <= N <= 100
-1000 <= K <= 1000
-100 <= A[] <= 100

https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1
Method 1: Bruteforce. TC: O(N^4) SC: O(N*N)
	- sort() input as output needs sorting
	- i = 0 to n, j = i+1 to n, k = j to n, l = k+1 to n
	- keep a sum in last loop. if sum == K.
	- temp.push_back(i, j, k, l); ans.push(temp);

Method 2: Loop 2 times and Binary Search. TC: O(N^3) SC: O(N*N)
	- sort(); [2 3 4 5 7 8 10]
	- iterate 2 times. for third(low) & forth(high) element do binary search.
	- if sum == k, add it to a set to avoid duplicates
	- at end copy the set to ans vector.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        set <vector<int>> s;
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                int start = j+1;
                int end = n-1;
                while (start < end)
                {
                    int sum = arr[i]+arr[j]+arr[start]+arr[end];
                    if (sum == k) {
                        s.insert({arr[i],arr[j],arr[start],arr[end]});
                        start++;
                        end--;
                    } else if (sum > k) {
                        end--;
                    } else  {
                        start++;
                    }
                }
            }
        }

        for(auto i:s)
            ans.push_back(i);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}