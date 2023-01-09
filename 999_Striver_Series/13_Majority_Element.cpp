/*
Majority_Element.cpp

https://leetcode.com/problems/majority-element/description/
*/

class Solution {
public:
    // // Map and major count. TC: O(N) SC: O(N)
    // int majorityElement(vector<int>& nums) {
    //     unordered_map<int, int> um;
    //     int major = nums[0];
    //     int majorCount = 0;

    //     for(auto &n: nums) {
    //         um[n]++;
    //         if(um[n] > majorCount) {
    //             majorCount = um[n];
    //             major = n;
    //         }
    //     }

    //     return major;
    // }


    // Candidate and shoot. TC: O(N) SC: O(1)
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int currLife = 0;

        for(auto &n: nums) {
            if(candidate == n) {
                currLife++;
            } 
            else if(currLife == 0) {
                candidate = n;
                currLife = 1;
            } 
            else {
                currLife--;
            }
        }

        return candidate;
    }
};















