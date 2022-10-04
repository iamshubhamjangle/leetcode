/*
Pascals_Triangle.cpp

https://leetcode.com/problems/pascals-triangle/
*/


// Method 1: Calculate nCr at each point. nCr = n! / r!*(n-r)!
// TC: O(N*N) SC: O(1)


// Method 2: There are some similarity in nCr at each col we can use value or prev node


// Method 3: Using prev row data to calculate next
// TC: O(N*M) SC: O(1)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows);     // vector of size n

        for(int i=0; i<numRows; i++) {
            r[i].resize(i+1);       // resize 0th row vector to o+1 size
            r[i][0] = r[i][i] = 1;  // first n last col is always 1

            for(int j=1; j<i; j++) {
                r[i][j] = r[i-1][j-1] + r[i-1][j];
            }
        }

        return r;
    }
};