/*
Find_Subarrays_With_Equal_Sum.cpp

Given a 0-indexed integer array nums, determine whether there exist two subarrays of length 2 with equal sum. Note that the two subarrays must begin at different indices.
Return true if these subarrays exist, and false otherwise.
A subarray is a contiguous non-empty sequence of elements within an array.

https://leetcode.com/contest/biweekly-contest-86/problems/find-subarrays-with-equal-sum/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        return 0;
    }
};

int main(){
	Solution s;
	vector<int> nums;
	nums = {4,2,4};
	cout << s.findSubarrays(nums) << endl;	
	nums = {1,2,3,4,5};
	cout << s.findSubarrays(nums) << endl;
	nums = {0,0,0};
	cout << s.findSubarrays(nums) << endl;
}