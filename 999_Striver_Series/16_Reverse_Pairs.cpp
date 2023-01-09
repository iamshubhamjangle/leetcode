/*
Reverse_Pairs.cpp

https://leetcode.com/problems/reverse-pairs/description/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // // Brute. TC: O(N*N) SC: O(1)
    // int reversePairs(vector<int>& nums) {
    //     int n = nums.size();
    //     int cnt = 0;
    //     for(int i=0; i<n; i++) {
    //         for(int j=i+1; j<n; j++) {
    //             if((long long)nums[i] > (long long)2*nums[j]) cnt++;
    //         }
    //     }
    //     return cnt;
    // }

    // Merge Sort. TC: O(NlogN) SC: O(N)
    void merge(vector<int> &nums, int l, int m, int h, int &cnt) {
        int p2 = m+1;
        for(int i=l; i<=m; i++) {
            while(p2 <= h && nums[i]/2.0 > nums[p2]) p2++;
            cnt += (p2 - (m+1));
        }

        int n1 = m-l+1;
        int n2 = h-m;

        int L[n1], R[n2];

        for(int i=0; i<n1; i++) L[i] = nums[l+i];
        for(int i=0; i<n2; i++) R[i] = nums[m+i+1];

        int i = 0; // L
        int j = 0; // R
        int k = l; // nums

        while(i < n1 && j < n2) {
            if(L[i] <= R[j])
                nums[k++] = L[i++];
            else {
                nums[k++] = R[j++];
            }
        }

        while(i < n1) nums[k++] = L[i++];
        while(j < n2) nums[k++] = R[j++];
    }

    void mergeSort(vector<int> &nums, int l, int h, int &cnt) {
        if(l < h) {
            int m = l + (h-l)/2;
            mergeSort(nums, l, m, cnt);
            mergeSort(nums, m+1, h, cnt);
            merge(nums, l, m, h, cnt);
        }
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        mergeSort(nums, 0, n-1, cnt);
        return cnt;
    }
};