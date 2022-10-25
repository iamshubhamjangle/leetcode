/*
Pow(x,n).cpp

https://leetcode.com/problems/powx-n/
*/

class Solution {
public:
//     // Method 1: Naive. TLE. TC: O(N) SC: O(1)
//     double myPow(double x, int n) {
//         if(x == 0) return 0;
//         if(x == 1) return x;
//         if(n == 0) return 1;
        
//         double ans = 1;
//         bool isNegative = false;
//         if(n < 0) isNegative = true;
//         n = abs(n);
        
//         while(n--) {
//             ans *= x;
//         }
        
//         if(isNegative) ans = 1/ans;
//         return ans;
//     }
   
    
    // Method 2: Bitwise. TC: O(1-bits) SC: O(1)
    double myPow(double x, int n) {
        double res = 1;
        while (n) {
            if (n % 2) res = n > 0 ? res * x : res / x;
            x = x * x;
            n /= 2;
        }
        return res;
    }
};