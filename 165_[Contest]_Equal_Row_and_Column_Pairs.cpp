/*
[Contest]_Equal_Row_and_Column_Pairs.cpp

https://leetcode.com/problems/equal-row-and-column-pairs/
1. Convert to string and compare. TC: O(N*M) SC: O(2N)
2. use map of vector. TC: O(N*M) SC: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

// rows and columns ko string me convert krke compare kiya. Edge cases he thode unko tackle krne 2 maps lage
// Method: TC: O(N*M) SC: O(2N)
int equalPairs1(vector<vector<int>>& grid) {
	int n = grid.size();			// rows
	int m = grid[0].size();		// columns
	unordered_map<string, int> rowMap;
	unordered_map<string, int> colMap;

	for(int i=0; i<n; i++) {		// row
		string s = "";
		for(int j=0; j<m; j++) {	// columns
			s = s + to_string(grid[i][j]) + ',';
		}
		rowMap[s]++;
	}

	for(int i=0; i<n; i++) {		// row
		string s = "";
		for(int j=0; j<m; j++) {	// columns
			s = s + to_string(grid[j][i]) + ',';
		}
		colMap[s]++;
	}

	int count = 0;

	for(auto i: colMap) {
		if(rowMap[i.first]) count += i.second * rowMap[i.first];
		// cout << i.first << " -> " << i.second <<  endl;
	}

	return count;
}


// rows and columns ko string me convert krke compare kiya. Edge cases he thode unko tackle krne 2 maps lage
int equalPairs(vector<vector<int>>& grid)  {
    int ans = 0;
    map<vector<int>, int> mp;

    for (int i = 0; i < grid.size(); i++)	    // Storing each row of vector int he map
        mp[grid[i]]++;
    
    for (int i = 0; i < grid[0].size(); i++) {
        vector<int> v;
        for (int j = 0; j < grid.size(); j++)	// iterate columns
            v.push_back(grid[j][i]);
        ans += mp[v];
    }
    return ans;
}


int main(){
	vector<vector<int>> grid = {{3,2,1},{1,7,6},{2,7,7}};
	cout << equalPairs(grid) << endl;

	vector<vector<int>> grid1 = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
	cout << equalPairs(grid1) << endl;

	vector<vector<int>> grid2 = {{11,1},{1,11}};
	cout << equalPairs(grid2) << endl;

	vector<vector<int>> grid3 = {{13,13},{13,13}};
	cout << equalPairs(grid3) << endl;
}


// 3122, 1445, 2422, 2422
// 3122, 1444, 2422, 2522