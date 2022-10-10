/*
[Contest]_The_Employee_That_Worked_on_the_Longest_Task.cpp

https://leetcode.com/contest/weekly-contest-314/problems/the-employee-that-worked-on-the-longest-task/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int difference = logs[0][1]-0;
        int id = logs[0][0];
        for(int i=1; i<=logs.size()-1; i++){
            int ans = logs[i][1]-logs[i-1][1];
            if(ans == difference){
                id = min(id,logs[i][0]);
            }
            if(ans > difference){
                difference = ans;
                id = logs[i][0];
            }
        }
        return id;
    }
};


int main(){
	Solution s;
	vector<vector<int>> logs;

	logs = {{0,3},{2,5}, {0,9}, {1,15}};
	cout << s.hardestWorker(10, logs) << endl;

	logs = {{1,1},{3,7}, {2,12}, {7,17}};
	cout << s.hardestWorker(10, logs) << endl;
}