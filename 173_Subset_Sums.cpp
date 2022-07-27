/*
Subset_Sums.cpp

1. Bruteforce: PowerSet
2. Take-notake + sort: TC: O(2^n + 2^n*log(2^n)) SC: 2^n
*/




#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
	void helper(int idx, vector<int> &arr, int n, vector<int> &ans, int sum) {
		if(idx == n) {
			ans.push_back(sum);
			return;
		}

		helper(idx+1, arr, n, ans, sum+arr[idx]);
		helper(idx+1, arr, n, ans, sum);
	}

    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> ans;
    	helper(0, arr, N, ans, 0);
        return ans;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}