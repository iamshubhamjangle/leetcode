/*
[Contest]_Most_Popular_Video_Creator.cpp

https://leetcode.com/contest/weekly-contest-317/problems/most-popular-video-creator/
*/

class Solution {
public:
    static bool customCompare(pair<string, int> p1, pair<string, int> p2 ){
		if(p1.second != p2.second) return p1.second > p2.second; 
			return p1.first < p2.first;
    }

    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        long long maxi = -1;
        int n = views.size();
        vector<string> ans;
        vector<vector<string>> result;
        unordered_map<string, vector<pair<string, int>>> mpp;
        unordered_map<string, long long> mpp1;

        for(int i=0; i<n; i++){
            mpp[creators[i]].push_back({ids[i], views[i]});
            mpp1[creators[i]]+=views[i];
        }
        
        for(auto it : mpp1) {
            maxi= max(maxi, it.second);
        }

        for(auto it : mpp1){
            if(it.second==maxi) ans.push_back(it.first);
        }
        
        for(auto x : ans){
            vector<string>v;
            auto temp = mpp[x];
            sort(temp.begin(), temp.end(), customCompare);
            v.push_back(x);
            v.push_back(temp[0].first);
            result.push_back(v);
        }

        return result;
    }
};