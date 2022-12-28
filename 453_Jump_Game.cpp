/*
Jump_Game.cpp

https://leetcode.com/problems/jump-game/
*/

class Solution {
public:
	// // 1. Recursion. TC: O(N) SC: O(1) ASC: O(N)
    // bool solve(int i, int n, vector<int> &nums) {
    //     cout << "curr: " << i << endl;
    //     if(i == n-1) return true;

    //     bool canJump = false;
    //     for(int j=1; j<=nums[i]; j++) {
    //         canJump = canJump || solve(i+j, n, nums);
    //     }

    //     return canJump;
    // }

    // bool canJump(vector<int>& nums) {
    //     int n = nums.size();
    //     return solve(0, n, nums);
    // }


	// 2. Memoisation. 
    // bool solve(int i, int n, vector<int> &nums, vector<int> &dp) {
    //     if(i == n-1) return true;

    //     if(dp[i] != -1) return dp[i];

    //     bool canJump = false;
    //     for(int j=1; j<=nums[i]; j++) {
    //         canJump = canJump || solve(i+j, n, nums, dp);
    //     }

    //     return dp[i] = canJump;
    // }

    // bool canJump(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n, -1);
    //     return solve(0, n, nums, dp);
    // }


};


// Iterate from back and keep track of min jumps req at a point. TC: O(N) SC: O(N)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i, minjump = 0;
        for(i = nums.size()-2; i >= 0; i--){
            minjump++;
            if(nums[i] >= minjump)
			    minjump = 0;
        }
        if(minjump == 0) 
		    return true;
        else 
		    return false;
    }
};