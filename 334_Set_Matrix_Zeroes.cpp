/*
Set_Matrix_Zeroes.cpp

https://leetcode.com/problems/set-matrix-zeroes/
*/


class Solution {
public:
	// TC: O(N*M) + O(2N),  SC: O(2N)
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<bool> rows(n, false);    // is row zero?
        vector<bool> cols(m, false);    // is col zero?
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            if(rows[i]) {
                for(int col=0; col<m; col++) {
                    matrix[i][col] = 0;
                }
            }
        }
        
        for(int i=0; i<m; i++) {
            if(cols[i]) {
                for(int row=0; row<n; row++) {
                    matrix[row][i] = 0;
                }
            }
        }
    }
};


/// MEthod2 : TC: O(M*N) SC: O(1)
class Solution {
public:
void setZeroes(vector<vector<int>>& matrix) {
    bool RowZero = false;
    bool ColZero = false;
    //check the first row
    for (int i = 0; i < matrix[0].size(); i++) { 
        if (matrix[0][i] == 0) {
            RowZero = true;
            break;
        } 
    }

    //check the first column
    for (int i = 0; i < matrix.size(); i++) { 
        if (matrix[i][0] == 0) {
            ColZero = true;
            break;
        } 
    }

    //check except the first row and column
    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }        
        }
    }

	//process except the first row and column
    for (int i = 1; i < matrix.size(); i++) {
       for (int j = 1; j < matrix[0].size(); j++)
           if (matrix[i][0] == 0 || matrix[0][j] == 0)
               matrix[i][j] = 0;
    }

    //handle the first row
    if(RowZero) 
        for (int i = 0; i < matrix[0].size(); i++) 
            matrix[0][i] = 0;
    if (ColZero)
    	for (int i = 0; i < matrix.size(); i++)
            matrix[i][0] = 0;
    }
};