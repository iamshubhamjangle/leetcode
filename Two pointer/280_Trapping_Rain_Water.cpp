/*
Trapping_Rain_Water.cpp

Given n non-negative integers representing an elevation map where the 
width of each bar is 1, compute how much water it can trap after raining.

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Input: height = [4,2,0,3,2,5]
Output: 9

https://leetcode.com/problems/trapping-rain-water/
1. Bruteforce. TC: O(N*N) SC: O(1).
2. Prefix/Suffix max height. TC:O(N) SC: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

// // 1. Bruteforce. TC: O(N*N) SC: O(1).
// // find max on both sides and return the amount of rainwater trapped.
// class Solution {
// public:
// 	int findMaxHeight(int start, int end, vector<int> &height) {
// 		int maxHeight = 0;
// 		for(int i=start; i<=end; i++) {
// 			maxHeight = max(height[i], maxHeight);
// 		}
// 		return maxHeight;
// 	}

//     int trap(vector<int>& height) {
//         int n = height.size();
//         int ans = 0;

//         for(int i=0; i<n; i++) {
//         	int l = findMaxHeight(0, i, height);
//         	int r = findMaxHeight(i, n-1, height);
//         	int temp = min(l,r) - height[i];
//         	ans += temp;
//         }

//         return ans;
//     }
// };


// // 2. Prefix/Suffix max height. TC:O(N) SC: O(N)
// // instead of calculating max each time. lets store it for O(1) access;
// class Solution {
// public:
// 	void print(vector<int> &v) {
// 		for(auto i: v) cout << i << ", ";
// 		cout << endl;
// 	}

//     int trap(vector<int>& height) {
//     	int n = height.size();

// 		vector<int> prefix(n), suffix(n);
// 		int maxi = 0;
// 		for(int i=0; i<n; i++) {
// 			prefix[i] = max(height[i], maxi);
// 			maxi = prefix[i];
// 		}

// 		maxi = 0;
// 		for(int i=n-1; i>=0; i--) {
// 			suffix[i] = max(height[i], maxi);
// 			maxi = suffix[i];
// 		}

// 		int ans = 0;
// 		for(int i=0; i<n; i++) {
// 			ans += min(prefix[i], suffix[i]) - height[i];
// 		}
// 		return ans;
//     }
// };


// 3. Two Pointer. TC:O(N) SC: O(1)
// Keep track of left max, right max.
// Conditions make sure that there's a leftmax/rightmax present hence we fill the water
class Solution {
public:
    int trap(vector<int>& height) {
    	int n = height.size();
    	int left  = 0;
    	int right = n-1;
    	int res = 0;
    	int maxLeft = 0;
    	int maxRight = 0;

    	while(left <= right) {
    		// There someone greater at right we can store water if curr < left max;
    		if(height[left] <= height[right]) {
    			// there's someone more than leftMax, update leftMax
    			if(height[left] >= maxLeft) maxLeft = height[left];
    			// we can store water curr < left max
    			else res += maxLeft - height[left];

    			left++;
    		} else {
    			if(height[right] >= maxRight) maxRight = height[right];
    			else res += maxRight - height[right];

    			right--;
    		}
    	}

    	return res;
    }
};

int main(){
	Solution s;
	vector<int> height;

	height = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout << s.trap(height) << endl;
	
	height = {4,2,0,3,2,5};
	cout << s.trap(height) << endl;
}