/*
Search_in_a_row-column_sorted_Matrix.cpp

Given a matrix of size n x m, where every row and column is sorted in increasing order, and a number x. Find whether element x is present in the matrix or not.

n = 3, m = 3, x = 62
matrix[][] = {{ 3, 30, 38},
              {36, 43, 60},
              {40, 51, 69}}
Output: 0

https://practice.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1
Method 1: Bruteforce TC: O(N*M), SC: O(1)
Method 2: TC: O(N+M), SC: O(1)
*/

#include<bits/stdc++.h> 
using namespace std;

class Solution
{
    public:
    // Method 1: Bruteforce TC: O(N*M), SC: O(1)
    // bool search(vector<vector<int> > matrix, int n, int m, int x)  {
    //     for(int i=0; i<n; i++) {
    //     	for(int j=0; j<m; j++) {
    //     		if(matrix[i][j] == x) {
    //     			return 1;
    //     		}
    //     	}
    //     }
    //     return 0;
    // }

    // Method 2: TC: O(N+M), SC: O(1)
    bool search(vector<vector<int> > matrix, int n, int m, int x)  {
    	int i = 0;		// point to first row
    	int j = m-1;	// point to last column

    	while(i<n && j>=0) {
    		if(matrix[i][j] == x) {
    			return 1;
    		} else if (matrix[i][j] > x) {	//if curr > x, check prev column
    			j--;
    		} else {						//if curr < x, check next row
    			i++;
    		}
    	}

    	return 0;
    }
};

int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        Solution obj;
        if (obj.search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
}