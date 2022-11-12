/*
Running_in_Circles.cpp

Kickstart Round H 2022
*/

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

int solve(int l, int n) {
    int d; char c;   // distance, direction

    int count = 0;
    int lsum = 0;
    int rsum = 0;

    for(int i=0; i<n; i++) {
        cin >> d >> c;
        if(c == 'C')
            rsum += d;
        else
            lsum -= d;
        cout << "sum: " << sum << endl;
    }

    // cout << "cwSum: "<<cwSum<<" acwSum: "<<acwSum<<endl;

    return floor(abs(sum) / l);
}

int main() {
    int t;
    cin>>t;
    int te=t;
    while(t--)
    {
        int ans=0;
        // Inputs
        int l, n;   // length, no of runs
        cin >> l >> n;
        // Logic
        ans = solve(l, n);

        // output
        cout<< "Case #" << te-t << ": " << ans << endl;
    }

    return 0;
}