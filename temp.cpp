#include <bits/stdc++.h>
using namespace std;

template<typename T>
void print(vector<T> &v) { cout << "vector<T> = ["; for(int i=0; i<v.size(); i++) { cout << v[i]; if(i<v.size()-1) cout << ","; } cout << "]" << endl; }

template<typename T>
void print(vector<vector<T>> &v) { int n = v.size(); int m = v[0].size(); cout << "vector<vector<T>> = ["; for(int i=0; i<n; i++) { cout << "["; for(int j=0; j<m; j++) {cout << v[i][j]; if(j<m-1) cout << ","; } cout << "]"; } cout << "]" << endl; }


// class Solution {
// public:
//     int alternateDigitSum(int n) {
//         string s = to_string(n);
//         bool add = true;
//         int sum = 0;
//         for(auto &ch: s) {
//             if(add) sum += (ch - '0');
//             else sum -= (ch - '0');
//             add = !add;
//         }
//         return sum;
//     }
// };

int main(){
    
}