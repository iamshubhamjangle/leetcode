/*
2_sum.cpp
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> um;

        for(int i=0; i<n; i++) {
            if(um.find(target - nums[i]) != um.end()) {
                return { i, um[target - nums[i]] };
            }
            um[nums[i]] = i;
        }

        return {};
    }
};