/*
Solve_the_Sudoku.cpp

Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), 
the task to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.

Expected Time Complexity: O(9N*N).
Expected Auxiliary Space: O(N*N).

https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1
Method: Backtracking. TC: O(9N*N), SC:O(N*N)

*/

#include <bits/stdc++.h>
using namespace std;

#define UNASSIGNED 0  	// UNASSIGNED is used for empty cells in sudoku grid 
#define N 9  		// size of Sudoku grid will be NxN

class Solution 
{
    public:
    bool isSafe(int grid[9][9], int num, int i, int j)  {
    	// not exist in horizontally and vertically
        for(int x=0; x<9; x++)
        	if(grid[i][x] == num || grid[x][j] == num)
        		return false;

        int sx = (i/3)*3;
        int sy = (j/3)*3;

        // not exist in 3x3 smaller box
        for(int x=sx; x<sx+3; x++)
            for(int y=sy; y<sy+3; y++)
        	    if(grid[x][y] == num) return false;

        return true;
    }

    bool helper(int grid[9][9],int i,int j)  {
        if(i==9) return true;	// reached last row, return true.
        if(j==9) return helper(grid,i+1,0);	// reaching last column go to next row
        if(grid[i][j]!=0) return helper(grid,i,j+1);	// If current is not zero then recurse
        
        for(int n=1;n<=9;n++)  {
            if(isSafe(grid,n,i,j)) {
                grid[i][j] = n;
                if(helper(grid,i,j+1)) return true;
            }
        }

        grid[i][j] = 0;		// backtrack
        return false;
    }


    bool SolveSudoku(int grid[N][N]) {
        return helper(grid,0,0);

    }
    
    void printGrid (int grid[N][N]) {
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            	cout<<grid[i][j]<<" ";
    }
};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}