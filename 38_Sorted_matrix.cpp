/*
Sorted_matrix.cpp

Given an NxN matrix Mat. Sort all elements of the matrix.

Input:
N=4
Mat=[[10,20,30,40],
[15,25,35,45] 
[27,29,37,48] 
[32,33,39,50]]
Output:
10 15 20 25 
27 29 30 32
33 35 37 39
40 45 48 50

https://practice.geeksforgeeks.org/problems/sorted-matrix/0
    - Method 1: TC: O(N*N), SC: O(N*N)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Method 1: TC: O(N*N), SC: O(N*N)
    vector<vector<int>> sortedMatrix(int n, vector<vector<int>> arr) {
        vector<int> v;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                v.push_back(arr[i][j]);
            }
        }

        sort(v.begin(), v.end());

        int k = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                arr[i][j] = v[k++];
            }
        }

        return arr;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}