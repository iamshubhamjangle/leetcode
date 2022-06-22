/*
Middle_of_Three.cpp

Given three distinct numbers A, B and C. 
Find the number with value in middle (Try to do it with minimum comparisons).

Input : A = 978, B = 518, C = 300
Output: 518

Input : A = 162, B = 934, C = 200
Output: 200

https://practice.geeksforgeeks.org/problems/middle-of-three2926/1#
Method 1: 8 comparision using &&
Method 2: 4 comparision using min,max
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
  // 8 comparision
    int middle(int A, int B, int C){
        if((A > B && B > C) || (A < B && B < C))
            return B;
        else if((B > C && C > A) || (B < C && C < A))
            return C;
        else
            return A;
    }
    
    // 4 comparision
    int middle2(int A, int B, int C){
        
       int m= max(A,max(B,C));
       int n= min(A,min(B,C));
       
       int ans= (A+B+C)-(m+n);
       return ans;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
}