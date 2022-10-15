#include <bits/stdc++.h>
 
typedef long double LD;
typedef long long LL;
typedef int64_t I64;

// Many of the solutions require mod by 10e^9+7
#define MOD 1000000007

// The least significant bit
#define LSB(i) ((i) & -(i))
 
using namespace std;

// Print Vector string:
void print(vector<string> &v) {
    for(auto i: v) cout << i << ", ";
    cout << endl;
}

// Print Vector int:
void print(vector<int> &v) {
    for(auto i: v) cout << i << ", ";
    cout << endl;
}

// Print vector of vector
void print(vector<vector<int>> &v) {
  cout << "[";
  for(auto i: v) { cout << "["; for(auto j: i) cout << j << ","; cout << "]"; }
  cout << "]" << endl;
}

int solve() {



}

int main() {
    int t;
    cin>>t;
    int te=t;
    while(t--)
    {
        int ans=0;
        // Inputs

        // Logic
        ans = solve(n, d, id, v);

        // output
        cout<< "Case #" << te-t << ": " << ans << endl;
    }

    return 0;
}