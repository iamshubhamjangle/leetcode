/*
Increasing_Triplet_Subsequence.cpp

https://leetcode.com/problems/increasing-triplet-subsequence/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX, c2 = INT_MAX;
        for (int curr : nums) {
            if (curr <= c1) {
                c1 = curr;           // c1 is min seen so far (it's a candidate for 1st element)
            } else if (curr <= c2) { // here when curr > c1, i.e. curr might be either c2 or c3
                c2 = curr;           // curr is better than the current c2, store it
            } else {              // here when we have/had c1 < c2 already and curr > c2
                return true;      // the increasing subsequence of 3 elements exists
            }
        }
        return false;
    }
};

int main(){
	Solution s;
	vector<int> nums;

	nums = {5,4,3,2,1};			// false
	cout << s.increasingTriplet(nums) << endl;

	nums = {1,2,3,4,5};			// true
	cout << s.increasingTriplet(nums) << endl;

	nums = {20,100,10,12,5,13};	// true
	cout << s.increasingTriplet(nums) << endl;

	nums = {1,2,1,3};		// true
	cout << s.increasingTriplet(nums) << endl;
}