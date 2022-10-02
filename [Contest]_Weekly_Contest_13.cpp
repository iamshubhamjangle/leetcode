#include <bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/number-of-common-factors/
class Solution {
public:
    int commonFactors(int a, int b) {
        int goUpto = min(a,b);
        int count = 0;
        for(int i=1; i<=goUpto; i++) {
            if(a%i == 0 && b%i == 0) count++;
        }
        return count;
    }
};


// https://leetcode.com/problems/maximum-sum-of-an-hourglass/
class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
    	int n = grid.size();
    	int m = grid[0].size();
    	int maxSum = 0;

    	for(int i=0; i<=n-3; i++) {
    		for(int j=0; j<=m-3; j++) {
    			int sum = grid[i][j] + grid[i][j+1] + grid[i][j+2] 
    								 + grid[i+1][j+1] 
    					+ grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
    			maxSum = max(sum, maxSum);
    		}
    	}

    	return maxSum;
    }
};


// https://leetcode.com/problems/minimize-xor/
class Solution {
public:
    int countNumberOfSetBits(int num2) {
        int count=0;

        while(num2!=0) {
            if((num2 & 1) == 1) count++;
            num2 = num2 >> 1;
        }
        
        return count;
    }

    int minimizeXor(int num1, int num2) {
		int a = num1;
		int b = countNumberOfSetBits(num2);
		int numSetBits = b;
		int ans = 0;

		for(int i=31;i>=0 && numSetBits>0;i--) {
		    if((a & (1<<i))>0) {
		        ans = ans | (1<<i);
		        numSetBits--;

		    }
		}

		for(int i=0 ;i<=31 && numSetBits >0 ;i++) {
		    if((a & (1<<i)) == 0) {
		        ans = ans |(1<<i);
		        numSetBits--;
		    }
		}
		return ans;
    }
};


// https://leetcode.com/problems/maximum-deletions-on-a-string/
class Solution {
public:
    int deleteString(string s) {
        int n = s.size();
        vector<vector<int>> lcs(n + 1, vector<int>(n + 1, 0));
        vector<int> dp(n, 1);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j])
                    lcs[i][j] = lcs[i + 1][j + 1] + 1;
                if (lcs[i][j] >= j - i)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return dp[0];
    }
};