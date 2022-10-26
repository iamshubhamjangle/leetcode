/*
Majority_Element.cpp

https://leetcode.com/problems/majority-element/
*/

class Solution {
public:
    // // Method 1: counting the freq. Finding the max frequent > (n/2)
    // // TC: O(2N) SC: O(N)
    // int majorityElement(vector<int>& nums) {
    //     unordered_map<int,int> um;
    //     for(auto &n: nums) um[n]++;
        
    //     pair<int,int> maxNumberFreq = {0,0};    // {Numberwith, maxFrequency}
    //     for(auto &it: um) {
    //         if(it.second > maxNumberFreq.second) {
    //             maxNumberFreq = {it.first, it.second};
    //         }
    //     }
        
    //     return maxNumberFreq.first;
    // }
    

    // // Method 2: Sort and return center
    // // TC: O(NlogN) SC: O(1)
    // int majorityElement(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     return nums[nums.size()/2];         // Majority element > n/2 so will be definitely found at center
    // }
    

    // Method 3: Boyer-Moore Majority Vote Algorithm
    // TC: O(N) SC: O(1)
    int majorityElement(vector<int>& nums) {
        int major=nums[0], count = 1;
        for(int i=1; i<nums.size();i++){
            if(count==0){
                count++;
                major=nums[i];
            }else if(major==nums[i]){
                count++;
            }else count--;
            
        }
        return major;
    }
    
};