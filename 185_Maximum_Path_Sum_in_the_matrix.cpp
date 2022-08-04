/*
Maximum_Path_Sum_in_the_matrix.cpp

Input:
2
4 4
1 2 10 4
100 3 2 1
1 1 20 2
1 2 2 1
3 3
10 2 3
3 7 2
8 1 5

Output:
105
25

https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998
- Recursion. TC: O(3^n) SC: O(1) ASC: O(N)
- Memoisation. TC: O(n*n) SC: O(N*M) ASC: O(N)
- Tabulation. TC: O(n*m) SC: O(N*M)
- Space optimisation. TC: O(n*m) SC: O(M)


*/

#include <bits/stdc++.h>
using namespace std;

// // Recursion. TC: O(3^n) SC: O(1) ASC: O(N)
// int solve(int i, int j, int m, vector<vector<int>> &arr) {
// 	if(j < 0 || j >= m) return -1e9;	// If out of bound return min
// 	if(i == 0) return arr[i][j];		// base case reached 1st row arr[0][j]

// 	int up = arr[i][j] + solve(i-1, j, m, arr);
// 	int ld = arr[i][j] + solve(i-1, j-1, m, arr);
// 	int rd = arr[i][j] + solve(i-1, j+1, m, arr);

// 	return max(up, max(ld, rd));
// }

// int getMaxPathSum(vector<vector<int>> &matrix) {
// 	int n = matrix.size();
// 	int m = matrix[0].size();
// 	int maxi = INT_MIN;
	
// 	for(int j=0; j<m; j++) {
// 		int ans = solve(n-1, j, m, matrix);	// row = n-1, col = we will check from each column max sum
// 		maxi = max(maxi, ans);
// 	}

// 	return maxi;
// }

// // Memoisation. TC: O(n*n) SC: O(N*M) ASC: O(N)
// int solve(int i, int j, int m, vector<vector<int>> &arr, vector<vector<int>> &dp) {
// 	if(j < 0 || j >= m) return -1e9;	// If out of bound return min
// 	if(i == 0) return arr[i][j];		// base case reached 1st row arr[0][j]

// 	if(dp[i][j] != -1)
// 		return dp[i][j];

// 	int up = arr[i][j] + solve(i-1, j, m, arr, dp);
// 	int ld = arr[i][j] + solve(i-1, j-1, m, arr, dp);
// 	int rd = arr[i][j] + solve(i-1, j+1, m, arr, dp);

// 	return dp[i][j] = max(up, max(ld, rd));
// }

// int getMaxPathSum(vector<vector<int>> &matrix) {
// 	int n = matrix.size();
// 	int m = matrix[0].size();
// 	int maxi = INT_MIN;
// 	vector<vector<int>> dp(n, vector<int>(m, -1));

// 	for(int j=0; j<m; j++) {
// 		int ans = solve(n-1, j, m, matrix, dp);	// row = n-1, col = we will check from each column max sum
// 		maxi = max(maxi, ans);
// 	}

// 	return maxi;
// }


// // Tabulation. TC: O(n*m) SC: O(N*M)
// int getMaxPathSum(vector<vector<int>> &matrix) {
// 	int n = matrix.size();
// 	int m = matrix[0].size();
// 	vector<vector<int>> dp(n, vector<int>(m, 0));

// 	// base case
// 	for(int j=0; j<m; j++) {
// 		dp[0][j] = matrix[0][j];
// 	}

// 	for(int i=1; i<n; i++) {
// 		for(int j=0; j<m; j++) {	// for every possible i, j goes from 0 to m-1
// 			int up = matrix[i][j] + dp[i-1][j];
			
// 			int ld = matrix[i][j];
// 			if(j-1>=0) ld += dp[i-1][j-1];
// 			else ld += -1e9;

// 			int rd = matrix[i][j];
// 			if(j+1<m) rd += dp[i-1][j+1];
// 			else rd +=  -1e9;

// 			dp[i][j] = max(up, max(ld, rd));
// 		}
// 	}

// 	int maxi = dp[n-1][0]; 	// let assume max is in first col or last row
// 	for(int j=1; j<m; j++) {
// 		maxi = max(maxi, dp[n-1][j]);
// 	}

// 	return maxi;
// }


// Space optimisation. TC: O(n*m) SC: O(M)
int getMaxPathSum(vector<vector<int> > &matrix){
    
     int n = matrix.size();
    int m = matrix[0].size();
    
    vector<int> prev(m,0), cur(m,0);	// m as we only want to store column
    
    // Initializing first row - base condition
    for(int j=0; j<m; j++){
        prev[j] = matrix[0][j];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0;j<m;j++){
            
            int up = matrix[i][j] + prev[j];
            
            int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += prev[j-1];
            else leftDiagonal += -1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<m) rightDiagonal += prev[j+1];
            else rightDiagonal += -1e9;
            
            cur[j] = max(up, max(leftDiagonal,rightDiagonal));
            
        }
        
        prev = cur;
    }
    
    int maxi = INT_MIN;
    
    for(int j=0; j<m;j++){
        maxi = max(maxi,prev[j]);
    }
    
    return maxi;
}



int main(){
	int t;
	cin >> t;		//input no. of test cases
	while(t--){
		vector<vector<int>> matrix;

		int n, m; cin >> n >> m;
		for(int i=0; i<n; i++) {
			vector<int> temp;
			for(int j=0; j<m; j++) {
				int x; cin >> x;
				temp.push_back(x);
			}
			matrix.push_back(temp);
		}

		cout << getMaxPathSum(matrix) << endl;	//run this 't' times
	}
}
