/*
[Contest]_Smallest_Subarrays_With_Maximum_Bitwise_OR.cpp

You are given a 0-indexed array nums of length n, consisting of non-negative integers. For each index i from 0 to n - 1, you must determine the size of the minimum sized non-empty subarray of nums starting at i (inclusive) that has the maximum possible bitwise OR.
In other words, let Bij be the bitwise OR of the subarray nums[i...j]. You need to find the smallest subarray starting at i, such that bitwise OR of this subarray is equal to max(Bik) where i <= k <= n - 1.
The bitwise OR of an array is the bitwise OR of all the numbers in it.
Return an integer array answer of size n where answer[i] is the length of the minimum sized subarray starting at i with maximum bitwise OR.
A subarray is a contiguous non-empty sequence of elements within an array.

Input: nums = [1,0,2,1,3]
Output: [3,3,2,2,1]

Input: nums = [1,2]
Output: [2,1]

https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/
*/

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& A) {
        int last[30] = {}, n = A.size();
        vector<int> res(n, 1);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 30; ++j) {
                if (A[i] & (1 << j))
                    last[j] = i;
                res[i] = max(res[i], last[j] - i + 1);
            }
        }
        return res;
    }
};