/*
Look_and_Say_Pattern 

Given an integer n. Return the nth row of the following look-and-say pattern.
1
11
21
1211
111221

Input:
n = 5
Output: 111221

Input:
n = 3
Output: 21

https://practice.geeksforgeeks.org/problems/decode-the-pattern1138/1
Method 1: Bruteforce: TC: dont_know. SC: dont_know
	- Recursion calculate prev and use it to calculate next.
	- video explaination: https://www.youtube.com/watch?v=_nky2KlUWhc
*/

#include<bits/stdc++.h> 
using namespace std;

class Solution {
  public:
    string lookandsay(int n) {
        if(n == 1) return "1";
        if(n == 2) return "11";

        string result = lookandsay(n-1);	//recursion call to cal prev result

        string newResult = "";
        int count = 1;

        for(int i=1; i<result.size(); i++) {
        	if(result[i] != result[i-1]) {
        		newResult.push_back('0' + count);
        		newResult.push_back(result[i-1]);
        		count = 1;
        	} else {
        		count++;
        	}

        	if(i == result.size() - 1) {
        		newResult.push_back('0' + count);
        		newResult.push_back(result[i]);
        	}
        }

        return newResult;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}