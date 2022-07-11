/*
Bit_Difference.cpp

You are given two numbers A and B. The task is to count the number of bits 
needed to be flipped to convert A to B.

Input: A = 10, B = 20
Output: 4
Explanation:
A  = 01010
B  = 10100
As we can see, the bits of A that need 
to be flipped are 01010. If we flip 
these bits, we get 10100, which is B.

Input: A = 20, B = 25
Output: 3

https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1#
Method: __builtin_popcount(a^b) TC: O(log N) SC: O(1).

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countBitsFlip1(int a, int b){   
        return __builtin_popcount(a^b);
    }
    
    int countBitsFlip(int a, int b){
        int count=0;
        int c=a^b;
        while(c>=1){
            int d=c&1;
            if(d==1)count++;
            c=c>>1;
        }
        return count;
    }
};

int main() {
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b

        Solution ob;
		cout<<ob.countBitsFlip(a, b)<<endl;
	}
	return 0;
}