/*
Combination_Sum.cpp

Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B. 
The same number may be chosen from the array any number of times to make B.

Note:
1. All numbers will be positive integers.
2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
3. The combinations themselves must be sorted in ascending order.

Input:
N = 4
arr[] = {7,2,6,5}
B = 16
Output:
(2 2 2 2 2 2 2 2)
(2 2 2 2 2 6)
(2 2 2 5 5)
(2 2 5 7)
(2 2 6 6)
(2 7 7)
(5 5 6)

https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1
https://leetcode.com/problems/combination-sum/
Method: Backtracking all posibble sums

*/

#include <bits/stdc++.h>
using namespace std;

/*
base conditions:
1. When no element left in array || sum < 0;
2. if sum == 0; add it to ans;
*/
class Solution {
  public:
  	vector<vector<int>> ans;

  	void solve(int i, vector<int> &arr, vector<int> &temp, int target) {
  		//base conditions
		if(target == 0) {
			ans.push_back(temp);
			return;
		}

		if(target < 0 || i == arr.size()) {
			return;
		}

  		//recusive calls
  		solve(i+1, arr, temp, target);	// left
  		temp.push_back(arr[i]);			// 
  		solve(i, arr, temp, target - arr[i]);	// right
  		temp.pop_back();				// 
  	}

    vector<vector<int> > combinationSum(vector<int> &arr, int target) {
        ans.clear();
        vector<int> temp;
        solve(0, arr, temp, target);
		sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}