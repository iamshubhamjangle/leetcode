/*
Merge_Sorted_Array.cpp

https://leetcode.com/problems/merge-sorted-array/
*/

class Solution {
public:
    // Method 1: Copy nums1 to nums2. Apply mergesort on the nums1. TC: O(NlogN) SC: O(1)
    
    // Method 2: Start from end of both arr. Copy them in num1 in order. TC: O(m+n) SC: O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m+n == 1) {
            if(n == 1) nums1[0] = nums2[0];
            return;
        }
        
        int p1 = m-1;   // nums1
        int p2 = n-1;   // nums2
        int p = m+n-1;  // at end of nums1
        
        while(p1 >= 0 && p2 >= 0) {
            if(nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
                p--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
                p--;
            }
        }
        
        while(p2 >= 0) {
            nums1[p] = nums2[p2];
            p--; p2--;
        }
    }
};