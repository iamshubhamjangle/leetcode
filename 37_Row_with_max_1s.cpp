/*
Row_with_max_1s.cpp

Given a boolean 2D array of n x m dimensions where each row is sorted. 
Find the 0-based index of the first row that has the maximum number of 1's.

Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2

Input: 
N = 2, M = 2
Arr[][] = {{0, 0}, {1, 1}}
Output: 1

https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#
    - Method 1: Bruteforce O(N*M), space: O(1)
    - Method 2: 


*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Method 1: Bruteforce O(N*M), space: O(1)
	// int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
 //        pair<int,int> p = {-1, 0};    //pair of row, count

	//     for(int i=0; i<n; i++) {
 //            int count = 0;
 //            for(int j=0; j<m; j++) {
 //                if(arr[i][j] == 1) count++;
 //            }
 //            if(count > p.second) {
 //                p.first = i;
 //                p.second = count;
 //            }
 //        }

 //        return p.first;
	// }

    // Method 2: Travese from top right. TC: O(N+M), SC: O(1)
    // As the matrix is sorted. start from top left
    // Go left if you encounter 1
    // Go down if you encounter 0
    // Stop when you reach the last row or first column.
    int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
        int i = 0;      // row
        int j = m-1;    // column
        int row = -1;

        while(i < n && j >= 0) {
            if(arr[i][j] == 1) {
                j--;
                row = i;
            } else {
                i++;
            }
        }

        return row;
    }

};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}