/*
[Contest]_Average_Value_of_Even_Numbers_That_Are_Divisible_by_Three.cpp

https://leetcode.com/contest/weekly-contest-317/problems/average-value-of-even-numbers-that-are-divisible-by-three/
*/

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0;
        int count = 0;
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            if(nums[i]%2 == 0 && nums[i]%3 == 0) {
                sum += nums[i];
                count++;
            }
        }
        
        if(count>0)
            return sum/count;
        
        return 0;
    }
};

