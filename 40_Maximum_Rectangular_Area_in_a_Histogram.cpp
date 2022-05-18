/*
Maximum_Rectangular_Area_in_a_Histogram.cpp

Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12

Input:
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16

https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1
    - Method 1: Bruteforce TC: O(N*N), SC: O(1)
    - Method 2: Using PSE, NSE. TC: O(N), SC: O(3N) - two array and one stack

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // Method 1: Bruteforce TC: O(N*N), SC: O(1) 
    // long long getMaxArea(long long arr[], int n) {
    // 	if(n == 0) return 0;

    // 	int maxArea = 0;
    // 	for(int i=0; i<n; i++) {
    // 		int min = arr[i];
    // 		for(int j=i; j<n; j++) {
    // 			int area = 0;

    // 			if(arr[j] < min) min = arr[j];

    // 			if(i == j) {
    // 				area = arr[i];
    // 			} else {
    // 				area = (j-i+1) * min;
    // 			}

    // 			maxArea = max(maxArea, area);
    // 		}
    // 	}
    // 	return maxArea;
    // }

    // Method 2: Using PSE, NSE. TC: O(N), SC: O(3N) - two array and one stack
    // Find prev smallest, next smallest for each element
	// this would stay in two different array.
    // use these two array to calculate max area of histogram
    // ithArea = (rightSmallest[i] - leftSmallest[i] + 1) * height
	// long long getMaxArea(long long arr[], long long n) {
 //        vector<long long> l(n), r(n);
 //        stack<int> st;

 //        for(int i=0; i<n; i++) {
 //            while(!st.empty() && arr[st.top()] >= arr[i]) 
 //            	st.pop();
 //            l[i] = st.empty() ? -1 : st.top();
 //            st.push(i);
 //        }

 //        while(!st.empty()) 
 //        	st.pop();
        
 //        for(int i=n-1; i>=0; i--) {
 //            while(!st.empty() && arr[st.top()] >= arr[i]) 
 //            	st.pop();
 //            r[i] = st.empty() ? n : st.top();
 //            st.push(i);
 //        }

 //        long long res=0;
 //        for(int i=0; i<n; i++)
 //            res = max(res, arr[i] * (r[i]-l[i]-1));
 //        return res;
	// }

	// Method 3: Optimal TC: O(N), SC: O(N) 
	long long getMaxArea(long long arr[], long long n) {
      stack < int > st;
      int maxA = 0;
      for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || arr[st.top()] >= arr[i])) {
          int height = arr[st.top()];
          st.pop();
          int width;
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1;
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
      return maxA;
    }
};

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}