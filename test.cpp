#include <bits/stdc++.h>
using namespace std;

void solve();

int ZeroPairSum(int n, vector<int> arr){
    return 1;
}

int main(){
    cout << "main()" << endl;
    int t;
    cin >> t;
    while(t--){
        solve();    //run this 't' times
    }
}

void solve() {
    cout << "solve" << endl;
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "solve 2" << endl;

    cout << ZeroPairSum(n, arr) << endl;
}