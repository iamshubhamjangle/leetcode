/*
[Contest]_Minimum_Addition_to_Make_Integer_Beautiful.cpp

https://leetcode.com/contest/weekly-contest-317/problems/minimum-addition-to-make-integer-beautiful/
*/

class Solution {
public:
    bool isSumOfDigitLessThanTarget(long long n, int target) {
        int sum = 0;
        while(n) {
            sum += (n % 10);
            n /= 10;
        }
        return sum <= target;
    }

    long long makeIntegerBeautiful(long long n, int target) {
        long long sum = 0;
        long long xz = 10;
        
        while(true) {
            if(isSumOfDigitLessThanTarget(n, target)) {
                return sum;
            } else {
                long long temp1 = xz - (n % xz);
                n += temp1;
                sum += temp1;
                xz *= 10;
            }
        }

        return sum;
    }
};