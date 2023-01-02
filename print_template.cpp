#include <bits/stdc++.h>
using namespace std;

template<typename T>
void print(vector<T> &v) { cout << "vector<T> = ["; for(int i=0; i<v.size(); i++) { cout << v[i]; if(i<v.size()-1) cout << ","; } cout << "]" << endl; }

template<typename T>
void print(vector<vector<T>> &v) { int n = v.size(); int m = v[0].size(); cout << "vector<vector<T>> = ["; for(int i=0; i<n; i++) { cout << "["; for(int j=0; j<m; j++) {cout << v[i][j]; if(j<m-1) cout << ","; } cout << "]"; } cout << "]" << endl; }

int main() {
    vector<int> v1 = {1,2,3,3,4,5,5,6,7,8};
    vector<char> v2 = {'a','b','c','d','e','f'};
    vector<string> v3 = {"shubham","aniket"};

    print(v1);
    print(v2);
    print(v3);

    vector<vector<int>> v4 = {{1,2,3},{3,4,5},{5,6,7}};
    vector<vector<char>> v5 = {{'a','b'},{'d','e'}};
    vector<vector<string>> v6 = {{"shubham", "sanket"},{"aniket", "chiku"}};

    print(v4);
    print(v5);
    print(v6);
}