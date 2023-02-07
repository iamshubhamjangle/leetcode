/*
Sort_the_Students_by_Their_Kth_Score.cpp

https://leetcode.com/problems/sort-the-students-by-their-kth-score/description/
*/

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), 
            [k](vector<int>& a, vector<int>& b) { return a[k] > b[k]; });
        return score; 
    }
};