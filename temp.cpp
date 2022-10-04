#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<int, int>> solve(int arr1[], int arr2[], int n, int m) {
    vector<pair<int, int>> ans;
    unordered_map<int, int> um;

    for(int i=0; i<n; i++) um[arr1[i]]++;

    for(int i=0; i<m; i++)
        if(um.find(arr2[i]) != um.end())
            ans.push_back({arr2[i], um[arr2[i]]});

    return ans;
}

int main() {
    int arr1[] = {3, 7, 2, 2, 15, 15};
    int arr2[] = {10, 3, 9, 2};

    vector<pair<int, int>> sol = solve(arr1, arr2, 7, 4);

    for (pair<int,int> pr : sol) {
        if(pr.second>1){
            cout << pr.first << " ";
        }
    }

    return 0;
}