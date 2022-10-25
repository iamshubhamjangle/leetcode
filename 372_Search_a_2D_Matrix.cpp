/*
Search_a_2D_Matrix.cpp

https://leetcode.com/problems/search-a-2d-matrix/
*/

class Solution {
public:
    // 1. Bruteforce. TC: O(m*n) SC: O(1)
//     // 2. Optimal - Check which row target exist and binary search on that row. TC: O(NlogN) SC: O(1)
//     bool isPresent(vector<int> &arr, int target) {
//         int n = arr.size();
//         int l = 0;
//         int h = n-1;
        
//         while(l <= h) {
//             int m = l + (h-l)/2;
//             if(arr[m] == target) {
//                 return true;
//             }
//             else if(arr[m] > target) {
//                 h = m - 1;
//             } 
//             else {
//                 l = m + 1;
//             }
//         }
        
//         return false;
//     }
    
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n = matrix.size();
//         int m = matrix[0].size();
        
//         for(int i=0; i<n; i++) {
//             if(target >= matrix[i][0] && target <= matrix[i][m-1]) {
//                 return isPresent(matrix[i], target);
//             }
//         }
        
//         return false;
//     }
    
    
    // Method 3: Thinking this as BST. starting from top-right corner.
    // TC: O(N) SC: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(),
			cols = matrix[0].size(),
            row = 0, col = cols - 1;
			
        while (row < rows && col > -1) {
            int cur = matrix[row][col];
            if (cur == target) return true;
            if (target > cur) row++;
            else col--;
        }
        
        return false;
    }
};