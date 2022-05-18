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
Method 1: use maxHistogram - TC: O(m*n), SC: O(N)
    - use maxHistogram to solve by adding each row and calulating maxArea


*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution{
  public:
    // Method 1: use maxHistogram - TC: O(m*n), SC: O(N)
    // - use maxHistogram to solve by adding each row and calulating maxArea
    int maxHistogram(int arr[], int n) {
        vector<int> l(n), r(n);
        stack<int> st;

        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) 
             st.pop();
            l[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) 
         st.pop();
        
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) 
             st.pop();
            r[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int res=0;
        for(int i=0; i<n; i++)
            res = max(res, arr[i] * (r[i]-l[i]-1));
        return res;
    }

    int maxArea(int M[MAX][MAX], int n, int m) {
        int res = maxHistogram(M[0],m);
        for(int i = 1; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(M[i][j] == 1) M[i][j]+= M[i-1][j];
            }
            res= max(res, maxHistogram(M[i],m));
        }
        return res;
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