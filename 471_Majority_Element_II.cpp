/*
Majority_Element_II.cpp

https://leetcode.com/problems/majority-element-ii/description/
*/

class Solution {
public:
    // // Brute using map to count. TC: O(N) SC: O(N)
    // vector<int> majorityElement(vector<int>& nums) {
    //     int siz = nums.size();

    //     unordered_map<int, int> um;
    //     for(auto &n: nums) um[n]++;

    //     vector<int> ans;
    //     for(auto [k,v]: um) if(v > siz/3) ans.push_back(k); 
    //     return ans;
    // }


    // Candidate & life
    // At max we can have 2 majority as nums/3. There can be only two parts > nums/3
    vector<int> majorityElement(vector<int>& nums) {
        int siz = nums.size();
        int c1 = 0, c2 = 0; // candidates
        int l1 = 0, l2 = 0; // lifes

        // get the max count candidates
        for(auto &n: nums) {
            if(n == c1) l1++;
            else if(n == c2) l2++;
            else if(l1 == 0) { c1 = n; l1++; }
            else if(l2 == 0) { c2 = n; l2++; }
            else { l1--; l2--; }
        }

        // these candidates can be with count < n/3; so let only pick onces with cnt > n/3
        int cnt1 = 0, cnt2 = 0;
        for(auto &n: nums) {
            if(n == c1) cnt1++;
            else if(n == c2) cnt2++;
        }

        vector<int> ans;
        if(cnt1 > siz/3) ans.push_back(c1);
        if(cnt2 > siz/3) ans.push_back(c2);
        return ans;
    }
};






