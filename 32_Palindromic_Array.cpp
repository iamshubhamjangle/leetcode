/*
Palindromic_Array 
A palindromic number (also known as a numeral palindrome or a numeric palindrome) is a number (such as 16461) that remains the same when its digits are reversed.

Input:
2
5
111 222 333 444 555
3
121 131 20

Output:
1
0

https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1
Method 1: TC: O(n)
	- looop through each element find rev of the num.
	- if rev != arr[i] return 0; else return 1;
*/

#include<iostream>
#include<string.h>
using namespace std;

class Solution {
public:
    int PalinArray(int a[], int n) {
		for(int i=0; i<n; i++) {
			int num = a[i];
			int rev = 0;
			
			//find the reverse of the num
			while(num > 0) {
				rev = rev*10 + num%10;
				num = num/10; 
			}

			if(rev != a[i]) {
				return 0;
			}
		}
		return 1;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}