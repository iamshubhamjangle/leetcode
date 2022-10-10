/*


*/

#include <bits/stdc++.h>
using namespace std;

int minGroups(vector<int> arr, int k) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int ans = 1;

    int limit = arr[0] + k;
    int i = 0;
    while(i < n) {
        if(arr[i] > limit) {
            ans++;
            limit = arr[i] + k;
        }
        i++;
    }

    return ans;
}

int main(){
    vector<int> arr = {1,13,6,8,9,3,5};
    cout << minGroups(arr, 4) << endl;
}