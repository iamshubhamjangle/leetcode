/*
Delete_Columns_to_Make_Sorted.cpp

https://leetcode.com/problems/delete-columns-to-make-sorted/description/
*/

class Solution {
public:
    // TC: O(NM) SC: O(1)
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();    // rows
        int cols = strs[0].size(); // cols
        int remove = 0;

        if(rows <= 1) return remove;

        for(int i=0; i<cols; i++) {
            for(int j=1; j<rows; j++) {
                if(strs[j-1][i] > strs[j][i]) {
                    remove++;
                    break;
                }
            }
        }

        return remove;
    }
};