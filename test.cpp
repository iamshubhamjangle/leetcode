#include <bits/stdc++.h>
using namespace std;

void solve() {
    unordered_map<int, int> um;

    um[1]++;
    um[2]++;
    um[2]++;
    um[3]++;
    um[4]++;
    cout << "size: "<< um.size() << endl;
    um[3]--;
    cout << "size: "<< um.size() << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();    //run this 't' times
    }
}