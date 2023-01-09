/*
Pow_x_n.cpp

https://leetcode.com/problems/powx-n/
*/

class Solution {
public:
    // bruteforce: multiply x, n times; If negative 1/ans;
    // TC: O(X*N) SC: O(N)

    // Optimised. Maths. TC: O(logN) SC: O(1)
    double myPow(double x, int nn) {
        double res = 1.0;
        long long n = abs(nn);

        while(n) {
            if(n%2 == 0) {  // even
                x = x*x;
                n = n/2;
            } else {    // odd
                res *= x;
                n--;
            }
        }

        if(nn < 0) return 1.0/res;
        return res;
    }
};











