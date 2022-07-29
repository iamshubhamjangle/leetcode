/*
Rat in a Maze Problem - I

Input: N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR

Input: N = 2
m[][] = {{1, 0},
         {1, 0}}
Output: -1

https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
Method: Backtracking. TC: O((3N^2))  SC: O(L*X), L = length of the path, X = number of paths.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<string> ans;
    
    void solve(int i, int j, vector<vector<int>> &m, int n, string ds) {
        if(i < 0 || j < 0 || i >= n || j >= n || m[i][j] == 0) {     // if we are beyond boundary / current is blocked = 0
            return;
        }

        if(i == n-1 && j == n-1) {      // If we reached the end
            ans.push_back(ds);
            ds = "";
            return;
        }

        m[i][j] = 0;                    // set current visited so it wont picked up next time
        solve(i, j+1, m, n, ds + "R");
        solve(i, j-1, m, n, ds + "L");
        solve(i+1, j, m, n, ds + "D");
        solve(i-1, j, m, n, ds + "U");
        m[i][j] = 1;                    // backtrack it to 1
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string ds = "";
        if(m[0][0] == 0 || m[n-1][n-1] == 0)    // If we cannot start at first position or end
            return {};
        solve(0, 0, m, n, ds);
        return ans;
    }
};

    
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends