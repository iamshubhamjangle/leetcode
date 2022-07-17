/*
[Contest-Medium]Max_Sum_of_a_Pair_With_Equal_Sum_of_Digits.cpp
https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/
*/

#include <bits/stdc++.h>
using namespace std;

int maximumSum(vector<int>& nums) {
    int res = -1;
    int dn[82] = {}; // 9 * 9
    
    for (int n : nums) {
        int d = 0;
        for (int i = n; i; i /= 10)
            d += i % 10;
        if (dn[d])
            res = max(res, dn[d] + n);
        dn[d] = max(dn[d], n);
    }
    
    return res;
}

int main(){
    vector<int> n1 = {368,369,307,304,384,138,90,279,35,396,114,328,251,364,300,191,438,467,183};
    cout << maximumSum(n1) << endl;
    vector<int> n2 = {243,205,369,253,72,484,300,161,188,69,309,96,226,308,252};
    cout << maximumSum(n2) << endl;    
    vector<int> n3 = {10,12,19,14};
    cout << maximumSum(n3) << endl;
}