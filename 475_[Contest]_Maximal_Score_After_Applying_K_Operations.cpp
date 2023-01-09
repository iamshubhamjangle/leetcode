/*
Maximal_Score_After_Applying_K_Operations.cpp
*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> void print(vector<T> &v) { cout << "vector<T> = ["; for(int i=0; i<v.size(); i++) { cout << v[i]; if(i<v.size()-1) cout << ","; } cout << "]" << endl; }
template<typename T> void print(vector<vector<T>> &v) { int n = v.size(); int m = v[0].size(); cout << "vector<vector<T>> = ["; for(int i=0; i<n; i++) { cout << "["; for(int j=0; j<m; j++) {cout << v[i][j]; if(j<m-1) cout << ","; } cout << "]"; } cout << "]" << endl; }

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end()); // max pq
        long long score = 0;
        
        while(k--) {
        	int temp = pq.top(); pq.pop();
			score += temp;
			temp = ceil(temp*1.0/3);
			pq.push(temp);
        }
        
        return score;
    }
};




int main(){
	Solution s;
	vector<int> nums;

	nums = {1,10,3,3,3};
	cout << s.maxKelements(nums, 3) << endl;
	
}