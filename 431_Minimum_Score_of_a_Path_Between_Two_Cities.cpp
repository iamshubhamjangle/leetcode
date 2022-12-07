/*
Minimum_Score_of_a_Path_Between_Two_Cities.cpp

https://leetcode.com/contest/weekly-contest-322/problems/minimum-score-of-a-path-between-two-cities/
*/

class Solution{
public:
	int minScore(int n, vector<vector<int>>& r) {
		int k = r.size();
	    vector<vector<pair<int,int>>> arry(n+1);

	    for(int i=0;i<k;i++) {
	        arry[r[i][0]].push_back({r[i][1],r[i][2]});
	        arry[r[i][1]].push_back({r[i][0],r[i][2]});
	    }

	    vector<int> visitted(n+2,0);

	    queue<vector<int>> q;
	    q.push({n, INT_MAX});
	    int mini = INT_MAX;

	    while(!q.empty()) {
	        auto tp = q.front();
	        q.pop();
	        mini = min(mini,tp[1]);
	        visitted[tp[0]]=1; 
	        for(auto e : arry[tp[0]]) {
	            if(!visitted[e.first]) {
	                q.push({e.first, e.second});
	            }
	        }
	    }

	    return mini;
	}
};