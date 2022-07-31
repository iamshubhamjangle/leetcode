/*
Unique_Paths.cpp

Input:
2
2 2
1 1

Output:
2
1

https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470
- Recursion. TC: O(2^(m*n)) SC: O(m*n) ASC: O((N-1)+(M-1))
- Memoisation. TC: O(M*N)  SC: O((N-1)+(M-1))
- Tabulation. TC: O(M*N) SC: O(M*N)
- Space Optimisation. TC: O(M*N) SC: O(N)

*/

#include <bits/stdc++.h>
using namespace std;

// Recursion. TC: O(2^(m*n)) SC: O(m*n) ASC: O((N-1)+(M-1))
/*
int solve(int m, int n) {
    if(m == 0 && n == 0)
        return 1;
    if(m < 0 || n < 0)
        return 0;
    
    int left  = solve(m, n-1);
    int up = solve(m-1, n);
    
    return left + up;
}

int uniquePaths(int m, int n) {
	return solve(m-1, n-1);
}
*/

// Memoisation. TC: O(M*N)  SC: O((N-1)+(M-1))
/*
int solve(int m, int n, vector<vector<int>> &dp) {
    if(m == 0 && n == 0)
        return 1;
    if(m < 0 || n < 0)
        return 0;
    
    if(dp[m][n] != -1) return dp[m][n];

    int left  = solve(m, n-1, dp);
    int up = solve(m-1, n, dp);
    
    return dp[m][n] = left + up;
}

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n,-1));
	return solve(m-1, n-1, dp);
}
*/


// Tabulation. TC: O(M*N) SC: O(M*N)
/*
int solve(int m, int n, vector<vector<int>> &dp) {
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(i==0 && j==0) {
				dp[i][j] = 1;
				continue;
			}

			int left = 0;
			int up = 0;

			if(i>0) up   = dp[i-1][j];
			if(j>0) left = dp[i][j-1];

			dp[i][j] = up + left;
		}
	}

	return dp[m-1][n-1];
}

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n,-1));
	return solve(m, n, dp);
}
*/

// Space Optimisation. TC: O(M*N) SC: O(N)
int uniquePaths(int m, int n) {
    vector<int> prev(n,0);
    for(int i=0; i<m; i++){
        vector<int> temp(n,0);
        for(int j=0; j<n; j++){
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
		int m,n;
		cin >> m >> n;
		cout << uniquePaths(m, n) << endl;	//run this 't' times
	}
}
