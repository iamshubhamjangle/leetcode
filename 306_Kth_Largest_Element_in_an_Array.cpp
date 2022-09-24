/*
Kth_Largest_Element_in_an_Array.cpp

Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
You must solve it in O(n) time complexity.

https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    	sort(nums.begin(), nums.end(), greater<int>());
    	return nums[k-1];
    }

	// Min Heap. TC: O(NlogK) SC: O(N)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minPQ;
        int n = nums.size();

        for(int i=0; i<n; i++) {
        	minPQ.push(nums[i]);
        	if(minPQ.size() > k) minPQ.pop();
        }

        return minPQ.top();
    }
};