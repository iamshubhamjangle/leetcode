/*
Rotate_Image.cpp
*/


class Solution {
public:
    // TC: O(NM) SC: O(1)
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // swap lower left corner
        for(int row=0; row<n; row++) {
            for(int col=0; col<row; col++) {
                cout << row << " " << col << endl;
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        // reverse each row
        for(int row=0; row<n; row++) {
            reverse(matrix[row].begin(), matrix[row].end());
        }
    }
};