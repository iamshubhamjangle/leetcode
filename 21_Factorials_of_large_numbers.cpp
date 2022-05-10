/*
Factorials_of_large_numbers.cpp

Given an integer N, find its factorial.

Example 1:
Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120

Example 2:
Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1#
Method 1: time: O(N*N), space: O(N)
- take a resultVector insert 1 into it
- iterate from 2 to N
- iterate from 0 to resultVector.size and keep a carry
- reverse the vector and return
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Method 1: time: O(N*N), space: O(N)
	vector<int> factorial(int N){
        vector<int>res;
        res.push_back(1);
        for(int j=2;j<=N;j++){
            int carr=0;
            for(int i=0;i<res.size();i++){
                int val=res[i]*j+carr;
                res[i]=val%10;
                carr=val/10;
            }
            while(carr!=0){
                res.push_back(carr%10);
                carr/=10;
            }
        }
        reverse(res.begin(),res.end());
        return res;
   }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}