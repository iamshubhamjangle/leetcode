/*
Spirally_traversing_a_matrix.cpp
Given a matrix of size r*c. Traverse the matrix in spiral form.

Input: r = 4, c = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
Method 1: loop while(top <= down && left <= right), TC: O(r*c), space: O(r+c)
	- https://www.youtube.com/watch?v=1ZGJzvkcLsA
	- mark the boundaries with top, down, left, right		
	- keep a direction count and increment it every iteration: direction = (direction + 1) % 4;
	- push_back() the correct element.
*/

#include <bits/stdc++.h> 
using namespace std; 

class Solution {   
    public: 
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c) {
    	/*
    		top - starting row index
    		down - ending row index
    		left - starting column index
    		right - ending column index
    	*/
    	int top = 0;
    	int left = 0;
    	int down = r - 1;
    	int right = c - 1;
    	/*
			direction = 0 left to right
			direction = 1 top to down
			direction = 2 right to left
			direction = 3 down to top
    	*/
    	int direction = 0;

    	vector<int> ans;

    	while(top <= down && left <= right) {
    		// cout << "direction: " << direction << endl;

			if(direction == 0) {
	    		for(int i=left; i<=right; i++) {
	    			ans.push_back(matrix[top][i]);
    				// cout << "matrix[top][i]: " << matrix[top][i] << endl;
	    		}
	    		top++;
			} else if (direction == 1) {
	    		for(int i=top; i<=down; i++) {
	    			ans.push_back(matrix[i][right]);
    				// cout << "matrix[i][right]: " << matrix[i][right] << endl;
	    		}
	    		right--;
			} else if (direction == 2) {
    			for(int i=right; i>=left; i--) {
    				ans.push_back(matrix[down][i]);
    				// cout << "matrix[down][i]: " << matrix[down][i] << endl;
	    		}
	    		down--;
			} else if (direction == 3) {
    			for(int i=down; i>=top; i--) {
    				ans.push_back(matrix[i][left]);
    				// cout << "matrix[left][i]: " << matrix[left][i] << endl;
    			}
				left++;
			} else {
				cout << "direction error!";
			}

			direction = (direction + 1) % 4;
    	}

    	return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}