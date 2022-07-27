/*
Combination_Sum_II.cpp

base case - when target == 0 that our combination
if currSum > target. we cannot go further.
when we previously pickup x we cannot pick it up again. continue.

https://leetcode.com/problems/combination-sum-ii/
1. Take-noTake. Use set to avoid duplicate. 
    - TC: O(2^n*k*log(m)),  SC: k*n
    - m = set size 
2. Iterate Take. No take. 
    - TC: O(2^n*k),    SC: O(k*x)
*/

#include <bits/stdc++.h>
using namespace std;

// Method 1: take no take technique. Elements wont repeat (so use i+1). Use set to avoid duplicates.
// TC: 2^n * k * log(m) // m= set size SC: k*n
void findCombination(int i, int target, vector<int> &candidates, set<vector<int>> &ans, vector<int> ds) {
    if(i == candidates.size()) {
        if(target == 0) {
            ans.insert(ds);
        }
        return;
    }

    if(candidates[i] <= target) {
        ds.push_back(candidates[i]);
        findCombination(i+1, target - candidates[i], candidates, ans, ds);   // pick (i will remain same as elements can repeat)
        ds.pop_back();
    }

    findCombination(i+1, target, candidates, ans, ds);      // nopick
}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> ds;
    set<vector<int>> temp;
    findCombination(0, target, candidates, temp, ds); 
    
    // convert set of vector to vector of vector
    vector<vector<int>> ans;

    for(auto it: temp) {
        vector<int> vec;
        for(auto v: it) {
            vec.push_back(v);
        }
        ans.push_back(vec);
    }

    return ans;
}

// Method 2: Iterating each subsequence to find combination sum. 
// sort the array to make sure output ans is sorted
// TC: O(2^n*k),    SC: O(k*x)
void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int>&ds) {
    if(target==0) {
        ans.push_back(ds);
        return;
    }
    
    for(int i = ind; i<arr.size(); i++) {
        if(i>ind && arr[i]==arr[i-1]) continue; // if i==ind we must not check previous
        if(arr[i]>target) break; 
        ds.push_back(arr[i]);
        findCombination(i+1, target - arr[i], arr, ans, ds); 
        ds.pop_back(); 
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans; 
    vector<int> ds; 
    findCombination(0, target, candidates, ans, ds); 
    return ans;
}


int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> arr = combinationSum2(candidates, target);

    for( auto &row : arr) {
        for(auto col : row)
             cout << col << " ";
        cout<<endl; 
    }
}