/*
Minimum_Rounds_to_Complete_All_Tasks.cpp

https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
*/
#include <bits/stdc++.h>
using namespace std;

template<typename T>
void print(vector<T> &v) { cout << "vector<T> = ["; for(int i=0; i<v.size(); i++) { cout << v[i]; if(i<v.size()-1) cout << ","; } cout << "]" << endl; }

template<typename T>
void print(vector<vector<T>> &v) { int n = v.size(); int m = v[0].size(); cout << "vector<vector<T>> = ["; for(int i=0; i<n; i++) { cout << "["; for(int j=0; j<m; j++) {cout << v[i][j]; if(j<m-1) cout << ","; } cout << "]"; } cout << "]" << endl; }

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        int rounds = 0;

        unordered_map<int,int> um;
        for(auto &n: tasks) um[n]++;

        for(auto &[k,v]: um) {
            if(v == 1) return -1;
            rounds += (v + 2) / 3;
            // rounds += int(v/3) + bool(v%3);  // add 1 if it's not divisible by 3
        }

        return rounds;
    }
};

int main(){
    Solution s;
    vector<int> tasks;

    tasks = {2,2,3,3,2,4,4,4,4,4};
    cout << s.minimumRounds(tasks) << endl;

    tasks = {2,3,3};
    cout << s.minimumRounds(tasks) << endl;

    tasks = {3,3,3,3};
    cout << s.minimumRounds(tasks) << endl;
}