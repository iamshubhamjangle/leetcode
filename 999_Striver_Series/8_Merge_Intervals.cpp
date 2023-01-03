/*
Merge_Intervals.cpp
*/

class Solution {
public:
    // TC: O(NlogN) SC: O(1)
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        if(n <= 1) return arr;
        
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());

        for(int i=1; i<n; i++) {                // for each interval
            if(arr[i][0] <= arr[i-1][1]) {      // If currStart < prevEnd
                arr[i][0] = arr[i-1][0];        //      update curr start to prev start
                if(arr[i][1] < arr[i-1][1]) {   // if currEnd < prevEnd
                    arr[i][1] = arr[i-1][1];    //      update curr end to prev end
                }
            } else {
                res.push_back(arr[i-1]);        // is prev was correct push it to res
            }
        }

        res.push_back(arr[n-1]);                // add the remaining element to arr
        return res;
    }
};