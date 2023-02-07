/*
Alternating_Digit_Sum.cpp

https://leetcode.com/problems/alternating-digit-sum/
*/

class Solution {
public:
	// TC: O(N) SC: O(N)
    int alternateDigitSum(int n) {
        string s = to_string(n);
        bool add = true;
        int sum = 0;
        for(auto &ch: s) {
            if(add) sum += (ch - '0');
            else sum -= (ch - '0');
            add = !add;
        }
        return sum;
    }
};