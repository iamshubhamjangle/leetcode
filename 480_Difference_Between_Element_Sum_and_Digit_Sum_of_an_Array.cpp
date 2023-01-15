/*
Difference_Between_Element_Sum_and_Digit_Sum_of_an_Array.cpp

https://leetcode.com/contest/weekly-contest-328/problems/difference-between-element-sum-and-digit-sum-of-an-array/
*/

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int digitSum = 0;
        int elementSum = 0;
        
        for(int i=0; i<nums.size(); i++) {
            digitSum += nums[i];
            
            int temp = nums[i];
            while(temp) {
                elementSum += temp%10;
                temp/=10;
            }
        }
        
        return abs(digitSum - elementSum);
    }
};