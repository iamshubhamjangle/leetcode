// Set_Matrix_Zeroes.cpp
// DSA Day 1: Q1

class Solution {
public:
    // TC: O(NM) SC: O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();          // # of rows
        int n = matrix[0].size();       // # of cols
        bool isRowZero = false;
        bool isColZero = false;

        for(int col=0; col<n; col++) {
            if(matrix[0][col] == 0) {
                isRowZero = true;
                break;
            }
        }

        for(int row=0; row<m; row++) {
            if(matrix[row][0] == 0) {
                isColZero = true;
                break;
            }
        }

        // Find zero and mark the corresponding column and row header to zero;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;   // first row
                    matrix[i][0] = 0;   // first col
                }
            }
        }

        // loop through matrix and check if zero present in corresponding row/col
        // If yes mark the current as zero
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if(isRowZero) {
            for(int col=0; col<n; col++) {
                matrix[0][col] = 0;
            }
        }

        if(isColZero) {
            for(int row=0; row<m; row++) {
                matrix[row][0] = 0;
            }
        }
    }
};