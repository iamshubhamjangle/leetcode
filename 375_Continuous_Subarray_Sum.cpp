/*
Continuous_Subarray_Sum.cpp

https://leetcode.com/problems/continuous-subarray-sum/
*/

class Solution {
public:
// // Method 1: Bruteforce. TC: O(N^3) SC: O(1)
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();

//         for(int i=0; i<n; i++) {
//         	for(int j=i+1; j<n; j++) {
// 				int sum = 0;
//         		for(int k=i; k<=j; k++) {
//         			sum += nums[k];
//         		}
//         		if(sum % k == 0) return true;
//         	}
//         }

//         return false;
//     }


// Method 2: Prefix Sum
    bool checkSubarraySum(vector<int>& nums, int k) {

        int prefSum = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            prefSum += nums[i];
            prefSum %= k;

            if(prefSum == 0 && i) return true;

            // cout << prefSum << " ";
            if(mp.find(prefSum) != mp.end())  // Found the required prefix sum 
            {
                if(i - mp[prefSum] > 1) return true; // check if atleast 2 elements are there or not
            }
            else mp[prefSum] = i;
        }

        return false;
    }
};









