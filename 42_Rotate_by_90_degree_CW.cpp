/*
Rotate Matrix Clock Wise 90 deg

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

Constraints:
n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000

https://leetcode.com/problems/rotate-image/
Method 1: Swap NE diagonals and reverse -- TC: O(N*N), SC: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	int n = matrix.size();
    	if(n == 0) return;
    	int m = matrix[0].size();

        for(int i=0; i<n; i++)
        	for(int j=0; j<n-i-1; j++)
        		swap(matrix[i][j], matrix[m-j-1][n-i-1]);

        reverse(matrix.begin(), matrix.end());
    }

    /*
	 * anticlockwise rotate
	 * first reverse left to right, then swap the symmetry
	 * 1 2 3     3 2 1     3 6 9
	 * 4 5 6  => 6 5 4  => 2 5 8
	 * 7 8 9     9 8 7     1 4 7
	*/
	// void anti_rotate(vector<vector<int> > &matrix) {
	//     for (auto vi : matrix) reverse(vi.begin(), vi.end());
	//     for (int i = 0; i < matrix.size(); ++i) {
	//         for (int j = i + 1; j < matrix[i].size(); ++j)
	//             swap(matrix[i][j], matrix[j][i]);
	//     }
	// }
};

int main() {
	int t;
	cin >> t;
	while(t--) {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++) {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }

		Solution s;
		s.rotate(matrix);

        for (int i = 0; i < n; ++i) {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
	} 
	return 1;
}