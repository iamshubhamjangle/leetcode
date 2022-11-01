/*
Where_Will_the_Ball_Fall.cpp

https://leetcode.com/problems/where-will-the-ball-fall/
*/

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();	// rows
        int n = grid[0].size();	// cols
        vector<int> ans(n, -1);

        for(int i=0; i<n; i++) {	// for each col
        	int row = 0, col = i;
        	
        	while(row < m) {	// for each row
        		if(grid[row][col] == 1 && col+1 < n && grid[row][col+1] == 1) {	// can move right?
        			col++, row++;
        		}
        		else if(grid[row][col] == -1 && col-1 >= 0 && grid[row][col-1] == -1) {	// can move left?
        			col--; row++;
        		}
        		else {
        			break;	// ball is stuck
        		}
        	}

        	ans[i] = ((row == m) ? col : -1);
        }

        return ans;
    }
};

