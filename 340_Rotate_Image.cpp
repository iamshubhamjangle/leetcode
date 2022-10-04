/*
Rotate_Image.cpp

https://leetcode.com/problems/rotate-image/
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	int n = matrix.size();
    	int m = matrix[0].size();

    	for(int i=0; i<n; i++) {
    		for(int j=0; j<m-i-1; j++) {
    			swap(matrix[i][j], matrix[m-j-1][n-i-1]);
    		}
    	}

    	reverse(matrix.begin(), matrix.end());
    }
};