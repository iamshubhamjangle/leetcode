/*
Delete_Greatest_Value_in_Each_Row.cpp

https://leetcode.com/contest/weekly-contest-323/problems/delete-greatest-value-in-each-row/
*/

#include <bits/stdc++.h>
using namespace std;

// Print vector of vector
void print(vector<vector<int>> &v) {
  cout << "[";
  for(auto i: v) { cout << "["; for(auto j: i) cout << j << ","; cout << "]"; }
  cout << "]" << endl;
}

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for(auto &i: grid) sort(i.begin(), i.end());
        print(grid);

        int result = 0;

        int noOfRows = grid.size();
        int noOfCols = grid[0].size();

        for(int col=0; col<noOfCols; col++) {
        	int maxi = 0;

        	for(int row=0; row<noOfRows; row++) {
        		maxi = max(maxi, grid[row][col]);
        	}

        	result += maxi;
        }

        return result;
    }
};

int main(){
	Solution s;

	vector<vector<int>> grid = {{1,2,4},{3,3,1}};
	cout << s.deleteGreatestValue(grid) << endl;

	vector<vector<int>> grid2 = {{10}};
	cout << s.deleteGreatestValue(grid2) << endl;
}