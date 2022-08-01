/*
Unique_Paths_II.cpp

Input:
2    
2 2
0 0
0 0
3 3
0 0 0 
0 -1 0 
0 0 0

Output:
2
2

https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241
Method: DP.

*/

#include <bits/stdc++.h>
using namespace std;

// Recursion. TC: O(2^(m*n)) SC: O(1) ASC: O(N)
// int solve(int i, int j, vector<vector<int>> &mat) {
//     if(i<0 || j<0 || mat[i][j] == -1)
//         return 0;
    
//     if(i == 0 && j == 0)
//     	return 1;

//     int left = solve(i, j-1, mat);
//     int up   = solve(i-1, j, mat);
    
//     return left + up;
// }

// int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
//     return solve(n-1, m-1, mat);
// }



// // Memoisation. TC: O(m*n) SC: O(m-1*n-1) ASC: O(m+n)
// int mod = 1e9 + 7;

// int solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp) {
//     if(i<0 || j<0 || mat[i][j] == -1)
//         return 0;
    
//     if(i == 0 && j == 0)
//     	return 1;

//     if(dp[i][j] != -1) return dp[i][j];

//     int left = solve(i, j-1, mat, dp);
//     int up   = solve(i-1, j, mat, dp);
    
//     return dp[i][j] = (left + up) % mod;
// }

// int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
//     vector<vector<int>> dp(n, vector<int> (m, -1));
//     return solve(n-1, m-1, mat, dp);
// }


// // Tabulation TC: O(N*M) SC: O(N*M)
// int mod = int(1e9 + 7);
// int solve(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp) {
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(mat[i][j]==-1)
//             	dp[i][j]=0;
//             else if(i==0 && j==0)
//             	dp[0][0]=1;
//             else{
//                 int a=0,b=0;
//                 if(i>0)a=dp[i-1][j];
//                 if(j>0)b=dp[i][j-1];
//                 dp[i][j]=(a+b)%mod;
//             }
//         }
//     }
//     return dp[n-1][m-1];
// }

// int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
//     vector<vector<int>> dp(n, vector<int> (m, 0));
//     return solve(n, m, mat, dp);
// }


// Space Optimized: TC: O(N*M). SC: O(N)
int mazeObstacles(int n, int m, vector<vector<int> > &maze){
    vector<int> prev(m,0);
    for(int i=0; i<n; i++){
        vector<int> temp(m,0);
        for(int j=0; j<m; j++){
            if(i>0 && j>0 && maze[i][j]==-1){
                temp[j]=0;
                continue;
            }
            if(i==0 && j==0){
                temp[j]=1;
                continue;
            }
            
            int up=0;
            int left =0;
            
            if(i>0)
                up = prev[j];
            if(j>0)
                left = temp[j-1];
                
            temp[j] = up + left;
        }
        prev = temp;
    }
    
    return prev[n-1];
}

int main(){
	int t;
	cin >> t;		//input no. of test cases
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> mat;

		for(int i=0; i<n; i++) {
			vector<int> temp;
			for(int j=0; j<m; j++) {
				int x; cin >> x;
				temp.push_back(x);
			}
			mat.push_back(temp);
		}

		cout << mazeObstacles(n, m, mat) << endl;	//run this 't' times
	}
}
