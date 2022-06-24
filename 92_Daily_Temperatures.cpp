/*
Daily_Temperatures.cpp

Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of days you have to 
wait after the ith day to get a warmer temperature. If there is no future 
day for which this is possible, keep answer[i] == 0 instead.

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Input: temperatures = [30,60,90]
Output: [1,1,0]

https://leetcode.com/problems/daily-temperatures/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// TLE - bruteforce: TC: O(N*N) SC: O(N)
    vector<int> dailyTemperatures1(vector<int>& arr) {
        int n = arr.size();
        if(n == 0)
        	return {};
    
        vector<int> ans;
        for(int i=0; i<n; i++) {
        	bool found = false;
            for(int j=i+1; j<n; j++) {
                if(arr[j] > arr[i]) {
                	found = true;
                    ans.push_back(j-i);
                    break;
                }
            }
            if(!found) ans.push_back(0);
        }
        
        return ans;
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
	    vector<int> res(temperatures.size());
	    for (int i = temperatures.size() - 1; i >= 0; --i) {
	        int j = i+1;
	        while (j < temperatures.size() && temperatures[j] <= temperatures[i]) {
	            if (res[j] > 0) j = res[j] + j;
	            else j = temperatures.size();
	        }
	        if (j < temperatures.size()) res[i] = j - i;
	    }
	    return res;
	}
};

int main(){
	int t;
	cin >> t;		//input no. of test cases
	while(t--){
		int n; cin >> n;
		vector<int> arr;
		while(n--) {
			int temp; cin >> temp;
			arr.push_back(temp);
		}

		Solution s;
		vector<int> ans = s.dailyTemperatures(arr);	//run this 't' times

		for(auto i: ans)
			cout << i << " ";

		cout << endl;
	}
}

