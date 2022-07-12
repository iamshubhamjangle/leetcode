/*
Count_total_set_bits.cpp

You are given a number N. Find the total count of set bits for all numbers from 1 to N
(both inclusive).

Input: N = 4
Output: 5

Input: N = 17
Output: 35

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1
	- Method 1: Get last bit for each num TC: O(N*N) SC: O(1)
	- Method 2: finding common in elements upto 2^x. Using same for rest. TC: O(N) SC: O(1)
	reference: https://www.youtube.com/watch?v=g6OxU-hRGtY

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // get last bit for each num O(N*N)
    int countSetBits(int n) {
        int count = 0;
        while(n) {
        	int temp = n;
        	while(temp) {
        		temp = temp & (temp-1);
        		count++;
        	}
        	n--;
        }
        return count;
    }

    // Using maths to find last bit: O(N*N)
    int countSetBits(int n) {
		int count=0;
		int r=0;
		int i=1;
		int x=0;

		while(i<=n) {			// loop from 1 - n
			x=i;
			while(x>0) {		// while each num is > 0;
				r=x%2;			// get the last digit
				if(r==1)		// if its 1, count++
					count++;
				x=x/2;			// remove the last digit
			}
			i++;				// go to next num
		}
		return count;
   }


   // Method 3: finding common in elements upto 2^x. Using same for rest. TC: O(N) SC: O(1)
   int countSetBits(int n) {
		if(n == 0) return 0;
		
		int x = largestPowerOf2inRange(n);
		int bitsTill2x = x * (1 << (x-1));
		int msbxton = n - (1 << x) + 1;
		int rest = n - (1 << x);
		int ans = bitsTill2x + msbxton + countSetBits(rest);
		return ans;
   }
   
   int largestPowerOf2inRange(int n) {
       int x = 0;
       while((1 << x) <= n) {
           x++;
       }
       return x-1;
   }
};

int main() {
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}