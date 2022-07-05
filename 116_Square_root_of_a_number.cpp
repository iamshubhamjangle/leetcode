/*
Square_root_of_a_number.cpp

Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).

Input : x = 5
Output: 2

Input : x = 4
Output: 2

https://practice.geeksforgeeks.org/problems/square-root/1#
Method 1: Internal function TC: O(x^0.5) SC: O(1)
Method 2: Iterate n/2. 		TC: O(N) SC: O(1)
Method 3: Binary Search. 	TC: O(logN) SC: O(1)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        if(x == 1) return 1;
        for(int i=2; i<=x/2; i++) {
            if(i*i == x) return i;
            else if(i*i > x) return i-1;
        }
    }
  
    long long int floorSqrt1(long long int x) 
    {
        return sqrt(x);
    }
  
    long long int floorSqrt2(long long int x) 
    {
        if(x == 1) return 1;
        long long l = 1;
        long long h = x/2;    // bze the square root of x always lies below x/2
        long long ans;
        
        while(l<=h) {
            long long mid = l + (h-l)/2;
            long long sqr = mid * mid;
            if(sqr > x) {
                h = mid - 1;
            } else if(sqr < x) {
                ans = mid;
                l = mid + 1;
            } else {
                return mid;
            }
        }
        
        return ans;
    }
};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}