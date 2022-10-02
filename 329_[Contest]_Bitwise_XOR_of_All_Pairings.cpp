/*
Bitwise_XOR_of_All_Pairings.cpp

https://leetcode.com/contest/biweekly-contest-88/problems/bitwise-xor-of-all-pairings/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
        int m = nums2.size();
        int xor1 = 0 , xor2 = 0;
        
        for (int i = 0 ; i < n ;i++)
            xor1^=nums1[i];
        
        for (int i = 0 ; i < m ;i++)
            xor2^=nums2[i];
        
        int ans = 0 ;
        if (n % 2 == 1 and m % 2 == 0)
            ans = xor2;
        else if (n % 2 == 0 and m % 2 == 0 )
            ans = 0;
        else if (n % 2 == 1 and m % 2 == 1 )
            ans = xor1 ^ xor2 ;
        else if (n % 2 == 0 and m % 2 == 1 )
            ans = xor1 ;

        return ans; 
    }
};