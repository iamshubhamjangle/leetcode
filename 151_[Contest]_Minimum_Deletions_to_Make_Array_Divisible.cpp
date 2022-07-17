/*
[Contest-Hard]Minimum_Deletions_to_Make_Array_Divisible.cpp
https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/
*/

#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& A, vector<int>& numsDivide) {
    int g = numsDivide[0];
    for (int a: numsDivide)
        g = gcd(g, a);
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size() && A[i] <= g; ++i)
        if (g % A[i] == 0)
            return i;
    return -1;
}


int main(){
	vector<int> nums = {2,3,2,4,3};
	vector<int> numsDivide = {9,6,9,3,15};
	cout << minOperations(nums, numsDivide) << endl;
}