/*
Find_the_Duplicate_Number.cpp
*/

class Solution {
public:
    // Sorting. TC: O(NlogN) SC: O(1)
    // int findDuplicate(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n <= 1) return -1;

    //     sort(nums.begin(), nums.end());

    //     for(int i=1; i<n; i++) {
    //         if(nums[i] == nums[i-1]) {
    //             return nums[i];
    //         }
    //     }

    //     return -1;
    // }

    // Unordered-set TC: O(N) SC: O(N)
    // int findDuplicate(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n <= 1) return -1;

    //     unordered_set<int> us;
    //     for(auto &n: nums) {
    //         if(us.find(n) != us.end()) return n;
    //         us.insert(n);
    //     }

    //     return -1;
    // }


    // multiply visited index using curr number by -1. Duplicate will have +ve value
    // TC: O(N) SC: O(1)
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            nums[index] *= -1;      // mark as visited
            if(nums[index] > 0)     // incase of duplicate, this will become +ve 
                return abs(nums[i]);
        }    
        return -1;
    }
};