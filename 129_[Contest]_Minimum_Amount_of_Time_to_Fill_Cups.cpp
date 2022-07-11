/*
129_[Contest]_Minimum_Amount_of_Time_to_Fill_Cups.cpp
https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/
Method: Normal loop - max(mx, (sum+1)/2);

You have a water dispenser that can dispense cold, warm, and hot water. 
Every second, you can either fill up 2 cups with different types of water, or 1 cup of any type of water.

You are given a 0-indexed integer array amount of length 3 where amount[0], amount[1], and amount[2] 
denote the number of cold, warm, and hot water cups you need to fill respectively. Return the minimum 
number of seconds needed to fill up all the cups.

Input: amount = [1,4,2]
Output: 4

Input: amount = [5,4,4]
Output: 7

Input: amount = [5,0,0]
Output: 5

https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/
Method: Normal loop - max(mx, (sum+1)/2);
*/

class Solution {
public:
    int fillCups(vector<int>& amount) {
        int mx = 0;
        int sum = 0;
        for(int &i: amount) {
            mx = max(mx, i);
            sum += i;
        }
        
        return max(mx, (sum+1)/2);
    }
};