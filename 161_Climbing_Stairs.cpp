/*
Climbing_Stairs.cpp

https://leetcode.com/problems/climbing-stairs/
1. Recursion TC: O(2^N) SC: O(1)
2. Memoisation TC: O(N) SC: O(N)
3. Tabulation TC: O(N) SC: O(N)
4. Space optimisation TC: O(N) SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// 1. Recursion TC: O(2^N) SC: O(1)
// int climbStairs(int n) {
//     if(n==0) return 1;
//     if(n==1) return 1;
    
//     int l = climbStairs(n-1);
//     int r = climbStairs(n-2);
    
//     return l + r;
// }


// 2. Memoisation TC: O(N) SC: O(N)
// int helper(int n, vector<int> &v) {
//     if(n==0) return 1;
//     if(n==1) return 1;
    
//     if(v[n] != -1)
//     	return v[n];

//     int l = helper(n-1, v);
//     int r = helper(n-2, v);
    
//     return v[n] = l + r;
// }

// int climbStairs(int n) {
// 	vector<int> v(n+1, -1);
// 	return helper(n, v);
// }


// 3. Tabulation TC: O(N) SC: O(N)
// int climbStairs(int n) {
// 	if(n <= 1) return 1;

// 	vector<int> v(n+1, -1);
// 	v[0] = 1;
// 	v[1] = 1;

// 	for(int i=2; i<=n; i++) {
// 		v[i] = v[i-1] + v[i-2];
// 	}

// 	return v[n];
// }


// 4. Space optimisation TC: O(N) SC: O(1)
int climbStairs(int n) {
	if(n <= 1) return 1;

	int prev0 = 1;
	int prev1 = 1;

	for(int i=2; i<=n; i++) {
		int temp = prev0;
		prev0 = prev1;
		prev1 = temp + prev1;
	}

	return prev1;
}

int main(){
	int t;
	cin >> t;		//input no. of test cases
	while(t--){
		int n; cin >> n;
		cout << climbStairs(n);	//run this 't' times
		cout << endl;
	}
}





