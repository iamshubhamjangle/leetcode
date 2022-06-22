/*
Count_Squares.cpp

Consider a sample space S consisting of all perfect squares starting from 1, 4, 9 and so on. 
You are given a number N, you have to output the number of integers less than N in the 
sample space S.

Input : N = 9
Output: 2

Input : N = 3
Output: 1

https://practice.geeksforgeeks.org/problems/count-squares3649/1#
Method 1: loop and check i*i > n. TC: O(N), SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSquares(int n) {
        int i;
        for(i=0; i<n; i++) {
            if(i*i >= n)
                break;
        }
        
        return i-1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}