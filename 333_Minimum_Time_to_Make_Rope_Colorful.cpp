/*
Minimum_Time_to_Make_Rope_Colorful.cpp

*/

class Solution {
public:
//     int minCost(string colors, vector<int>& neededTime) {
//         int n = neededTime.size();
//         if(n <= 1) return 0;
        
        
//         int ans = 0;
//         for(int i=0; i<n-1; i++) {
//             if(colors[i] == colors[i+1]) {
//                 if(neededTime[i] < neededTime[i+1]) {
//                     ans += neededTime[i];
//                 } else {
//                     ans += neededTime[i+1];
//                     neededTime[i+1] = neededTime[i];
//                 }
//             }
//         }
        
//         return ans;
//     }
    
    
    int minCost(string s, vector<int>& cost) {
        int res = 0, max_cost = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0 && s[i] != s[i - 1])
                max_cost = 0;
            res += min(max_cost, cost[i]);
            max_cost = max(max_cost, cost[i]);
        }
        return res;
    }

};