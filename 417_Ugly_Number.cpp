/*
Ugly_Number.cpp

https://leetcode.com/problems/ugly-number/
*/

class Solution {
public:
    bool isUgly(int num) {
        if (num > 0) {
            for (int i=2; i<6; i++)
                while (num % i == 0)
                    num /= i;
        }
        return num == 1;
    }
};