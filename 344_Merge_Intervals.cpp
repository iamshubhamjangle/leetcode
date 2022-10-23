/*
Merge_Intervals.cpp

https://leetcode.com/problems/merge-intervals/
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size() == 0) return res;

        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];        // get the first interval in temp

        for(auto it: intervals) {               // loop over all intervals
            if(it[0] <= temp[1]) {              // curr start <= temp end ---> merge 
                temp[1] = max(temp[1], it[1]);          // update temp end with curr end
            } else {
                res.push_back(temp);            // as temp was valid push it to res
                temp = it;                      // temp = curr
            }
        }

        res.push_back(temp);                    // push last temp
        return res;                             // return res
    }
};
