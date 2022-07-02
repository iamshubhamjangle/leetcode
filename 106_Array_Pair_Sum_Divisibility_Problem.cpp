/*
Array_Pair_Sum_Divisibility_Problem.cpp

Given an array of integers and a number k, write a function that returns true 
if given array can be divided into pairs such that sum of every pair is divisible by k.

Input : arr = [9, 5, 7, 3], k = 6
Output: True
Explanation: {(9, 3), (5, 7)} is a 
possible solution. 9 + 3 = 12 is divisible
by 6 and 7 + 5 = 12 is also divisible by 6.

Input : arr = [2, 4, 1, 3], k = 4
Output: False
Explanation: There is no possible solution.

https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1
Method 1: Hashing. TC: O(N) SC: O(N)
reference: https://www.youtube.com/watch?v=BvKv-118twg

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

  	// Frequency of remainder must match and should be equal to k -> number will be divisible
  	// e.g. k = 10, pair = {14, 26} freq = {4: 1, 6: 1} -> so for x remainder k-x must exist
  	// For numbers with freq 0 -> must occur in even count to pair up. bze they clash
  	// e.g. k = 10, pair = {60, 40} freq = {0: 2}
  	// For numbers with freq 5 -> must occur in even count to pair up. bze they clash
  	// e.g. k = 10, pair = {60, 40} freq = {0: 2}
    bool canPair(vector<int> nums, int k) {
    	// create frequency map
        unordered_map<int, int> um;
    	for(int i: nums) {
    		um[i % k]++;
    	}

    	for(auto i: nums) {
            int rem = i % k;

            // if freq of rem=0 is odd
            if(rem == 0) {
                if(um[rem] % 2 == 1)
                    return false;
            }
            // If freq of k/2 is odd
            else if(2 * rem == k) {
                if(um[rem] % 2 == 1)
                    return false;   
            }
            else {
                int fq = um[rem];
                int otherFq = um[k-rem];
                if(fq != otherFq)
                    return false;
            }
    	}

    	return true;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
        cout << "****************************\n";
    }
    return 0;
}