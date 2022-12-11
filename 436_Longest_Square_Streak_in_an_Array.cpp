/*
Longest_Square_Streak_in_an_Array.cpp

https://leetcode.com/contest/weekly-contest-323/problems/longest-square-streak-in-an-array/
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // int longestSquareStreak(vector<int>& nums) {
    //     int res = 0;

    //     sort(nums.begin(), nums.end());
    //     unordered_map<int, bool> um;
    //     for(auto n: nums) um[n] = false;

    //     for(int i=0; i<nums.size(); i++) {
    //     	int result = 0;
    //     	int curr = nums[i];

    //     	while(um[curr] == false) {
    //     		um[curr] = true;
    //     		int sqr = nums[i] * nums[i];
    //     		if(um[sqr] == false) {
    //     			result++;
    //     			curr = sqr;
    //     			um[sqr] = true;
    //     		}
    //     	}

    //     	res = max(res, result);
    //     }

    //     return res == 1 ? -1 : res;	 
    // }


	    int longestSquareStreak(vector<int>& nums) {
	        unordered_map<int,int> mp;
	        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
	        sort(nums.begin(),nums.end());

	        int ans = -1;
	        for(int i=0;i<nums.size();i++) {
	            int temp=1;
	            int curr=nums[i];
	            while(true) {
					long long sq = curr * 1LL * curr;
					if(mp.find(sq)!=mp.end() && mp[sq]!=-1) {
	                    temp++;
	                    curr = sq;
	                } else {
	                	mp[sq] = -1; 
	                	break;
	                }
	            }
	            if(temp>1) ans=max(ans,temp);
	        }

	        return ans;
	    }
};

int main(){
	Solution s;
	vector<int> nums;

	nums = {4,3,6,16,8,2};
	cout << s.longestSquareStreak(nums) << endl;
	
	nums = {2,3,5,6,7};
	cout << s.longestSquareStreak(nums) << endl;
}