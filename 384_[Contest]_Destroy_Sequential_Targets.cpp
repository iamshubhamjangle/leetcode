/*
[Contest]_Destroy_Sequential_Targets.cpp

Input: nums = [3,7,8,1,1,5], space = 2
Output: 1

https://leetcode.com/contest/biweekly-contest-90/problems/destroy-sequential-targets/
*/

class Solution {
public:
int destroyTargets(vector<int>& a, int d) {
    sort(a.begin(), a.end());
    map<int,int> mpp;

    for(int i=0;i<a.size();i++) {
        int x = a[i] / d;
        x = a[i] - x*d;
        if(x==0) 
            x = d;
        mpp[x]++;
    }

    int mx = -1;
    for(auto i: mpp) {
        if(i.second>mx)
            mx = i.second;
    }

    set<int> result;
    for(auto i : mpp) {
        if(i.second==mx)
            result.insert(i.first);
    }

    int ans = INT_MAX;
    for(int i=0; i<a.size(); i++) {
        int x = a[i]/d;
        x = a[i] - x*d;

        if(x==0) 
            x=d;

        if(result.find(x)!=result.end()) {
            if(ans > a[i])
                ans = a[i];
        }
    }

    return(ans);
}
};