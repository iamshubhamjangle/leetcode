/*
Search_a_2D_Matrix.cpp

https://leetcode.com/problems/search-a-2d-matrix/
*/

class Solution {
public:
	// Brute TC: O(N*M) SC: O(1)

	// Binary Search. TC: O(logNM) SC: O(1)

	// BST. TC: O(logH) SC: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	int i = 0;
    	int j = matrix[0].size()-1;

    	while(j >= 0 && i < matrix.size()) {
    		if(target == matrix[i][j])
    			return true;

			if(target < matrix[i][j]) {
				j--;
			} else {
				i++;
			}
    	}

    	return false;
    }
};