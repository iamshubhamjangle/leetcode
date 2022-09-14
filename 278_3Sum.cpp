/*
3Sum.cpp

Given an integer array nums, return all the triplets 
[nums[i], nums[j], nums[k]] such that 
i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

https://leetcode.com/problems/3sum/
1. Bruteforce. TC: O(N*N*N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

  // // 1. Bruteforce. All combination. TC: O(N^3) SC: O(N) TLE
  //   vector<vector<int>> threeSum(vector<int>& nums) {
		// set<vector<int>> st;

		// int n = nums.size();
		// for(int i=0; i<n; i++) {
		// 	for(int j=i+1; j<n; j++) {
		// 		for(int k=j+1; k<n; k++) {
		// 			if(nums[i]+nums[j]+nums[k] == 0) {
		// 				vector<int> v = {nums[i], nums[j], nums[k]};
		// 				sort(v.begin(), v.end());
		// 				st.insert(v);
		// 			}
		// 		}
		// 	}
		// }

		// vector<vector<int>> ans;

		// for(auto i: st) {
		// 	ans.push_back(i);
		// }

		// return ans;
  //   }


	// // 2. Using hashmap to keep track of 3rd guy.
	// // TC: O(N^2) SC: O(2N)
 //    vector<vector<int>> threeSum(vector<int>& nums) {
	// 	unordered_map<int, int> um;
	// 	set<vector<int>> s;
	// 	for(auto i: nums) um[i]++;
	// 	int n = nums.size();

	// 	for(int i=0; i<n; i++) {
	// 		um[nums[i]]--;
	// 		for(int j=i+1; j<n; j++) {
	// 			um[nums[j]]--;

	// 			int aplusb = nums[i] + nums[j];
	// 			if(um[-aplusb]) {
	// 				// add to set
	// 				vector<int> v = {nums[i], nums[j], -aplusb};
	// 				sort(v.begin(), v.end());
	// 				s.insert(v);
	// 			}

	// 			um[nums[j]]++;
	// 		}
	// 		um[nums[i]]++;
	// 	}

	// 	vector<vector<int>> ans;
	// 	for(auto i: s) ans.push_back(i);
	// 	return ans;
	// }



    vector<vector<int>> threeSum(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	vector<vector<int>> ans;
    	int n = nums.size();

    	// iterate 'a' from 0 - n-3
    	for(int i=0; i<n-2; i++) {
    		// consider only first value as 'a', further if dup found ignore
    		if(i==0 || (i>0 && nums[i] != nums[i-1])) {
    			// lets setup 'b' and 'c', b + c = 0 - a
    			int lo = i+1;
    			int hi = n-1;
    			int sum= 0-nums[i];

    			while(lo < hi) {
    				if(nums[lo] + nums[hi] == sum) {
    					// we got the triplet
    					vector<int> temp;
    					temp.push_back(nums[i]);
    					temp.push_back(nums[lo]);
    					temp.push_back(nums[hi]);
    					ans.push_back(temp);

    					// skip dup low and high and move to next
    					while(lo < hi && nums[lo] == nums[lo+1]) lo++;
    					while(lo < hi && nums[hi] == nums[hi-1]) hi--;

    					lo++; 
    					hi--;
    				} 
    				else if(nums[lo] + nums[hi] < sum) {
    					lo++;
    				} else {
    					hi--;
    				}
    			}
    		}
    	}

    	return ans;
    }

};
