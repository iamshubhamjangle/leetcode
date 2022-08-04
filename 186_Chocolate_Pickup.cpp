/*
Chocolate_Pickup.cpp

Input:
2
3 4
2 3 1 2
3 4 2 2
5 6 3 5
2 2
1 1
1 2

Output:
21
5

https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885
- Recursion. TC: O(3^n) SC: O(1) ASC: O(N)
- Memoisation. TC: O(n*m*m*9) SC: O(n*m*m) ASC: O(N)

*/
/*
express everything in terms of index
explore all the paths
max sum
*/

#include <bits/stdc++.h>
using namespace std;


// // Recursion. TC: O(3^n) SC: O(1) ASC: O(N)
// int solve(int i, int j1, int j2, int r, int c, vector<vector<int>> &arr) {
// 	if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) {
// 		return -1e8;
// 	}

// 	if(i == r-1) {	// If we reach the last row
// 		if(j1 == j2)
// 			return arr[i][j1];	//  if both are at same pos take once
		
// 		return arr[i][j1] + arr[i][j2];	// else take both sum
// 	}

// 	// at each position we can go j1-1, j1, j1+1 and j2-1, j2, j2+1
// 	int maxi = INT_MIN;
// 	vector<int> dj = {-1, 0, +1};
// 	for(int ele1: dj) {
// 		for(int ele2: dj) {
// 			int ans = 0;
// 			if(j1 == j2) 
// 				ans = arr[i][j1] + solve(i+1, j1+ele1, j2+ele2, r, c, arr);
// 			else 
// 				ans = arr[i][j1] + arr[i][j2] + solve(i+1, j1+ele1, j2+ele2, r, c, arr);
// 			maxi = max(maxi, ans);
// 		}
// 	}

// 	return maxi;	
// }

// int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
//     return solve(0, 0, c-1, r, c, grid);	// i, j1, j2, rows, cols, grid
// }


// // Memoisation. TC: O(n*m*m*9) SC: O(n*m*m) ASC: O(N)
// int solve(int i, int j1, int j2, int r, int c, vector<vector<int>> &arr, vector<vector<vector<int>>> &dp) {
// 	if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) {
// 		return -1e8;
// 	}

// 	if(i == r-1) {	// If we reach the last row
// 		if(j1 == j2)
// 			return arr[i][j1];	//  if both are at same pos take once
		
// 		return arr[i][j1] + arr[i][j2];	// else take both sum
// 	}

// 	if(dp[i][j1][j2] != -1) {
// 		return dp[i][j1][j2];
// 	}

// 	// at each position we can go j1-1, j1, j1+1 and j2-1, j2, j2+1
// 	int maxi = INT_MIN;
// 	vector<int> dj = {-1, 0, +1};
// 	for(int ele1: dj) {
// 		for(int ele2: dj) {
// 			int ans = 0;
// 			if(j1 == j2) 
// 				ans = arr[i][j1] + solve(i+1, j1+ele1, j2+ele2, r, c, arr, dp);
// 			else 
// 				ans = arr[i][j1] + arr[i][j2] + solve(i+1, j1+ele1, j2+ele2, r, c, arr, dp);
// 			maxi = max(maxi, ans);
// 		}
// 	}

// 	return dp[i][j1][j2] = maxi;
// }

// int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
// 	vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (c, -1)));
//     return solve(0, 0, c-1, r, c, grid, dp);	// i, j1, j2, rows, cols, grid
// }


// // Tabulation. TC: O(n*m*m*9) SC: O(n*m*m)
// // Base case to up from cal n-1 then go from n-2 to 0
// int maximumChocolates(int n, int m, vector < vector < int >> & grid) {
//   vector <vector<vector<int>>> dp(n, vector<vector<int>> (m, 
//   vector <int>(m, 0)));

//   for (int j1 = 0; j1 < m; j1++) {
//     for (int j2 = 0; j2 < m; j2++) {
//       if (j1 == j2)
//         dp[n - 1][j1][j2] = grid[n - 1][j1];
//       else
//         dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
//     }
//   }

//   //Outer Nested Loops for travering DP Array
//   for (int i = n - 2; i >= 0; i--) {
//     for (int j1 = 0; j1 < m; j1++) {
//       for (int j2 = 0; j2 < m; j2++) {

//         int maxi = INT_MIN;

//         //Inner nested loops to try out 9 options
//         for (int di = -1; di <= 1; di++) {
//           for (int dj = -1; dj <= 1; dj++) {

//             int ans;

//             if (j1 == j2)
//               ans = grid[i][j1];
//             else
//               ans = grid[i][j1] + grid[i][j2];

//             if ((j1 + di < 0 || j1 + di >= m) ||
//               (j2 + dj < 0 || j2 + dj >= m))

//               ans += -1e9;
//             else
//               ans += dp[i + 1][j1 + di][j2 + dj];

//             maxi = max(ans, maxi);
//           }
//         }
//         dp[i][j1][j2] = maxi;
//       }
//     }
//   }

//   return dp[0][0][m - 1];
// }


// Space Optimisation. TC: O(N*M*M)*9, SC: O(M*M)
int maximumChocolates(int n, int m, vector < vector < int >> & grid) {
  vector < vector < int >> front(m, vector < int > (m, 0)), cur(m, vector < int > 
  (m, 0));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        front[j1][j2] = grid[n - 1][j1];
      else
        front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  //Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {

        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += front[j1 + di][j2 + dj];

            maxi = max(ans, maxi);

          }
        }
        cur[j1][j2] = maxi;
      }
    }
    front = cur;
  }

  return front[0][m - 1];
}


int main(){
	int t;
	cin >> t;		//input no. of test cases
	while(t--){
		int n, m; cin>>n>>m;
		vector<vector<int>> grid;
		for(int i=0; i<n; i++) {
			vector<int> temp;
			for(int j=0; j<m; j++) {
				int x; cin>>x;
				temp.push_back(x);
			}
			grid.push_back(temp);
		}
		cout << maximumChocolates(n, m, grid) << endl;	//run this 't' times
	}
}



