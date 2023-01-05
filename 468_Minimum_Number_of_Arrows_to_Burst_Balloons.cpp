/*
Minimum_Number_of_Arrows_to_Burst_Balloons.cpp

https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

Intuition
Why sort by Xend ??
Because we want this interval to overlap with maximum intervals.
So if we shoot at this end point we will burst all intervals containing this point. Hence requiring minimum arrows.

Complexity
Time complexity: O(nlogn)
Space complexity: O(1)
*/

bool comp(vector<int> &a,vector<int> &b){
    return a[1]<b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0) return 0;
        sort(points.begin(),points.end(),comp);
        int arrows=1;
        int end=points[0][1];
        for(int i=1;i<points.size();i++){
          if(points[i][0]>end){
              arrows++;
              end=points[i][1];
          }  
        }
        return arrows;
    }
};