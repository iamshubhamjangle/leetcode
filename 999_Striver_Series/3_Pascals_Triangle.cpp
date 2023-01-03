/*
Pascals_Triangle.cpp

https://leetcode.com/problems/pascals-triangle/
*/

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> r(n);     // vector of size n

        for(int i=0; i<n; i++) {
            r[i].resize(i+1);       // resize 0th row vector to o+1 size
            r[i][0] = r[i][i] = 1;  // first n last col is always 1

            for(int j=1; j<i; j++) {
                r[i][j] = r[i-1][j-1] + r[i-1][j];
            }
        }

        return r;
    }
};