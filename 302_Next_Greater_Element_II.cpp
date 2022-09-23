/*
Next_Greater_Element_II.cpp

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] 
is nums[0]), return the next greater number for every element in nums.

https://leetcode.com/problems/next-greater-element-ii/
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    	int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;

        // loop from back
        for(int i = 2*n-1; i >= 0; i--) {
        	// while the top elemnt is less than curr remove it
        	while(!st.empty() && st.top() <= nums[i % n]) st.pop();

        	// top element should be our nge for 1 to n range 	
        	if(i<n && !st.empty()) {
        		nge[i] = st.top();
        	}

        	st.push(nums[i%n]);
        }

        return nge;
    }
};