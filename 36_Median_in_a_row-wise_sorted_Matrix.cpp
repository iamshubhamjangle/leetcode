/*
Median_in_a_row-wise_sorted_Matrix.cpp

Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.
Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]

Output: 5

Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2

https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
Method 1: naive approach. TC: O(N*M log N*M), SC: O(N*M)
    - Iterate and put all elements to a DataStructure i.e. pq
    - As this will be sorted the centre element will be median
Method 2: Binary search - striver video

*/


#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                pq.push(matrix[i][j]);
            }
        }

        int nth = r*c / 2;
        for(int i=0; i<nth; i++) {
            pq.pop();
        }

        int ans = pq.top();
        return ans;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}