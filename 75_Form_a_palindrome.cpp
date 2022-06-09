/*
Form_a_palindrome.cpp 

Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd

Input : str = "abcd"
Output: 3

Input : str = "aa"
Output: 0

https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1#
  - Solve like LCS: O(N*N) TC: O(N*N)

length of PS = 1 / # of deletion

i.e. To find minimum # of deletion we have to find max length of Palindromic subsequence.
so # of deletion = length(string) - length(PS)

LPS (longest Palindromic Subsequence) = LCS(s, reverse(s));

https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1#
// Method 1: Using LCS. TC: 2^n, SC: O(1)
// Method 2: Bottom up approach - Using Recusion + Matrix = Memoization.
// Method 3: Top down approach - Only Matrix. TC: O(N*M) SC: O(N*M)
reference: https://www.youtube.com/watch?v=AEcRW4ylm_c&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=31

*/


#include <bits/stdc++.h>
using namespace std;

/*
// Method 1: Using LCS. TC: 2^n, SC: O(1)
// # of insertion = length of string - LCS
// LCS will the LPS as we are checking for LCS(str, reverse(str)
// .: LPS (Longest Palindromic Subsequence) = n - LCS(s, reverse(s))
// https://www.youtube.com/watch?v=4Urd0a0BNng&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=19
class Solution{
  public:
    int LCS(string str1, string str2, int n, int m) {
      // base condition: if str is empty the lcs is zero
      if(n == 0 || m == 0)
          return 0;

      // If last two char are equal we will count it as palindrome
      // if not equal check if last char of str1 is present in str2 and vice versa
      if(str1[n-1] == str2[m-1])
          return 1 + LCS(str1, str2, n-1, m-1);
      else
          return max(LCS(str1, str2, n-1, m), LCS(str1, str2, n, m-1));
    }

    int countMin(string str){
      int n = str.size();
      string revStr { str };
      reverse(revStr.begin(), revStr.end());
      return n - LCS(str, revStr, n, n);
    }
};
*/

/*
// Method 2: Bottom up approach - Using Recusion + Matrix = Memoization.
int matrix[1001][1001];

class Solution{
  public:
    int LCS(string str1, string str2, int n, int m) {
      if(n == 0 || m == 0)
          return matrix[n][m] = 0;

      if( matrix[n][m] != -1)
          return matrix[n][m];

      if(str1[n-1] == str2[m-1])
          return matrix[n][m] = 1 + LCS(str1, str2, n-1, m-1);
      else 
          return matrix[n][m] = max(LCS(str1, str2, n-1, m), LCS(str1, str2, n, m-1));
    }

    int countMin(string str){
      int n = str.size();
      string revStr { str };
      reverse(revStr.begin(), revStr.end());
      return n - LCS(str, revStr, n, n);
    }
};

int main(){
  int testcases;
  cin >> testcases;
  while(testcases--){
      memset(matrix, -1, sizeof(matrix));
      string str;
      cin >> str;
      Solution ob;
      cout << ob.countMin(str) << endl;
  }
  return 0;
}
*/


// Method 3: Top down approach - Only Matrix. TC: O(N*M) SC: O(N*M)
int matrix[1001][1001];

class Solution{
  public:
    int LCS(string str1, string str2, int n, int m) {
        for(int i=0; i<n+1; i++) {
          for(int j=0; j<m+1; j++) {
            if(i==0 || j==0)
                matrix[i][j] = 0;
               else if(str1[i-1] == str2[j-1])
                    matrix[i][j] = 1 + matrix[i-1][j-1];
                else
                    matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
            }
        }
        return matrix[n][m];
    }

    int countMin(string str){
      memset(matrix, -1, sizeof(matrix));
      int n = str.size();
      string revStr { str };
      reverse(revStr.begin(), revStr.end());
      return n - LCS(str, revStr, n, n);
    }
};

int main(){
  int testcases;
  cin >> testcases;
  while(testcases--){
      string str;
      cin >> str;
      Solution ob;
      cout << ob.countMin(str) << endl;
  }
  return 0;
}