/*
Number_of_1_Bits.cpp

Given a positive integer N, print count of set bits in it. 

Input : N = 6
Output: 2

Input : 8
Output: 1

https://practice.geeksforgeeks.org/problems/set-bits0143/1


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int setBits1(int N) {
        int count = 0;
        while(N) {					// While N is not zero
        	count = count + N%2;	// add N%2 to count (note: N is not changed here)
        	N = N >> 1;				// Right shift bits / N = N/2; to get next bit
        }
        return count;
    }

    // more shorter but diff approach
    int setBits(int N) {
        int count = 0;
        while(N) {					// While N is not zero
        	N = N & (N-1);			// remove the 1 (high) bit from N.
        	count++;				// count the removed 1
        }
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}