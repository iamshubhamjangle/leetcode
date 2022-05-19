/*
Determine_Whether_Matrix_Can_Be_Obtained_By_Rotation.cpp
Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.

Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
Output: true

Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
Output: false

https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
Method 1: Loop over and inplace check all the positions whether it can be achived or not.
	- TC: O(N*N), SC: O(1) 
*/

class Solution {
	public:
	bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
		bool c[4];
		memset(c,true,sizeof(c));
		int n=mat.size();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(mat[i][j]!=target[i][j]) c[0]=false;
				if(mat[i][j]!=target[n-j-1][i]) c[1]=false;
				if(mat[i][j]!=target[n-i-1][n-j-1]) c[2]=false;
				if(mat[i][j]!=target[j][n-i-1]) c[3]=false;
			}
		}
		return c[0]||c[1]||c[2]||c[3];
	}
};

void main() {
	
}