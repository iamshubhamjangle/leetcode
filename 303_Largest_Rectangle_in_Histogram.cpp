/*
Largest_Rectangle_in_Histogram.cpp

Given an array of integers heights representing the histogram's bar height where 
the width of each bar is 1, return the area of the largest rectangle in the histogram.

Input: heights = [2,1,5,6,2,3]
Output: 10

Input: heights = [2,4]
Output: 4

https://leetcode.com/problems/largest-rectangle-in-histogram/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // // Bruteforce. TC: O(N*N) SC: O(1)
    // // on each position find left min and right min. calculate area -> maxarea;
    // int largestRectangleArea(vector<int>& arr) {
    //     int n = arr.size();
    //     int maxArea = 0;

    //     for(int i=0; i<n; i++) {
    //         // min on left
    //         int left = 0;
    //         for(int j=i-1; j>=0; j--) {
    //             if(arr[j] < arr[i]) {
    //                 left = j+1;
    //                 break;
    //             }
    //         }
    //         // min on right
    //         int right = n-1;
    //         for(int j=i+1; j<n; j++) {
    //             if(arr[j]<arr[i]) {
    //                 right = j-1;
    //                 break;
    //             }
    //         }

    //         int ithArea = (right - left + 1) * arr[i];
    //         maxArea = max(maxArea, ithArea);
    //     }

    //     return maxArea;
    // }


    // // Two stack solution. TC: O(2N) SC: O(N)
    // int largestRectangleArea(vector<int>& arr) {
    //     int n = arr.size();
    //     stack<int> st;
    //     int leftSmall[n], rightSmall[n];

    //     // precompute left smallest array
    //     for(int i=0; i<n; i++) {
    //         // remove all greater elements
    //         while(!st.empty() && arr[st.top()] >= arr[i]) 
    //             st.pop();

    //         if(st.empty()) leftSmall[i] = 0;
    //         else leftSmall[i] = st.top() + 1;

    //         st.push(i); // push curr index
    //     }

    //     // clear the stack
    //     while(!st.empty()) st.pop();
    //     int maxArea = 0;

    //     // precompute right smallest arr
    //     for(int i=n-1; i>=0; i--) {
    //         // remove all greater elements
    //         while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

    //         if(st.empty()) rightSmall[i] = n-1;
    //         else rightSmall[i] = st.top() - 1;

    //         maxArea = max(maxArea, (rightSmall[i] - leftSmall[i] + 1) * arr[i]);
    //         st.push(i);
    //     }

    //     return maxArea;
    // }


    // Optimised. One stack. TC: O(N) SC: O(N)
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int maxA = 0;
        int n = arr.size();
        for(int i=0; i<=n; i++) {
            while(!st.empty() && (i==n || arr[st.top()] >= arr[i])) {
                int height = arr[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;

                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }
};


int main(){
    Solution s;

    vector<int> arr;

    arr = {2,1,5,6,2,3};
    cout << s.largestRectangleArea(arr) << endl;
    arr = {2,4};
    cout << s.largestRectangleArea(arr) << endl;
}