/*
Rotate_Image.cpp

https://leetcode.com/problems/rotate-image/
*/


#include <bits/stdc++.h>
using namespace std;

// Print vector of vector
void print(vector<vector<int>> &v) {
  cout << "[" << endl;
  for(auto i: v) { cout << "["; for(auto j: i) cout << j << ","; cout << "]" << endl; }
  cout << "]" << endl;
}

// // rotate image 90deg (CW). TC: O(N*M) SC: O(1)
// void rotate(vector<vector<int>>& matrix) {
//     int n = matrix.size();
//     int m = matrix[0].size();
    
//     for(int row=0; row<n; row++) {
//         for(int col=0; col<row+1; col++) {
//             swap(matrix[row][col], matrix[col][row]);
//         }
//     }

//     for(int row=0; row<n; row++) {
//     	reverse(matrix[row].begin(), matrix[row].end());
//     }
// }

// // rotate image -90deg (ACW)
// void rotate(vector<vector<int>>& matrix) {
// 	int n = matrix.size();
// 	int m = matrix[0].size();

// 	for(int row=0; row<n; row++) {	// visit all rows
// 		for(int col=0; col<m-row-1; col++) {
// 			swap(matrix[row][col], matrix[n-col-1][m-row-1]);
// 		}
// 	}

// 	for(int row=0; row<n; row++) {
// 		reverse(matrix[row].begin(), matrix[row].end());
// 	}
// }


int main(){
	vector<vector<int>> matrix;
	matrix = {{1,2,3},{4,5,6},{7,8,9}};
	print(matrix);
	rotate(matrix);
	print(matrix);
}