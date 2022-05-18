/*
Max_rectangle.cpp

Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8

https://practice.geeksforgeeks.org/problems/max-rectangle/1
    - Method 1: 


*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
    }
};

int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}