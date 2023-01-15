/*
Increment_Submatrices_by_One.cpp

https://leetcode.com/contest/weekly-contest-328/problems/increment-submatrices-by-one/
*/

class Solution {
public:
    // vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    // 	vector<vector<int>> matrix(n, vector<int>(n, 0));

	// 	for(int i=0; i<queries.size(); i++) {
			// int x1 = queries[i][0];
			// int y1 = queries[i][1];
			// int x2 = queries[i][2];
			// int y2 = queries[i][3];

	// 		for(int i=0; i<n; i++) {
	// 			for(int j=0; j<n; j++) {
	// 				if((x1 <= i && i <= x2) && (y1 <= j && j < y2)) {
	// 					matrix[i][j] += 1;
	// 				}
	// 			}
	// 		}
	// 	}

	// 	return matrix;
    // }




    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    	vector<vector<int>> matrix(n, vector<int>(n, 0));
    	unordered_map<int,int> umx;
    	unordered_map<int,int> umy;

		for(int i=0; i<queries.size(); i++) {
			int x1 = queries[i][0];
			int y1 = queries[i][1];
			int x2 = queries[i][2];
			int y2 = queries[i][3];

			umx[x1]++;
			umx[x2]++;
			umy[y1]++;
			umy[y2]++;
		}

		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				matrix[i][j] = min(umx[i], umy[i]);
			}
		}

		return matrix;
    }
};