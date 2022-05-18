/*
Rotate_by_90_degree.cpp

Given a square matrix[][] of size N x N. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space.

Input:
N = 3
matrix[][] = [[1 2 3],
              [4 5 6],
              [7 8 9]]
Output:
3 6 9 
2 5 8 
1 4 7

https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1
	Method 1: swap and reverse. TC: O(N*N), SC: O(1) 


*/


#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */

// Method 1: swap and reverse. TC: O(N*N), SC: O(1) 
// void rotate(vector<vector<int> >& matrix) {
// 	int n = matrix.size();
// 	for(int i=0; i<n; i++) {
// 		for(int j=0; j<=i; j++) {
// 			swap(matrix[i][j], matrix[j][i]);
// 		}
// 	}

// 	reverse(matrix.begin(), matrix.end());
// }


// if space is not an issue
void rotate(vector<vector<int>>& matrix) {
    vector<vector<int>> temp(matrix);
    int size=matrix.size();
    for(int i=0;i<size;i++)
        for(int j=0; j<size;j++)
            matrix[i][j] = temp[j][size-i-1];
}

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}