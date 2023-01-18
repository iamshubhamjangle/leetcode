/*
Insert_Interval.cpp

https://leetcode.com/problems/insert-interval/description/
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0, n = intervals.size();

        // while newStart > currEnd
        while(i < n && newInterval[0] > intervals[i][1]) {
            res.push_back(intervals[i]);
            i++;
        }

        // while newEnd <= currStart
        while(i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        res.push_back(newInterval);

        // leftovers
        while(i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};