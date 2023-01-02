#include <bits/stdc++.h>
using namespace std;

template<typename T>
void print(vector<T> &v) { cout << "vector<T> = ["; for(int i=0; i<v.size(); i++) { cout << v[i]; if(i<v.size()-1) cout << ","; } cout << "]" << endl; }

template<typename T>
void print(vector<vector<T>> &v) { int n = v.size(); int m = v[0].size(); cout << "vector<vector<T>> = ["; for(int i=0; i<n; i++) { cout << "["; for(int j=0; j<m; j++) {cout << v[i][j]; if(j<m-1) cout << ","; } cout << "]"; } cout << "]" << endl; }

/*
a-a: 0
a-A: 32
a  : 97
___________________
z-a: 25
z-A: 57
z  : 122
___________________
A-a: -32
A-A: 0
A  : 65
___________________
Z-a: -7
Z-A: 25
Z  : 90
*/

int main(){
    string word = "azAZ";
    
    for(auto ch: word) {
        cout << "___________________" << endl;
        cout << ch << "-a: " << ch - 'a' << endl;
        cout << ch << "-A: " << ch - 'A' << endl;
        cout << ch << "  : " << (int) ch << endl;
    }

    cout << islower('a') << endl;
    cout << isupper('a') << endl;
}