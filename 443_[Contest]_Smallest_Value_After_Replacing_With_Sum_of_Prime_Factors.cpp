/*
Smallest_Value_After_Replacing_With_Sum_of_Prime_Factors.cpp

https://leetcode.com/contest/weekly-contest-324/problems/smallest-value-after-replacing-with-sum-of-prime-factors/
*/

#include <iostream>
#include <numeric>
class Solution {
public:

	#define MAXN 100001
	int spf[MAXN];
	void init() {
	  spf[1] = 1;
	  for (int i=2; i<MAXN; i++) spf[i] = i;

	  for (int i=4; i<MAXN; i+=2) spf[i] = 2;

	  for (int i=3; ii<MAXN; i++) {
	    if (spf[i] == i) {
	      for (int j=ii; j<MAXN; j+=i)
	        if (spf[j]==j) spf[j] = i;
	    }
	  }
	}

	bool isPrime(int n) {
	    if (n <= 1)
	        return false;
	    for (int i = 2; i * i <= n; i++) {
	        if (n % i == 0)
	            return false;
	    }
	    return true;
	}

	vector<int> getFactorization(int x) {
	  vector<int> ret;
	  while (x != 1) {
	    ret.push_back(spf[x]);
	    x = x / spf[x];
	  }
	  return ret;
	}

	int smallestValue(int n) {
	    init();
	    if(n <= 4)return n;
	    while(!isPrime(n)){
	        vector <int> p = getFactorization(n);
	        int a= 0;
	        for(int i= 0; i< p.size();i++) {
	            a += p[i];
	        }
	        n = a;
	    }
	    return n;
	}
};