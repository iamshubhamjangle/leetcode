/*
Sort_the_People.cpp

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();

        vector<pair<int,string>> vp;
        for(int i=0; i<n; i++) {
        	vp.push_back({ heights[i], names[i] });
        }

        sort(vp.rbegin(), vp.rend());

        for(int i=0; i<n; i++) {
        	names[i] = vp[i].second;
        }

        return names;
    }
};
