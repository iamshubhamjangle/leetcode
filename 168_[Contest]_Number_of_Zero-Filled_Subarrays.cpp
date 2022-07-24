/*
[Contest]_Number_of_Zero-Filled_Subarrays.cpp

https://leetcode.com/contest/biweekly-contest-83/problems/number-of-zero-filled-subarrays/
Bruteforce: TC: O(N*N) SC: O(1)
Two pointer. TC: O(N) SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
// Bruteforce: TC: O(N*N) SC: O(1)
// long long zeroFilledSubarray(vector<int>& nums) {
// 	int n = nums.size();
// 	long long count = 0;
// 	for(int i=0; i<n; i++) {
// 		for(int j=i; j<n; j++) {
// 			bool onlyzero = true;
// 			for(int k=i; k<=j; k++) {
// 				if(nums[k] != 0) onlyzero = false;
// 			}
// 			if(onlyzero)
// 				count++;
// 		}
// 	}
// 	return count;
// }

// Two pointer. TC: O(N) SC: O(1)
long long zeroFilledSubarray(vector<int>& nums) {
    long long res = 0;
    for (int i = 0, j = 0; i < nums.size(); ++i) {
        if (nums[i] != 0)
            j = i + 1;
        res += i - j + 1;
    }
    return res;
}

int main(){
	vector<int> n1 = {1,3,0,0,2,0,0,4};
	cout << zeroFilledSubarray(n1) << endl;
	vector<int> n2 = {0,0,0,2,0,0};
	cout << zeroFilledSubarray(n2) << endl;
	vector<int> n3 = {0,-9,6,-5,0,0,8,0,0,3,-3};
	cout << zeroFilledSubarray(n3) << endl;
}
