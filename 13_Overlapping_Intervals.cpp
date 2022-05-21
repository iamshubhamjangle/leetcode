/*
Overlapping_Intervals

Given a collection of Intervals, the task is to merge all of the overlapping Intervals.

Input 1:
Intervals = {{1,3},{2,4},{6,8},{9,10}}
Output: {{1, 4}, {6, 8}, {9, 10}}

Input 2:
Intervals = {{6,8},{1,9},{2,4},{4,7}}
Output: {{1, 9}}

https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1
Method 1: sort, put in stack then compare then return TC: O(N log N), SC: O(N)
Method 2: sort, Compare within array and push_back() or replace existing value TC: O(N logN), SC: O(1)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        // vector<vector<int>> ans;
        // sort(intervals.begin(),intervals.end());
         
        // //store first intervals[0][0] and intervals[0][1];
        // ans.push_back(intervals[0]);
        // int j=0;
         
        // int n = intervals.size();
        // for(int i=1;i<n;i++) {
        //     if(ans[j][1]>=intervals[i][0]) {
        //         ans[j][1] = max(intervals[i][1],ans[j][1]);
        //     }
        //     else if(ans[j][1]<intervals[i][0]) {
        //         ans.push_back(intervals[i]);
        //         j++;
        //     }
        // }
        // return ans;

    // }
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        stack<vector<int>> st;
        st.push(intervals[0]);

        for(int i=1; i<intervals.size(); i++) {
        	vector<int> v = st.top();
        	int element1 = v[0];
        	int element2 = v[1];

        	if(element2 >= intervals[i][0] && element2 >= intervals[i][1]) {
        		continue;
        	} else if(element2 >= intervals[i][0] && element2 < intervals[i][1]) {
        		//merge
        		vector<int> newInterval;
        		newInterval.push_back(element1);
        		newInterval.push_back(intervals[i][1]);

        		st.pop();				//remove old interval from stack
        		st.push(newInterval);	//push new interval to stack
        	} else {
        		st.push(intervals[i]);
        	}
        }


        stack<vector<int>> stReverseCopy;
        while(!st.empty()) {
        	stReverseCopy.push(st.top());
        	st.pop();
        }

        vector<vector<int>> ans;
        while(!stReverseCopy.empty()) {
        	ans.push_back(stReverseCopy.top());
        	stReverseCopy.pop();
        }

        return ans;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}