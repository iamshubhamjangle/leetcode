/*
max_activities.cpp

https://www.codingninjas.com/codestudio/problems/1062712
*/

#include <bits/stdc++.h>

int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int,int>> v;
    for(int i=0; i<start.size(); i++) {
        v.push_back({ start[i], finish[i] });
    }

    sort(v.begin(), v.end(), [](pair<int,int> p1, pair<int,int> p2){
        if(p1.second < p2.second) return true;
        return false;
    });

    int maxActivities = 0;
    int prevEnd = 0;
    for(auto a: v) {
        if(a.first >= prevEnd) {
            prevEnd = a.second;
            maxActivities++;
        }
    }

    return maxActivities;
}