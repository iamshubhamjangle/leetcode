/*
Toeplitz_Matrix.cpp

https://leetcode.com/problems/toeplitz-matrix/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
        return true;
    }
};

int main(){
	Solution s;

	vector<vector<int>> matrix;

	matrix = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
	cout << s.isToeplitzMatrix(matrix) << endl;
	
	matrix = {{11,74,0,93},{40,11,74,7}};
	cout << s.isToeplitzMatrix(matrix) << endl;
	
}