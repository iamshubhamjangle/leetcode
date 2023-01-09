#include <bits/stdc++.h>
using namespace std;

template<typename T>
void print(vector<T> &v) { cout << "vector<T> = ["; for(int i=0; i<v.size(); i++) { cout << v[i]; if(i<v.size()-1) cout << ","; } cout << "]" << endl; }

template<typename T>
void print(vector<vector<T>> &v) { int n = v.size(); int m = v[0].size(); cout << "vector<vector<T>> = ["; for(int i=0; i<n; i++) { cout << "["; for(int j=0; j<m; j++) {cout << v[i][j]; if(j<m-1) cout << ","; } cout << "]"; } cout << "]" << endl; }


int main(){
    // unordered_map<pair<int,int>, int> um;
    map<pair<int,int>, int> um;

    um[{0,0}]++;
    um[{0,0}]++;
    um[{1,1}]++;
    um[{1,1}]++;
    um[{1,1}]++;
    
    cout << um[{0,0}] << endl;
    cout << um[{1,1}] << endl;
}