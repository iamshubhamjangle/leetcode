/*
Count_Number_of_Distinct_Integers_After_Reverse_Operations.cpp

https://leetcode.com/contest/weekly-contest-315/problems/count-number-of-distinct-integers-after-reverse-operations/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int reverseThisNum(int n) {
		string s = to_string(n);
		reverse(s.begin(), s.end());
		return stoi(s);
	}

    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> freq;
        for(int i=0; i<n; i++) {
        	freq[nums[i]]++;
        	int rev = reverseThisNum(nums[i]);
        	freq[rev]++;
        }

        return freq.size();
    }
};

int main(){
	Solution s;
	vector<int> nums;

	nums = {1,13,10,12,31};	// 6
	cout << s.countDistinctIntegers(nums) << endl;
	
	nums = {2,2,2};	// 1
	cout << s.countDistinctIntegers(nums) << endl;
}