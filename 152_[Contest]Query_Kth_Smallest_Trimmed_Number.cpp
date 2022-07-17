/*
[Contest-Medium]Query_Kth_Smallest_Trimmed_Number.cpp
https://leetcode.com/problems/query-kth-smallest-trimmed-number/

Input: nums = ["102","473","251","814"], queries = [[1,1],[2,3],[4,2],[1,2]]
Output: [2,2,1,0]

*/

#include <bits/stdc++.h>
using namespace std;

void print(vector<int> a) {	for(auto i: a) cout << i << " "; cout << endl; }
void print(vector<string> a) {	for(auto i: a) cout << i << " "; cout << endl; }

vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
	int n = nums.size();
	int m = queries.size();
	vector<int> ans;
    for(int i=0; i<m; i++) {
    	vector<pair<string, int>> v; 
    	for(int j=0; j<n; j++) {
    		v.push_back({ (nums[j].substr(nums[j].size() - queries[i][1])), j});
    	}
    	sort(v.begin(), v.end());
    	ans.push_back(v[queries[i][0]-1].second);
    }
    return ans;
}

int main(){
	vector<string> nums;
	vector<vector<int>> queries;
	
	nums = {"102","473","251","814"};
	queries = {{1,1},{2,3},{4,2},{1,2}};
	print(smallestTrimmedNumbers(nums, queries));
}