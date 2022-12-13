/*
Minimum_Falling_Path_Sum.cpp

https://leetcode.com/problems/minimum-falling-path-sum/
*/

// //Brute force TLE
// class Solution {
// public:
// 	int solve(vector<vector<int>>& matrix, int r, int c) {
//         if(r == 0 and c < matrix[0].size() and c >= 0) return matrix[r][c]; 
//         if(c >= matrix[0].size() or c < 0) return INT_MAX;
        
//         int left  = solve(matrix, r-1, c+1);
//         int right = solve(matrix, r-1, c);
//         int mid   = solve(matrix, r-1, c-1);
        
//         return matrix[r][c] + min({left, right, mid});
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int rows = matrix.size(), cols = matrix[0].size();
//         int ans = INT_MAX;
//         for(int c=0; c < cols; c++) {
//             ans = min(ans, solve(matrix, rows-1, c));
//         }
//         return ans;
//     }
// };


// // Memoisation
// class Solution {
// public:
// 	int solve(vector<vector<int>>& matrix, int r, int c, vector<vector<int>> &dp) {
//		   if(r == 0 and c >= 0 and c < matrix[0].size()) return matrix[r][c]; 
//         if(c >= matrix[0].size() or c < 0) return INT_MAX;
        
//         if(dp[r][c] != INT_MAX) return dp[r][c];

//         int left  = solve(matrix, r-1, c+1, dp);
//         int right = solve(matrix, r-1, c, dp);
//         int mid   = solve(matrix, r-1, c-1, dp);
        
//         return dp[r][c] = matrix[r][c] + min({left, right, mid});
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int rows = matrix.size(); 
//         int cols = matrix[0].size();

//         int ans = INT_MAX;
//         vector<vector<int>> dp(rows+1, vector<int>(cols+1, INT_MAX));

//         for(int c=0; c < cols; c++) {
//             ans = min(ans, solve(matrix, rows-1, c, dp));
//         }
//         return ans;
//     }
// };


// // Tabulation
// class Solution {
// public:
//     int customMin(int a, int b, int c){
//         return min(a,min(b,c));
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int rows = matrix.size(), cols = matrix[0].size();
//         int ans = INT_MAX;
        
//         for(int r=1; r < rows; r++){
//             for(int c=0; c < cols; c++){
//                 int leftD, middle, rightD;               
//                 if(c == 0){
//                     rightD = matrix[r-1][c+1];
//                     middle = matrix[r-1][c];
//                     matrix[r][c] += min(rightD, middle);
//                 }else if(c == cols-1){
//                     leftD = matrix[r-1][c-1];
//                     middle = matrix[r-1][c];
//                     matrix[r][c] += min(leftD, middle);
//                 }else{
//                     leftD = matrix[r-1][c+1];
//                     middle = matrix[r-1][c];
//                     rightD = matrix[r-1][c-1];
//                     matrix[r][c] += customMin(leftD, rightD, middle);
//                 } 
//             }
//         }
//         for(int c=0; c < cols; c++){
//             ans = min(ans, matrix[rows-1][c]);
//         }
//         return ans;
//     }
// };


// // Elegant
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& A) {
// 		int n = A.size();
// 		for (auto i = 1; i < n; ++i)
// 			for (auto j = 0; j < n; ++j)
// 				A[i][j] += min({ A[i-1][j], A[i-1][max(0,j-1)], A[i-1][min((int)n-1,j+1)] });
// 		return *min_element(begin(A[n - 1]), end(A[n - 1]));
// 	}
// };
