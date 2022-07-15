/*
find_sqrt_of_num.cpp

Given a non-negative integer x, compute and return the square root of x.
Since the return type is an integer, the decimal digits are truncated, 
and only the integer part of the result is returned.
Note: You are not allowed to use any built-in exponent function or operator, 
such as pow(x, 0.5) or x ** 0.5.

Input : x = 4
Output: 2

Input : x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.

https://leetcode.com/problems/sqrtx/
	Method 1: Using inbuilt function. pow(x, 0.5)
	Method 2: Using iterative method upto N/2. TLE. O(N) O(1)
	Method 3: Binary search. TC: O(log N) SC: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

/* Method 1: Using inbuilt function */
int mySqrt1(int x) {
	return pow(x, 0.5);
}

/* TC: O(N) SC: O(1)
Method 2: Using iterative method upto N/2.
sqrt of a number is always within 1-n/2 range.
*/
int mySqrt2(int x) {
    if(x <= 1) return x;
    
    int res = 1;
    for(int i=1; i<=x/2; i++) {
        if(i <= x/i) {
            res = i;
        }
    }
    return res;
}


/* Method 3: TC: O(log N) SC: O(1)
Square root of num lies between 1 - n/2;
Binary search
*/
int mySqrt(int x) {
	if(x <= 1) return x;

	int l = 1;
	int h = x;

	while(l <= h) {
		int mid = l + (h-l)/2;

		if(mid == x/mid)	// x/mid to avoid overflow of int <> int comparision
			return mid;

		if(mid >= x/mid) {
			h = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	return h;
}

int main(){
	int t;
	cin >> t;		//input no. of test cases
	while(t--){
		int x;
		cin >> x;
		cout << mySqrt(x) << endl;	//run this 't' times
	}
}


