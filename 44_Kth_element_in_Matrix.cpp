/*
Kth_element_in_Matrix.cpp

Given a N x N matrix, where every row and column is sorted in non-decreasing order. 
Find the kth smallest element in the matrix.

Input:
N = 4
mat[][] =     {{16, 28, 60, 64},
               {22, 41, 63, 91},
               {27, 50, 87, 93},
               {36, 78, 87, 94 }}
K = 3
Output: 27

Input:
N = 4
mat[][] =     {{10, 20, 30, 40}
               {15, 25, 35, 45}
               {24, 29, 37, 48}
               {32, 33, 39, 50}}
K = 7
Output: 30

-----------------------------------------------
Method 1: 


*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

int mat[MAX][MAX];
// int kthSmallest(int mat[MAX][MAX], int n, int k);
// Method 1: Vector + sort. TC: O(N*M), SC: O(N+M)
// 	- put element in vector and sort. return arr[k-1]
int kthSmallest(int arr[MAX][MAX], int n, int k) {
        vector<int> v;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                v.push_back(arr[i][j]);
            }
        }

        sort(v.begin(), v.end());

        return v[k-1];
}


// Method 2: Max Heap, TC- O(n*n(logk)) , SC - O(k)
int kthSmallest(int mat[MAX][MAX], int n, int k) {
	priority_queue<int>maxh;
	for(int i=0;i<n;i++) {
	    for(int j=0;j<n;j++) {
	        maxh.push(mat[i][j]);
	        if(maxh.size() > k) maxh.pop();
	    }
	}
	return maxh.top();
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
	return 0;
}


