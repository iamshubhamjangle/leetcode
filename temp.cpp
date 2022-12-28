#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {11,12,13,14,15,15,16,17,19,19,19,20};
    // _________________0__1__2__3__4__5__6__7__8__9_10_11___________

    cout << upper_bound(arr.begin(), arr.end(),  9) - arr.begin() << endl;  // < bound - 0
    cout << upper_bound(arr.begin(), arr.end(), 11) - arr.begin() << endl;  // 1st idx - 1
    cout << upper_bound(arr.begin(), arr.end(), 12) - arr.begin() << endl;  // present - 2
    cout << upper_bound(arr.begin(), arr.end(), 15) - arr.begin() << endl;  // double  - 6
    cout << upper_bound(arr.begin(), arr.end(), 18) - arr.begin() << endl;  // missing - 8
    cout << upper_bound(arr.begin(), arr.end(), 22) - arr.begin() << endl;  // > bound - 12

    cout << lower_bound(arr.begin(), arr.end(),  9) - arr.begin() << endl;  // < bound - 0
    cout << lower_bound(arr.begin(), arr.end(), 11) - arr.begin() << endl;  // 1st idx - 0
    cout << lower_bound(arr.begin(), arr.end(), 12) - arr.begin() << endl;  // present - 1
    cout << lower_bound(arr.begin(), arr.end(), 15) - arr.begin() << endl;  // double  - 4
    cout << lower_bound(arr.begin(), arr.end(), 18) - arr.begin() << endl;  // missing - 8
    cout << lower_bound(arr.begin(), arr.end(), 22) - arr.begin() << endl;  // > bound - 12
}