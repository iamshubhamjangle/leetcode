/*
Power_of_2.cpp

Given a non-negative integer N. The task is to check if N is a power of 2. 
More formally, check if N can be expressed as 2x for some x.

Input: N = 1
Output: YES

Input: N = 98
Output: NO

https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1#
Method 1: bitwise &. O(1)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // bitwise & of num and (num-1) for 2powerx is always zero
    /*
    2       4       8       16
    10      100     1000    10000
    &       &       &       &
    1       3       7       15
    01      011     0111    01111
    ______________________________
    00      000     0000    00000
    */
    bool isPowerofTwo(long long n){
        return (n==0) ? 0 : (n&(n-1))==0;
    }
};

int main()
{

    int t;
    cin>>t;//testcases

    for(int i=0;i<t;i++)
    {
        long long n; //input a number n
        cin>>n;

        Solution ob;
         if(ob.isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;

    }

    return 0;
}